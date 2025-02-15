#pragma once

#include "Game2D.h"

namespace jm
{
	class GeometricObject
	{
	public:
		vec2 pos;
		RGB color;
		/*float size;
		float width, height;*/

		void init(const RGB& _color, const vec2& _pos)
		{
			color = _color;
			pos = _pos;
		}

		virtual void drawGeometry() const = 0;
		//{
		//	// XXXX
		//}

		void draw()
		{
			beginTransformation();
			{
				translate(pos);
				drawGeometry();
			}
			endTransformation();
		}
	};
}