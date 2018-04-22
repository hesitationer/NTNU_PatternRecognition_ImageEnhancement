#pragma once

//#pragma managed(push, off)
#include "MyImage.h"
//#pragma managed(pop)

namespace NTNUEEPR_WPF {

	using namespace System;
	using namespace System::Drawing;

	public ref class MyImageData  {
	public:
		typedef unsigned char uchar;
		typedef MyImage<uchar> TYPE;
		typedef TYPE::COLOR COLOR;

		String^ name;
		MyImage<unsigned char>* data;

		MyImageData(String^ name);
		MyImageData() :data() {  new TYPE(); }

		bool operator ==(MyImageData^ &other);
		bool operator ==(String^ &other);

		unsigned int GetWidth();
		unsigned int GetHeight();

		uchar** GetPixels(COLOR type);
		uchar** GetPixelsCopy(COLOR type) {
			return data->GetPixelsCopy(type);
		}

		static void DeletePixels(uchar** ptr_pixels, unsigned int width, unsigned int height);

	};
}