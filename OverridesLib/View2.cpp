#include "View2.h"

#include <iostream>

BaseView* View2::create(){
  return new View2();
}

void View2::display() {
  std::cout<<"Size of V2 "<<sizeof(View2)<<std::endl;
  _clear();
  auto ascii =  R"view(
|----------|
|          |
|  Text 1  |
|          |
|  Text 2  |
|          |
|          |
|          |
|----------|
  )view";
  std::cout<<ascii<<std::endl;
}
