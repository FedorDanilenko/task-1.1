#include <gtest/gtest.h>

#include "stack.h"

using namespace my_stack;

TEST(stack, push) {
    StackHead head{1};
    head.Push("1");
    EXPECT_EQ(head.Pop(), "1");
}

TEST(stack, pop) {
    StackHead head{2};
    head.Push("1");
    head.Push("2");
    EXPECT_EQ(head.Pop(), "2");
    EXPECT_EQ(head.Pop(), "1");
}

TEST(stack, capacity_error) {
    try{
        StackHead head{1};
        head.Push("1");
        head.Push("2");
    }
    catch(const std::exception& stack_error) {
        ASSERT_EQ(std::string(stack_error.what()), "Error: push attempt on a full stack");
    }
}

TEST(stack, empty_pop_error) {
    try{
        StackHead head{1};
        head.Push("1");
        head.Pop();
        head.Pop();
    }
    catch(const std::exception& stack_error) {
        ASSERT_EQ(std::string(stack_error.what()), "Error: pop attempt on an empty stack");
    }
}

TEST(stack, front) {
    StackHead head{0};
    EXPECT_EQ(head.Front(), nullptr);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
