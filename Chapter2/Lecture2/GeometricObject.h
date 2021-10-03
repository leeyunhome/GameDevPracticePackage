#pragma once

#include "Game2D.h"

namespace jm
{
	class GeometricObject : public Game2D
	{
	public:
		vec2 pos;
		RGB color;
		float time = 0.0f;
		/*float size;
		float width, height;*/

		void init(const RGB& _color, const vec2& _pos)
		{
			color = _color;
			pos = _pos;
		}

		virtual void drawGeometry()  = 0;
		//{
		//	// XXXX
		//}

		void rotate_geometry(float time, const float& angle) const
		{
			rotate(time * angle);
		}

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