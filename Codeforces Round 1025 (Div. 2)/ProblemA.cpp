#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<string> res;

    for(int i = 0;i < n; i++){
        int m;
        cin >> m;

        int zeroCount = 0;
        bool fair = true;

        int prev;
        int curr;
        cin >> prev;

        if(prev == 0){
            zeroCount++;
        }

        for(int j = 0; j < m - 1; j++){
            cin >> curr;
            if(prev == 0 && curr == 0){
                fair = false;
            }else if(curr == 0){
                zeroCount++;
            }
            prev = curr;
        }

        if(zeroCount == 0){
            fair = false;
        }

        if(fair){
            res.push_back("NO");
        }else{
            res.push_back("YES");
        }
    }

    for(string& r : res){
        cout<<r<<endl;
    }

    return 0;
}