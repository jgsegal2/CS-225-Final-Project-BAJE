-Output and correctness of each algorithm: <i>  You should summarize, visualize, or highlight some part of the full-scale run of each algorithm. Additionally, the report should briefly describe what tests you performed to confirm that each algorithm was working as intended.</i>

There are two readinfile() functions, one that takes in no parameters and does the data parsing of the airports and routes for the data from OpenFlights automatically. The second readinfile() takes in two file names, the first for the airports file name and the second for the route file name and can be used to input custom airports and routes. Both functions have no output but do create the graph or airports and routes used in subsequent algorithms. Tests for the data parsing test the number of verticies in the graph, the kind of verticies in the graph, and the proper edges exist.

The BFS algorithm function takes in two strings/vertices and checks whether they are connected or not using the FIFO based queue strucuture and a map<Vertex, bool>. We looped through the neighbors of the given vertex and pushed them onto the queue while also storing their “bool values” on the map so as to ensure connectivity and not revisit the neighboring vertices. If we run the function  bool valid = (obj.BFS("BTI", "CMI")); (BarterIsland Alaska to Champign,IL) it will return 1 (or true). Similarly, for bool valid = (obj.BFS("LFI", "ORD")) (Langley Airforce Base in Hampton US to Chicago O'Hare), the function will return 0 or false) as there is no route from the Langley AirForce base, that is it has no connectivity. Our code passed all four different test cases we wrote specifically for the function.


The A* algorithm function takes two parameters which are origin and destination vertices respectively. When given an origin point and a destination airport, the algorithm is to find the shortest path between the two airports. The heuristic used in the calculation in the algorithm is also the great circle distance between the current point and destination, same as the calculation of edge weights. We also wrote a ReconstructPath function to do the back tracing once we found the connection with the destination point, which finally returns the vector of the airports on the shortest path. For testing the part, we both used the original graph as the data and created a smaller dataset consisting of 6 airports. For the small graph we created, we used precalculated shortest path routes and values of distance combined to be the expected result. For the original graph consisting of 1200 nodes, we chose the routes and the distances we already know. For example, we know that there are direct flights from LAX (Los Angeles International) to ORD (Chicago O’Hare), and CMI (Champaign Airport) is a small airport, so the shortest path from LAX to CMI is only LAX-ORD-CMI. Our code passed all four different test cases we wrote specifically for the function.

Our implementation of Floyd Warshall takes in four parameters. When used on a graph (test graph depiction here https://github.com/jgsegal2/CS-225-Final-Project-BAJE/blob/main/image.png), the function will only consider vertices with a minimum number of edges each, a value determined by edge_bound, one of the function parameters. All shortest path pairs between all vertices will be calculated characteristic to Floyd Warshall, but the origin parameter will determine which starting airports to filter out. The num_back parameter will return the closest num_back amount of destinations below the distance parameter and the closest num_back amount of destinations above the distance parameter. If we run the function with ("ORD", 1290.65, 0, 1), on the six vertex test map, with ORD being Chicago. Then the first return value will be a destination closer than 1290.65 km, and the second return value will be further than 1290.65. The former, Washington DC, is closer than all other aiports below 1290.65 km. The latter, NYC, is closer than all other aiports above 1290.65 km. Below are the output results from the terminal. However, the function itself returns a vector containing the three letter codes of the desired airports: {"IAD", "JFK"}. 


ORD to ORD Distance should be 0

ORD to IAD Distance should be 945.406

ORD to DFW Distance should be 1290.65

ORD to JFK Distance should be 1311.73

ORD to MCO Distance should be 2167.43

ORD to LAX Distance should be 3273.82

IAD:945.406

JFK:1187.84

-Answer to your leading question: <i> You should direct address your proposed leading question. How did you answer this question? What did you discover? If your project was ultimately unsuccessful, give a brief reflection about what worked and what you would do differently as a team. </i>

Our leading question being to find the shortest path in terms of distance between two airports US was answered using an A-Star algorithm to find the shortest path between these airports. Along with finding airports at a similar distance to offer the user comparative options to go to we utilized a Floyd-Warshall algorithm to do this. We discovered the connectivity of many of the cities along with utilzing varying data structures to get a relatively efficient code. We also learned how inefficient Floyd-Warshall is having an big-O of n^3 which forced to use a subset of vertices when finding our comparative distanced airports. Overall most of the project went smoothly though there was a rush at the end to finish the last algorithm due to peoples' schedules. If we could do it differently we would move things up in the schedule and hold group members to a higher account.
