#pragma once

#include "GeometricObject.h"

namespace jm
{
	class Box : public GeometricObject
	{
	public:

		float width, height;
		void init(const RGB& _color, const vec2& _pos, const float& _width,
			const float& _height)
		{
			GeometricObject::init(_color, _pos);

			//size = _size;
			width = _width;
			height = _height;
		}

		void drawGeometry() const override
		{
			drawFilledBox(Colors::blue,	this->width, this->height);
		}
	};
}