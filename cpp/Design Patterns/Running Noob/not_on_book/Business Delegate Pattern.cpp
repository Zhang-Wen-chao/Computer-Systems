#include <iostream>
#include <string>

class BusinessService {
public:
    virtual void doProcessing() = 0;
};

class EJBService : public BusinessService {
public:
    void doProcessing() override {
        std::cout << "Processing task by invoking EJB Service" << std::endl;
    }
};

class JMSService : public BusinessService {
public:
    void doProcessing() override {
        std::cout << "Processing task by invoking JMS Service" << std::endl;
    }
};

class BusinessLookUp {
public:
    BusinessService* getBusinessService(const std::string& serviceType) {
        if (serviceType == "EJB") {
            return new EJBService();
        }
        else {
            return new JMSService();
        }
    }
};

class BusinessDelegate {
private:
    BusinessLookUp lookupService;
    BusinessService* businessService;
    std::string serviceType;

public:
    void setServiceType(const std::string& serviceType) {
        this->serviceType = serviceType;
    }

    void doTask() {
        businessService = lookupService.getBusinessService(serviceType);
        businessService->doProcessing();
        delete businessService;
    }
};

class Client {
private:
    BusinessDelegate& businessService;

public:
    Client(BusinessDelegate& businessService) : businessService(businessService) {}

    void doTask() {
        businessService.doTask();
    }
};

int main() {
    BusinessDelegate businessDelegate;
    businessDelegate.setServiceType("EJB");

    Client client(businessDelegate);
    client.doTask();

    businessDelegate.setServiceType("JMS");
    client.doTask();

    return 0;
}