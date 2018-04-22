//#include "MyImage.h"
//
////template<typename T>
////MyImage<T>::MyImage()
////{
////}
////
//template<typename T>
//inline MyImage<T>::MyImage(T ** ptr_pixels_red, T ** ptr_pixels_green, T ** ptr_pixels_blue, uint width, uint height)
//{
//	Initialize(ptr_pixels_blue,ptr_pixels_green,ptr_pixels_red,width,height);
//}
//
//template<typename T>
//MyImage<T>::~MyImage()
//{
//	for (uint index_x = 0; index_x < width; index_x++) {
//		delete[] this->ptr_del_red[index_x];
//		delete[] this->ptr_del_green[index_x];
//		delete[] this->ptr_del_blue[index_x];
//	}
//	delete[] this->ptr_del_red;
//	delete[] this->ptr_del_green;
//	delete[] this->ptr_del_blue;
//}
//
//
////template<typename T>
////inline void MyImage<T>::Initialize(T ** ptr_pixels_red, T ** ptr_pixels_green, T ** ptr_pixels_blue, uint width, uint height)
////{
////	this->ptr_pixels_red = ptr_pixels_red;
////	this->ptr_pixels_green = ptr_pixels_green;
////	this->ptr_pixels_blue = ptr_pixels_blue;
////
////	this->ptr_del_red = ptr_pixels_red;
////	this->ptr_del_green = ptr_pixels_green;
////	this->ptr_del_blue = ptr_pixels_blue;
////
////	this->width = width;
////	this->height = height;
////}
//
//template<typename T>
//inline uint MyImage<T>::GetWidth()
//{
//	return width;
//}
//
//template<typename T>
//inline uint MyImage<T>::GetHeight()
//{
//	return height;
//}
//
//template<typename T>
//inline T ** MyImage<T>::GetPixels(COLOR type)
//{
//	switch (type)
//	{
//	case COLOR::R:
//		return ptr_pixels_red;
//	case COLOR::G:
//		return ptr_pixels_green;
//	case COLOR::B:
//		return ptr_pixels_blue;
//	default:
//		return nullptr;
//	}
//}
//
//template<typename T>
//inline T ** MyImage<T>::GetPixelsCopy(COLOR type)
//{
//	T ** ptr_newPixels = new *T[width];
//	T ** ptr_oldPixels = GetPixels(type);
//
//	for (uint index_x = 0; index_x < width; index_x++) {
//		ptr_newPixels[index_x] = new T[height];
//		for (uint index_y = 0; index_y < height; index_y++;) {
//			ptr_newPixels[index_x][index_y] =
//				ptr_oldPixels[index_x][index_y];
//		}
//	}
//	return ptr_newPixels;
//}
//
//template<typename T>
//void MyImage<T>::DeletePixels(T** ptr_pixels, uint width, uint height)
//{
//	for (uint index_x = 0; index_x < width; index_x++) {
//		delete[] ptr_pixels[index_x];
//	}
//	delete[] ptr_pixels;
//}