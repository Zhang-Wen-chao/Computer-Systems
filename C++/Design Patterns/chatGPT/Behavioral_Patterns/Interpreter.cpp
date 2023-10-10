/*
Interpreter

Intent
Given a language, define a represention for its grammar along with an interpreter that uses the representation to interpret sentences in the language.

Applicability
Use the Interpreter pattern when there is a language to interpret, and you can represent statements in the language as abstract syntax trees. The Interpreter pattern works best when

• the grammar is simple. For complex grammars, the class hierarchy for the grammar becomes large and unmanageable. Tools such as parser generators are a better alternative in such cases. They can interpret expressions without building abstract syntax trees, which can save space and possibly time.

• efficiency is not a critical concern. The most efficient interpreters are usually not implemented by interpreting parse trees directly but by first translating them into another form. For example, regular expressions are often transformed into state machines. But even then, the translator can be implemented by the Interpreter pattern, so the pattern is still applicable.
*/

#include <iostream>
#include <string>
#include <unordered_map>

// Abstract Expression
class Expression {
public:
    virtual int interpret(std::unordered_map<std::string, int>& variables) = 0;
};

// Terminal Expression
class Number : public Expression {
private:
    int value;

public:
    Number(int value) : value(value) {}

    int interpret(std::unordered_map<std::string, int>& variables) override {
        return value;
    }
};

// Nonterminal Expression
class Variable : public Expression {
private:
    std::string name;

public:
    Variable(const std::string& name) : name(name) {}

    int interpret(std::unordered_map<std::string, int>& variables) override {
        if (variables.find(name) != variables.end()) {
            return variables[name];
        }
        return 0; // Default value if variable not found
    }
};

// Nonterminal Expression
class Add : public Expression {
private:
    Expression* left;
    Expression* right;

public:
    Add(Expression* left, Expression* right) : left(left), right(right) {}

    int interpret(std::unordered_map<std::string, int>& variables) override {
        return left->interpret(variables) + right->interpret(variables);
    }
};

// Client code
int main() {
    std::unordered_map<std::string, int> variables;
    variables["x"] = 10;
    variables["y"] = 5;

    Expression* expression = new Add(new Variable("x"), new Number(15));
    int result = expression->interpret(variables);

    std::cout << "Result: " << result << std::endl;

    delete expression;

    return 0;
}