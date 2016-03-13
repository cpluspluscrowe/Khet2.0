#include <iostream>	
#include "Pieces.h"
#include "Pieces.cpp"
#include "Cells.h"
#include "Boards.h"

#include <string>
using namespace std;

int main()
{
	//Piece p(Color::red);
	Board board;
	board.setup_board(GameType::classic);
	cout << "Welcome to Khet 2.0.  White goes first.";
	cout << "Pick the row\n";
	int row;
	cin >> row;
	cout << "Pick the column\n";
	int col;
	cin >> col;
	Cell cell(board.get_cell(row, col));
	Piece* piece(cell.getPiece());
	cout << "move or rotate\n";
	string m_or_r;
	cin >> m_or_r;
	if (m_or_r == "move")
	{
		piece->rotate_ccw(*(piece->get_top()), *(piece->get_right()), *(piece->get_bottom()), *(piece->get_left()));
	} else if (m_or_r == "rotate")
	{
		
	} else
	{
		cout << "You did not enter move or rotate";
	}
	int number;
	cin >> number;
}