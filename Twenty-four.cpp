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

const int inf = 1e9;
int calc(int op,int x,int y)
{
    if (op==0)
    {
        return x+y;
    }
    else if (op==1)
    {
        return x-y;
    }
    else if (op==2)
    {
        return x*y;
    }
    else
    {
        if (y==0 || x%y!=0)
        {
            return inf;
        }
        return x/y;
    }
    return inf;

}

void solve()
{
    int n = 4;
    vector<int>a(n);
    for (auto &i:a)cin >> i;
    sort(a.begin(),a.end());
    int ans = -1;
    auto run=[&]()
    {
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                for (int k=0; k<n; k++)
                {

                    int first = calc(i,a[0],a[1]);
                    if (first==inf)continue;
                    int second = calc(j,first,a[2]);
                    if (second==inf)continue;
                    int third = calc(k,second,a[3]);
                    if (third==inf)continue;
                    if (third <= 24)
                    {
                        ans = max(ans, third);
                    }
                }
            }
        }

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int first = calc(i, a[0], a[1]);
                    if (first == inf)
                    {
                        continue;
                    }

                    int second = calc(j, a[2], a[3]);
                    if (second == inf)
                    {
                        continue;
                    }

                    int third = calc(k, first, second);
                    if (third == inf)
                    {
                        continue;
                    }

                    if (third <= 24)
                    {
                        ans = max(ans, third);
                    }
                }
            }
        }



    };

    do
    {
        run();
    }
    while( next_permutation(a.begin(),a.end()));


    cout << ans << '\n';

}
int32_t main()
{
    IOS;
    int _=1;
    cin>>_;
    for(int tc=1; tc<=_; tc++)
    {
        // cout << "Case #" << tc << ": ";
        solve();
    }

}
