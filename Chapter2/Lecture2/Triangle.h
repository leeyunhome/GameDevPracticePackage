#pragma once

#include "GeometricObject.h"

namespace jm
{
	class Triangle : public GeometricObject
	{
	public:
		float time = 0.0f;
		float size;

		void init(const RGB& _color, const vec2& _pos, const float& _size)
		{
			GeometricObject::init(_color, _pos);
			/*color = _color;
			pos = _pos;*/
			size = _size;
		}

		void drawGeometry() override
		{
			rotate_geometry(time, -60.0f);
			drawFilledTriangle(color, size);
			time += this->getTimeStep();
		}
	};
}