#pragma once
#include "MyFilter.h"
#include "vector"
#include "algorithm"
using namespace std;

template<typename T>
public class MedianFilter :public MyFilter<T>
{
public:

	MedianFilter() {}
	~MedianFilter() {
		if (resultImg != nullptr)
			delete resultImg;
	}

	MyImage<T>* Execute(MyImage<T>* input) override
	{
		int width = input->GetWidth();
		int height = input->GetHeight();

		vector<T> values;

		T*** color_new = new T**[3];

		T** color_old;

		for (int index_col = 0; index_col < 3; index_col++) {
			MyImage<T>::COLOR color = (MyImage<T>::COLOR)index_col;
			color_new[index_col] = input->GetPixelsCopy(color);
			color_old = input->GetPixels(color);
			for (int index_w = 0; index_w < width; index_w++) 
			{
				for (int index_h = 0; index_h < height; index_h++) 
				{
					values.clear();
					for (int index_in_w = 0; index_in_w < 3; index_in_w++) 
					{
						for (int index_in_h = 0; index_in_h < 3; index_in_h++)
						{
							int x = index_in_w + index_w;
							int y = index_in_h + index_h;
							if( x < width && y < height)
								values.push_back(
									color_old[x][y]
								);
						}
					}
					
					sort(values.begin(), values.end());
					int size = values.size()!=0 ? ((values.size()-1) / 2):0;
					color_new[index_col][index_w][index_h] = values[size];
				}
			}
		}
		if (resultImg == nullptr)
			resultImg = new MyImage<T>(
				color_new[MyImage<T>::COLOR::R],
				color_new[MyImage<T>::COLOR::G],
				color_new[MyImage<T>::COLOR::B],
				input->GetWidth(),
				input->GetHeight()
			);
		else
			resultImg->Initialize(
				color_new[MyImage<T>::COLOR::R],
				color_new[MyImage<T>::COLOR::G],
				color_new[MyImage<T>::COLOR::B],
				input->GetWidth(),
				input->GetHeight()
			);
		return resultImg;
	}

private:
	MyImage<T>* resultImg = nullptr;

	bool Swap(T i, T j) { return (i<j); }
};
