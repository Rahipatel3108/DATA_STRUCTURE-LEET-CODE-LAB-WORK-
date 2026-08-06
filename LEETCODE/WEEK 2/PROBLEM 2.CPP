/* • Given an integer array nums, move all 0's to the end of it while maintaining the
relative order of the non-zero elements.
• Note that you must do this in-place without making a copy of the array. */

#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int writeIndex = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[writeIndex] = nums[i];
            writeIndex++;
        }  }
     while (writeIndex < nums.size()) {
        nums[writeIndex] = 0;
        writeIndex++;
    } }

void printArray(const vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) {
            cout << ", ";
        }  }
    cout << "]";
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
           cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
            moveZeroes(nums);
     cout << "After moving zeroes: ";
    printArray(nums);
    cout << endl;

    return 0;
}
