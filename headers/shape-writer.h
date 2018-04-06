#ifndef SHAPE_WRITER_H
#define SHAPE_WRITER_H
#include "shape.h"

#include <string>
// std::string
#include <memory>
// std::shared_ptr
#include <vector>
// std::vector

namespace cps {
void writePSfile(std::vector<std::shared_ptr<Shape>> shapes,
                 std::string ps_filename);
} // namespace cps
#endif
