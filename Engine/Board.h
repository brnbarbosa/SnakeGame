#pragma once

#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	void DrawBorder(Graphics& gfx);
	int GetWidth() const;
	int GetHeight() const;
	bool InsideBoard(const Location& loc) const;
private:
	static constexpr int DIMENSION = 20;
	static constexpr int BORDERPADDING = 50;
	static constexpr int CELLPADDING = 2;
	int width = 50;
	int height;
	int bw;
	int bh;
	const int BORDERWIDTH = width * DIMENSION + BORDERPADDING + CELLPADDING;
	const int BORDERHEIGHT = height * DIMENSION + BORDERPADDING + CELLPADDING;
	Graphics& gfx;
};
	