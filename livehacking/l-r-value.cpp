#include <iostream>
#include <string>

using namespace std;

void f(const int& a)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void f(int&& a)
{
    cout << __PRETTY_FUNCTION__ << endl;
    a = 42;
}

string&& g()
{
    string&& ret = string("blah");
    return ret;
}

int main()
{
    int a = 42;
    f(a);                                              // <-- lvalue ref

    f(666);                                            // <-- rvalue ref

    string&& srr = g();
    cout << srr << endl;

    return 0;
}
