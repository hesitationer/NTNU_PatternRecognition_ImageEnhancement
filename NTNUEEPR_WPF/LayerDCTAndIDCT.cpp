#include "LayerDCTAndIDCT.h"
#include "DiscreteCosineTransformFilter.h"

namespace NTNUEEPR_WPF {

	NTNUEEPR_WPF::LayerDCTAndIDCT::LayerDCTAndIDCT()
	{
		algorithm = new DiscreteCosineTransformFilter<MyImageData::uchar>();
		layer_names = "Discrete Cosine Transform ";
	}

	LayerDCTAndIDCT::~LayerDCTAndIDCT()
	{
		delete algorithm;
	}

	MyImageData ^ NTNUEEPR_WPF::LayerDCTAndIDCT::Execute(MyImageData ^ input)
	{
		if (!isEnable)
			return input;
		auto result = gcnew MyImageData();
		result->data = algorithm->Execute(input->data);
		return result;
	}

}