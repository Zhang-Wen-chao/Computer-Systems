#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Person {
private:
    std::string name;
    std::string gender;
    std::string maritalStatus;

public:
    Person(const std::string& name, const std::string& gender, const std::string& maritalStatus)
        : name(name), gender(gender), maritalStatus(maritalStatus) {}

    std::string getName() const {
        return name;
    }
    std::string getGender() const {
        return gender;
    }
    std::string getMaritalStatus() const {
        return maritalStatus;
    }

    bool operator==(const Person& other) const {
        return this->name == other.name && this->gender == other.gender && this->maritalStatus == other.maritalStatus;
    }
};

class Criteria {
public:
    virtual std::vector<Person> meetCriteria(const std::vector<Person>& persons) = 0;
};

class CriteriaMale : public Criteria {
public:
    std::vector<Person> meetCriteria(const std::vector<Person>& persons) override {
        std::vector<Person> malePersons;
        for (const auto& person : persons) {
            if (person.getGender() == "Male") {
                malePersons.push_back(person);
            }
        }
        return malePersons;
    }
};

class CriteriaFemale : public Criteria {
public:
    std::vector<Person> meetCriteria(const std::vector<Person>& persons) override {
        std::vector<Person> femalePersons;
        for (const auto& person : persons) {
            if (person.getGender() == "Female") {
                femalePersons.push_back(person);
            }
        }
        return femalePersons;
    }
};

class CriteriaSingle : public Criteria {
public:
    std::vector<Person> meetCriteria(const std::vector<Person>& persons) override {
        std::vector<Person> singlePersons;
        for (const auto& person : persons) {
            if (person.getMaritalStatus() == "Single") {
                singlePersons.push_back(person);
            }
        }
        return singlePersons;
    }
};

class AndCriteria : public Criteria {
private:
    Criteria* criteria;
    Criteria* otherCriteria;

public:
    AndCriteria(Criteria* criteria, Criteria* otherCriteria)
        : criteria(criteria), otherCriteria(otherCriteria) {}

    std::vector<Person> meetCriteria(const std::vector<Person>& persons) override {
        std::vector<Person> firstCriteriaPersons = criteria->meetCriteria(persons);
        return otherCriteria->meetCriteria(firstCriteriaPersons);
    }
};

class OrCriteria : public Criteria {
private:
    Criteria* criteria;
    Criteria* otherCriteria;

public:
    OrCriteria(Criteria* criteria, Criteria* otherCriteria)
        : criteria(criteria), otherCriteria(otherCriteria) {}

    std::vector<Person> meetCriteria(const std::vector<Person>& persons) override {
        std::vector<Person> firstCriteriaItems = criteria->meetCriteria(persons);
        std::vector<Person> otherCriteriaItems = otherCriteria->meetCriteria(persons);

        for (const auto& person : otherCriteriaItems) {
            if (std::find_if(firstCriteriaItems.begin(), firstCriteriaItems.end(), [&](const Person& p) {
                    return p.getName() == person.getName() && p.getGender() == person.getGender() && p.getMaritalStatus() == person.getMaritalStatus();
                }) == firstCriteriaItems.end()) {
                firstCriteriaItems.push_back(person);
            }
        }
        return firstCriteriaItems;
    }
};

void printPersons(const std::vector<Person>& persons) {
    for (const auto& person : persons) {
        std::cout << "Person : [ Name : " << person.getName()
            << ", Gender : " << person.getGender()
            << ", Marital Status : " << person.getMaritalStatus()
            << " ]" << std::endl;
    }
}

int main() {
    std::vector<Person> persons;

    persons.push_back(Person("Robert", "Male", "Single"));
    persons.push_back(Person("John", "Male", "Married"));
    persons.push_back(Person("Laura", "Female", "Married"));
    persons.push_back(Person("Diana", "Female", "Single"));
    persons.push_back(Person("Mike", "Male", "Single"));
    persons.push_back(Person("Bobby", "Male", "Single"));

    CriteriaMale male;
    CriteriaFemale female;
    CriteriaSingle single;
    AndCriteria singleMale(&single, &male);
    OrCriteria singleOrFemale(&single, &female);

    std::cout << "Males: " << std::endl;
    printPersons(male.meetCriteria(persons));

    std::cout << "\nFemales: " << std::endl;
    printPersons(female.meetCriteria(persons));

    std::cout << "\nSingle Males: " << std::endl;
    printPersons(singleMale.meetCriteria(persons));

    std::cout << "\nSingle Or Females: " << std::endl;
    printPersons(singleOrFemale.meetCriteria(persons));

    return 0;
}