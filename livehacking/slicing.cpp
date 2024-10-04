#include <iostream>
using namespace std;

class Base
{
public:
    Base(int a) : _a(a) {}
    int a() const { return _a; }

    virtual void meldung() const
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

private:
    int _a;
};

class Derived1 : public Base
{
public:
    Derived1(int a, int b) : Base(a), _b(b) {}
    int b() const { return _b; }

    void meldung() const override
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

private:    
    int _b;
};

class Derived2 : public Base
{
public:
    Derived2(int a, int b) : Base(a), _b(b) {}
    int b() const { return _b; }

    void meldung() const override
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

private:    
    int _b;
};

int main()
{
    Base b(100);
    Derived1 d1(1000, 2000);
    Derived2 d2(10000, 20000);

    b = d1;
    cout << b.a() << endl;

    //d1 = d2;

    Base& bref = d1;
    bref = d2;

    cout << d1.a() << ',' << d1.b() << endl;

    d1.meldung();
    d2.meldung();
    bref.meldung();

    return 0;
}
