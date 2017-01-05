TERMUX_PKG_HOMEPAGE=http://www.openblas.net/
TERMUX_PKG_DESCRIPTION="openblas"
TERMUX_PKG_VERSION=0.2.19
#TERMUX_PKG_BUILD_REVISION=
TERMUX_PKG_SRCURL=http://github.com/xianyi/OpenBLAS/archive/v${TERMUX_PKG_VERSION}.tar.gz
TERMUX_PKG_FOLDERNAME="OpenBLAS-${TERMUX_PKG_VERSION}"
TERMUX_PKG_BUILD_IN_SRC=yes
TERMUX_PKG_NO_DEVELSPLIT=yes
TERMUX_PKG_KEEP_STATIC_LIBRARIES=yes
#TERMUX_PKG_DEPENDS="gcc-6"
#haven't tested yet on x86
TERMUX_PKG_BLACKLISTED_ARCHES="x86_64, i686, arm"
export NO_STATIC=1
termux_step_make () {
unset CFLAGS
unset FFLAGS
FFLAGS="-O2 -L/data/data/com.termux/files/usr/lib"
CFLAGS="-O2 -L/data/data/com.termux/files/usr/lib -spec=/root/termux-packages/termux.spec"
#if [ $TERMUX_ARCH == 'aarch64' ]; then
make TARGET=ARMV8 BINARY=64 HOSTCC=gcc CC=aarch64-linux-android-gcc FC=aarch64-linux-android-gfortran  -j  ${TERMUX_MAKE_PROCESSES} 
aarch64-linux-android-gcc -shared -o libopenblas_armv8p-r0.2.19.so -L/root/termux-packages/z/openblas/src -Wl,--whole-archive  -l:libopenblas_armv8p-r0.2.19.a -Wl,--no-whole-archive -lm -L/data/data/com.termux/files/usr/lib -lgfortran -lm
#aarch64-linux-android-gcc -shared -o libopenblas_armv8p-r${TERMUX_PKG_VERSION}.so -L/root/termux-packages/z/openblas/src -Wl,--whole-archive  -lopenblas_armv8p-r${TERMUX_PKG_VERSION} -Wl,--no-whole-archive -lm -L/data/data/com.termux/files/usr/lib -l:libgfortran.so -lm 
#ln -s libopenblas_armv8p-r${TERMUX_PKG_VERSION}.so libopenblas.so
#		aarch64-linux-android-gcc -shared -Wl,--whole-archive -o libopenblas.so -L/data/data/com.termux/files/usr/lib  -lopenblas_armv8p-r${TERMUX_PKG_VERSION} -Wl,--no-whole-archive -lgcc -lm -lgfortran		
		#else 
	#make TARGET=ARMV7 HOSTCC=gcc CC=arm-linux-androideabi-gcc FC=arm-linux-androideabi-gfortran -j  ${TERMUX_MAKE_PROCESSES}
#fi
termux_step_make_install () {
	make install  TARGET=ARMV8 BINARY=64 HOSTCC=gcc CC=aarch64-linux-android-gcc FC=aarch64-linux-android-gfortran NO_STATIC=1 PREFIX=/data/data/com.termux/files/usr 
	cp libopenblas_armv8p-r${TERMUX_PKG_VERSION}.so  /data/data/com.termux/files/usr/lib
	cd /data/data/com.termux/files/usr/lib
	ln -s libopenblas_armv8p-r${TERMUX_PKG_VERSION}.so libopenblas.so
}
