#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <list>


using namespace std;
const int imax = std::numeric_limits<int>::max();  //imax declared as the max value for int (in C++)


void add_edge(vector<vector<int>> adj, int a, int b) {
    adj[a][b] = 1;
    adj[b][a] = 1;
}


void dfs(int n, vector<vector<int>> adj, int si, int ei, vector<vector<int>> paths)
{
    vector<int> distance(n, imax);
    vector<int> path;
    queue<int> q; q.push(si); distance[si] = 0;

    while (!q.empty()) {
        auto curr = q.front(); q.pop();

        for (int i = 0; i < (int)adj[curr].size(); ++i) {
            if (distance[i] == imax) {
                distance[i] = distance[curr] + 1;
                //save the parent to have the path at the end of the algo.
                path[i] = curr;
            }
        }
    }
    /* t can be anything you want */
    int t = 5;
    paths.push_back(path);
                                                                                        // не понимаю эту часть - что такое t
}                                                                                       // может быть t это ei ? типа конец пути

void find_closest_gate(int e, vector<vector<int>> paths)
{
    int index = 0; // индекс пути к ближайшему гейту
    int min = paths[0].size();
    for (int j = 0; j < e; j++) {
        if (paths[j].size() < min) { min = paths[j].size(); index = j; }
    }
    // блокируем ребро от текущего положения вируса до следующего в сторону короткого пути
    cout << paths[index][0] << " " << paths[index][1] << endl;
}


int main()
{
    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    cin >> n >> l >> e; cin.ignore();

    // list<int> adj_list[n];  //create an array of lists whose size is n
    vector<vector<int>> adj(n);

    for (int i = 0; i < l; i++) {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;
        cin >> n1 >> n2; cin.ignore();

        add_edge(adj, n1, n2);
    }

    vector<int> gateway(e);
    for (int i = 0; i < e; i++) {
        int ei; // the index of a gateway node
        cin >> ei; cin.ignore();
        gateway[i] = ei;
    }


    // game loop
    while (1) {
        int si; // The index of the node on which the Bobnet agent is positioned this turn
        cin >> si; cin.ignore();

        vector<vector<int>> paths;

        // вызов ф-ии, пррсчитывающей кратчайший путь до каждого из гейтов на каждое движение вируса
        for (int i = 0; i < e; i++) {
            dfs(n, adj, si, gateway[i], paths);
        }
        
        
        // далее делаем так, что блокируется путь от текущей точки в сторону кратчайшего пути
        if (e != 1) {
            find_closest_gate(e, paths);
        }
        
        
        // и удаляем этот путь из всех доступных нам, чтоб функция его больше не учитывала

    }

}
