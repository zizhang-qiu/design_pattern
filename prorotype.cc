//
// Created by 13738 on 2024/12/21.
//
#include <iostream>
#include <memory>
#include <string>
#include <utility>

class Prototype {
 public:
  virtual ~Prototype() = default;

  virtual std::unique_ptr<Prototype> Clone() = 0;

  virtual void Display() const = 0;
};

class ConcretePrototypeA : public Prototype {
 public:
  explicit ConcretePrototypeA(std::string  value) : value_(std::move(value)) {}

  std::unique_ptr<Prototype> Clone() override {
    return std::make_unique<ConcretePrototypeA>(*this);
  }

  void Display() const override {
    std::cout << "ConcretePrototypeA: " << value_ << std::endl;
  }

 private:
  std::string value_;
};

class ConcretePrototypeB : public Prototype {
 public:
  explicit ConcretePrototypeB(int value) : value_(value) {}
  std::unique_ptr<Prototype> Clone() override {
    return std::make_unique<ConcretePrototypeB>(*this);
  }

  void Display() const override {
    std::cout << "ConcretePrototypeB: " << value_ << std::endl;
  }

 private:
  int value_;
};

int main(int argc, char* argv[]) {
  ConcretePrototypeA proto_a("Hello, Prototype!");
  ConcretePrototypeB proto_b(42);

  std::unique_ptr<Prototype> cloneA = proto_a.Clone();
  std::unique_ptr<Prototype> cloneB = proto_b.Clone();

  cloneA->Display();  // Output: ConcretePrototypeA: Hello, Prototype!
  cloneB->Display();  // Output: ConcretePrototypeB: 42

  return 0;
}
