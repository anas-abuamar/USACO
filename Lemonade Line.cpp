/*
  USACO 2018 US Open Contest, Silver
  Problem 2. Lemonade Line
  http://www.usaco.org/index.php?page=viewproblem2&cpid=835
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
   // Think twice code once
   int n;cin >> n;
   vi a(n);
   _cin(a)
   int ans = 0 , cur = n-1;
   sort(all(a));
   for (int i=0;i<n;i++){
      if (a[i]>=(n-1-i)){
         ans++;
         ///debugg(i,a[i])
      }
   }
   cout << ans;
}

int32_t main() {
    IOS;
    ///setIO("lemonade");
   int _=1;
    //cin>>_;
    for(int tc=1;tc<=_;tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }

}
