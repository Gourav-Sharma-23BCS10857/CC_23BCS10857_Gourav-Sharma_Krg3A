#include<bits/stdc++.h>
using namespace std;
int Grid_path(int i, int j,vector<vector<int>>&dp){
    if(i==0 && j==0){
        return 1;
    }
    if(i<0||j<0){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int left=Grid_path(i,j-1,dp);
    int right=Grid_path(i-1,j,dp);
    return dp[i][j]=right+left;
}
int main(){
    int i,j;
    cin>>i>>j;
    vector<vector<int>>dp(i,vector<int>(j,-1));
    cout<<Grid_path(i-1,j-1,dp);
}