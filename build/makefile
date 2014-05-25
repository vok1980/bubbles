TOOLCHAIN:=x

#ANDROID_EABI:=armeabi
ARM_SO_DIR:=../src/platform/android/Bubbles/libs
ANDROID_BUILD_DIR:=android
ANDROID_TOOLCHAINS_DIR:=$(CURDIR)/../tools/android-toolchains


all:
	@echo use android target to build android


android: android.arm android.mips android.x86
#	make android.cmake
#	make android.build

android.arm: android.armeabi android.armeabi-v7a

android.armeabi:  
	make \
		PATH="${ANDROID_TOOLCHAINS_DIR}/arm-linux-androideabi-4.8/bin:$(PATH)" \
		BUILD_DIR=android.arm \
		ANDROID_EABI:=armeabi	\
		LDFLAGS="-lstdc++ -lGLESv1_CM -llog" \
		CFLAGS="-mthumb -DANDROID -O0" \
		CXXFLAGS="-mthumb -DANDROID -O0 -std=c++11" \
		CC=arm-linux-androideabi-gcc CXX=arm-linux-androideabi-g++ \
		CMAKE_DEF="-DANDROID=true" \
	android.build  

android.armeabi-v7a:  
	make \
		PATH="${ANDROID_TOOLCHAINS_DIR}/arm-linux-androideabi-4.8/bin:$(PATH)" \
		BUILD_DIR=android.armv7-a \
		ANDROID_EABI:=armeabi-v7a 	\
		LDFLAGS="-lstdc++ -lGLESv1_CM -llog" \
		CFLAGS="-march=armv7-a -mfloat-abi=softfp -DANDROID -O0" \
		CXXFLAGS="-march=armv7-a -mfloat-abi=softfp -DANDROID -O0 -std=c++11" \
		CC=arm-linux-androideabi-gcc CXX=arm-linux-androideabi-g++ \
		CMAKE_DEF="-DANDROID=true" \
	android.build  

android.mips: 
	make \
		PATH="${ANDROID_TOOLCHAINS_DIR}/mipsel-linux-android-4.8/bin:$(PATH)" \
		BUILD_DIR=android.mips \
		ANDROID_EABI:=mips  	\
		LDFLAGS="-lstdc++ -lGLESv1_CM -llog" \
		CFLAGS="-DANDROID -O0" \
		CXXFLAGS="-DANDROID -O0 -std=c++11" \
		CC=mipsel-linux-android-gcc CXX=mipsel-linux-android-g++ \
		CMAKE_DEF="-DANDROID=true" \
	android.build  

android.x86:
	make \
		PATH="${ANDROID_TOOLCHAINS_DIR}/x86-4.8/bin:$(PATH)" \
		BUILD_DIR=android.x86 \
		ANDROID_EABI:=x86 	\
		LDFLAGS="-lstdc++ -lGLESv1_CM -llog" \
		CFLAGS="-DANDROID -O0" \
		CXXFLAGS="-DANDROID -O0 -std=c++11" \
		CC=i686-linux-android-gcc CXX=i686-linux-android-g++ \
		CMAKE_DEF="-DANDROID=true" \
	android.build  

android.build: android.cmake android.make

android.cmake: 

	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && \
		PATH="${PATH}" \
		LDFLAGS="${LDFLAGS}" \
		CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" \
		CC=${CC} CXX=${CXX} \
		cmake ${CMAKE_DEF} ../../src

clean:
	rm -rf $(ANDROID_BUILD_DIR)

android.make:
	cd $(BUILD_DIR) && make
	mkdir -p $(ARM_SO_DIR)/$(ANDROID_EABI)
	cp $(BUILD_DIR)/platform/android/*.so $(ARM_SO_DIR)/$(ANDROID_EABI)/


check.toolchain:
	@if [ -d $(TOOLCHAIN)/bin ] ; then true ; \
	else echo "Couldn't locate toolchain directory, please invoke make with \"make TOOLCHAIN=/path/to/android/ndk/toolchain ...\"" ; exit 1 ; \
	fi


