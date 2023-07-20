#include <iostream>
#include <string>

class Iterator {
public:
   virtual bool hasNext() = 0;
   virtual std::string next() = 0;
};

class Container {
public:
   virtual Iterator* getIterator() = 0;
};

class NameRepository : public Container {
public:
   std::string names[4] = { "Robert", "John", "Julie", "Lora" };

   Iterator* getIterator() override {
      return new NameIterator(this);
   }

private:
   class NameIterator : public Iterator {
   private:
      NameRepository* nameRepo;
      int index;

   public:
      NameIterator(NameRepository* nameRepo)
         : nameRepo(nameRepo), index(0) {}

      bool hasNext() override {
         if (index < sizeof(nameRepo->names) / sizeof(nameRepo->names[0])) {
            return true;
         }
         return false;
      }

      std::string next() override {
         if (this->hasNext()) {
            return nameRepo->names[index++];
         }
         return "";
      }
   };
};

int main() {
   NameRepository* namesRepository = new NameRepository();

   for (Iterator* iter = namesRepository->getIterator(); iter->hasNext();) {
      std::string name = iter->next();
      std::cout << "Name: " << name << std::endl;
   }

   delete namesRepository;

   return 0;
}