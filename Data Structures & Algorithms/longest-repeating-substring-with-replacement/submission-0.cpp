class Solution {
public:
    int characterReplacement(string s, int k) {
       int maxFreq = 0;
       int maxlen = 0;
       int hash[26] = {0};
       int l = 0;
       int r = 0;

       while(r < s.size()){
        hash[s[r]-'A']++;
        maxFreq = max(maxFreq, hash[s[r] - 'A']);

        if((r-l+1) - maxFreq > k){
            hash[s[l]-'A']--;
            maxFreq = 0;

            l = l+1;
        }

        if((r-l+1) - maxFreq <= k){
            maxlen = max(maxlen, r-l+1);
        }

        r++;
       }

       return maxlen;

    }
};