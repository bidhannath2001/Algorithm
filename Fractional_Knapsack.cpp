#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, w;
    cin >> n >> w;
    vector<int> obj(n);
    vector<int> profit(n);
    vector<int> weight(n);
    vector<pair<float, int>> profit_per_kg;

    for (int i = 0; i < n; i++) {
        cin >> obj[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    for (int i = 0; i < n; i++) {
        profit_per_kg.push_back({(float)profit[i] / weight[i], i});
    }

    sort(profit_per_kg.begin(), profit_per_kg.end(), greater<pair<float, int>>());

    vector<pair<int,float>>element; 

    float total_profit = 0;
    int remaining_weight = w;
    for (int i = 0; i < n; i++) {
        int idx = profit_per_kg[i].second;
        if (remaining_weight > 0 && weight[idx] <= remaining_weight) {
            remaining_weight -= weight[idx];
            total_profit += profit[idx];
            element.push_back({obj[idx],100.0});
        } 
        else 
        {
            if (remaining_weight > 0) {
                total_profit += profit_per_kg[i].first * remaining_weight;
                element.push_back({obj[idx],((float)remaining_weight/weight[idx])*100});
                remaining_weight = 0;
            }
            break;
        }
    }
    sort(element.begin(), element.end());

    //Which object is used and how much is that object used?
    for(auto it:element){
        cout<<it.first<<"  "<<fixed<<setprecision(2)<<it.second<<"%"<<endl;
    }
    cout<<endl;

    //total profit
    cout <<"Total profit: "<< fixed << setprecision(2) << total_profit << endl;

    return 0;
}


/*
    7 15
    1 2 3 4 5 6 7 
    10 5 15 7 6 18 3
    2 3 5 7 1 4 1
    1  100.00%
    2  66.67%
    3  100.00%
    5  100.00%
    6  100.00%
    7  100.00%

    Total profit: 55.33
*/
