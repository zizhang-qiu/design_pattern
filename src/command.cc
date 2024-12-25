//
// Created by 13738 on 2024/12/24.
//
#include <iostream>

class Command {
 public:
  virtual ~Command() = default;
  virtual void Execute() = 0;
};

class Light {
public:
  void TurnOn() {
    std::cout << "Light is on" << std::endl;
  }

  void TurnOff() {
    std::cout << "Light is off" << std::endl;
  }
};

class LightOnCommand : public Command {
 public:
  explicit LightOnCommand(Light* light) : light_(light) {}

  void Execute() override {
    light_->TurnOn();
  }

 private:
  Light* light_;
};

class LightOffCommand : public Command {
public:
  explicit LightOffCommand(Light* light) : light_(light) {}

  void Execute() override {
    light_->TurnOff();
  }

private:
  Light* light_;
};

class RemoteControl {
public:
  void SetCommand(Command* command) {
    command_ = command;
  }

  void PressButton() {
    command_->Execute();
  }
private:
  Command* command_ = nullptr;
};

int main(int argc, char* argv[]) {
  auto living_room_light = new Light();

  auto living_room_light_on = new LightOnCommand(living_room_light);
  auto living_room_light_off = new LightOffCommand(living_room_light);

  auto remote = new RemoteControl();

  remote->SetCommand(living_room_light_on);
  remote->PressButton();

  remote->SetCommand(living_room_light_off);
  remote->PressButton();

  delete remote;
  delete living_room_light;
  delete living_room_light_on;
  delete living_room_light_off;

  return 0;
}
