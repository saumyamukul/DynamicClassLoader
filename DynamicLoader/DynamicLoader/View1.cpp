#include "View1.h"

#include <iostream>

BaseView* View1::create() {
  return new View1();
}

void View1::display() {
  _clear();
  auto ascii =  R"view(
|----------|
|----------|
|          |
|          |
| -------- |
| |      | |
| -------- |
|          |
|----------|
  )view";
  std::cout<<ascii<<std::endl;
}
