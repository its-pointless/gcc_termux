TERMUX_PKG_HOMEPAGE=https://sourceforge.net/projects/qrupdate/
TERMUX_PKG_DESCRIPTION="qrupdate is a Fortran library for fast updates of QR and Cholesky decompositions."
TERMUX_PKG_VERSION=1.1.2
TERMUX_PKG_SRCURL=https://launchpad.net/ubuntu/+archive/primary/+files/qrupdate_1.1.2.orig.tar.gz
TERMUX_PKG_SHA256=e2a1c711dc8ebc418e21195833814cb2f84b878b90a2774365f0166402308e08
TERMUX_PKG_FOLDERNAME="qrupdate-1.1.2"
TERMUX_PKG_BUILD_IN_SRC=yes
TERMUX_PKG_MAINTAINER="@its-pointless github"
termux_step_pre_configure () {
rm /data/data/com.termux/files/usr/lib/libqrupdate* 
}
