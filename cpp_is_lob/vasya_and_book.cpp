#include<bits/stdc++.h>
#define infinity 999999999999999999
#define float long double
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define MOD_DEFINE const int MOD = 1e9 + 7;
#define And &&
#define Or ||
#define endl '\n'
#define space " "
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb(n) push_back(n)
#define mii map<int, int>
#define umii unordered_map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
#define cout std::cout
#define cin std::cin
#define safe_unordered_map(int, T) unordered_map<int, T, custom_hash>

using namespace std;
MOD_DEFINE
int32_t main(){
  FIO

  test_cases_loop{

        int n, x, y, d; cin >> n >> x >> y >> d;

        // if((y-x)%d==0){cout << (y-x)/d << endl; continue;}

        if((max(x, y) - min(x, y))%d==0){cout << (max(x, y) - min(x, y))/d << endl; continue;}

        int ans=infinity;

        if((y-1)%d==0){

            ans = ceil((x-1)/(float)d) + (y-1)/d;

        }

        if((n-y)%d==0){

            // ans = min(ans, ceil((n-y)/(float)d) + (n-y)/d);

            // ans=-1;

            int t = ceil((n-x)/(float)d) + (n-y)/d;

            ans = min(ans, t);
        }

        // if(ans<0)ans*=-1;

        cout << (ans==infinity ? -1 : ans) << endl;
  }
  
  return 0;
}
