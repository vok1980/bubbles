 
all:
	@echo use android target to build android


android:
	make android.cmake
	make android.build


android.cmake:
	mkdir -p build.android
	cd build.android && cmake -DANDROID=true ..


android.build:
	cd build.android && make
