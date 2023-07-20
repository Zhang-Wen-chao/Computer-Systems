#include <iostream>
#include <string>
#include <ctime>

class ChatRoom {
public:
   static void showMessage(const std::string& name, const std::string& message) {
      std::time_t currentTime = std::time(nullptr);
      std::cout << std::asctime(std::localtime(&currentTime))
         << " [" << name << "] : " << message << std::endl;
   }
};

class User {
private:
   std::string name;

public:
   User(const std::string& name)
      : name(name) {}

   std::string getName() const {
      return name;
   }

   void sendMessage(const std::string& message) {
      ChatRoom::showMessage(this->name, message);
   }
};

int main() {
   User* robert = new User("Robert");
   User* john = new User("John");

   robert->sendMessage("Hi! John!");
   john->sendMessage("Hello! Robert!");

   delete robert;
   delete john;

   return 0;
}