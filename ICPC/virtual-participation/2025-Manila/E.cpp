#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int n,m;
int di[] = {1,-1,0,0}, dj[] = {0,0,1,-1};

struct node{
    int a_i;
    int a_j;
    int b_i;
    int b_j;
};
bool check(pair<int,int> pos){
    return pos.f < n && pos.f >= 0 && pos.s < m && pos.s >= 0; 
}
void solve(){
    cin>>n>>m;
    char arr[n][m],brr[n][m];
    pair<int,int> a_pos,b_pos; // i,j
    for(int i=0;i<n;i++){
        string str;cin>>str;
        for(int j=0;j<m;j++){
            arr[i][j] = str[j];
            if(str[j]=='S'){
                a_pos.f = i;
                a_pos.s = j;
            }
        }
    }
    for(int i=0;i<n;i++){
        string str;cin>>str;
        for(int j=0;j<m;j++){
            brr[i][j] = str[j];
            if(str[j]=='S'){
                b_pos.f = i;
                b_pos.s = j;
            }
        }
    }
    int visit[n][m][n][m];
    memset(visit,0,sizeof(visit));
    queue<node> q;
    node tmp = {a_pos.f,a_pos.s,b_pos.f,b_pos.s};
    q.push(tmp);
    int ans = -1;
    while(!q.empty() && ans == -1){
        tmp = q.front();q.pop();
        //cout<<tmp.a_i<<' '<<tmp.a_j<<'|'<<tmp.b_i<<' '<<tmp.b_j<<'\n';
        for(int t=0; t < 4; t++){
            pair<int,int> a,b;
            a.f = tmp.a_i+di[t];a.s = tmp.a_j+dj[t];
            if(check(a) && arr[a.f][a.s] != 'X'){
                b.f = (brr[tmp.b_i+di[t]][tmp.b_j+dj[t]] == 'X' || tmp.b_i + di[t] < 0 || tmp.b_i + di[t] >= n) ? b.f = tmp.b_i : b.f = tmp.b_i+di[t];
                b.s = (brr[tmp.b_i+di[t]][tmp.b_j+dj[t]] == 'X' || tmp.b_j + dj[t] < 0 || tmp.b_j + dj[t] >= m) ? b.s = tmp.b_j : b.s = tmp.b_j+dj[t];
                if(visit[a.f][a.s][b.f][b.s]) continue;
                visit[a.f][a.s][b.f][b.s] = visit[tmp.a_i][tmp.a_j][tmp.b_i][tmp.b_j]+1;
                q.push({a.f,a.s,b.f,b.s});
                if(brr[b.f][b.s] == 'D') ans = visit[a.f][a.s][b.f][b.s];
            }
        }
    }
    cout<<ans<<'\n';
}
int main(){
    int T;cin>>T;
    while(T--) solve();
}

