#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store item info
struct Item {
    int value;
    int weight;
};

// 1. Greedy Approach (based on value/weight ratio)
double knapsackGreedy(vector<Item> items, int W) {
    vector<pair<double, int>> ratioIndex; // ratio, index
    for (int i = 0; i < items.size(); i++) {
        double ratio = (double)items[i].value / items[i].weight;
        ratioIndex.push_back({ratio, i});
    }

    sort(ratioIndex.rbegin(), ratioIndex.rend()); // sort descending by ratio

    int remaining = W;
    double totalValue = 0.0;

    for (auto &p : ratioIndex) {
        int idx = p.second;
        if (items[idx].weight <= remaining) {
            totalValue += items[idx].value;
            remaining -= items[idx].weight;
        }
    }
    return totalValue;
}

// 2. Dynamic Programming Approach
int knapsackDP(vector<Item> items, int W) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (items[i-1].weight <= w)
                dp[i][w] = max(items[i-1].value + dp[i-1][w - items[i-1].weight], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}

// 3. Backtracking Approach
int knapsackBacktrack(vector<Item> &items, int W, int index = 0, int currentWeight = 0, int currentValue = 0, int &maxValue = *(new int(0))) {
    if (index == items.size()) {
        if (currentValue > maxValue) maxValue = currentValue;
        return maxValue;
    }

    // Exclude current item
    knapsackBacktrack(items, W, index + 1, currentWeight, currentValue, maxValue);

    // Include current item if it doesn't exceed capacity
    if (currentWeight + items[index].weight <= W) {
        knapsackBacktrack(items, W, index + 1, currentWeight + items[index].weight, currentValue + items[index].value, maxValue);
    }

    return maxValue;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    vector<Item> items(n);

    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    double greedyResult = knapsackGreedy(items, W);
    int dpResult = knapsackDP(items, W);
    int maxBacktrack = 0;
    int backtrackResult = knapsackBacktrack(items, W, 0, 0, 0, maxBacktrack);

    cout << "\nResults:\n";
    cout << "Greedy Approach Value: " << greedyResult << endl;
    cout << "Dynamic Programming Value: " << dpResult << endl;
    cout << "Backtracking Approach Value: " << backtrackResult << endl;

    return 0;
}