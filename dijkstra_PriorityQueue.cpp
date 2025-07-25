#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
int N, M;
vector<vector<pair<int, int>>> graph;
vector<int> dist;
vector<int> parent;

void printPath(int node)
{
    if (parent[node] == -1)
    {
        cout << node;
        return;
    }
    printPath(parent[node]);
    cout << " -> " << node;
}

void dijkstra(int start)
{
    dist.assign(N + 1, INF);
    parent.assign(N + 1, -1);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // {dist, node}
    pq.push({ 0, start });

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (dist[curr] < cost) continue;

        for (auto& next : graph[curr])
        {
            int ed = next.first;
            int ed_dist = next.second;

            if (dist[ed] > dist[curr] + ed_dist)
            {
                dist[ed] = dist[curr] + ed_dist;
                pq.push({ dist[ed], ed });
                parent[ed] = curr;
            }
        }
    }
}

int main()
{

    cin >> N >> M;
    graph.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int st, ed, cost;
        cin >> st >> ed >> cost;
        graph[st].push_back({ ed, cost });
    }

    int start, end; cin >> start >> end;

    dijkstra(start);

    printPath(end);

    return 0;
}
