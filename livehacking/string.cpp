#include <iostream>
#include <cstring>

class String
{
public:
    String()
    : _s(new char[1]{})
    {}
    String(const char* s)
    : _s(new char[strlen(s)+1])
    {
        strcpy(_s, s);
    }
    ~String()
    {
        delete[] _s;
    }

    String(const String& rhs)
    : _s(new char[strlen(rhs._s)+1])
    {
        strcpy(_s, rhs._s);
    }
    String& operator=(const String& rhs)
    {
        if (this != &rhs) {                            // <-- self assignment check
            delete[] _s;
            _s = new char[strlen(rhs._s)+1];
            strcpy(_s, rhs._s);
        }
        return *this;
    }
    
    const char* c_str() const { return _s; }
    size_t size() const { return strlen(_s); }

private:
    char* _s;
};

int main()
{
    String s1("hallo");

    s1 = s1;

    std::cout << s1.c_str() << std::endl;
    
    return 0;
}
