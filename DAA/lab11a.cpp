#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};

bool cmp(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

int main() {
    Item items[] = {{60,10}, {100,20}, {120,30}};
    int n = 3, W = 50;
    
    sort(items, items + n, cmp);

    double totalProfit = 0;

    for(int i = 0; i < n; i++) {
        if(W >= items[i].weight) {
            totalProfit += items[i].value;
            W -= items[i].weight;
        } else {
            totalProfit += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }

    cout << "Maximum Profit: " << totalProfit;
}