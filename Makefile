all:
	gcc -Wl,--version-script version -shared libsample.c -o libsample.so -fPIC
