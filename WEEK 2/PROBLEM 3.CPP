/* • Given an array nums of n integers where nums[i] is in the range [1, n], return an
array of all the integers in the range [1, n] that do not appear in nums. */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    unordered_set<int> s;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }

    vector<int> missing;
    for (int i = 1; i <= n; i++) {
        if (s.find(i) == s.end()) {
            missing.push_back(i);
        }  }
  cout << "Missing numbers in array: [";
    for (int i = 0; i < missing.size(); i++) {
        if (i > 0) cout << ", ";
        cout << missing[i];
    }
    cout << "]" << endl;

    return 0;
}
