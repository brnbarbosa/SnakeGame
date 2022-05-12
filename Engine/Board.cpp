#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
	width = (gfx.ScreenWidth - ((BORDERPADDING - CELLPADDING) * 2)) / DIMENSION;
	bw = width * DIMENSION + BORDERPADDING + CELLPADDING;

	height = (gfx.ScreenHeight - ((BORDERPADDING - CELLPADDING) * 2)) / DIMENSION;
	bh = height* DIMENSION + BORDERPADDING + CELLPADDING;
}

void Board::DrawCell(const Location& loc, Color c)
{	
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);

	gfx.DrawRectDim(loc.x * DIMENSION + BORDERPADDING, loc.y * DIMENSION + BORDERPADDING, DIMENSION - 2, DIMENSION - 2, c);
}

void Board::DrawBorder(Graphics& gfx)
{
	for (int i = BORDERPADDING; i < bw; i++)
	{
		gfx.PutPixel(i, BORDERPADDING, Colors::Green);
		gfx.PutPixel(i, bh, Colors::Green);
	}

	for (int j = BORDERPADDING; j < bh; j++)
	{
		gfx.PutPixel(BORDERPADDING, j, Colors::Green);
		gfx.PutPixel(bw, j, Colors::Green);
	}
	/*
	for (int i = BORDERPADDING; i < BORDERWIDTH; i++)
	{
		gfx.PutPixel(i, BORDERPADDING, Colors::Green);
		gfx.PutPixel(i, BORDERHEIGHT, Colors::Green);
	}

	for (int j = BORDERPADDING; j < BORDERHEIGHT; j++)
	{
		gfx.PutPixel(BORDERPADDING, j, Colors::Green);
		gfx.PutPixel(BORDERWIDTH, j, Colors::Green);
	}

	for (int i = 0; i < width * DIMENSION; i = i + DIMENSION)
	{
		for (int j = 0; j < height * DIMENSION; j = j + DIMENSION)
		{
			if ((j / 2) % 2 == 0 && (i / 2) % 2 == 0)
			{
				gfx.DrawRectDim(i, j, DIMENSION, DIMENSION, Colors::Cyan);

			}
			else
			{
				gfx.DrawRectDim(i, j, DIMENSION, DIMENSION, Colors::Gray);
			}

		}
	}*/
}

int Board::GetWidth() const
{
	return width;
}

int Board::GetHeight() const
{
	return height;
}

bool Board::InsideBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.x < width &&
		loc.y >= 0 && loc.y < height;
}
