// Author : ysh
// Pre-compiled : 2026/10/15 Thu 18:15:07

#include<bits/stdc++.h>
# 0 "<stdin>"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "<stdin>"



using namespace std;

# 1 "/Users/ysh/lab/Coding/library/slow" 1
# 38 "/Users/ysh/lab/Coding/library/slow"
template<class T>
std::istream& operator>>(std::istream& fin,std::vector<T>&f) {
    for(auto &&i : f) fin>>i;
    return fin;
}
template<class T,class R>
std::istream& operator>>(std::istream& fin,std::pair<T,R>&x) {
    fin>>x.first>>x.second;
    return fin;
}

template<class T>
std::ostream& operator<<(std::ostream& fout,std::vector<T>&f) {
    for(auto &i : f) fout<<i<<" ";
    return fout;
}
template<class T,class R>
std::ostream& operator<<(std::ostream& fout,std::pair<T,R>&x) {
    fout<<x.first<<" "<<x.second;
    return fout;
}
# 7 "<stdin>" 2



int64_t n;
vector<pair<int64_t, int64_t>>f;
vector<bool>flag;

const pair<int64_t, int64_t> operator+(const pair<int64_t, int64_t>&l, const pair<int64_t, int64_t>&r) {
    return make_pair(l.first + r.first, l.second + r.second);
}







inline void push(int64_t t, int64_t l, int64_t r) {
    if(l == r) return flag.at(t) = 0, void();

    if(!flag.at(t)) return;
    flag.at(t) = 0;

    int64_t mid = (l + r) >> 1;

    '*';




    (flag.at(((t << 1) | 1)) = !flag.at(((t << 1) | 1)), f.at(((t << 1) | 1)) = make_pair(((mid) - (l) + 1) - f.at(((t << 1) | 1)).second - f.at(((t << 1) | 1)).first, f.at(((t << 1) | 1)).second));
    '*';
    (flag.at(((t << 1) + 2)) = !flag.at(((t << 1) + 2)), f.at(((t << 1) + 2)) = make_pair(((r) - (mid + 1) + 1) - f.at(((t << 1) + 2)).second - f.at(((t << 1) + 2)).first, f.at(((t << 1) + 2)).second));

    '*';

    return;
}

void init(vector<int64_t>&v, int64_t t = 0, int64_t l = -1, int64_t r = -1) {
    if(l == -1 && r == -1) l = 0, r = n - 1;
    if(l == r) return f.at(t) = {v.at(l) == -1 ? 0 : v.at(l), v.at(l) == -1 ? 1 : 0}, void();

    int64_t mid = (l + r) >> 1;
    init(v, ((t << 1) | 1), l, mid);
    init(v, ((t << 1) + 2), mid + 1, r);

    (f.at(t) = f.at(((t << 1) | 1)) + f.at(((t << 1) + 2)));
    return;
}


void check(int64_t l, int64_t r, int64_t t = 0, int64_t nl = -1, int64_t nr = -1) {

    if(nl == -1 && nr == -1) nl = 0, nr = n - 1;


    push(t, nl, nr);

    if(nl >= l && nr <= r) return (flag.at(t) = !flag.at(t), f.at(t) = make_pair(((nr) - (nl) + 1) - f.at(t).second - f.at(t).first, f.at(t).second)), void();
    if(nl > r || nr < l) return;

    int64_t mid = (nl + nr) >> 1;
    check(l, r, ((t << 1) | 1), nl, mid);
    check(l, r, ((t << 1) + 2), mid + 1, nr);

    (f.at(t) = f.at(((t << 1) | 1)) + f.at(((t << 1) + 2)));

    return;
}





signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t a, b;cin>>a>>b;
    vector<int64_t>mark(a), f(a);
    for(int64_t i = 0;i<a;i++) cin>>mark.at(i)>>f.at(i);

    int64_t ans = accumulate(f.begin(),f.end(), 0);
    ::f = vector<pair<int64_t, int64_t>>(a << 2);
    flag = vector<bool>(a << 2);
    ::n = a;

    init(mark);



    for(int64_t _ = 0;_<b;_++) {
        char op;cin>>op;
        if(op == 'W') {
            int64_t l, r;cin>>l>>r;
            check(l, r);
            '*';
        } else {
            int64_t x;cin>>x;
            ans += (::f.at(0).first) * x;
        }
    }

    cout<<(ans);
    return 0;
}
/*
// Author : ysh
// 2026/10/15 Thu 16:28:50
#include<bits/stdc++.h>
using namespace std;
// #include<seg_tree>
#include<slow>

#define int int64_t

int n;
vc<pair<int, int>>f;
vc<bool>flag;

const pair<int, int> operator+(const pair<int, int>&l, const pair<int, int>&r) {
    return make_pair(l.first + r.first, l.second + r.second);
}

#define left(i) ((i << 1) | 1)
#define right(i) ((i << 1) + 2)
#define pull(i) (f.at(i) = f.at(left(i)) + f.at(right(i)))
#define flip(i, l, r) (flag.at(i) = !flag.at(i), f.at(i) = make_pair(((r) - (l) + 1) - f.at(i).second - f.at(i).first, f.at(i).second))
// #define push(t) 

inline void push(int t, int l, int r) {
    if(l == r) return flag.at(t) = 0, void();

    if(!flag.at(t)) return;
    flag.at(t) = 0;

    int mid = (l + r) >> 1;

    debug(t, l, r);
    
    // push(left(t), l, mid);
    // push(right(t), mid + 1, r);

    flip(left(t), l, mid);
    debug(f, right(t), mid + 1, r);
    flip(right(t), mid + 1, r);

    debug(f);

    return;
}

void init(vc<int>&v, int t = 0, int l = -1, int r = -1) {
    if(l == -1 && r == -1) l = 0, r = n - 1;
    if(l == r) return f.at(t) = {v.at(l) == -1 ? 0 : v.at(l), v.at(l) == -1 ? 1 : 0}, void();

    int mid = (l + r) >> 1;
    init(v, left(t), l, mid);
    init(v, right(t), mid + 1, r);

    pull(t);
    return;
}

#undef nl
void check(int l, int r, int t = 0, int nl = -1, int nr = -1) {
    // debug(l, r, t, nl, nr);
    if(nl == -1 && nr == -1) nl = 0, nr = n - 1;
    // if(nl == nr) 

    push(t, nl, nr);

    if(nl >= l && nr <= r) return flip(t, nl, nr), void();
    if(nl > r || nr < l) return;

    int mid = (nl + nr) >> 1;
    check(l, r, left(t), nl, mid);
    check(l, r, right(t), mid + 1, nr);

    pull(t);

    return;
}

#define get(...) (::f.at(0).first)

// int get(int l, int r, int t)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;cin>>a>>b;
    vc<int>mark(a), f(a);
    re(i, a) cin>>mark.at(i)>>f.at(i);

    int ans = accumulate(all(f), 0);
    ::f = vc<pair<int, int>>(a << 2);
    flag = vc<bool>(a << 2);
    ::n = a;

    init(mark);

    // seg_tree<int>t(f);

    re(b) {
        char op;cin>>op;
        if(op == 'W') {
            int l, r;cin>>l>>r;
            check(l, r);
            debug(::f);
        } else {
            int x;cin>>x;
            ans += get() * x;
        }
    }

    out(ans);
    return 0;
}
*/

