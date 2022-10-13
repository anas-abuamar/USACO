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
#define  int long long
#define  vi vector<int>
struct cow{
   int x,y,ind;
};
void solve(){
   int n;cin >> n;
   vector<cow>Ncows , Ecows;
   for (int i=0;i<n;i++){
      char d;
      int x,y;
      cin >> d >> x >> y;
      if (d=='N')Ncows.pb({x,y,i});
      else Ecows.pb({x,y,i});
   }

   sort(all(Ncows),[](cow &one,cow &two){
         return one.x<two.x;
   });
   sort(all(Ecows),[](cow &one,cow &two){
         return one.y<two.y;
   });
   vector<int>ans(n,-1);
   for (cow Acow : Ncows){
      for (cow Bcow:Ecows){
         if (Acow.x>Bcow.x && Acow.y<Bcow.y){
            int Ndif = Bcow.y-Acow.y;
            int Edif = Acow.x-Bcow.x;

            if (Edif > Ndif && ans[Bcow.ind]==-1){
               ans[Bcow.ind] = Edif;
            }
            else if (Ndif > Edif && ans[Bcow.ind]==-1){
               ans[Acow.ind] = Ndif;
               break;
            }
         }
      }
   }
   for (int i=0;i<n;i++){
      if (ans[i]== -1){
         cout << "Infinity\n";
      }
      else {
         cout << ans[i] << '\n';
      }
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
