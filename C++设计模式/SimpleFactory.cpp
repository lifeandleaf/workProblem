#include <iostream>
#include <string>

enum TYPE {COREA, COREB};

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

// 工厂
class Factory
{
public:
    SingleCore* CreateSingleCore(enum TYPE ctype) {
        if(ctype == COREA) {
            return new SingleCoreA();
        }
        else if(ctype == COREB) {
            return new SingleCoreB();
        }
        else {
            return nullptr;
        }
    }
};

int main(int argc, char const *argv[])
{
    Factory fac;
    SingleCore *p = nullptr;
    std::string ch;
    std::cin >> ch;
    p = fac.CreateSingleCore((ch == "A" ? TYPE::COREA : TYPE::COREB));
    p->show();
    delete p;
    p = nullptr;
    return 0;
}
