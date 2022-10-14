/*
USACO 2017 December Contest, Bronze
Problem 3. Milk Measurement
http://www.usaco.org/index.php?page=viewproblem2&cpid=761
  
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

struct str{
   int d;
   string name;
   int add;
}                                            ;
void solve(){
   int n;cin >> n;
   vector<str>days;
   for (int i=0;i<n;i++){
      int d,add;
      string name;char sign;
      cin >> d >> name >> sign >> add;
      if (sign=='-')add*=-1;
      days.pb({d,name,add});
   }
   sort(days.begin(),days.end(),[](str a,str b){
         return a.d<b.d;
        });
   int ans = 0;
   map<string,int>upd;
   vector<string>cow = {"Bessie","Mildred","Elsie"};
   for (int i=0;i<3;i++){
      upd[cow[i]] = 7;
   }
   set<string>cur = {all(cow)};
   auto ok=[&](){
      set<string>tmp;
      int mx = 0;
      for (int i=0;i<3;i++){
         mx = max(mx,upd[cow[i]]);
      }
      for (int i=0;i<3;i++){
         if (upd[cow[i]]==mx){
            tmp.insert(cow[i]);
         }
      }
      if (cur!=tmp){
         cur = tmp;
         ans++;
      }


   };
   for (auto day:days){
      upd[day.name] += day.add;
      ok();
   }
   cout << ans << '\n';
}
int32_t main() {
    IOS;
    setIO("measurement");
    int _=1;
    //cin>>_;
    for(int tc=1;tc<=_;tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }

}
