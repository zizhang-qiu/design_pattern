//
// Created by 13738 on 2024/12/21.
//
#include <iostream>

class Singleton {
  public:
  static Singleton& GetInstance() {
    static Singleton instance;
    return instance;
  }

  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

  void DoSomething() const{
    std::cout << "Doing something" << std::endl;
  }

private:
  Singleton() {
    std::cout << "Singleton instance created!" << std::endl;
  }

  ~Singleton() {
    std::cout << "Singleton instance destroyed!" << std::endl;
  }
};

int main() {
  Singleton::GetInstance().DoSomething();

  // The following code would cause compilation errors as you cannot directly create or copy the singleton.
  // Singleton instance2;  // Error! Constructor is private
  // Singleton instance3 = Singleton::Instance();  // Error! Copying is disabled

  return 0;
}