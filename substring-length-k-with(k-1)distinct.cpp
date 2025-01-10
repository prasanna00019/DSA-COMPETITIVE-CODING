// https://www.geeksforgeeks.org/problems/substrings-of-length-k-with-k-1-distinct-elements/1
int countOfSubstrings(string S, int K) {
    int n = S.length();
    if (n < K) return 0; // If string is smaller than K, no such substrings are possible.

    unordered_map<char, int> freq;
    int count = 0;

    // Initialize the first window
    for (int i = 0; i < K; i++) {
        freq[S[i]]++;
    }

    // Check for the first window
    if (freq.size() == K - 1) {
        count++;
    }

    // Slide the window across the string
    for (int i = K; i < n; i++) {
        // Add the new character in the window
        freq[S[i]]++;
        // Remove the character going out of the window
        char toRemove = S[i - K];
        freq[toRemove]--;
        if (freq[toRemove] == 0) {
            freq.erase(toRemove);
        }

        // Check the condition for the current window
        if (freq.size() == K - 1) {
            count++;
        }
    }

    return count;
}
