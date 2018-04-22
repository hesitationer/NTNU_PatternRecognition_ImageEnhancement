#pragma once
#include "FilterToLayer.h"

namespace NTNUEEPR_WPF {

	public ref class LayerMedianFilter : FilterToLayer
	{
	public:
		LayerMedianFilter();
		~LayerMedianFilter();

		MyImageData^ Execute(MyImageData^ input) override;
	private:

	};
}
