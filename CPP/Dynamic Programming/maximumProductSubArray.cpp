//Problem: https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int n = nums.size();
        int mn[n],mx[n];
        memset(mx,0,sizeof(mx));
        memset(mn,0,sizeof(mn));
        mn[0] = mx[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            mx[i] = std::max(nums[i], max(nums[i] * mn[i-1], nums[i] * mx[i-1] ));
            mn[i] = std::min(nums[i], min(nums[i] * mn[i-1], nums[i] * mx[i-1] ));
        }
        
        int mne = std::max(*max_element(mx,mx+n),*max_element(mn,mn+n));
        return mne;
    }
};