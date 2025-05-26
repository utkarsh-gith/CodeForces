#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<bool> check(n, true);
    vector<pair<int, int>> res(n);

    for(int i = 0;i < n; i++){
        int k;
        cin >> k;

        int rt = sqrt(k);
        if(rt * rt != k){
            check[i] = false;
        }else{
            int l = rt / 2;
            int r;
            if(rt % 2 == 0){
                r = l;
            }else{
                r = l + 1;
            }
            res[i] = {l, r};
        }
    }

    for(int i = 0;i < n; i++){
        if(check[i]){
            cout<<res[i].first<<" "<<res[i].second<<endl;
        }else{
            cout<<"-1"<<endl;
        }
    }

    return 0;
}