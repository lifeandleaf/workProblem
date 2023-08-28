#include <iostream>
using namespace std;


class NoStackObject
{
protected:
    NoStackObject() {}
    ~NoStackObject() {}
public:
    static NoStackObject* createObject() {
        cout << "Construct an object in heap." << endl;
        return new NoStackObject();
    }

    void destory() {
        cout << "Destory an object in heap." << endl;
        delete this;
    }

};

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
    // NoStackObject * ptr = NoStackObject::createObject();
    // ptr->destory();
    // ptr = NULL;

    NoHeapObject a;
    // NoHeapObject * p = new NoHeapObject();
    return 0;
}