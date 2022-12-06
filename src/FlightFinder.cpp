#include "FlightFinder.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h> /* cos */

#define PI 3.14159265

using namespace std;

void FlightFinder::read_in_file()
{
  read_in_file("../airports.dat", "../routes.dat");
}

void FlightFinder::read_in_file(std::string airportfile, std::string routefile)
{
  std::ifstream file(airportfile);
  for (std::string line; std::getline(file, line); line = "")
  {
    std::vector<std::string> vect;
    SplitString(line, ',', vect);
    if (vect.at(3).compare("\"United States\"") == 0 && vect.at(4).compare("\\N") != 0)
    {
      vect.at(4) = vect.at(4).substr(1, vect.at(4).length() - 2);
      g_.insertVertex(Vertex(vect.at(4)));
      coords[vect.at(4)] = std::pair<double, double>(std::stod(vect.at(6)), std::stod(vect.at(7)));
    }
  }
  // edges
  std::ifstream file2(routefile);
  for (std::string line; std::getline(file2, line); line = "")
  {
    std::vector<std::string> vect;
    SplitString(line, ',', vect);
    Vertex orgin(vect.at(2));
    Vertex dest(vect.at(4));
    if (g_.vertexExists(orgin) && g_.vertexExists(dest))
    {
      g_.insertEdge(orgin, dest);
      double weight = calculate_weights(orgin, dest);
      g_.setEdgeWeight(orgin, dest, weight);
    }
  }
}
double FlightFinder::calculate_weights(Vertex orgin, Vertex dest)
{
  double a = coords[orgin].first * PI / 180.0;  // lat 1
  double b = coords[dest].first * PI / 180.0;   // lat 2
  double x = coords[orgin].second * PI / 180.0; // long 1
  double y = coords[dest].second * PI / 180.0;  // long 2
  double r = 6371.009;                          // radius in km
  double d = r * acos(cos(a) * cos(b) * cos(x - y) + sin(a) * sin(b));
  return d;
}

// return true if greater than the number inputted exist
bool FlightFinder::test_number_of_vertices(unsigned num)
{
  if (g_.getVertices().size() >= num)
  {
    return true;
  }
  return false;
}

// return true if  number ov vertices for a given vertex is equal to num and false otherwise
bool FlightFinder::test_number_of_edges_on_vertex(Vertex v, unsigned num)
{
  if (g_.getAdjacent(v).size() == num)
  {
    return true;
  }
  return false;
}

// returns true if vertex exists
bool FlightFinder::test_vertex_existance(Vertex v)
{
  return g_.vertexExists(v);
}

// returns true if edge exists
bool FlightFinder::test_edge_exists(Vertex o, Vertex d)
{
  return g_.edgeExists(o, d);
}

double FlightFinder::edge_weight(Vertex o, Vertex d)
{
  return g_.getEdgeWeight(o, d);
}
// std::vector<std::string> FlightFinder::destinations(Vertex o) {
//   return g_.getAdjacent(o);
// }

