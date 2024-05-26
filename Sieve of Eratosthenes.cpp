#include<bits/stdc++.h>
using namespace std;
/*
bool checkPrime(int n){
    int cnt = 0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cnt++;
            if((n/i)!=i){
                cnt++;
            }
        }
    }
    if(cnt==2){
        return true;
    }
    return false;
}
*/
const int N =1000000;
bool sieve[1000001];
bool createSieve(int n){
    for(int i=2;i<=N;i++){
        sieve[i]=true;
    }
    for(int i=2;i*i<=N;i++){
        if(sieve[i]==true){
            for(int j=i*i;j<=N;j+=i){
                sieve[j]=false;
            }
        }
    }
    return sieve[n];
}
int main ()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool res = createSieve(n);
        if(res)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
