#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to sort the elements in a single bucket
void insertionSort(vector<int>& bucket) {
    int n = bucket.size();
    for (int i = 1; i < n; i++) {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) {
        return; // Array is already sorted
    }

    // Find the minimum and maximum values in the array
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());

    // Determine the range of each bucket
    int range = (maxVal - minVal) / n + 1;

    // Create buckets
    vector<vector<int>> buckets(n);

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (arr[i] - minVal) / range;
        buckets[index].push_back(arr[i]);
    }

    // Sort each bucket and place elements back into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i]);
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    vector<int> arr = {37, 89, 41, 65, 91, 53, 25, 62, 73, 17};
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    bucketSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
