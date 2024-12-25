//
// Created by 13738 on 2024/12/20.
#include <iostream>

class OperatingSystem {
  public:
  virtual ~OperatingSystem() = default;
  virtual void Run() = 0;
};

class WindowsOS : public OperatingSystem {
  public:
  void Run() override {
    std::cout << "Windows OS" << std::endl;
  }
};

class LinuxOS : public OperatingSystem {
  public:
  void Run() override {
    std::cout << "Linux OS" << std::endl;
  }
};

class Application {
  public:
  virtual ~Application() = default;
  virtual void Open() = 0;
};

class WordApp : public Application {
  public:
  void Open() override {
    std::cout << "WordApp" << std::endl;
  }
};

class ExcelApp : public Application {
  public:
  void Open() override {
    std::cout << "ExcelApp" << std::endl;
  }
};

class SoftwareFactory {
 public:
  virtual ~SoftwareFactory() = default;
  virtual OperatingSystem* CreateOperatingSystem() = 0;
  virtual Application* CreateApplication() = 0;
};

class WindowsFactory : public SoftwareFactory {
  public:
  OperatingSystem* CreateOperatingSystem() override {
    return new WindowsOS();
  }

  Application* CreateApplication() override {
    return new ExcelApp();
  }
};

class LinuxFactory : public SoftwareFactory {
  public:
  OperatingSystem* CreateOperatingSystem() override {
    return new LinuxOS();
  }

  Application* CreateApplication() override {
    return new WordApp();
  }
};

int main(int argc, char* argv[]) {
  auto windows_factory = new WindowsFactory();
  auto windows_os = windows_factory->CreateOperatingSystem();
  auto windows_app = windows_factory->CreateApplication();

  windows_os->Run();
  windows_app->Open();

  auto linux_factory = new LinuxFactory();
  auto linux_os = linux_factory->CreateOperatingSystem();
  auto linux_app = linux_factory->CreateApplication();

  linux_os->Run();
  linux_app->Open();

  delete windows_factory;
  delete linux_factory;
  delete windows_os;
  delete windows_app;
  delete linux_os;
  delete linux_app;

  return 0;
}
