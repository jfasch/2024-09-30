#include <string>

class CharArrayHolder
{
public:
    /*explicit!!!*/ CharArrayHolder(char* mem) // <-- "explicit" is necessary to uncover bugs
    {
        _mem = mem;
    }
    ~CharArrayHolder()
    {
        delete[] _mem;
    }

    const char* mem() const { return _mem; }

private:
    char* _mem;
};

void do_something_with(const CharArrayHolder& h, unsigned int ntimes)
{
    while (ntimes--)
        if (true) {
            const void* my_mem = h.mem();
            // do something with mem
            (void)my_mem;                              // <-- not actually doing anything
        }
}

int main()
{
    char* mem = new char[10];
    CharArrayHolder r(mem);

    do_something_with(r, 10);
    do_something_with(mem/*!*/, 10);  // <-- BUG: temporary CharArrayHolder object
                                      // <-- leading to double-free

    return 0;
}
