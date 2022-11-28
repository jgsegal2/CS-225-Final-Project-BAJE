//Floyd Warshall
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

class fw {
  
  public:
  void floydWarshall(/*pass in graph*/);
  void solution(double path[V][V]);
  
  private:
  unsigned int dne = 99999;
  //unsigned int V = <- pull data from graph
  
}




