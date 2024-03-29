#include <iostream>
#include <vector>
#include <stack>
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

struct node
{
    int val;
    node * next;
    node() : val(-1), next(nullptr) {}
};

node * getMid(node * head) {
    node *p = head;
    node *q = head;
    while(q) {
        p = p->next;
        q = q->next;
        if(q) {
            q = q->next;
        }
    }
    return p;
}

int main()
{
    vector<int> tree = {0, 1, 2, 3, 4, 5};
    stack<int> box;
    int id = 1;
    while(id < tree.size() || !box.empty()) {
        while(id < tree.size() && tree[id] != -1) {
            box.push(id);
            id = id * 2;
        }
        cout << tree[box.top()] << endl;
        id = box.top();
        box.pop();
        id = id * 2 + 1;
    }
    while(!box.empty()) {
        cout << tree[box.top()] << endl;
        box.pop();
    }
    return 0;
}