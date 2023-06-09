cmake_minimum_required(VERSION 3.0)
project(wedge3)

option(DEBUG "Build for debugging" OFF)
option(SHARED "Build as a shared library" OFF)
option(USE_STATIC_LIBS "Link with static libraries" ON)
option(RASPBERRYPI "Build for Raspberry Pi" OFF)
option(RASPBERRYPI_NORMAL "Build for Raspberry Pi (standard)" OFF)
option(USE_D3DX "Use D3DX to compiler shaders online" OFF)
option(STEAMWORKS "Build for Steam" off)
option(MAS "Build for Mac App Store" off)
option(ASHEDIT_TRAILER "Build AshEdit trailer" off)
option(WANT_TTF "Build with TTF support" OFF)

set(USER_INCLUDE_PATH "" CACHE FILEPATH "Any extra include directories you want")
set(USER_LIBRARY_PATH "" CACHE FILEPATH "Any extra library directories you want")

include_directories("include")
include_directories(${USER_INCLUDE_PATH})
link_directories(${USER_LIBRARY_PATH})

# Inputs

set(LIB_SOURCES
	src/achieve.cpp
	src/area.cpp
	src/area_game.cpp
	src/a_star.cpp
	src/battle_end.cpp
	src/battle_enemy.cpp
	src/battle_entity.cpp
	src/battle_game.cpp
	src/battle_player.cpp
	src/branch.cpp
	src/change_angle.cpp
	src/check_positions.cpp
	src/chest.cpp
	src/delay.cpp
	src/delete_map_entity.cpp
	src/fade.cpp
	src/game.cpp
	src/general.cpp
	src/generic_callback.cpp
	src/generic_immediate_callback.cpp
	src/generic_gui.cpp
	src/give_object.cpp
	src/globals.cpp
	src/input.cpp
	src/inventory.cpp
	src/look_around_input.cpp
	src/main.cpp
	src/map_entity.cpp
	src/npc.cpp
	src/offset_arc.cpp
	src/omnipresent.cpp
	src/onscreen_controller.cpp
	src/pause_player_input.cpp
	src/pause_presses.cpp
	src/pause_sprite.cpp
	src/pause_task.cpp
	src/play_animation.cpp
	src/play_music.cpp
	src/play_sound.cpp
	src/player_input.cpp
	src/rumble.cpp
	src/screen_shake.cpp
	src/set_animation.cpp
	src/set_direction.cpp
	src/set_integer.cpp
	src/set_music_volume.cpp
	src/set_milestone_complete.cpp
	src/set_solid.cpp
	src/set_visible.cpp
	src/shop_step.cpp
	src/slide_entity.cpp
	src/slide_entity_offset.cpp
	src/special_number.cpp
	src/spells.cpp
	src/stats.cpp
	src/step.cpp
	src/stop_music.cpp
	src/stop_sound.cpp
	src/system.cpp
	src/task.cpp
	src/tile_movement.cpp
	src/wait.cpp
	src/wait_for_integer.cpp
	src/wander_input.cpp
)

if(WIN32 AND SHARED)
	LIST(APPEND LIB_SOURCES versioninfo.rc)
endif()

# Outputs

set(WEDGE_LIB wedge3)

# Platform specifics

if(MINGW)
	if(NOT SHARED)
		add_compile_definitions(WEDGE3_STATIC)
	endif()
	if(DEBUG)
		add_compile_options(-g -fno-omit-frame-pointer -fsanitize=address -fsanitize-recover=address -fsanitize-address-use-after-scope)
		add_link_options(-fno-omit-frame-pointer -fsanitize=address -fsanitize-recover=address -fsanitize-address-use-after-scope)
		#add_compile_options(-g -fsanitize=leak)
	endif()
	if(USE_STATIC_LIBS)
		add_compile_definitions(TGUI5_STATIC SHIM3_STATIC)
	else()
		set(LIBS tgui4 shim2 SDL2)
	endif()
	if(USE_D3DX)
		add_compile_definitions(USE_D3DX)
	endif()
	if(STEAMWORKS)
		add_compile_definitions(STEAMWORKS)
	endif()
	if(WANT_TTF)
		add_compile_definitions(USE_TTF)
	endif()
	if(SHARED)
		set(LIBS ${LIBS} zlibstatic)
	endif()
elseif(WIN32)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ignore:4099")
	SET(FLAGS "/D_CRT_SECURE_NO_WARNINGS /D_USE_MATH_DEFINES /EHsc /MP /W3 /wd4244 /wd4800 /wd4101 /MT /DWEDGE3_BUILD /Gy")
	SET(FLAGS "${FLAGS} /DNTDDI_VERSION=0x06010000 /D_WIN32_WINNT=0x601")
	if(NOT SHARED)
		add_compile_options(/DWEDGE3_STATIC)
	endif()
	if(DEBUG)
		add_compile_options(/DDEBUG)
	endif()
	if(USE_STATIC_LIBS)
		add_compile_options(/DTGUI5_STATIC /DSHIM3_STATIC)
	else()
		set(LIBS tgui4 shim2 SDL2)
	endif()
	if(USE_D3DX)
		add_compile_options(/DUSE_D3DX)
	endif()
	if(STEAMWORKS)
		SET(FLAGS "${FLAGS} /DSTEAMWORKS")
	endif()
	if(ASHEDIT_TRAILER)
		SET(FLAGS "${FLAGS} /DASHEDIT_TRAILER")
	endif()
	if(WANT_TTF)
		add_compile_options(/DUSE_TTF)
	endif()
	if(SHARED)
		set(LIBS ${LIBS} zlibstatic)
	endif()
else() # Linux
	add_compile_options(-fpermissive -fvisibility=hidden -Wall -Wno-psabi -Wno-strict-aliasing -Wno-comment -std=c++0x)
	if(STEAMWORKS)
		add_compile_definitions(STEAMWORKS)
	endif()
	if(DEBUG)
		add_compile_options(-g -fno-omit-frame-pointer -fsanitize=address -fsanitize-recover=address -fsanitize-address-use-after-scope)
		add_link_options(-fno-omit-frame-pointer -fsanitize=address -fsanitize-recover=address -fsanitize-address-use-after-scope)
		#add_compile_options(-g -fsanitize=leak)
	endif()
	IF(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" AND SHARED)
		add_compile_options(-fPIC)
	ENDIF()
	if (RASPBERRYPI)
		add_compile_definitions(RASPBERRYPI=1)
		add_compile_definitions(RASPBERRYPI=1)
	endif()
	if (RASPBERRYPI_NORMAL)
		add_compile_definitions(RASPBERRYPI_NORMAL=1)
		add_compile_definitions(RASPBERRYPI_NORMAL=1)
	endif()
	if (NOT DEBUG AND (RASPBERRYPI OR RASPBERRYPI_NORMAL))
		set(CMAKE_C_FLAGS_RELEASE "-Os")
		set(CMAKE_CXX_FLAGS_RELEASE "-Os")
	endif()
	if (NOT RASPBERRYPI AND NOT RASPBERRYPI_NORMAL)
		set(CMAKE_C_FLAGS_RELEASE "-O2")
		set(CMAKE_CXX_FLAGS_RELEASE "-O2")
	endif()
	if(RASPBERRYPI)
		include_directories("/opt/vc/include")
	endif()
endif()

if(SHARED)
	add_library(${WEDGE_LIB} SHARED ${LIB_SOURCES})
else()
	add_library(${WEDGE_LIB} STATIC ${LIB_SOURCES})
endif()
target_link_libraries(${WEDGE_LIB} ${LIBS})
