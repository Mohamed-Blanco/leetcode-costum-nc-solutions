class Solution {
public:
    
    std::vector<vector<int>> sets{}; 

    void BFS(int i,int n,std::vector<int> set,vector<int>& nums)
    {
        if(i == n )
        {
            this->sets.push_back(set);
            return;  
        }

        set.push_back(nums[i]); 
        BFS(i+1,n,set,nums);
        set.pop_back(); 
        BFS(i+1,n,set,nums);

    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        BFS(0,std::ssize(nums),{}, nums); 
        return this->sets ; 
    }
};