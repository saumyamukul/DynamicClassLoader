#pragma once

#include "BaseView.h"

extern "C" {
  typedef BaseView* (*ClassFactory)();
  struct ClassDef {
    const char* name;
    ClassFactory factory;
  };
}
