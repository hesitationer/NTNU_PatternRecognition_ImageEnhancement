#pragma once

#include "MyFilter.h"
#include "MyImageData.h"

namespace NTNUEEPR_WPF {

	public ref class FilterToLayer abstract
	{
	public:

		FilterToLayer();
		virtual ~FilterToLayer(void) ;

		virtual MyImageData^ Execute(MyImageData^ input)=0;
		String^ Name() { return layer_names; }

		bool isEnable = true;

	protected:
		MyFilter<MyImageData::uchar>* algorithm = nullptr;

		String^ layer_names;
		
	};
}