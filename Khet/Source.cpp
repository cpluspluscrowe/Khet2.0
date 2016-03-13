#include <iostream>	
#include "Pieces.h"
#include "Pieces.cpp"
#include "Cells.h"
#include "Boards.h"

using namespace std;

int main()
{
	//Piece p(Color::red);
	Board board;
	board.set_cell(8, 10, Cell(dynamic_cast<Piece*>(&Piece(Color::red)), 8, 10));
	int number;
	cin >> number;
}