// Author : Zhenzhe
// Time : 2024 / 12 / 02
// Info : 2023 全國賽
// Problem : https://tioj.ck.tp.edu.tw/problems/2367
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int n,k,t,human[105];
bool check(int feature) {
    for(int i=0;i<n;i++) {
        if(human[i] == feature) return false;
    }
    int per[k];
    for(int i=k-1;i>=k-t;i--) per[i] = 1;
    for(int i=0;i<k-t;i++) per[i] = 0;
    do {
        bool check = 0;
        vector<int> ck;
        for(int i=0;i<k;i++) {
            if(per[i]) ck.push_back(i);
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<ck.size();j++) {
                if((human[i]>>j)&1 ==)
            }
        }
    }while(next_permutation(per,per+k));
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> k >> t;
    for(int i=0;i<n;i++) cin >> human[i];
    //enumeration
    for(int i=0;i<k;i++) {
        for(int j=0;j<k;j++) {
            for(int m=0;m<k;m++) {
                if(i == j || j == m || m == i) continue;
                int feat = (1<<i) + (1<<j) + (1<<m);
            }
        }
    }
}