/*
 * Name: Soham Sapkal
 * PRN: 124B1F047
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

struct Record {
    string userID;
    string app;
    int dailyMinutes;
    int posts;
    int likes;
    int follows;
};

Record arr[1000];
Record temp[1000];
int n = 0;

// Merge two sorted subarrays: arr[low..mid] and arr[mid+1..high]
void merge(int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    // Compare elements from both halves and place smaller one into temp
    while (i <= mid && j <= high) {
        if (arr[i].dailyMinutes <= arr[j].dailyMinutes) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements of left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements of right subarray
    while (j <= high) {
        temp[k++] = arr[j++];
    }

    // Copy sorted elements back to original array
    for (i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
}

// Recursive Merge Sort using Divide and Conquer
void mergeSort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(low, mid);
        mergeSort(mid + 1, high);

        merge(low, mid, high);
    }
}

int main() {
    ifstream file("social_media_usage.csv");

    if (!file) {
        cout << "File not found!" << endl;
        return 0;
    }

    string line;

    // Skip CSV header row
    getline(file, line);

    // Read and parse dataset records line by line
    while (getline(file, line) && n < 1000) {
        stringstream ss(line);
        string value;

        getline(ss, arr[n].userID, ',');
        getline(ss, arr[n].app, ',');

        getline(ss, value, ',');
        arr[n].dailyMinutes = atoi(value.c_str());

        getline(ss, value, ',');
        arr[n].posts = atoi(value.c_str());

        getline(ss, value, ',');
        arr[n].likes = atoi(value.c_str());

        getline(ss, value, ',');
        arr[n].follows = atoi(value.c_str());

        n++;
    }

    file.close();

    // Sort records by Daily_Minutes_Spent
    mergeSort(0, n - 1);

    // Display Output
    cout << "\nSorted by Daily_Minutes_Spent\n\n";
    cout << "User_ID\tApp\tMinutes\n";

    for (int i = 0; i < n; i++) {
        cout << arr[i].userID << "\t"
             << arr[i].app << "\t"
             << arr[i].dailyMinutes << endl;
    }

    return 0;
}
