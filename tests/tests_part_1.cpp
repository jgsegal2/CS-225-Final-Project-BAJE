#include <catch2/catch_test_macros.hpp>
//#include "tests_helper.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "FlightFinder.h"

using namespace std;

TEST_CASE("graph data parsing", "[part=1] [vertices] [edges]")
{
    FlightFinder obj;
    obj.read_in_file();
    // tests number of vertices in graph, should be 1,251 as 1,512 airports are in the US and 261 don't have 3-letter codes
    REQUIRE(obj.test_number_of_vertices(10));
    REQUIRE(obj.test_number_of_vertices(10000) == false);
    REQUIRE(obj.test_number_of_vertices(1200) == true);
    REQUIRE(obj.test_number_of_vertices(1300) == false);
    // Check that US airports exists as vertices
    REQUIRE(obj.test_vertex_existance("ORD")); // O'Hare Chicago
    REQUIRE(obj.test_vertex_existance("MFE")); // Mc Allen International Airport
    REQUIRE(obj.test_vertex_existance("CDB")); // Cold Bay airport
    REQUIRE(obj.test_vertex_existance("MDW")); // Midway Chicago
    REQUIRE(obj.test_vertex_existance("LAX")); // Los Angeles
    REQUIRE(obj.test_vertex_existance("SEA")); // Seatle US
    // vertex that don't exist
    REQUIRE(obj.test_vertex_existance("EDO") == false); // Balıkesir Körfez Airport Turkey
    REQUIRE(obj.test_vertex_existance("UAH") == false); // Ua Huka Airport French Polynisia
    REQUIRE(obj.test_vertex_existance("MAG") == false); // Madang Airpor Papaua New Guinea
    // Check edges exist
    REQUIRE(obj.test_edge_exists("ATL", "MDW") == true); // Atlanta to Midway Chicago
    REQUIRE(obj.test_edge_exists("ANC", "LAX") == true); // Achrorage Alaska, to Los Angeles
    // check edges don't exist
    REQUIRE(obj.test_edge_exists("ZCL", "MDW") == false); // Mexico city airport to Chicago Midway
    REQUIRE(obj.test_edge_exists("EDW", "SAW") == false); // Bremerhaven airport Germany to Istanbul Turkey
    // check number of edges correct

    REQUIRE(obj.test_number_of_edges_on_vertex("DUT", 3));
    // DUT (Unalaska ALaska US) (6 mentions in routes, only 3 where it is an orgin and has US destinations)
    // DUT to AKB
    // DUT to IKO
    // DUT to KQA

    REQUIRE(obj.test_number_of_edges_on_vertex("MDW", 0) == false);
    // Midway should have edges not none

    REQUIRE(obj.test_number_of_edges_on_vertex("COS", 11));
    // COS (Colorado Springs): 27 mentions in routes, only 11 where it is an origin and not a duplicate and 11 with US destination So edges expected are 10
    //  	COS to ATL //Atlanta
    //  	COS to DEN //Denver
    //  COS to IAD //Washington Dulles
    //  COS to IAH //Houston
    //  COS to LAX //Los Angeles
    //  COS to ORD //O'Hare Chicago
    //  COS to SFO //San Francisco
    //  COS to DFW //Dallas Fort Worth
    //  COS to SLC //Salt Lake City
    //  COS to LAS //LAs Vegas
    //  COS to SEA // Seatle US
}

TEST_CASE("BFS", "[part=2] [BFS]")
{
    FlightFinder obj;
    obj.read_in_file();
    // test potential route exists
    REQUIRE(obj.BFS("JNU", "COS")); // Juneau ALaska to Colorado Springs
    REQUIRE(obj.BFS("BTI", "CMI")); // BarterIsland Alaska to Champign,IL
    // test with an international airport (should be false since we aren't using international airports)
    REQUIRE(obj.BFS("MEX", "CMI") == false); // Mexico to Champaign
    // Using airport in US with no connection
    REQUIRE(obj.BFS("LFI", "ORD") == false); // Langley Airforce Base in Hampton US to Chicago O'Hare
}

TEST_CASE("weights", "[part=3] [weights]")
{
    FlightFinder obj;
    obj.read_in_file();
    // Juneau to Anchorage distance = 915.9240554118511 km
    REQUIRE(obj.edge_weight("JNU", "ANC") > 900.0); // Juneau to Anchorage
    REQUIRE(obj.edge_weight("JNU", "ANC") < 950.0); // Juneau to Anchorage

    // COS to LAX distance = 1339.2200803268508 km
    REQUIRE(obj.edge_weight("COS", "LAX") > 1330.0); // Colorado Springs to Los Angeles
    REQUIRE(obj.edge_weight("COS", "LAX") < 1350.0); // Colorado Springs to Los Angeles
}

