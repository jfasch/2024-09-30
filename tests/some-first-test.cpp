#include <gtest/gtest.h>

#include <base/container.h>


TEST(some_first_test, test_that_passes)
{
    Container container{{1, "eins"}};
    ASSERT_EQ(container.n_elements(), 1);
    ASSERT_TRUE(container.has(1));
}

TEST(some_first_test, test_that_fails)
{
    Container container{{1, "eins"}};
    ASSERT_EQ(container.n_elements(), 1);
    ASSERT_TRUE(container.has(2));      // <-- fails
}
