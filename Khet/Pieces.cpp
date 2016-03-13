
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
Reflected Side::get_reflect_dir() const
{
	return reflect_dir;
}
Type Side::get_surface() const
{
	return surface;
}

/*
Piece class implementation
*/
Piece::Piece(Color color)
{
	setColor(color);
};
Piece::Piece()
{
	//do nothing
};
Color Piece::getColor() const
{
	return color;
}
void Piece::setColor(Color color)
{
	color = color;
}
bool Piece::isHit(int dir)
{
	return true;
};





/*
Scarab class implementation
*/
Scarab::Scarab(Color color, int rotation) : Piece(color) {
	Side top(Type::mirror, Reflected::rright);
	Side right(Type::mirror, Reflected::rup);
	Side left(Type::mirror, Reflected::rdown);
	Side bottom(Type::mirror, Reflected::rleft);
	setColor(color);
	if (rotation == 1)
	{
		rotate(top, right, bottom, left);
	}
}
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
/*
Pyramid class implementation
*/
Pyramid::Pyramid(Color color, int rotation) : Piece(color){
	Side top(Type::mirror, Reflected::rright);
	Side right(Type::mirror, Reflected::rup);
	Side left(Type::unprotected, Reflected::rnone);
	Side bottom(Type::unprotected, Reflected::rnone);
	setColor(color);
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
Pharaoh::Pharaoh(Color color) : Piece(color){
	Side top(Type::unprotected, Reflected::rnone);
	Side right(Type::unprotected, Reflected::rnone);
	Side left(Type::unprotected, Reflected::rnone);
	Side bottom(Type::unprotected, Reflected::rnone);
}

/*
Anubis class implementation
*/
Anubis::Anubis(Color color, int rotation) : Piece(color){
	Side top(Type::blocker, Reflected::rright);
	Side right(Type::unprotected, Reflected::rup);
	Side left(Type::unprotected, Reflected::rdown);
	Side bottom(Type::unprotected, Reflected::rleft);
	for (int i = 0; i < rotation; i++)
	{
		rotatecw(top, right, bottom, left);
	}
}
void Anubis::rotatecw(Side &top, Side &right, Side &bottom, Side &left)
{
	if (top.get_surface() == Type::blocker)
	{
		top.set_surface(Type::unprotected);
		right.set_surface(Type::blocker);
	}
	else if (right.get_surface() == Type::blocker)
	{
		right.set_surface(Type::unprotected);
		bottom.set_surface(Type::blocker);
	}
	else if (bottom.get_surface() == Type::blocker)
	{
		bottom.set_surface(Type::unprotected);
		left.set_surface(Type::blocker);
	} else //(left.get_surface() == Type::blocker)
	{
		left.set_surface(Type::unprotected);
		top.set_surface(Type::blocker);
	}
}
void Anubis::rotateccw(Side &top, Side &right, Side &bottom, Side &left)
{
	rotatecw(top, right, bottom, left);
	rotatecw(top, right, bottom, left);
	rotatecw(top, right, bottom, left);
}
