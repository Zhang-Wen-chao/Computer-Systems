#include <iostream>
#include <vector>

class Packing;

class Item {
public:
    virtual std::string name() = 0;
    virtual Packing* packing() = 0;
    virtual float price() = 0;
};

class Packing {
public:
    virtual std::string pack() = 0;
};

class Wrapper : public Packing {
public:
    std::string pack() override {
        return "Wrapper";
    }
};

class Bottle : public Packing {
public:
    std::string pack() override {
        return "Bottle";
    }
};

class Burger : public Item {
public:
    Packing* packing() override {
        return new Wrapper();
    }

    virtual float price() = 0;
};

class ColdDrink : public Item {
public:
    Packing* packing() override {
        return new Bottle();
    }

    virtual float price() = 0;
};

class VegBurger : public Burger {
public:
    float price() override {
        return 25.0f;
    }

    std::string name() override {
        return "Veg Burger";
    }

    Packing* packing() override {
        return new Wrapper();
    }
};

class ChickenBurger : public Burger {
public:
    float price() override {
        return 50.5f;
    }

    std::string name() override {
        return "Chicken Burger";
    }

    Packing* packing() override {
        return new Wrapper();
    }
};

class Coke : public ColdDrink {
public:
    float price() override {
        return 30.0f;
    }

    std::string name() override {
        return "Coke";
    }

    Packing* packing() override {
        return new Bottle();
    }
};

class Pepsi : public ColdDrink {
public:
    float price() override {
        return 35.0f;
    }

    std::string name() override {
        return "Pepsi";
    }

    Packing* packing() override {
        return new Bottle();
    }
};

class Meal {
private:
    std::vector<Item*> items;

public:
    void addItem(Item* item) {
        items.push_back(item);
    }

    float getCost() {
        float cost = 0.0f;
        for (Item* item : items) {
            cost += item->price();
        }
        return cost;
    }

    void showItems() {
        for (Item* item : items) {
            std::cout << "Item: " << item->name();
            std::cout << ", Packing: " << item->packing()->pack();
            std::cout << ", Price: " << item->price() << std::endl;
        }
    }
};

class MealBuilder {
public:
    Meal* prepareVegMeal() {
        Meal* meal = new Meal();
        meal->addItem(new VegBurger());
        meal->addItem(new Coke());
        return meal;
    }

    Meal* prepareNonVegMeal() {
        Meal* meal = new Meal();
        meal->addItem(new ChickenBurger());
        meal->addItem(new Pepsi());
        return meal;
    }
};

int main() {
    MealBuilder mealBuilder;

    Meal* vegMeal = mealBuilder.prepareVegMeal();
    std::cout << "Veg Meal" << std::endl;
    vegMeal->showItems();
    std::cout << "Total Cost: " << vegMeal->getCost() << std::endl;

    Meal* nonVegMeal = mealBuilder.prepareNonVegMeal();
    std::cout << std::endl << "Non-Veg Meal" << std::endl;
    nonVegMeal->showItems();
    std::cout << "Total Cost: " << nonVegMeal->getCost() << std::endl;

    return 0;
}