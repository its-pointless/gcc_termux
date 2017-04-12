TERMUX_PKG_HOMEPAGE=http://www.openblas.net/
TERMUX_PKG_DESCRIPTION="openblas"
TERMUX_PKG_VERSION=0.2.19
TERMUX_PKG_REVISION=2
TERMUX_PKG_SRCURL=http://github.com/xianyi/OpenBLAS/archive/v${TERMUX_PKG_VERSION}.tar.gz
TERMUX_PKG_FOLDERNAME="OpenBLAS-${TERMUX_PKG_VERSION}"
TERMUX_PKG_BUILD_IN_SRC=yes
TERMUX_PKG_NO_DEVELSPLIT=yes
TERMUX_PKG_DEPENDS="libgcc, libgfortran"
TERMUX_PKG_MAINTAINER=" @its-pointless github"
TERMUX_PKG_SHA256=9c40b5e4970f27c5f6911cb0a28aa26b6c83f17418b69f8e5a116bb983ca8557
TERMUX_PKG_MAINTAINER="@its-pointless github"
FC=${TERMUX_HOST_PLATFORM}-gfortran
# not tested but should work okay on x86_64 i686 with a fixed up script
TERMUX_PKG_BLACKLISTED_ARCHES="x86_64, i686, arm"

termux_step_configure () {
return 0
}
termux_step_make () {
	 CFLAGS=" -lm -lgfortran"
	LDFLAGS=" -lm -lgfortran"
#without setting num threads to this scipy fails unit tests	
		make NUM_THREADS=32  TARGET=ARMV8 BINARY=64 HOSTCC=gcc CC=aarch64-linux-android-gcc  FC=aarch64-linux-android-gfortran -j  ${TERMUX_MAKE_PROCESSES} 
}
termux_step_post_make_install() {
unset BLAS
unset LAPACK
	cd $TERMUX_PREFIX/lib 
	$TERMUX_CONTERT_TOSOLIB libopenblas.a
}
