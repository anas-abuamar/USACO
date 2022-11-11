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


#include<ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;


typedef tree<int,null_type,less<int>,rb_tree_tag,
   tree_order_statistics_node_update> indexed_set;

   vector<bool> visited(8);
vector<set<int>> adj(8);
vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
map<string,int> ind;

void dfs(int node){
	if(visited[node])return;
	visited[node]=true;
	cout << cows[node] << "\n";
	for(auto &x:adj[node])if(!visited[x])dfs(x);
}


void solve(){
	for(int i = 0;i<cows.size();i++)ind[cows[i]]=i;
	int n;
	cin >> n;
	for (int i = 0;i<n;i++){
		string a,b,c,d,e,f;
		cin >> a >> b >> c >> d >> e >> f;
		int x = ind[a],y=ind[f];
		adj[x].insert(y);
		adj[y].insert(x);
	}
	for (int i= 0 ;i <8;i++){
		if(!visited[i]&&adj[i].size()<2)dfs(i);
	}


}
int32_t main() {
    IOS;
    setIO("lineup");
    int _=1;
    //cin>>_;
    for(int tc=1;tc<=_;tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }

}
