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
		set_cell(4, 4, Cell(dynamic_cast<Piece*>(&Scarab(Color::gray, 1)), 4, 4));
		set_cell(4, 5, Cell(dynamic_cast<Piece*>(&Scarab(Color::gray, 0)), 4, 5));
		set_cell(7, 2, Cell(dynamic_cast<Piece*>(&Pyramid(Color::gray, 3)), 7, 2));
		set_cell(6, 7, Cell(dynamic_cast<Piece*>(&Pyramid(Color::gray, 0)), 6, 7));
		set_cell(2, 3, Cell(dynamic_cast<Piece*>(&Pyramid(Color::gray, 3)), 2, 3));
		set_cell(3, 2, Cell(dynamic_cast<Piece*>(&Pyramid(Color::gray, 2)), 3, 2));
		set_cell(4, 2, Cell(dynamic_cast<Piece*>(&Pyramid(Color::gray, 3)), 4, 2));
		set_cell(3, 9, Cell(dynamic_cast<Piece*>(&Pyramid(Color::gray, 3)), 3, 9));
		set_cell(4, 9, Cell(dynamic_cast<Piece*>(&Pyramid(Color::gray, 2)), 4, 9));
		set_cell(7, 4, Cell(dynamic_cast<Piece*>(&Pharaoh(Color::gray)), 7, 4));
		set_cell(7, 3, Cell(dynamic_cast<Piece*>(&Anubis(Color::gray,0)), 7, 3));
		set_cell(7, 5, Cell(dynamic_cast<Piece*>(&Anubis(Color::gray,0)), 7, 5));


		set_cell(4, 5, Cell(dynamic_cast<Piece*>(&Scarab(Color::red, 0)), 4, 5));
		set_cell(4, 6, Cell(dynamic_cast<Piece*>(&Scarab(Color::red, 1)), 4, 6));
		set_cell(3, 0, Cell(dynamic_cast<Piece*>(&Pyramid(Color::red, 0)), 3, 0));
		set_cell(4, 0, Cell(dynamic_cast<Piece*>(&Pyramid(Color::red, 0)), 4, 0));
		set_cell(3, 5, Cell(dynamic_cast<Piece*>(&Pyramid(Color::red, 1)), 3, 7));
		set_cell(4, 5, Cell(dynamic_cast<Piece*>(&Pyramid(Color::red, 0)), 4, 7));
		set_cell(1, 2, Cell(dynamic_cast<Piece*>(&Pyramid(Color::red, 2)), 1, 2));
		set_cell(0, 7, Cell(dynamic_cast<Piece*>(&Pyramid(Color::red, 1)), 0, 7));
		set_cell(5, 6, Cell(dynamic_cast<Piece*>(&Pyramid(Color::red, 1)), 5, 6));
		set_cell(0, 5, Cell(dynamic_cast<Piece*>(&Pharaoh(Color::red)), 0, 5));
		set_cell(0, 4, Cell(dynamic_cast<Piece*>(&Anubis(Color::red, 2)), 0, 4));
		set_cell(0, 6, Cell(dynamic_cast<Piece*>(&Anubis(Color::red, 2)), 0, 6));
	}
}
