#include "Cell.h"
#include <cstddef>

Cell::Cell(Piece piece, int row, int col)
{
	setPiece(piece);
	setRow(row);
	setCol(col);
}
void Cell::setRow(int row)
{
	row = row;
}
void Cell::setCol(int col)
{
	col = col;
}
int Cell::getRow() const
{
	return row;
}
int Cell::getCol() const
{
	return col;
}
Cell::Cell() 
{
	setPiece(nullptr);
}
bool Cell::contains_piece() const
{
	if (Cell::getPiece == nullptr)
	{
		return false;
	} else
	{
		return true;
	}
}
void Cell::setPiece(Piece &piece)
{
	piece = piece;
}
void Cell::setPiece(Piece * piece)
{
	piece = nullptr;
}
Piece Cell::getPiece() const
{
	return piece;
}