//
// Created by 13738 on 2024/12/24.
//
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

class Observer {
  public:
  virtual ~Observer() = default;
  virtual void Update(int state) = 0;
  virtual bool operator==(const Observer &other) const {
    return false;
  }
};

class Subject {
public:
  virtual ~Subject() = default;
  virtual void AddObserver(Observer* observer)=0;
  virtual void RemoveObserver(Observer* observer)=0;
  virtual void NotifyObservers()=0;
};

class ConcreteSubject : public Subject {
public:
  int GetState() {
    return state_;
  }

  void SetState(int state) {
    state_ = state;
    NotifyObservers();
  }

  void AddObserver(Observer* observer) override {
    observers.push_back(observer);
  }

  void RemoveObserver(Observer* observer) override {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
      observers.erase(it);
    }
  }

  void NotifyObservers() override {
    for (auto observer : observers) {
      observer->Update(state_);
    }
  }
private:
  std::vector<Observer*> observers;
  int state_;
};

class ConcreteObserver : public Observer {
public:
  explicit ConcreteObserver(std::string name):name_(std::move(name)){}

  void Update(int state) override {
    std::cout << name_ << " get update, new state: " << state << std::endl;
  }

  bool operator==(const ConcreteObserver &other) const {
    return name_ == other.name_;
  }
private:
  std::string name_;
};

int main(int argc, char* argv[]) {
  auto subject = new ConcreteSubject();

  auto observer1 = new ConcreteObserver("Observer 1");
  auto observer2 = new ConcreteObserver("Observer 2");

  subject->AddObserver(observer1);
  subject->AddObserver(observer2);

  subject->SetState(10);
  subject->SetState(20);

  subject->RemoveObserver(observer1);

  subject->SetState(30);

  delete subject;
  delete observer1;
  delete observer2;

  return 0;
}
