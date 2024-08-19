class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();

        if(t.length() > n)
         return "";

         unordered_map <char, int>mp;
         //for storing elements in map
         for(char &ch : t)
         mp[ch]++;

         int windowSize = INT_MAX;
         int required_count = t.length();
         int i = 0,j = 0;
         int str_i = 0;

         //start jounrny to iterate
         while(j < n){
            char ch = s[j];
            if (mp[ch] > 0)
               required_count--;
               mp[ch]--;
            
            while(required_count == 0){
                //start srink
                int currWindowSize = j-i+1;
                 if(windowSize > currWindowSize){
                    windowSize = currWindowSize;
                    str_i = i;
                 }
                 mp[s[i]]++;
                 if(mp[s[i]] > 0){
                    required_count++;
                 }
                 i++;
            }
            j++;
         }
       
       return windowSize == INT_MAX ? "" : s.substr(str_i, windowSize);

    }
};
