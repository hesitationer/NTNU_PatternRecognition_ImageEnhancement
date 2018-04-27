#include "LayerContractBalance.h"
#include "ContrastBalanceFilter.h"

namespace NTNUEEPR_WPF {
	LayerContrastBalance::LayerContrastBalance()
	{
		algorithm = new ContractBalanceFilter<MyImageData::uchar>();
		layer_names = "Contrast Balance";
	}

	LayerContrastBalance ::~LayerContrastBalance()
	{
		delete algorithm;
	}

	MyImageData ^ LayerContrastBalance::Execute(MyImageData ^ input)
	{
		if (!isEnable)
			return input;
		auto result = gcnew MyImageData();
		result->data = algorithm->Execute(input->data);
		return result;
	}
}