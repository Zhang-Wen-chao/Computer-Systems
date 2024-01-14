/*
Composite

Intent
Compose objects into tree structures to represent part-whole hierarchies. Composite lets clients treat individual objects and compositions of objects uniformly.

Applicability
Use the Composite pattern when

• you want to represent part-whole hierarchies of objects.

• you want clients to be able to ignore the difference between compositions of objects and individual objects. Clients will treat all objects in the composite structure uniformly.
*/
#include <iostream>
#include <vector>

// 抽象组件类
class Component {
public:
    virtual void operation() const = 0;
};

// 叶子组件类
class Leaf : public Component {
public:
    Leaf(const std::string& name) : m_name(name) {}
    
    void operation() const {
        std::cout << "Leaf " << m_name << " operation" << std::endl;
    }

private:
    std::string m_name;
};

// 容器组件类
class Composite : public Component {
public:
    void add(Component* component) {
        m_components.push_back(component);
    }
    
    void remove(Component* component) {
        for (auto it = m_components.begin(); it != m_components.end(); ++it) {
            if (*it == component) {
                m_components.erase(it);
                break;
            }
        }
    }
    
    void operation() const {
        for (auto component : m_components) {
            component->operation();
        }
    }

private:
    std::vector<Component*> m_components;
};

// 客户端代码
int main() {
    Component* leafA = new Leaf("A");
    Component* leafB = new Leaf("B");
    
    Component* composite = new Composite();
    static_cast<Composite*>(composite)->add(leafA);
    static_cast<Composite*>(composite)->add(leafB);
    
    composite->operation();
    
    delete leafA;
    delete leafB;
    delete composite;
    
    return 0;
}