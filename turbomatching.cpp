#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x != end(arr); ++x)
#define FORREV(x,plus,arr) for(auto x = (arr).rbegin()+(plus); x !=(arr).rend(); ++x)
#define REE(s_) {cout<<s_<<'\n';exit(0);}
#define GETCIN(arr) for(auto &i: (arr)) cin>>i
#define GET(arr) for(auto &i: (arr)) sc(i)
#define GETSTR(arr) for(auto &i: (arr)) getstr(i)
#define INF 0x7F7F7F7F //2139062143 | 127 in memset -> memset(arr,127,size)
#define SINF 1061109567 //Safe INF, for graphs or 2d arrays 63 in memset(arr,63,size)
#define LL_INF 7234017283807667300 //100 in memset(arr,100,size) !!!must be LL
#define whatis(x) cerr << #x << " is " << x << endl;
#define e1 first
#define e2 second
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
#define umap unordered_map
#define uset unordered_set
using namespace std;

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
template<typename T> inline void print_128(T num){ if(!num) return; print_128(num / 10); cout.put((num % 10) + '0'); }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> inline T mod(T i, T n) { return (i % n + n) % n; }

#define N 100001

int vis[N];
int assign[N];
vector<int> adj[N];

int matchit; //so you dont have to clear vis
//INCREMENT BEFORE EACH SALVE OF AUGS
//2 Grupy muszą być oddzielone w oznaczeniu, tzn. np zajmuja miejsca 0..n-1 n..n+m-1
//Jesli nie potrzeba takiego speeda, można uniknąć warunku powużej jak wywalisz
//podówjny assign (tylko zostawiasz dla 2 grupy)
bool aug(int cur){
    if(vis[cur] == matchit) return 0;
    vis[cur] = matchit;
    FORR(i,adj[cur]){
        if(assign[i] == -1){
            assign[i] = cur;
            assign[cur] = i;
            return 1;
        }
    }
    FORR(i,adj[cur]){
        if(aug(assign[i])){
            assign[i] = cur;
            assign[cur] = i;
            return 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n,m,tmp;
    sc(t);
    FORE(cas,1,t){
        sc(n,m);
        FOR(i,0,n){
            adj[i].clear();
            FOR(x,0,m){
                sc(tmp);
                if(tmp)
                    adj[i].push_back(x+n);
            }
        }
        memset(assign,-1,(n+m) << 2);
        int mf = 0;
        //pojedyńczy aug:
        /* { */
        /*     ++matchit; */
        /*     int i = 5; */
        /*     mf += aug(i); */
        /* } */
        //TURBO MATCHING (SERIA)
        list<int> unm;
        FOR(i,0,n) unm.push_back(i);
        int bmf = -1;
        while(mf > bmf){
            ++matchit;
            bmf = mf;
            for(auto it = unm.begin(); it != unm.end(); ){
                if(vis[*it] != matchit && !~assign[*it] && aug(*it)){ //WAŻNE ŻEBY NIE NATKĄĆ SIĘ TU NA V Z 2. GRUPY
                    ++mf;
                    ++it;
                    unm.erase(prev(it));
                }
                else{
                    ++it;
                }
            }
            /* FOR(i,0,n){ //WAŻNE ŻEBY NIE NATKĄĆ SIĘ TU NA V Z 2. GRUPY */
            /*     if(vis[i] != matchit && !~assign[i] && aug(i)) ++mf; */
            /* } */
        }
        cout << "Case " << cas << ": a maximum of " << mf << " nuts and bolts can be fitted together\n";
    }
}

