overall notes:
> members need to be prepended with m


- constructor
> line 14:
> > gridSize should be set to param or define. reduce the amount of
> > magic numbers. what is parent=0? could that be a default?


- sceneItemAt

> line 44:
> > this if statement is huge. i would move all these conditional checks
> > to a helper method that simply returns true or false when passed
> > scene\_items. if nothing else to make it easier to unit test. getting
> > full coverage on this function could be hellish.

- mousePressEvent

> line 81:
> > move to helper method

> line 100:
> > make another method called create\_item or something


> this function is huge. maybe take loop at line 81 and put it into a helper
> method (called deselect\_items or something), especially since the loop is
> exactly rewritten at the bottom of the function. maybe move second half of
> function to another method called create\_item, especially since it is going
> to grow into a large set of conditionals.

- mouseMoveEvent
> do we even need this method?

- mouseReleaseEvent
> line 138+:
> > these state values should be defines. magic numbers == bad.


> line 135:
> > this could be a helper method called set\_state

> line 151:
> > this could be a helper method called is\_clicked or something


- mouseDoubleClickEvent

> do we need this method?

- drawBackground
> whole method needs empty lines for readability

> line 187:
> > what is grid? if it is a member needs to be prepended with m_> > same with gridSize. also if gridInterval isn't any different from
> > gridSize, just use gridSize.

> line 203:
> > 0.2 (20%) should be a define (as should be the array lengths)_
