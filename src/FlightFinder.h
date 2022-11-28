#pragma once
#include "graph.h"
#include <vector>
#include <string>
#include <map>
#include <queue>
#include "utils.h"

class FlightFinder{
    public:
    
    FlightFinder(): g_(true, true) {};
    void read_in_file();
    double calculate_weights(Vertex orgin, Vertex dest);
    //@return bool if the two places (vertices) are connected
    bool BFS(std::string orgin, std::string destination);
    //@return 5 closest lower distances and 5 closest huigher distances based on input
    std::vector<std::string> floyd_warshall(std::string orgin, double distance);
    //@return a vector containing the path of airports traveled to along with the distance attached as the last component of the vector
    std::vector <std::string> a_star(std::string orgin, std::string destination);
    
    //Test functions
    //return true if greater than the number inputted exist 
    bool test_number_of_vertices(unsigned num);
    //return true if  number ov vertices for a given vertex is equal to num and false otherwise
    bool test_number_of_edges_on_vertex(Vertex v, unsigned num);
    //returns true if vertex exists
    bool test_vertex_existance(Vertex v);
    //returns true if edge exists
    bool test_edge_exists(Vertex o, Vertex d);

    private:
    Graph g_;
    std::map<std::string, std::pair<double,double>> coords;


};
