## C++ Problem

#### C++如何限制只能在堆或栈上产生对象
**设计只能在堆上产生对象：**

将构造函数也设为private或者protected，但需要让该类提供一个static成员函数专门用于产生该类型的堆对象。

```cpp

#include <iostream>
using namespace std;


class NoStackObject
{
protected:
    NoStackObject();
    ~NoStackObject();
public:
    static NoStackObject* createObject() {
        cout << "Construct an object in heap." << endl;
        return new NoStackObject();
    }

    static void destory() {
        cout << "Destory an object in heap." << endl;
        delete this;
    }

};

int main()
{
    NoStackObject * ptr = NoStackObject::createObject();
    ptr->destory();
    ptr = NULL;
    return 0;
}

```

**只能在栈上生成对象：**

将operator new设为私有即可，保证在类外面无法定义，也无法使用。

```cpp
#include <iostream>
using namespace std;

class NoHeapObject
{
private:
    void* operator new(size_t) {}
    void operator delete(void*) {}
public:
    NoHeapObject()
    {
        cout << "NoHeapObject()" << endl;
    }

    ~NoHeapObject()
    {
        cout << "~NoHeapObject()" << endl;
    }
};

int main()
{
    NoHeapObject a;
    // NoHeapObject * p = new NoHeapObject(); ERROR
    return 0;
}

```

