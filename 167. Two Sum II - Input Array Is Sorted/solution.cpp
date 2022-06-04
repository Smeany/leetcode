class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int ia = 0, ib = numbers.size()-1;
        int sum = numbers[ia] + numbers[ib];
        while(sum != target) {
            if(sum < target) {
                ia++;
            }
            if(sum > target) {
                ib--;
            }
            sum = numbers[ia] + numbers[ib];
        }
        return {ia+1,ib+1};
    }
};
