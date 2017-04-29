TERMUX_PKG_HOMEPAGE=http://utfcpp.sourceforge.net/
TERMUX_PKG_DESCRIPTION="Powerful, double-entry accounting system"
TERMUX_PKG_VERSION=2.3.4
TERMUX_PKG_SRCURL=http://pkgs.fedoraproject.org/repo/extras/utf8cpp/utf8_v2_3_4.zip/c5e9522fde3debcad5e8922d796b2bd0/utf8_v2_3_4.zip
#TERMUX_PKG_FOLDERNAME="ledger-${TERMUX_PKG_VERSION}"
TERMUX_PKG_SHA256=3373cebb25d88c662a2b960c4d585daf9ae7b396031ecd786e7bb31b15d010ef
# TERMUX_PKG_EXTRA_CONFIGURE_ARGS="-DBoost_INCLUDE_DIR=/home/builder/.termux-build/boost/src -DBOOST_LIBRARYDIR=$TERMUX_PREFIX/lib"
TERMUX_PKG_FOLDERNAME="source"
TERMUX_PKG_BUILD_IN_SRC=yes
TERMUX_PKG_NO_DEVELSPLIT=yes
termux_step_configure() {
	return 0;
}
termux_step_make() {
	return 0;
}
termux_step_make_install(){
	cp * -r $TERMUX_PREFIX/include
}
