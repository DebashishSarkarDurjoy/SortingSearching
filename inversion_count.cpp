#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int> &array, int s, int e) {
    int i = s;
    int mid = (s+e) / 2;
    int j = mid + 1;

    vector<int> temp;
    int cnt = 0;
    while (i <= mid && j <= e) {
        if (array[i] < array[j]) {
            temp.push_back(array[i]);
            i++;
        }
        else {
            cnt += mid - i + 1;
            temp.push_back(array[j]);
            j++;
        }
    }

    while (i <= mid) temp.push_back(array[i++]);
    while (j <= e) temp.push_back(array[j++]);

    int k = 0;
    for (int idx = s; idx <= e; idx++) array[idx] = temp[k++];

    return cnt;
}

int inversion_count(vector<int> &array, int s, int e) {
    // base case
    if (s >= e) return 0;

    // recursive case
    int mid = (s+e) / 2;
    int c1 = inversion_count(array, s, mid);
    int c2 = inversion_count(array, mid+1, e);

    int ci = merge(array, s, e);
    return c1 + c2 + ci;
}

int main(void) {
    vector<int> arr{0,5,2,3,1};

    int start = 0;
    int end = arr.size() - 1;
    cout << inversion_count(arr, start, end) << endl;

    return 0;
}