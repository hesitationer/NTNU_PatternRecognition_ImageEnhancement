#pragma once
#include "MyFilter.h"
#include "vector"
#include "algorithm"
#include <math.h>
using namespace std;

template<typename T>
public class DiscreteCosineTransformFilter :public MyFilter<T>
{
public:

	DiscreteCosineTransformFilter() {}
	~DiscreteCosineTransformFilter() {
		if (resultImg != nullptr)
			delete resultImg;
	}

	MyImage<T>* Execute(MyImage<T>* input) override
	{
		int width = input->GetWidth();
		int height = input->GetHeight();

		T*** ptr_colors = input->Get3ColorPixels();
		T*** ptr_new_colors = input->Get3ColorPixelsCopy();

		for (int index_color = 0; index_color < 3;index_color++) {
			for (int index_w = 0; index_w < width; index_w += blockSize) {
				for (int index_h = 0; index_h < height; index_h += blockSize) {
					auto dct = DCT(ptr_colors[index_color], index_w,index_h,width,height);
					auto idct = IDCT(dct, index_w,index_h,width,height);
					for(int index_dct_w=0;index_dct_w< blockSize;index_dct_w++)
						for (int index_dct_h = 0; index_dct_h < blockSize; index_dct_h++) {
							int index_img_w = index_dct_w + index_w;
							int index_img_h = index_dct_h + index_h;
							if (index_img_w >= width || index_img_h >= height)
								continue;
							ptr_new_colors[index_color][index_img_w][index_img_h]
									= (T)idct[index_dct_w][index_dct_h];
						
						}
					DeleteBlock(dct);
					DeleteBlock(idct);
				}
			}
		}

		if (resultImg == nullptr)
			resultImg = new MyImage<T>(
				ptr_new_colors[MyImage<T>::COLOR::R],
				ptr_new_colors[MyImage<T>::COLOR::G],
				ptr_new_colors[MyImage<T>::COLOR::B],
				input->GetWidth(),
				input->GetHeight()
				);
		else
			resultImg->Initialize(
				ptr_new_colors[MyImage<T>::COLOR::R],
				ptr_new_colors[MyImage<T>::COLOR::G],
				ptr_new_colors[MyImage<T>::COLOR::B],
				input->GetWidth(),
				input->GetHeight()
			);
		return resultImg;
	}

	void SetColorTable(int* table) {
		this->table = table;
	}

	float deleteColumnFactor = 0.25;
	int blockSize = 8;

private:	
	MyImage<T>* resultImg = nullptr;

	double** DCT(T** value,int start_w,int start_h,int width,int height) {
		double** block = CreateBlock();

		int M = blockSize;
		int N = blockSize;

		if (M + start_w > width)M = width - start_w;
		if (N + start_h > height)N = height - start_h;

		int cal_M = (int)((double)M*deleteColumnFactor);
		int cal_N = (int)((double)N*deleteColumnFactor);
		double constant = 2 / sqrt( M * N );
		double pi_div_2N = 3.14159 / (2 * blockSize);

		for (int m = 0; m < M; m++)
		{
			for (int n = 0; n < N; n++)
			{
				if (m > cal_M || n > cal_N) continue;

				double factor = constant * C(m,n);
				for (int x = 0; x < M; x++) {
					for (int y = 0; y < N; y++)
						block[m][n] +=
						(double)value[x+start_w][y+start_h] *
						cos(
							(2 * x + 1)*m*pi_div_2N
						)*
						cos(
							(2 * y + 1)*n*pi_div_2N
						)
						;
				}
				block[m][n] *= factor;
			}
		}
		return block;
	}

	double** IDCT(double** block, int start_w, int start_h,int width,int height) {
		double** result_block = CreateBlock();

		int M =  blockSize;
		int N =  blockSize;

		if (M + start_w > width)M = width - start_w;
		if (N + start_h > height)N = height - start_h;

		double constant = 2 / sqrt(M*N);
		double pi_div_2N = 3.14159 / (2 * M);

		for (int x = 0; x < M; x++)
		{
			for (int y = 0; y < N; y++)
			{
				for (int m = 0; m < M; m++) {
					for (int n = 0; n < N; n++)
						result_block[x][y] +=
						C(m,n) *
						block[m][n] *
						cos(
							(2 * x + 1)*m*pi_div_2N
						)*
						cos(
							(2 * y + 1)*n*pi_div_2N
						)
						;
				}
				result_block[x][y] *= constant;
			}
		}
		return result_block;
	}

	double** CreateBlock() {
		double** block = new double*[blockSize];
		for (int index = 0; index < blockSize; index++) {
			block[index] = new double[blockSize];
			for (int index_c = 0; index_c < blockSize; index_c++) {
				block[index][index_c] = 0;
			}
		}
		return block;
	}

	void DeleteBlock(double** block) {
		for (int index = 0; index < blockSize; index++) {
			delete [] block[index];
		}
		delete[] block;
	}

	double C(int m,int n) {
		double result = 1;
		if (m == 0)
			result /= sqrt(2);
		if (n == 0)
			result /= sqrt(2);
		return result;
	}
};
