#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
using namespace std;

void solve(set<int>& res, vector<bool>& check, int& sum, int idx, int& n){
    if(idx <= 0){
        res.insert(sum);
        return;
    }

    for(int i = 1;i <= n; i++){
        if(check[i] == true){
            continue;
        }

        check[i] = true;
        sum += abs(i - idx);
        solve(res, check, sum, idx - 1, n);
        sum -= abs(i - idx);
        check[i] = false;
    }
}

int main() {
    int n;
    cin >> n;

    set<int> res;
    vector<bool> check(n + 1, false);
    int sum = 0;

    for(int i = 1;i <= n; i++){
        check[i] = true;
        sum += abs(i - n);
        solve(res, check, sum, n - 1, n);
        sum -= abs(i - n);
        check[i] = false;
    }
    
    cout << res.size();

    return 0;
}