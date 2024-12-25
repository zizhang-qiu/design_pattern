//
// Created by 13738 on 2024/12/24.
//
#include <iostream>
#include <vector>
template <typename T>
class Iterator {
 public:
  virtual ~Iterator() = default;

  virtual T Next()=0;
  virtual bool HasNext()=0;
};

template<typename T>
class IterableCollection {
public:
  virtual ~IterableCollection() = default;
  virtual Iterator<T>* CreateIterator() = 0;
};

template<typename T>
class ConcreteIterator: public Iterator<T> {
public:
  explicit ConcreteIterator(const std::vector<T>& items): items_(items) {}
  bool HasNext() override {return position_ < items_.size();}
  T Next() override {
    if (HasNext()) {
      T item = items_[position_];
      ++position_;
      return item;
    }
    throw std::out_of_range("No more items available");
  }
private:
  std::vector<T> items_;
  int position_ = 0;
};

template<typename T>
class ConcreteCollection: public IterableCollection<T> {
public:
  void AddItem(const T& item) {
    items_.push_back(item);
  }

  Iterator<T>* CreateIterator() override {
    return new ConcreteIterator(items_);
  }
private:
  std::vector<T> items_;
};



int main(int argc, char* argv[]) {
  auto* collection = new ConcreteCollection<std::string>();
  collection->AddItem("Item 1");
  collection->AddItem("Item 2");
  collection->AddItem("Item 3");

  const auto iterator = collection->CreateIterator();
  while (iterator->HasNext()) {
    std::cout << iterator->Next() << std::endl;
  }

  delete iterator;
  delete collection;
  return 0;
}
