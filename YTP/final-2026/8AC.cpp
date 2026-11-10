#include <bits/stdc++.h>
#define int int64_t
using namespace std;

template <typename T = int>
struct MonoStack {
    static vector<int> next_greater(const vector<T>& a) {
        int n = (int)a.size() - 1;
        vector<int> nxt(n + 1, n + 1);
        vector<int> stk;
        for (int i = 1; i <= n; ++i) {
            while (!stk.empty() && a[stk.back()] < a[i]) {
                nxt[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return nxt;
    }

    static vector<int> prev_greater(const vector<T>& a) {
        int n = (int)a.size() - 1;
        vector<int> prv(n + 1, 0);
        vector<int> stk;
        for (int i = n; i >= 1; --i) {
            while (!stk.empty() && a[stk.back()] < a[i]) {
                prv[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return prv;
    }

    static vector<int> next_smaller(const vector<T>& a) {
        int n = (int)a.size() - 1;
        vector<int> nxt(n + 1, n + 1);
        vector<int> stk;
        for (int i = 1; i <= n; ++i) {
            while (!stk.empty() && a[stk.back()] > a[i]) {
                nxt[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return nxt;
    }

    static vector<int> prev_smaller(const vector<T>& a) {
        int n = (int)a.size() - 1;
        vector<int> prv(n + 1, 0);
        vector<int> stk;
        for (int i = n; i >= 1; --i) {
            while (!stk.empty() && a[stk.back()] > a[i]) {
                prv[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return prv;
    }
};

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1), pref(n+1, 0);
    b[0] = (int) 1e18;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + a[i];
    }
    MonoStack stk;
    vector<int> front = stk.prev_smaller(b), back = stk.next_smaller(b);
    int ans = -1;
    for(int i = 1; i <= n; i++) {
        int L = front[i] + 1, R = back[i] - 1;
        ans = max(ans, b[i] * (pref[R] - pref[L-1]));
    }
    cout << ans;
}