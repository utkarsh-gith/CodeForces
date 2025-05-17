#include <iostream>
#include <vector>
using namespace std;

int daysCount(int n, int a, int b, int c){
    int cycle = a + b + c;
    int full_days = (n / cycle) * 3;
    int remaining = n % cycle;

    if (remaining > 0) {
        if (remaining <= a) full_days += 1;
        else if (remaining <= a + b) full_days += 2;
        else full_days += 3;
    }

    return full_days;   
}

int main() {
    int n;
    cin >> n;

    vector<int> res;

    for(int i = 0;i < n; i++){
        int m , a, b, c;
        cin >> m >> a >> b >> c;
        res.push_back(daysCount(m, a, b, c));
    }

    for(int r : res){
        cout<<r<<endl;
    }
}