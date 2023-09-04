#include <iostream>
#include <string>

class SingleCore 
{
public:
    virtual void show() = 0;
};

class SingleCoreA : public SingleCore
{
public:
    void show() {
        std::cout << "SingleCore A" << std::endl;
    }
};

class SingleCoreB : public SingleCore
{
public:
    void show() {
        std::cout << "SingleCore B" << std::endl;
    }
};

class Factory
{
public:
    virtual SingleCore* CreateSingleCore() = 0;
};

class FactoryA : public Factory
{
public:
    SingleCore* CreateSingleCore() {
        return new SingleCoreA();
    }
};

class FactoryB : public Factory
{
public:
    SingleCore* CreateSingleCore() {
        return new SingleCoreB();
    }
};

int main(int argc, char const *argv[])
{
    Factory *f = nullptr;
    SingleCore *obj = nullptr;
    std::string ch;
    std::cin >> ch;
    if(ch == "A") {
        f = new FactoryA();
        obj = f->CreateSingleCore();
    }
    else {
        f = new FactoryB();
        obj = f->CreateSingleCore();
    }
    obj->show();
    delete obj;
    obj = nullptr;
    return 0;
}

