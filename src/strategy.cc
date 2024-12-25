//
// Created by 13738 on 2024/12/25.
//
#include <iostream>

class MathOperation {
  public:
  virtual ~MathOperation() = default;
  virtual int Operate(int a, int b) = 0;
};

class Addition : public MathOperation {
  public:
  int Operate(int a, int b) override {
    return a + b;
  }
};

class Subtraction : public MathOperation {
  public:
  int Operate(int a, int b) override {
    return a - b;
  }
};

class Multiplication : public MathOperation {
  public:
  int Operate(int a, int b) override {
    return a * b;
  }
};

class Calculator {
  public:
  void SetOperation(MathOperation* operation) {
    operation_ = operation;
  }

  int PerformOperation(int a, int b) {
    if (operation_ != nullptr) {
      return operation_->Operate(a, b);
    }
    throw std::invalid_argument("No operation set.");
  }
private:
  MathOperation *operation_;
};

int main(int argc, char *argv[]) {
  auto calc = new Calculator();
  auto add = new Addition();
  calc->SetOperation(add);
  int res1 = calc->PerformOperation(5, 3);
  std::cout << "Addition result: " << res1 << std::endl;

  auto sub = new Subtraction();
  calc->SetOperation(sub);
  int res2 = calc->PerformOperation(10, 4);
  std::cout << "Subtraction result: " << res2 << std::endl;

  auto mul = new Multiplication();
  calc->SetOperation(mul);
  int res3 = calc->PerformOperation(6, 2);
  std::cout << "Multiplication result: " << res3 << std::endl;

  delete calc;
  delete add;
  delete sub;
  delete mul;

  return 0;
}
