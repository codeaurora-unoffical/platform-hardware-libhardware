# Build the keymaster unit tests

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    keymaster_test.cpp

LOCAL_SHARED_LIBRARIES := \
    liblog \
    libutils \
    libboringcrypto \
    libhardware \

LOCAL_MODULE := keymaster_test

LOCAL_MODULE_TAGS := tests

LOCAL_C_INCLUDES += \
	$(LOCAL_PATH)/include \
	$(TOP)/external/boringssl/include 

include $(BUILD_NATIVE_TEST)
