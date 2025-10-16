class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;

        // vector<int> count(26,0);

        // for(char &ch:s){
        //     count[ch-'a']++;
        // }

        //  for(char &ch:t){
        //     count[ch-'a']--;
        // }

        // bool allZeros = all_of(begin(count),end(count), [](int element){
        //     return element == 0;
        // });
        // return allZeros;
    }
};