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
			double** dct_values = DCT(ptr_colors[index_color], width, height);
			double** new_values = IDCT(dct_values, width, height);
			for (int index_width = 0; index_width < width; index_width++) {
				for (int index_height = 0; index_height < height; index_height++) {
					ptr_new_colors[index_color][index_width][index_height]
						= (T)new_values[index_width][index_height];
				}
			}
			DeleteValues(dct_values, width);
			DeleteValues(new_values, width);
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

	float deleteColumnFactor = 0.5;

private:
	
	MyImage<T>* resultImg = nullptr;

	double** DCT(T** value,int M, int N) {
		double** ptr_result = new double*[M];
		double constant = 2 / sqrt(M*N);
		double pi_div_2M = 3.14159 / (2 * M);
		double pi_div_2N = 3.14159 / (2 * N);

		int cal_M = M*deleteColumnFactor;
		int cal_N = N*deleteColumnFactor;

		for (int m = 0; m < M; m++)
		{
			ptr_result[m] = new double[N];
			for (int n = 0; n < N ; n++)
			{
				double factor = constant * C(m) * C(n);
				ptr_result[m][n] = 0;
				if (m < cal_M && n < cal_N) {
					for (int x = 0; x < M; x++) {
						for (int y = 0; y < N; y++)
							ptr_result[m][n] +=
							(double)value[x][y] *
							cos(
								(2 * x + 1)*m*pi_div_2M
							)*
							cos(
								(2 * y + 1)*n*pi_div_2N
							)
							;
					}
					ptr_result[m][n] *= factor;
				}
			}
		}
		return ptr_result;
	}

	double** IDCT(double** dct, int M, int N) {
		double** ptr_result = new double*[M];
		double constant = 2 / sqrt(M*N);
		double pi_div_2M = 3.14159 / (2 * M);
		double pi_div_2N = 3.14159 / (2 * N);


		for (int x = 0; x < M; x++)
		{
			ptr_result[x] = new double[N];
			for (int y = 0; y < N; y++)
			{
				ptr_result[x][y] = 0;
				for (int m = 0; m < M; m++) {
					for (int n = 0; n < N; n++)
						ptr_result[x][y] +=
						C(m) * C(n) *
						dct[m][n] *
						cos(
							(2 * x + 1)*m*pi_div_2M
						)*
						cos(
							(2 * y + 1)*n*pi_div_2N
						)
						;
				}
				ptr_result[x][y] *= constant;
			}
		}
		return ptr_result;
	}

	void DeleteValues(double** values,int width) {
		for (int index = 0; index < width; index++) {
			delete [] values[index];
		}
		delete[] values;
	}

	double C(int n) {
		if(n==0)
			return 0.707;
		return 1;
	}
};
