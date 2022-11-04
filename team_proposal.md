## Leading Question 

Our leading question is to find the shortest path in terms of distance between two airports globally along with finding airports at a similar distance to offer the user comparative options to go to. This will be a general search tool for an inputted origin and destination airports and would output the shortest route from the origin to the destination along with similar distanced destinations. Data will be parsed from the chosen datasets and the BFS algorithm will be employed to check whether there is a valid route between two airports. Subsequently, the A* search algorithm will be used to efficiently search for the shortest path from the starting airport to the destination airport. We finally will give a list of suggested destinations in distance similar to the intended destination using Dijkstra’s algorithm (this will likely be 5 destinations in higher distance, and 5 below).

## Dataset Acquisition



## Data Format

The source data is openflights.org. It contains a list of 14000 airport data records around the world with latitude and longitude decimal data and corresponding airport specification codes. We would probably subset out all the airports without a three letter IATA code as well as only airports within the United States. We will also utilize the route data from the same website which is 2MB large and subset the data by checking if the origin and destination IATA codes are within the US by checking against the vertices we inputted from the airport data set. 


## Data Correction

We will parse through the data for airports line by line and check if there is a 3 letter IATA code and it is within the United States. If it is, then we will add the airport to the vertex list and create a subsequent edge list for it. We will then parse through the data for the routes line by line and check if the 3 digit IATA codes are within the airport vertex list and if both are, then we will add the adjacent vertices to the edge list. All data stored by the graph will be complete, and any data with missing entries would have been ignored and not entered into the graph data structure.

## Data Storage

We will be using a vector to store all the airport vertices as nodes that contain the 3 letter IATA code, the latitude, and longitude. For the routes it will be stored in an adjacency list that is in the form of a 2-D-vector where the first vector holds a vector in index i which stores the 3 letter IATA codes of airports that are connected by route to the airport in the airport vertex vector in index i where i is a index within the vector. We will then use maps to store the codes of the origin and the destination along with the distance between the two places. We estimate the total storage cost to be O(n) for each storage method.

## Algorithm 

Data will be parsed from the chosen datasets and the BFS algorithm will be employed to check whether there is a valid route between two airports. The input will be the graph created with aforementioned datasets, and the starting and ending points. The output will be a boolean value of the validity check. 
    Runtime will be O(n).
Subsequently, the A* search algorithm will be used to efficiently search for the shortest path from the starting airport to the destination airport. The expected inputs for the A* search algorithm are going to be the two IATA codes, which will be used to search the shortest distance between them. 
    Runtime will be O(n).
We finally will give a list of suggested destinations in distance similar to the intended destination using Dijkstra’s algorithm (this will likely be 5 destinations in higher distance, and 5 below). We will be giving the function the IATA codes for the origin and the destination and the distance between them, which will be calculated from the A* search function. 
    Output will be in text. To be specific, the return type A* search will be double and the return type of Djikstra’s function is going to be a vector of strings. 
    Runtime will be O(mlog(n) + nlog(n)).


## Timeline

    Nov 4th: Finish Team Contract and Project Proposal
    Nov 11th: Finish Data Parsing pipeline (loading data into vertices/edges/weights) (for Mid-check-in)
    Nov 18th: Finish BFS algorithm
    Nov 30th: Finish Dijkstra’s algorithm
    Dec 5th: Finish A* algorithm and formatted output for main
    Dec 8th: Ensure the project is bug free and turn it in! 🎉
