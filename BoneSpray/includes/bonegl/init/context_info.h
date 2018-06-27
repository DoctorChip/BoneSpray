#pragma once
#include "stdafx.h"

namespace core
{
	struct context_info 
	{
		int major_version, minor_version;
		bool core;

		context_info()
		{
			major_version = 3;
			minor_version = 3;
			core = true;
		}

		context_info(int major_version, int minor_version, bool core)
		{
			this->major_version = major_version;
			this->minor_version = minor_version;
			this->core = core;
		}

		context_info(const context_info& context_info)
		{
			major_version = context_info.major_version;
			minor_version = context_info.minor_version;
			core = context_info.core;
		}

		void operator=(const context_info& context_info)
		{
			major_version = context_info.major_version;
			minor_version = context_info.minor_version;
			core = context_info.core;
		}
	};
}