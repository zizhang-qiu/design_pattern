//
// Created by 13738 on 2024/12/23.
//
#include <iostream>
#include <string>
#include <utility>
class Image {
  public:
  virtual ~Image()  = default;
  virtual void Display() = 0;
};

class RealImage : public Image {
public:
  explicit RealImage(std::string filename):filename_(std::move(filename)) {
    LoadImageFromDisk();
  }

  void Display() override {
    std::cout << "Displaying image: " << filename_ << std::endl;
  }

private:
  std::string filename_;
  void LoadImageFromDisk() {
    std::cout << "Loading image from disk: " << filename_ << std::endl;
  }
};

class ProxyImage : public Image {
  public:
  explicit ProxyImage(std::string filename):filename_(std::move(filename)) {}

  void Display() override {
    if (real_image_ == nullptr) {
      real_image_ = new RealImage(filename_);
    }
    real_image_->Display();
  }
private:
  RealImage* real_image_{};
  std::string filename_;
};

int main(int argc, char* argv[]) {
  Image* image = new ProxyImage("sample.jpg");
  image->Display();
  image->Display();

  delete image;
  return 0;
}


