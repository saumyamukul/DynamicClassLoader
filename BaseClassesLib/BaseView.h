#pragma once

class BaseView {
  public:
    static BaseView* create();
    virtual void display();
  protected:
    void _clear();
};
