#pragma once
#include "graph.h"
#include <vector>
#include <string>
#include <map>
#include <queue>
#include "utils.h"
#include <limits>

class FlightFinder
{
public:
    FlightFinder() : g_(true, true){};
    void read_in_file();
    void read_in_file(std::string airportfile, std::string routefile);
    double calculate_weights(Vertex orgin, Vertex dest);
    //@return bool if the two places (vertices) are connected
    bool BFS(std::string orgin, std::string destination);
    //@return num_bound closest lower distances and num_bound closest higher distances based on input
    std::vector<std::string> floyd_warshall(std::string orgin, double distance, size_t edge_bound, size_t num_back);
    //@return a vector containing the path of airports traveled to along with the distance attached as the last component of the vector
    std::vector<std::string> a_star(std::string orgin, std::string destination);
    // Reconstruct path helper function for A*. Returns vector of stirngs
    std::vector<std::string> ReconstructPath(std::map<Vertex, Vertex> previous, Vertex curr, double distance);

    // Test functions
    // return true if greater than the number inputted exist
    bool test_number_of_vertices(unsigned num);
    // return true if  number ov vertices for a given vertex is equal to num and false otherwise
    bool test_number_of_edges_on_vertex(Vertex v, unsigned num);
    // returns true if vertex exists
    bool test_vertex_existance(Vertex v);
    // returns true if edge exists
    bool test_edge_exists(Vertex o, Vertex d);
    // return the weight of the edge
    double edge_weight(Vertex o, Vertex d);
    // //return adj list
    // std::vector<std::string> destinations(Vertex o);

private:
    Graph g_;
    std::map<std::string, std::pair<double, double>> coords;
};
