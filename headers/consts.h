#ifndef CONSTS_H
#define CONSTS_H

#include <string>
// std::string

namespace cps {
static const std::string DRAW_RECTANGLE = "/h height def\n\
/w width def\n\
gsave\n\
newpath\n\
moveto\n\
w 2 div h 2 div translate\n\
-1 w mul 0 rlineto\n\
0 -1 h mul rlineto\n\
w 0 rlineto\n\
closepath\n\
stroke\n\
grestore\n";

static const std::string DRAW_CIRCLE = "newpath\n\
radius 0 360 arc\n\
stroke\n";
static const std::string DRAW_POLYGON = "/ExtAngle 360 n div def\n\
gsave\n\
newpath\n\
moveto\n\
number_sides 1 sub{\n\
side_length 0 rlineto % add line\n\
ExtAngle rotate\n\
} repeat\n\
closepath\n\
stroke\n\
grestore\n";
static const int INCH = 72;

} // namespace cps
#endif
