//
// Created by 13738 on 2024/12/21.
//
#include <iostream>
#include <string>

class House {

  public:
  void SetFoundation(const std::string& foundation) {
    foundation_ = foundation;
  }
  void SetStructure(const std::string& structure) {
    structure_ = structure;
  }
  void SetRoof(const std::string& roof) {
    roof_ = roof;
  }
  void SetInterior(const std::string& interior) {
    interior_ = interior;
  }
  [[nodiscard]] std::string ToString() const {
    return "House [foundation=" + foundation_ + ", structure=" + structure_ +"roof=" + roof_ + "interior=" + interior_ + "]";
  }
private:
  std::string foundation_;
  std::string structure_;
  std::string roof_;
  std::string interior_;
};

class HouseBuilder {
public:
  virtual ~HouseBuilder() = default;
  virtual void BuildFoundation() = 0;
  virtual void BuildStructure() = 0;
  virtual void BuildRoof() = 0;
  virtual void BuildInterior() = 0;
  [[nodiscard]] House* GetHouse() const {
    return house_;
  }
protected:
  House* house_ = new House();
};

class ConcreteHouseBuilder : public HouseBuilder {
public:
  void BuildFoundation() override {
    house_->SetFoundation("Standard Foundation");
  }
  void BuildStructure() override {
    house_->SetStructure("Standard Structure");
  }
  void BuildRoof() override {
    house_->SetRoof("Standard Roof");
  }
  void BuildInterior() override {
    house_->SetInterior("Standard Interior");
  }
};

class LuxuryHouseBuilder : public HouseBuilder {
public:
  void BuildFoundation() override {
    house_->SetFoundation("Strong Foundation");
  }
  void BuildStructure() override {
    house_->SetStructure("Reinforced Structure");
  }
  void BuildRoof() override {
    house_->SetRoof("Elegant Roof");
  }
  void BuildInterior() override {
    house_->SetInterior("Luxury Interior");
  }
};

class Director {
public:
  explicit Director(HouseBuilder* house_builder)
    :house_builder_(house_builder){}

  [[nodiscard]] House* ConstructHouse() const {
    house_builder_->BuildFoundation();
    house_builder_->BuildStructure();
    house_builder_->BuildRoof();
    house_builder_->BuildInterior();
    return house_builder_->GetHouse();
  }

private:
  HouseBuilder* house_builder_;
};

int main(int argc, char* argv[]) {
  HouseBuilder* concrete_house_builder = new ConcreteHouseBuilder();
  const auto* director1 = new Director(concrete_house_builder);
  const House* concrete_house = director1->ConstructHouse();
  std::cout << "Concrete house: " << concrete_house->ToString() << std::endl;
  delete concrete_house;
  delete director1;
  delete concrete_house_builder;

  HouseBuilder* luxury_house_builder = new LuxuryHouseBuilder();
  const auto* director2 = new Director(luxury_house_builder);
  const House* luxury_house = director2->ConstructHouse();
  std::cout << "Luxury House: " << luxury_house->ToString() << std::endl;
  delete luxury_house;
  delete director2;
  delete luxury_house_builder;

  return 0;
}
