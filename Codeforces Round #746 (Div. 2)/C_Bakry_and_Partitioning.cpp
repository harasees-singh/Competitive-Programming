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
#define fps(x,y)                        fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

MOD_DEFINE

vector<vi> g;

int f;

int root;

vi prefXor;

void dfs(int i, int p){

        for(auto q : g[i])
                if(q != p)
                        dfs(q, i);
        

        for(auto q : g[i])
                if(q != p)
                        prefXor[i] ^= prefXor[q];

        

        if(prefXor[i] == root)
                f++, prefXor[i] = 0;

}

int32_t main(){
    FIO
    

    w(t){
            int n, k; cin >> n >> k;

            g = vector<vi>(n + 1);

            prefXor = vi(n + 1);

            l(i, 0, n){
                    cin >> prefXor[i + 1];
            }

            l(i, 0, n - 1){
                    int u, v; cin >> u >> v;

                    g[u].pb(v), g[v].pb(u);
            }
            f = 0;

            root = 0;

            for(auto p : prefXor)
                    root ^= p;

            dfs(1, 0);

            bool ok = 0;

            ok = (root == 0);

            if(ok){
                    cout << "YES" << endl; continue;
            }

            cout << ((k >= 3 and f >= 2) ? "YES" : "NO") << endl;
    }

}
