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
const int N = 101;
int n;
int ans = 1;
map<pair<int,int>,vector<pair<int,int>>>adj;
map<pair<int,int>,bool>vis,open;
bool turn(pair<int,int> a){
   return (a.fs>=0 && a.fs<=n && a.sc>=0 && a.sc<=n);
}
void dfs(pair<int,int>node){
   if (vis[node] || !open[node]|| !turn(node))return;
   vis[node] = true;
   //debugg(node.fs,node.sc)
   for (auto &i:adj[node]){
      if (!open[i]){
         //debugg(i.fs,i.sc)
         open[i] = true;
         ans++;
      }
      if (vis[{i.fs,i.sc+1}] || vis[{i.fs+1,i.sc}] || vis[{i.fs-1,i.sc}] || vis[{i.fs,i.sc-1}] ){
         dfs(i);
      }
   }
   dfs({node.fs,node.sc-1});
   dfs({node.fs,node.sc+1});
   dfs({node.fs-1,node.sc});
   dfs({node.fs+1,node.sc});
}
void solve(){
   // Think twice code once
   int m;cin >> n >> m;
   //bool close[n+1][n+1];
   for (int i=0;i<m;i++){
      pair<int,int>a,b;
      cin >> a.fs >> a.sc;
      cin >> b.fs >> b.sc;
      adj[a].pb(b);
   }
   open[{1,1}] = true;
   dfs({1,1});
   cout << ans;
}
int32_t main() {
    IOS;
    //freopen("lightson.in","r",stdin);
    //freopen("lightson.out","w",stdout);
    int _=1;
    //cin>>_;
    for(int tc=1;tc<=_;tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }
}
