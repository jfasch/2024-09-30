#include <iostream>

/*const std::string& ERROR!!!*/ 
std::string create_string(const char* prefix)
{
    std::string ret(prefix);
    ret += ' ';
    ret += "blah";

    return ret;
}

int main()
{
    std::string s = create_string("foo");
    std::cout << s << std::endl;
    return 0;
}
