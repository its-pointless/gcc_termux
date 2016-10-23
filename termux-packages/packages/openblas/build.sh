TERMUX_PKG_HOMEPAGE=http://www.openblas.net/
TERMUX_PKG_DESCRIPTION="openblas"
TERMUX_PKG_VERSION=0.2.19
#TERMUX_PKG_BUILD_REVISION=
TERMUX_PKG_SRCURL=http://github.com/xianyi/OpenBLAS/archive/v${TERMUX_PKG_VERSION}.tar.gz
TERMUX_PKG_FOLDERNAME="OpenBLAS-${TERMUX_PKG_VERSION}"
TERMUX_PKG_BUILD_IN_SRC=yes
TERMUX_PKG_NO_DEVELSPLIT=yes
TERMUX_PKG_KEEP_STATIC_LIBRARIES=yes
#TERMUX_PKG_DEPENDS=""
#haven't tested yet on x86
TERMUX_PKG_BLACKLISTED_ARCHES="x86_64, i686"
termux_step_make () {
	
	if [ $TERMUX_ARCH == 'aarch64' ]; then
		make TARGET=ARMV8 BINARY=64 HOSTCC=gcc CC=aarch64-linux-android-gcc FC=aarch64-linux-android-gfortran -j  ${TERMUX_MAKE_PROCESSES} 
	else 
	make TARGET=ARMV7 HOSTCC=gcc CC=arm-linux-androideabi-gcc FC=arm-linux-androideabi-gfortran -j  ${TERMUX_MAKE_PROCESSES}
fi
}

