#include <iostream>
#include <unordered_map>

class Service {
public:
    virtual ~Service() {}  // 添加虚析构函数
    virtual std::string getName() = 0;
    virtual void execute() = 0;
};

class Service1 : public Service {
public:
    void execute() override {
        std::cout << "Executing Service1" << std::endl;
    }

    std::string getName() override {
        return "Service1";
    }
};

class Service2 : public Service {
public:
    void execute() override {
        std::cout << "Executing Service2" << std::endl;
    }

    std::string getName() override {
        return "Service2";
    }
};

class InitialContext {
public:
    Service* lookup(const std::string& jndiName) {
        if (jndiName.compare("SERVICE1") == 0) {
            std::cout << "Looking up and creating a new Service1 object" << std::endl;
            return new Service1();
        } else if (jndiName.compare("SERVICE2") == 0) {
            std::cout << "Looking up and creating a new Service2 object" << std::endl;
            return new Service2();
        }
        return nullptr;
    }
};

class Cache {
private:
    std::unordered_map<std::string, Service*> services;

public:
    ~Cache() {  // 添加析构函数，释放内存
        for (auto it = services.begin(); it != services.end(); ++it) {
            delete it->second;
        }
    }

    Service* getService(const std::string& serviceName) {
        auto it = services.find(serviceName);
        if (it != services.end()) {
            std::cout << "Returning cached " << serviceName << " object" << std::endl;
            return it->second;
        }
        return nullptr;
    }

    void addService(const std::string& serviceName, Service* newService) {
        services[serviceName] = newService;
    }
};

class ServiceLocator {
private:
    static Cache* cache;
    static InitialContext* context;

public:
    ~ServiceLocator() { cleanup(); }  // Add destructor to call cleanup()

    static Service* getService(const std::string& jndiName) {
        if (cache == nullptr) {
            cache = new Cache();
        }

        Service* service = cache->getService(jndiName);

        if (service != nullptr) {
            return service;
        }

        if (context == nullptr) {
            context = new InitialContext();
        }

        service = context->lookup(jndiName);
        if (service != nullptr) {
            cache->addService(jndiName, service);
        }

        return service;
    }

    static void cleanup() {
        if (cache != nullptr) {
            delete cache;
            cache = nullptr;
        }
        if (context != nullptr) {
            delete context;
            context = nullptr;
        }
    }
};

Cache* ServiceLocator::cache = nullptr;
InitialContext* ServiceLocator::context = nullptr;

int main() {
    Service* service = ServiceLocator::getService("SERVICE1");
    if (service != nullptr) {
        service->execute();
        delete service;
    }

    service = ServiceLocator::getService("SERVICE2");
    if (service != nullptr) {
        service->execute();
        delete service;
    }

    service = ServiceLocator::getService("SERVICE1");
    if (service != nullptr) {
        service->execute();
        delete service;
    }

    service = ServiceLocator::getService("SERVICE2");
    if (service != nullptr) {
        service->execute();
        delete service;
    }

    // No need to call ServiceLocator::cleanup() explicitly

    return 0;
}