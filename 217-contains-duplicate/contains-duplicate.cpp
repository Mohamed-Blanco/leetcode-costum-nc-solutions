#include <map>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        std::unordered_set<int> numbers {}; 
        for(const auto& num : nums)
        {
            if(numbers.find(num) == numbers.end()) 
            {
                numbers.insert(num); 
            }else 
            {
                return true ; 
            }
        }
        
        return false ; 

    }
};