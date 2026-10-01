class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int l = 0;
        unordered_map<char, int> mpp;
        

        for(int r = 0; r< s.size(); r++){
            mpp[s[r]]++;

            while(mpp[s[r]] > 1){
                mpp[s[l]]--;
                l++;
            }

            max_len = max(max_len, r-l+1);
        }

        return max_len;
    }
};
