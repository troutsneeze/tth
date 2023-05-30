#ifndef NOO_VERTEX_CACHE_H
#define NOO_VERTEX_CACHE_H

#include "shim3/main.h"
#include "shim3/image.h"
#include "shim3/shim.h"

namespace noo {

namespace gfx {

class Vertex_Cache {
public:
	static void static_start();
	static Vertex_Cache *instance();
	static void destroy();

	// These ones use the already selected cache...
	SHIM3_EXPORT void start(bool repeat = false); // no texture
	SHIM3_EXPORT void start(Image *image, bool repeat = false);
	SHIM3_EXPORT void end();

	SHIM3_EXPORT bool is_started();

	SHIM3_EXPORT void cache(SDL_Colour vertex_colours[3], util::Point<float> da, util::Point<float> db, util::Point<float> dc);
	SHIM3_EXPORT void cache(SDL_Colour vertex_colours[4], util::Point<float> source_position, util::Size<float> source_size, util::Point<float> da, util::Point<float> db, util::Point<float> dc, util::Point<float> dd, int flags);
	SHIM3_EXPORT void cache_z_range(SDL_Colour vertex_colours[4], util::Point<float> source_position, util::Size<float> source_size, util::Point<float> dest_position, float z_top, float z_bottom, util::Size<float> dest_size, int flags);
	SHIM3_EXPORT void cache_z(SDL_Colour vertex_colours[4], util::Point<float> source_position, util::Size<float> source_size, util::Point<float> dest_position, float z, util::Size<float> dest_size, int flags);
	SHIM3_EXPORT void cache(SDL_Colour vertex_colours[4], util::Point<float> source_position, util::Size<float> source_size, util::Point<float> dest_position, util::Size<float> dest_size, int flags);
	SHIM3_EXPORT void cache_z(SDL_Colour vertex_colours[4], util::Point<float> pivot, util::Point<int> source_position, util::Size<int> source_size, util::Point<float> dest_position, float angle, float scale_x, float scale_y, float z, int flags);
	SHIM3_EXPORT void cache(SDL_Colour vertex_colours[4], util::Point<float> pivot, util::Point<int> source_position, util::Size<int> source_size, util::Point<float> dest_position, float angle, float scale, int flags);
	SHIM3_EXPORT void cache_3d(SDL_Colour tint, float *in_verts, int *in_faces, float *in_normals, float *in_texcoords, float *in_colours, int num_triangles);
	SHIM3_EXPORT void cache_3d_immediate(float *buffer, int num_triangles);

	SHIM3_EXPORT void maybe_resize_cache(int increase);

	SHIM3_EXPORT void select_cache(Uint32 id);
	SHIM3_EXPORT Uint32 get_current_cache();

	SHIM3_EXPORT void reset();

private:
	static Vertex_Cache *v;

	SHIM3_EXPORT Vertex_Cache();
	SHIM3_EXPORT ~Vertex_Cache();

	float **_vertices;
	int *_count;
	int *_total;
	bool *_started;
	bool *_repeat;
	Image **_image;

	std::map<Uint32, float *> vertices;
	std::map<Uint32, int> count;
	std::map<Uint32, int> total;
	std::map<Uint32, bool> started;
	std::map<Uint32, bool> repeat;
	std::map<Uint32, Image *> image;

	Uint32 current_cache;
};

} // End namespace gfx

} // End namespace noo

#endif // NOO_VERTEX_CACHE_H
