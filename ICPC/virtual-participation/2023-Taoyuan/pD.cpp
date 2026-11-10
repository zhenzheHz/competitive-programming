// Author : ysh
// Pre-compiled : 2026/10/15 Thu 15:59:05

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
# 6 "<stdin>" 2

const int xx[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int yy[] = {1, 0, -1, 0, 1, 1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k = 0;
    int n;cin>>n;
    while(n--) {
        cout<<("Airplane #");
        cout<<(++k);
        cout<<(":")<<"\n";

        int a, b, l, r;cin>>a>>b>>l>>r;

        vector<vector<int>>f(a, vector<int>(b));
        char tmp;

        for(auto &i : f) for(auto &j : i) cin>>tmp, j = (tmp == 'V' ? -1 : 0);

        for(int i = 0;i<a;i++) for(int j = 0;j<b;j++) {
            if(f.at(i).at(j) != -1) continue;
            for(int k = 0;k<8;k++) {
                int nx = i + xx[k];
                int ny = j + yy[k];

                if(nx < 0 || ny < 0 || nx >= a || ny >= b) continue;
                if(f.at(nx).at(ny) == -1) continue;

                f.at(nx).at(ny) = max(f.at(nx).at(ny), (k >= 4 ? r : l));
            }
        }

        for(auto &i : f) {for(auto &j : i) ((j == -1 ? cout<<('V') : cout<<(j))); cout<<"\n";}
    }
    return 0;
}
/*
// Author : ysh
// 2026/10/15 Thu 15:44:37
#include<bits/stdc++.h>
using namespace std;
#include<slow>

const int xx[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int yy[] = {1, 0, -1, 0, 1, 1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k = 0;
    int n;cin>>n;
    while(n--) {
        outt(Airplane #);
        out(++k);
        outl(":");

        int a, b, l, r;cin>>a>>b>>l>>r;

        vc<vc<int>>f(a, vc<int>(b));
        char tmp;

        repo(&i, f) repo(&j, i) cin>>tmp, j = (tmp == 'V' ? -1 : 0);

        re(i, a) re(j, b) {
            if(f.at(i).at(j) != -1) continue;
            re(k, 8) {
                int nx = i + xx[k];
                int ny = j + yy[k];

                if(nx < 0 || ny < 0 || nx >= a || ny >= b) continue;
                if(f.at(nx).at(ny) == -1) continue;

                f.at(nx).at(ny) = max(f.at(nx).at(ny), (k >= 4 ? r : l));
            }
        }

        repo(&i, f) {repo(&j, i) ((j == -1 ? out('V') : out(j))); nl;}
    }
    return 0;
}
*/

