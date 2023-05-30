#ifndef NOO_MODEL_H
#define NOO_MODEL_H

#include "shim3/main.h"

namespace noo {

namespace gfx {

class Image;

class Model {
public:
	static void static_start();
	static void update_all();

	struct Node;

	EXPORT_STRUCT_ALIGN(Weights, 16) {
		std::string name;
		float *weights;
		glm::mat4 transform;

		Weights();
		~Weights();

		// For 16 byte alignment to make glm::mat4 able to use SIMD
#ifdef _WIN32
		void *operator new(size_t i);
		void operator delete(void* p);
#endif
	};

	EXPORT_STRUCT_ALIGN(Bone, 16) {
		std::string name;
		std::vector<glm::mat4> frames;
		glm::mat4 combined_transform;

		// For 16 byte alignment to make glm::mat4 able to use SIMD
#ifdef _WIN32
		void *operator new(size_t i);
		void operator delete(void* p);
#endif
	};

	struct Animation {
		std::string name;
		std::map<std::string, Bone *> bones;
		bool is_precalculated;
		int precalc_fps;
	};

	struct Influence {
		std::vector<Weights *> weights;
		std::vector<Bone *> bones;
	};

	EXPORT_STRUCT_ALIGN(Node, 16) {
		std::string name;
		Node *parent;
		glm::mat4 transform;
		float *vertices;
		float *animated_vertices;
		int *face_textures;
		std::vector<Image *> textures;
		int num_triangles;
		int num_vertices;
		Influence *influences;
		std::vector<Weights *> weights;
		std::vector<Node *> children;

		float min_x, min_y, min_z;
		float max_x, max_y, max_z;

		Node();
		~Node();

		Node *find(std::string name);
		void create_arrays(float *v, int *f, float *n, int *i, float *t, float *c, int num_triangles);

		void animate(Animation *animation, int frame, glm::mat4 *transform);

		// For 16 byte alignment to make glm::mat4 able to use SIMD
#ifdef _WIN32
		void *operator new(size_t i);
		void operator delete(void* p);
#endif
	};

	SHIM3_EXPORT Model();
	SHIM3_EXPORT Model(std::string filename, bool load_from_filesystem = false);
	SHIM3_EXPORT ~Model();

	SHIM3_EXPORT std::vector<Node *> get_nodes();
	SHIM3_EXPORT Node *find(std::string name);
	SHIM3_EXPORT void add_node(Node *node);
	SHIM3_EXPORT Animation *get_animation(std::string name);
	SHIM3_EXPORT void set_animation(std::string name, util::Callback finished_callback = 0, void *finished_callback_data = 0);
	SHIM3_EXPORT std::string get_current_animation();
	SHIM3_EXPORT int get_current_frame();
	SHIM3_EXPORT void start();
	SHIM3_EXPORT void stop();
	SHIM3_EXPORT void reset();

	SHIM3_EXPORT void precalculate_animations(int fps);

	SHIM3_EXPORT void draw();
	SHIM3_EXPORT void draw_tinted(SDL_Colour tint);
	SHIM3_EXPORT void draw_textured();
	SHIM3_EXPORT void draw_tinted_textured(SDL_Colour tint);

	SHIM3_EXPORT bool save_binary_model(std::string filename);

private:
	SHIM3_EXPORT void read(std::string filename, bool load_from_filesystem);
	SHIM3_EXPORT int read_byte(SDL_RWops *file);
	SHIM3_EXPORT void unget(int c);
	SHIM3_EXPORT void skip_whitespace(SDL_RWops *file);
	SHIM3_EXPORT void destroy(Node *node);
	SHIM3_EXPORT void destroy(Animation *animation);
	SHIM3_EXPORT std::string read_word(SDL_RWops *file);
	SHIM3_EXPORT Node *read_text_frame(SDL_RWops *file);
	SHIM3_EXPORT void skip_section(SDL_RWops *file);
	SHIM3_EXPORT void read_text_model(SDL_RWops *file);
	SHIM3_EXPORT Animation *read_animationset(SDL_RWops *file);
	SHIM3_EXPORT Bone *read_animation(SDL_RWops *file);
	SHIM3_EXPORT void precalculate_animation(std::string name, int fps);
	SHIM3_EXPORT float *calc_frame(std::string anim_name, int frame);
	SHIM3_EXPORT void draw(SDL_Colour tint, bool textured);
	SHIM3_EXPORT void read_binary_model(SDL_RWops *file);
	SHIM3_EXPORT void write_string(SDL_RWops *file, std::string s);
	SHIM3_EXPORT void write_matrix(SDL_RWops *file, glm::mat4 &matrix);
	SHIM3_EXPORT void save_binary_frame(SDL_RWops *file, Node *n);
	SHIM3_EXPORT void save_binary_animation(SDL_RWops *file, Animation *a);
	SHIM3_EXPORT std::string read_string(SDL_RWops *file);
	SHIM3_EXPORT glm::mat4 read_matrix(SDL_RWops *file);
	SHIM3_EXPORT Node *read_binary_frame(SDL_RWops *file);
	SHIM3_EXPORT Animation *read_binary_animation(SDL_RWops *file);

	struct Instance {
		std::map<std::string, Animation *> animations;
		std::string current_animation;
		util::Callback finished_callback;
		void *finished_callback_data;
		bool started;
		Uint32 elapsed;
		int frames_per_second;
	};

	static std::map<std::string, Instance *> loaded_models;

	std::vector<Node *> roots;
	std::vector<int> ungot;
	int line;

	std::string filename;

	Instance *instance;

	std::map<std::string, float **> precalculated;
};

} // End namespace gfx

} // End namespace noo

#endif // NOO_MODEL_H
