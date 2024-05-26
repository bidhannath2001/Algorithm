#include <bits/stdc++.h>
using namespace std;

int index(vector<int>& v, int low, int high) {
    int x = v[high]; // Pivot element
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (v[j] <= x) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return i + 1;
}

void Quick_sort(vector<int>& v, int low, int high) {
    if (low < high) {
        int pivot = index(v, low, high);
        Quick_sort(v, low, pivot - 1);
        Quick_sort(v, pivot + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    Quick_sort(v, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
