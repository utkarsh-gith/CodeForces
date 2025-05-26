#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main () {
    int a;
    cin >> a;

    vector<string> res(a);

    for(int i = 0; i < a; i++) {
        int n, k;
        cin >> n >> k;

        string str;
        cin >> str;

        int zeroGood = 0;
        int oneGood = 0;
        int bad = 0;

        for(int x = 0;x < n/2; x++){
            if(str[x] == '0' && str[n - x - 1] == '0'){
                zeroGood++;
            } else if(str[x] == '1' && str[n - x - 1] == '1'){
                oneGood++;
            } else {
                bad++;
            }
        }

        if(zeroGood + oneGood == k){
            res[i] = "YES";
        } else if(zeroGood + oneGood > k){
            if(zeroGood == 0 || oneGood == 0){
                res[i] = "NO";
            }else if((zeroGood + oneGood - k) % 2 != 0){
                res[i] = "NO";
            }
            else{
                int z = min(zeroGood, oneGood) * 2;
                int y = zeroGood + oneGood - k;
                if(z - y >= 0){
                    res[i] = "YES";
                } else {
                    res[i] = "NO";
                }
            }
        } else {
            int z = k - zeroGood - oneGood;
            if(z % 2 != 0){
                res[i] = "NO";
            } else {
                if(bad >= z){
                    res[i] = "YES";
                } else {
                    res[i] = "NO";
                }
            }
        }
    }

    for(const string& r : res){
        cout << r << endl;
    }

    return 0;
}