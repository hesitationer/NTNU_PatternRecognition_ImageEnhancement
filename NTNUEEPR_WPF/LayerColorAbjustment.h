#pragma once
#include "FilterToLayer.h"

namespace NTNUEEPR_WPF {
	public ref class LayerColorAdjustmentFilter : FilterToLayer
	{
	public:
		LayerColorAdjustmentFilter();
		~LayerColorAdjustmentFilter(void);

		MyImageData^ Execute(MyImageData^ input) override;
	private:

	};

}