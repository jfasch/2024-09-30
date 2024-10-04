#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
    String()
    : _s(nullptr)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    String(const char* s)
    : _s(new char[strlen(s)+1])
    {
        cout << __PRETTY_FUNCTION__ << endl;
        strcpy(_s, s);
    }
    ~String()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        delete[] _s;
    }

    String(const String& rhs)
    {
        cout << __PRETTY_FUNCTION__ << endl;
        if (rhs._s == nullptr)
            _s = nullptr;
        else {
            _s = new char[strlen(rhs._s)+1];
            strcpy(_s, rhs._s);
        }
    }

    String(String&& rhs)
    {
        cout << __PRETTY_FUNCTION__ << endl;
        _s = rhs._s;
        rhs._s = nullptr;
    }

    String& operator=(const String& rhs)
    {
        cout << __PRETTY_FUNCTION__ << endl;
        if (this != &rhs) {                            // <-- self assignment check
            delete[] _s;
            _s = nullptr;

            if (rhs._s != nullptr) {
                _s = new char[strlen(rhs._s)+1];
                strcpy(_s, rhs._s);
            }
        }
        return *this;
    }

    String& operator=(String&& rhs)
    {
        cout << __PRETTY_FUNCTION__ << endl;
        if (this != &rhs) {                            // <-- self assignment check
            _s = rhs._s;
            rhs._s = nullptr;
        }
        return *this;
    }

    String& operator+=(const String& s)
    {
        if (_s == nullptr) {
            _s = new char[strlen(s._s) + 1];
            strcpy(_s, s._s);
        }
        else {
            char* newmem = new char[size() + s.size() + 1];
            strcpy(newmem, _s);
            strcpy(newmem+size(), s._s);
            delete[] _s;
            _s = newmem;
        }
        return *this;
    }
    
    const char* c_str() const { return (_s == nullptr)? "\0": _s; }
    size_t size() const { return (_s == nullptr)? 0: strlen(_s); }

private:
    char* _s;
};

String f(const String& eini)
{
    cout << __PRETTY_FUNCTION__ << endl;
    return eini;
}
String f(String&& eini)
{
    cout << __PRETTY_FUNCTION__ << endl;
    return String(std::move(eini));
}

int main()
{
    // String my_eini("eini");
    // auto aussi = f(std::move(my_eini));

    // cout << my_eini.size() << endl;

    // // auto aussi = f("eini");

    // std::cout << aussi.c_str() << " (" << std::hex << (void*)aussi.c_str() << ')' << std::endl;

    String s1("blah");
    String s2;

    s2 = std::move(s1);

    cout << s1.c_str() << endl;
    cout << s2.c_str() << endl;
    
    return 0;
}
