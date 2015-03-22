## Coverage Testing with Trucov ##

### Download ###
Here is where you can download the source. If you are using Ubuntu 10.04, you can download the deb. Otherwise just grab trucov\_10.1.tgz

http://code.google.com/p/trucov/downloads/list


### Install ###
If you are using Ubuntu 10.04, type the following command as root and you are done:
```
dpkg -i trucov_10.1_amd64.deb
```

Else, you need to build it from source. First unpack:
```
tar xf trucov_10.1.tgz
cd trucov_10.1/
```

Now generate the makefile using cmake (apt-get install cmake if you haven't already)
```
cmake .
```

There are several dependencies that you need, which would be taken care of in the debian install. However we will have to manually install them. As root, apt-get install the following packages:
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

Now build and install:
```
make
make install
```

### Usage ###
The best tutorial on usage is probably the one on the project website:
http://code.google.com/p/trucov/wiki/Tutorial