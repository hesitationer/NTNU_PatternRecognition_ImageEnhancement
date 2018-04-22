#pragma once

typedef unsigned int uint;

template<typename T>
class MyImage {
public:

	enum COLOR {
		R,
		G,
		B
	};

	MyImage() {}
	MyImage(T** ptr_pixels_red, T** ptr_pixels_green,
		T** ptr_pixels_blue,
		uint width, uint height)
	{
		Initialize(ptr_pixels_blue, ptr_pixels_green, ptr_pixels_red, width, height);
	}

	~MyImage()
	{
		DeletePixels(ptr_pixels_red,width,height);
		DeletePixels(ptr_pixels_green, width, height);
		DeletePixels(ptr_pixels_blue, width, height);
	}

	void Initialize(T** ptr_pixels_red, T** ptr_pixels_green,
		T** ptr_pixels_blue,
		uint width, uint height) {

		if (this->ptr_pixels_blue == this->ptr_pixels_green) {
			DeletePixels(this->ptr_pixels_blue, width, height);
		}
		else {

			if (this->ptr_pixels_blue != nullptr) {
				DeletePixels(this->ptr_pixels_blue, width, height);
			}
			if (this->ptr_pixels_red != nullptr) {
				DeletePixels(this->ptr_pixels_red, width, height);
			}
			if (this->ptr_pixels_green != nullptr) {
				DeletePixels(this->ptr_pixels_green, width, height);
			}
		}

		this->ptr_pixels_red = ptr_pixels_red;
		this->ptr_pixels_green = ptr_pixels_green;
		this->ptr_pixels_blue = ptr_pixels_blue;

		this->width = width;
		this->height = height;
	}

	uint GetWidth() {
		return width;
	}
	uint GetHeight() {
		return height;
	}

	T** GetPixels(COLOR type) {
		switch (type)
		{
		case COLOR::R:
			return ptr_pixels_red;
		case COLOR::G:
			return ptr_pixels_green;
		case COLOR::B:
			return ptr_pixels_blue;
		}
		return nullptr;
	}

	T** GetPixelsCopy(COLOR type) {
		T **ptr_newPixels = new T*[width];
		T **ptr_oldPixels = GetPixels(type);

		for (uint index_x = 0; index_x < width; index_x++) {
			ptr_newPixels[index_x] = new T[height];
			for (uint index_y = 0; index_y < height; index_y++) {
				ptr_newPixels[index_x][index_y] =
					ptr_oldPixels[index_x][index_y];
			}
		}
		return ptr_newPixels;
	}

	static void DeletePixels(T** ptr_pixels, uint width, uint height)
	{
		if (ptr_pixels == nullptr)
			return;
		for (uint index_x = 0; index_x < width; index_x++) {
			delete[] ptr_pixels[index_x];
		}
		delete[] ptr_pixels;
		ptr_pixels = nullptr;
	}

protected:

private:

	uint width = 0;
	uint height = 0;

	T ** ptr_pixels_red = nullptr;
	T ** ptr_pixels_green = nullptr;
	T ** ptr_pixels_blue = nullptr;
};



