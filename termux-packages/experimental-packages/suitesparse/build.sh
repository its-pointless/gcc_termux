TERMUX_PKG_HOMEPAGE=http://faculty.cse.tamu.edu/davis/suitesparse.html
TERMUX_PKG_DESCRIPTION="SuiteSparse is a suite of sparse matrix algorithms"
TERMUX_PKG_VERSION=4.5.4
TERMUX_PKG_SRCURL=https://fossies.org/linux/misc/SuiteSparse-4.5.4.tar.gz
TERMUX_PKG_FOLDERNAME="SuiteSparse"
TERMUX_PKG_MAINTAINER="@its-pointless github"
TERMUX_PKG_BUILD_IN_SRC=true
TERMUX_PKG_CLANG=no
TERMUX_PKG_SHA256=698b5c455645bb1ad29a185f0d52025f3bd7cb7261e182c8878b0eb60567a714
	if [ -e /data/data/com.termux/files/usr/include/cs.h ]; then
		rm /data/data/com.termux/files/usr/include/cs.h
	fi
if [ $TERMUX_ARCH == "arm" ]; then
	TERMUX_PKG_DEPENDS="libgfortran,libatlas" 
else 
	TERMUX_PKG_DEPENDS="libgfortran,openblas"
fi
termux_step_make() {
	CFLAGS+=" -lm"
	LDFLAGS+=" -L${TERMUX_PKG_SRCDIR}/lib -lm -lgfortran $BLAS "
	make library -j4 
}
termux_step_make_install() {
	cp -av lib/* /data/data/com.termux/files/usr/lib/
	cp -av include/* /data/data/com.termux/files/usr/include/
}
