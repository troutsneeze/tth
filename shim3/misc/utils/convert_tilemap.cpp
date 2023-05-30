#include "shim3/shim3.h"

using namespace noo;

int main(int argc, char **argv)
{
	try {
		shim::static_start_all();

		shim::argc = argc+1;
		shim::argv = new char *[shim::argc];
		for (int i = 0; i < shim::argc-1; i++) {
			shim::argv[i] = new char[strlen(argv[i])+1];
			strcpy(shim::argv[i], argv[i]);
		}
		shim::argv[shim::argc-1] = new char[strlen("-fullscreen")+1];
		strcpy(shim::argv[shim::argc-1], "-fullscreen");
		shim::hide_window = true;
		shim::use_cwd = true;
		shim::error_level = 3;
		shim::log_tags = false;

		shim::start_all(1920, 1080, false, 1920, 1080);

		if (argc < 3) {
			util::infomsg("Usage: %s <in.map> <out.map>\n", argv[0]);
			return 0;
		}

		gfx::Image::keep_data = true;
		shim::tile_size = 16;

		gfx::Tilemap *input = new gfx::Tilemap(argv[1], true);

		input->save(argv[2]);

		delete input;

		shim::end_all();

		shim::static_end();
	}
	catch (util::Error e) {
		util::errormsg("Fatal error: %s\n", e.error_message.c_str());
	}

	return 0;
}
