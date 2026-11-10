#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int32_t main(){
    int n;cin>>n;
    vector<int> sequence(n);
    for(int &number : sequence)cin >> number;
    reverse(sequence.begin(),sequence.end());
    for(int &number : sequence)cout << number << ' ';
}
