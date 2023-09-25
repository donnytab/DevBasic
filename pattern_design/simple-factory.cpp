#include <iostream>
#include <string>
using namespace std;

class Product {
  public:
    Product() {}
    virtual void show()=0
};

class ProductA : public Product {
  public:
    ProductA() {}
    ~ProductA(){}
    void show() { cout << "product A" << endl; }
};

class simpleFactory {
  public:
    simpleFactory(){}
    Product* create(const string str) {
        if (str == "productA") {
            return new ProductA();
        }
        return nullptr;
    }
};

int main() {
    simpleFactory factory;
    Product* p = factory.create("ProductA");
    p->show();
    delete p;
    p = nullptr;
    return 0;
}
