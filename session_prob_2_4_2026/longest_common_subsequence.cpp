#include<bits/stdc++.h>
using namespace std;
int lcs(string &a, string &b,int i,int j){
if(i<0 || j<0) return 0;
if(a[i]==b[j]){
    return 1+lcs(a,b,i-1,j-1);
} 
return max(lcs(a,b,i-1,j),lcs(a,b,i,j-1));
}
int main(){
string a="abcde";
string b="bcdam";
vector<vector<int>>dp(a.size(),vector<int>(b.size()));
cout<<lcs(a,b,a.size()-1,b.size()-1);
return 0;
}



// #include<bits/stdc++.h>
// using namespace std;

// int lcs(string &a, string &b, int i, int j, vector<vector<int>> &dp){
//     if(i < 0 || j < 0) return 0;

//     if(dp[i][j] != -1) return dp[i][j];  // already computed

//     if(a[i] == b[j]){
//         return dp[i][j] = 1 + lcs(a, b, i-1, j-1, dp);
//     }

//     return dp[i][j] = max(
//         lcs(a, b, i-1, j, dp),
//         lcs(a, b, i, j-1, dp)
//     );
// }

// int main(){
//     string a = "abcde";
//     string b = "bcdam";

//     vector<vector<int>> dp(a.size(), vector<int>(b.size(), -1));

//     cout << lcs(a, b, a.size()-1, b.size()-1, dp);

//     return 0;
// }