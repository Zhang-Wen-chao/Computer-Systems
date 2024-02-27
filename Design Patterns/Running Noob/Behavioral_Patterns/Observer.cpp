#include <iostream>
#include <vector>
#include <bitset>

class Observer;

class Subject {
private:
   std::vector<Observer*> observers;
   int state;

public:
   int getState() const {
      return state;
   }

   void setState(int state) {
      this->state = state;
      notifyAllObservers();
   }

   void attach(Observer* observer) {
      observers.push_back(observer);
   }

   void notifyAllObservers();

};

class Observer {
protected:
   Subject* subject;

public:
   virtual void update() = 0;
};

class BinaryObserver : public Observer {
public:
   BinaryObserver(Subject* subject) {
      this->subject = subject;
      this->subject->attach(this);
   }

   void update() override {
      std::cout << "Binary String: "
                << std::bitset<4>(subject->getState()) << std::endl;
   }
};

class OctalObserver : public Observer {
public:
   OctalObserver(Subject* subject) {
      this->subject = subject;
      this->subject->attach(this);
   }

   void update() override {
      std::cout << "Octal String: "
                << std::oct << subject->getState() << std::endl;
   }
};

class HexaObserver : public Observer {
public:
   HexaObserver(Subject* subject) {
      this->subject = subject;
      this->subject->attach(this);
   }

   void update() override {
      std::cout << "Hex String: "
                << std::hex << subject->getState() << std::endl;
   }
};

void Subject::notifyAllObservers() {
   for (auto observer : observers) {
      observer->update();
   }
}

int main() {
   Subject subject;

   HexaObserver hexObserver(&subject);
   OctalObserver octObserver(&subject);
   BinaryObserver binObserver(&subject);

   std::cout << "First state change: 15\n";
   subject.setState(15);

   std::cout << "Second state change: 10\n";
   subject.setState(10);

   return 0;
}