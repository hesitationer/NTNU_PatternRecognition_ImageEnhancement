#include "LayerInverse.h"
#include "InverseFilter.h"

namespace NTNUEEPR_WPF {

	NTNUEEPR_WPF::LayerInverse::LayerInverse()
	{
		algorithm = new InverseFilter<MyImageData::uchar>();
		layer_names = "Inverse";
	}
	LayerInverse::~LayerInverse()
	{
		delete algorithm;
	}
	MyImageData ^ LayerInverse::Execute(MyImageData ^ input)
	{
		if (!isEnable)
			return input;
		auto result = gcnew MyImageData();
		result->data = algorithm->Execute(input->data);
		return result;
	}
}
