#pragma once

#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& initLoc);
		void InitBody();
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd) const;
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;	
	};

public:
	Snake(const Location& initLoc);
	void MoveBy(const Location& deltaLoc);
	void Grow();
	void Draw(Board& brd) const;
	Location GetNextHeadLocation(const Location& deltaLoc) const;
	bool IsInTileExceptEnd(const Location& target) const;
	bool IsInTile(const Location& target) const;
private:
	static constexpr Color HEAD = Colors::Yellow;
	static constexpr Color BODY = Colors::Green;
	static constexpr int SEGMENTSMAX = 100;
	Segment segments[SEGMENTSMAX];
	int nSegments = 1;
};

