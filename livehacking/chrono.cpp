#include <chrono>
#include <thread>

using namespace std::chrono_literals;


int main()
{
    unsigned millis = 500;
    std::this_thread::sleep_for(std::chrono::milliseconds(millis));

    return 0;
}
