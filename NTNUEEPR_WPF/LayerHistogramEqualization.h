#pragma once
#include "FilterToLayer.h"

namespace NTNUEEPR_WPF {
	public ref class LayerHistogramEqualization : FilterToLayer
	{
	public:
		LayerHistogramEqualization ();
		~LayerHistogramEqualization (void);

		MyImageData^ Execute(MyImageData^ input) override;
	private:

	};

}