/*
Command

Intent
Encapsulate a request as an object, thereby letting you parameterize clients with different requests, queue or log requests, and support undoable operations.

Applicability
Use the Command pattern when you want to

• parameterize objects by an action to perform, as Menultem objects did above. You can express such parameterization in a procedural language with a callback function, that is, a function that’s registered somewhere to be called at a later point. Commands are an object-oriented replacement for callbacks.

• specify, queue, and execute requests at different times. A Command object can have a lifetime independent of the original request. If the receiver of a request can be represented in an address space-independent way, then you can transfer a command object for the request to a different process and fulfill the request there.

• support undo. The Command’s Execute operation can store state for reversing its effects in the command itself. The Command interface must have an added Unexecute operation that reverses the effects of a previous call to Execute. Executed commands are stored in a history list. Unlimited-level undo and redo is achieved by traversing this list backwards and forwards calling Unexecute and Execute, respectively.

• support logging changes so that they can be reapplied in case of a system crash. By augmenting the Command interface with load and store operations, you can keep a persistent log of changes. Recovering from a crash involves reloading logged commands from disk and reexecuting them with the Execute operation.

• structure a system around high-level operations built on primitives operations. Such a structure is common in information systems that support transactions. A transaction encapsulates a set of changes to data. The Command pattern offers a way to model transactions. Commands have a common interface, letting you invoke all transactions the same way. The pattern also makes it easy to extend the system with new transactions.
*/
#include <iostream>
#include <vector>

// Command 接口
class Command {
public:
    virtual ~Command() {}
    virtual void execute() const = 0;
};

// Receiver 类
class Receiver {
public:
    void open() const {
        std::cout << "Receiver: Opening file." << std::endl;
    }

    void save() const {
        std::cout << "Receiver: Saving file." << std::endl;
    }

    void close() const {
        std::cout << "Receiver: Closing file." << std::endl;
    }
};

// 具体的 Command 实现
class OpenCommand : public Command {
public:
    OpenCommand(Receiver* receiver) : m_receiver(receiver) {}

    void execute() const override {
        m_receiver->open();
    }

private:
    Receiver* m_receiver;
};

class SaveCommand : public Command {
public:
    SaveCommand(Receiver* receiver) : m_receiver(receiver) {}

    void execute() const override {
        m_receiver->save();
    }

private:
    Receiver* m_receiver;
};

class CloseCommand : public Command {
public:
    CloseCommand(Receiver* receiver) : m_receiver(receiver) {}

    void execute() const override {
        m_receiver->close();
    }

private:
    Receiver* m_receiver;
};

// Invoker 类
class Invoker {
public:
    void setCommand(Command* command) {
        m_command = command;
    }

    void executeCommand() {
        if (m_command) {
            m_command->execute();
        }
    }

private:
    Command* m_command;
};

// 客户端代码
int main() {
    Receiver receiver;
    OpenCommand openCommand(&receiver);
    SaveCommand saveCommand(&receiver);
    CloseCommand closeCommand(&receiver);

    Invoker invoker;

    // 执行打开命令
    invoker.setCommand(&openCommand);
    invoker.executeCommand();

    // 执行保存命令
    invoker.setCommand(&saveCommand);
    invoker.executeCommand();

    // 执行关闭命令
    invoker.setCommand(&closeCommand);
    invoker.executeCommand();

    return 0;
}