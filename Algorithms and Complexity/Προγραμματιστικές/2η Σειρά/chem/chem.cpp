#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

long long calculateTotalEnergy(const vector<vector<long long>> &prefixSum, int start, int end) {
    long long total = 0;
    for (int i = start; i <= end; ++i) {
        total += prefixSum[i][end];
    }
    return total;
}

int main() {
    int numSubstances, numVials;        // N, K
    cin >> numSubstances >> numVials;

    vector<vector<int>> energy(numSubstances, vector<int>(numSubstances, 0));       // A[i, j]
    for (int i = 0; i < numSubstances - 1; ++i) {
        for (int j = 0; j < numSubstances - i - 1; ++j) {
            cin >> energy[i][i + j + 1];
            energy[i + j + 1][i] = energy[i][i + j + 1];
        }
    }

    vector<vector<long long>> prefixSum(numSubstances, vector<long long>(numSubstances, 0));
    for (int i = 0; i < numSubstances; ++i) {
        for (int j = i; j < numSubstances; ++j) {
            prefixSum[i][j] = energy[i][j] + (j > i ? prefixSum[i][j - 1] : 0);
        }
    }

    vector<vector<long long>> minEnergy(numSubstances, vector<long long>(numVials + 1, 100000));

    vector<vector<long long>> precomputedEnergy(numSubstances, vector<long long>(numSubstances, 0));
    for (int i = 0; i < numSubstances; ++i) {
        for (int j = i; j < numSubstances; ++j) {
            precomputedEnergy[i][j] = calculateTotalEnergy(prefixSum, i, j);
        }
    }

    for (int i = 0; i < numSubstances; ++i) {
        minEnergy[i][1] = precomputedEnergy[0][i];
    }

    for (int vialsUsed = 2; vialsUsed <= numVials; ++vialsUsed) {
        vector<long long> dp(numSubstances, 100000);  
        for (int i = 0; i < numSubstances; ++i) {
            for (int k = 0; k < i; ++k) {
                dp[i] = min(dp[i], minEnergy[k][vialsUsed - 1] + precomputedEnergy[k + 1][i]);
            }
        }
        for (int i = 0; i < numSubstances; ++i) {
            minEnergy[i][vialsUsed] = dp[i];
        }
    }

    cout << minEnergy[numSubstances - 1][numVials] << endl;

    return 0;
}
