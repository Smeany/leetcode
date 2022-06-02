class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size());
        ret[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            ret[i] = ret[i-1] * nums[i - 1];
        }
        
        int n = 1;
        for(int i = nums.size() - 2; i >= 0; i--) {
            n *= nums[i+1];
            ret[i] *= n;
        }
        
        return ret;
    }
};
