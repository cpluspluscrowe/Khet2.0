#include "Pieces.h"
#include "Cell.h"

enum class GameType {classic = 0};
class Board
{
public:
	void setup_board(GameType gametype);
	Cell board[8][10];
	Cell get_piece(int row, int col);
	void set_piece(int row, int col, Cell &cell);
};
