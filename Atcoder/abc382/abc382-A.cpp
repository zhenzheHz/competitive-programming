// Problem : https://atcoder.jp/contests/abc382/tasks/abc382_a
#include <bits/stdc++.h>
int main() {
    int n,d,Empty = 0;
    std::string cookie;
    std::cin >> n >> d >> cookie;
    for(int i=0;i<n;i++) Empty += (cookie[i]=='.');
    std::cout<< Empty+d << '\n';
    return 0;
}