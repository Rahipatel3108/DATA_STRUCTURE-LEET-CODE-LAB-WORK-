/* Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume
that the majority element always exists in the array. */

#include <stdio.h>
int findMajorityElement(int* nums, int n) {
    int candidate = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
          if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        } }
    return candidate;
}
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    int result = findMajorityElement(nums, n);
    printf("The Majority Element is: %d\n", result);
    return 0;}
