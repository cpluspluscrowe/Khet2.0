enum class Type { mirror = 0, unprotected, blocker };
enum class Reflected { rup = 0, rright, rdown, rleft, rnone };
enum class Color {red, gray};

/*
Side class.  
Each piece has 4 Side instances.
*/
class Side
{
public:
	Side(Type surface_type, Reflected dir);
	void set_surface(const Type &surface_type);
	void set_reflect_dir(const Reflected &dir);
	Reflected get_reflect_dir() const;
	Type get_surface() const;
private:
	Type surface;
	Reflected reflect_dir;
};

class Piece {
public:
	Piece(Color color);
	Piece();
	void move(int dy, int dx);
	bool isHit(int dir);
	int getxpos() const;
	int getypos() const;
	void setRotation(int x);
	Color getColor() const;
	void setColor(Color color);
private:
	int posx;
	int posy;
	int rotation;
	Color color;
};
/*
Scarab Class
*/
class Scarab : public Piece
{
public:
	Scarab(Color color, int rotation);
	void Scarab::rotate(Side &top, Side &right, Side &bottom, Side &left);
	Reflected Scarab::get_opposite_reflected(Side &current) const;
private:
};
/*
Pyramid class
*/
class Pyramid : public Piece
{
public:
	Pyramid(Color color, int rotation);
	void rotate_cc(Side &top, Side &right, Side &bottom, Side &left);
	void rotate_cw(Side &top, Side &right, Side &bottom, Side &left);
private:
};
/*
Pharaoh class
*/
class Pharaoh : public Piece
{
public:
	Pharaoh(Color color);
private:
};
/*
Anubis class
*/
class Anubis : public Piece
{
public:
	Anubis(Color color, int rotation);
private:
};