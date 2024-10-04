#include <variant>
#include <iostream>
#include <string>

using std::cout;
using std::endl;


int main()
{
    std::variant<int, float, std::string> v{42.666f};

    if (std::holds_alternative<float>(v))
        cout << std::get<float>(v) << endl;
    else if (std::holds_alternative<int>(v))
        cout << std::get<int>(v) << endl;

    if (const int* pi = std::get_if<int>(&v); pi)
        cout << *pi << endl;
    else
        cout << "nix int" << endl;

    struct Visitor
    {
        void operator()(int) const { cout << "int" << endl; }
        void operator()(float) const { cout << "float" << endl; }
        void operator()(std::string) const { cout << "std::string" << endl; }
    };

    Visitor vis;
    std::visit(vis, v);

    return 0;
}
