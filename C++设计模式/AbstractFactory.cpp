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

class MultiCore
{
public:
    virtual void show() = 0;
};

class MultiCoreA : public MultiCore
{
public:
    void show() {
        std::cout << "Multi Core A" << std::endl;
    }
};

class MultiCoreB : public MultiCore
{
public:
    void show() {
        std::cout << "Multi Core B" << std::endl;
    }
};

class Factory
{
public:
    virtual SingleCore* CreateSingleCore() = 0;
    virtual MultiCore* CreateMultiCore() = 0;
};

class FactoryA : public Factory
{
public:
    SingleCore* CreateSingleCore() {
        return new SingleCoreA();
    }

    MultiCore* CreateMultiCore() {
        return new MultiCoreA();
    }
};

class FactoryB : public Factory
{
public:
    SingleCore* CreateSingleCore() {
        return new SingleCoreB();
    }

    MultiCore* CreateMultiCore() {
        return new MultiCoreB();
    }
};

int main(int argc, char const *argv[])
{
    Factory *f = nullptr;
    SingleCore* sc = nullptr;
    MultiCore* mc = nullptr;
    std::string c2;
    std::cin >> c2;
    if(c2 == "A") {
        f = new FactoryA();
    }
    else f = new FactoryB();
    sc = f->CreateSingleCore();
    mc = f->CreateMultiCore();
    sc->show();
    mc->show();
    return 0;
}
