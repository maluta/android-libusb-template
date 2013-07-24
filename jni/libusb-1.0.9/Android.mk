LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
  libusb/core.c \
  libusb/descriptor.c \
  libusb/io.c \
  libusb/sync.c \
  libusb/os/linux_usbfs.c \
  libusb/os/threads_posix.c

LOCAL_C_INCLUDES += \
  $(LOCAL_PATH)/android \
  $(LOCAL_PATH)/libusb \
  $(LOCAL_PATH)/libusb/os

LOCAL_CFLAGS += \
  -DLIBUSB_DESCRIBE=""

LOCAL_MODULE:= libusb-1.0
include $(BUILD_SHARED_LIBRARY)
