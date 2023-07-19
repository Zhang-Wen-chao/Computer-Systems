/*
Flyweight

Intent
Use sharing to support large numbers of fine-grained objects efficiently.

Applicability
The Flyweight pattern’s effectiveness depends heavily on how and where it’s used. Apply the Flyweight pattern when all of the following are true:

• An application uses a large number of objects.

• Storage costs are high because of the sheer quantity of objects.

• Most object state can be made extrinsic.

• Many groups of objects may be replaced by relatively few shared objects once extrinsic state is removed.

• The application doesn’t depend on object identity. Since flyweight objects may be shared, identity tests will return true for conceptually distinct objects.
*/
#include <iostream>
#include <string>
#include <unordered_map>

// Flyweight 接口
class Flyweight {
public:
    virtual ~Flyweight() {}
    virtual void operation(const std::string& extrinsicState) const = 0;
};

// 具体的 Flyweight 实现
class ConcreteFlyweight : public Flyweight {
public:
    ConcreteFlyweight(const std::string& intrinsicState) : m_intrinsicState(intrinsicState) {}

    void operation(const std::string& extrinsicState) const override {
        std::cout << "Intrinsic state: " << m_intrinsicState << ", Extrinsic state: " << extrinsicState << std::endl;
    }

private:
    std::string m_intrinsicState;
};

// Flyweight 工厂
class FlyweightFactory {
public:
    Flyweight* getFlyweight(const std::string& key) {
        if (m_flyweights.find(key) == m_flyweights.end()) {
            m_flyweights[key] = new ConcreteFlyweight(key);
        }
        return m_flyweights[key];
    }

    ~FlyweightFactory() {
        for (const auto& it : m_flyweights) {
            delete it.second;
        }
    }

private:
    std::unordered_map<std::string, Flyweight*> m_flyweights;
};

// 客户端代码
int main() {
    FlyweightFactory factory;
    
    Flyweight* flyweight1 = factory.getFlyweight("Flyweight1");
    flyweight1->operation("ExtrinsicState1");

    Flyweight* flyweight2 = factory.getFlyweight("Flyweight2");
    flyweight2->operation("ExtrinsicState2");

    Flyweight* flyweight3 = factory.getFlyweight("Flyweight1");
    flyweight3->operation("ExtrinsicState3");

    return 0;
}