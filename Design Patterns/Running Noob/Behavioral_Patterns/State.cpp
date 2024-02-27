#include <iostream>
#include <string>

class Context;

class State {
public:
   virtual void doAction(Context* context) = 0;
   virtual std::string toString() = 0;
};

class StartState : public State {
public:
   void doAction(Context* context) override;
   std::string toString() override;
};

class StopState : public State {
public:
   void doAction(Context* context) override;
   std::string toString() override;
};

class Context {
private:
   State* state;

public:
   Context() {
      state = nullptr;
   }

   void setState(State* state) {
      this->state = state;
   }

   State* getState() {
      return state;
   }
};

void StartState::doAction(Context* context) {
   std::cout << "Player is in start state\n";
   context->setState(this);
}

std::string StartState::toString() {
   return "Start State";
}

void StopState::doAction(Context* context) {
   std::cout << "Player is in stop state\n";
   context->setState(this);
}

std::string StopState::toString() {
   return "Stop State";
}

int main() {
   Context context;

   StartState startState;
   startState.doAction(&context);

   std::cout << context.getState()->toString() << std::endl;

   StopState stopState;
   stopState.doAction(&context);

   std::cout << context.getState()->toString() << std::endl;

   return 0;
}