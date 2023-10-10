#include <iostream>
#include <vector>

class Order {
public:
   virtual void execute() = 0;
};

class Stock {
private:
   std::string name = "ABC";
   int quantity = 10;

public:
   void buy() {
      std::cout << "Stock [ Name: " << name << ", Quantity: " << quantity << " ] bought" << std::endl;
   }

   void sell() {
      std::cout << "Stock [ Name: " << name << ", Quantity: " << quantity << " ] sold" << std::endl;
   }
};

class BuyStock : public Order {
private:
   Stock* abcStock;

public:
   BuyStock(Stock* abcStock)
      : abcStock(abcStock) {}

   void execute() override {
      abcStock->buy();
   }
};

class SellStock : public Order {
private:
   Stock* abcStock;

public:
   SellStock(Stock* abcStock)
      : abcStock(abcStock) {}

   void execute() override {
      abcStock->sell();
   }
};

class Broker {
private:
   std::vector<Order*> orderList;

public:
   void takeOrder(Order* order) {
      orderList.push_back(order);
   }

   void placeOrders() {
      for (Order* order : orderList) {
         order->execute();
      }
      orderList.clear();
   }
};

int main() {
   Stock* abcStock = new Stock();

   BuyStock* buyStockOrder = new BuyStock(abcStock);
   SellStock* sellStockOrder = new SellStock(abcStock);

   Broker* broker = new Broker();
   broker->takeOrder(buyStockOrder);
   broker->takeOrder(sellStockOrder);

   broker->placeOrders();

   delete broker;
   delete sellStockOrder;
   delete buyStockOrder;
   delete abcStock;

   return 0;
}