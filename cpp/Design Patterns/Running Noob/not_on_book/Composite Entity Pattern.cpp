#include <iostream>
#include <string>

class DependentObject1 {
private:
    std::string data;

public:
    void setData(const std::string& data) {
        this->data = data;
    }

    std::string getData() const {
        return data;
    }
};

class DependentObject2 {
private:
    std::string data;

public:
    void setData(const std::string& data) {
        this->data = data;
    }

    std::string getData() const {
        return data;
    }
};

class CoarseGrainedObject {
private:
    DependentObject1 do1;
    DependentObject2 do2;

public:
    void setData(const std::string& data1, const std::string& data2) {
        do1.setData(data1);
        do2.setData(data2);
    }

    std::string getData1() const {
        return do1.getData();
    }

    std::string getData2() const {
        return do2.getData();
    }
};

class CompositeEntity {
private:
    CoarseGrainedObject cgo;

public:
    void setData(const std::string& data1, const std::string& data2) {
        cgo.setData(data1, data2);
    }

    std::string getData1() const {
        return cgo.getData1();
    }

    std::string getData2() const {
        return cgo.getData2();
    }
};

class Client {
private:
    CompositeEntity compositeEntity;

public:
    void printData() {
        std::cout << "Data: " << compositeEntity.getData1() << std::endl;
        std::cout << "Data: " << compositeEntity.getData2() << std::endl;
    }

    void setData(const std::string& data1, const std::string& data2) {
        compositeEntity.setData(data1, data2);
    }
};

int main() {
    Client client;
    client.setData("Test", "Data");
    client.printData();
    client.setData("Second Test", "Data1");
    client.printData();

    return 0;
}