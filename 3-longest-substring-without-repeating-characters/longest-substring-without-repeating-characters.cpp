#include <map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int l{0},r {0}; 
        int maxRange{0};
        std::map<char,int> chars {}; 

        while(r < s.length())
        {
            while(chars[s[r]] >= 1 )
            {
                if(maxRange < (r-l))
                {
                    maxRange = (r-l); 
                }
                chars[s[l]] -= 1; 
                ++l;
            }
            chars[s[r]] += 1;
            ++r; 
        } 

        return maxRange > (r-l) ? maxRange : (r-l); 
    }
};