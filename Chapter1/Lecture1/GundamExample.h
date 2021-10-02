#pragma once

#include "Game2D.h"

namespace jm
{
	class GundamExample : public Game2D
	{
	public:
		void update() override
		{
			beginTransformation();
			drawFilledCircle(Colors::white, 0.8f);
			drawFilledSquare(Colors::gold, 0.8f);
			rotate(180.0f);
			const float width = 0.5f;
			for (float row = 0.1f; row < width; row += 0.1f)
			{
				translate(row, 0.0f);
				drawFilledTriangle(Colors::green, 0.2f);
			}
			endTransformation();

			for (float x = -0.5f; x < 0.4f; x += 0.05f)
			{
				drawLine(Colors::black, vec2(x, 0.6f), Colors::gray, vec2(x + 0.05f, 0.85f));
			}
		}
	};
}