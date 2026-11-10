// Author : Zhenzhe
// Problem : https://tioj.ck.tp.edu.tw/problems/2367
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
vector<int> users;
unordered_set<int> user_set;
int n,k,t;
int conv(const string &s) {
    int res = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '1') {
            res |= (1 << (s.size() - 1 - i));
        }
    }
    return res;
}
bool check(int q_mask) {
    if(user_set.find(q_mask) != user_set.end()) return 0;
    string mask = string(k - t, '0') + string(t, '1');
    do {
        int status = conv(mask);
        bool flag = 0;
        for(auto user_mask : users) {
            if((q_mask & status) == (user_mask & status)) {
                flag = 1;
                break;
            }
        }
        if(!flag) return 0;
    } while(next_permutation(mask.begin(),mask.end()));
    return 1;
}
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    cin >> n >> k >> t;
    for(int i = 0; i < n; i++) {
        string user;
        cin >> user;
        int bmask = conv(user);
        users.push_back(bmask);
        user_set.insert(bmask);
    }
    int ans = -1;
    if(check(0)) ans = 0;
    for(int i = 0; i < k; i++) {
        if(check((1 << i))) ans = (1<<i);
    }
    for(int i = 0; i < k; i++) {
        for(int j = i+1; j < k; j++) {
            if(check((1<<i) | (1<<j))) ans = ((1<<i) | (1<<j));
        }
    }
    for(int i = 0; i < k; i++) {
        for(int j = i+1; j < k; j++) {
            for(int m = j+1; m < k; m++) {
                if(check((1<<i) | (1<<j) | (1<<m))) {
                    ans = ((1<<i) | (1<<j) | (1<<m));
                }
            }
        }
    }
    if(ans == -1) cout<<"none\n";
    else {
        for(int i = k-1; i >= 0; i--) {
            cout << ((ans >> i) & 1);
        }
    }
    return 0;
}