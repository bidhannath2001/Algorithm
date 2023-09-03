#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    long long a, b;
    cin >> a >> b;
    vector<long long> fibo;
    fibo.push_back(0);
    fibo.push_back(1);

    long long next = fibo[0] + fibo[1];
    while (next <= b) {
        fibo.push_back(next);
        next = fibo[fibo.size() - 1] + fibo[fibo.size() - 2];
    }

    // Use a set to store unique Fibonacci numbers within the range [a, b]
    set<long long> uniqueFibo;

    for (long long num : fibo) {
        if (num >= a && num <= b) {
            uniqueFibo.insert(num);
        }
    }

    // Print the unique Fibonacci numbers
    for (long long num : uniqueFibo) {
        cout << num << endl;
    }

    return 0;
}
