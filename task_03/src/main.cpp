#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int middle, int right) {
    int left_half_size = middle - left + 1;
    int right_half_size = right - middle;

    vector<int> left_half(left_half_size);
    vector<int> right_half(right_half_size);

    for (int i = 0; i < left_half_size; i++) {
        left_half[i] = arr[left + i];
    }
    for (int i = 0; i < right_half_size; i++) {
        right_half[i] = arr[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < left_half_size && j < right_half_size) {
        if (left_half[i] <= right_half[j]) {
            arr[k++] = left_half[i++];
        } else {
            arr[k++] = right_half[j++];
        }
    }

    while (i < left_half_size) {
        arr[k++] = left_half[i++];
    }
    while (j < right_half_size) {
        arr[k++] = right_half[j++];
    }
}

void merge_sort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int middle = left + (right - left) / 2;
    merge_sort(arr, left, middle);
    merge_sort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    merge_sort(arr, 0, arr.size() - 1);

    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
