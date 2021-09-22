#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <vector>

TEST_CASE("incrementing values in integer vector", "[addN]"){
	std::vector<int> v{1,2,3,4,5};

    SECTION("checking sum of elements in v"){
        REQUIRE(Sum(v)==15);
    }
	SECTION("checking with +ve n"){
		int n=5;
		std::vector<int> res = VectorPlusN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == 6 );
		REQUIRE( res[v.size()-1] == 10 );
		REQUIRE(res[random] == v[random]+n);
	}
	SECTION("checking with -ve n"){
		int n=-5;
		std::vector<int> res = VectorPlusN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == -4 );
		REQUIRE( res[v.size()-1] == 0 );
		REQUIRE(res[random] == v[random]+n);
	}
	
}
