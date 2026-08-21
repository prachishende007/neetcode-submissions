class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        for(int j = 0; j<nums.size(); j++){
            for(int i = j+1; i<nums.size(); i++){
                if(nums[i] + nums[j] == target){
                    ans.push_back(j);
                    ans.push_back(i);

                    return ans;
                }
            }
        }
    }
};
