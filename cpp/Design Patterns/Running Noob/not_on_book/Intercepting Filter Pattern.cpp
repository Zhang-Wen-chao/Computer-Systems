#include <iostream>
#include <vector>

class Filter {
public:
    virtual void execute(const std::string& request) = 0;
};

class AuthenticationFilter : public Filter {
public:
    void execute(const std::string& request) override {
        std::cout << "Authenticating request: " << request << std::endl;
    }
};

class DebugFilter : public Filter {
public:
    void execute(const std::string& request) override {
        std::cout << "request log: " << request << std::endl;
    }
};

class Target {
public:
    void execute(const std::string& request) {
        std::cout << "Executing request: " << request << std::endl;
    }
};

class FilterChain {
private:
    std::vector<Filter*> filters;
    Target* target;

public:
    void addFilter(Filter* filter) {
        filters.push_back(filter);
    }
 
    void execute(const std::string& request) {
        for (Filter* filter : filters) {
            filter->execute(request);
        }
        target->execute(request);
    }
 
    void setTarget(Target* target) {
        this->target = target;
    }
};

class FilterManager {
private:
    FilterChain filterChain;

public:
    FilterManager() = default;  // 默认构造函数

    explicit FilterManager(Target* target) {
        filterChain = FilterChain();
        filterChain.setTarget(target);
    }

    void setFilter(Filter* filter) {
        filterChain.addFilter(filter);
    }

    void filterRequest(const std::string& request) {
        filterChain.execute(request);
    }
};

class Client {
private:
    FilterManager filterManager;

public:
    Client() = default;  // 默认构造函数

    explicit Client(FilterManager* filterManager) : filterManager(*filterManager) {}

    void sendRequest(const std::string& request) {
        filterManager.filterRequest(request);
    }
};

int main() {
    Target target;

    FilterManager filterManager(&target);
    filterManager.setFilter(new AuthenticationFilter());
    filterManager.setFilter(new DebugFilter());

    Client client(&filterManager);
    client.sendRequest("HOME");

    return 0;
}