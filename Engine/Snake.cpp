#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location& initLoc)
{
	segments[0].InitHead(initLoc);
}

void Snake::MoveBy(const Location& deltaLoc)
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(deltaLoc);
}

void Snake::Grow()
{
	if (nSegments < SEGMENTSMAX)
	{
		segments[nSegments].InitBody(nSegments);
		++nSegments;
	}
}

void Snake::Draw(Board& brd) const
{
	for (int i = 0; i < nSegments; ++i)
	{
		segments[i].Draw(brd);
	}
}

Location Snake::GetNextHeadLocation(const Location& deltaLoc) const
{
	Location nextHeadLoc = segments[0].GetLocation();
	nextHeadLoc.add(deltaLoc);
	return nextHeadLoc;
}

bool Snake::IsInTileExceptEnd(const Location& target) const
{
	for (int i = 0; i < nSegments - 1; ++i)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

bool Snake::IsInTile(const Location& target) const
{
	for (int i = 0; i < nSegments; ++i)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

void Snake::Segment::InitHead(const Location& initLoc)
{
	loc = initLoc;
	c = Snake::HEAD;
}

void Snake::Segment::InitBody(const int segmentPosition)
{
	const int possibleColors = 4;
	const Color tonsOfGreen[possibleColors] =
	{
		{46, 182, 44},
		{87, 200, 77},
		{131, 212, 117},
		{171, 224, 152}
	};

	c = tonsOfGreen[segmentPosition % possibleColors];
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.add(delta_loc);
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
