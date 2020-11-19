// Palindrome library function.
#include <cassert>
#include <cctype>
#include <string>

using namespace std;

static char normalizeChar(char ch) {
        // Palindrome should only be called on ASCII characters.
        assert(isascii(ch));

        // If ch is a letter, return the lowercase.
        if (isalpha(ch))
                return tolower(ch);

        // if ch is anything else, returh the null character.
        return '\0';
}

// Returns true iff str is a case-insensitive palindrome
// after ignoring all non-alphabetic characters. str must be
// 7-bit ASCII.
extern bool isPalindrome(string str) {
	// Returns true if the input string is a palindrome.
	// ignores capitalization and all non-alphabetic characters.
	int i = 0;
	int j = str.length();

	while (true) {

		char ch1;
		do
			ch1 = normalizeChar(str[i++]);
		while (ch1 == '\0' && i < j);
		if (i >= j)
			return true;
		
		char ch2;
		do
			ch2 = normalizeChar(str[--j]);
		while (ch2 == '\0' && i < j);
		if (i >= j)
			return true;

		if (ch1 != ch2) {
			return false;
		}
	}
	return true;
}
