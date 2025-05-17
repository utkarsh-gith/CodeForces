#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> connection(n - 1);
    for(int i = 0;i < n - 1; i++){
        cin >> connection[i];
    }

    stack<int> st;
    st.push(n);

    while(st.top() != 1){
        st.push(connection[n - 2]);
        n = st.top();
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}