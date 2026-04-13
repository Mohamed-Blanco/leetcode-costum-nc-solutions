#include <map>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::string,vector<std::string>> groups {}; 

        for(const auto& str : strs)
        {
            //sort 
            std::string sortedStr {str};
            std::sort(sortedStr.begin(), sortedStr.end());

            // group
            groups[sortedStr].push_back(str); // handles both cases cleanly
        } 

        std::vector<std::vector<std::string>> result {}; 
        for (const auto& element : groups)
        {
            result.push_back(element.second); 
        }

        return result ; 

    }
};