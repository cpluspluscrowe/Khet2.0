#include "Boards.h"

Cell Board::get_cell(int row, int col)
{
	return board[row][col];
}
void Board::set_cell(int row, int col, Cell &cell)
{
	board[row][col] = cell;
}
void Board::setup_board(GameType gametype)
{
	if (gametype == GameType::classic)
	{
		
	}
}
