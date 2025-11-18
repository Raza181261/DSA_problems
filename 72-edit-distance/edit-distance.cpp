class Solution {
public:
    int m, n;
    int t[501][501];
    int solve(int i, int j, string& word1, string& word2) {
        if (i == word1.length()) {
            return n - j;
        } else if (j == word2.length()) {
            return m - i;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        if (word1[i] == word2[j]) {
            return t[i][j] = solve(i + 1, j + 1, word1, word2);
        }

        int insert = 1 + solve(i, j + 1, word1, word2);
        int del = 1 + solve(i + 1, j, word1, word2);
        int replace = 1 + solve(i + 1, j + 1, word1, word2);

        return t[i][j] = min({insert, del, replace});
    }
    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();
        memset(t,-1,sizeof(t));
        return solve(0, 0, word1, word2);
    }
};