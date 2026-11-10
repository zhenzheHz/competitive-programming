#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int32_t main(){
    int r,c;cin>>r>>c;
    auto format = [](int num){
        if(num >= 100)cout << ' ';
        else if(num >=10)cout << "  ";
        else cout << "   ";
        cout << num ;
    };
    auto println = [&](){
        cout << "+-----+";
        for(int i=1;i<=c;i++)cout << "----";
        cout << "--+\n";
    };
    auto print_tail = [&](){
          cout << "  |\n";
    };
    auto table = [&](int &row){
        if(row == 10)cout << "| " << row << "  |";
        else cout << "|  " << row << "  |";
        for(int i=1;i<=c;i++)format(row*i);
        print_tail();
    };
    println();
    cout << "|     |";
    for(int i=1;i<=c;i++)format(i);
    print_tail();
    println();
    for(int i=1;i<=r;i++)table(i);
    println();
}
