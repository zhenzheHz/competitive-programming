#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int l = s.size();
    if(l%2==0) cout<<":)";
    else cout<<s[l/2];
}

