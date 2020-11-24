#include <iostream>
#include <math.h>

using namespace std;

class Base {
protected:
    double value;

public:
    Base(double v) : value(v) {}

    ~Base() {}

    void callFunc() {
        innerFunc();
    }

    virtual void innerFunc() {
        cout << "from base: " << pow(value, 2) << endl;
    }
};


typedef function<double(double)> funcType;

class Derive : public Base {
private:
    funcType m_func;
public:
    Derive(double v, funcType inFunc) : Base(v) {
        m_func = inFunc;
    }

    void innerFunc() override {
        cout << "from derive: " << m_func(value) << endl;
    }
};


double func(double v) {
    return pow(v, 10);
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    double v = 2.2;

    Base base(v);
    base.callFunc();

    Derive derive(v, func);

    derive.callFunc();

    return 0;
}