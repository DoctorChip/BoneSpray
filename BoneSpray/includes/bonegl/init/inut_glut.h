#pragma once
#include "stdafx.h"
#include "context_info.h"
#include "frame_buffer_info.h"
#include "window_info.h"
#include "init_glew.h"
#include "bonegl/core/bonegl_i_listener.h"
#include <iostream>

namespace core
{
	class init_glut
	{

	public:
		static void init(const core::window_info& window, const core::context_info& context, const core::frame_buffer_info& frame_buffer_info);

	public:
		static void run();

		static void close();

		void enter_fullscreen();

		void exit_fullscreen();

		static void print_info(const core::window_info& windowInfo, const core::context_info& context);

		static void set_listener(core::i_listener*& listener);

	private:

		static core::i_listener* listener;

		static core::window_info window_info;

		static void idle_callback(void);

		static void display_callback(void);

		static void reshape_callback(int width, int height);

		static void close_callback();
	};
}