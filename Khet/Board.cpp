#include "Board.h"
#include "Pieces.h"

Cell Board::get_piece(int row, int col)
{
	return board[row][col];
}
void Board::set_piece(int row, int col, Cell &cell)
{
	board[row][col] = cell;
}
void setup_board(GameType gametype)
{
	if (gametype == GameType::classic)
	{
		board[8][10] = Scarab::Scarab(Color::red, 0);
	}
}