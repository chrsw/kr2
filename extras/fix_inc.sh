#!/bin/sh
# Change all 
#include "stdio.h"
# to
#include "ch8_stdio.h"
find ./ -type f -exec sed -i -e 's/^#include \"stdio.h\"/#include \"ch8_stdio.h\"/' {} \;
