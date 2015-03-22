# unit testing portion nearly complete, other two still need some work


## Approach (Strategy) ##

We use three different phases of testing for the entire
project:

  1. Unit Testing
  1. Integration Testing
  1. Functional Testing

### 1. Unit Testing ###

> Since the project is almost entirely GUI based, satisfactory unit
> testing can be a difficult task. So we refactored our code to follow
> a more rigorous Model View Control implementation. This was accomplished
> by seperating the logical parts of the code from the code that invokes
> GUI events (which cannot be truly unit tested).

> Take the saveAsFile method as an example. This method is composed of
> three parts:
    * invoking a dialog box to enter the filename
    * writing the current diagram into xml
    * opening a new tab.
> Since the first and third parts are invoking GUI events, this method cannot be fully unit tested independently of the GUI itself. It can only  be tested during an integration test. However, since xml writing (tests/ routines/methods?) contains all the logic of the method (branching, loops, etc.) with no GUI interaction, it can be moved to a helper method and be unit tested independently of GUI events.
> At that point, when GUI events have been tested in the integration testing phase, and the logical portion is independently unit tested, we can conclude that the saveFileAs process is tested to a satisfactory level.

> In order to perform thorough unit testing, two things must be achieved: data
> coverage and branch coverage. The tool we use for data coverage is CxxTest.
> This is the framework that will test the logical portions of the code and
> supply a variety of data to test all possible inputs.

> The tool used for coverage testing is Trucov. Coverage testing is done on
> both the logical portions of the code as well as the GUI event portions.
> To test for coverage on the logical portions, the tool is run over the unit
> tests. The GUI event coverage testing is automated with a tool called
> Open HMI Tester, which is simply a GUI recorder that will launch the program
> and walk through a series of actions within the GUI.



### 2. Integration Testing ###
> This is the phase where the actual GUI events are tested. During this
> phase, all of the use cases will be walked through manually while confirming
> that the right events are being invoked based on input. For these individual
> use case tests, each test must be run as independantly as possible, with
> minimal setup. This is to observe the behavior of each use case completely
> independant of the others.

> As these individual test cases are walked through, the GUI events taking place
> are recorded with a GUI recorder (Open HMI Tester). This way the process of rerunning
> the test cases is automated so that as adjustments are made one could simply kick off
> a script and let the integration tests happen by themselves. Since the test cases are
> automated, coverage testing is also run over the project as the integration tests are
> executed. In this manner we are able to get coverage reports on the GUI portions of the
> code that could not be unit tested. So unit testing coverage in addition to this style
> of integration testing coverage results in the ability to get coverage on the entire
> project and leave no line of code untouched.

> The integration testing phase tests GUI events. During this phase, the application is fully assembled. All integration tests will be run on the full application.
> The testers will follow the test cases included in this test plan. Each test case draws from a use case from the Use Case diagram. Each test case contains its own setup instructions, and its own criteria for success.

### 3. Functional Testing ###
> The functional phase is where the usage of the UML editor is tested to a
> much higher degree. Rather than testing each use case individually, there
> will be a variety of users selected to attempt to produce UML diagrams
> of different types and magnitudes. This will produce a very large variety
> of permutations of use cases, and allow us to observe how the use cases
> behave when used together.

> The functional testers will have a minimum set of tasks that must be performed
> within the application for it to be considered a thorough enough run. These
> minimum requirements include:
  * at least one of every icon available
  * at least ten icons total
  * at least one of every line available
  * at least one note icon
  * must save the diagram at least one time
  * must re-open the diagram after exiting for the first time
  * must attempt all above criteria with each available diagram type


### 4. Test Plan Items ###
> Functions to be tested:
    * Add Testing of Line Creation vs Shape Creation mutual exclusivity
    * Add Testing of memory efficiency

### 6. Features to be Tested ###
  * Creation/deletion of objects and lines
  * Diagram logic
  * Saving/loading
  * Tab functionality (toolbar switches, "remembers" diagrams, etc.)
  * Selection logic
  * Stacking and scaling
  * Another 'Low Priority' test  is customizable color of Icons

### 7. Features not to be Tested ###
  * Undo/Redo (I think)
    * Undo/Redo have been removed from the 1.0 feature list.  They will be implemented and tested in future versions of the product.
    * (I believe IF we had enough time, undo/redo would be tested, as part of a "1.1" release...how would we explain this in the test plan?)
  * Revision: all icons will be tested
    * Why aren't we testing all of the icons? Shouldn't each new test simply be copy/paste?
  * Similarly, Saving/Loading Certain Icons/Lines (Some will be thoroughly tested, like Classbox, Ellipse, Actor, a few different line types, but not all need such treatment. I would suggest testing one of each diagram type that uses everything possible, just to show all diagram elements save and load successfully, then do more robust testing with only a handful of types.)

### 13. Environmental Needs ###

For this small scale of testing there are very little as far as outside needs.  All tests will be conducted on local machiens on a variety of platform, using manual insertion, and gui testing tools.  Testing will continue on each part util the results match the desired results for each respective part.

### 14. Staff and Training needs ###

Training will be required for the members of the team doing the testing to be able to work the testing software.  Also any outside testers that are brought on will have to be trained on the workings of the program.

We designed the software so that minimal training is needed to run it.  However, testers are assumed to have familiarity with UML diagrams.  Each tester will be given a quick tutorial (or quick reference card?) on the software's basic functionality, and will be expected to refer to the help documentation if any difficulties arise.

Staff training will include the training in the use of the Cxx unit testing framework, the trucov coverage tester, the Open HMI GUI recorder, and the in-house makefile that automates the majority of tool use and also generates test reports on the wiki repository.

### 15. Responsibilities ###

Each team member will individually add their own parts to the test plans, that includes creating unit tests for individual sections of code and being able to run the unit test framework(Cxx Test) as well as the coverage tester (trucov) on their individual machines or on a VM.

### 16. Scheduling ###

The main portion of testing is scheduled to begin imediately following the third milestone and demo.  Many of the use cases will be able to be tested for functionality even before this milestone, allowing for limited testing to begin despite delays in the previous programing sections.  All dates are listed in the Gantt chart.

### 17. Planning Risks and Contingencies ###

Ample time is alloted for testing even given possible delays, but in case of running short on given time, tests will begin before the remaining functioalities of the program are functional, or even included.  This may require multiple retests as each new function is implemented and weaken the final test suit, but will have each piece tested before final date.

### 18. Approvals ###

Approvals for test will originate within the group from ones working on specific parts that are to be tested.  As each different function is added it will be aproved for the given test case corisponding to it, and testing will begin as soon as milestone 3 is reached, or when the delivery date for milestone 3 has bbeen passed and there is sufficient testable product.

With regards to unit testing, a module is considered sufficiently tested when its report on the wiki repository displays satisfactory test and coverage results. These reports will be verified by a minimum of two team members (in addition to the author) and then be signed off after the report and the tests themselves are deemed sufficient.

### 19. Glossary ###

Any unclear words will be added as encountered.