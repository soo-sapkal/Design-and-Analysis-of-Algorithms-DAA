/*
 * Name: Soham Sapkal
 * PRN: 124B1F047
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

// Structure to represent a directed edge between stages
struct Edge
{
    int u, v;
    double base_cost, cur_cost;
};

int main()
{
    // Read number of stages and nodes per stage
    int stages, i, j;

    cout << "Enter number of stages: ";
    cin >> stages;

    if (stages < 2)
    {
        cout << "Number of stages must be at least 2.\n";
        return 0;
    }

    vector<int> stageCount(stages);
    vector<int> stageOf;
    int N = 0;

    cout << "Enter number of nodes in each stage ("
         << stages << " values): ";

    for (i = 0; i < stages; i++)
    {
        cin >> stageCount[i];

        if (stageCount[i] <= 0)
        {
            cout << "Each stage must contain at least one node.\n";
            return 0;
        }

        for (j = 0; j < stageCount[i]; j++)
        {
            stageOf.push_back(i);
            N++;
        }
    }

    // Read directed edges connecting nodes to later stages
    int E;
    cout << "Enter number of edges: ";
    cin >> E;

    if (E < 0)
    {
        cout << "Invalid number of edges.\n";
        return 0;
    }

    vector<Edge> edges;
    vector< vector<int> > adj(N);
    vector< vector<int> > rev_adj(N);

    cout << "Enter each edge as: u v cost\n";

    for (i = 0; i < E; i++)
    {
        Edge e;

        cin >> e.u >> e.v >> e.base_cost;

        if (e.u < 0 || e.u >= N ||
            e.v < 0 || e.v >= N)
        {
            cout << "Invalid node ID.\n";
            return 0;
        }

        if (stageOf[e.u] >= stageOf[e.v])
        {
            cout << "Invalid edge: edges must go to a later stage.\n";
            return 0;
        }

        if (e.base_cost < 0)
        {
            cout << "Edge costs must be non-negative.\n";
            return 0;
        }

        e.cur_cost = e.base_cost;

        edges.push_back(e);

        int index = (int)edges.size() - 1;

        adj[e.u].push_back(index);
        rev_adj[e.v].push_back(index);
    }

    const double INF = numeric_limits<double>::max();

    vector<double> best_cost(N);
    vector<int> next_node(N);

    // Calculate shortest costs backward through the stages.
    // Every node in the final stage has cost zero to itself.

    for (i = 0; i < N; i++)
    {
        best_cost[i] = INF;
        next_node[i] = -1;
    }

    int lastStart = N - stageCount[stages - 1];

    for (i = lastStart; i < N; i++)
    {
        best_cost[i] = 0;
    }

    // Dynamic programming from the last stage to Stage 0.

    for (int s = stages - 2; s >= 0; s--)
    {
        int start = 0;

        for (i = 0; i < s; i++)
        {
            start += stageCount[i];
        }

        int end = start + stageCount[s];

        for (int u = start; u < end; u++)
        {
            for (j = 0; j < (int)adj[u].size(); j++)
            {
                int index = adj[u][j];
                int v = edges[index].v;

                if (best_cost[v] != INF)
                {
                    double candidate =
                        edges[index].cur_cost + best_cost[v];

                    if (candidate < best_cost[u])
                    {
                        best_cost[u] = candidate;
                        next_node[u] = v;
                    }
                }
            }
        }
    }

    cout << fixed << setprecision(6);

    cout << "\nBest costs from Stage-0 nodes:\n";

    for (i = 0; i < stageCount[0]; i++)
    {
        cout << "Node " << i << ": cost = ";

        if (best_cost[i] == INF)
            cout << "Unreachable\n";
        else
            cout << best_cost[i] << "\n";
    }

    // Reconstruct and display shortest path from chosen source node
    int source;

    cout << "\nEnter a source node id (in stage 0) to print path, "
         << "or -1 to skip: ";
    cin >> source;

    if (source != -1)
    {
        if (source < 0 || source >= N ||
            stageOf[source] != 0)
        {
            cout << "Invalid source node.\n";
        }
        else if (best_cost[source] == INF)
        {
            cout << "Destination is unreachable from "
                 << source << ".\n";
        }
        else
        {
            cout << "Path from " << source << " : ";

            int current = source;
            cout << current;

            while (next_node[current] != -1)
            {
                current = next_node[current];
                cout << " -> " << current;
            }

            cout << "\nTotal route cost (sum edges): "
                 << best_cost[source] << "\n";
        }
    }

    // Apply live dynamic updates to edge costs
    int updates;

    cout << "\nEnter number of live updates to edge costs "
         << "(0 to finish): ";
    cin >> updates;

    for (int update = 0; update < updates; update++)
    {
        int u, v;
        double multiplier;

        cout << "Enter edge update (u v multiplier): ";
        cin >> u >> v >> multiplier;

        if (u < 0 || u >= N ||
            v < 0 || v >= N || multiplier < 0)
        {
            cout << "Invalid update. Skipping.\n";
            continue;
        }

        int found = 0;

        for (i = 0; i < (int)edges.size(); i++)
        {
            if (edges[i].u == u && edges[i].v == v)
            {
                edges[i].cur_cost =
                    edges[i].base_cost * multiplier;

                found = 1;
            }
        }

        if (!found)
        {
            cout << "Edge not found. Update skipped.\n";
        }
    }

    if (updates > 0)
    {
        // Recalculate all best costs after the updates.

        for (i = 0; i < N; i++)
        {
            best_cost[i] = INF;
            next_node[i] = -1;
        }

        for (i = lastStart; i < N; i++)
        {
            best_cost[i] = 0;
        }

        for (int s = stages - 2; s >= 0; s--)
        {
            int start = 0;

            for (i = 0; i < s; i++)
            {
                start += stageCount[i];
            }

            int end = start + stageCount[s];

            for (int u = start; u < end; u++)
            {
                for (j = 0; j < (int)adj[u].size(); j++)
                {
                    int index = adj[u][j];
                    int v = edges[index].v;

                    if (best_cost[v] != INF)
                    {
                        double candidate =
                            edges[index].cur_cost + best_cost[v];

                        if (candidate < best_cost[u])
                        {
                            best_cost[u] = candidate;
                            next_node[u] = v;
                        }
                    }
                }
            }
        }

        cout << "\nAfter updates, best costs from Stage-0 nodes:\n";

        for (i = 0; i < stageCount[0]; i++)
        {
            cout << "Node " << i << ": cost = ";

            if (best_cost[i] == INF)
                cout << "Unreachable\n";
            else
                cout << best_cost[i] << "\n";
        }
    }

    return 0;
}

