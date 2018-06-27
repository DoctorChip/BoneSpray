#pragma once
#include "model.h"

namespace rendering
{
	namespace models
	{
		class triangle : public model
		{
		public:
			triangle();
			~triangle();

			void create();
			virtual void update() override final;
			virtual void draw() override final;
		};
	}
}