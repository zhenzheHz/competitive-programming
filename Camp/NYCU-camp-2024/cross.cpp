#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int32_t main(){
    int n;cin>>n;
    vector<int> sequence1(n),sequence2(n);
    for(int &number : sequence1)cin >> number;
    for(int &number : sequence2)cin >> number;
    for(int i=0;i<n;i++){
        cout << sequence1.at(i) << ' ';
        cout << sequence2.at(i) << ' ';
    }
}
