/*
 * Name: Soham Sapkal
 * PRN: 124B1F047
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <functional>

using namespace std;

// Dijkstra's algorithm to find shortest paths from source vertex
void dijkstra(int source,
              vector< vector< pair<int, int> > >& graph,
              vector<int>& dist) {
    int V = graph.size();

    dist.assign(V, INT_MAX);
    dist[source] = 0;

    // Min-priority queue storing {distance, vertex}
    priority_queue<
        pair<int, int>,
        vector< pair<int, int> >,
        greater< pair<int, int> >
    > pq;

    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Ignore stale distance entries
        if (d > dist[u])
            continue;

        // Relax adjacent neighbors
        for (int i = 0; i < (int)graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    int V, E;

    cout << "Enter number of intersections (vertices): ";
    cin >> V;

    cout << "Enter number of roads (edges): ";
    cin >> E;

    vector< vector< pair<int, int> > > graph;
    graph.resize(V);

    cout << "\nEnter edges (u v w):\n";
    cout << "u = starting node, v = ending node, w = travel time\n\n";

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // Undirected edge representing bidirectional road
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    int source;
    cout << "\nEnter ambulance start location (source): ";
    cin >> source;

    int H;
    cout << "Enter number of hospitals: ";
    cin >> H;

    vector<int> hospitals(H);
    cout << "Enter hospital nodes: ";
    for (int i = 0; i < H; i++) {
        cin >> hospitals[i];
    }

    // Compute shortest travel times from ambulance location
    vector<int> dist;
    dijkstra(source, graph, dist);

    int minTime = INT_MAX;
    int nearestHospital = -1;

    // Identify nearest hospital based on minimum distance
    for (int i = 0; i < H; i++) {
        int h = hospitals[i];

        if (dist[h] < minTime) {
            minTime = dist[h];
            nearestHospital = h;
        }
    }

    if (nearestHospital == -1 || minTime == INT_MAX) {
        cout << "\nNo hospital reachable.\n";
    } else {
        cout << "\nNearest hospital is at node "
             << nearestHospital
             << " with travel time "
             << minTime
             << " minutes.\n";
    }

    return 0;
}
