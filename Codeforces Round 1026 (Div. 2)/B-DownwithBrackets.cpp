#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<string> res;

    for(int i=0;i < n;i++){
        
        string s;
        cin >> s;

        int ans = 0;
        int open = 0;

        for(char& c : s){
            if(c == '('){
                open++;
            }else if(c == ')'){
                open--;
            }

            if(open == 0){
                ans++;
            }
        }

        if(ans > 1){
            res.push_back("YES");
        }else{
            res.push_back("NO");
        }
        
    }

    for(string& s : res){
        cout << s << endl;
    }

    return 0;
}