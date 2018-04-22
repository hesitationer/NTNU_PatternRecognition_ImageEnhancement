#include "MedianFilter.h"
#include "LayerMedianFilter.h"

namespace NTNUEEPR_WPF {

	LayerMedianFilter::LayerMedianFilter()
	{
		algorithm = new MedianFilter<MyImageData::uchar>();
		layer_names = "Median Filter";
	}

	LayerMedianFilter ::~LayerMedianFilter()
	{
		delete algorithm;
	}

	MyImageData ^ LayerMedianFilter::Execute(MyImageData ^ input)
	{
		if (!isEnable)
			return input;
		auto result = gcnew MyImageData();
		result->data = algorithm->Execute(input->data);
		return result;
	}


}