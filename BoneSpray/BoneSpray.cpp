
#include "stdafx.h"
#include "jack/jack.h"
#include "jack/types.h"
#include "jackinterface.h"

#pragma comment(lib, "libjack.lib")

int main()
{
	jint::activate();

	while (1) Sleep (1000);

	jint::close();
}
