
#include "stdafx.h"
#include "jack/jack.h"
#include "jack/types.h"
#include "jackinterface.h"
#include "bonespraygraphics.h"
#pragma comment(lib, "libjack.lib")

/*
 *	The main entry point of our program.
 *	This spawns the JACK connection, launched the GL window, and then keeps the program running.
 */
int main(int argc, char **argv)
{
	jint::activate();

	bonegl::launch(argc, argv);

	while (1) Sleep (1000);

	jint::close();
}