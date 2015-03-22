This page explains how to install Open HMI Tester

### Download ###
The source can be found at:
http://sourceforge.net/projects/openhmitester/

### Install ###
Unpack the source:
```
tar xf OpenHMITester_v0.9.tar.gz
```

Now move the resulting directory to a local spot (you guessed it, we are doing a manual "install")
```
mkdir ~/apps/
mv HMITester/ ~/apps/
cd ~/apps/HMITester/
```

Now build the source:
```
make -f Makefile.svn
make
cd libPreload/
make
```

If you run into compile errors install these dependencies (but you should be all set after installing trucov):
```
libboost-filesystem1.40-dev
libboost-program-options1.40-dev
libboost-regex1.40-dev
libboost-system1.40-dev
libboost-thread1.40-dev
libc6
libgcc1
libstdc++6
binutils
graphviz
```

Now you can make the executable available however you like. I like to append to my path, so I added this to my .bashrc:
```
export PATH=$PATH:~/apps/HMITester/
```

And out of personal preference I like all my commands to be lower-case, so I just moved the executable to something else:
```
mv ~/apps/HMITester/HMITester ~/apps/HMITester/hmitester
```

### Usage ###
coming soon