//
// Created by 13738 on 2024/12/20.
//
#include <iostream>

class Shape {
  public:
    virtual ~Shape() = default;
    virtual void Draw() = 0;
};

class Rectangle : public Shape {
  public:
  ~Rectangle() override = default;
  void Draw() override {
    std::cout << "Rectangle Draw" << std::endl;
  }
};

class Circle : public Shape {
  public:
  ~Circle() override = default;
  void Draw() override {
    std::cout << "Circle Draw" << std::endl;
  }
};

class Factory {
  public:
  virtual ~Factory() = default;
  Shape *CreateShape(std::string_view type) {
    if (type=="Rectangle") {
      return new Rectangle();
    }
    if (type=="Circle") {
      return new Circle();
    }
    return nullptr;
  }
};

int main(int argc, char *argv[]) {
  auto *my_factory = new Factory();
  const auto rec = my_factory->CreateShape("Rectangle");
  const auto circle= my_factory->CreateShape("Circle");

  rec->Draw();
  circle->Draw();
  delete my_factory;
  delete rec;
  delete circle;
}
