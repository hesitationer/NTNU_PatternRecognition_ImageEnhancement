#include "MyImageData.h"

namespace NTNUEEPR_WPF {
	MyImageData::MyImageData(String ^ name)
	{
		this->name = name;

		try {
			Image^ orginImg = Image::FromFile(name);
			data = new MyImage<uchar>();

			/*analysis pixels*/
			int w = orginImg->Width, h = orginImg->Height;
			uchar** ptr_pixels_r = new uchar*[w];
			uchar** ptr_pixels_g = new uchar*[w];
			uchar** ptr_pixels_b = new uchar*[w];

			Bitmap^ bm = gcnew Bitmap(orginImg);
			for (int index_w = 0; index_w < w; index_w++) {
				ptr_pixels_r[index_w] = new uchar[h];
				ptr_pixels_g[index_w] = new uchar[h];
				ptr_pixels_b[index_w] = new uchar[h];
				for (int index_h = 0; index_h < h; index_h++) {
					ptr_pixels_r[index_w][index_h] = bm->GetPixel(index_w, index_h).R;
					ptr_pixels_g[index_w][index_h] = bm->GetPixel(index_w, index_h).G;
					ptr_pixels_b[index_w][index_h] = bm->GetPixel(index_w, index_h).B;
				}
			}

			data->Initialize(ptr_pixels_r, ptr_pixels_g, ptr_pixels_b, w, h);
		}
		catch(Exception^) {
			data = nullptr;
		}
	}
	bool MyImageData::operator==(MyImageData ^& b)
	{
		return String::Compare(this->name,b->name)==0;
	}
	bool MyImageData::operator==(String ^& other)
	{
		return String::Compare(this->name,other)==0;
	}
	unsigned int MyImageData::GetWidth()
	{
		return data->GetWidth();
	}
	unsigned int MyImageData::GetHeight()
	{
		return data->GetHeight();
	}
	 MyImageData::uchar ** MyImageData::GetPixels(COLOR type)
	{
		return data->GetPixels(type);
	}
	void MyImageData::DeletePixels(uchar ** ptr_pixels, unsigned int width, unsigned int height)
	{
		MyImage<MyImageData::uchar>::DeletePixels(ptr_pixels,width,height);
	}
}