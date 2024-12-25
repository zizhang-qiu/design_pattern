//
// Created by 13738 on 2024/12/24.
//
#include <iostream>
#include <utility>

class Memento {
  public:
  explicit Memento(std::string  state) :state_(std::move(state)){}

  std::string GetState() const {
    return state_;
  }

private:
  std::string state_;
};

class Originator {
public:
  void SetState(std::string  state) {
    state_ = std::move(state);
  }

  [[nodiscard]] std::string GetState() const {
    return state_;
  }

  [[nodiscard]] Memento* CreateMemento() const {
    return new Memento(state_);
  }

  void RestoreMemento(const Memento* memento) {
    state_ = memento->GetState();
  }
private:
  std::string state_;
};

class Caretaker {
public:
  [[nodiscard]] Memento* GetMemento() const {
    return memento_;
  }

  void SetMemento(Memento* memento) {
    memento_ = memento;
  }
private:
  Memento* memento_ = nullptr;
};

int main() {
  auto originator = new Originator();
  auto caretaker = new Caretaker();

  originator->SetState("State 1");
  std::cout << "Current state: " << originator->GetState() << std::endl;

  const auto memento = originator->CreateMemento();
  caretaker->SetMemento(memento);

  originator->SetState("State 2");
  std::cout << "Updated state: " << originator->GetState() << std::endl;

  originator->RestoreMemento(caretaker->GetMemento());
  std::cout << "Restored state: " << originator->GetState() << std::endl;

  delete originator;
  delete caretaker;
  delete memento;
  return 0;
}