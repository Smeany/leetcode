#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    static vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> vec;

        map<int,int> map;
        for(int x : nums)
            map[x]++;

        vector<vector<int>> freq(nums.size()+1);
        for (auto it = map.begin(); it != map.end(); ++it)
            freq[it->second].push_back(it->first);

        for(int i = freq.size()-1; i >= 0 ; i--) {
            for(int j = 0; j < freq[i].size(); j++) {
                vec.push_back(freq[i][j]);
                if(vec.size() == k) return vec;
            }
        }
        return vec;
    }
};



int main() {
    std::cout << "whoas" << std::endl;
    vector<int> v = {1};
    vector<int> res = Solution::topKFrequent(v, 1);
    for(int x : res)
        cout << x << ", ";
}
