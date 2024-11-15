#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool maxLuggageMEMO(const vector<int>& weights, int n, int maxW, unordered_map<int, unordered_map<int, bool>>& memo) {
    if (maxW == 0) return true;
    if (n == 0 || maxW < 0) return false;

    if (memo[n].find(maxW) != memo[n].end()) {
        return memo[n][maxW];
    }

    bool result = maxLuggageMEMO(weights, n - 1, maxW, memo);
    if (!result) {
        result = maxLuggageMEMO(weights, n - 1, maxW - weights[n - 1], memo);
    }

    memo[n][maxW] = result;
    return result;
}

int main() {
    int testCases; 
    cin >> testCases; 
    while (testCases--) {
        vector<int> weights;
        int weight, totalWeight = 0;
        while (cin >> weight) {
            weights.push_back(weight);
            totalWeight += weight;
            if (cin.peek() == '\n') break;
        }    
        if (totalWeight % 2 != 0) {
            cout << "NO" << endl;
        } else {
            int maxW = totalWeight / 2;
            unordered_map<int, unordered_map<int, bool>> memo; 
            if (maxLuggageMEMO(weights, weights.size(), maxW, memo))
                cout << "YES" << endl;
            else 
                cout << "NO" << endl;
        }
    }
    return 0;
}
