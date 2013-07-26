#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#include <libusb-1.0/libusb.h>
#include <android/log.h>

#include "io_github_maluta_libusbproject_NativeLib.h"

static uint16_t vendor_id = 0x0403;
static uint16_t product_id = 0x6001;
static uint16_t interface = 0x0000;
static libusb_context *context = NULL;
static libusb_device_handle *device_handle = NULL;
static unsigned char ctrl_input = '\0';
static uint16_t actual = 0x0;

JNIEXPORT jstring JNICALL Java_io_github_maluta_libusbproject_NativeLib_listDevices(
		JNIEnv *env, jobject object) {

	libusb_device *dev;
	struct libusb_device_descriptor desc;
	int i = 0;
	int j = 0;
	libusb_device **devs;
	int r;
	ssize_t cnt;
	int ret;

	char usb_list[2000];

	if (context == NULL) {
		if (libusb_init(&context) == 0) {
			__android_log_print(ANDROID_LOG_DEBUG, "LOG_TAG", "libusb_init");
			libusb_set_debug(context, 6);
		}
	}

	cnt = libusb_get_device_list(context, &devs);

	while ((dev = devs[i++]) != NULL) {
		int r = libusb_get_device_descriptor(dev, &desc);
		if (r < 0) {
			fprintf(stderr, "failed to get device descriptor");
		}

		j += sprintf(usb_list+j,"%04x:%04x\n", desc.idVendor, desc.idProduct);

		__android_log_print(ANDROID_LOG_DEBUG, "LOG_TAG", "%x:%x",
				desc.idVendor, desc.idProduct);

	}

	return (*env)->NewStringUTF(env, usb_list);

	/* Some other functions that you can use */

	//	ret = libusb_open(dev, &device_handle);

	// if (device_handle == NULL) { }

	/*
	switch (libusb_kernel_driver_active(device_handle, interface)) {
	case 0: {
		break;
	}
	case 1: {

		if (!libusb_detach_kernel_driver(device_handle, interface)) {
			// unable to detach interface
			libusb_close(device_handle);
			device_handle = NULL;
			//goto out3;
		}
		break;
	}
	default: {
		// error quering the device
		libusb_close(device_handle);
		device_handle = NULL;
		//goto out2;
	}
	}*/

	// get interface
	// if (libusb_claim_interface(device_handle, interface) != 0) { }

	// bulk transfer
	// libusb_bulk_transfer(device_handle, (0x02 | LIBUSB_ENDPOINT_OUT), &byte, 1, &actual, 1000);
    // libusb_release_interface(device_handle, interface);
}
