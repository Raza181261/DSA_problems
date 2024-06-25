class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return getActual(s) == getActual(t);
    }

private:
    string getActual(const string& input) {
        string actualString;
        int hashCount = 0;

        for (int i = input.length() - 1; i >= 0; i--) {
            if (input[i] == '#') {
                hashCount++;
            } else {
                if (hashCount > 0) {
                    hashCount--;
                } else {
                    actualString += input[i];
                }
            }
        }
        reverse(actualString.begin(), actualString.end());
        return actualString;
    }
};