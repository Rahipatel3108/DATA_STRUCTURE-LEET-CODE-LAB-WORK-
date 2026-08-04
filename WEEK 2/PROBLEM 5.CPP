/* • Alice has n candies, where the i

th candy is of type candyType[i]. Alice noticed that

she started to gain weight, so she visited a doctor.
• The doctor advised Alice to only eat n / 2 of the candies she has (n is always
even). Alice likes her candies very much, and she wants to eat the maximum
number of different types of candies while still following the doctor's advice.
• Given the integer array candy Type of length n, return the maximum number of
different types of candies she can eat if she only eats n / 2 of them. */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> uniqueTypes(candyType.begin(), candyType.end());
        return min((int)uniqueTypes.size(), (int)candyType.size() / 2);
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter the total number of candies: ";
    cin >> n;

    vector<int> candies(n);
    cout << "Enter the " << n << " candy types (space-separated): ";
    for (int i = 0; i < n; i++) {
        cin >> candies[i];
    }

    int result = sol.distributeCandies(candies);
    cout << "Maximum number of different types Alice can eat: " << result << endl;

    return 0;
}
