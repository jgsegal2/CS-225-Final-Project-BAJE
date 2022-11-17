#include <fstream>
#include <string>
#include <math.h>       /* cos */

#define PI 3.14159265

void read_in_file(){
  //vertcies
  std::ifstream file(/../airports.dat);
  for(std::string line; std::getline(file, line); line=""){
    //int comma_count= 0;
    std::vector <std::string> vect;
    SplitString(line, ',', vect);
    int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields);
    if (vect.at(2).compare("United States")==0 && vect.at(3).compare("") != 0){
      g_.insertVertex(Vertex(vect.at(3)));
      coords[vect.at(3)] = std::pair<double, double> (std::stod(vect.at(5)), std::stod(vect.at(6)));
    }

  }
  //edges
  std::ifstream file2(/../routes.dat);
  for(std::string line; std::getline(file2, line); line=""){
    std::vector <std::string> vect;
    SplitString(line, ',', vect);
    Vertex orgin(vect.at(2);
    Vertex dest(vect.at(4));
    if(vertexExists(orgin) && vertexExists(dest)){
      g_.insertEdge(orgin, dest);
      double weight= calculate_weight(orgin, dest); //need to ask Benson to change function, seems most efficient to do this here in the initialization
      g_.setEdgeWeight(orgin, dest, weight);
      
    }
  }
}
// double calculate_weight(orgin, dest) {
//   double a = -6.081689834590001 * PI / 180.0; // lat 1
//   double b = -5.20707988739 * PI / 180.0; // long 1
//   double x = 145.391998291 * PI / 180.0; // lat 2
//   double y = 145.789001465 * PI / 180.0; // long 2
//   double r = 6378.1;

//   double param, result;
//   param = 60.0;
//   double d = r * acos(cos(a) * cos(b) * cos(x - y) + sin(a) * sin(b));
//   printf ("The great circle distance is %f km.\n", d );
//   return 0;
// }
