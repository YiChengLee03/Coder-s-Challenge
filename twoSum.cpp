#include <vector>
#include <map>

// Time complexity: O(n^2)
// Space complexity: O(1)
std::vector<int> findItems(std::vector<int>& prices, int target) {
    std::vector<int> ret(2, -1);
    for (int i = 0; i < prices.size(); ++i) {
        for (int j = 0; j < prices.size(); ++j) {
            int sum = prices[i] + prices[j];
            if (j != i && sum == target) {
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    return ret;
}

// Time complexity: O(n)
// Space complexity: O(n)
std::vector<int> findItems2(std::vector<int>& prices, int target) {
    std::map<int, int> map;
    std::vector<int> ret(2, -1);
    for(int i = 0; i < prices.size(); ++i) {
        double complement = target - prices[i];
        if(map.find(complement) != map.end()) {
            ret[0] = map[complement];
            ret[1] = i;
            return ret;
        } else {
            map.insert(std::make_pair(prices[i], i));
        }
    }
    return ret;
}
