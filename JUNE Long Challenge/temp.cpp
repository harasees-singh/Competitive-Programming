#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
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
#define umii unordered map<int, int>
#define test_cases_loop int t; cin >> t; while(t--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(var, initial, final) for(int var=initial; var < final; var++)
using namespace std;
void dfs(vector<vi> &tree, int node, int parent){
    if(tree[node].size()==1 And node!=1){
        cout << "found 3 " << node << endl;
        return;
    }
    cout << "where we at " << node << endl;
    loop(i, 0, tree[node].size()){
        if(tree[node][i] != parent){
            dfs(tree, tree[node][i], node);
        }
    }
    return;
}
int32_t main(){
    int n, k; cin >> n >> k;
    vi depth_vector(n+1);
    vector<vi> tree(n+1, vector<int>());
    loop(i, 0, n-1){
        int parent, child; cin >> parent >> child;
        tree[parent].pb(child); tree[child].pb(parent);
        
    }
    // cout << tree[1][0] << endl;
    dfs(tree, 1, 0);
    cout << sz(tree[3]) << endl;
}