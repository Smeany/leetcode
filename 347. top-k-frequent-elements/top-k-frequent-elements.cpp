#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> map;
        vector<int> kVec(k);
        for(int x : nums) {
            map[x]++;
            int i = kVec.size()-1;
            int j = i/2;
            while(j != 0) {
                if(map[x] > map[kVec[i]])
                    i += j;
                else
                    i -= j;
                j /= 2;
            }
            if(x == kVec[i] || map[x] < map[kVec[0]]) continue;
            if(map[x] > map[kVec[i]]) i++;
            kVec.insert(kVec.begin() + i, x);
            if(kVec.size() > k) {
                kVec.erase(kVec.begin());
            }
        }
        return kVec;
    }
};

int main() {
    
}