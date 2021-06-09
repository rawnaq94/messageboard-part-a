#include "Direction.hpp"
#include <string>
#include <iostream>
using std::string;





namespace ariel
{ // Defines a direction of a message on the board
  
class Board 
 {
	private:
		   int od;
        public:
	           Board(){}
		   void post(unsigned int,unsigned int, Direction,string const&);
                   string read(unsigned int,unsigned int, Direction, int);
                   string show();	
	};
};
