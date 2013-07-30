TOOLCHAIN:=x

ANDROID_EABI:=armeabi
ARM_SO_DIR:=../src/platform/android/Bubbles/libs
ANDROID_BUILD_DIR:=android


all:
	@echo use android target to build android


android:
	make android.cmake
	make android.build


android.cmake:
	make check.toolchain

	mkdir -p $(ANDROID_BUILD_DIR)
	cd $(ANDROID_BUILD_DIR) && \
		PATH="$(TOOLCHAIN)/bin:$(PATH)" \
		LDFLAGS="-lstdc++ -lGLESv1_CM -llog" \
		CFLAGS="-DANDROID -O0" \
		CXXFLAGS="-DANDROID -O0 -std=c++11" \
		CC=arm-linux-androideabi-gcc CXX=arm-linux-androideabi-g++ \
		cmake -DANDROID=true ../../src

clean:
	rm -rf $(ANDROID_BUILD_DIR)

android.build:
	cd $(ANDROID_BUILD_DIR) && make
	mkdir -p $(ARM_SO_DIR)/$(ANDROID_EABI)
	cp $(ANDROID_BUILD_DIR)/platform/android/*.so $(ARM_SO_DIR)/$(ANDROID_EABI)


check.toolchain:
	@if [ -d $(TOOLCHAIN)/bin ] ; then true ; \
	else echo "Couldn't locate toolchain directory, please invoke make with \"make TOOLCHAIN=/path/to/android/ndk/toolchain ...\"" ; exit 1 ; \
	fi


