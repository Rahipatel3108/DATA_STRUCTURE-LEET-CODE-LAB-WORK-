#include <iostream>
using namespace std;

int main()
{
    int n, key;
    int a[50];

    // Input size
    cout << "Enter number of elements: ";
    cin >> n;

    // Input elements
    cout << "Enter elements in random order:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Sorting the array using Bubble Sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Display sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // Input element to search
    cout << "Enter element to search: ";
    cin >> key;

    // Binary Search
    int low = 0;
    int high = n - 1;
    int found = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == key)
        {
            found = mid;
            break;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    // Display result
    if (found != -1)
    {
        cout << "Element found at position " << found + 1 << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}
