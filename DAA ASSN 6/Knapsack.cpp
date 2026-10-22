/*
 * Name: Soham Sapkal
 * PRN: 124B1F047
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int N, W, i, j;

    cout << "Enter number of items: ";
    cin >> N;

    cout << "Enter truck capacity (kg): ";
    cin >> W;

    if (N <= 0 || W < 0)
    {
        cout << "Invalid input.\n";
        return 0;
    }

    vector<int> weight(N);
    vector<int> value(N);
    vector< vector<int> > dp(
        N + 1, vector<int>(W + 1, 0)
    );

    // Read weight and utility value for each item
    cout << "Enter weight and utility value of each item:\n";

    for (i = 0; i < N; i++)
    {
        cout << "Item " << i + 1 << ": ";
        cin >> weight[i] >> value[i];

        if (weight[i] <= 0 || value[i] < 0)
        {
            cout << "Invalid weight or utility value.\n";
            return 0;
        }
    }

    // Build the DP table (0/1 Knapsack)
    for (i = 1; i <= N; i++)
    {
        for (j = 0; j <= W; j++)
        {
            // Do not select the current item.
            dp[i][j] = dp[i - 1][j];

            // Select the item if it fits.
            if (weight[i - 1] <= j)
            {
                int newValue =
                    value[i - 1] +
                    dp[i - 1][j - weight[i - 1]];

                if (newValue > dp[i][j])
                {
                    dp[i][j] = newValue;
                }
            }
        }
    }

    cout << "\nMaximum total utility: "
         << dp[N][W] << "\n";

    // Backtrack to find items included in the optimal solution
    vector<int> selected;
    int remainingCapacity = W;

    for (i = N; i >= 1; i--)
    {
        if (dp[i][remainingCapacity] !=
            dp[i - 1][remainingCapacity])
        {
            selected.push_back(i - 1);
            remainingCapacity -= weight[i - 1];
        }
    }

    int totalWeight = 0;

    // Display selected items and capacity summary
    cout << "\nSelected items:\n";

    if (selected.size() == 0)
    {
        cout << "No items selected.\n";
    }

    for (i = (int)selected.size() - 1; i >= 0; i--)
    {
        int index = selected[i];

        cout << "Item " << index + 1
             << " - Weight: " << weight[index]
             << " kg, Utility: " << value[index]
             << "\n";

        totalWeight += weight[index];
    }

    cout << "\nTotal weight: " << totalWeight << " kg\n";
    cout << "Remaining capacity: "
         << W - totalWeight << " kg\n";

    return 0;
}

