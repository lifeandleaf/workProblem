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

// 静态变量instance初始化不要放在头文件中, 如果多个文件包含singleton.h会出现重复定义问题
Singleton* Singleton::instance_ = nullptr;

int main(int argc, char const *argv[])
{
    Singleton *s1 = Singleton::GetInstance();
    Singleton *s2 = Singleton::GetInstance();

    std::cout << "s1地址:" << s1 << std::endl;
    std::cout << "s2地址:" << s2 << std::endl;
    return 0;
}
