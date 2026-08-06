/* • You are given a sorted unique integer array nums.
• A range [a, b] is the set of all integers from a to b (inclusive).
• Return the smallest sorted list of ranges that cover all the numbers in the
array exactly. That is, each element of nums is covered by exactly one of the
ranges, and there is no integer x such that x is in one of the ranges but not
in nums.
• Each range [a, b] in the list should be output as:
• "a->b" if a! = b
• "a" if a == b */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int start = nums[i];

            while (i + 1 < n && (long long)nums[i + 1] - nums[i] == 1) {
                i++;   }

            if (start == nums[i]) {
                result.push_back(to_string(start));
            } else {
                result.push_back(to_string(start) + "->" + to_string(nums[i]));  }  }
 return result; } };

int main() {
    Solution sol;
    int size;
    cout << "Enter number of elements: ";
    cin >> size;

    if (size == 0) {
        cout << "Output: []" << endl;
        return 0;
    }
     vector<int> nums(size);
    cout << "Enter " << size << " unique integers: ";
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    vector<string> result = sol.summaryRanges(nums);
     cout << "Summary Ranges: [";
    for (int i = 0; i < result.size(); i++) {
        cout << "\"" << result[i] << "\"";
        if (i < result.size() - 1) cout << ", ";     }
        cout << "]" << endl;

    return 0;  }
