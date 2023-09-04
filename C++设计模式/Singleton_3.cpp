#include <iostream>
#include <string>

class Singleton
{
public:
    static Singleton* GetInstance() {
        if(instance_ == nullptr) {
            instance_ = new Singleton();
        }
        return instance_;
    }
private:
    Singleton() {}
    static Singleton* instance_;
};

Singleton* Singleton::instance_ = new Singleton();

int main(int argc, char const *argv[])
{
    Singleton *s1 = Singleton::GetInstance();
    Singleton *s2 = Singleton::GetInstance();

    std::cout << "s1地址:" << s1 << std::endl;
    std::cout << "s2地址:" << s2 << std::endl;
    return 0;
}
