# Cxxtest Unit Testing Framework #

## Download ##
No debian file exists, so for now we need the source. It doesn't need building, just copying.
The source can be found at:
http://sourceforge.net/projects/cxxtest/files/cxxtest/4.0.2/

```
# Unpack the source (lives in ~/Downloads by default): 
tar xf cxxtest-4.0.2.tar.gz
cd cxxtest
```


## Install the Python ##
You will need Python for this part. Run the following commands as root. If you have dependency problems consult:
http://cxxtest.com/cxxtest/doc/guide.html#installation

```
cd python
python ez_setup.py -U setuptools
python setup.py install
```

## 'Install' the Source ##
The header file paths for cxxtest will need to be in the -I include args for compiling later. I put them in a global place for consistency. Copy the subdirectory 'cxxtest' to a good place. Project Pummel's makefiles use `/usr/include`.

```
>>$ ls
admin  bin  build_tools  COPYING  cxxtest  doc  NOTES  python  README  sample  test  Versions  www

>>$ ls cxxtest/
Descriptions.cpp       ErrorFormatter.h   GlobalFixture.h  Mock.h                RealDescriptions.h  StdioFilePrinter.h  TeeListener.h   TestSuite.cpp    ValueTraits.cpp  XmlFormatter.h
Descriptions.h         ErrorPrinter.h     Gui.h            ParenPrinter.h        Root.cpp            StdioPrinter.h      TestListener.h  TestSuite.h      ValueTraits.h    XmlPrinter.h
DummyDescriptions.cpp  Flags.h            LinkedList.cpp   QtGui.h               SelfTest.h          StdTestSuite.h      TestMain.h      TestTracker.cpp  Win32Gui.h       XUnitPrinter.h
DummyDescriptions.h    GlobalFixture.cpp  LinkedList.h     RealDescriptions.cpp  StdHeaders.h        StdValueTraits.h    TestRunner.h    TestTracker.h    X11Gui.h         YesNoRunner.h

>>$ cp -rf cxxtest /usr/include
```

## Creating Tests ##

Create a test header file that will hold your tests.
A super simple test goes like:
```
// MyTestSuite.h
         
#include <cxxtest/TestSuite.h>
#include "test_obj.h"
         
class MyTestSuite : public CxxTest::TestSuite 
{
public:
   void test_get_val( void ) 
   {
      int actual, expected = 5;
      test_obj *t = new test_obj();
      
      t->set_val(expected);
      actual = t->get_val();

      TS_ASSERT( actual == expected );
      TS_ASSERT_EQUALS( actual, expected );
   }
};
```

Use cxxtestgen to generate source (.cpp) to run your test:
```
cxxtestgen --error-printer -o unit_tests.cpp MyTestSuite.h
```


Build and run:
```
>>$ make
>>$ ./unit_tests
Running 1 test.OK!
```

Now you are ready to write some tests! Here is the Cxxtest user guide (includes some pretty nifty makefile stuff):
http://cxxtest.com/cxxtest/doc/guide.html