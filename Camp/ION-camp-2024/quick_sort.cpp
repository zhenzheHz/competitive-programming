#include <bits/stdc++.h>
#define int int64_t
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define all(x) x.begin(),x.end()
using namespace std;
template<typename... T>
void get(T&&... args){((cin >> args), ...)}
template<typename... T>
void send(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}
template<typename... T>
void trace(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}

void quick_sort(int *arr,int length){
    if(length <= 1)return;
    int mark = rand()%length;
    int pivot = arr[mark];
    swap(arr[length-1],arr[mark]);
    int left_length = 0;
    for(int i=0;i<length;i++){
        if(arr[i] < pivot)swap(arr[i],arr[left_length++]);
    }
    swap(arr[left_length],arr[length-1]);
    quick_sort(arr,left_length);
    quick_sort(arr+left_length+1,length - left_length -1);
}

int32_t main(){
    int arr[5] = {5,4,3,1,2};
    quick_sort(arr,5);
    for(int &i : arr){
        cout << i << ' ';
    }
}