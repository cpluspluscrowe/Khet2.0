#include <iostream>
#include "Pieces.h"
using namespace std;



/*
Side class implementation
*/
Side::Side(Type surface_type, Reflected dir)
{
	set_surface(surface_type);
	set_reflect_dir(dir);
}
void Side::set_surface(const Type &surface_type)
{
	surface = surface_type;
}
void Side::set_reflect_dir(const Reflected &dir)
{
	reflect_dir = dir;
}

/*
Piece class implementation
*/
Piece::Piece(int posx, int posy)
{
	setxpos(posx);
	setypos(posy);
};
void Piece::move(int dy, int dx)
{
	posy += dy;
	posx += dx;
};
bool Piece::isHit(int dir)
{
	return true;
};
int Piece::getxpos() const
{
	return posx;
};
int Piece::getypos() const
{
	return posy;
};
void Piece::setxpos(int x)
{
	posx = x;
};
void Piece::setypos(int y)
{
	posy = y;
};
void Piece::setRotation(int x)
{
	rotation = x;
}
Reflected Side::get_reflect_dir() const
{
	return reflect_dir;
}
Type Side::get_surface() const
{
	return surface;
}


/*
Scarab class implementation
*/
void Scarab::rotate(Side &top, Side &right, Side &bottom, Side &left)
{
	top.set_reflect_dir(get_opposite_reflected(top));
	right.set_reflect_dir(get_opposite_reflected(top));
	bottom.set_reflect_dir(get_opposite_reflected(top));
	left.set_reflect_dir(get_opposite_reflected(top));
};
Reflected Scarab::get_opposite_reflected(Side &current) const
{
	if (current.get_reflect_dir() == Reflected::rup)
	{
		return Reflected::rdown;
	}
	else if (current.get_reflect_dir() == Reflected::rdown)
	{
		return Reflected::rup;
	} else if (current.get_reflect_dir() == Reflected::rleft)
	{
		return Reflected::rright;
	} else //(current.get_reflect_dir() == Reflected::rright)
	{
		return Reflected::rleft;
	}
}
Scarab::Scarab(int x, int y, int rotation) :Piece(x, y){
	Side top(Type::mirror, Reflected::rright);
	Side right(Type::mirror, Reflected::rup);
	Side left(Type::mirror, Reflected::rdown);
	Side bottom(Type::mirror, Reflected::rleft);
	if (rotation == 1)
	{
		rotate(top, right, bottom, left);
	}
}
/*
Pyramid class implementation
*/
Pyramid::Pyramid(int x, int y, int rotation) :Piece(x, y){
	Side top(Type::mirror, Reflected::rright);
	Side right(Type::mirror, Reflected::rup);
	Side left(Type::unprotected, Reflected::rnone);
	Side bottom(Type::unprotected, Reflected::rnone);
	if (rotation == 1)
	{
		rotate_cc(top, right, bottom, left);
	} else if (rotation == 2)
	{
		rotate_cc(top, right, bottom, left);
		rotate_cc(top, right, bottom, left);
	} else if (rotation == 3)
	{
		rotate_cw(top, right, bottom, left); //Note rotates clockwise, not counterclockwise like the above two!
	}
}
void Pyramid::rotate_cc(Side &top, Side &right, Side &bottom, Side &left)
{
	if (top.get_reflect_dir() == Reflected::rright && right.get_reflect_dir() == Reflected::rup && 
		bottom.get_surface() == Type::unprotected && left.get_surface() == Type::unprotected)
	{
		top.set_reflect_dir(Reflected::rnone);
		top.set_surface(Type::unprotected);
		right.set_reflect_dir(Reflected::rdown);
		right.set_surface(Type::mirror);
		bottom.set_reflect_dir(Reflected::rright);
		bottom.set_surface(Type::mirror);
		left.set_reflect_dir(Reflected::rnone);
		left.set_surface(Type::unprotected);
	}
	else if (top.get_surface() == Type::unprotected && right.get_reflect_dir() == Reflected::rdown &&
		bottom.get_reflect_dir() == Reflected::rright && left.get_surface() == Type::unprotected)
	{
		top.set_reflect_dir(Reflected::rnone);
		top.set_surface(Type::unprotected);
		right.set_reflect_dir(Reflected::rnone);
		right.set_surface(Type::unprotected);
		bottom.set_reflect_dir(Reflected::rleft);
		bottom.set_surface(Type::mirror);
		left.set_reflect_dir(Reflected::rdown);
		left.set_surface(Type::mirror);
	} else if (top.get_surface() == Type::unprotected && right.get_surface() == Type::unprotected &&
		bottom.get_reflect_dir() == Reflected::rleft && left.get_reflect_dir() == Reflected::rdown)
	{
		top.set_reflect_dir(Reflected::rleft);
		top.set_surface(Type::mirror);
		right.set_reflect_dir(Reflected::rnone);
		right.set_surface(Type::unprotected);
		bottom.set_reflect_dir(Reflected::rnone);
		bottom.set_surface(Type::unprotected);
		left.set_reflect_dir(Reflected::rup);
		left.set_surface(Type::mirror);
	} else if (top.get_reflect_dir() == Reflected::rleft && right.get_surface() == Type::unprotected && 
		bottom.get_surface() == Type::unprotected && left.get_reflect_dir() == Reflected::rleft)
	{
		top.set_reflect_dir(Reflected::rright);
		top.set_surface(Type::mirror);
		right.set_reflect_dir(Reflected::rup);
		right.set_surface(Type::mirror);
		bottom.set_reflect_dir(Reflected::rnone);
		bottom.set_surface(Type::unprotected);
		left.set_reflect_dir(Reflected::rnone);
		left.set_surface(Type::unprotected);
	} else
	{
		cout << "Error with rotating Pyramid piece!";
	}
}
void Pyramid::rotate_cw(Side &top, Side &right, Side &bottom, Side &left)
{
	rotate_cc(top, right, bottom, left);
	rotate_cc(top, right, bottom, left);
	rotate_cc(top, right, bottom, left);
}
/*
Pharaoh class implementation
*/
Pharaoh::Pharaoh(int x, int y) :Piece(x, y){
	Side top(Type::unprotected, Reflected::rnone);
	Side right(Type::unprotected, Reflected::rnone);
	Side left(Type::unprotected, Reflected::rnone);
	Side bottom(Type::unprotected, Reflected::rnone);
}

/*
Anubis class implementation
*/
Anubis::Anubis(int x, int y, int rotation) :Piece(x, y){
	Side top(Type::blocker, Reflected::rright);
	Side right(Type::unprotected, Reflected::rup);
	Side left(Type::unprotected, Reflected::rdown);
	Side bottom(Type::unprotected, Reflected::rleft);
}
