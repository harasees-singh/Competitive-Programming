#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define test_cases_loop int t;          cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE

void Algo1(int n){
    if(n%2)
            cout << 1 << space << n/2 << space << n/2 << endl;
        else 
            if(n%4 == 0)
                cout << n/2 << space << n/4 << space << n/4 << endl;
            
            else 
                cout << 2 << space << (n - 2)/2 << space << (n - 2)/2 << endl;
}

int32_t main(){
    FIO 

    test_cases_loop{
        int n, k; 
        cin >> n >> k;
        // repeat algo 1 for n - k + 3; and k = 3;

        l(i, 0, k - 3)
                cout << 1 << space;
        
        Algo1(n - k + 3);
    }

    return 0;
}
