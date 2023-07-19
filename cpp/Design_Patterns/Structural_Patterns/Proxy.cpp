/*
Proxy

Intent
Provide a surrogate or placeholder for another object to control access to it.

Applicability
Proxy is applicable whenever there is a need for a more versatile or sophisticated reference to an object than a simple pointer. Here are several common situations in which the Proxy pattern is applicable:

1. A remote proxy provides a local representative for an object in a different address space. NEXTSTEP [Add94] uses the class NXProxy for this purpose. Coplien [Cop92] calls this kind of proxy an “Ambassador.”

2. A virtual proxy creates expensive objects on demand. The ImageProxy described in the Motivation is an example of such a proxy.

3. A protection proxy controls access to the original object. Protection proxies are useful when objects should have different access rights. For example, KernelProxies in the Choices operating system [CIRM93] provide protected access to operating system objects.

4. A smart reference is a replacement for a bare pointer that performs additional actions when an object is accessed. Typical uses include

• counting the number of references to the real object so that it can be freed automatically when there are no more references (also called smart pointers [Ede92]).

• loading a persistent object into memory when it’s first referenced.

• checking that the real object is locked before it’s accessed to ensure that no other object can change it.
*/
#include <iostream>
#include <string>

// Subject 接口
class Subject {
public:
    virtual ~Subject() {}
    virtual void request() const = 0;
};

// RealSubject 实现 Subject 接口
class RealSubject : public Subject {
public:
    void request() const override {
        std::cout << "RealSubject: Handling request." << std::endl;
    }
};

// Proxy 实现 Subject 接口，并在内部维护一个 RealSubject 对象
class Proxy : public Subject {
public:
    Proxy(Subject* realSubject) : m_realSubject(realSubject) {}

    void request() const override {
        // 在这里可以实现一些额外的逻辑处理
        std::cout << "Proxy: Logging request." << std::endl;

        // 转发请求给 RealSubject 对象
        m_realSubject->request();

        // 在这里可以实现一些额外的逻辑处理
        std::cout << "Proxy: Cleaning up after request." << std::endl;
    }

private:
    Subject* m_realSubject;
};

// 客户端代码
int main() {
    RealSubject realSubject;
    Proxy proxy(&realSubject);

    // 通过 Proxy 对象发送请求
    proxy.request();

    return 0;
}