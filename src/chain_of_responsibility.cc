//
// Created by 13738 on 2024/12/24.
//
#include <iostream>
#include <string>
#include <utility>

class ReimbursementRequest {
 public:
  ReimbursementRequest(const double amount, std::string description)
      : amount_{amount}, description_{std::move(description)} {}

  double Amount() const { return amount_; }

  std::string Description() const { return description_; }

 private:
  double amount_;
  std::string description_;
};

class ReimbursementHandler {
public:
  virtual ~ReimbursementHandler() = default;
  void SetSuccessor(ReimbursementHandler* successor) {
    successor_ = successor;
  }
  virtual void HandleRequest(ReimbursementRequest request) = 0;
protected:
  ReimbursementHandler* successor_{};
};

class ManagerHandler : public ReimbursementHandler {
public:
  void HandleRequest(ReimbursementRequest request) override {
    if (request.Amount() <= 1000) {
      std::cout << "Manager handles the request: " << request.Description() << std::endl;
    }else if (successor_ != nullptr) {
      successor_->HandleRequest(request);
    }
  }
};

class DepartmentHeadHandler : public ReimbursementHandler {
public:
  void HandleRequest(ReimbursementRequest request) override {
    if (request.Amount() <= 5000) {
      std::cout << "Department head handles the request: " << request.Description() << std::endl;
    }else if (successor_ != nullptr) {
      successor_->HandleRequest(request);
    }
  }
};

class FinanceHandler : public ReimbursementHandler {
public:
  void HandleRequest(ReimbursementRequest request) override {
      std::cout << "Finance handles the request: " << request.Description() << std::endl;
  }
};

int main(int argc, char* argv[]) {
  const auto manager = new ManagerHandler();
  const auto department_head = new DepartmentHeadHandler();
  const auto finance = new FinanceHandler();

  manager->SetSuccessor(department_head);
  department_head->SetSuccessor(finance);

  ReimbursementRequest request1(800, "Buy office items");
  ReimbursementRequest request2(3000, "Join class");
  ReimbursementRequest request3(10000, "Hold events");

  manager->HandleRequest(request1);
  manager->HandleRequest(request2);
  manager->HandleRequest(request3);

  delete manager;
  delete department_head;
  delete finance;

  return 0;
}
