#include<bits/stdc++.h>
using namespace std;

signed main(){
    string a,b;
    cin>>a>>b;
    int la=a.size();
    int lb=b.size();
    int M=0;
    if(lb > la){
        string x=a;
        a=b;
        b=x;
        int y=la;
        la=lb;
        lb=y;
    }
    for(int i=la-lb;i<=la;i++){
        int count=0, k=i;
        for(int j=0;j<lb;j++){
            if(k>=la) k-=la;
            //cout<<a[k]<<' '<<b[j]<<'\n';
            if(a[k] == b[j]) {
                count += 1;
            }
            k++;
        }
        //cout<<"c= "<<count<<'\n';
        if(count > M) M = count;
        //cout<<"_____\n";
    }
    cout<<M<<'\n';

    return 0;
}