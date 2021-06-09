#include "Board.hpp"
#include "doctest.h"
#include "Direction.hpp"
#include <string>
#include <algorithm>


using ariel::Direction;
using namespace ariel;
using namespace std;

//------------------------------- Empty board and read at Horizontal direction ----------------------------------

TEST_CASE("Nothing to read on Horizontal direction")
{
    ariel::Board board;
    CHECK(board.read(2,8,Direction::Horizontal,4) == "____");
    CHECK(board.read(6,2,Direction::Horizontal,2) == "__");
    CHECK(board.read(12,10,Direction::Horizontal,6) == "______"); 
    CHECK(board.read(20,1,Direction::Horizontal,3) == "___"); 
    CHECK(board.read(2,9,Direction::Horizontal,5) == "_____");
    CHECK(board.read(4,3,Direction::Horizontal,3) == "___");
    board.post(2, 8, Direction::Horizontal, "Rawnaq1994");
    board.post(6, 2, Direction::Horizontal, "Rawnaq1995");
    board.post(12, 10, Direction::Horizontal, "Rawnaq1996");
    board.post(20, 1, Direction::Horizontal, "Rawnaq1997");
    board.post(2, 9, Direction::Horizontal, "Rawnaq1998");
    board.post(4, 3, Direction::Horizontal, "Rawnaq1999");
    CHECK(board.read(2,8,Direction::Horizontal,4) == "Rawn");
    CHECK(board.read(6,2,Direction::Horizontal,2) == "Ra");
    CHECK(board.read(12,10,Direction::Horizontal,6) == "Rawnaq"); 
    CHECK(board.read(20,1,Direction::Horizontal,3) == "Raw");
    CHECK(board.read(2,9,Direction::Horizontal,5) == "Rawna");
    CHECK(board.read(4,3,Direction::Horizontal,3) == "Raw");
}


//------------------------------- Empty board and read at Vertical direction ----------------------------------

TEST_CASE("Nothing to read on Vertical direction")
{
     ariel::Board board;
    CHECK(board.read(2,8,Direction::Vertical,4) == "____");
    CHECK(board.read(6,2,Direction::Vertical,2) == "__");
    CHECK(board.read(12,10,Direction::Vertical,6) == "______"); 
    CHECK(board.read(20,1,Direction::Vertical,3) == "___"); 
    CHECK(board.read(2,9,Direction::Vertical,5) == "_____");
    CHECK(board.read(4,3,Direction::Vertical,3) == "___");
    board.post(2, 8, Direction::Vertical, "Rawnaq1994");
    board.post(6, 2, Direction::Vertical, "Rawnaq1995");
    board.post(12, 10, Direction::Vertical, "Rawnaq1996");
    board.post(20, 1, Direction::Vertical, "Rawnaq1997");
    board.post(2, 9, Direction::Vertical, "Rawnaq1998");
    board.post(4, 3, Direction::Vertical, "Rawnaq1999");
    CHECK(board.read(2,8,Direction::Vertical,4) == "Rawn");
    CHECK(board.read(6,2,Direction::Vertical,2) == "Ra");
    CHECK(board.read(12,10,Direction::Vertical,6) == "Rawnaq"); 
    CHECK(board.read(20,1,Direction::Vertical,3) == "Raw");
    CHECK(board.read(2,9,Direction::Vertical,5) == "Rawna");
    CHECK(board.read(4,3,Direction::Vertical,3) == "Raw");
}

//---------------------------------   Chack Horizontal direction posts ---------------------------------------


