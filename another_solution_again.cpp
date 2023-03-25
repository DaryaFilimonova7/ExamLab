#include <iostream>
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


const shortestPathBfs = (si, ei) => {
  const previous = new Map();
  const visited = new Set();
  const queue = [];
  queue.push({ node: si, dist: 0 });
  visited.add(si);

  while (queue.length > 0) {
    const { node, dist } = queue.shift();
    if (node === stopNode) return { shortestDistande: dist, previous };

    for (let neighbour of adjacencyList.get(node)) {
      if (!visited.has(neighbour)) {
        previous.set(neighbour, node);
        queue.push({ node: neighbour, dist: dist + 1 });
        visited.add(neighbour);
      }
    }
  }
  return { shortestDistance: -1, previous };
};

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
