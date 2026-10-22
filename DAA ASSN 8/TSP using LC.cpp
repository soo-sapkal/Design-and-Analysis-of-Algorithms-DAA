/*
 * Name: Soham Sapkal
 * PRN: 124B1F047
 */

#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

const double INF = 1e15;

// Node in the state space tree for branch and bound
struct Node
{
    vector<int> path;
    vector<int> visited;
    double cost;
    double bound;
};

// Comparator for min-heap priority queue based on lower bound
struct CompareNode
{
    bool operator()(const Node &a, const Node &b) const
    {
        return a.bound > b.bound;
    }
};

// Compute lower bound for remaining tour from the current state
double lowerBound(const Node &node,
                  const vector< vector<double> > &dist,
                  const vector<double> &minOut,
                  int n)
{
    double bound = node.cost;
    int current = node.path[node.path.size() - 1];

    // Minimum outgoing cost from the current city.
    bound += minOut[current];

    // Minimum outgoing cost from every unvisited city.
    for (int i = 0; i < n; i++)
    {
        if (!node.visited[i])
        {
            bound += minOut[i];
        }
    }

    return bound;
}

int main()
{
    int n, i, j;

    cout << "Enter number of cities: ";
    cin >> n;

    if (n < 2)
    {
        cout << "At least 2 cities are required.\n";
        return 0;
    }

    vector< vector<double> > dist(
        n, vector<double>(n, -1)
    );

    cout << "Enter distance/cost matrix (-1 for no route):\n";

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> dist[i][j];

            if (i == j)
            {
                dist[i][j] = -1;
            }
            else if (dist[i][j] < -1)
            {
                cout << "Invalid edge cost.\n";
                return 0;
            }
        }
    }

    // Find the minimum outgoing edge cost for each city.
    vector<double> minOut(n, INF);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j && dist[i][j] >= 0)
            {
                if (dist[i][j] < minOut[i])
                {
                    minOut[i] = dist[i][j];
                }
            }
        }

        if (minOut[i] == INF)
        {
            cout << "No complete tour is possible.\n";
            return 0;
        }
    }

    // Initialize priority queue and root node at city 0
    priority_queue<Node, vector<Node>, CompareNode> pq;

    Node start;
    start.path.push_back(0);
    start.visited.assign(n, 0);
    start.visited[0] = 1;
    start.cost = 0;
    start.bound = lowerBound(start, dist, minOut, n);

    pq.push(start);

    double bestCost = INF;
    vector<int> bestPath;

    // Explore state space tree using Least Cost Branch and Bound
    while (!pq.empty())
    {
        Node current = pq.top();
        pq.pop();

        if (current.bound >= bestCost)
        {
            continue;
        }

        int last = current.path[current.path.size() - 1];

        // All cities visited: return to the starting city.
        if ((int)current.path.size() == n)
        {
            if (dist[last][0] >= 0)
            {
                double totalCost = current.cost + dist[last][0];

                if (totalCost < bestCost)
                {
                    bestCost = totalCost;
                    bestPath = current.path;
                    bestPath.push_back(0);
                }
            }

            continue;
        }

        // Expand the current partial route.
        for (i = 0; i < n; i++)
        {
            if (!current.visited[i] && dist[last][i] >= 0)
            {
                Node child = current;

                child.path.push_back(i);
                child.visited[i] = 1;
                child.cost = current.cost + dist[last][i];

                // Prune routes already more expensive than best.
                if (child.cost >= bestCost)
                {
                    continue;
                }

                child.bound = lowerBound(child, dist, minOut, n);

                if (child.bound < bestCost)
                {
                    pq.push(child);
                }
            }
        }
    }

    cout << fixed << setprecision(2);

    if (bestPath.empty())
    {
        cout << "\nNo complete tour is possible.\n";
    }
    else
    {
        cout << "\nOptimal delivery route: ";

        for (i = 0; i < (int)bestPath.size(); i++)
        {
            cout << bestPath[i];

            if (i < (int)bestPath.size() - 1)
            {
                cout << " -> ";
            }
        }

        cout << "\nMinimum total cost: " << bestCost << "\n";
    }

    return 0;
}

