class Solution {
public:
    int search(vector<int>& nums, int target) {
        

        int midd, r , l ; 
        l = 0; 
        r = std::size(nums); 

        while( l < r )
        {
            midd = (l+r)/2; 
            if(nums[midd] == target )
            {
                return midd ; 
            }else if(nums[midd] > target)
            {
                r = midd; 
            }else
            {   
                l = midd+1; 
            }
        }

        if(l < std::size(nums) && nums[l] == target )
        {
            return l+1; 
        }

        return -1; 
    }
};