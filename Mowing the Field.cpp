/*
USACO 2016 January Contest, Bronze
Problem 3. Mowing the Field
http://www.usaco.org/index.php?page=viewproblem2&cpid=593

*/

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

void solve(){
   int n;cin >> n;
   int x = 0, y = 0 , t = 0 , ans = 1e9;
   map<pair<int,int>,int>vis;
   for (int i=0;i<n;i++){
      char c;int k;
      cin >> c >> k;
      for (int j=0;j<k;j++){
               if (c=='N')y++;
               else if (c=='S')y--;
               else if (c=='E')x++;
               else x--;
               if ( vis.count({x,y}) ){
                  ans = min(ans , t-vis[{x,y}]);
               }
               vis[{x,y}] = t++;
      }
   }
   if (ans==1e9)ans = -1;
   cout << ans << '\n';
  /*
     int n;cin >> n;
   map<pair<int,int>,vector<int>>cor;
   int init = 0 , curt = 1;
   pair<int,int> inif = {0,0};
   map<pair<int,int>,int>vis;
   int ans =   1e9;
   for (int i=0;i<n;i++){
      char c;int x;
      cin >> c >> x;
      pair<int,int> add = {0,0};
      if (c=='N') add.sc++;
      else if (c=='S')add.sc--;
      else if (c=='E')add.fs++;
      else add.fs--;
      for (int j=1;j<=x;j++){
         inif.fs+=add.fs;
         inif.sc+=add.sc;
         ///debugg(curt,vis[inif])
         if (vis[inif] != 0){
            ans = min(ans , curt-vis[inif]);
         }
         vis[inif] = curt++;
         ///debugg(inif.fs,inif.sc)
      }
   }

   if (ans==1e9)ans = -1;
   cout << ans << '\n';

  
  
  */

}
int32_t main() {
    IOS;
    setIO("mowing");
    int _=1;
    //cin>>_;
    for(int tc=1;tc<=_;tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }

}
