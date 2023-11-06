// 406. Queue Reconstruction by Height
// https://leetcode.com/problems/queue-reconstruction-by-height/

#include <algorithm>
#include "../printUtils.hpp"

struct Person {
    int height;
    int count;

    Person(int h, int c) : height(h), count(c) {}
};

bool cmp(Person& p1, Person& p2) {
    if (p1.height == p2.height)
        return p1.count < p2.count;
    return p1.height > p2.height;
}

std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people) {
    std::vector<Person> persons;
    for (const auto& p : people) {
        persons.emplace_back(p[0], p[1]);
    }

    std::sort(persons.begin(), persons.end(), cmp);

    std::vector<std::vector<int>> result;
    for (const auto& p : persons) {
        result.insert(result.begin() + p.count, { p.height, p.count });
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> people = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
    printSet(reconstructQueue(people));

    std::vector<std::vector<int>> people2 = { {6,0},{5,0},{4,0},{3,2},{2,2},{1,4} };
    printSet(reconstructQueue(people2));

    return 0;
}
