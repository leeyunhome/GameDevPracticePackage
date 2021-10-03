#pragma once

#include "Game2D.h"

namespace jm
{
	/*
	TODO:
	- add left arm and left leg
	- make a Person class and use it to draw many people.
	- make an Ironman and allow for him to shoot repulsor beam with his right hand
	*/
	class Earth
	{
	public:
		void draw()
		{
			// earth
			beginTransformation();
			translate(0.0f, -0.8f);
			drawFilledBox(Colors::gray, 2.0f, 0.1f);
			endTransformation();
		}
	};

	class Person
	{
		float time = 0.0f;

	public:
		void draw(float time)
		{
			// gold face
			beginTransformation();
			translate(0.0f, 0.12f);
			drawFilledCircle(Colors::gold, 0.08f);
			translate(0.05f, 0.03f);
			drawFilledCircle(Colors::white, 0.01f); // while eye

			endTransformation();

			// yellow left arm
			beginTransformation();
			rotate(sin(time * 5.0f) * -30.0f);					// animation!
			scale(1.0f, 2.0f);
			translate(0.0f, -0.1f);
			drawFilledBox(Colors::yellow, 0.05f, 0.18f);
			endTransformation();

			// green left leg
			beginTransformation();
			translate(0.0f, -0.6f);
			translate(0.0f, 0.2f);
			rotate(sinf(time * 5.0f + 3.141592f) * -30.0f);	// animation!
			translate(0.0f, -0.2f);
			drawFilledBox(Colors::green, 0.1f, 0.4f);
			endTransformation();

			// red body
			beginTransformation();
			scale(1.0f, 2.0f);
			translate(0.0f, -0.1f);
			drawFilledBox(Colors::red, 0.13f, 0.2f);
			endTransformation();

			// yellow right arm
			beginTransformation();
			rotate(sin(time * 5.0f) * 30.0f);					// animation!
			scale(1.0f, 2.0f);
			translate(0.0f, -0.1f);
			drawFilledBox(Colors::yellow, 0.05f, 0.18f);
			endTransformation();



			// green right leg
			beginTransformation();
			translate(0.0f, -0.6f);
			translate(0.0f, 0.2f);
			rotate(sinf(time * 5.0f + 3.141592f) * 30.0f);	// animation!
			translate(0.0f, -0.2f);
			drawFilledBox(Colors::green, 0.1f, 0.4f);
			endTransformation();

			//time += this->getTimeStep();
		}
		
	};

	class WalkingPerson : public Game2D
	{
		Person person;
		Earth earth;

		float time = 0.0f;

	public:
		WalkingPerson()
		{}
		~WalkingPerson()
		{}

		void update() override
		{
			earth.draw();


			if (isKeyPressedAndReleased(GLFW_KEY_SPACE)) translate(0.0f, 0.2f);


			//if (isKeyPressed(GLFW_KEY_SPACE))
			//{
			//};

			//person.draw(time);
			/*translate(0.25f, 0.25f);
			person.draw(time);
			person.draw(time);
			translate(0.25f, 0.0f);
			person.draw(time);*/
			translate(0.25f, 0.0f);
			person.draw(time);

			time += this->getTimeStep();
		}
	};
}