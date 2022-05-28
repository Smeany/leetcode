class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size());
        vector<int> bck(nums.size());
        ret[0] = 1;
        bck[nums.size() - 1] = 1;
        for(int i = 1; i < nums.size(); i++){
            ret[i] = ret[i-1] * nums[i - 1];
            bck[nums.size()-1-i] = bck[nums.size()-i] * nums[nums.size()-i];
        }
        
        for(int i = 0; i < nums.size() - 1; i++) {
            ret[i] *= bck[i];
        }
        
        return ret;
    }
};
