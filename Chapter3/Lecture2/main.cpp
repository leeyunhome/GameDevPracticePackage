#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include "RigidCircle.h"
#include <vector>
#include <memory>

namespace jm
{
	class Example : public Game2D
	{
	public:
		RigidCircle rb0, rb1;

		Example()
			: Game2D()
		{
			reset();
		}

		void reset()
		{
			// Initial position and velocity
			rb0.pos = vec2(-0.8f, 0.3f);
			rb0.vel = vec2(2.0f, 0.0f);
			rb0.color = Colors::hotpink;
			rb0.radius = 0.1f;
			rb0.mass = 1.0f;

			rb1.pos = vec2(0.8f, 0.3f);
			rb1.vel = vec2(-2.0f, 0.0f);
			rb1.color = Colors::yellow;
			rb1.radius = 0.15f;
			rb1.mass = rb0.mass * std::pow(rb1.radius / rb0.radius, 2.0f);
		}

		void drawWall()
		{
			setLineWidth(5.0f);
			drawLine(Colors::blue, { -1.0f, -1.0f }, Colors::blue, { 1.0f, -1.0f });
			drawLine(Colors::blue, { 1.0f, -1.0f }, Colors::blue, { 1.0f, 1.0f });
			drawLine(Colors::blue, { -1.0f, -1.0f }, Colors::blue, { -1.0f, 1.0f });
		}

		void update() override
		{
			const float dt = getTimeStep() * 0.1f;

			// physics update
			rb0.update(dt);
			rb1.update(dt);

			// check collision between two rigid bodies

			// compute impulse

			// update velocities of two bodies

			// draw
			drawWall();
			rb0.draw();
			rb1.draw();

			// reset button
			if (isKeyPressedAndReleased(GLFW_KEY_R)) reset();
		}
	};
}

int main(void)
{
	jm::Example().run();

	return 0;
}