TEST_CASE("a_star", "[part=4] [a_star]")
{
    FlightFinder obj;
    obj.read_in_file("../test_airport.dat", "../test_route.dat");

    std::vector<std::string> output = obj.a_star("LAX", "JFK");
    std::vector<std::string> expected;
    expected.push_back("LAX");
    expected.push_back("DFW");
    expected.push_back("ORD");
    expected.push_back("IAD");
    expected.push_back("JFK");
    expected.push_back("4585.550787");

    REQUIRE(output == expected);

    FlightFinder obj2;
    obj2.read_in_file();

    vector<string> output2 = obj2.a_star("LAX", "CMI");
    vector<string> expected2;

    expected2.push_back("LAX");
    expected2.push_back("ORD");
    expected2.push_back("CMI");
    expected2.push_back("3020.033956");

    REQUIRE(output2 == expected2);

    FlightFinder obj3;
    obj3.read_in_file();

    vector<string> output3 = obj3.a_star("ORD", "JFK");
    vector<string> expected3;

    expected3.push_back("ORD");
    expected3.push_back("JFK");
    expected3.push_back(to_string(obj3.calculate_weights("ORD", "JFK")));

    REQUIRE(output3 == expected3);

    FlightFinder obj4;
    obj4.read_in_file();

    vector<string> output4 = obj4.a_star("PIT", "ANC");
    vector<string> expected4;

    expected4.push_back("PIT");
    expected4.push_back("MSP");
    expected4.push_back("ANC");
    expected4.push_back("5208.748254");

    REQUIRE(output4 == expected4);
}

TEST_CASE("regional start", "[part=5]") {
    FlightFinder obj;
    obj.read_in_file("../test_airport.dat", "../test_route.dat");
    std::cout << "DFW" << " to DFW Distance should be" << 0 << std::endl;
    std::cout << "ORD" << " to DFW Distance should be" << obj.edge_weight("DFW", "ORD") << std::endl;
    std::cout << "MCO" << " to DFW Distance should be" << obj.edge_weight("DFW", "MCO") << std::endl;
    std::cout << "LAX" << " to DFW Distance should be" << obj.edge_weight("DFW", "LAX") << std::endl;
    std::cout << "IAD" << " to DFW Distance should be" << obj.edge_weight("DFW", "ORD") + obj.edge_weight("ORD", "IAD") << std::endl;
    std::cout << "JFK" << " to DFW Distance should be" << obj.edge_weight("DFW", "ORD") + obj.edge_weight("ORD", "IAD") + obj.edge_weight("IAD", "JFK") << std::endl;

    std::cout << "find one above and one below MCO." << std::endl;
    auto vect0 = obj.floyd_warshall("DFW", 1582.42, 0, 1);
    REQUIRE(vect0[0] == "ORD");
    REQUIRE(vect0[1] == "LAX");

    std::cout << "find two above and two below LAX." << std::endl;
    auto vect1 = obj.floyd_warshall("DFW", 1983.18, 0, 2);
    REQUIRE(vect1[0] == "ORD");
    REQUIRE(vect1[1] == "MCO");
    REQUIRE(vect1[2] == "IAD");
    REQUIRE(vect1[3] == "JFK");


    std::cout << "find two above and two below IAD. Will only return one above and three below." << std::endl;
    auto vect2 = obj.floyd_warshall("DFW", 2236.05, 0, 2);
    REQUIRE(vect2[0] == "ORD");
    REQUIRE(vect2[1] == "MCO");
    REQUIRE(vect2[2] == "LAX");
    REQUIRE(vect2[3] == "JFK");
    
}
    
TEST_CASE("FW ORD start", "[part=6]") {
    FlightFinder obj;
    obj.read_in_file("../test_airport.dat", "../test_route.dat");
    //final three do not have direct flights based on the graph built from the test files read above
    std::cout << "ORD" << " to ORD Distance should be" << 0 << std::endl;
    std::cout << "ORD" << " to IAD Distance should be" << obj.edge_weight("ORD", "IAD") << std::endl;
    std::cout << "ORD" << " to DFW Distance should be" << obj.edge_weight("ORD", "DFW") << std::endl;
    std::cout << "ORD" << " to JFK Distance should be" << obj.edge_weight("ORD", "IAD") + obj.edge_weight("IAD", "JFK") << std::endl;
    std::cout << "ORD" << " to MCO Distance should be" << obj.edge_weight("ORD", "IAD") + obj.edge_weight("IAD", "MCO") << std::endl;
    std::cout << "ORD" << " to LAX Distance should be" << obj.edge_weight("ORD", "DFW") + obj.edge_weight("DFW", "LAX") << std::endl;

    //chicago to IAD and DFW only direct flights


    auto vect = obj.floyd_warshall("ORD", 1290.65, 0, 1);
    for(size_t i=0; i< vect.size(); i++) {
        double dist = obj.calculate_weights("ORD", vect[i]);
        std::cout << vect[i] << ":" << dist << std::endl;
        
        
    }
    //inputting the distance of 1290.65 so we should get one below and one above according to outputs above
    REQUIRE(vect[0] == "IAD");
    REQUIRE(vect[1] == "JFK");

}
    
    
    

}