bool FlightFinder::BFS(std::string origin, std::string destination)
{

  if (origin == destination)
  {
    return true;
  }

  map<Vertex, bool> map;

  for (const Vertex &v : g_.getVertices())
  {
    map[v] = false;
  }

  // Create a queue for BFS
  std::queue<string> q;

  map[origin] = true;
  q.push(origin);

  while (!q.empty())
  {
    // Deq a vertex from q and print it
    origin = q.front();
    q.pop();

    // Get all adjacent vertices of the dequeued vertex s
    // If a adjacent has not been visited, then mark it visited
    // and enqueue it

    vector<Vertex> adj = g_.getAdjacent(origin);
    for (auto vertices : adj)
    {
      // If this adjacent node is the destination node, then
      // return true
      if (vertices == destination)
      {
        return true;
      }

      // Else, continue to do BFS
      if (!map[vertices])
      {
        map[vertices] = true;
        q.push(vertices);
      }
    }
  }

  // If BFS is complete without visiting destination
  return false;
}
std::vector<std::string> FlightFinder::a_star(std::string origin, std::string destination)
{
  vector<Vertex> openSet;
  openSet.push_back(origin);

  vector<Vertex> closedSet;

  map<Vertex, Vertex> cameFrom;

  map<Vertex, double> g_Score;

  for (auto keys : coords)
  {
    g_Score[keys.first] = std::numeric_limits<double>::max();
  }

  g_Score[origin] = 0;

  map<Vertex, double> f_Score;

  for (auto keys : coords)
  {
    f_Score[keys.first] = std::numeric_limits<double>::max();
  }

  f_Score[origin] = calculate_weights(origin, destination);

  double tentative_g_Score;

  while (!openSet.empty())
  {

    Vertex current = openSet[0];

    for (size_t i = 0; i < openSet.size(); ++i)
    {
      if (f_Score[openSet[i]] < f_Score[current])
      {
        current = openSet[i];
      }
    }

    if (current == destination)
    {
      return ReconstructPath(cameFrom, current, g_Score[current]);
    }

    // openSet should remove current
    openSet.erase(find(openSet.begin(), openSet.end(), current));
    closedSet.push_back(current);

    vector<Vertex> neighbors = g_.getAdjacent(current);

    for (auto neighbor : neighbors)
    {
      if (std::find(closedSet.begin(), closedSet.end(), neighbor) != closedSet.end())
      {
        continue;
      }
      else
      {
        tentative_g_Score = g_Score[current] + g_.getEdgeWeight(current, neighbor);
      }

      if ((!(std::find(openSet.begin(), openSet.end(), neighbor) != openSet.end())) || tentative_g_Score <= g_Score[neighbor])
      {
        cameFrom[neighbor] = current;
        g_Score[neighbor] = tentative_g_Score;
        f_Score[neighbor] = g_Score[neighbor] + calculate_weights(neighbor, destination);

        if ((!(std::find(openSet.begin(), openSet.end(), neighbor) != openSet.end())))
        {
          openSet.push_back(neighbor);
        }
      }
    }
  }
  return vector<Vertex>();
}
std::vector<std::string> FlightFinder::ReconstructPath(std::map<Vertex, Vertex> previous, Vertex curr, double distance)
{
  std::vector<std::string> path;
  path.push_back(curr);
  while (previous[curr].compare("") != 0)
  {
    curr = previous[curr];
    path.insert(path.begin(), curr);
  }
  path.push_back(to_string(distance));
  return path;
}

vector<string> FlightFinder::floyd_warshall(string origin, double distance)
{
  // make a map to index through dist matrix using ints instead of vertex names
  unsigned v = g_.getVertices().size();
  
  std::vector<Vertex> vertices;
  std::vector<Vertex> all_vertices = g_.getVertices();
  for (size_t i=0; i<all_vertices.size(); i++){
    if(g_.getAdjacent(all_vertices.at(i)).size() >40){
      vertices.push_back(all_vertices.at(i));
    }
  }
  // string path[v][v];
  // vector<vector<string>> dist(v, vector<string>(v, 0));

  vector<vector<double>> next(v, std::vector<double>(v, -1));
  vector<vector<double>> dp(v, std::vector<double>(v, -1));

  for (unsigned i = 0; i < v; i++)
  {
    for (unsigned j = 0; j < v; j++)
    {
      if (g_.edgeExists(vertices[i], vertices[j]))
      {
        next[i][j] = j;
        dp[i][j] = g_.getEdgeWeight(vertices[i], vertices[j]);
      }
    }
  }

  int count = 0;
  for (unsigned k = 0; k < v; k++)
  {
    for (unsigned i = 0; i < v; i++)
    {
      for (unsigned j = 0; j < v; j++)
      {
        if (dp[i][k] + dp[k][j] < dp[i][j])
        {
          dp[i][j] = dp[i][k] + dp[k][j];
          next[i][j] = next[i][k];
          count++;
          std::cout << count << endl;
        }
      }
    }
  }

  // use pair
  vector<std::pair<double, Vertex>> destinations;
  unsigned int find = std::find(vertices.begin(), vertices.end(), origin) - vertices.begin();

  vector<Vertex> final;
  for (unsigned i = 0; i < v; i++)
  {
    destinations.push_back(std::pair<double, Vertex>(dp[find][i], vertices.at(i)));
  }

  sort(destinations.begin(), destinations.end());

  // while (!destinations.empty())
  //{
  // for (int i=0; i<10; i++) {
  //   final.push_back(closest(destinations, distance));
  //   destinations;
  // }
  for (unsigned i = 0; i < destinations.size(); i++)
  {
    int countabove = 1;
    if (destinations[i].first > distance)
    {
      final.push_back(destinations[i].second);
      countabove--;
      if (countabove == 0)
        break;
    }
  }
  for (unsigned i = destinations.size() - 1; i >= 0; i--)
  {
    int countbelow = 1;
    if (destinations[i].first < distance)
    {
      final.push_back(destinations[i].second);
      countbelow--;
      if (countbelow == 0)
        break;
    }
  }
  //}

  return final;
}
