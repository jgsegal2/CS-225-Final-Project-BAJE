#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "FlightFinder.h"

int main(int argc, char* argv[]) {
    FlightFinder obj;
    obj.read_in_file();
    if(argc != 3){
        std::cout<< "Not the correct number of arguments. Only list two 3-letter digit IATA airport codes for the origin and destination."<<std::endl;
        return -1;
    }
    bool valid = obj.BFS(argv[1], argv[2]);
    if (!valid){
        std::cout << "The airports you entered are either invlaid entries or don't have routes between them. Please enter another set of valid 3-digit capitalized IATA airport codes within the US."<<std::endl;
        return -1;
    }
    std::vector<std::string> astar_result = obj.a_star(argv[1], argv[2]);
    double distance= stod(astar_result.at(astar_result.size()-1));
    astar_result.pop_back();
    std::cout<< "The following route is the shortest path to your destination:"<<std::endl;
    for (unsigned i = 0; i < astar_result.size(); i++) {
        std::cout << astar_result[i];
        if (i < astar_result.size() - 1) {
            std::cout << " -> ";
        }
    }
    
    std::cout<<"\n"<<std::endl;
    std::cout<<"10 Alternative Destinations at Similar Distances (in shortest to longest order) are:"<<std::endl;
    std::vector<Vertex> dests= obj.floyd_warshall(argv[1], distance, 40, 5);
    for(size_t i=0; i<dests.size();i++){
        std::cout<< dests.at(i) << std::endl;
    }
    
    return -1;
}
