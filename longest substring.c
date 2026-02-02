#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int maxLength = 0;
    int left = 0;
    
    // Array to store the last seen index of each character (ASCII 128)
    int lastSeen[128];
    // Initialize all positions to -1
    for (int i = 0; i < 128; i++) lastSeen[i] = -1;

    for (int right = 0; right < n; right++) {
        char current_char = s[right];

        // If the character was seen before AND is inside our current window
        if (lastSeen[current_char] >= left) {
            // Move the left boundary past the last occurrence of this character
            left = lastSeen[current_char] + 1;
        }

        // Update the last seen position of the character
        lastSeen[current_char] = right;

        // Calculate current window size and update max
        maxLength = MAX(maxLength, right - left + 1);
    }

    return maxLength;
}
