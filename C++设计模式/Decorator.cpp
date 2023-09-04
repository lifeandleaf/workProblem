#include <iostream>
#include <string>

class Phone
{
public:
    Phone() {}
    virtual ~Phone() {}
    virtual void ShowDecorate() {}
};

// 具体手机类
class iPhone : public Phone
{
public:
    iPhone(std::string name) : m_name(name) {}
    ~iPhone() {}
    void ShowDecorate() {
        std::cout << m_name << "的装饰" << std::endl;
    }
private:
    std::string m_name;
};

class NokiaPhone : public Phone
{
public:
    NokiaPhone(std::string name) : m_name(name) {}
    ~NokiaPhone() {}
    void ShowDecorate() {
        std::cout << m_name << "的装饰" << std::endl;
    }
private:
    std::string m_name;
};

// 装饰类
class DecoratorPhone : public Phone
{
public:
    DecoratorPhone(Phone *phone) : m_phone(phone) {}
    virtual void ShowDecorate() {
        m_phone->ShowDecorate();
    }
private:
    Phone *m_phone;
};

class DecoratorPhoneA : public DecoratorPhone
{
public:
    DecoratorPhoneA(Phone *phone) : DecoratorPhone(phone) {}
    void ShowDecorate() {
        DecoratorPhone::ShowDecorate();
        AddDecorate();
    }
private:
    void AddDecorate() {
        std::cout << "增加挂件" << std::endl;
    }
};

class DecoratorPhoneB : public DecoratorPhone
{
public:
    DecoratorPhoneB(Phone *phone) : DecoratorPhone(phone) {}
    void ShowDecorate() {
        DecoratorPhone::ShowDecorate();
        AddDecorate();
    }
private:
    void AddDecorate() {
        std::cout << "屏幕贴膜" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Phone *pphone = new NokiaPhone("6300");
    Phone *dpa = new DecoratorPhoneA(pphone); // 装饰，增加挂件
    Phone *dpb = new DecoratorPhoneB(pphone); // 装饰，屏幕贴膜
    dpb->ShowDecorate();
    delete dpa;
    delete dpb;
    delete pphone;
    return 0;
}
