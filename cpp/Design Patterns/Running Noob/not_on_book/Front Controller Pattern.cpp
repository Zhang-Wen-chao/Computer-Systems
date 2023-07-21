#include <iostream>
#include <string>

class HomeView {
public:
    void show() {
        std::cout << "Displaying Home Page" << std::endl;
    }
};

class StudentView {
public:
    void show() {
        std::cout << "Displaying Student Page" << std::endl;
    }
};

class Dispatcher {
private:
    StudentView studentView;
    HomeView homeView;

public:
    Dispatcher() {
        studentView = StudentView();
        homeView = HomeView();
    }

    void dispatch(const std::string& request) {
        if (request == "STUDENT") {
            studentView.show();
        } else {
            homeView.show();
        }
    }
};

class FrontController {
private:
    Dispatcher dispatcher;

    bool isAuthenticUser() {
        std::cout << "User is authenticated successfully." << std::endl;
        return true;
    }

    void trackRequest(const std::string& request) {
        std::cout << "Page requested: " << request << std::endl;
    }

public:
    FrontController() {
        dispatcher = Dispatcher();
    }

    void dispatchRequest(const std::string& request) {
        // 记录每一个请求
        trackRequest(request);
        // 对用户进行身份验证
        if (isAuthenticUser()) {
            dispatcher.dispatch(request);
        }
    }
};

int main() {
    FrontController frontController;
    frontController.dispatchRequest("HOME");
    frontController.dispatchRequest("STUDENT");

    return 0;
}