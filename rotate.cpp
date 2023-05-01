#include <algorithm>
#include <iostream>
#include <vector>

// Copy solution
// Time complexity: O(n)
// Space complexity: O(n)
void rotate(std::vector<char>& chars, int k) {
    if(k == chars.size()) return;
    k %= chars.size();
    std::vector<char> copy;
    for(int i = chars.size()-k; i < chars.size(); ++i) {
        copy.push_back(chars[i]);
    }
    for(int i = 0; i < chars.size()-k; ++i) {
        copy.push_back(chars[i]);
    }
    chars = copy;
}

// Swapping solution
// Time complexity: O(n)
// Space complexity: O(1) 
void rotate(std::vector<char>& chars, int k) {
    if(k == chars.size()) return;
    int len = chars.size();
    k %= len;
    for(int i = 0; i < k; ++i) {
        char temp = chars[len-1];
        for(int i = len-1; i > 0; --i) {
            chars[i] = chars[i-1];
        }
        chars[0] = temp;
    }
}

// Reversing array solution
// Time complexity: O(n)
// Space complexity: O(1) 
void rotate(std::vector<char>& chars, int k) {
    if(k == chars.size()) return;
    int len = chars.size();
    k %= len;
    std::reverse(chars.begin(), chars.end());
    std::reverse(chars.begin(), chars.begin()+k);
    std::reverse(chars.begin()+k, chars.end());
}
