#include <iostream>
#include <vector>
#include <climits>

// Time Complexity: O(n^2)
// Space Complexity: O(1)
int maxPriceIncrease(std::vector<int>& priceChanges) {
    int len = priceChanges.size();
    
    if (len == 1) {
        return priceChanges[0];
    }
    
    int max = INT_MIN;
    for(int i = 0; i < len; ++i) {
        int currSum = 0;
        for(int j = i; j < len; ++j) {
            currSum += priceChanges[j];
            max = std::max(max, currSum);
        }
    }
    return max;
}

// Time complexity: O(n)
// Space complexity: O(n)
int maxPriceIncrease(std::vector<int>& priceChanges) {
    int len = priceChanges.size();

    if (len == 1) {
        return priceChanges[0];
    }

    int addNext[len];
    addNext[0] = priceChanges[0];
    int max = addNext[0];
    for (int i = 1; i < len; ++i) {
        addNext[i] = priceChanges[i] + std::max(addNext[i-1], 0);
        max = std::max(max, addNext[i]);
    }
    return max;
}