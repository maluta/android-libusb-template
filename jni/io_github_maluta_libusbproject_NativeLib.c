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
	libusb_device **devs;
	int r;
	ssize_t cnt;
	int ret;

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
			//goto out4;
		}
		__android_log_print(ANDROID_LOG_DEBUG, "LOG_TAG", "%x:%x",desc.idVendor, desc.idProduct);
		//if ((desc.idVendor == 0x0403) && (desc.idProduct == 0x6001))
		//	break;
	}

	/*	ret = libusb_open(dev, &device_handle);
	 if (ret != 0) {
	 //goto out4;
	 }

	 if (device_handle == NULL) {
	 //goto out4;
	 }*/

	/*switch (libusb_kernel_driver_active(device_handle, interface)) {
	 case 0: {
	 // nothing to do
	 break;
	 }
	 case 1: {
	 // driver active
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
	 }

	 // get interface
	 if (libusb_claim_interface(device_handle, interface) != 0) {
	 //goto out1;
	 }*/

	/*libusb_control_transfer(device_handle,
	 LIBUSB_ENDPOINT_OUT | LIBUSB_REQUEST_TYPE_VENDOR
	 | LIBUSB_RECIPIENT_INTERFACE, 0, 0x0000, 0, 0, 0, 250);
	 */
	// libusb_bulk_transfer(device_handle, (0x02 | LIBUSB_ENDPOINT_OUT),relay/*&byte*/, 1, &actual, 1000);
	//libusb_release_interface(device_handle, interface);

	return (*env)->NewStringUTF(env, "OK!");
}