TEST_CASE("The lest post is on the board at Horizontal direction")
{
    ariel::Board board;
	board.post(2, 8, Direction::Horizontal, "Rawnaq1");
	board.post(2, 8, Direction::Horizontal, "Amer199");
	board.post(2, 8, Direction::Horizontal, "Yesssss");
	board.post(2, 8, Direction::Horizontal, "Nothing");
  CHECK(board.read(2,8,Direction::Horizontal,7) == "Nothing"); 
  CHECK(board.read(2,8,Direction::Horizontal,7) != "Yesssss"); 
  CHECK(board.read(2,8,Direction::Horizontal,7) != "Amer199");
  CHECK(board.read(2,8,Direction::Horizontal,7) != "Rawnaq1");
  board.post(6, 2, Direction::Horizontal, "Rooz50");
	board.post(6, 2, Direction::Horizontal, "Noon100");
	board.post(6, 2, Direction::Horizontal, "Doon150");
	board.post(6, 2, Direction::Horizontal, "Soon200");
  CHECK(board.read(6,2,Direction::Horizontal,7) == "Soon200"); 
  CHECK(board.read(6,2,Direction::Horizontal,7) != "Doon150"); 
  CHECK(board.read(6,2,Direction::Horizontal,7) != "Noon100");
  CHECK(board.read(6,2,Direction::Horizontal,7) != "Rooz50");
  board.post(8, 2, Direction::Horizontal, "Rawnaq1");
	board.post(8, 3, Direction::Horizontal, "Noon100");
	board.post(8, 4, Direction::Horizontal, "Doon150");
	board.post(8, 5, Direction::Horizontal, "Soon200");
  board.post(8, 6, Direction::Horizontal, "Foon250");
  board.post(8, 7, Direction::Horizontal, "Moon300");
  CHECK(board.read(8,2,Direction::Horizontal,6) == "RNDSFM"); 
  CHECK(board.read(8,7,Direction::Horizontal,5) == "Moon3"); 
  CHECK(board.read(8,3,Direction::Horizontal,4) == "NDSF");
  CHECK(board.read(8,6,Direction::Horizontal,5) == "FMoon");
  CHECK(board.read(8,5,Direction::Horizontal,9) == "SFMoon300");
  CHECK_THROWS(board.read(2,8,Direction::Horizontal , -8)); 
  CHECK_THROWS(board.read(6,2,Direction::Horizontal , -6)); 
  CHECK_THROWS(board.read(8,6,Direction::Horizontal , -1));
  CHECK_THROWS(board.read(8,5,Direction::Horizontal , -3)); 
  CHECK_THROWS(board.read(8,7,Direction::Horizontal , -7)); 
  CHECK_THROWS(board.read(8,4,Direction::Horizontal , -10));
  CHECK(board.read(2,8,Direction::Horizontal,0) == "");
  CHECK(board.read(6,2,Direction::Horizontal,0) == "");
  CHECK(board.read(8,6,Direction::Horizontal,0) == "");
  CHECK(board.read(8,4,Direction::Horizontal,0) == "");
  CHECK(board.read(8,3,Direction::Horizontal,0) == "");
  
  
}

//---------------------------------   Chack Vertical direction posts ---------------------------------------

TEST_CASE("The lest post is on the board at Vertical direction")
{
 ariel::Board board;
	board.post(2, 8, Direction::Vertical, "Rawnaq1");
	board.post(2, 8, Direction::Vertical, "Amer199");
	board.post(2, 8, Direction::Vertical, "Yesssss");
	board.post(2, 8, Direction::Vertical, "Nothing");
  CHECK(board.read(2,8,Direction::Vertical,7) == "Nothing"); 
  CHECK(board.read(2,8,Direction::Vertical,7) != "Yesssss"); 
  CHECK(board.read(2,8,Direction::Vertical,7) != "Amer199");
  CHECK(board.read(2,8,Direction::Vertical,7) != "Rawnaq1");
  board.post(6, 2, Direction::Vertical, "Rooz50");
	board.post(6, 2, Direction::Vertical, "Noon100");
	board.post(6, 2, Direction::Vertical, "Doon150");
	board.post(6, 2, Direction::Vertical, "Soon200");
  CHECK(board.read(6,2,Direction::Vertical,7) == "Soon200"); 
  CHECK(board.read(6,2,Direction::Vertical,7) != "Doon150"); 
  CHECK(board.read(6,2,Direction::Vertical,7) != "Noon100");
  CHECK(board.read(6,2,Direction::Vertical,7) != "Rooz50");
  board.post(8, 2, Direction::Vertical, "Rawnaq1");
	board.post(8, 3, Direction::Vertical, "Noon100");
	board.post(8, 4, Direction::Vertical, "Doon150");
	board.post(8, 5, Direction::Vertical, "Soon200");
  board.post(8, 6, Direction::Vertical, "Foon250");
  board.post(8, 7, Direction::Vertical, "Moon300");
  CHECK(board.read(8,2,Direction::Vertical,6) == "RNDSFM"); 
  CHECK(board.read(8,7,Direction::Vertical,5) == "Moon3"); 
  CHECK(board.read(8,3,Direction::Vertical,4) == "NDSF");
  CHECK(board.read(8,6,Direction::Vertical,5) == "FMoon");
  CHECK(board.read(8,5,Direction::Vertical,9) == "SFMoon300");
  CHECK_THROWS(board.read(2,8,Direction::Vertical , -8)); 
  CHECK_THROWS(board.read(6,2,Direction::Vertical , -6)); 
  CHECK_THROWS(board.read(8,6,Direction::Vertical , -1));
  CHECK_THROWS(board.read(8,5,Direction::Vertical , -3)); 
  CHECK_THROWS(board.read(8,7,Direction::Vertical , -7)); 
  CHECK_THROWS(board.read(8,4,Direction::Vertical , -10));
  CHECK(board.read(2,8,Direction::Vertical,0) == "");
  CHECK(board.read(6,2,Direction::Vertical,0) == "");
  CHECK(board.read(8,6,Direction::Vertical,0) == "");
  CHECK(board.read(8,4,Direction::Vertical,0) == "");
  CHECK(board.read(8,3,Direction::Vertical,0) == "");
}


