// Author : Zhenzhe
// Problem : https://zerojudge.tw/ShowProblem?problemid=f470
#include <bits/stdc++.h>
#define int int64_t
using namespace std;
using Integar = string;
Integar operator+(const Integar &A, const Integar &B) {
    Integar C;
    int16_t carry = 0;
    for(int i = 0; i < (int) max(A.size(), B.size()); i++) {
        int16_t a = (i < (int)A.size()? A[A.size()-i-1] - '0' : 0);
        int16_t b = (i < (int)B.size()? B[B.size()-i-1] - '0' : 0);
        int sum = a + b + carry;
        C.push_back('0' + sum % 10);
        carry = sum / 10;
    }
    if(carry) C.push_back('0' + carry);
    reverse(C.begin(),C.end());
    return C;
} 
struct Trie {
    struct Node {
        Node *ch[10];
        int term = 1e18;
        Node () {
            for(int i = 0; i < 10; i++) {
                ch[i] = nullptr;
            }
        }
    }; 
    Node *rt;
    Trie() {rt = new Node();};
    void insert(const string &str, int n) {
        Node *now = rt;
        for(auto &c : str) {
            int idx = c - '0';
            if(!now->ch[idx]) now->ch[idx] = new Node();
            now = now->ch[idx];
            now->term = min(now->term, n);
        }
    }
    int query(const string &str) {
        Node *now = rt;
        for(auto &c : str) {
            int idx = c - '0';
            if(!now->ch[idx]) return -1;
            now = now->ch[idx];
        }
        return now->term;
    }
};
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    Integar a = "1", b = "1" , c = "0";
    Trie dict = Trie();
    dict.insert(a, 0);
    dict.insert(b, 1);
    for(int i = 2; i <= 100000; i++) {
        c = a + b;
        a = b;
        b = c;
        Integar pre(c.begin(),c.begin()+min((int)c.size(),(int)50));
        dict.insert(pre,i);
    }
    for(int Case = 1; Case <= n; Case++) {
        string prefix;
        cin >> prefix;
        cout << "Case #" << Case << ": " << dict.query(prefix) << '\n';
    }
    return 0;
}