#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    int reqsum=3;
    int cnt=0;
    int total = 1 << n; 

    for (int mask = 0; mask < total; mask++) {
        int currsum=0;
        cout << "{ ";
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                cout << arr[i] << " ";
                currsum+=arr[i];
            }
        }
        if(currsum==reqsum){
                    cnt++;
                }
        cout << "}" << endl;
    }
    cout<<cnt;

    return 0;
}