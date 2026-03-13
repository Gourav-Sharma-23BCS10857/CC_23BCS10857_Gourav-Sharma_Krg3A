#include <bits/stdc++.h>
using namespace std;

int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());

    int left = 0;
    int right = tokens.size() - 1;

    int score = 0;
    int maxScore = 0;

    while(left <= right) {

        if(power >= tokens[left]) {
            power -= tokens[left];
            score++;
            left++;
            maxScore = max(maxScore, score);
        }

        else if(score > 0) {
            power += tokens[right];
            score--;
            right--;
        }

        else break;
    }

    return maxScore;
}

int main() {

    vector<int> tokens = {100, 200};
    int power = 150;

    cout << bagOfTokensScore(tokens, power);

    return 0;
}