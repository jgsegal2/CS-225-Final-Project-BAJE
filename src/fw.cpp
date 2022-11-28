//Floyd Warshall
#include "fw.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

void fw::floydWarshall(/*pass in graph*/) {

double path[V][V];
for (unsigned int a=0; a<V; a++) {
  path[a][a] = 0.0;
}
  
for (unsigned int x=0; x<V; x++) {
  for (unsigned int y=0; y<V; y++) {
    if (x == y){
      path[x][y] = 0.0;
    }
    else {
      if (/*weight at x,y is NULL, meaning no direct flights) { //find a way to still get shortest path for non direct flights
        path[x][y] = dne;
      }
      path[x][y] = //<- pull from weights from graph
    }
  }
}
  
  
for (int k=1; k<=V; k++) {
      
        for (int i=1; i<=V; i++) {
          
            for (int j=1; j<=V; j++) {
              
                if (path[i][j] > (path[i][k] + path[k][j]) && (path[k][j] != dne && path[i][k] != dne)) {
                    path[i][j] = path[i][k] + path[k][j];
                }
            }
        }
} 

solution(path);   
}

void fw::solution(int path[V][V]) {
  cout << "This outputs shows the shortest path between all airport pairs using Floyd Warshall." << endl;
  for (unsigned int x=0; x<V; y++) {
    for (unsigned int y=0; y<V; y++) {
      cout << "The shortest flight from " << /*display name of airport x*/ << "to " << /*display name of airport y*/ << "is: ";
      if (path[x][y] == dne) {
        cout << "There are no direct flights." << endl;
      }
      else {
        cout << path[x][y] << endl;
      }
    }
  }
}
