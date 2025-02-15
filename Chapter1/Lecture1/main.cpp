#include "Game2D.h"
#include "PrimitivesGallery.h"
#include "TankExample.h"
#include "FaceExample.h"
#include "WalkingPerson.h"
#include "SolarSystem.h"
#include "GundamExample.h"

namespace jm
{
	class MouseExample : public Game2D
	{
	public:
		void update() override
		{
			const vec2 mouse_pos = getCursorPos();

			if (this->isMouseButtonPressed(GLFW_MOUSE_BUTTON_1) == true)
			{
				translate(mouse_pos);
				drawFilledCircle(Colors::gold, 0.1f);
			}
			else if (isMouseButtonPressed(GLFW_MOUSE_BUTTON_2) == true)
			{
				translate(mouse_pos);
				drawFilledCircle(Colors::red, 0.1f);
			}
		}
	};
}

namespace jm
{
	class TransformationsExample : public Game2D
	{
	public:
		float time = 0;

		void update() override
		{
			//{
			//	const vec2 point = vec2(0.0f, 0.0f);

			//	//translate(0.1f, 0.0f);
			//	//drawPoint(Colors::black, point, 5.0f);
			//}

			//const float dx = 0.1f;
			//const float dy = 0.2f;

			//// translation
			//const vec2 p0(0.0f + dx, 0.0f);
			//const vec2 p1(0.5f + dx, 0.5f);
			//const vec2 p2(0.5f + dx, 0.0f);

			//beginTransformation();

			//translate(0.1f, 0.0f);

			//const vec2 p0(0.0f, 0.0f);
			//const vec2 p1(0.5f, 0.5f);
			//const vec2 p2(0.5f, 0.0f);

			////const vec2 p0(0.0f + dx, 0.0f + dy);
			////const vec2 p1(0.5f + dx, 0.5f + dy);
			////const vec2 p2(0.5f + dx, 0.0f + dy);

			//drawLine(Colors::red, p0, Colors::blue, p1);
			//drawLine(Colors::red, p1, Colors::blue, p2);
			//drawLine(Colors::red, p2, Colors::blue, p0);
			//
			//endTransformation();

			//translate(-0.1f, 0.0f);

			//drawLine(Colors::red, p0, Colors::blue, p1);
			//drawLine(Colors::red, p1, Colors::blue, p2);
			//drawLine(Colors::red, p2, Colors::blue, p0);

			//setLineWidth(3.0f);

			//drawWiredBox(Colors::gold, 0.5f, 0.25f);

			//beginTransformation();
			////rotate(30.0f);
			//translate(0.25f, 0.0f);
			//drawWiredBox(Colors::skyblue, 0.5f, 0.25f);
			//endTransformation();

			//beginTransformation();
			//translate(0.25f, 0.0f);
			//rotate(30.0f);
			//drawWiredBox(Colors::red, 0.5f, 0.25f);
			//endTransformation();

			//beginTransformation();
			//rotate(15.0f);
			//translate(0.25f, 0.0f);
			//drawWiredBox(Colors::blue, 0.5f, 0.25f);
			//endTransformation();

			//beginTransformation();
			//rotate(30.0f);
			//translate(0.25f, 0.0f);
			//drawWiredBox(Colors::blue, 0.5f, 0.25f);
			//endTransformation();

			//setLineWidth(3.0f);

			//const vec2 center_of_rot(-0.4f, 0.0f);
			//drawWiredBox(Colors::skyblue, 0.5f, 0.25f);

			//translate(center_of_rot);
			//rotate(45.0f);
			//translate(-center_of_rot);
			//drawWiredBox(Colors::gold, 0.5f, 0.25f);
			//drawPoint(Colors::black, center_of_rot, 5.0f);

			setLineWidth(3.0f);

			rotate(time * 90.0f);

			translate(0.5f, 0.0f);
			rotate(time * 90.0f);
			scale(2.0f, 0.25f);
			drawWiredBox(Colors::gold, 0.5f, 0.5f);

			time += this->getTimeStep();
		}
	};
	class RotatingStarExample : public Game2D
	{
		float time = 0.0f;

	public:
		void update() override
		{
			rotate(time * 180.0f);

			drawWiredBox(Colors::blue, 0.4f, 0.25f);

			time += this->getTimeStep();
		}
	};
}

int main(void)
{
	//jm::TransformationsExample().run();
	jm::MouseExample().init("This is my digital canvas!", 1000, 1000, false).run();
	////jm::Game2D().init("This is my digital canvas!", 1280, 960, false).run();
	//jm::RotatingStarExample().init("Rotating Star Example!", 1280, 960, false).run();
	//jm::PrimitivesGallery().init("Primitive Gallery", 1280, 960, false).run();
	//jm::SolarSystem().run();
	//jm::FaceExample().run();
	//jm::WalkingPerson().run();
	//jm::TankExample().run();
	//jm::GundamExample().run();

	return 0;
}
