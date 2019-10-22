#pragma once

#include "BaseView.h"

class View2: public BaseView {
  public:
    static BaseView* create();
    virtual void display() override;
  protected:
    int testa = 0;
    int testb = 0;
};
