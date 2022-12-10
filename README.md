## CS-225-Final-Project-BAJE

<b>GitHub Organization:</b>
  
 -The code created for this project is within the src folder. FlightFinder.h and FlightFinder.cpp are the two main files in which our functions are located in. Other files in the src folder are files pulled from the cs225 library. Within the entry folder is a main in which the code can be run from a user standpoint.
 
 -Tests are located in the tests folders with their being a file called tests_part1 which houses the tests for the data parsing, CalculateWeight, BFS algorithm, FLoyd-Warshall, and A* algorithm. 

-The main data used is in the files airport.dat and routes.dat and is located in the main directory.

-The written report is in the main directory called results.md.

-The project presentation is in the main directory called Presentation.mp4.


<b>Running Instructions:</b>

 -To run the code first change your directory to the main project directory using the command "cd CS-225-Final-Project-BAJE-main" in the terminal. Then create a build folder using the command "mkdir build". Then change your directory to the build directory using the command "cd build" and run the "cmake .." command in the terminal to create the makefiles for the project. From there you can then run either the main or tests using the command "./tests" or "./main" in the terminal. To run the main there need to be two string arguments inserted after the "./main" command that are 3-letter IATA airport codes for US airports with the first string input being the origin the user wants and the second being the destination the user wants.
 
 <i>Functions </i>
 
 -In FlightFinder is where we created all our functions. There is a a FlightFinder constructor that takes no parameters and gives no output. There are two readinfile() functions, one that takes in no parameters and does the data parsing of the airports and routes for the data from OpenFlights automatically. The second readinfile() takes in two file names, the first for the airports filename and the second for the route file name and can be used to input custom airports and routes. Both functions have no output. The calculate_weights() function takes in two Vertex types (std::strings) the first being an origin and the second being the destination and returns the calculated great circle distance as a double value. 
 
 -The BFS() function takes in two std::string (or Vertex) as the origin and destination respectively and returns a bool if there is a path between the two Vertices and and both vertices exist in the graph. 
 
 -The floyd_warshall() function takes in a std::string (or Vertex) first, a distance as a double value, a parameter called edge_bound which dictates the airports that will be subsetted from the full graph to be used in the algorithm, and a num_back which states half the number of airports that should be returned that are the closest to the distance it took from the origin to the destination airport with ideally an equal number above and below. The output will be a a vector of strings (std::vector<std::string>>) that contain the 5 closest lower distances and 5 closest higher distances based on the distance input in regards to the origin. 
 
 -The a_star() function takes in two std::string (or Vertex) types as the orgin and destination respectively and outputs a vector of strings (std::vector<std::string>) that contains a path from the origin to the destination and attached at the end of the vector is path distance. 
 
 -The ReconstructPath() function is a helper function for a_star which takes in a map of Vertex types which maps to Vertex types and a second parameter of a Vertex that is the current point. It outputs a vector of strings (std::vector<std::string>) that contains a path from the origin to the destination given in the a_star function. The rest of the functions in the class are for testing purposes only and should not be used by the user.
 
 <i>Tests </i>
 
 -The tests created are meant to test every function with many different cases the functions should handle. Tests for the data parsing test the number of vertices in the graph, the kind of vertices in the graph, and the proper edges exist. The BFS tests check that a specfic path exists or not. The calculate_weights tests check to ensure the weights are generally calculated right for an edge. The a_star algorithm tests check to ensure the right path is returned. And the Floyd-Warshall tests ensure the right airports are being returned for an inputted distance destination. For a more detailed description of what each test tests, please read the comments in the test_part1.cpp file located in the tests folder. The user can run the command "./test" to run our full test-suite.
  
  <i>Main </i>
  
 -The main is the place for the code to be run from the user standpoint. To run the main there need to be two string arguments inserted after the "./main" command that are 3-letter IATA airport codes for US airports with the first string input being the origin the user wants and the second being the destination the user wants. For example the terminal command of "./main CMI LAX" will run the main with an origin of Willard airport in Champaign, IL and a destination of Los Angeles International airport in Los Angeles. The main will not function properly and produce an error message if the user provides an invalid amount of arguments. The main will tell the user if an airport doesn't exist or if there are no routes between the origin and destination. If these error messages aren't produced then the main will output the pathway of airports from the origin to the destination. Then the 10 destinations that are at a similar distance will be printed out after the route is returned with the shorter routes at the top and longer routes closer to the bottom.
