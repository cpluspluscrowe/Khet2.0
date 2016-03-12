#include "Pieces.h"

class Cell
{
public:
	Cell(Piece piece, int row, int col);
	Cell();
	bool contains_piece() const;
	void setPiece(Piece &piece);
	void Cell::setPiece(Piece * piece);
	Piece getPiece() const;
	void setRow(int row);
	void setCol(int col);
	int getRow() const;
	int getCol() const;
private:
	Piece piece;
	int row;
	int col;
};
