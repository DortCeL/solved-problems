#include <bits/stdc++.h>
using namespace std;

// A structure to represent an item in the knapsack
struct Item {
    int weight;
    int value;

    // Constructor
    Item(int w, int v) : weight(w), value(v) {}
};

// Comparison function to sort items by value-to-weight ratio
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items by value-to-weight ratio in decreasing order
    sort(items.begin(), items.end(), cmp);

    int n = items.size();
    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        // If the current item can fit in the knapsack, take it all
        if (items[i].weight <= W) {
            W -= items[i].weight;
            totalValue += items[i].value;
        }
        // If the current item can't fit, take the fraction that can fit
        else {
            totalValue += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    vector<Item> sack;
    sack.push_back(Item(2, 3));
    sack.push_back(Item(3, 4));
    sack.push_back(Item(4, 5));
    sack.push_back(Item(5, 6));

    int W = 5; // Maximum weight of knapsack

    double maxValue = fractionalKnapsack(W, sack);

    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
