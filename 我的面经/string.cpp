#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char * data_;
public:
    String(const char* tmp = nullptr);
    String(const String& other);
    ~String();
    String& operator=(const String& other);
};
// 普通构造函数
String::String(const char* tmp) {
    if(tmp == nullptr) {
        this->data_ = new char[1];
        this->data_[0] = '\0';
    }
    else {
        int length = strlen(tmp);
        this->data_ = new char[length + 1];
        strcpy(this->data_, tmp);
    }
}
// 拷贝构造函数（深拷贝）
String::String(const String& other) {
    int length = strlen(other.data_);
    this->data_ = new char[length + 1];
    strcpy(this->data_, other.data_);
}
// 析构函数
String::~String() {
    delete [] this->data_;
}
// 赋值函数（注意判断自赋值）
String& String::operator=(const String& other) {
    if(this == &other) {
        return *this;
    }
    int length = strlen(other.data_);
    if(this->data_) delete [] this->data_;
    this->data_ = new char[length + 1];
    strcpy(this->data_, other.data_);
    return *this;
}