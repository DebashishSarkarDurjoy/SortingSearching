#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &array, int s, int e) {
    int i = s;
    int mid = (s+e) / 2;
    int j = mid + 1;

    vector<int> temp;
    while (i <= mid && j <= e) {
        if (array[i] < array[j]) {
            temp.push_back(array[i++]);
        }
        else temp.push_back(array[j++]);
    }

    while (i <= mid) temp.push_back(array[i++]);
    while (j <= e) temp.push_back(array[j++]);

    int k = 0;
    for (int idx = s; idx <= e; idx++) {
        array[idx] = temp[k++];
    }

    return ;
}

void mergeSort(vector<int> &arr, int s, int e) {
    // base case
    if (s >= e) return ;

    // recursive case
    int mid = (s+e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    return merge(arr, s, e);
}

int main(void) {
    vector<int> arr{10,5,2,0,7,6,4};

    int start = 0;
    int end = arr.size() - 1;
    mergeSort(arr, start, end);

    for (int x: arr) {
        cout << x << ", ";
    }
    cout << endl;

    return 0;
}