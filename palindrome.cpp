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
	int n = str.length();
	// Trival cases.
	if (n <= 1)
		// Empty string is a palindrome.
		// One non-letter is a palindrome.
		// One letter is a palindrom.
		return true;
	int i = 0;
	int j = n;
	// let removeNonAlpha(s) = s with non-alpha characters deleted
	// let filter(s) = map(removeNonAlpha . normalizeChar, s)
	// let rev(s) = string-reversal of s
	// let rfilter(s) = rev(filter(s))
	//
	// Invariant:
	//    i >= 0
	//    j <= n
	//    i + 1 < j
	//    filter(str[0..i]) = rfilter(str[j..n])
	while (i + 1 < j) {
		// i + 1 < j
		char ch1 = normalizeChar(str[i]);
		if (ch1 == '\0') {
			i += 1;
			// filter(str[0..i]) = rfilter(str[j..n])
			continue;
		}
		// ch1 is alpha

		// i + 1 < j
		char ch2 = normalizeChar(str[j - 1]);
		if (ch2 == '\0') {
			j -= 1;
			// filter(str[0..i]) = rfilter(str[j..n])
			continue;
		}
		// ch1 is alpha and ch2 is alpha

		if (ch1 != ch2)
			// filter(str[0..i]) != rfilter(str[j..n])
			return false;
		
		// str[i] == str[j]
		// filter(str[0..=i]) = rfilter(str[j-1..n])
		i += 1;
		j -= 1;
		// filter(str[0..i]) = rfilter(str[j..n])
	}
        // filter(str[0..i]) = rfilter(str[j..n])
        // j = i  (n even)
        // j = i + 1 (n odd)
        return true;
}
