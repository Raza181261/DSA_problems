class Solution {
public:
    // Pick the max subsequence of length k from single array
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> stack;
        int drop = nums.size() - k; // Number of elements we can drop
        for (int num : nums) {
            while (!stack.empty() && drop > 0 && stack.back() < num) {
                stack.pop_back();
                drop--;
            }
            stack.push_back(num);
        }
        stack.resize(k);
        return stack;
    }

    // Merge two sequences into the maximum number
    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> res;
        int i = 0, j = 0;
        while (i < a.size() || j < b.size()) {
            if (lexicographical_compare(a.begin() + i, a.end(), b.begin() + j, b.end()))
                res.push_back(b[j++]);
            else
                res.push_back(a[i++]);
        }
        return res;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        int m = nums1.size(), n = nums2.size();
        for (int i = max(0, k - n); i <= min(k, m); i++) {
            vector<int> subseq1 = maxSubsequence(nums1, i);
            vector<int> subseq2 = maxSubsequence(nums2, k - i);
            vector<int> candidate = merge(subseq1, subseq2);
            if (candidate > ans)
                ans = candidate;
        }
        return ans;
    }
};
