cmake_minimum_required(VERSION 3.0)
project("tth")

# Options

option(DEBUG "Debug build" OFF)
option(USE_STATIC_LIBS "Link with static libraries" ON)
option(STEAMWORKS "Build for Steam" OFF)
option(DEMO "Build the demo version" OFF)
option(WANT_TTF "Build with TTF support" OFF)

set(USER_INCLUDE_PATH "" CACHE FILEPATH "Any extra include directories you want")
set(USER_LIBRARY_PATH "" CACHE FILEPATH "Any extra library directories you want")

include_directories("include")
include_directories(${USER_INCLUDE_PATH})
link_directories(${USER_LIBRARY_PATH})

set(WEDGE3_LIB wedge3)
set(SHIM3_LIB shim3)
set(TGUI5_LIB tgui5)

# Inputs

set(SOURCES
	src/achievements.cpp
	src/area_game.cpp
	src/autosave.cpp
	src/battle_combo_drawer.cpp
	src/battle_game.cpp
	src/battle_player.cpp
	src/battle_transition_in.cpp
	src/battle_transition_in2.cpp
	src/battle_transition_out.cpp
	src/battle_transition_out2.cpp
	src/battles.cpp
	src/coin.cpp
	src/combo.cpp
	src/dialogue.cpp
	src/enemies.cpp
	src/general.cpp
	src/globals.cpp
	src/gui.cpp
	src/gui_drawing_hook.cpp
	src/hit.cpp
	src/inventory.cpp
	src/menu.cpp
	src/pan_camera.cpp
	src/question.cpp
	src/start_battle.cpp
	src/transition.cpp
	src/tth.cpp
	src/widgets.cpp
)

if(WIN32)
	list(APPEND SOURCES misc/tth.manifest misc/versioninfo.rc icons/windows_icons.rc)
endif()

if(APPLE)
	set(SOURCES ${SOURCES} src/apple.M)
endif()

# Platform specifics

if(MINGW)
	add_link_options(-fstack-protector) # because of how FLAC is compiled. This requires ssp DLL
	add_link_options(-static -static-libgcc -static-libstdc++)
	add_link_options(-Wl,--subsystem,windows)
	if(DEBUG)
		add_compile_options(-g -fno-omit-frame-pointer -fsanitize=address -fsanitize-recover=address -fsanitize-address-use-after-scope)
		add_link_options(-fno-omit-frame-pointer -fsanitize=address -fsanitize-recover=address -fsanitize-address-use-after-scope)
		#add_compile_options(-g -fsanitize=leak)
	endif()
	if(USE_STATIC_LIBS)
		add_compile_definitions(TGUI5_STATIC SHIM3_STATIC WEDGE3_STATIC)
	endif()
	if(STEAMWORKS)
		add_compile_definitions(STEAMWORKS)
		set(LIBS ${LIBS} steam_api64)
	endif()
	if(DEMO)
		add_compile_definitions(DEMO)
	endif()
	if(WANT_TTF)
		add_compile_definitions(USE_TTF)
	endif()
	set(LIBS ${LIBS} ${WEDGE3_LIB} ${SHIM3_LIB} ${TGUI5_LIB} mingw32 SDL2main SDL2 FLAC ogg freetype zlibstatic d3d9 winmm dbghelp shcore msvcrt imm32 setupapi version)
elseif(WIN32)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /IGNORE:4075 /IGNORE:4099")
	SET(FLAGS "${FLAGS} /D_CRT_SECURE_NO_WARNINGS /D_USE_MATH_DEFINES /EHsc /MP /W3 /wd4244 /wd4800 /wd4101 /MT")
	SET(FLAGS "${FLAGS} /DNTDDI_VERSION=0x06010000 /D_WIN32_WINNT=0x601")
	if(DEBUG)
		add_compile_options(/DDEBUG=1)
	endif()
	if(USE_STATIC_LIBS)
		add_compile_options(/DTGUI5_STATIC /DSHIM3_STATIC /DWEDGE3_STATIC)
	endif()
	if(STEAMWORKS)
		add_compile_options(/DSTEAMWORKS)
		set(LIBS ${LIBS} steam_api64)
	endif()
	if(DEMO)
		add_compile_options(/DDEMO)
	endif()
	if(WANT_TTF)
		add_compile_options(/DUSE_TTF)
	endif()
	set(LIBS ${LIBS} ${WEDGE3_LIB} ${SHIM3_LIB} ${TGUI5_LIB} SDL2 SDL2main ogg FLAC zlibstatic d3d9 winmm dbghelp shcore)
else() # Linux
	add_compile_options(-Wall -Wno-comment -Wno-strict-aliasing -std=c++0x)
	add_link_options(-Wl,-rpath,\$ORIGIN)
	if(DEBUG)
		add_compile_options(-g -fno-omit-frame-pointer -fsanitize=address -fsanitize-recover=address -fsanitize-address-use-after-scope)
		add_link_options(-fno-omit-frame-pointer -fsanitize=address -fsanitize-recover=address -fsanitize-address-use-after-scope)
		#add_compile_options(-g -fsanitize=leak)
		set(LIBS ${LIBS} asan)
	endif()
	if(STEAMWORKS)
		add_compile_definitions(STEAMWORKS)
		set(LIBS ${LIBS} steam_api)
	endif()
	if(DEMO)
		add_compile_definitions(DEMO)
	endif()
	set(LIBS ${LIBS} wedge3 shim3 tgui5 SDL2 GL Xcursor X11 FLAC ogg z)
endif()

add_executable("tth" ${SOURCES})
set_target_properties("tth" PROPERTIES OUTPUT_NAME "tth")
target_link_libraries("tth" ${LIBS})
