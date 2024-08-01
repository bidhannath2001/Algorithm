#include <bits/stdc++.h>
#define vll vector<vector<int>>
using namespace std;
vector<int> object_selected(vll dp, int n, int W, vector<int> wt) {
    vector<int> obj;
    int j = W;
    for (int i = n; i > 0 && j > 0; i--) { 
        if (dp[i][j] != dp[i - 1][j]) {
            obj.push_back(i);
            j = j - wt[i - 1];
        }
    }
    return obj;
} 
  
void knapsack(int W, vector<int> wt, vector<int> val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) 
            {
                dp[i][w] = 0;
            } 
            else if (wt[i - 1] <= w) 
            {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } 
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum Profit: " << dp[n][W] << endl;

    vector<int> obj = object_selected(dp, n, W, wt);
    cout << "Selected Objects: ";
    sort(obj.begin(),obj.end());
    for (int i = 0; i < obj.size(); i++) {
        cout << obj[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> v(n);
    vector<int> wt(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i]>>wt[i];
        
    }
    knapsack(W, wt, v, n);

    return 0;
}
