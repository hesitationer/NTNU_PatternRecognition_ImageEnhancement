#include "LayerColorAbjustment.h"
#include "ColorAdjustmentFilter.h"

namespace NTNUEEPR_WPF {

	NTNUEEPR_WPF::LayerColorAdjustmentFilter::LayerColorAdjustmentFilter()
	{
		algorithm = new ColorAdjustmentFilter<MyImageData::uchar>();
		int table[255];
		for (int index = 0; index < 255; index++) {
			if (index >= 192) {
				 table[index] = (255 / (255 - 192))*(index-192);
			}
			else if (index >= 61) {
				table[index] = 255 - (255 / (192 - 61))*(index-61);
			}
			else {
				table[index] = 255 / 61 * index;
			}
		}
		((ColorAdjustmentFilter<MyImageData::uchar >*)algorithm)->SetColorTable(table);
		layer_names = "Color Adjustment";
	}

	NTNUEEPR_WPF::LayerColorAdjustmentFilter::~LayerColorAdjustmentFilter(void)
	{
		delete algorithm;
	}

	MyImageData ^ NTNUEEPR_WPF::LayerColorAdjustmentFilter::Execute(MyImageData ^ input)
	{
		if (!isEnable)
			return input;
		auto result = gcnew MyImageData();
		result->data = algorithm->Execute(input->data);
		return result;
	}
}

