/*You are given an array prices where prices[i] is the price of a given stock on the i
th day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the
stock before you buy again). */

#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;}
int maxProfit(int prices[], int n) {
    if (n == 0) {
        return 0; }
 int firstBuy = -prices[0];
    int firstSell = 0;
    int secondBuy = -prices[0];
    int secondSell = 0;
  for (int i = 1; i < n; i++) {
        firstBuy = max(firstBuy, -prices[i]);
        firstSell = max(firstSell, firstBuy + prices[i]);
        secondBuy = max(secondBuy, firstSell - prices[i]);
        secondSell = max(secondSell, secondBuy + prices[i]); }
 return secondSell;}
int main() {
    int n;
 printf("Enter number of days: ");
    scanf("%d", &n);
   int prices[n];
printf("Enter stock prices: ");
    for (int i = 0; i < n; i++) {
scanf("%d", &prices[i]); }
 int result = maxProfit(prices, n);
printf("Maximum Profit = %d\n", result);
 return 0; }
