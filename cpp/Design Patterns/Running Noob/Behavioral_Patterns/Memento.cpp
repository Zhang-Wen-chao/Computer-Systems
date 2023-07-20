#include <iostream>
#include <vector>
#include <string>

class Memento {
private:
   std::string state;

public:
   Memento(const std::string& state)
      : state(state) {}

   std::string getState() const {
      return state;
   }
};

class Originator {
private:
   std::string state;

public:
   void setState(const std::string& state) {
      this->state = state;
   }

   std::string getState() const {
      return state;
   }

   Memento saveStateToMemento() {
      return Memento(state);
   }

   void getStateFromMemento(const Memento& memento) {
      state = memento.getState();
   }
};

class CareTaker {
private:
   std::vector<Memento> mementoList;

public:
   void add(const Memento& state) {
      mementoList.push_back(state);
   }

   Memento get(int index) {
      return mementoList[index];
   }
};

int main() {
   Originator originator;
   CareTaker careTaker;
   originator.setState("State #1");
   originator.setState("State #2");
   careTaker.add(originator.saveStateToMemento());
   originator.setState("State #3");
   careTaker.add(originator.saveStateToMemento());
   originator.setState("State #4");

   std::cout << "Current State: " << originator.getState() << std::endl;
   originator.getStateFromMemento(careTaker.get(0));
   std::cout << "First saved State: " << originator.getState() << std::endl;
   originator.getStateFromMemento(careTaker.get(1));
   std::cout << "Second saved State: " << originator.getState() << std::endl;

   return 0;
}