// Problem : https://codeforces.com/problemset/problem/706/D
// Tags : Trie, Bitmask
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
struct Trie {
    struct node {
        node *ch[2];
        int cnt = 0;
        node() {ch[0] = ch[1] = nullptr;}
    };
    node *root = new node();
    void insert(int x) {
        node *now = root;
        for(int i=31;i>=0;i--) {
            int bit = (x >> i) & 1;
            if(!now->ch[bit]) now->ch[bit] = new node();
            now = now->ch[bit];
            now->cnt += 1;
        }
    }
    void erase(int x) {
        node *now = root;
        for(int i=31;i>=0;i--) {
            int bit = (x >> i) & 1;
            now = now->ch[bit];
            now->cnt -= 1;
        }
    }
    int query(int x) {
        node *now = root;
        int ans = 0;
        for(int i=31;i>=0;i--) {
            int bit = (x >> i) & 1;
            if(now->ch[bit^1] && now->ch[bit^1]->cnt >= 1) {
                ans |= ((bit ^ 1) << i);
                now = now->ch[bit^1];
            }
            else if(now->ch[bit] && now->ch[bit]->cnt >= 1) {
                ans |= (bit << i);
                now = now->ch[bit];
            }
        }
        return (x ^ ans);
    }
};
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    Trie mulset = Trie();
    mulset.insert(0);
    for(int i=0;i<n;i++) {
        char op;
        int x;
        cin >> op >> x;
        if(op == '+') mulset.insert(x);
        if(op == '-') mulset.erase(x);
        if(op == '?') cout << mulset.query(x) << '\n';
    }
    return 0;
}