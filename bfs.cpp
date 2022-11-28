#include "bfs.h"

#include <queue>
#include <map>

using namespace std;

bool BFS(std::string origin, std::string destination)
{

    if (origin == destination)
    {
        return true;
    }

    // Mark all the vertices as not visited
    // bool *visited = new bool[V]; // where V is the graph size
    // for (int i = 0; i < V; i++)
    // {
    //     visited[i] = false;
    // }

    map<Vertex, bool> map;

    for (const Vertex &v : g_.getVertices())
    {
        map[v] = false;
    }


    // Create a queue for BFS
    queue<string> q;

    // Mark the current node as visited and enqueue it
    // visited[origin] = true;

    map[origin] = true;
    q.push(origin);

    // it will be used to get all adjacent vertices of a vertex
    // list<int>::iterator i;

    while (!q.empty())
    {
        // Deq a vertex from q and print it
        origin = q.front();
        q.pop();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it

        vector<Vertex> adj = g_.getAdjacent(origin);
        for (auto vertices: adj)
        {
            // If this adjacent node is the destination node, then
            // return true
            if (vertices == destination) {
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