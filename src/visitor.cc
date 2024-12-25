//
// Created by 13738 on 2024/12/25.
//
#include <iostream>

constexpr double PI = 3.14159265358979323846;
class ShapeVisitor;

class Shape {
 public:
  virtual ~Shape() = default;
  virtual void Accept(ShapeVisitor* visitor) = 0;
};

class Circle : public Shape {
 public:
  explicit Circle(const double radius) : radius_(radius) {}
  [[nodiscard]] double GetRadius() const { return radius_; }
  void Accept(ShapeVisitor* visitor) override;

 private:
  double radius_;
};

class Rectangle : public Shape {
 public:
  Rectangle(const double width, const double height) : width_(width), height_(height) {}
  [[nodiscard]] double GetWidth() const { return width_; }
  [[nodiscard]] double GetHeight() const { return height_; }
  void Accept(ShapeVisitor* visitor) override;

 private:
  double width_;
  double height_;
};

class ShapeVisitor {
 public:
  virtual ~ShapeVisitor() = default;
  virtual void Visit(Circle* circle) = 0;
  virtual void Visit(Rectangle* rectangle) = 0;
};

void Circle::Accept(ShapeVisitor* visitor) { visitor->Visit(this); }

void Rectangle::Accept(ShapeVisitor* visitor) { visitor->Visit(this); }

class AreaCalculator : public ShapeVisitor {
 public:
  void Visit(Circle* circle) override{
    area_ += PI * circle->GetRadius() * circle->GetRadius();
  }

  void Visit(Rectangle* rectangle) override{
    area_ += rectangle->GetWidth() * rectangle->GetHeight();
  }

  [[nodiscard]] double GetArea() const { return area_; }

 private:
  double area_ = 0;
};

int main(int argc, char* argv[]) {
  const auto circle = new Circle(5);
  const auto rectangle = new Rectangle(4, 6);

  const auto area_calculator = new AreaCalculator();
  circle->Accept(area_calculator);
  rectangle->Accept(area_calculator);

  std::cout << "Total area: " << area_calculator->GetArea() << std::endl;
  delete area_calculator;
  delete circle;
  delete rectangle;
  return 0;
}
