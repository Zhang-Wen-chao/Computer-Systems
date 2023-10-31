#include <iostream>
#include <string>

class Expression {
public:
   virtual bool interpret(const std::string& context) = 0;
};

class TerminalExpression : public Expression {
private:
   std::string data;

public:
   TerminalExpression(const std::string& data)
      : data(data) {}

   bool interpret(const std::string& context) override {
      if (context.find(data) != std::string::npos) {
         return true;
      }
      return false;
   }
};

class OrExpression : public Expression {
private:
   Expression* expr1;
   Expression* expr2;

public:
   OrExpression(Expression* expr1, Expression* expr2)
      : expr1(expr1), expr2(expr2) {}

   bool interpret(const std::string& context) override {
      return expr1->interpret(context) || expr2->interpret(context);
   }
};

class AndExpression : public Expression {
private:
   Expression* expr1;
   Expression* expr2;

public:
   AndExpression(Expression* expr1, Expression* expr2)
      : expr1(expr1), expr2(expr2) {}

   bool interpret(const std::string& context) override {
      return expr1->interpret(context) && expr2->interpret(context);
   }
};

int main() {
   Expression* isMale = new OrExpression(
      new TerminalExpression("Robert"),
      new TerminalExpression("John")
   );
   Expression* isMarriedWoman = new AndExpression(
      new TerminalExpression("Julie"),
      new TerminalExpression("Married")
   );

   std::cout << "John is male? " << (isMale->interpret("John") ? "true" : "false") << std::endl;
   std::cout << "Julie is a married woman? " << (isMarriedWoman->interpret("Married Julie") ? "true" : "false") << std::endl;

   delete isMale;
   delete isMarriedWoman;

   return 0;
}