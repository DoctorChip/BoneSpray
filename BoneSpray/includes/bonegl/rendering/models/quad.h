#pragma once
#include "stdafx.h"
#include "model.h"

namespace rendering
{
	namespace models
	{
		class quad : public models::model
		{

		public:
			quad();

			~quad();

			void create();

			virtual void draw() override final;

			virtual void update() override final;
		};
	}
}