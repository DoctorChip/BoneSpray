#include "stdafx.h"
#include "jack/jack_interface.h"
#include "bonegl/init/inut_glut.h"
#include "bonegl/init/window_info.h"
#include "bonegl/init/context_info.h"
#pragma comment(lib, "libjack.lib")

int main(int argc, char **argv)
{
	jack::activate();

	// Configure OpenGL
	core::window_info window_info((char*)"Bone Spray", 300, 300, 500, 500, true);
	core::context_info context_info(4, 3, true);
	core::frame_buffer_info frame_buffer_info(true, true, true, true);

	// Launch!
	core::init_glut::init(window_info, context_info, frame_buffer_info);

	while (1) Sleep (1000);

	jack::close();
}