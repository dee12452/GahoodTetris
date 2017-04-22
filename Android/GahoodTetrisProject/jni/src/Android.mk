LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main
LOCAL_CFLAGS += -std=c++11
LOCAL_CFLAGS += -Wall

SDL_PATH := ../SDL2
SDL_IMG_PATH := ../SDL2_image
FILE_LIST := $(wildcard $(LOCAL_PATH)/*.cpp)
FILE_LIST_ANIMATION := $(wildcard $(LOCAL_PATH)/animation/*.cpp)
FILE_LIST_DRAWABLE := $(wildcard $(LOCAL_PATH)/drawable/*.cpp)
FILE_LIST_GAME := $(wildcard $(LOCAL_PATH)/game/*.cpp)
FILE_LIST_INPUT := $(wildcard $(LOCAL_PATH)/input/*.cpp)
FILE_LIST_SPRITE := $(wildcard $(LOCAL_PATH)/sprite/*.cpp)
FILE_LIST_UTIL := $(wildcard $(LOCAL_PATH)/util/*.cpp)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(SDL_IMG_PATH)

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
	$(FILE_LIST:$(LOCAL_PATH)/%=%) \
	$(FILE_LIST_GAME:$(LOCAL_PATH)/%=%) \
	$(FILE_LIST_UTIL:$(LOCAL_PATH)/%=%) \
	$(FILE_LIST_SPRITE:$(LOCAL_PATH)/%=%) \
	$(FILE_LIST_INPUT:$(LOCAL_PATH)/%=%) \
	$(FILE_LIST_DRAWABLE:$(LOCAL_PATH)/%=%) \
	$(FILE_LIST_ANIMATION:$(LOCAL_PATH)/%=%)

LOCAL_SHARED_LIBRARIES := SDL2
LOCAL_SHARED_LIBRARIES += SDL2_image

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

include $(BUILD_SHARED_LIBRARY)
