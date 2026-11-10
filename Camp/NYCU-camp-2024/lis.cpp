#include <bits/stdc++.h>
using namespace std;
int32_t main(){
    int n;cin>>n;
    vector<int> nums(n),LIS;
    for(int &num : nums){
        cin >> num;
        auto found = lower_bound(LIS.begin(),LIS.end(),num);
        if(found == LIS.end())LIS.push_back(num);
        else *found = num;
    }
    cout << LIS.size();
}
