#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"

namespace jm
{
	class House
	{
	private:
		RGB roof_color;
		vec2 pos;
		float angle = 0.0f;

	public:
		House()
			: roof_color(Colors::red), pos(0.0f, 0.0f), angle(0.0f)
		{}

		void setPosition(const vec2& _pos)
		{
			pos = _pos;
		}

		void setAngle(const float _angle)
		{
			angle = _angle;
		}

		void setRoofColor(const RGB& _color)
		{
			roof_color = _color;
		}

		void draw()
		{
			// draw a house
			beginTransformation();
			{
				translate(pos);
				rotate(angle);

				// wall
				drawFilledBox(Colors::yellow, 0.2f, 0.2f);

				// roof
				drawFilledTriangle(roof_color, { -0.13f, 0.1f }, { 0.13f, 0.1f }, { 0.0f, 0.2f });
				drawWiredTriangle(roof_color, { -0.13f, 0.1f }, { 0.13f, 0.1f }, { 0.0f, 0.2f });

				// window
				drawFilledBox(Colors::skyblue, 0.1f, 0.1f);
				drawWiredBox(Colors::gray, 0.1f, 0.1f);
				drawLine(Colors::gray, { 0.0f, -0.05f }, Colors::gray, { 0.0f, 0.05f });
				drawLine(Colors::gray, { -0.05f, 0.0f }, Colors::gray, { 0.05f, 0.0f });

			}
			endTransformation();
		}
	};
	

	class Example : public Game2D
	{
		float time = 0.0f;
	public:
		House houses[10];

		Example()
			: Game2D()
		{
			RandomNumberGenerator rnd;


			for (int i = 0; i < 10; ++i)
			{
				houses[i].setPosition(vec2{ -1.3f + 0.3f * float(i), rnd.getFloat(-0.5f, 0.5f) });
				houses[i].setRoofColor(RGB(100 * rnd.getInt(0, i), rnd.getInt(0, i * 3), 300));
				
			}
		}
		void update() override
		{
			/*House left_house, center_house, right_house;

			left_house.setPosition(vec2{ -0.5f, 0.0f });
			center_house.setPosition(vec2{ 0.0f, 0.0f });
			center_house.setAngle(10.0f);
			center_house.setRoofColor(Colors::gold);
			right_house.setPosition(vec2{ 0.5f, 0.0f });

			left_house.draw();
			center_house.draw();
			right_house.draw();*/

			//const int number_of_house = 10;
			//House houses[number_of_house];

			//for (float iter = 0, width = 0.1f; iter < number_of_house; iter++, width += 0.05f)
			//{
			//	houses[(int)iter].setRoofColor(Colors::black);
			//	houses[(int)iter].setPosition({ -1.0f + width, width });
			//	houses[(int)iter].draw();

			//}
			
			//drawHouse(vec2(0.0f, 0.0f));
			//drawHouse(Colors::red, { -0.5f, 0.0f }, 0.0f);
			//drawHouse(Colors::blue, { 0.0f, 0.0f }, 10.0f);
			//drawHouse(Colors::olive, { 0.5f, 0.0f }, 0.0f);

			

			for (int i = 0; i < 10; ++i)
			{
				houses[i].draw();
				if (0 == i % 2)
				{
					houses[i].setAngle(90.0f * time);
				}
				time += getTimeStep();
			}
		}
	};
}

int main(void)
{
	jm::Example().run();
	//jm::Game2D().init("This is my digital canvas!", 1280, 960, false).run();
	//jm::PrimitivesGallery().run();
	
	return 0;
}
