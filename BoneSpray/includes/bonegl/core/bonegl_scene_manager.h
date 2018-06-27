#pragma once
#include "stdafx.h"
#include "bonegl_shader_manager.h"
#include "bonegl_model_manager.h"
#include "bonegl_i_listener.h"

namespace man
{
	class scene_manager : public core::i_listener
	{
	
	public:
		scene_manager();

		~scene_manager();

		virtual void notify_begin_frame();

		virtual void notify_display_frame();

		virtual void notify_end_frame();

		virtual void notify_reshape(int width, int height, int previous_width, int previous_height);
	
	private:
		man::shader_manager* shader_man;

		man::models_manager* models_man;
	};
}