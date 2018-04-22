#include "MyFilterHistogramEqualization.h"
#include "LayerHistogramEqualization.h"

namespace NTNUEEPR_WPF {

	LayerHistogramEqualization::LayerHistogramEqualization()
	{
		algorithm = new MyFilterHistogramEqualization<MyImageData::uchar>();
		layer_names = "Histogram Equalization";
	}

	LayerHistogramEqualization ::~LayerHistogramEqualization()
	{
		delete algorithm;
	}

	MyImageData ^ LayerHistogramEqualization::Execute(MyImageData ^ input)
	{
		if (!isEnable)
			return input;
		auto result = gcnew MyImageData();
		result->data = algorithm->Execute(input->data);
		return result;
	}


}