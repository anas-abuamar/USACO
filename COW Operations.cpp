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
   // 
   string s;cin >> s;
   int n = sz(s)+1;
   vector<int>C(n),W(n),O(n);
   n--;
   for (int i=0;i<n;i++){
      C[i+1]+= (s[i]=='C')+C[i];
      W[i+1]+= (s[i]=='W')+W[i];
      O[i+1]+= (s[i]=='O')+O[i];
   }
   int q;cin >> q;
   for (int i=0;i<q;i++){
      int l,r;cin >> l >> r;
      l--;
      int c = C[r]-C[l];
      int o = O[r]-O[l];
      int w = W[r]-W[l];
      if ( (c+o)%2==0 ||(c+w)%2==0) cout << "N";
      else cout << "Y";
   }
}
int32_t main() {
    IOS;
    int _=1;
    //cin>>_;
    for(int tc=1;tc<=_;tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }

}
