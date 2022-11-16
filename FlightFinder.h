#pragma once
#include "graph.h"
#include <vector>
#include <string>
#include <map>
#include "utils.h"

class FlightFinder{
    public:
    
    void read_in_file();
    void calculate_weights();
    //@return bool if the two places (vertices) are connected
    bool BFS(std::string orgin, std::string destination);
    //@return 5 closest lower distances and 5 closest huigher distances based on input
    std::vector<std::string> floyl_warshall(std::string orgin, double distance);
    //@return a vector containing the path of airports traveled to along with the distance attached as the last component of the vector
    std::vector <std::string> a_star(std::string orgin, std::string destination);
    
    private:
    Graph g_;
    std::map<std::string, std::pair<double,double>> coords;


};