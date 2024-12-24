//
// Created by 13738 on 2024/12/24.
//
#include <iostream>

class AbstractClass {
  public:
  virtual ~AbstractClass() = default;
  virtual void TemplateMethod() {
    Step1();
    Step2();
    Step3();
  }

  virtual void Step1() = 0;
  virtual void Step2() = 0;
  virtual void Step3() = 0;
};

class ConcreteClass: public AbstractClass {
public:
  void Step1() override {
    std::cout << "ConcreteClass: Step1" << std::endl;
  }
  void Step2() override {
    std::cout << "ConcreteClass: Step2" << std::endl;
  }
  void Step3() override {
    std::cout << "ConcreteClass: Step3" << std::endl;
  }
};

int main(int argc, char *argv[]) {
  AbstractClass* t = new ConcreteClass();
  t->TemplateMethod();

  delete t;
  return 0;
}
