#include "stdafx.h"
#include "bonespraygraphics.h"
#include "sload.h"

#include <iostream>

#include "GL/glew.h"
#include "GL/freeglut.h"

namespace bonegl
{
	GLuint program;

	void render(void)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glUseProgram(program);

		glDrawArrays(GL_TRIANGLES, 0, 3);
	 
		glutSwapBuffers();
	}

	void loadShaders()
	{
		SLoader sLoader;
		program = sLoader.CreateProgram
		(
			"Shaders\\Vertex_Shader.glsl",
			"Shaders\\Fragment_Shader.glsl"
		);
	}

	int launch(int argc, char **argv)
	{
		// Config
		const int GL_WINDOW_W = 500;
		const int GL_WINDOW_H = 500;
		const char* WINDOW_NAME = "Bone Spray";
		const bool DISPLAY_FULL_SCREEN = false;

		// Initalise GLUT + GLEW
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
		glutInitWindowSize(GL_WINDOW_W, GL_WINDOW_H);
		glutCreateWindow(WINDOW_NAME);
		glEnable(GL_DEPTH_TEST);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glewInit();
		if (DISPLAY_FULL_SCREEN) glutFullScreen();

		// Bind Shaders
		loadShaders();

		// Register Callbacks
		glutDisplayFunc(render);

		// Main Loop
		glutMainLoop();
		return 0;
	}
}