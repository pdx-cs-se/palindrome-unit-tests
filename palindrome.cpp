// whattotest.cpp
#include <string>

using namespace std;

char normalizeChar(char ch) {
	if ('a' <= ch && ch <= 'z') {
		// if ch is a lowercase letter, return it.
		return ch;
	} else if ('A' <= ch && ch <= 'Z') {
		// If ch is a capital letter, returns the lowercase version.
		return ch + ('a' - 'A');
	} else {
		// if ch is anything else, returh the null character.
		return '\0';
	}
}

bool isPalindrome(string str) {
	// Returns true if the input string is a palindrome.
	// ignores capitalization and all non-alphabetic characters.
	int i = 0;
	int j = str.length() - 1;

	while (i < j) {
		char ch1 = '\0';
		char ch2 = '\0';
		// Skip over all non-alphabetic characters.
		do {
			ch1 = normalizeChar(str[i]);
			i++;
		} while (ch1 == '\0');

		do {
			ch2 = normalizeChar(str[j]);
			j--;
		} while (ch2 == '\0');
		
		if (ch1 != ch2) {
			return false;
		}
	}
	return true;
}
