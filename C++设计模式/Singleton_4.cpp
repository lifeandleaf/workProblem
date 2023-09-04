#include <iostream>
#include <string>

class Singleton
{
public:
    static Singleton& GetInstance() {
        static Singleton instance;
        return instance;
    }
    // 禁止拷贝构造
    Singleton(const Singleton&) = delete;
    // 禁止使用赋值操作隐式表达的构造函数
    Singleton& operator=(const Singleton&) = delete;
private:
    Singleton() {}
};

int main(int argc, char const *argv[])
{
    Singleton *s1 = &Singleton::GetInstance();
    Singleton *s2 = &Singleton::GetInstance();

    std::cout << "s1地址:" << s1 << std::endl;
    std::cout << "s2地址:" << s2 << std::endl;
    return 0;
}
