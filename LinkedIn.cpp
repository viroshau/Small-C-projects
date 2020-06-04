//
//  LinkedIn.cpp
//  std_lib_facilities_mac
//
//  Created by Viroshaan Uthayamoorthy on 25/04/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "LinkedIn.hpp"

void Network::addEdge(string u, string v){
    edges[u].insert(v);
    if(symmetric){
        edges[v].insert(u);
    }
}

Network loadNetwork(string filename, bool symmetric){
    string line;
    ifstream InputFile(filename);
    Network nettverk{symmetric};
    if (!InputFile){
        throw "Failed to open file\n";
    }
    while (getline(InputFile, line)){
        stringstream ss(line);
        string node;
        string edge;
        ss>> node;
        nettverk.addNode(node);
        while (ss >> edge){
            nettverk.addEdge(node, edge);
        }
    }
    return nettverk;
}

void Network::addPath(vector<string> nodes){
    if (nodes.size() == 0){
        return;
    } else if (nodes.size() == 1){
        addNode(nodes[0]);
    }
    else{
        for(int i = 1; i < nodes.size(); ++i){
            addNode(nodes[i]);
            addEdge(nodes[i], nodes[i-1]);
        }
    }
}

Network Network::operator+(Network &rhs) {
    Network nettverk;
    nettverk.nodes = nodes;
    nettverk.nodes.insert(rhs.nodes.begin(),rhs.nodes.end());
    nettverk.edges = edges;
    for(auto p:rhs.edges){
        for(auto i:p.second){
            nettverk.addEdge(p.first, i);
        }
    }
    return nettverk;
}

int Network::distance(string from, string to){
    map<string, int> possiblepos = traverse(from);
    for (auto i: possiblepos){
        if (i.first == to){
            return i.second;
        }
    }
    return -1;
}

int Network::distance2(string from, string to) { //ANNEN MÅTE Å LØSE DET PÅ.
    map<string, int> dist = traverse(from);
    if (dist.find(to) == dist.end()) {
        return -1;
    }
    return dist[to];
}

float Network::avgPathLength(){
    double N = nodes.size();
    int sum = 0;
    map<string, int> dist;
    for (string n : nodes) {
        map<string, int> dist = traverse(n);
        for (pair<string, int> p : dist)
            sum += p.second;
    }
    return sum /(2*N*(N-1));
}
