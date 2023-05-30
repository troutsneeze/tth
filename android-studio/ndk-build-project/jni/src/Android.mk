LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL2
TGUI_PATH := ../../../../tgui5
SHIM_PATH := ../../../../shim3
WEDGE_PATH := ../../../../wedge3
TTH_PATH := ../../../../../tth
ANDROID_DIR := ../../../../../android.newer

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include \
	$(LOCAL_PATH)/$(TGUI_PATH)/include \
	$(LOCAL_PATH)/$(SHIM_PATH)/include \
	$(LOCAL_PATH)/$(WEDGE_PATH)/include \
	$(LOCAL_PATH)/$(TTH_PATH)/include \
	$(LOCAL_PATH)/$(ANDROID_DIR)/$(TARGET_ARCH_ABI)/include \

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
	$(TGUI_PATH)/src/tgui5.cpp \
	$(TGUI_PATH)/src/tgui5_sdl.cpp \
	$(SHIM_PATH)/src/a_star.cpp \
	$(SHIM_PATH)/src/achievements.cpp \
	$(SHIM_PATH)/src/audio.cpp \
	$(SHIM_PATH)/src/cd.cpp \
	$(SHIM_PATH)/src/cloud.cpp \
	$(SHIM_PATH)/src/cpa.cpp \
	$(SHIM_PATH)/src/crash.cpp \
	$(SHIM_PATH)/src/devsettings.cpp \
	$(SHIM_PATH)/src/error.cpp \
	$(SHIM_PATH)/src/flac.cpp \
	$(SHIM_PATH)/src/font.cpp \
	$(SHIM_PATH)/src/gfx.cpp \
	$(SHIM_PATH)/src/gui.cpp \
	$(SHIM_PATH)/src/image.cpp \
	$(SHIM_PATH)/src/input.cpp \
	$(SHIM_PATH)/src/interp.cpp \
	$(SHIM_PATH)/src/json.cpp \
	$(SHIM_PATH)/src/md5.cpp \
	$(SHIM_PATH)/src/mml.cpp \
	$(SHIM_PATH)/src/model.cpp \
	$(SHIM_PATH)/src/mt19937ar.cpp \
	$(SHIM_PATH)/src/pixel_font.cpp \
	$(SHIM_PATH)/src/primitives.cpp \
	$(SHIM_PATH)/src/sample.cpp \
	$(SHIM_PATH)/src/shader.cpp \
	$(SHIM_PATH)/src/shim.cpp \
	$(SHIM_PATH)/src/sound.cpp \
	$(SHIM_PATH)/src/sprite.cpp \
	$(SHIM_PATH)/src/tilemap.cpp \
	$(SHIM_PATH)/src/tokenizer.cpp \
	$(SHIM_PATH)/src/translation.cpp \
	$(SHIM_PATH)/src/ttf.cpp \
	$(SHIM_PATH)/src/utf8.cpp \
	$(SHIM_PATH)/src/util.cpp \
	$(SHIM_PATH)/src/vertex_cache.cpp \
	$(SHIM_PATH)/src/vorbis.cpp \
	$(SHIM_PATH)/src/widgets.cpp \
	$(SHIM_PATH)/src/xml.cpp \
	$(WEDGE_PATH)/src/achieve.cpp \
	$(WEDGE_PATH)/src/area.cpp \
	$(WEDGE_PATH)/src/area_game.cpp \
	$(WEDGE_PATH)/src/a_star.cpp \
	$(WEDGE_PATH)/src/battle_end.cpp \
	$(WEDGE_PATH)/src/battle_enemy.cpp \
	$(WEDGE_PATH)/src/battle_entity.cpp \
	$(WEDGE_PATH)/src/battle_game.cpp \
	$(WEDGE_PATH)/src/battle_player.cpp \
	$(WEDGE_PATH)/src/branch.cpp \
	$(WEDGE_PATH)/src/change_angle.cpp \
	$(WEDGE_PATH)/src/check_positions.cpp \
	$(WEDGE_PATH)/src/chest.cpp \
	$(WEDGE_PATH)/src/delay.cpp \
	$(WEDGE_PATH)/src/delete_map_entity.cpp \
	$(WEDGE_PATH)/src/fade.cpp \
	$(WEDGE_PATH)/src/game.cpp \
	$(WEDGE_PATH)/src/general.cpp \
	$(WEDGE_PATH)/src/generic_callback.cpp \
	$(WEDGE_PATH)/src/generic_immediate_callback.cpp \
	$(WEDGE_PATH)/src/generic_gui.cpp \
	$(WEDGE_PATH)/src/give_object.cpp \
	$(WEDGE_PATH)/src/globals.cpp \
	$(WEDGE_PATH)/src/input.cpp \
	$(WEDGE_PATH)/src/inventory.cpp \
	$(WEDGE_PATH)/src/look_around_input.cpp \
	$(WEDGE_PATH)/src/main.cpp \
	$(WEDGE_PATH)/src/map_entity.cpp \
	$(WEDGE_PATH)/src/npc.cpp \
	$(WEDGE_PATH)/src/offset_arc.cpp \
	$(WEDGE_PATH)/src/omnipresent.cpp \
	$(WEDGE_PATH)/src/onscreen_controller.cpp \
	$(WEDGE_PATH)/src/pause_player_input.cpp \
	$(WEDGE_PATH)/src/pause_presses.cpp \
	$(WEDGE_PATH)/src/pause_sprite.cpp \
	$(WEDGE_PATH)/src/pause_task.cpp \
	$(WEDGE_PATH)/src/play_animation.cpp \
	$(WEDGE_PATH)/src/play_music.cpp \
	$(WEDGE_PATH)/src/play_sound.cpp \
	$(WEDGE_PATH)/src/player_input.cpp \
	$(WEDGE_PATH)/src/rumble.cpp \
	$(WEDGE_PATH)/src/screen_shake.cpp \
	$(WEDGE_PATH)/src/set_animation.cpp \
	$(WEDGE_PATH)/src/set_direction.cpp \
	$(WEDGE_PATH)/src/set_integer.cpp \
	$(WEDGE_PATH)/src/set_milestone_complete.cpp \
	$(WEDGE_PATH)/src/set_music_volume.cpp \
	$(WEDGE_PATH)/src/set_solid.cpp \
	$(WEDGE_PATH)/src/set_visible.cpp \
	$(WEDGE_PATH)/src/shop_step.cpp \
	$(WEDGE_PATH)/src/slide_entity.cpp \
	$(WEDGE_PATH)/src/slide_entity_offset.cpp \
	$(WEDGE_PATH)/src/special_number.cpp \
	$(WEDGE_PATH)/src/spells.cpp \
	$(WEDGE_PATH)/src/stats.cpp \
	$(WEDGE_PATH)/src/step.cpp \
	$(WEDGE_PATH)/src/stop_music.cpp \
	$(WEDGE_PATH)/src/stop_sound.cpp \
	$(WEDGE_PATH)/src/system.cpp \
	$(WEDGE_PATH)/src/task.cpp \
	$(WEDGE_PATH)/src/tile_movement.cpp \
	$(WEDGE_PATH)/src/wait.cpp \
	$(WEDGE_PATH)/src/wait_for_integer.cpp \
	$(WEDGE_PATH)/src/wander_input.cpp \
	$(TTH_PATH)/src/achievements.cpp \
	$(TTH_PATH)/src/area_game.cpp \
	$(TTH_PATH)/src/autosave.cpp \
	$(TTH_PATH)/src/battle_combo_drawer.cpp \
	$(TTH_PATH)/src/battle_game.cpp \
	$(TTH_PATH)/src/battle_player.cpp \
	$(TTH_PATH)/src/battle_transition_in.cpp \
	$(TTH_PATH)/src/battle_transition_in2.cpp \
	$(TTH_PATH)/src/battle_transition_out.cpp \
	$(TTH_PATH)/src/battle_transition_out2.cpp \
	$(TTH_PATH)/src/battles.cpp \
	$(TTH_PATH)/src/coin.cpp \
	$(TTH_PATH)/src/combo.cpp \
	$(TTH_PATH)/src/dialogue.cpp \
	$(TTH_PATH)/src/enemies.cpp \
	$(TTH_PATH)/src/general.cpp \
	$(TTH_PATH)/src/globals.cpp \
	$(TTH_PATH)/src/gui.cpp \
	$(TTH_PATH)/src/gui_drawing_hook.cpp \
	$(TTH_PATH)/src/hit.cpp \
	$(TTH_PATH)/src/inventory.cpp \
	$(TTH_PATH)/src/menu.cpp \
	$(TTH_PATH)/src/pan_camera.cpp \
	$(TTH_PATH)/src/question.cpp \
	$(TTH_PATH)/src/start_battle.cpp \
	$(TTH_PATH)/src/transition.cpp \
	$(TTH_PATH)/src/tth.cpp \
	$(TTH_PATH)/src/widgets.cpp

LOCAL_SHARED_LIBRARIES := SDL2

LOCAL_CFLAGS := -Wall -DANDROID -DUSE_FLAC -Wno-absolute-value -fvisibility=hidden
LOCAL_LDLIBS := -L$(LOCAL_PATH)/$(ANDROID_DIR)/$(TARGET_ARCH_ABI)/lib -llog -lGLESv1_CM -lGLESv2 -lFLAC-static -lzstatic

include $(BUILD_SHARED_LIBRARY)
