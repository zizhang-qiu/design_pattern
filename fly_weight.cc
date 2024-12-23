//
// Created by 13738 on 2024/12/23.
//
#include <random>

#include <iostream>
#include <unordered_map>

enum Color {
  kRed, kGreen, kBlue, kYellow
};

std::ostream& operator<<(std::ostream& os, const Color& color) {
  switch (color) {
    case Color::kRed:
      os << "Red";
      break;
    case Color::kGreen:
      os << "Green";
      break;
    case Color::kBlue:
      os << "Blue";
      break;
    case Color::kYellow:
      os << "Yellow";
      break;
    default:
      os << "Unknown";
  }
  return os;
}

class Shape {
public:
  virtual  ~Shape()  = default;
  virtual void Draw(int x, int y) = 0;
};

class Circle : public Shape {
  public:
  Circle(Color c) : color_(c) {}

  void Draw(int x, int y) override {
    std::cout << "Drawing a " << color_ << " circle at (" << x << ", " << y << ")" << std::endl;
  }
private:
  Color color_;
};

class ShapeFactory {
public:
  static Shape* GetCircle(Color color) {
    auto it = circle_map_.find(color);
    if (it == circle_map_.end()) {
      Shape* new_shape = new Circle(color);
      circle_map_[color] = new_shape;
      return new_shape;
    }
    return it->second;
  }

private:
  static std::unordered_map<Color, Shape*> circle_map_;
};

std::unordered_map<Color, Shape*> ShapeFactory::circle_map_;

int main() {
  Color colors[] = { kRed, kGreen, kBlue, kYellow };
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(0, std::size(colors) - 1);
  std::uniform_int_distribution<int> dist2(0, 100);
  for (int i=0; i<20; ++i) {
    Color random_color = colors[dist(gen)];
    Shape* circle = ShapeFactory::GetCircle(random_color);
    circle->Draw(dist2(gen), dist2(gen));
  }

  return 0;
}