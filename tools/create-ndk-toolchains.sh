#!/bin/bash

if [ -d "$NDKROOT" ] ; then
	echo "using NDKROOT = \"$NDKROOT\""
else
	echo "Failed to found NDKROOT"
	exit 1;
fi

TOOLCHAINS=$(cat ndk-toolchains-list.txt)
mkdir -p android-toolchains

for tchain in $TOOLCHAINS 
do
	echo $tchain
	$NDKROOT/build/tools/make-standalone-toolchain.sh --platform=android-9 --toolchain=$tchain --install-dir=android-toolchains/$tchain
done