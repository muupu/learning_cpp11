#include <string>
#include <memory>

class IHello
{
public:
    virtual ~IHello() {}       // 将多态基类的析构函数声明为virtual
    virtual void show() = 0;
                    // 子类只有实现该接口才可进行对象的实例化工作
};

class Hello :public IHello
{
public:
    Hello(const std::string& name):_name(name){
    }

    void show() { 
    	std::cout << "hello " + _name << std::endl;
    }

private:
    std::string _name;
};

class HelloDecorator :public IHello
{
public:
    HelloDecorator(IHello* hello):_hello(hello){

    }

    void show() { 
    	_hello->show();
    }

private:
    IHello* _hello;
    virtual void addDecorator() = 0;
};

class HelloDecoratorA :public HelloDecorator
{
private:
    void addDecorator() { 
    	std::cout << "logging in ..." << std::endl;
    }
public:
    HelloDecoratorA(IHello* hello):HelloDecorator(hello){

    }
    
    void show()
    {
        addDecorator();
        HelloDecorator::show();
    }
};


