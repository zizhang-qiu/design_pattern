//
// Created by 13738 on 2024/12/24.
//
#include <iostream>

class Expression {
  public:
  virtual ~Expression() = default;
  virtual int Interpret() = 0;
};

class NumberExpression : public Expression {
  public:
  explicit NumberExpression(const int value) : value_(value) {}

  int Interpret() override { return value_; }

private:
  int value_;
};

class AddExpression : public Expression {
public:
  AddExpression(Expression *left, Expression *right) : left_(left), right_(right) {}
  ~AddExpression() override {
    delete left_;
    delete right_;
  }
  int Interpret() override { return left_->Interpret() + right_->Interpret(); }
private:
  Expression *left_;
  Expression *right_;
};

class SubtractExpression : public Expression {
public:
  SubtractExpression(Expression *left, Expression *right) : left_(left), right_(right) {}
  ~SubtractExpression() override {
    delete left_;
    delete right_;
  }
  int Interpret() override { return left_->Interpret() - right_->Interpret(); }
private:
  Expression *left_;
  Expression *right_;
};

int main(int argc, char *argv[]) {
  Expression* expression = new AddExpression(
    new NumberExpression(2),
    new SubtractExpression(
      new NumberExpression(3), new NumberExpression(1))
    );

  std::cout << expression->Interpret() << std::endl;
  delete expression;
  return 0;
}
