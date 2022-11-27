#include "FlightFinder.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>       /* cos */

#define PI 3.14159265

void FlightFinder::read_in_file(){
  //vertcies/workspaces/cs225/Final Project/airports.dat
  std::ifstream file("/../airports.dat");
  for(std::string line; std::getline(file, line); line=""){
    //int comma_count= 0;
    std::vector <std::string> vect;
    SplitString(line, ',', vect);
    int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields);
    if (vect.at(3).compare("United States")==0 && vect.at(4).compare("") != 0){
      g_.insertVertex(Vertex(vect.at(4)));
      coords[vect.at(4)] = std::pair<double, double> (std::stod(vect.at(6)), std::stod(vect.at(7)));
    }

  }
  //edges
  std::ifstream file2("/../routes.dat");
  for(std::string line; std::getline(file2, line); line=""){
    std::vector <std::string> vect;
    SplitString(line, ',', vect);
    Vertex orgin(vect.at(2));
    Vertex dest(vect.at(4));
    if(g_.vertexExists(orgin) && g_.vertexExists(dest)){
      g_.insertEdge(orgin, dest);
      double weight= calculate_weights(orgin, dest); 
      g_.setEdgeWeight(orgin, dest, weight);
      
    }
  }
}
double FlightFinder::calculate_weights(Vertex orgin, Vertex dest) {
  double a = coords[orgin].first * PI / 180.0; // lat 1
  double b = coords[dest].first * PI / 180.0; // lat 2
  double x = coords[orgin].second * PI / 180.0; // long 1
  double y = coords[dest].second * PI / 180.0; // long 2
  double r = 6371.009; // radius in km   
  double d = r * acos(cos(a) * cos(b) * cos(x - y) + sin(a) * sin(b));
  return d;
}

//return true if greater than the number inputted exist 
bool FlightFinder::test_number_of_vertices(int num){
  if (g_.getVertices().size()>=num){
    return true;
  }
  return false;
}

//return true if  number ov vertices for a given vertex is equal to num and false otherwise
bool FlightFinder::test_number_of_edges_on_vertex(Vertex v, int num){
  if(g_.getAdjacent(v).size()==num){
    return true;
  }
  return false;
}

//returns true if vertex exists
bool FlightFinder::test_vertex_existance(Vertex v){
  return g_.vertexExists(v);
}

//returns true if edge exists
bool FlightFinder::test_edge_exists(Vertex o, Vertex d){
  return g_.edgeExists(o,d);
}
