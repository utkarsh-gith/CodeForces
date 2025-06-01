#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> res;

    while(n--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        a = min(a, c);
        b = min(b, d);

        res.push_back(a < b ? "Flower" : "Gellyfish");
    }

    for(string r : res){
        cout << r << endl;
    }
    return 0;
}