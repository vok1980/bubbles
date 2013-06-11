TOOLCHAIN:=x
####test  
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
		LDFLAGS="" \
		CFLAGS="-DANDROID -O0" \
		CXXFLAGS="-DANDROID -O0 -std=c++11" \
		CC=arm-linux-androideabi-gcc CXX=arm-linux-androideabi-g++ \
		cmake ..

### -DANDROID=true


android.build:
	cd build.android && make


check.toolchain:
	@if [ -d $(TOOLCHAIN)/bin ] ; then true ; \
	else echo "Couldn't locate android NDK toolchain directory, please invoke make with \"make TOOLCHAIN=/path/to/android/ndk/toolchain ...\"" ; exit 1 ; \
	fi
