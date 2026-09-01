class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int lsmallest = INT_MIN;
        int cnt = 0;
        int longest = 1;

        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] - 1 == lsmallest){
                cnt++;
                lsmallest = nums[i];
            } else if(lsmallest != nums[i]){
                cnt = 1;
                lsmallest = nums[i];
            }
            longest = max(longest, cnt);
        }

        return longest;
    }
};
