#include <bits/stdc++.h> //Stack size ~2'000'000(x4) use "int *arr = new int[n]" above that
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define all(a) (a.begin()),(a.end())
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORRC(x,arr) for(auto const &x: arr)
#define PRINT(arr) {copy((arr).begin(), (arr).end(), ostream_iterator<int>(cout, " "));cout<<'\n';}
#define REE(s_) {cout<<s_<<'\n';return 0;} //print s_ and terminate program
#define GET(arr) for(auto &i: (arr)) cin>>i
#define GETSC(arr) for(auto &i: (arr)) sc(i)
#define GETSTR(arr) for(auto &i: (arr)) getstr(i)
#define INF 2139062143 //127 in memset -> memset(arr,127,size)
#define SINF 1061109567 //Safe INF, for graphs or 2d arrays 63 in memset(arr,63,size)
#define LL_INF 7234017283807667300 //100 in memset(arr,100,size) !!!must be LL
#define whatis(x) cerr << #x << " is " << x << endl;
typedef std::pair<int,int> pi; typedef std::vector<int> vi; typedef std::vector<std::string> vs;
using namespace std;

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }//prnt vec
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }//prnt pair
template<typename T> inline T fstoi(const string &str){auto it=str.begin();bool neg=0;T num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
template<typename T> inline void sc(T &num){bool neg=0;int c;num=0;while(c=getchar_unlocked(),c<33){;}if(c=='-'){neg=1;c=getchar_unlocked();} for(;c>47;c=getchar_unlocked()) num=num*10+c-48;if(neg) num*=-1;}
inline void getstr(string &str){char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}

const int N = 1e5+2;
int t[N*2];
int n;

//Find index of max number in range without extra parameters

int query(int v, int l, int r, int tl, int tr){ //all inclusive
    if(v >= n)
        return v-n;
    int tm = (tl+tr) >> 1;
    if((t[v << 1] > t[v << 1|1] && l <= tm) || tm+1 > r)
        return query(v << 1,l,min(r,tm),tl,tm);
    return query(v << 1|1,max(l,tm+1),r,tm+1,tr);
}

void modify(int p, int val){
    for(t[p += n] = val; p > 1; p>>=1)
        t[p>>1] = max(t[p] , t[p^1]);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string str;
    vector<int> vec{4,6,1,6,32,65,43,54,12,32,53,34,65,23,45,76,89,45,71,2,6,9,43,33,11,77,54,76,1,2,3,7};
    auto cur = vec.begin();
    n = vec.size();
    whatis(vec)
    whatis(n)
    for(auto ct = t+n; ct < t+2*n; ++ct)
        *ct = *cur++;
    for(int i = n - 1; i > 0; --i)
        t[i] = max(t[i*2] , t[i*2|1]);
    int qu;
    sc(qu);
    int l,r;
    while(qu--){
        sc(l);
        sc(r);
        cout << query(1,l,r,0,n) << endl; //inclusive
        /* modify(l-1,3); */
        /* cout << query(1,l-1,r,0,n) << '\n'; */
    }
}

