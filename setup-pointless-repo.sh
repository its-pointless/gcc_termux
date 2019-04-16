#!/data/data/com.termux/files/usr/bin/sh
# Get some needed tools. coreutils for mkdir command, gnugp for the signing key, and apt-transport-https to actually connect to the repo
apt-get update
apt-get  --assume-yes upgrade 
apt-get  --assume-yes install coreutils gnupg wget 
# Make the sources.list.d directory
mkdir $PREFIX/etc/apt/sources.list.d
# Write the needed source file
if apt-cache policy | grep -q "https://dl.bintray.com/termux/termux-packages-24" ; then
echo "deb https://its-pointless.github.io/files/24 termux extras" > $PREFIX/etc/apt/sources.list.d/pointless.list
else
echo "deb https://its-pointless.github.io/files/ termux extras" > $PREFIX/etc/apt/sources.list.d/pointless.list
fi
# Download signing key from https://its-pointless.github.io/pointless.gpg 
wget https://its-pointless.github.io/pointless.gpg
apt-key add pointless.gpg
# Update apt
apt update
