class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength = 0;
        int l = 0;
        int r = 0;
        int hash[256];

        for(int i =0; i<256; i++){
            hash[i] = -1;
        }

        while(r<s.size()){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]]+ 1;
                }
            }

            maxlength = max(r-l+1, maxlength);

            hash[s[r]] = r;
            r++;
        }

        return maxlength;
    }
};
