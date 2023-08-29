/*

智能指针的实现（手撕智能指针）
智能指针能有效防止内存泄漏问题（某片内存被申请使用但是却没有相应的指针指向他，导致这篇内存无法被管理，造成内存泄漏）
实现原理：计数器
通过将指针和计数器绑定，记录指向内存空间的指针数量，在指向内存的指针数量变为0时，将空间释放，以防出现内存泄漏

需要实现的功能：
    构造函数：根据指针或者内存地址创建智能指针对象
    析构函数：
    拷贝构造函数：根据另一个智能指针对象构造智能指针对象
    赋值运算符：将一个智能指针对象赋值给另一个
    取值运算符：获取智能指针维护的指针指向的数据
    间接访问运算符：->
    查看计数器
*/

#include <iostream>
#include <memory>
#include <cassert>
using namespace std;


template<typename T>
class smartPtr
{
private:
    T *_ptr;
    size_t *_count;
public:
    // 构造函数
    smartPtr(T * ptr = nullptr) : _ptr(ptr) {
        if(this->_ptr == nullptr) {
            this->_count = new size_t(0);
        }
        else {
            this->_count = new size_t(1);
        }
    }

    // 析构函数
    // 是否有必要在计数器不为零时，delete
    ~smartPtr() {
        (*this->_count)--;
        if((*this->_count) == 0) {
            delete this->_ptr;
            delete this->_count;
        }
    }

    // 拷贝构造函数
    smartPtr(const smartPtr &ptr) { //拷贝构造，计数器+1
        // 这个判断是否有必要
        if(this != &ptr) {
            this->_ptr = ptr._ptr;
            this->_count = ptr._count;
            (*this->_count)++;
        }
    }

    // 赋值运算符重载
    smartPtr &operator=(const smartPtr &ptr) {
        if(this == &ptr) {
            return *this;
        }
        // 原智能指针存在维护的指针
        if(this->_ptr) {
            (*this->_count)--;
            if((*this->_count) == 0) {
                delete this->_ptr;
                delete this->_count;
            }
        }
        this->_ptr = ptr._ptr;
        this->_count = ptr._count;
        (*this->_count)++;
        return *this;
    }

    // 取值运算符
    T &operator*() const {
        assert(this->_ptr != nullptr);
        return *(this->_ptr);
    }

    // 间接访问运算符
    T *operator->() const {
        assert(this->_ptr != nullptr);
        return this->_ptr;
    }

    // 访问计数器
    size_t use_count() {
        return *this->_count;
    }

};

struct stu
{
    int id, score;
    stu(int i = -1, int s = 0) : id(i), score(s) {}
};

int main()
{
    smartPtr<stu> p(new stu(1, 87));
    cout << p.use_count() << endl;
    cout << p->id << " " << p->score << endl;
    p->id = 2;
    p->score = 100;
    cout << p->id << " " << p->score << endl;
    smartPtr<stu> q(p);
    cout << q.use_count() << endl;
    cout << p.use_count() << endl;
    return 0;
}