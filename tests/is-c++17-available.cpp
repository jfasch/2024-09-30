#include <gtest/gtest.h>

#include <tuple>


TEST(is_cxx17_available, compile_and_pass)
{
    auto my_pair = std::make_tuple(1, "eins");
    auto [num, str] = my_pair;

    ASSERT_EQUAL(num, 1);
    ASSERT_EQUAL(str, "eins");
}
