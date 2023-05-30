#ifndef NOO_TILEMAP_H
#define NOO_TILEMAP_H

#include "shim3/main.h"

namespace noo {

namespace gfx {

class Image;

class Tilemap
{
public:
	struct Animation_Data
	{
		util::Point<int> topleft;
		util::Size<int> size;
		int delay;
		std::vector< util::Point<int> > frames;
	};

	static float elapsed;

	static void static_start();
	static void release_sheets();
	static void reload_sheets(bool load_from_filesystem = false);
	static void update_all();
	static Image *get_sheet(int sheet);

	SHIM3_EXPORT Tilemap(std::string map_filename, bool load_from_filesystem = false);
	SHIM3_EXPORT ~Tilemap();

	SHIM3_EXPORT int get_num_layers();
	SHIM3_EXPORT util::Size<int> get_size();

	// in tiles
	SHIM3_EXPORT bool is_solid(int layer, util::Point<int> position);
	SHIM3_EXPORT void set_solid(int layer, util::Point<int> position, util::Size<int> size, bool solid);
	// in pixels
	SHIM3_EXPORT bool collides(int layer, util::Point<int> topleft, util::Point<int> bottomright);

	SHIM3_EXPORT void draw(int start_layer, int end_layer, util::Point<float> position, bool clip_small_tilemaps = false);
	SHIM3_EXPORT void draw(int layer, util::Point<float> position, bool clip_small_tilemaps = false);

	SHIM3_EXPORT void add_animation_data(Animation_Data data);

	SHIM3_EXPORT void swap_tiles(int layer1, int layer2, util::Point<int> topleft, util::Size<int> swap_size); // swap tiles between layers

	SHIM3_EXPORT bool get_tile(int layer, util::Point<int> position, util::Point<int> &tile_xy, bool &solid); // returns false OOB, -1 x on nothing
	SHIM3_EXPORT bool set_tile(int layer, util::Point<int> position, util::Point<int> tile_xy, bool solid); // returns false OOB

	SHIM3_EXPORT void save(std::string filename);
	
	SHIM3_EXPORT util::Point<int> get_animated_tile(util::Point<int> tile);

private:
	struct Layer
	{
		int **x;
		int **y;
	};
	bool **solid;

	SHIM3_EXPORT Animation_Data *get_animation_data(util::Point<int> tile);
	SHIM3_EXPORT bool has_alpha(int col, int row); // col/row in tilemap tile has any non-255 alpha pixels
	SHIM3_EXPORT bool all_clear(int col, int row); // col/row in tilemap is entirely clear pixels (to be removed)

	util::Size<int> size; // in tiles
	int num_layers;

	Layer *layers;

	std::vector<Animation_Data> animation_data;
};

} // End namespace gfx

} // End namespace noo

#endif // NOO_TILEMAP_H
