#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> M;
vector<vector<int>> K;

int MatrixChainOrder(vector<int>& v, int i, int j) {
    if (i == j) {
        M[i][j] = 0;
        K[i][j] = 0;
        return 0;
    }
    if (M[i][j] != 0) {
        return M[i][j];
    }
    int mini = INT_MAX;
    int split = -1;
    for (int k = i; k < j; k++) {
        int count = MatrixChainOrder(v, i, k) + MatrixChainOrder(v, k + 1, j) + v[i - 1] * v[k] * v[j];
        if (count < mini) {
            mini = count;
            split = k;
        }
    }
    M[i][j] = mini;
    K[i][j] = split;
    return mini;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> v[i];
    }

    M.resize(n + 1, vector<int>(n + 1, 0)); 
    K.resize(n + 1, vector<int>(n + 1, 0));

    cout << "Minimum number of multiplications is " << MatrixChainOrder(v, 1, n) << endl;

    cout << "Matrix M:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
    cout << "Matrix K:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << K[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
