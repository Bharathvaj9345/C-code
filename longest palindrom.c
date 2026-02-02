#include <string.h>
#include <stdlib.h>

// Helper function to expand and return the length of the palindrome
int expand(char* s, int left, int right, int n) {
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n < 1) return "";

    int start = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        // Case 1: Odd length (e.g., "aba", center is 'b')
        int len1 = expand(s, i, i, n);
        // Case 2: Even length (e.g., "abba", center is between 'b' and 'b')
        int len2 = expand(s, i, i + 1, n);

        int len = (len1 > len2) ? len1 : len2;

        if (len > maxLen) {
            maxLen = len;
            start = i - (len - 1) / 2;
        }
    }

    // Allocate memory for the result string (+1 for null terminator)
    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    
    return result;
}
