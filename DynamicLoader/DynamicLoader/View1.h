#pragma once

#include "BaseView.h"

class View1: public BaseView {
  public:
    static BaseView* create();
    virtual void display() override;
};
