#include "palindrome.cpp"
#include <gtest/gtest.h>

TEST(IsPalindromeTest, racecar) {
    ASSERT_EQ(true, isPalindrome("racecar"));
}

TEST(IsPalindromeTest, a) {
    ASSERT_EQ(true, isPalindrome("a"));
}

TEST(IsPalindromeTest, aba) {
    ASSERT_EQ(true, isPalindrome("aba"));
}

TEST(IsPalindromeTest, aaaa) {
    ASSERT_EQ(true, isPalindrome("aaaa"));
}

TEST(IsPalindromeTest, racecaa) {
    ASSERT_EQ(false, isPalindrome("racecaa"));
}

TEST(IsPalindromeTest, adasha) {
    ASSERT_EQ(true, isPalindrome("a-a"));
}

TEST(IsPalindromeTest, newline) {
    ASSERT_EQ(true, isPalindrome("\n   "));
}

TEST(IsPalindromeTest, empty) {
    ASSERT_EQ(true, isPalindrome(""));
}

TEST(IsPalindromeTest, panama) {
    ASSERT_EQ(true, isPalindrome("A man, a plan, a canal: Panama!"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}