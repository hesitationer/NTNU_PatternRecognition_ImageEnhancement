#pragma once
#include "FilterToLayer.h"


namespace NTNUEEPR_WPF {
	public ref class LayerDCTAndIDCT : FilterToLayer
	{
	public:
		LayerDCTAndIDCT();
		~LayerDCTAndIDCT();

		MyImageData^ Execute(MyImageData^ input)override;
	private:

	};
}