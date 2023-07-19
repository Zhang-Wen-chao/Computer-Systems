/*
Iterator

Intent
Provide a way to access the elements of an aggregate object sequentially without exposing its underlying representation.

Applicability
Use the Iterator pattern

• to access an aggregate object’s contents without exposing its internal representation.

• to support multiple traversals of aggregate objects.

• to provide a uniform interface for traversing different aggregate structures (that is, to support polymorphic iteration).
*/
#include <iostream>
#include <vector>

// Abstract Iterator
class Iterator {
public:
    virtual int next() = 0;
    virtual bool hasNext() = 0;
    virtual int currentItem() = 0;
};

// Abstract Aggregate
class Aggregate {
public:
    virtual Iterator* getIterator() = 0;
};

// Concrete Iterator
class ConcreteIterator : public Iterator {
private:
    std::vector<int>& collection;
    int currentPosition;

public:
    ConcreteIterator(std::vector<int>& collection) : collection(collection), currentPosition(0) {}

    int next() override {
        return collection[currentPosition++];
    }

    bool hasNext() override {
        return currentPosition < collection.size();
    }

    int currentItem() override {
        return collection[currentPosition];
    }
};

// Concrete Aggregate
class ConcreteAggregate : public Aggregate {
private:
    std::vector<int> collection;

public:
    ConcreteAggregate(const std::vector<int>& collection) : collection(collection) {}

    Iterator* getIterator() override {
        return new ConcreteIterator(collection);
    }
};

// Client code
int main() {
    std::vector<int> collection = {1, 2, 3, 4, 5};
    ConcreteAggregate aggregate(collection);
    Iterator* iterator = aggregate.getIterator();

    while (iterator->hasNext()) {
        int item = iterator->next();
        std::cout << item << " ";
    }
    std::cout << std::endl;

    delete iterator;

    return 0;
}