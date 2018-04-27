#pragma once

#include "MyFilter.h"
#include "MyImage.h"

template<typename T>
public class MyFilterHistogramEqualization : public MyFilter<T>
{
public:
	MyFilterHistogramEqualization() {}
	~MyFilterHistogramEqualization (){
		if(resultImg!=nullptr)
			delete resultImg;
	}

	MyImage<T>* Execute(MyImage<T>* img)override {
		//para
		int width = img->GetWidth(), height = img->GetHeight();
		int dataSize = GetDataLength();
		T** ptr_pixels_gray = nullptr;

		//to be histogram
		int* histogram = GetHistogram(img,ptr_pixels_gray,dataSize,width,height);
		//get cdf
		int* cdf = GetCDF(img,dataSize, histogram, width, height);
		int cdfMin = GetCDFMin(cdf,dataSize);
		//to be result
		T** result_histogram = Calculate(ptr_pixels_gray,histogram,width,height,cdf,dataSize,cdfMin);

		if (resultImg == nullptr)
			resultImg = new MyImage<T>(result_histogram, result_histogram, result_histogram,
				img->GetWidth(), img->GetHeight());
		else
			resultImg->Initialize(result_histogram, result_histogram, result_histogram,
				img->GetWidth(), img->GetHeight());

		img->DeletePixels(ptr_pixels_gray,width,height);

		delete [] histogram;
		delete[] cdf;

		//return
		return resultImg;
	}

private:

	MyImage<T>* resultImg = nullptr;

	int GetDataLength() {
		return sizeof(T)*256;
	}

	int* GetHistogram(MyImage<T>* img,T** &ptr_pixels_gray,int size,int width,int height) {

		int*  graph = new int[size];
		for (int index_col = 0; index_col < size; index_col++) {
			graph[index_col] = 0;
		}

		T** const r = img->GetPixels(MyImage<T>::COLOR::R);
		T** const g = img->GetPixels(MyImage<T>::COLOR::G);
		T** const b = img->GetPixels(MyImage<T>::COLOR::B);

		ptr_pixels_gray = img->GetPixelsCopy(MyImage<T>::COLOR::G);

		for (int index_w = 0; index_w < width; index_w++) {
			for (int index_h = 0; index_h < height; index_h++) {
				int index_col =
					(r[index_w][index_h] + g[index_w][index_h] + b[index_w][index_h]) / 3;
				graph[index_col]++;
				ptr_pixels_gray[index_w][index_h] = index_col;
			}
		}
		return graph;
	}

	int* GetCDF(MyImage<T>* img,int size,int* histogram,int width,int height) {
		int* cdf = new int[size];
		for (int index_col = 0; index_col < size; index_col++)
			cdf[index_col] = 0;
		unsigned int currMin = -1;
		for (int index = 1; index < GetDataLength(); index++) {
			cdf[index] += histogram[index] + cdf[index-1];
			if (currMin < (unsigned int)cdf[index])
				currMin = cdf[index];
		}
		return cdf;
	}

	int GetCDFMin(int* cdf,int cdfLength) {
		for (int index = 0; index < cdfLength;index++) {
			int value = cdf[index];
			if (0 != value)
				return value;
		}
		return 0;
	}

	T** Calculate(T** gray,int* histogram,int width,int height,int* cdf,int cdfLength,int cdfMin) {
		T** result = new T*[width];
		cdfLength -= 1;
		int MXNMinusOne = width*height - cdfMin;
		for (int index_w = 0; index_w < width; index_w++) 
		{
			result[index_w] = new T[height];
			for (int index_h = 0; index_h < height; index_h++) 
			{
				int newValue = (
					(cdf[gray[index_w][index_h]] - cdfMin)
					*(cdfLength)
					)
					/
					(MXNMinusOne);
				result[index_w][index_h] = newValue;
			}
		}
		return result;
	}
};

