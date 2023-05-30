// WARNING: any of the 'printf' style functions in this file have limits on supported sizes of strings

#ifndef NOO_UTIL_H
#define NOO_UTIL_H

#include "shim3/main.h"

namespace noo {

namespace util {

bool basic_start();
bool static_start();
void static_end();

bool start();
void end();

template <typename T> T sign(T v) { return (T(0) < v) - (v < T(0)); }

void SHIM3_EXPORT mkdir(std::string path);

void SHIM3_EXPORT errormsg(const char *fmt, ...);
void SHIM3_EXPORT errormsg(std::string s);
void SHIM3_EXPORT infomsg(const char *fmt, ...);
void SHIM3_EXPORT infomsg(std::string s);
void SHIM3_EXPORT debugmsg(const char *fmt, ...);
void SHIM3_EXPORT debugmsg(std::string s);
void SHIM3_EXPORT verbosemsg(const char *fmt, ...);
void SHIM3_EXPORT verbosemsg(std::string s);
void SHIM3_EXPORT printGLerror(const char *fmt, ...);
#ifdef DEBUG
#define PRINT_GL_ERROR(...) util::printGLerror(__VA_ARGS__)
#else
#define PRINT_GL_ERROR(...)
#endif

class List_Directory {
public:
	List_Directory(std::string filespec);
	~List_Directory();

	std::string next();

private:
#ifdef _WIN32
	bool got_first;
	bool done;
	HANDLE handle;
	WIN32_FIND_DATA ffd;
#elif !defined ANDROID
	int i;
	glob_t gl;
#endif
};

// some functions SDL doesn't have that are handy
int SHIM3_EXPORT SDL_fgetc(SDL_RWops *file);
int SHIM3_EXPORT SDL_fputc(int c, SDL_RWops *file);
char SHIM3_EXPORT *SDL_fgets(SDL_RWops *file, char * const buf, size_t max);
int SHIM3_EXPORT SDL_fputs(const char *string, SDL_RWops *file);
SHIM3_EXPORT void SDL_fprintf(SDL_RWops *file, const char *fmt, ...);

SDL_RWops *open_file(std::string filename, int *sz, bool data_only = false);
void close_file(SDL_RWops *file);
void free_data(SDL_RWops *file);

int SHIM3_EXPORT check_args(int argc, char **argv, std::string arg);
bool SHIM3_EXPORT bool_arg(bool default_value, int argc, char **argv, std::string arg);

SHIM3_EXPORT std::string string_printf(const char *fmt, ...);

SHIM3_EXPORT std::string itos(int i);

std::string SHIM3_EXPORT uppercase(std::string);
std::string SHIM3_EXPORT lowercase(std::string);

SHIM3_EXPORT std::string escape_string(std::string s, char c); // add backslashes before c characters in s
SHIM3_EXPORT std::string unescape_string(std::string);

std::string SHIM3_EXPORT load_text(std::string filename);
char SHIM3_EXPORT *slurp_file(std::string filename, int *sz);
char SHIM3_EXPORT *slurp_file_from_filesystem(std::string filename, int *sz);

// For trimming whitespace from left, right or both
std::string SHIM3_EXPORT &ltrim(std::string &s);
std::string SHIM3_EXPORT &rtrim(std::string &s);
std::string SHIM3_EXPORT &trim(std::string &s);

enum Path_Type {
	DOCUMENTS = 1,
	APPDATA,
	HOME,
	SAVED_GAMES
};

// These 3 are safe to call before calling shim::start
std::string SHIM3_EXPORT get_standard_path(Path_Type type, bool create);
// appdata_dir is used for crashdumps, can be used for anything else you want like config files
std::string SHIM3_EXPORT get_appdata_dir();
void SHIM3_EXPORT set_appdata_dir(std::string appdata_dir, bool create);

void SHIM3_EXPORT open_with_system(std::string filename); // open with default app
void SHIM3_EXPORT open_url(std::string url);

#ifdef ANDROID
bool SHIM3_EXPORT is_chromebook();
#endif

std::string SHIM3_EXPORT get_system_language(); // returns language in Steam format like "english", "french" etc

Uint64 file_date(std::string filename);

#ifndef _WIN32 // FIXME: need this for Windows
time_t utc_secs();
#endif

} // End namespace util

} // End namespace noo

#endif // NOO_UTIL_H
