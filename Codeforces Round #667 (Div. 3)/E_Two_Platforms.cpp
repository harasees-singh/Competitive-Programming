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
#define test_cases_loop                 int t; cin >> t; while(t--)
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

int32_t main(){
    FIO

    test_cases_loop{

        int n, k; cin >> n >> k;

        vi X(n);
        l(i, 0, n)
                cin >> X[i];
        int t;
        l(i, 0, n)
                cin >> t;
        
        sort(all(X));

        auto it = X.begin();

        int s1 = 0, s2 = 0;

        int maxi = 1;

        while((it + 1) != X.end()){

                auto i = lower_bound(all(X), *it - k);

                int temp = max(s1, it - i + 1ll);

                s1 = max(s1, temp);

                i = upper_bound(all(X), *(it + 1) + k);

                s2 = i - (it + 1);

                maxi = max(maxi, s1 + s2);

                it++;
        }
        cout << maxi << endl;
    }

}
