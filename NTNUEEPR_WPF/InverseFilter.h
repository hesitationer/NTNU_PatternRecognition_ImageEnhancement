#pragma once
#include "MyFilter.h"
#include "vector"
#include "algorithm"
using namespace std;

template<typename T>
public class InverseFilter :public MyFilter<T>
{
public:

	InverseFilter() {}
	~InverseFilter() {
		if (resultImg != nullptr)
			delete resultImg;
	}

	MyImage<T>* Execute(MyImage<T>* input) override
	{
		int width = input->GetWidth();
		int height = input->GetHeight();
		int max_value = sizeof(T) * 256 - 1;

		T*** new_pixels = new T**[3];
		for (int index_col = 0; index_col < 3; index_col++) {
			new_pixels[index_col] = input->GetPixelsCopy((MyImage<T>::COLOR)index_col);
			for (int index_w = 0; index_w < width; index_w++) {
				for (int index_h = 0; index_h < height; index_h++) {
					new_pixels[index_col][index_w][index_h] =
						max_value - new_pixels[index_col][index_w][index_h];
				}
			}
		}
		if (resultImg == nullptr)
			resultImg = new MyImage<T>(
				new_pixels[MyImage<T>::COLOR::R],
				new_pixels[MyImage<T>::COLOR::G],
				new_pixels[MyImage<T>::COLOR::B],
				input->GetWidth(),
				input->GetHeight()
				);
		else
			resultImg->Initialize(
				new_pixels[MyImage<T>::COLOR::R],
				new_pixels[MyImage<T>::COLOR::G],
				new_pixels[MyImage<T>::COLOR::B],
				input->GetWidth(),
				input->GetHeight()
			);
		return resultImg;
	}

	void SetColorTable(int* table) {
		this->table = table;
	}

private:
	MyImage<T>* resultImg = nullptr;
	int* table = nullptr;

	bool Swap(T i, T j) { return (i<j); }
};
