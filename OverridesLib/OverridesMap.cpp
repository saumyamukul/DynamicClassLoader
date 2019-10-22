#include "ClassDef.h"
#include "View2.h"

#include <map>
#include <string>

extern "C" {
void get_class_overrides(ClassDef** def_array, int& size) {
  size = 1;
  *def_array = new ClassDef[1];
  (*def_array)[0].name = "View2";
  (*def_array)[0].factory = View2::create;
}
}
