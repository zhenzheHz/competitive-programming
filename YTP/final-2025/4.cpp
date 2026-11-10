#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int MAXN = 2e5+5, md = 1e9+7;
vector<int> g[MAXN];
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    
    for(char c='a'; c<='z'; c++){
        string b="";
        b+=c;
        bool mk=1;
        for(int x=0; x<s.size(); x++){
            if(s.substr(x, 1) == b){
                mk=0; break;
            }
        }
        if(mk) return cout << b, 0;
    }
    for(char d='a'; d<='z'; d++){
        for(char c='a'; c<='z'; c++){
            string b="";
            b+=d;
            b+=c;
            bool mk=1;
            for(int x=0; x<s.size()-1; x++){
                if(s.substr(x, 2) == b){
                    mk=0; break;
                }
            }
            if(mk) return cout << b, 0;
        }
    }
    for(char e='a'; e<='z'; e++){
        for(char d='a'; d<='z'; d++){
            for(char c='a'; c<='z'; c++){
                string b="";
                b+=e;
                b+=d;
                b+=c;
                bool mk=1;
                for(int x=0; x<s.size()-2; x++){
                    if(s.substr(x, 3) == b){
                        mk=0; break;
                    }
                }
                if(mk) return cout << b, 0;
            }
        }
    }
    for(char f='a'; f<='z'; f++){
    for(char e='a'; e<='z'; e++){
        for(char d='a'; d<='z'; d++){
            for(char c='a'; c<='z'; c++){
                string b="";
                b+=f;
                b+=e;
                b+=d;
                b+=c;
                bool mk=1;
                for(int x=0; x<s.size()-3; x++){
                    if(s.substr(x, 4) == b){
                        mk=0; break;
                    }
                }
                if(mk) return cout << b, 0;
            }
        }
    }
    }
}