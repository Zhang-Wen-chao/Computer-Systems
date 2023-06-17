#include "stuinfo.hpp"
#include <iostream>

void inputstu(stuinfo stu[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "Enter name of student " << i + 1 << ": ";
        std::cin.getline(stu[i].name, 20);

        double sum = 0.0;
        for (int j = 0; j < 3; j++) {
            std::cout << "Enter score " << j + 1 << " for student " << i + 1 << ": ";
            std::cin >> stu[i].score[j];
            sum += stu[i].score[j];
        }
        std::cin.ignore(); // Ignore the newline character

        stu[i].ave = sum / 3.0;
    }
}

void showstu(stuinfo stu[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "Student " << i + 1 << ":\n";
        std::cout << "Name: " << stu[i].name << std::endl;
        std::cout << "Scores: ";
        for (int j = 0; j < 3; j++) {
            std::cout << stu[i].score[j] << " ";
        }
        std::cout << std::endl;
        std::cout << "Average: " << stu[i].ave << std::endl;
    }
}
