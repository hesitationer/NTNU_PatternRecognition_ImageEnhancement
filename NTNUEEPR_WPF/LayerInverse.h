#pragma once
#include "FilterToLayer.h"

namespace NTNUEEPR_WPF {

	public ref class LayerInverse : FilterToLayer
	{
	public:
		LayerInverse();
		~LayerInverse();

		MyImageData^ Execute(MyImageData^ input) override;
	private:

	};
}
