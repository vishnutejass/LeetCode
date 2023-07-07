class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int>hash;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(hash.find(target-nums[i])!=hash.end()){
               
             ans.push_back(hash[target-nums[i]]); //target-nums[i] index value 
             ans.push_back(i); //nums[i] index value
            
            return ans;

         }   
            else
         hash[nums[i]] = i;   //pushing the index as a key   

        }

        
       return ans; 
    }
};


