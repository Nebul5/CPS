#include "../headers/shape-writer.h"
using cps::writePSfile;
#include "../headers/shape.h"
using cps::Shape;

#include <fstream>
using std::ofstream;
#include <string>
using std::string;
#include <memory>
using std::shared_ptr;
#include <vector>
using std::vector;

void cps::writePSfile(vector<shared_ptr<Shape>> shapes, string ps_filename) {
  ofstream ps_file;
  ps_filename += ".ps";
  string ps_file_str;
  ps_file.open(ps_filename.c_str());
  for (auto i = 0; i < shapes.size(); ++i) {
    ps_file_str += shapes[i]->toPostScript() + "\n";
  }
  ps_file_str += "showpage\n";
  ps_file << ps_file_str;
  ps_file.close();
}
