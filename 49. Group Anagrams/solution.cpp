class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<unsigned int,26>,vector<string>> map;

        for(string str : strs) {
            array<unsigned int,26> arr;
            arr.fill(0);
            for(char c : str)
                arr[c - 'a']++;
            if(map.find(arr) != map.end())
                map[arr].push_back(str);
            else
                map[arr] = {str};
        }

        vector<vector<string>> result;
        for(const auto& p : map) {
            result.push_back(p.second);
        }

        return result;
    }
};
