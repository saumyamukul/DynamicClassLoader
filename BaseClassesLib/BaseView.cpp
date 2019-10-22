#include "BaseView.h"

#include <iostream>

BaseView* BaseView::create() {
  return new BaseView();
}

void BaseView::display() {
  _clear();
  auto ascii =  R"view(
|----------|
|          |
|          |
|          |
|          |
|          |
|          |
|          |
|----------|
  )view";
  std::cout<<ascii<<std::endl;
}

void BaseView::_clear() {
  std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
