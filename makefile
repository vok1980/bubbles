TOOLCHAIN:=x

ARM_SO_DIR:=src/starter.android/Bubbles/libs/armeabi/

all:
	@echo use android target to build android


android:
	make android.cmake
	make android.build


android.cmake:
	make check.toolchain

	mkdir -p build.android
	cd build.android && \
		PATH="$(TOOLCHAIN)/bin:$(PATH)" \
		LDFLAGS="-lstdc++ -lGLESv1_CM -llog" \
		CFLAGS="-DANDROID -O0" \
		CXXFLAGS="-DANDROID -O0 -std=c++11" \
		CC=arm-linux-androideabi-gcc CXX=arm-linux-androideabi-g++ \
		cmake -DANDROID=true ..

clean:
	rm -rf build.android

android.build:
	cd build.android && make
	mkdir -p $(ARM_SO_DIR)
	cp build.android/src/starter.android/*.so $(ARM_SO_DIR)


check.toolchain:
	@if [ -d $(TOOLCHAIN)/bin ] ; then true ; \
	else echo "Couldn't locate android NDK toolchain directory, please invoke make with \"make TOOLCHAIN=/path/to/android/ndk/toolchain ...\"" ; exit 1 ; \
	fi


