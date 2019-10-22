#include "View2.h"

#include <iostream>

BaseView* View2::create() {
  return new View2();
}

void View2::display() {
  _clear();
  auto ascii =  R"view(
|----------|
|          |
|  Text 1  |
|          |
| Text 2   |
|          |
|          |
|          |
|----------|
  )view";
  std::cout<<ascii<<std::endl;
}
