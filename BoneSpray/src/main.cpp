#include "stdafx.h"
#include "jack/jack_interface.h"
#pragma comment(lib, "libjack.lib")

int main(int argc, char **argv)
{
	jack::activate();
	jack::close();
	return 0;
}