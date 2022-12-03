## CS-225-Final-Project-BAJE

<b>GitHub Organization:</b>
  
 -The code created for this project is within the src folder. FlightFinder.h and FlightFinder.cpp are the two main files in which our functions are located in. Other files in the src folder are files pulled from the cs225 library. Within the entry folder is a main in which the code can be run from a user standpoint.
 
 -Tests are located in the tests folders with their being a file called tests_part1 which houses the tests for the data parsing, CalculateWeight, BFS algorithm, and A* algorithm. 

-The main data used is in the files airport.dat and routes.dat and is located in the main directory.

-The written report is in the main directory.

-The project presentation is in the main directory.


<b>Running Instructions:</b>

 -To run the code first change your directory to the main project direcory using the command "cd CS-225-Final-Project-BAJE-main" in the terminal. Then create a build folder using the command "mkdir build". Then change your directory to the build directory using the command "cd build" and run the "cmake .." command in the terrminal to create the makefiles for the project. From there you can then run either the main or tests using the command "./tests" or "./main" in the terminal. 
 
 -In FlightFinder is where we created all our functions. There is a a FlightFidner constructor that takes no parameters and gives no output. There are two readinfile() functions, one that takes in no parameters and does the data parsing of the airports and routes for the data from OpenFlights automatically. The second readinfile() takes in two file names, the first for the airports file name and the second for the route file name and can be used to input custom airports and routes. Both functions have no output. The calculate_weights() function takes in two Vertex's (std::strings) the first being an origin and the second being the destination and returns the calculated great circle distance as a double value. The BFS() function takes in two std::string (or Vertex) as the origin and destination respectivly and returns a bool if there is a path between the two Vertices and and both verticies exist in the graph. 
 
 -The tests created are meant to test every function with many different cases the functions should handle. For a more detailed description of what each test tests, please read the comments in the test_part1.cpp file located in the tests folder.
  
 -The main is the place for the code to be run from the user standpoint.
