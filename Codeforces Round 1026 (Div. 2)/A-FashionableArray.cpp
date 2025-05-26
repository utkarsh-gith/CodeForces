#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fun(vector<int>& input, int l, int h){
    if(l >= h){
        return 0;
    }
    if((input[l] + input[h]) % 2 == 0){
        return 0;
    }

    return min(fun(input, l + 1, h), fun(input, l, h - 1)) + 1;
}

int main() {

    int n;
    cin >> n;

    vector<int> res;

    for(int i = 0;i < n; i++){
        int k;
        cin >> k;

        vector<int> input(k);

        for(int j = 0;j < k; j++){
            cin >> input[j];
        }

        sort(input.begin(), input.end());

        res.push_back(fun(input, 0, k - 1));
    }

    for(int& r : res){
        cout<<r<<endl;
    }

    return 0;
}