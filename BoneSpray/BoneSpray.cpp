
#include "stdafx.h"
#include <iostream>
#include <jack/jack.h>
#include <jack/types.h>
#pragma comment (lib, "libjack.lib")

jack_port_t *in_port;

int 
process (jack_nframes_t nframes, void *arg)
{
	jack_default_audio_sample_t *in;
	int i;

	in = (jack_default_audio_sample_t *) jack_port_get_buffer (in_port, nframes);
	
	for (i = 0; i < nframes; i++)
	{
		std::cout << in[i];
	}

	return 0;
}

void
jack_shutdown (void *arg)
{
	exit(1);
}

int 
main ()
{
	const char *CLIENT_NAME = "BS";
	const char *IN_NAME = "BSIn1";
	jack_status_t *STATUS = {};

	jack_client_t* client = jack_client_open (CLIENT_NAME, JackNullOption, STATUS);
	in_port = jack_port_register (client, IN_NAME, JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);

	jack_nframes_t nframes = jack_get_buffer_size(client);

	jack_set_process_callback (client, process, 0);
	jack_on_shutdown (client, jack_shutdown, 0);

	int activate = jack_activate (client);

	while (1)
	{
		Sleep (1000);
	}

	jack_client_close (client);
	exit(0);
}
