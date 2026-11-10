// Problem : https://codeforces.com/problemset/problem/455/B
// Tags : Game Theory, Trie
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
struct Trie {
    struct node {
        node *ch[26];
        node() {
            for(int i=0;i<26;i++) ch[i] = nullptr;
        }
    };
    node *root;
    Trie() {root = new node();}
    void insert(const string &str) {
        node *now = root;
        for(const char &c : str) {
            int idx = c - 'a';
            if(!now->ch[idx]) now->ch[idx] = new node();
            now = now->ch[idx];
        }
    }
    bool dfs1(node *now) {
        for(int i=0;i<26;i++) {
            if(now->ch[i] && !dfs1(now->ch[i]))
                return 1;
        }
        return 0;
    }
    bool dfs2(node *now) {
        bool check = 1;
        for(int i=0;i<26;i++) {
            if(now->ch[i]) {
                check = 0;
                if(!dfs2(now->ch[i])) return 1;
            }
        }
        return check;
    }
};
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    Trie rt = Trie();
    for(int i=0;i<n;i++) {
        string str;
        cin >> str;
        rt.insert(str);
    }
    bool win = rt.dfs1(rt.root);
    bool lose = rt.dfs2(rt.root);
    string ans;
    if(win) {
        if(lose) ans = "First";
        else ans = k & 1? "First" : "Second";
    }else ans = "Second";
    return cout<<ans,0;
}