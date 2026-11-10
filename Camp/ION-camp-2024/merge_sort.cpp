#include <bits/stdc++.h>
#define int int64_t
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
using namespace std;
template<typename... T>
void trace(T&&... args) { ((cerr << args << " "), ...);cerr<<'\n';}

void merge_sort(int *arr,int length){
    if(length <= 1)return;
    int left_length = length>>1;
    int right_length = length - left_length;
    int *left_arr = arr,*right_arr = arr + left_length;
    merge_sort(left_arr,left_length);
    merge_sort(right_arr,right_length);
    int tmp[length];
    int l_pointer = 0,r_pointer = 0,index = 0;
    while(l_pointer<left_length && r_pointer<right_length){
        if(left_arr[l_pointer] < right_arr[r_pointer]){
            tmp[index++] = left_arr[l_pointer++];
        }else tmp[index++] = right_arr[r_pointer++];
    }
    while(l_pointer<left_length)tmp[index++] = left_arr[l_pointer++];
    while(r_pointer<right_length)tmp[index++] = right_arr[r_pointer++];
    for(int i=0;i<length;i++)arr[i] = tmp[i];
}

int32_t main(){
    int arr[5] = {1,3,5,4,2};
    merge_sort(arr,arr.size());
    for(int &i : arr){
        cout << i << ' ';
    }
}