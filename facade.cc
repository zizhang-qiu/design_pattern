//
// Created by 13738 on 2024/12/23.
//
#include <iostream>

class StereoSystem {
 public:
  void TurnOn() { std::cout << "Stereo System is turned on\n"; }

  void TurnOff() { std::cout << "Stereo System is turned off\n"; }
};

class Projector {
 public:
  void TurnOn() { std::cout << "Projector is turned on\n"; }
  void TurnOff() { std::cout << "Projector is turned off\n"; }
};

class LightsControl {
 public:
  void TurnOn() { std::cout << "Lights are turned on\n"; }

  void TurnOff() { std::cout << "Lights are turned off\n"; }
};

class HomeTheaterFacade {
 public:
  HomeTheaterFacade()
      : stereo_(new StereoSystem()),
        projector_(new Projector()),
        lights_(new LightsControl()) {}

  ~HomeTheaterFacade() {
    delete stereo_;
    delete projector_;
    delete lights_;
  }

  void WatchMovie() {
    std::cout << "Getting ready to watch a movie...\n";
    lights_->TurnOff();
    projector_->TurnOn();
    stereo_->TurnOn();
  }

  void EndMovie() {
    std::cout << "Ending the movie...\n";
    stereo_->TurnOff();
    projector_->TurnOff();
    lights_->TurnOn();
  }

 private:
  StereoSystem* stereo_;
  Projector* projector_;
  LightsControl* lights_;
};

int main(int argc, char* argv[]) {
  auto* home_theater = new HomeTheaterFacade();
  home_theater->WatchMovie();
  home_theater->EndMovie();
  delete home_theater;
  return 0;
}
