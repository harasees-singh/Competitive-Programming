// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        8999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back((n))
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(t)                            int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x, y)                       fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE
vi fire;
bool good(int tot, int drop){
        int need = 0;

        for(int i = (drop - 1); i >= 0; i--){
                need = max(need, max(0ll, fire[i] + (drop - i - 1)));
        }

        return (need <= tot);
}

int32_t main(){
        
        FIO

        w(t){
                int n, m, a, b; cin >> n >> m >> a >> b;

                fire = vi(m);

                for(auto &p : fire) cin >> p;

                sort(all(fire));

                int beg = 1, end = min(abs(a - b) - 1, m); 

                int time = (a < b ? b - 2 : n - b - 1);

                // cout << time << endl;

                while(beg <= end){
                        int mid = (beg + end)/2;

                        if(good(time, mid)) beg = mid + 1;

                        else end = mid - 1;
                }
                cout << end << endl;
        }

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/