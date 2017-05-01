
From now on im using apt for updates
add 
deb [trusted=yes] https://its-pointless.github.io/files/  termux extras
to sources.list or add a file with it in etc/apt/sources.list.d/
gpg key is https://its-pointless.github.io/pointless.gpg
apt key add pointless.gpg will add the key to apt

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
