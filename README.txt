
From now on im using apt for updates
add 
deb [trusted=yes] https://its-pointless.github.io/files/  termux extras
to sources.list or add a file with .list suffix in $PREFIX/etc/apt/sources.list.d/
gpg key is https://its-pointless.github.io/pointless.gpg
if not installed install gnupg
apt-get install gnupg
apt-key add pointless.gpg will add the key to apt
apt-get update

or use https://its-pointless.github.io/setup-pointless-repo.sh

use the commands setupclang setupgcc-6 and setupgcc-7 to switch compilers
nothing complex just moving symlinks around

12/09/2017
rustc is broken if you upgraded libllvm to 5.0 
to rememdy that install newly added package libllvm-4so should be working from there



08/09/2017

added fixedshe package and command executing it will start a new shell with
LD_PRELOAD=$PREFIX/lib/libandroid-fixshebang.so $shell
this will cause commands /bin/sh and /usr/bin/env to be redirected making shebangs with those 
commands work. to change default shell to do this the command fixedshe chsh will work as chsh does.

Doing this will enable  R and Octave library installs to work correctly first time much more often
things like fixedshe octave also work


27/08/2017

added openldap f0r testing need feedback 

updated gcc to 7.2 

added more stuff to x86_64 ans i686



08/08/2017
adding i686 and x86_64  stuff 
cargo and rusttc 
octave and R
etc
also some experimental nodejs 8.2.1 builds ...



29/07/2017

to get cargo for arm working add this to ~/.gitconfig 

[url "git://github.com/rust-lang/crates.io-index"]
        insteadOf = https://github.com/rust-lang/crates.io-index


25/07/2017
octave is fixed and back up on repo as well as gmic arm.

24/07/2017
octave isn't working right now ... 

23/07/2017
a working gmic binoary for arm required some magic getting it...


22/07/2017

gmic is not working for arm and it appears to be stubborn about it.
sorry about that. 


17/07/2017

Got almost everything working with the transision to libc++_shared. Updating the apt
repo shortyly there are a few packages there that are not not mentioned here... 







27/05/2017
added rustc and cargo for arm and aarch64 from @vishalbiswas
a bit buggy for now 


24/05/2017

Added quantlib. Will be adding R stuff shortly. Mpd-ext is also in repo extended for modpluglib and
libgme. So game emulation music plays. Haven't tested that yet should work.  



just added imgflo ... i haven't tested it if someoen wants to inform me how its screwed 
i would be thankful.
updated now with termux-packages pull requests as well

electrum egg added ...
updates
added boost ledger r-cran 
the mpv-ext is just mpv with caca enabled and alpine has been updated.


Octave seems to be working fairly well...
report bugs???
Its less annoying to compile than R so i might fix things that are really broken. 
The scripts to compile fortran stuff needs a bit of work to be more user friendly 
and less of a hack. 

termux gcc resurrected purely because scipy needs it. 
Don't annoy fornwall if you find a bug since its 
entirely unsupported. 
This is a compiler of last resort hecause you 
need to compile fortran or something needs gcc and
only gcc.


For scipy to work you need blaslib(openblas, reference blas +lapack or atlas) libgfortran
numpy and scipy.

If you want to do this yourself its not hard.
https://github.com/xianyi/OpenBLAS/wiki/How-to-build-OpenBLAS-for-Android
I compiled arm and arm64 tool chain for linux x86_64 (the .tar.bz2 file)
so you can extract over the android ndk tool chain for ndk-13 and when termux creates tool chain it should
pull stuff in. 
https://github.com/xianyi/OpenBLAS/wiki/How-to-build-OpenBLAS-for-Android

The default makefile for openblas uses hardfp and termux uses softfp so it won't work
on termux. Don't use it on arm use either lapack or atlas. Atlas will likely be faster
than lapack. 

LDFLAGS when compiling scipy and numpy for distribution is important. You can compile on android 6.0 and it might not 
work on 5.1 because the linker is different. 
