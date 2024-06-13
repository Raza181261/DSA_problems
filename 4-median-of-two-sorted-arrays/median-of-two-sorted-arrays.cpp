class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        int c = v1.size() + v2.size();
        vector<int> merged(c);

        // Merge the vectors using the merge function
        merge(v1.begin(), v1.end(), v2.begin(), v2.end(), merged.begin());

        if (c % 2 == 0) {
            // If the combined size is even, return the average of the two middle elements
            return (merged[c/2 - 1] + merged[c/2]) / 2.0;
        } else {
            // If the combined size is odd, return the middle element
            return merged[c/2];
        }
    }
};