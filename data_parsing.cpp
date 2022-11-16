#include <fstream>
#include <string>

void read_in_file(){
  std::ifstream file(/../airports.dat);
  for(std::string line; std::getline(file, line); line=""){
    //int comma_count= 0;
    std::string location;
    std::string latitude;
    std:string longitude;
    std::vector <std::string> vect;
    
    for(int i=0; i<line.size(); i++){
      char on= line.at(i);
      if (on==','){
        comma_count++;
      }else{
        //if country is US
      //if(comma_count == // location number){
      // location.push_back(on)
      //}
      //if(comma_count == // lat number){
      // latitude.push_back(on)
      //}
      //if(comma_count == // long number){
      // longitude.push_back(on)
      //}
      }
    }

    double lat_d=std::stod(latitude);
    double long_d=std::stod(longitude);
    //need to figure out where to store these (variable) //want to use graph from lab with slight modifications (need to talk to team)
  }
}
