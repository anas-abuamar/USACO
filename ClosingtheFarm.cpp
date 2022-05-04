#include <bits/stdc++.h>
using namespace std;
#define   IOS   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);srand(chrono::high_resolution_clock::now().time_since_epoch().count());
#define   mp make_pair
#define   pb push_back
#define   ll long long
#define   debug(x)  cout << '[' << #x << " is: " << x << "] " << endl;
#define   debugg(x,y)  cout << '[' << #x << " is: " << x << "] " << " " << '[' << #y << " is: " << y << "] \n";
#define   rsor(v)   sort(v.rbegin() , v.rend());
#define   rev(v)    reverse(v.begin() , v.end());
#define   sz(x)     (int)(x).size()
#define   all(x)    x.begin(), x.end()
#define  _cout(v)  for(auto f : v ) cout << f << " " ;
#define  _cin(v)   for(auto &it : v)cin >> it ;
#define  _for(v)   for(int i=0;i<(v);i++)
#define   PFD(n) cout.precision(n)<<fixed
#define gc getchar_unlocked
#define  fs first
#define  sc second
const long double PI=3.14159265359;
//#define  int long long
#define  vi vector<int>

void setIO(string name = "") {if(sz(name)){freopen((name+".in").c_str(), "r", stdin);
                                            freopen((name+".out").c_str(), "w", stdout);}}
const int N = 3e3+3;
vector<int>adj[N];
vector<bool>close(N),vis(N);
int cur;
void dfs(int node){
   if (vis[node] || close[node])return;
   vis[node] = true;
   cur++;
   for (auto X:adj[node]){
      if (!vis[X])dfs(X);
   }
}
void solve(){
   // Think twice code once
   // Educational
   int n,m;
   cin >> n >> m;
   for (int i=0;i<m;i++){
      int a,b;
      cin >> a >> b;
      adj[a].pb(b);
      adj[b].pb(a);
   }
   vi a(n);
   _cin(a)
   for (int i=0;i<n;i++){
      dfs(a[n-1]);
      if (cur == n-i)cout << "YES\n";
      else cout << "NO\n";
      close[a[i]] = true;
      fill(all(vis),false);
      cur = 0;
   }
}
int32_t main() {
    IOS;
    int _=1;
    ///setIO("closing");
    //cin>>_;
    for(int tc=1;tc<=_;tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }

}
