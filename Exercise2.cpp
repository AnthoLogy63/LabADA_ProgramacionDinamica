#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxIntercMEMO(const vector<int>& missiles, int index, vector<int>& memo) {
    if (memo[index] != -1)
        return memo[index];

    int maxNumIn = 1;
    for (int j = 0; j < index; ++j) {
        if (missiles[j] >= missiles[index])
            maxNumIn = max(maxNumIn, maxIntercMEMO(missiles, j, memo) + 1);
    }

    memo[index] = maxNumIn;
    return memo[index];
}

int main() {
    vector<vector<int>> testCases; 
    int height;

    while (cin >> height) {
        vector<int> missiles;
        
        while (height != -1) {
            missiles.push_back(height);
            cin >> height;
        }
        if (missiles.empty() && height == -1) 
            break;
        if (!missiles.empty()) 
            testCases.push_back(missiles);
    }

    int testCase = 1;
    int totalCases = testCases.size();
    for (const auto& missiles : testCases) {
        int n = missiles.size();
        vector<int> memo(n, -1);
        int numMmaxInterc = 0;

        for (int i = 0; i < n; ++i)
            numMmaxInterc = max(numMmaxInterc, maxIntercMEMO(missiles, i, memo));
        
        cout << "Test #" << testCase << ":\n";
        cout << "  maximum possible interceptions: " << numMmaxInterc << "\n";
        
        if (testCase != totalCases)
            cout << "\n";
        testCase++;
    }
    return 0;
}