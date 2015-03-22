As you all know, the project has some memory leaks. This is just a document that summarizes how I use valgrind. For useful information visit valgrind.org.


### install ###
if you are using a debian distribution, run the following command as root:
```
apt-get install valgrind
```

### usage ###
qmake generates an executable called src by default, so this is the command I run:
```
valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./src
```

actually interpreting valgrind output can be tricky, so one thing I like to do is replicate errors that valgrind is finding. for instance, you could write a simple main.cpp that just allocates a pointer without cleaning it up. run valgrind on the executable and you can see what kind of output corresponds to the error you created. same can be done with segfaults.