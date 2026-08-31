/*
 * Name: Soham Sapkal
 * PRN: 124B1F047
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

struct Item {
    string name;
    double weight;
    double value;
    double ratio;
    bool divisible;
};

// Comparator to sort items by value-to-weight ratio in descending order
bool compare(const Item& a, const Item& b) {
    return a.ratio > b.ratio;
}

int main() {
    vector<Item> items;

    Item item;

    item.name = "First Aid Kit";
    item.weight = 12;
    item.value = 210;
    item.divisible = false;
    items.push_back(item);

    item.name = "Canned Food";
    item.weight = 18;
    item.value = 135;
    item.divisible = true;
    items.push_back(item);

    item.name = "Water Bottles";
    item.weight = 25;
    item.value = 175;
    item.divisible = true;
    items.push_back(item);

    item.name = "Emergency Radio";
    item.weight = 8;
    item.value = 160;
    item.divisible = false;
    items.push_back(item);

    item.name = "Tents";
    item.weight = 30;
    item.value = 120;
    item.divisible = true;
    items.push_back(item);

    item.name = "Sanitation Kit";
    item.weight = 10;
    item.value = 140;
    item.divisible = false;
    items.push_back(item);

    double W = 55;

    // Calculate utility density (ratio = value / weight)
    for (int i = 0; i < (int)items.size(); i++) {
        items[i].ratio = items[i].value / items[i].weight;
    }

    // Greedy choice: sort items in descending order of utility ratio
    sort(items.begin(), items.end(), compare);

    double remainingWeight = W;
    double totalValue = 0;

    cout << "RELIEF SUPPLY SELECTION\n";
    cout << "-------------------------------------------------------------\n";

    cout << left
         << setw(20) << "Item"
         << setw(10) << "Weight"
         << setw(10) << "Value"
         << setw(10) << "Ratio"
         << setw(20) << "Selected"
         << endl;

    cout << "-------------------------------------------------------------\n";

    for (int i = 0; i < (int)items.size(); i++) {
        if (remainingWeight <= 0)
            break;

        // Take the complete item if capacity allows
        if (items[i].weight <= remainingWeight) {
            remainingWeight -= items[i].weight;
            totalValue += items[i].value;

            cout << left
                 << setw(20) << items[i].name
                 << setw(10) << items[i].weight
                 << setw(10) << items[i].value
                 << setw(10) << fixed << setprecision(2)
                 << items[i].ratio
                 << setw(20) << "Full item"
                 << endl;
        }
        // Take fractional part if item is divisible
        else if (items[i].divisible) {
            // But jar he asa kela tr soday lagtay,
            double fraction = remainingWeight / items[i].weight;
            double selectedValue = fraction * items[i].value;

            totalValue += selectedValue;

            cout << left
                 << setw(20) << items[i].name
                 << setw(10) << remainingWeight
                 << setw(10) << selectedValue
                 << setw(10) << fixed << setprecision(2)
                 << items[i].ratio
                 << setw(20) << "Fraction"
                 << endl;

            remainingWeight = 0; // Knapsack capacity reached
        }
        // Skip non-divisible item if it exceeds remaining capacity
        else {
            continue;
        }
    }

    cout << "-------------------------------------------------------------\n";

    cout << "Boat Capacity: "
         << W << " kg" << endl;

    cout << "Remaining Capacity: "
         << remainingWeight << " kg" << endl;

    cout << "Maximum Utility Value: "
         << fixed << setprecision(2)
         << totalValue << endl;

    return 0;
}
