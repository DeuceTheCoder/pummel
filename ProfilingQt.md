# Introduction #

Profiling is a way to measure how much of the run-time your program spends in which modules.


# Details #


**Using gprof**

After you have created the src.pro file (with qmake -project), edit
src.pro and add the following two lines below "INCLUDEPATH += .":
```
QMAKE_CXXFLAGS_DEBUG += -pg
QMAKE_LFLAGS_DEBUG += -pg
```

Save the file, and then run:
```
qmake -config debug
```
This replaces running qmake -makefile, and replaces any Makefile yoou already have present.

Build the project with make, and run the program. You will want to run through as many use cases as you wish to have data for in your usage report. Upon exiting, a file named "gmon.out" will be produced.

You next generate the report of what you just ran by running
```
gprof executableName > reportName
```
for example,
```
gprof ./src > ClassDiagramUseCase.txt
```
will build a report in `ClassDiagramUseCase.txt`.


Here is a sample report:
https://pummel.googlecode.com/hg-history/integration/doc/ClassDiagramUseCaseReport.pdf

---


**Using callgrind**

_to be added soon_




---


**references**

http://www.qtcentre.org/wiki/index.php?title=Profiling

http://web.eecs.umich.edu/~sugih/pointers/gprof_quick.html