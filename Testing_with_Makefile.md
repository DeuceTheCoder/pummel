# I have been getting a lot of questions on how the unit testing makefile works, so here is a short set of instructions.

### clone the wiki ###
go to the same directory level as the pummel repository and clone the wiki.
```
>>$ ls
doc  src  unit  web
>>$ cd ..
>>$ ls
pummel

>>$ hg clone https://code.google.com/p/pummel.wiki/
>>$ ls
pummel  pummel.wiki
# now you can push reports to the wiki!
```

### edit the makefile ###
In order to get coverage on the functions you want, you will need to add the function names to the FUNCS variable. Go ahead and get rid of `write_xml parse_xml` as those are just place holders.
```
## ## ## ## ## ## ## ## ## ## ##
##           MODIFY           ##
## ## ## ## ## ## ## ## ## ## ##
FUNCS=write_xml parse_xml
```

### print the commands ###
In order to see what commands you can use, use the help rule. This will display pretty much everything you need to know to use the makefile.
```
>>$ make help
#	usage: make rule
#
#	rules:
#
#	setup			- build the project with testing options (does a make)
#	full_setup		- build the project from scratch with testing options (make clean; make)
#	test_something		- build a given test (corresponds to ./tests/test_something.h)
#	test_something_coverage	- generage coverage reports for a given test
#	test_something_report	- push reports for a given test to the wiki repository
#	make all		- build and run all tests in the tests/ directory
#	make all_report		- build and run all tests and push their reports to the wiki repository
#	clean			- clean up all generated test files and reports
#	full_clean		- same as clean, but also cleans up src/ directory

```

### build the project ###
It is important to build the project using this makefile from the unit/ directory. This is because in order to get coverage tests the project must be built from scratch with gcov options. You don't need to learn how to do this, just rum a `make setup` or `make full_setup` and you are good to go.

### build a test ###
In order to build a test, you must put it in the tests/ directory (relative to the makefile) and prepend the filename with `test_`. If you follow this convention you don't need to add your test to the makefile; it is just picked up on the fly. So now that you have created `tests/test_something.h`, (and assuming you called it `test_something`) you can run `make test_something` (no .h) to build your test.

At this point two files of importance are generated: `test_something` (executable) and `test_something_log.txt` (report for you to document your test's progress/status).

### generate coverage reports ###
Assuming you have built the project with `make setup`, you can now generate coverage reports. To do this, run `make test_something_coverage` and both graphical and textual coverage reports are spit out.

IF YOU DO NOT HAVE 100% COVERAGE: you must document the reasons in the textual coverage report or in your `_log.txt`. Specifically explain why it is acceptable for the uncovered branches to remain uncovered. This is the only way we can get away with not having full coverage.

### documenting your progress ###
First, you need to clone the wiki repo on the same directory level as the project repo, otherwise the push\_reports script will not log your progress.
```
>>$ ls
pummel
>>$ hg clone https://code.google.com/p/pummel.wiki/
>>$ ls
pummel  pummel.wiki
```

Throughout the build process several log files are generated. Add comments to these as you see fit, and when you are done for the day use `make test_something_report` and all the generated reports will be shoved into a wiki page. This is how we document our testing progress so please DO NOT NEGLECT THIS PART even if you aren't done writing the test.


### common workflow ###
These are the typical steps I go through:
```
# do the initial setup
make full_setup

# build the test for the module you want (remember, no .h)
make test_xml_io

# generate the coverage report
make test_xml_io_coverage

# if you make changes to the source code rebuild with:
make setup

# and then rebuild the test
make test_xml_io

# when you are all done and ready to push documentation (make sure to have generated the coverage reports)
make test_xml_io_report
```


### weird errors ###
If you get compile errors, coverage errors, gcno/gcda errors, whatever, the first thing you should do is build everything from scratch and try again:
```
make full_clean
make full_setup
make test_something
make test_something_coverage
```

For all other times you need to tweak some code in the src/ directory, a `make setup` usually suffices. Always try this first as it is faster.