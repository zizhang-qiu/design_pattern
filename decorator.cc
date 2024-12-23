//
// Created by 13738 on 2024/12/23.
//
#include <string>
#include <iostream>

class Coffee {
public:
  virtual ~Coffee() = default;
  virtual double Cost() = 0;
  virtual std::string Description() = 0;
};

class SimpleCoffee : public Coffee {
public:
  double Cost() override {
    return 2.0;
  }

  std::string Description() override {
    return "Simple Coffee";
  }
};

class CoffeeDecorator : public Coffee {
public:
  explicit CoffeeDecorator(Coffee* coffee):decorated_coffee_(coffee){}

  double Cost() override {
    return decorated_coffee_->Cost();
  }

  std::string Description() override {
    return decorated_coffee_->Description();
  }
protected:
  Coffee *decorated_coffee_;
};

class MilkDecorator: public CoffeeDecorator {
  public:
  MilkDecorator(Coffee* coffee):CoffeeDecorator(coffee){}

  double Cost() override {
    return CoffeeDecorator::Cost() + 1.0;
  }

  std::string Description() override {
    return CoffeeDecorator::Description() + ", with Milk";
  }
};

class SugarDecorator: public CoffeeDecorator {
public:
  SugarDecorator(Coffee *coffee):CoffeeDecorator(coffee){}

  double Cost() override {
    return CoffeeDecorator::Cost() + 0.5;
  }

  std::string Description() override {
    return CoffeeDecorator::Description() + ", with Sugar";
  }
};

int main(int argc, char *argv[]) {
  Coffee *simple_coffee = new SimpleCoffee();
  std::cout << "Cost: $" << simple_coffee->Cost() << ", Description: " << simple_coffee->Description() << std::endl;

  Coffee* milk_coffee = new MilkDecorator(simple_coffee);
  std::cout << "Cost: $" << milk_coffee->Cost() << ", Description: " << milk_coffee->Description() << std::endl;

  Coffee* sugar_milk_coffee = new SugarDecorator(milk_coffee);
  std::cout << "Cost: $" << sugar_milk_coffee->Cost() << ", Description: " << sugar_milk_coffee->Description() << std::endl;

  delete simple_coffee;
  delete milk_coffee;
  delete sugar_milk_coffee;

  return 0;
}
