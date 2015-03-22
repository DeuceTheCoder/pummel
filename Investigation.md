**Team Pummel Code Investigation – 3/30/2012**

**1**

Line 11 – Probably take out parent=0

First constructor – member functions m_, not normal variables._

14 – Better definition

**26**

44-47 – checks the bounds of the objects, return properly defined item, rather than item we can’t use. Conditional is really big. **Helper function would be better.** Possibly place it into Icon, but scene\_items is in dragscene.cpp. Hit test in Icon.cpp, where it tests the icon itself which should know its functions.

**65**

81-84 & 113-116 - Remove to helper function?

**121**

Reason for mouseMoveEvent?  - Has to be passed down, acts as a bridging function. If not included, doesn’t apply to icons.
Inheritance? Don’t think it fires the event without this function. Check out, research. If inheritance works, it should be giving us a mousemoveevent for free. Depend on if QGraphicsScene mme is private/protected/etc.? Worth testing.

**131**

Line 138 – last clicked state necessary. Something better to be done? Should this be better defined?
Seems like a really large function, with a lot of cases. Possible to split up to make unit testing simpler? State detection loop moved to its own function? Seeing if an item is clicked is also a potential thing we can use as helper methods.
New methods (?): State detection loop (possibly icon class? I like it.), seeing if an item is clicked.
State detection loop with be really useful for lines.

**176**

Function Needed?

**184**

Research setWorldMatrixEnabled.
More research put into our code for grids.

191-192 –put more research back into it. We obviously don’t understand it very well. Why qreals? Qlinef likes reals. Document more thoroughly, especially arithmetic.

203 – Possible future app – user allowed to change the opacity

**210**

Used to test for simulating user or errors doing unauthorized things.

**Dr. J’s reflection**

What went better?
  * Qt GUI to collapse comments and functions.
  * Interesting, being only one reader
  * A lot more focused to one section of your program, same general concept, less complicated?
  * Beginning of a file, a few includes (Probably a header comment would be a good idea to explain what the file does.)
  * Constructor situation kept simple, no destructor (probably cleanup required for the closure of a tab?).
  * One dragscene per tab. Our equivalent of canvas.