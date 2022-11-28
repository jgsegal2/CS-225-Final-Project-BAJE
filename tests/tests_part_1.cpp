#include <catch2/catch_test_macros.hpp>
//#include "tests_helper.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "FlightFinder.h"




TEST_CASE("graph data parsing", "[part=1] [vertices] [edges]") {
    FlightFinder obj;
    obj.read_in_file();
    //tests number of vertices in graph, should be 1,251 as 1,512 airports are in the US and 261 don't have 3-letter codes
    REQUIRE(obj.test_number_of_vertices(10));
    REQUIRE(obj.test_number_of_vertices(10000)==false);
    REQUIRE(obj.test_number_of_vertices(1200)==true);
    REQUIRE(obj.test_number_of_vertices(1300)==false);
    //Check that US airports exists as vertices
    REQUIRE(obj.test_vertex_existance("ORD")); //O'Hare Chicago
    REQUIRE(obj.test_vertex_existance("MFE")); //Mc Allen International Airport
    REQUIRE(obj.test_vertex_existance("CDB")); //Cold Bay airport
    REQUIRE(obj.test_vertex_existance("MDW")); //Midway Chicago
    REQUIRE(obj.test_vertex_existance("LAX")); //Los Angeles
    REQUIRE(obj.test_vertex_existance("SEA")); //Seatle US
    //vertex that don't exist
    REQUIRE(obj.test_vertex_existance("EDO")==false); //Balıkesir Körfez Airport Turkey
    REQUIRE(obj.test_vertex_existance("UAH")==false); //Ua Huka Airport French Polynisia
    REQUIRE(obj.test_vertex_existance("MAG")==false); // Madang Airpor Papaua New Guinea
    //Check edges exist
    REQUIRE(obj.test_edge_exists("ATL","MDW")==true); //Atlanta to Midway Chicago
    REQUIRE(obj.test_edge_exists("ANC","LAX")==true); //Achrorage Alaska, to Los Angeles
    //check edges don't exist
    REQUIRE(obj.test_edge_exists("ZCL","MDW")==false); //Mexico city airport to Chicago Midway 
    REQUIRE(obj.test_edge_exists("EDW","SAW")==false); //Bremerhaven airport Germany to Istanbul Turkey
    //check number of edges correct

    REQUIRE(obj.test_number_of_edges_on_vertex("DUT", 3));
    // DUT (Unalaska ALaska US) (6 mentions in routes, only 3 where it is an orgin and has US destinations)
	// DUT to AKB
	// DUT to IKO
	// DUT to KQA

    REQUIRE(obj.test_number_of_edges_on_vertex("MDW", 0)==false);
    // Midway should have edges not none

    REQUIRE(obj.test_number_of_edges_on_vertex("COS", 11));
    //COS (Colorado Springs): 27 mentions in routes, only 11 where it is an origin and not a duplicate and 11 with US destination So edges expected are 10
    // 	COS to ATL //Atlanta
    // 	COS to DEN //Denver
    // COS to IAD //Washington Dulles
    // COS to IAH //Houston 
    // COS to LAX //Los Angeles
    // COS to ORD //Orlando
    // COS to SFO //San Francisco
    // COS to DFW //Dallas Fort Worth
    // COS to SLC //Salt Lake City 
    // COS to LAS //LAs Vegas
    // COS to SEA // Seatle US

}

TEST_CASE("BFS", "[part=2] [BFS]") {
    FlightFinder obj;
    obj.read_in_file();
    //test potential route exists
    REQUIRE(obj.BFS("JNU","COS")); //Juneau ALaska to Colorado Springs
    REQUIRE(obj.BFS("BTI","CMI")); // BarterIsland Alaska to Champign,IL 
    //test with an international airport (should be false since we aren't using international airports)
    REQUIRE(obj.BFS("MEX","CMI")==false); // Mexico to Champaign
    //Using airport in US with no connection
    REQUIRE(obj.BFS("LFI","ORD")==false); // Langley Airforce Base in Hampton US to Chicago O'Hare
}

TEST_CASE("weights", "[part=3] [weights]") {
    FlightFinder obj;
    obj.read_in_file();
    //
    // REQUIRE(obj.BFS("JNU","COS")); //Juno ALaska to Colorado Springs
    // REQUIRE(obj.BFS("BTI","CMI")); // BarterIsland Alaska to Champign,IL 
    // REQUIRE(obj.BFS("MEX","CMI")==false); // Mexico to Champaign
    // REQUIRE(obj.BFS("LFI","ORD")==false); // Langley Airforce Base in Hampton US to Chicago O'Hare
}
