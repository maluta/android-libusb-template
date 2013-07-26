LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := libusbproject_jni
LOCAL_SRC_FILES := io_github_maluta_libusbproject_NativeLib.c
LOCAL_C_INCLUDES := \
  $(LOCAL_PATH)/libusb-1.0.9/android/include
#LOCAL_LDLIBS := -L$(LOCAL_PATH)/prebuilt
LOCAL_LDLIBS := -llog
LOCAL_SHARED_LIBRARIES := libusb-1.0
LOCAL_ALLOW_UNDEFINED_SYMBOLS := false
include $(BUILD_SHARED_LIBRARY)

include $(call all-makefiles-under,$(LOCAL_PATH))
