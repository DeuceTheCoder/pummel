# Mercurial Reference #

## Initial Setup ##


1) put this in ~/.hgrc
```
   
[ui]
username=google_username
   
[paths]
default=https://code.google.com/p/pummel/
```

2) add this to the bottom of your ~/.bashrc, then execute the command:    `. ~/.bashrc`

```
PS1='\[\033[1;32m\]\u@\h:\[\033[1;34m\]\w/:\[\033[1;31m\]$(hg branch 2> /dev/null)\[\033[00m\]\n>>$ '
```
3) go into whatever directory you want to clone the repo into.
I like to use the directory dev/ so this is what I typed:

```
cd
mkdir dev; cd dev
hg clone https://code.google.com/p/pummel/
cd pummel
hg up integration
hg pull; hg update
```

note: when you clone, you will start out on the default branch. this branch
is not maintained, so just leave it alone. work from the integration branch

4) once you've cloned and are up to date, you will want to make your branch.
this is your own little world of development. i typed the following commands:

```
cd ~/dev/pummel/
hg branch cabljohn
hg commit -m 'made my branch'
hg pull; hg up
hg push --new-branch
```

note: if the --new-branch directive does not exist on your version of mercurial,
use `hg push -f`  instead



## Common Workflow ##

At the moment I have not yet figured out how to create subrepos
when using google code. Therefore whenever you pull or push changes,
you are more or less pulling and pushing snapshots of the entire repo at once.
The following commands correlate to my directory structure, username, etc

1) go to the root directory of the repo, change to the integration branch,
and pull the latest changes

```
cd ~/dev/pummel/
hg update integration
hg pull
hg update
```

2) now that you are up to date with the repo, you can start doing work.
first, change to your branch and merge it with integration (the current
version). after that, you are free to make all the changes you want
without affecting the latest version of the project.

```
hg update cabljohn
hg merge integration
hg commit -m 'merged with integration'
# do work
```

3) once you have made changes that you want to push into the current
project, the following is typically what you would type:

```
# finish doing work
hg status		      # shows you what changes you have made that are not committed to the repo
hg commit -m "added access methods to class panda" 	 # commit those changes to the repo
hg update integration         # change to the integration branch
hg pull   		      # make sure the integration branch is up to date. you may have to do an hg update
hg merge cabljohn 	      # merge your branch (your version of the repo) INTO integration
hg commit -m "merged in cable's changes" 	         # commit the changeset resulting from the merge
# TEST
# TEST (especially if you haven't merged with integration in a while)
# TEST
hg push   		      # push your changes out into the wild.
```


note: remember to only push when you are certain of two things:
  1. the integration branch is up to date
  1. you are happy with the current state of the repo

the reason for this is that even though there are ways to revert
changes and undo commits and such, once you have pushed, there is
no going back; it would take additional changesets to fix a broken repo

also note that when you push, you are pushing on all branches. so it is not
necessary to push on multiple branches. this means the changes made on your
branch AND the changes on the integration branch will both be pushed to the server



## add/remove files ##

1) add file.c to the repo (same for directories)
```
hg add file.c
```

2) remove file.c from the repo
```
hg remove file.c
```

after doing either of these steps, an 'hg status' (hg st) will tell you
that file.c has been either added or removed, and like a change, it will
not actually take effect in the repo until you commit and push

## Tracking Changes ##
Often times you will see that a file that you need to work on has changed
significantly since last time you saw it. One way to easily see what has
changed in the file since last time is to use `hg diff`. Here is an example
usage:

1) let's say we want to investigate file.c. First we can use `hg log` to see all
the tracked changes to file.c.
```
hg log file.c
```

this will give you the list of changesets to file.c. in every entry there will be a
line that looks like this:
```
changeset:   34:dd8b2335f729 
```
We know that this is [revision 34](https://code.google.com/p/pummel/source/detail?r=34) (the first number in that ugly hash). For simplicity, let's
say that this is the last changeset that I pushed; the last version of the file that I am
familiar with. Now we use `hg diff` to see the difference between the old revision of the file
and the current version of the file:
```
hg diff -r 34 file.c     # where -r is the revision directive
```
This will give you a unix-like diff dump. Optionally you can redirect the output into a file,
and if you give the file a .diff extension most unix editors will display it with colors and such:
```
hg diff -r 34 file.c > tmp.diff
```