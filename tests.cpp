#include "palindrome.cpp"
#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <cctype>
#include <string>

using namespace std;

TEST(IsPalindromeTest, racecar) {
    ASSERT_EQ(true, isPalindrome("racecar"));
}


TEST(IsPalindromeTest, racecap) {
    ASSERT_EQ(false, isPalindrome("racecap"));
}

TEST(IsPalindromeTest, pacecar) {
    ASSERT_EQ(false, isPalindrome("pacecar"));
}

TEST(IsPalindromeTest, empty) {
    ASSERT_EQ(true, isPalindrome(""));
}

TEST(IsPalindromeTest, a) {
    ASSERT_EQ(true, isPalindrome("a"));
}

TEST(IsPalindromeTest, aa) {
    ASSERT_EQ(true, isPalindrome("aa"));
}

TEST(IsPalindromeTest, ab) {
    ASSERT_EQ(false, isPalindrome("ab"));
}

TEST(IsPalindromeTest, aba) {
    ASSERT_EQ(true, isPalindrome("aba"));
}

TEST(IsPalindromeTest, abb) {
    ASSERT_EQ(false, isPalindrome("abb"));
}

TEST(IsPalindromeTest, bba) {
    ASSERT_EQ(false, isPalindrome("bba"));
}

TEST(IsPalindromeTest, abba) {
    ASSERT_EQ(true, isPalindrome("abba"));
}

TEST(IsPalindromeTest, abab) {
    ASSERT_EQ(false, isPalindrome("abab"));
}

TEST(IsPalindromeTest, a_a) {
    ASSERT_EQ(true, isPalindrome("a_a"));
}

TEST(IsPalindromeTest, __a_a_) {
    ASSERT_EQ(true, isPalindrome("__a_a_"));
}

TEST(IsPalindromeTest, _a_a__) {
    ASSERT_EQ(true, isPalindrome("_a_a__"));
}

TEST(IsPalindromeTest, _a_b__) {
    ASSERT_EQ(false, isPalindrome("_a_b__"));
}

TEST(IsPalindromeTest, newline) {
    ASSERT_EQ(true, isPalindrome("\n   "));
}

TEST(IsPalindromeTest, panama) {
    ASSERT_EQ(true, isPalindrome("A man, a plan, a canal: Panama!"));
}

static bool isPalindromeOracle(string s) {
    string sfilter = "";
    for (char const &c: s)
        if (isalpha(c))
            sfilter += c;
    string srev(sfilter);
    reverse(srev.begin(), srev.end());
    return sfilter == srev;
}

static void genTest(unsigned n, string s) {
    ASSERT_EQ(isPalindrome(s), isPalindromeOracle(s));
    if (s.length() == n)
        return;
    char chars[] = {'a', 'b', '-', '\0'};
    for (int i = 0; chars[i] != '\0'; i++) {
        string splus(s);
        splus += chars[i];
        genTest(n, splus);
    }
}

TEST(IsPalindromeTest, exhaustive9) {
    genTest(9, "");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
