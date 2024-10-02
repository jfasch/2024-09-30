#include <vector>
#include <iostream>

int main()
{
    const std::vector<int> meine_integers{3, 4};
    // const std::vector<int> meine_integers(3, 4);
    // const std::vector<int> meine_integers({3, 4});

    for (int i: meine_integers)
        std::cout << i << '\n';
    
    return 0;
}
