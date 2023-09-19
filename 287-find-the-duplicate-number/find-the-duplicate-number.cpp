#include <unordered_map>
class Solution {
public:
    int ans = 0;
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        for (auto i = freq.begin(); i != freq.end(); i++) {
            if (i->second > 1) {
                ans = i->first;
                break;
            }
        }
        return ans;
    }
};
