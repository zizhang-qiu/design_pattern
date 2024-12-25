//
// Created by 13738 on 2024/12/22.
//
#include <iostream>
#include <utility>
#include <vector>

class FileSystemComponent {
public:
  virtual ~FileSystemComponent() = default;
  virtual void DisplayInfo() = 0;
};

class File : public FileSystemComponent {
public:
  explicit File(std::string name) : name_(std::move(name)) {}
  void DisplayInfo() override {
    std::cout << "File: " << name_ << "\n";
  }
private:
  std::string name_;
};

class Directory : public FileSystemComponent {
public:
  explicit Directory(std::string name) : name_(std::move(name)) {}
  void AddComponent(FileSystemComponent* component) {
    components_.push_back(component);
  }

  void DisplayInfo() override {
    std::cout << "Directory: " << name_ << "\n";
    for (const auto component : components_) {
      component->DisplayInfo();
    }
  }

  private:
  std::string name_;
  std::vector<FileSystemComponent*> components_;
};

int main(int argc, char* argv[]) {
  const auto file1 = new File("file1.txt");
  const auto file2 = new File("file2.txt");
  auto* sub_directory = new Directory("subdirectory");

  sub_directory->AddComponent(file1);
  sub_directory->AddComponent(file2);

  auto* root_directory = new Directory("root");
  root_directory->AddComponent(sub_directory);

  root_directory->DisplayInfo();
  delete sub_directory;
  delete root_directory;
  delete file1;
  delete file2;
  return 0;
}
