class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int maxFreq = 0;
        int maxLen = 0;
        int i = 0, j = 0;
        while(j<s.size()){
            freq[s[j]]++;
            maxFreq = max(maxFreq, freq[s[j]]);
            if(j - i + 1 - maxFreq <= k){
                maxLen = max(maxLen, j - i + 1);
            }
            else{
                freq[s[i]]--;
                if(freq[s[i]]==0) freq.erase(s[i]);
                i++;
            }
            j++;
        }
        return maxLen;
    }
};
