
From now on im using apt for updates
add 
deb https://its-pointless.github.io/files/  termux extras
to sources.list or add a file with .list suffix in $PREFIX/etc/apt/sources.list.d/
gpg key is https://its-pointless.github.io/pointless.gpg
if not installed install gnupg
apt-get install gnupg
apt-key add pointless.gpg will add the key to apt
apt-get update

or use https://its-pointless.github.io/setup-pointless-repo.sh

use the commands setupclang setupclang and setupgcc-7 to switch compilers
nothing complex just moving symlinks around

03/04/2019
r-cran-tidyverse should work consistently except for those using android-5 due to linking issues
around librcon.so. Above android-5 the library can see all symbols linked in android-5 that the linker
won't let the library see symbols in libR.so since its not directly linked. I am not sure right now 
the correct way to deal with it. But changing $PREFIX/lib/R/etc/Makeconf to add -LR to ldflags and 
reinstalling readr package will work for now.

15/01/2019
ns_parse.h for a few missing reolver libs stuff missing  in android 5 and 6 so msmtp works. Havent tested 
as its a 20 minute cut and paste job from musl.
also opencv python3 doesn;t work as is but is easy enough to fix 
https://github.com/its-pointless/its-pointless.github.io/issues/18 
will do proper fixes at some point this week.

17/12/2018
added gnat for x86_64 and aarch64, gprbuild and xmlada packages available as well

27/09/2018

Added portaudio and elfutils 
For port audio to work without issue it requires pulseaudio. It also needs pulseaudio
sample rate set to PROPERTY_OUTPUT_SAMPLE_RATE or latency is too high
this value can be obtained via termux-audio-info
Any issues with this please mention...

14/08/2018

julia updated to 1.0.0
installing packages that link to libs is a bit tricky and requires
wiriting deps.jl yourself so they point to installed termux libs.
Even if you can compile the libs using julia, without setting 
LD_LIBRARY_PATH to where julia installed the libs it won't use them
causing error. 


30/07/2018
fixed a few annoyances with gcc-8 
Oz now becomes Os automatically 
and few warnings that llvm-config add won't cause errors since they are 
only implemented in clang 

30/03/2018

julia is compiling on all archs but must be done on device. see my android-termux branch 
of julia. Also added an arm build for testing...



20/03/2018

TESTING openblas for x86_64 atom....


7/02/2018

added povray because ... i don't know.


10/01/2018

updated rustc and rustc-nightlies
fixed issues on x86_64 gcc
added racket for arm and i686


5/01/2018
changed gcc-7 sources to linaro ... because why not? going to add source so 
everyone can compile and won't rely on me providing binaries... at all. 

added gnatmake for arm ( other archs are not likely to come since it requires
a sigtramp implentation that is absent on android)

added racket ... likely buggy for arm and i686. not working yet on 64 bit archs

also adding libboostpython libs which is a pull request for termux/termux-packages 

23/12/2017
updated ecl arm and julia for x86_64. both should now work again

20/12/2017

updated cargo for all but i686
updated rustc-nightly for and added for i686. not on x86_64...
if i have time i will work on it. Ecl should now compile maxima
technically there aren't any "major" dependencies missing for sagemath 
would have to built on device though...


13/12/2017
added ecl rustc nightly for arm and aarch64. 
added the cross_config stuff for ecl as well.

28/11/2017
added libgomp for gcc-7 in 7.2.0 and ndk 4.9.x flavours
Thanks to @arietal libcairo now works in R. 
also added julia lang for i686 x86_64. 
I have no idea how long or if ever arm and aarch64 will take. 

19/11/2017
r-cran package 3.4.2-1 uploading, should be working again... enabled openmp because i can.
pforth 32 bit fix upload for testing.
should get  updated scipy and numpy at some point hopefully soon

11/11/2017 
rustc now working for x86_64 and i686. The bug with cargo on arm is also fixed.
As libgit2 needed to be compiled with -no-integrated-as the fix is statically linked.



08/10/2017
added python 2 versions numpy and scipy


01/10/2017
guile 2.0 and 2.2 added
i686 version for 2.0 has threads disabled due to crashing half the time.
2.2 has no such issue as far as I can tell but the build process for 2.2 builds
needs some work before a pull request to main repo.


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
