#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "FlightFinder.h"

int main() {
    FlightFinder obj;
    obj.read_in_file();
    std::cout << obj.BFS("LAX","CMI") << std::endl;
    std::vector<std::string> astar_result = obj.a_star("LAX", "CMI");
    for (unsigned i = 0; i < astar_result.size(); i++) {
        std::cout << astar_result[i];
        if (i < astar_result.size() - 1) {
            std::cout << " -> ";
        }
    }
    
    return -1;
}
