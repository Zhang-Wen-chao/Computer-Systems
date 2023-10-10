#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    std::string name;
    int rollNo;

public:
    Student(const std::string& name, int rollNo) : name(name), rollNo(rollNo) {}

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

class StudentDao {
public:
    virtual std::vector<Student> getAllStudents() = 0;
    virtual Student getStudent(int rollNo) = 0;
    virtual void updateStudent(const Student& student) = 0;
    virtual void deleteStudent(const Student& student) = 0;
};

class StudentDaoImpl : public StudentDao {
private:
    std::vector<Student> students;

public:
    StudentDaoImpl() {
        students.emplace_back("Robert", 0);
        students.emplace_back("John", 1);
    }

    void deleteStudent(const Student& student) override {
        students.erase(students.begin() + student.getRollNo());
        std::cout << "Student: Roll No " << student.getRollNo() << ", deleted from database" << std::endl;
    }

    std::vector<Student> getAllStudents() override {
        return students;
    }

    Student getStudent(int rollNo) override {
        return students[rollNo];
    }

    void updateStudent(const Student& student) override {
        students[student.getRollNo()].setName(student.getName());
        std::cout << "Student: Roll No " << student.getRollNo() << ", updated in the database" << std::endl;
    }
};

int main() {
    StudentDaoImpl studentDao;

    // 输出所有的学生
    for (const auto& student : studentDao.getAllStudents()) {
        std::cout << "Student: [RollNo : " << student.getRollNo() << ", Name : " << student.getName() << " ]" << std::endl;
    }

    // 更新学生
    const std::vector<Student>& students = studentDao.getAllStudents();  // 使用常量引用接收返回值
    Student student = students[0];  // 这里改为拷贝一个学生对象
    student.setName("Michael");
    studentDao.updateStudent(student);

    // 获取学生
    student = studentDao.getStudent(0);
    std::cout << "Student: [RollNo : " << student.getRollNo() << ", Name : " << student.getName() << " ]" << std::endl;

    return 0;
}