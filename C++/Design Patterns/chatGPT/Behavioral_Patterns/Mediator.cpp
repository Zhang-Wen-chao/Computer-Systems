/*
Mediator

Intent
Define an object that encapsulates how a set of objects interact. Mediator promotes loose coupling by keeping objects from referring to each other explicitly, and it lets you vary their interaction independently.


2. The director gets the selection from the list box.

3. The director passes the selection to the entry field.

4. Now that the entry field contains some text, the director enables button(s) for initiating an action (e.g., “demibold,” “oblique”).

Note how the director mediates between the list box and the entry field. Widgets communicate with each other only indirectly, through the director. They don’t have to know about each other; all they know is the director. Furthermore, because the behavior is localized in one class, it can be changed or replaced by extending or replacing that class.

Here’s how the FontDialogDirector abstraction can be integrated into a class library:

image

DialogDirector is an abstract class that defines the overall behavior of a dialog. Clients call the ShowDialog operation to display the dialog on the screen. CreateWidgets is an abstract operation for creating the widgets of a dialog. WidgetChanged is another abstract operation; widgets call it to inform their director that they have changed. DialogDirector subclasses override CreateWidgets to create the proper widgets, and they override WidgetChanged to handle the changes.

Applicability
Use the Mediator pattern when

• a set of objects communicate in well-defined but complex ways. The resulting interdependencies are unstructured and difficult to understand.

• reusing an object is difficult because it refers to and communicates with many other objects.

• a behavior that’s distributed between several classes should be customizable without a lot of subclassing.
*/
#include <iostream>
#include <string>
#include <vector>

class Mediator; // 前向声明 Mediator 类

// Colleague
class Colleague {
protected:
    Mediator* mediator;

public:
    Colleague(Mediator* mediator) : mediator(mediator) {}

    virtual void send(const std::string& message) = 0;
    virtual void receive(const std::string& message) = 0;
};

// Concrete Colleague
class User : public Colleague {
private:
    std::string name;

public:
    User(const std::string& name, Mediator* mediator);

    void send(const std::string& message) override;
    void receive(const std::string& message) override;
};

// Mediator
class Mediator {
public:
    virtual void sendMessage(const std::string& message, Colleague* colleague) = 0;
    virtual void addUser(Colleague* colleague) = 0;
};

// Concrete Mediator
class ChatRoom : public Mediator {
private:
    std::vector<Colleague*> colleagues;

public:
    void sendMessage(const std::string& message, Colleague* colleague) override {
        for (auto c : colleagues) {
            if (c != colleague) {
                c->receive(message);
            }
        }
    }

    void addUser(Colleague* colleague) override {
        colleagues.push_back(colleague);
    }
};

User::User(const std::string& name, Mediator* mediator) : Colleague(mediator), name(name) {}

void User::send(const std::string& message) {
    std::cout << name << " sends message: " << message << std::endl;
    mediator->sendMessage(message, this);
}

void User::receive(const std::string& message) {
    std::cout << name << " receives message: " << message << std::endl;
}

int main() {
    Mediator* chatRoom = new ChatRoom();

    User* user1 = new User("User 1", chatRoom);
    User* user2 = new User("User 2", chatRoom);
    User* user3 = new User("User 3", chatRoom);

    chatRoom->addUser(user1);
    chatRoom->addUser(user2);
    chatRoom->addUser(user3);

    user1->send("Hello from User 1");
    user2->send("Hi, User 1!");

    delete user1;
    delete user2;
    delete user3;
    delete chatRoom;

    return 0;
}