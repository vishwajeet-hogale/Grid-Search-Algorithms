#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph(
    {
        {1, 1, 1, 1, 1},
        {1, 0, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 1, 1},
        {1, 0, 1, 1, 1},
    });
bool isValid(pair<int, int> point)
{
    if (point.first < graph.size() && point.second < graph[0].size())
        if (graph[point.first][point.second] == 1)
            return true;
    return false;
}
void dfsGridSearch(vector<vector<int>> &graph, pair<int, int> start, pair<int, int> end, vector<pair<int, int>> &r, vector<vector<pair<int, int>>> &res, vector<vector<int>> &vis)
{
    if (!isValid(start))
    {
        return;
    }
    if (vis[start.first][start.second] == 1)
        return;
    if (start.first == end.first && start.second == end.second)
    {
        r.push_back(end);
        res.push_back(r);
        r.pop_back();
        return;
    }
    r.push_back(start);

    vis[start.first][start.second] = 1;
    if (isValid(make_pair(start.first + 1, start.second)) && !vis[start.first + 1][start.second])
        dfsGridSearch(graph, make_pair(start.first + 1, start.second), end, r, res, vis);
    if (isValid(make_pair(start.first - 1, start.second)) && !vis[start.first - 1][start.second])
        dfsGridSearch(graph, make_pair(start.first - 1, start.second), end, r, res, vis);
    if (isValid(make_pair(start.first, start.second - 1)) && !vis[start.first][start.second - 1])
        dfsGridSearch(graph, make_pair(start.first, start.second - 1), end, r, res, vis);
    if (isValid(make_pair(start.first, start.second + 1)) && !vis[start.first][start.second + 1])
        dfsGridSearch(graph, make_pair(start.first, start.second + 1), end, r, res, vis);
    vis[start.first][start.second] = 0;
    r.pop_back();
}
void printSolution(vector<vector<int>> &graph, int i, vector<pair<int, int>> solution)
{
    cout << "Solution " << i << "\n";
    vector<vector<char>> map(graph.size(), vector<char>(graph[0].size(), '.'));
    for (auto &x : solution)
        map[x.first][x.second] = '#';
    cout << endl;
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[0].size(); j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
}
void getDFSPaths(vector<vector<int>> &graph, pair<int, int> start, pair<int, int> end)
{
    vector<vector<pair<int, int>>> res;
    vector<pair<int, int>> r;
    vector<vector<int>> vis(graph.size(), vector<int>(graph[0].size(), 0));
    dfsGridSearch(graph, start, end, r, res, vis);
    int x = 0;
    for (vector<pair<int, int>> j : res)
    {
        printSolution(graph, x + 1, j);
        x++;
    }
}
int main()
{
    pair<int, int> start = make_pair(0, 1), end = make_pair(4, 3);
    getDFSPaths(graph, start, end);

    return 0;
}
