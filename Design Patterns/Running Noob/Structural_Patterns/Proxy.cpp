#include <iostream>

class Image {
public:
   virtual void display() = 0;
};

class RealImage : public Image {
private:
   std::string fileName;

public:
   RealImage(const std::string& fileName)
      : fileName(fileName) {
      loadFromDisk(fileName);
   }

   void display() override {
      std::cout << "Displaying " << fileName << std::endl;
   }

private:
   void loadFromDisk(const std::string& fileName) {
      std::cout << "Loading " << fileName << std::endl;
   }
};

class ProxyImage : public Image {
private:
   RealImage* realImage;
   std::string fileName;

public:
   ProxyImage(const std::string& fileName)
      : realImage(nullptr), fileName(fileName) {}

   void display() override {
      if (realImage == nullptr) {
         realImage = new RealImage(fileName);
      }
      realImage->display();
   }
};

int main() {
   Image* image = new ProxyImage("test_10mb.jpg");

   // 图像将从磁盘加载
   image->display();
   std::cout << std::endl;
   // 图像将无法从磁盘加载
   image->display();
   
   delete image;

   return 0;
}