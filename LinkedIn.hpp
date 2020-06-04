//
//  LinkedIn.hpp
//  std_lib_facilities_mac
//
//  Created by Viroshaan Uthayamoorthy on 25/04/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#ifndef LinkedIn_hpp
#define LinkedIn_hpp

#include <stdio.h>
#include "std_lib_facilities.h"

#endif /* LinkedIn_hpp */

class Network {
private:
    // Set of nodes, each node is identified by a string
    set<string> nodes;
    // Map of edges for each node, i.e. edges[n] is a set of node n's neighbors
    map<string, set<string>> edges;
    // Whether the network is symmetric or asymmetric
    bool symmetric;
public:
    Network(bool symmetric = true) : nodes(), edges(), symmetric(symmetric) {}
    void addNode(string n) { nodes.insert(n); }
    void addEdge(string u, string v);
    void addPath(vector<string> ns);
    Network operator+(Network &rhs);
    map<string, int> traverse(string start);
    int distance(string from, string to);
    float avgPathLength();
    int Network::distance2(string from, string to);
};

Network loadNetwork(string filename, bool symmetric);
