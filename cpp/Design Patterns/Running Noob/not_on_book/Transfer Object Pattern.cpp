#include <iostream>
#include <vector>

class StudentVO {
private:
    std::string name;
    int rollNo;

public:
    StudentVO(const std::string& name, int rollNo) : name(name), rollNo(rollNo) {}

    std::string getName() const {
        return name;
    }

    void setName(const std::string& name) {
        this->name = name;
    }

    int getRollNo() const {
        return rollNo;
    }

    void setRollNo(int rollNo) {
        this->rollNo = rollNo;
    }
};

class StudentBO {
private:
    std::vector<StudentVO> students;

public:
    StudentBO() {
        StudentVO student1("Robert", 0);
        StudentVO student2("John", 1);
        students.push_back(student1);
        students.push_back(student2);
    }

    void deleteStudent(const StudentVO& student) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getRollNo() == student.getRollNo()) {
                students.erase(it);
                break;
            }
        }
        std::cout << "Student: Roll No " << student.getRollNo() << ", deleted from database" << std::endl;
    }

    std::vector<StudentVO> getAllStudents() const {
        return students;
    }

    StudentVO getStudent(int rollNo) const {
        return students[rollNo];
    }

    void updateStudent(const StudentVO& student) {
        students[student.getRollNo()].setName(student.getName());
        std::cout << "Student: Roll No " << student.getRollNo() << ", updated in the database" << std::endl;
    }
};

int main() {
    StudentBO studentBusinessObject;

    // 输出所有的学生
    for (const auto& student : studentBusinessObject.getAllStudents()) {
        std::cout << "Student: [RollNo : " << student.getRollNo() << ", Name : " << student.getName() << " ]" << std::endl;
    }

    // 更新学生
    StudentVO student = studentBusinessObject.getStudent(0);
    student.setName("Michael");
    studentBusinessObject.updateStudent(student);

    // 获取学生
    student = studentBusinessObject.getStudent(0);
    std::cout << "Student: [RollNo : " << student.getRollNo() << ", Name : " << student.getName() << " ]" << std::endl;

    return 0;
}