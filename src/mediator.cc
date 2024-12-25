//
// Created by 13738 on 2024/12/24.
//
#include <iostream>
#include <vector>

class User;

class ChatMediator {
 public:
  virtual ~ChatMediator() = default;
  virtual void SendMessage(const std::string& message, User* user) = 0;
  virtual void AddUser(User* user) = 0;
};

class User {
 public:
  User(std::string  name, ChatMediator* mediator)
      : name_(std::move(name)), mediator_(mediator) {}

  void SendMessage(const std::string& message) {
    std::cout << name_ << " send message: " << message << std::endl;
    mediator_->SendMessage(message, this);
  }

  void ReceiveMessage(const std::string& message) {
    std::cout << name_ << " receive message: " << message << std::endl;
  }

  bool operator==(const User& other) const {
    return name_ == other.name_;
  }

  bool operator!=(const User& other) const {
    return name_ != other.name_;
  }

 private:
  std::string name_;
  ChatMediator* mediator_;
};

class ConcreteChatMediator : public ChatMediator {
public:
  void SendMessage(const std::string& message, User* user) override {
    for (const auto u: users_) {
      if (*u != *user) {
        u->ReceiveMessage(message);
      }
    }
  }

  void AddUser(User* user) override{
    users_.push_back(user);
  }
private:
  std::vector<User*> users_;
};

int main(int argc, char* argv[]) {
  auto chat_mediator = new ConcreteChatMediator();

  auto user1 = new User("Alice", chat_mediator);
  auto user2 = new User("Bob", chat_mediator);
  auto user3 = new User("Charlie", chat_mediator);

  chat_mediator->AddUser(user1);
  chat_mediator->AddUser(user2);
  chat_mediator->AddUser(user3);

  user1->SendMessage("Hello");
  user2->SendMessage("Hello Alice");

  delete user1;
  delete user2;
  delete user3;
  delete chat_mediator;
  return 0;
}
