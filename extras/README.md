### Extra files for K&R 2nd Edition project

Miscellaneous files used by project and exercises.

`template.c`  
`template.h`  
Skeleton files to start new source files for various exercises and examples.

`fix_inc.sh`  
Recursively change the names of header files in include directives.
No longer necessary but provided for reference.

`kr2.utf-8.add`  
Project specific Vim dictionary.
In Vim:  
`:mkspell! <project root>/extras/kr2.utf-8.add`

Creates binary file: 
`kr2.utf-8.add.spl`
in current directly
Then in Vim run:
`set spell spelllang=kr2.utf-8.add.spl`
