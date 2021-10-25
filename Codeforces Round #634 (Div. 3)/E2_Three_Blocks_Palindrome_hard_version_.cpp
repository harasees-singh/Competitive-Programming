#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define space                           " "
// #define int                             long long
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
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

int cnt[200001][201];

vi order[201];

int32_t main(){
    FIO

        w(t){
                l(i, 1, 201)
                        order[i].clear();
                
                int n; cin >> n;

                l(i, 1, n + 1){

                        int t; cin >> t;

                        order[t].pb(i);

                        l(c, 1, 201)
                                cnt[i][c] = cnt[i - 1][c];

                        cnt[i][t]++;
                }
                int mex = 1;

                l(i, 1, 201){
                        
                        for(int k = 1; 2*k <= sz(order[i]); k++){
                                
                                int l = order[i][k - 1] + 1, r = order[i][sz(order[i]) - k] - 1;

                                int mid = 0;

                                l(c, 1, 201){
                                        mid = max(mid, cnt[r][c] - cnt[l - 1][c]);
                                }

                                mex = max(mex, mid + 2 * k);
                        }
                }

                cout << mex << endl;
        }
        return 0;

}
