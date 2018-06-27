#pragma once
#include <vector>
#include "bonegl/rendering/render_object.h"

namespace rendering
{
	namespace models
	{
		class model : public render_object
		{

		public:
			
			model();

			virtual ~model();

			virtual void draw() override;

			virtual void update() override;

			virtual void set_program(GLuint shaderName) override;

			virtual void destroy() override;

			virtual GLuint get_vao() const override;

			virtual const std::vector<GLuint>& get_vbos() const override;

		protected:
			GLuint vao;

			GLuint program;

			std::vector<GLuint> vbos;
		};
	}
}