#pragma once

#include "BaseView.h"

class View2: public BaseView {
  public:
    static BaseView* create();
    virtual void display() override;
};
