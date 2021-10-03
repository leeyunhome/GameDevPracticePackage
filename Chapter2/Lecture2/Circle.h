#pragma once

#include "GeometricObject.h"

namespace jm
{
	class Circle : public GeometricObject
	{
	public:
		float time = 0.0f;
		float size;

		void init(const RGB& _color, const vec2& _pos, const float& _size)
		{
			/*color = _color;
			pos = _pos;*/
			GeometricObject::init(_color, _pos);
			size = _size;
		}

		void drawGeometry() override
		{
			rotate_geometry(time, -50.0f);
			drawFilledCircle(color, size);
			time += this->getTimeStep();
		}
	};
}