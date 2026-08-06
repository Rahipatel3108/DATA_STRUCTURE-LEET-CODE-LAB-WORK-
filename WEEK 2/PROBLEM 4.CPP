/* • Our hero Teemo is attacking an enemy Ashe with poison attacks! When Teemo attacks
Ashe, Ashe gets poisoned for an exactly duration seconds. More formally, an attack at
second t will mean Ashe is poisoned during the inclusive time interval [t, t + duration -
1]. If Teemo attacks again before the poison effect ends, the timer for it is reset, and the
poison effect will end duration seconds after the new attack.
• You are given a non-decreasing integer array timeSeries, where timeSeries[i] denotes
that Teemo attacks Ashe at second timeSeries[i], and an integer duration.
• Return the total number of seconds that Ashe is poisoned. */

#include <iostream>
#include <vector>
using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    if (timeSeries.empty()) return 0;

    int totalPoisonedTime = 0;

    for (int i = 0; i < timeSeries.size(); i++) {
        if (i == timeSeries.size() - 1) {
            totalPoisonedTime += duration;
        } else {
            int timeUntilNextAttack = timeSeries[i + 1] - timeSeries[i];
            if (timeUntilNextAttack >= duration) {
                totalPoisonedTime += duration;
            } else {
                totalPoisonedTime += timeUntilNextAttack;
            }
        }
    }

    return totalPoisonedTime;
}

int main() {
    int n, duration;

    cout << "Enter size of time series: ";
    cin >> n;

    vector<int> timeSeries(n);

    cout << "Enter time series: ";
    for (int i = 0; i < n; i++) {
        cin >> timeSeries[i];
    }

    cout << "Enter duration: ";
    cin >> duration;

    cout << "Total no of seconds Ashe is poisoned: " << findPoisonedDuration(timeSeries, duration) << endl;

    return 0;
}
