TERMUX_PKG_HOMEPAGE=https://boost.org
TERMUX_PKG_DESCRIPTION="cpp libs"
TERMUX_PKG_VERSION=1.60.0
TERMUX_PKG_SRCURL=http://sourceforge.net/projects/boost/files/boost/1.60.0/boost_1_60_0.tar.bz2
TERMUX_PKG_SHA256=686affff989ac2488f79a97b9479efb9f2abae035b5ed4d8226de6857933fd3b
TERMUX_PKG_FOLDERNAME="boost_1_60_0"
TERMUX_PKG_BUILD_IN_SRC=yes
TERMUX_PKG_DEPENDS="libbz2"
termux_step_configure(){
	return 0;
}
termux_step_make() {
	return 0;
}
termux_step_make_install() {
	./bootstrap.sh
	echo "using clang : $TERMUX_ARCH : $CXX : <linkflags>-L/data/data/com.termux/files/usr/lib ; " >> project-config.jam
	./b2  target-os=android \
		include=/data/data/com.termux/files/usr/include \
		toolset=clang-$TERMUX_ARCH \
		--prefix="$TERMUX_PREFIX"  \
		--with-date_time \
		--with-filesystem \
		--with-system \
		--with-iostreams \
		--with-regex \
		--with-test \
		-q \
		cxxflags="$CXXFLAGS" \
		link=shared \
		threading=multi \
		install
}
