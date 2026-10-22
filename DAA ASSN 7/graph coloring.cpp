/*
 * Name: Soham Sapkal
 * PRN: 124B1F047
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, e, i, j;

    cout << "Enter number of courses: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of courses.\n";
        return 0;
    }

    vector< vector<int> > adj(n);

    cout << "Enter number of course conflicts: ";
    cin >> e;

    if (e < 0)
    {
        cout << "Invalid number of conflicts.\n";
        return 0;
    }

    // Read conflicting course pairs to build conflict graph
    cout << "Enter conflicting course pairs (0-based IDs):\n";

    for (i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        if (u < 0 || u >= n || v < 0 || v >= n || u == v)
        {
            cout << "Invalid course pair.\n";
            return 0;
        }

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n, -1);
    vector<int> mark(n, -1);

    int maxColor = -1;

    // Assign time slots (colors) using Greedy Graph Coloring
    for (i = 0; i < n; i++)
    {
        // Mark colors already used by adjacent courses.
        for (j = 0; j < (int)adj[i].size(); j++)
        {
            int neighbor = adj[i][j];

            if (color[neighbor] != -1)
            {
                mark[color[neighbor]] = i;
            }
        }

        // Find the smallest available color.
        int c = 0;

        while (c < n && mark[c] == i)
        {
            c++;
        }

        color[i] = c;

        if (c > maxColor)
        {
            maxColor = c;
        }
    }

    // Display exam timetable grouped by time slots
    cout << "\nExam Timetable:\n";

    for (i = 0; i <= maxColor; i++)
    {
        cout << "Time Slot " << i + 1 << ": ";

        int first = 1;

        for (j = 0; j < n; j++)
        {
            if (color[j] == i)
            {
                if (first == 0)
                    cout << ", ";

                cout << "Course " << j;
                first = 0;
            }
        }

        cout << "\n";
    }

    cout << "\nTotal exam slots required: "
         << maxColor + 1 << "\n";

    return 0;
}

