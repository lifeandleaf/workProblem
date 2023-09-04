#include <iostream>
#include <string>
#include <list>

class Observer
{
public:
    Observer() {}
    virtual ~Observer() {}
    virtual void Update() {}
};

class Blog
{
public:
    Blog() {}
    virtual ~Blog() {}
    void Attach(Observer *observer) {
        m_observer.push_back(observer);
    }
    void Remove(Observer *observer) {
        m_observer.remove(observer);
    }
    void Notify() {
        std::list<Observer*>::iterator it = m_observer.begin();
        for(; it != m_observer.end(); ++it) {
            (*it)->Update();
        }
    }
    virtual void SetStatus(std::string s) {
        m_status = s;
    }
    virtual std::string GetStatus() {
        return m_status;
    }
private:
    std::list<Observer*> m_observer;
protected:
    std::string m_status;
};

class BlogCSDN : public Blog
{
private:
    std::string m_name; 
public:
    BlogCSDN(std::string name) : m_name(name) {}
    ~BlogCSDN() {}
    void SetStatus(std::string s) {
        m_status = "CSDN通知 : " + m_name + s;
    }
    std::string GetStatus() {
        return m_status;
    }
};

class ObserverBlog : public Observer
{
private:
    std::string m_name;
    Blog *m_blog;
public:
    ObserverBlog(std::string name, Blog *blog) : m_name(name), m_blog(blog) {}
    ~ObserverBlog() {}
    void Update() {
        std::string status = m_blog->GetStatus();
        std::cout << m_name << "--------" << status << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Blog *blog = new BlogCSDN("wtt");
    Observer *observer1 = new ObserverBlog("tutupig", blog);
    blog->Attach(observer1);
    blog->SetStatus("发表设计模式C++实现");
    blog->Notify();
    delete blog;
    delete observer1;
    return 0;
}
