#include "stdafx.h"
#include "bonegl/init/inut_glut.h"

using namespace core;

void init_glut::init(const core::window_info& windowInfo, const core::context_info& context_info, const core::frame_buffer_info& frame_buffer_info)
{
	int fakeargc = 1;
	char *fakeargv[] = { (char*)"fake", NULL };
	glutInit(&fakeargc, fakeargv);

	if (context_info.core)
	{
		glutInitContextVersion(context_info.major_version, context_info.minor_version);
		glutInitContextProfile(GLUT_CORE_PROFILE);
	}
	else
	{
		glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	}

	glutInitDisplayMode(frame_buffer_info.flags);
	glutInitWindowPosition(windowInfo.position_x, windowInfo.position_y);
	glutInitWindowSize(windowInfo.width, windowInfo.height);

	glutCreateWindow(windowInfo.name);
	std::cout << "GLUT:initialized" << std::endl;

	glutIdleFunc(idle_callback);
	glutCloseFunc(close_callback);
	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape_callback);

	init_glew::init();

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	print_info(windowInfo, context_info);

}

void init_glut::run()
{
	std::cout << "GLUT:\t Start Running  " << std::endl;
	glutMainLoop();
}


void init_glut::close()
{
	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}

void init_glut::idle_callback(void)
{
	glutPostRedisplay();
}

void init_glut::display_callback()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1);
	glutSwapBuffers();
}

void init_glut::reshape_callback(int width, int height)
{

}

void init_glut::close_callback()
{
	close();
}

void init_glut::enter_fullscreen()
{
	glutFullScreen();
}

void init_glut::exit_fullscreen()
{
	glutLeaveFullScreen();
}

void init_glut::print_info(const core::window_info& window_info, const core::context_info& context_info)
{
	const unsigned char* renderer = glGetString(GL_RENDERER);
	const unsigned char* vendor = glGetString(GL_VENDOR);
	const unsigned char* version = glGetString(GL_VERSION);

	std::cout << "GLUT:\tVendor : " << vendor << std::endl;
	std::cout << "GLUT:\tRenderer : " << renderer << std::endl;
	std::cout << "GLUT:\tOpenGl version: " << version << std::endl;
	std::cout << "GLUT:\tInitial window is '" << window_info.name << "', with dimensions (" << window_info.width << "X" << window_info.height;
	std::cout << ") starts at (" << window_info.position_x << "X" << window_info.position_y;
	std::cout << ") and " << ((window_info.is_reshapable) ? "is" : "is not ") << " redimensionable" << std::endl;
	std::cout << "GLUT:\tInitial Framebuffer contains double buffers for" << std::endl;
	std::cout << "GLUT:\t OpenGL context is " << context_info.major_version << "." << context_info.minor_version;
	std::cout << " and profile is " << ((context_info.core) ? "core" : "compatibility") << std::endl;
}