#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Структура для хранения ребра 
struct Edge {
    int source, destination;
};




int main()
{
    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    cin >> n >> l >> e; cin.ignore();

    vector<Edge> edges;

    for (int i = 0; i < l; i++) {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;
        // cin >> n1 >> n2; cin.ignore(); // способ ввода, который дан изначально
        
        cin >> edges[i].source >> edges[i].destination; cin.ignore();
    
    }
    for (int i = 0; i < e; i++) {
        int ei; // the index of a gateway node
        cin >> ei; cin.ignore();
    }

    // game loop
    while (1) {
        int si; // The index of the node on which the Bobnet agent is positioned this turn
        cin >> si; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // Example: 0 1 are the indices of the nodes you wish to sever the link between
        

        /*
            hardcode for test 2 
            // cout << "0 2" << endl;
            // cout << "1 3" << endl;

        */
        
    }
    
}
