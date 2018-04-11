#ifndef CONSTS_H
#define CONSTS_H

#include <string>
// std::string

namespace cps {
static const double RADIAN = 3.1415 / 180.0;
static const std::string MOVETO = "moveto\n";
static const std::string ROTATE = "rotate\n";
static const std::string DRAW_SPACER = "/h height def\n\
/w width def\n\
/x x_coord def\n\
/y y_coord def\n\
gsave\n\
newpath\n\
x y moveto\n\
w 2 div h 2 div translate\n\
-1 w mul 0 rmoveto\n\
0 -1 h mul rmoveto\n\
w 0 rmoveto\n\
closepath\n\
stroke\n\
grestore\n";
static const std::string DRAW_RECTANGLE = "/h height def\n\
/w width def\n\
/x x_coord def\n\
/y y_coord def\n\
gsave\n\
newpath\n\
x y moveto\n\
w 2 div h 2 div translate\n\
-1 w mul 0 rlineto\n\
0 -1 h mul rlineto\n\
w 0 rlineto\n\
closepath\n\
stroke\n\
grestore\n";

static const std::string DRAW_CIRCLE = "/x x_coord def\n\
/y y_coord def\n\
/rad radius def\n\
gsave\n\
newpath\n\
x y moveto\n\
x rad sub y rad 0 360 arc\n\
stroke\n\
grestore\n ";
static const std::string DRAW_POLYGON = "/x x_coord def\n\
/y y_coord def\n\
/ns number_sides def\n\
/sl side_length def\n\
/ExtAngle 360 ns div def\n\
gsave\n\
newpath\n\
x y moveto\n\
ns 1 sub{\n\
sl 0 rlineto % add line\n\
ExtAngle rotate\n\
} repeat\n\
closepath\n\
stroke\n\
grestore\n";
static const int INCH = 72;

} // namespace cps
#endif
