//
//  main.cpp
//  DynamicLoading
//
//  Created by Saumya Mukul on 10/18/19.
//  Copyright © 2019 Saumya. All rights reserved.
//
#include "View1.h"
#include "View2.h"
#include "ClassDef.h"
#include <iostream>
#include <dlfcn.h>
#include <map>

typedef void(*ClassNameFunc)(ClassDef**, int&);

std::map<std::string, ClassFactory> g_class_map;
BaseView* g_current_view = nullptr;
std::string g_current_view_name;
void* g_dylib_handle = nullptr;

void _init_class_map() {
  g_class_map.insert({"BaseView", BaseView::create});
  g_class_map.insert({"View1", View1::create});
  g_class_map.insert({"View2", View2::create});
}

void _update_classes(ClassDef* definitions, int size) {
  for(int i = 0; i < size; ++i) {
    auto class_def = definitions[i];
    g_class_map[class_def.name] = class_def.factory;
    if(g_current_view_name == class_def.name) {
      g_current_view = class_def.factory();
    }
  }
}

void _navigate_to_view(const std::string& view_name) {
  auto iter = g_class_map.find(view_name);
  if(iter == g_class_map.end()) return;
  g_current_view = iter->second();
  g_current_view_name = view_name;
}

void _load_classes() {
  if(g_dylib_handle != nullptr) {
    dlclose(g_dylib_handle);
  }
  std::string lib_name("libOverridesLib.dylib");
  g_dylib_handle = dlopen(lib_name.c_str(), RTLD_NOW);
  assert(g_dylib_handle);
  ClassNameFunc class_func;
  class_func = reinterpret_cast<ClassNameFunc>(dlsym(g_dylib_handle, "get_class_overrides"));
  assert(class_func);
  ClassDef* definitions;
  int size = 0;
  class_func(&definitions, size);
  _update_classes(definitions, size);
}

void _handle_intput() {
  std::string input;
  getline (std::cin, input);
  if(input.find("navigate")!=std::string::npos) {
    std::cout<<"Enter destination view\n";
    getline (std::cin, input);
    _navigate_to_view(input);
  } else if(input.find("reload")!=std::string::npos) {
    _load_classes();
  }
  g_current_view->display();
}

int main(int argc, const char * argv[]) {
  _init_class_map();
  _navigate_to_view("BaseView");
  g_current_view->display();
  while(1) {
    _handle_intput();
  }
}
