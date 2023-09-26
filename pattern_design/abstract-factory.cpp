#include <iostream>
#include <pthread.h>
using namespace std;

class Product{
public:
Product(){}
virtual void show()=0; 
};

class Factory{
public:
virtual Product* CreateProduct()=0;
};

class ProductA:public Product{
public:
ProductA(){}
void show(){ std::cout<<"product A create!"<<std::endl; };
};

class ProductB:public Product{
public:
ProductB(){}
void show(){ std::cout<<"product B create!"<<std::endl; };
};

class FactorA: public Factory{
public:
Product* CreateProduct(){
Product* product_ = nullptr;
product_ = new ProductA();
return product_;
}
};

class FactorB: public Factory{
public:
Product* CreateProduct(){
Product* product_ = nullptr;
product_ = new ProductB();
return product_;
}
};

int main(){
    Product* product_ = nullptr;
    auto MyFactoryA = new FactorA();
    product_ = MyFactoryA->CreateProduct();
    product_->show();
    delete product_;
    auto MyFactoryB=new FactorB();
    product_ = MyFactoryB->CreateProduct();
    product_->show();
    delete product_;
    return 0;
}
