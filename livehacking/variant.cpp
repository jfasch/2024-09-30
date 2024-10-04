#include <variant>
#include <memory>
#include <vector>

using my_union = std::variant<std::unique_ptr<int>, bool>;

void f(my_union&& u)
{
    my_union myu = std::move(u);
}

int main()
{
    my_union u(std::make_unique<int>(42));
    f(std::move(u));

    return 0;
}
