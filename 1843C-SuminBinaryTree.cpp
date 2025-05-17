#include <iostream>
#include <vector>
using namespace std;

long long findSum(long long n){
    long long sum = n;
    while(n > 1){
        n /= 2;
        sum += n;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;

    vector<long long> res;

    for(int i = 0; i < n; i++){
        long long node;
        cin >> node;
        res.push_back(findSum(node));
    }

    for(long long r : res){
        cout << r << endl;
    }

    return 0;
}