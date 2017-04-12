# This package depends on boost, which is not yet available:
# https://github.com/ledger/ledger#user-content-dependencies
TERMUX_PKG_HOMEPAGE=http://ledger-cli.org/
TERMUX_PKG_DESCRIPTION="Powerful, double-entry accounting system"
TERMUX_PKG_VERSION=2015.2
TERMUX_PKG_SRCURL=http://www.qhull.org/download/qhull-2015-src-7.2.0.tgz
TERMUX_PKG_SHA256=78b010925c3b577adc3d58278787d7df08f7c8fb02c3490e375eab91bb58a436
#TERMUX_PKG_SRCURL=https://github.com/qhull/qhull/archive/f0bd8ceeb84b554d7cdde9bbfae7d3351270478c.zip
#TERMUX_PKG_SHA256=d85fd6e40ff903a26a1009119201e3b152a8d760f2adb7e4b57cbd29806e404f
TERMUX_PKG_FOLDERNAME=qhull-2015.2
#TERMUX_PKG_FOLDERNAME="qhull-f0bd8ceeb84b554d7cdde9bbfae7d3351270478c"
TERMUX_PKG_KEEP_STATIC_LIBRARIES=no
TERMUX_PKG_MAINTAINER="@its-pointless github"
#TERMUX_PKG_BUILD_IN_SRC=yes
# TERMUX_PKG_DEPENDS="..."
#termux_step_pre_configure () {
#export LDFLAGS+=" -lgnustl_shared"
#}

##termux_step_configure() {
#if [ $TERMUX_ARCH = "arm" ];
#then
#export TCC=arm-linux-androideabi-clang
###export 	TCXX=arm-linux-androideabi-clang++
#make install -j4 
#else 
#export TCC=aarch64-linux-android-clang
#export TCXX=aarch64-linux-android-clang++
#make install -j4
#fi
#}
