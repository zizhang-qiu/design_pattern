//
// Created by 13738 on 2024/12/25.
//
#include <iostream>

class ElevatorState {
 public:
  virtual ~ElevatorState() = default;
  virtual void CloseDoors() = 0;
  virtual void OpenDoors() = 0;
  virtual void Move() = 0;
  virtual void Stop() = 0;
};

class OpenState : public ElevatorState {
 public:
  void OpenDoors() override { std::cout << "Doors are already open.\n"; }
  void CloseDoors() override { std::cout << "Closing doors.\n"; }
  void Move() override { std::cout << "Cannot move while doors are open\n"; }
  void Stop() override { std::cout << "Stopping while doors are open\n"; }
};

class CloseState : public ElevatorState {
 public:
  void CloseDoors() override { std::cout << "Doors are already closed.\n"; }
  void OpenDoors() override { std::cout << "Opening doors.\n"; }
  void Move() override { std::cout << "Moving\n"; }
  void Stop() override { std::cout << "Stopping\n"; }
};

class Elevator {
 public:
  Elevator() : state_(new CloseState()) {}
  void SetState(ElevatorState *state) { state_ = state; }
  void OpenDoors() {
    state_->OpenDoors();
    state_ = new OpenState();
  }
  void CloseDoors() {
    state_->CloseDoors();
    state_ = new CloseState();
  }
  void Move() { state_->Move(); }
  void Stop() { state_->Stop(); }

 private:
  ElevatorState *state_;
};

int main(int argc, char *argv[]) {
  auto elevator = new Elevator();
  elevator->OpenDoors();
  elevator->Move();
  elevator->CloseDoors();
  elevator->Move();
  elevator->Stop();
  elevator->OpenDoors();
  delete elevator;
  return 0;
}
