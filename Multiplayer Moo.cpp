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
const int N = 251;
int n;
int k =0;
bool vis[N][N];
int a[N][N];
int cur , cur2;
void rec(int i,int j,int val){
   if (!vis[i][j]){
      cur++;
      vis[i][j] = true;
      if (i>0 && a[i-1][j] == val ) rec (i-1,j,val);
      if (j>0 && a[i][j-1] == val ) rec (i,j-1,val);
      if (i+1<n && a[i+1][j] == val ) rec (i+1,j,val);
      if (j+1<n && a[i][j+1] == val ) rec (i,j+1,val);
   }

}

void rec2(int i,int j,int val,int val2){
   if (!vis[i][j] && (a[i][j]==val || a[i][j] == val2)){
      cur++;
      vis[i][j] = true;
      if (i>0 && (a[i-1][j]==val || a[i-1][j] == val2) ) rec2 (i-1,j,val,val2);
      if (j>0 && (a[i][j-1]==val || a[i][j-1] == val2) ) rec2 (i,j-1,val,val2);
      if (i+1<n && (a[i+1][j]==val || a[i+1][j] == val2) ) rec2 (i+1,j,val,val2);
      if (j+1<n && (a[i][j+1]==val || a[i][j+1] == val2)  ) rec2 (i,j+1,val,val2);
   }
}

void setIO(string name = "") {if(sz(name)){freopen((name+".in").c_str(), "r", stdin);
                                            freopen((name+".out").c_str(), "w", stdout);}}

void solve(){
   // Think twice code once
   // Educational بسم الله الرحمن الرحيم
   cin >> n;
   for (int i=0;i<n;i++){
      for (int j=0;j<n;j++){
         cin >> a[i][j];
      }
   }
   int one = -1 , two = -1 ;
   for (int i=0;i<n;i++){
      for (int j=0;j<n;j++){
         cur = 0;
         if (!vis[i][j]){
            rec(i,j,a[i][j]);
            one = max(one,cur);

         }
      }
   }

   memset(vis,false,sizeof(vis));
   ///debugg(one,two)
   for (int i=1;i<n;i++){
      for (int j=1;j<n;j++){
         cur = 0;
         if (j>0 && a[i][j]!=a[i][j-1]){
            if (!vis[i][j]){
               rec2(i,j,a[i][j],a[i][j-1]);
               two = max(two,cur);
               if (cur>=n*n)break;
               memset(vis,false,sizeof(vis));
            }
         }
      }
   }
   ///debugg(one,two)
   cout << one << "\n" << two;
}
int32_t main() {
    IOS;
    ///setIO("multimoo");
    int _=1;
    //cin>>_;
    for(int tc=1;tc<=_;tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }

}
