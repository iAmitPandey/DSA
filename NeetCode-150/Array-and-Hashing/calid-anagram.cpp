class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        int arr_s[26] = {0};
        for(char c:s) arr_s[c-'a']++;
        for(char c:t) arr_s[c-'a']--;
        for(int i =0; i<26; i++){
            if(arr_s[i]!=0)return false;
        }
        return true;
    }
};
