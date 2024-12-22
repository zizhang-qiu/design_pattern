//
// Created by 13738 on 2024/12/21.
//
#include <iostream>

class LegacyRectangle {
public:
  void Display(int x1, int y1, int x2, int y2) {
    std::cout << "LegacyRectangle: Point1(" << x1 << ", " << y1 << "), Point2(" << x2 << ", " << y2 << ")" << std::endl;
  }
};

class Shape {
  public:
  virtual ~Shape() = default;
  virtual void Draw(int x, int y, int width, int height) = 0;
};

class RectangleAdapter : public Shape {
public:
  explicit RectangleAdapter(LegacyRectangle* legacy_rectangle):
    rectangle(legacy_rectangle){}
  void Draw(int x, int y, int width, int height) override {
    int x1 = x;
    int y1 = y;
    int x2 = x + width;
    int y2 = y + height;
    rectangle->Display(x1, y1, x2, y2);
  }
private:
  LegacyRectangle* rectangle;
};

int main() {
  auto* legacy_rectangle = new LegacyRectangle();
  Shape* shape_adapter = new RectangleAdapter(legacy_rectangle);
  shape_adapter->Draw(10, 20, 50, 30);

  delete shape_adapter;
  delete legacy_rectangle;
  return 0;
}