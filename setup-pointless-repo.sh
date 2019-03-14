#!/data/data/com.termux/files/usr/bin/sh
# Get some needed tools. coreutils for mkdir command, gnugp for the signing key, and apt-transport-https to actually connect to the repo
apt-get update
apt-get  --assume-yes upgrade 
apt-get  --assume-yes install coreutils gnupg apt-transport-https wget 
# Make the sources.list.d directory
mkdir $PREFIX/etc/apt/sources.list.d
# Write the needed source file
echo "deb https://its-pointless.github.io/files/ termux extras" > $PREFIX/etc/apt/sources.list.d/pointless.list
# Download signing key from https://its-pointless.github.io/pointless.gpg 
wget https://its-pointless.github.io/pointless.gpg
apt-key add pointless.gpg
# Update apt
apt update
