// Problem : https://atcoder.jp/contests/abc382/tasks/abc382_b
#include <bits/stdc++.h>
int main() {
    int n,d;
    std::string box;
    std::cin >> n >> d >> box;
    bool isEaten[n];
    for(int i=0;i<n;i++) isEaten[i] = (box[i]=='.');
    for(int i=n-1;i>=0 && d>0;i--) 
        if(!isEaten[i]) isEaten[i] = 1, d -= 1;
    for(int i=0;i<n;i++) 
        std::cout<<(isEaten[i]?'.':'@');
    return 0;
}