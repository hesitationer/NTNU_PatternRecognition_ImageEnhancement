#pragma once
#include "FilterToLayer.h"

namespace NTNUEEPR_WPF{
	public ref class LayerContrastBalance : FilterToLayer
	{
	public:
		LayerContrastBalance();
		~LayerContrastBalance();

		MyImageData^ Execute(MyImageData^ input)override;
	private:

	};
}