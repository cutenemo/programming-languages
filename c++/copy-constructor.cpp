//
//  main.cpp
//  copy constructor
//  ugh not really a good example
//
//  Created by Fatima B on 10/31/15.
//  Copyright © 2015 nemo. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <sstream>
#include <time.h>

class Graph {
public:
    int nvertices; // a graph of nvertices
    std::list<int> *adj;
    std::vector<std::pair<int,int>> edges;
    std::vector<bool> active;
    Graph(int v) {
        nvertices = v;
        adj = new std::list<int>[v + 1];
        for (int i = 0; i <= nvertices; i++) {
            active.push_back(true);
        }
    }

    Graph(const Graph& g) { // copy constructor
        nvertices = g.nvertices;
        adj = new std::list<int>[g.nvertices + 1];
        edges.insert(edges.end(), g.edges.begin(), g.edges.end());
        for (int i = 1; i <= nvertices; i++) {
            adj[i].insert(adj[i].end(), g.adj[i].begin(), g.adj[i].end());
        }
        for (int i = 0; i <= nvertices; i++) {
            active.push_back(g.active[i]);
        }
    }

    void insert_edge(int v, int u) {
        adj[v].push_back(u);
        edges.push_back(std::make_pair(v, u));
    }

    void remove_edge(int v, int u) {
        adj[v].remove(u);
        edges.erase(std::remove(edges.begin(), edges.end(),
                                std::make_pair(v, u)), edges.end());
    }

    void print() {
        for (int i = 1; i <= nvertices; i++) {
            if (!active[i]) {
                continue;
            }
            printf("%d: ", i);
            std::list<int> l = adj[i];
            for (auto i = l.begin(); i != l.end(); i++) {
                printf("%d ", *i);
            }
            printf("\n");
        }
        printf("\n");
    }
};

int main() {
    Graph g(4);
    g.insert_edge(1, 2);
    g.insert_edge(2, 1);
    g.insert_edge(3, 4);
    g.insert_edge(4, 3);

    Graph s(g);
    s.remove_edge(1, 2);
    s.remove_edge(2, 1);

    g.print();
    s.print();
    return 0;
}
