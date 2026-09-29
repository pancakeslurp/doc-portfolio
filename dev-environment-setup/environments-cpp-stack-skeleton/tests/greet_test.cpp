#include <gtest/gtest.h>
#include "greet.hpp"

TEST(Greet, SaysHello) {
    EXPECT_EQ(greet("Dave"), "Hello, Dave!");
}
