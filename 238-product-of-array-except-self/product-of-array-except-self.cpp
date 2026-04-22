class Solution {
public:

    // prefix sum 
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = std::size(nums); 
        std::vector<int> prefix(n,1),suffix(n,1), result(n,1);

        for (size_t i = 1 ; i < n ; ++i )
        {
            prefix[i] = prefix[i-1] * nums[i-1]; 
        }

        for( int i = n-2 ; i >= 0 ; --i )
        {
            suffix[i] = suffix[i+1] * nums[i+1]; 
        }

        for(size_t i = 0 ; i < n ; ++i)
        {
            result[i] = suffix[i] * prefix[i]; 
        }
        
        return result ; 
    }
};