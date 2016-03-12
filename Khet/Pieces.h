enum class Type { mirror = 0, unprotected, blocker };
enum class Reflected { rup = 0, rright, rdown, rleft, rnone };

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
	Piece(int posx, int posy);
	void move(int dy, int dx);
	bool isHit(int dir);
	int getxpos() const;
	int getypos() const;
	void setxpos(int x);
	void setypos(int y);
	void setRotation(int x);
private:
	int posx;
	int posy;
	int rotation;
};
/*
Scarab Class
*/
class Scarab : Piece
{
public:
	Scarab(int x, int y, int rotation);
	void Scarab::rotate(Side &top, Side &right, Side &bottom, Side &left);
	Reflected Scarab::get_opposite_reflected(Side &current) const;
private:
};
/*
Pyramid class
*/
class Pyramid : Piece
{
public:
	Pyramid(int x, int y, int rotation);
	void rotate_cc(Side &top, Side &right, Side &bottom, Side &left);
	void rotate_cw(Side &top, Side &right, Side &bottom, Side &left);
private:
};
/*
Pharaoh class
*/
class Pharaoh : Piece
{
public:
	Pharaoh(int x, int y);
private:
};
/*
Anubis class
*/
class Anubis : Piece
{
public:
	Anubis(int x, int y, int rotation);
private:
};