//
// Created by 13738 on 2024/12/22.
//
#include <iostream>

class Color {
 public:
  virtual ~Color() = default;
  virtual void ApplyColor() = 0;
};

class Red : public Color {
 public:
  void ApplyColor() override { std::cout << "Applying red color" << std::endl; }
};

class Blue : public Color {
 public:
  void ApplyColor() override {
    std::cout << "Applying blue color" << std::endl;
  }
};

class Shape {
 public:
  virtual ~Shape() = default;
  explicit Shape(Color* color) : color_(color) {}

  virtual void Draw() = 0;

 protected:
  Color* color_;
};

class Circle : public Shape {
 public:
  explicit Circle(Color* color) : Shape(color) {}
  void Draw() override {
    std::cout << "Drawing a circle" << std::endl;
    color_->ApplyColor();
  }
};

class Square : public Shape {
 public:
  explicit Square(Color* color) : Shape(color) {}
  void Draw() override {
    std::cout << "Drawing a square" << std::endl;
    color_->ApplyColor();
  }
};

int main(int argc, char* argv[]) {
  Color* red_color = new Red();
  Color* blue_color = new Blue();

  Shape* red_circle = new Circle(red_color);
  Shape* blue_square = new Square(blue_color);

  red_circle->Draw();
  blue_square->Draw();

  delete red_color;
  delete blue_color;
  delete red_circle;
  delete blue_square;

  return 0;
}
