#include "Game2D.h"
#include "PrimitivesGallery.h"
#include "TankExample.h"
#include "FaceExample.h"
#include "WalkingPerson.h"
#include "SolarSystem.h"

namespace jm
{
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
	////jm::MouseExample().init("This is my digital canvas!", 1000, 1000, false).run();
	////jm::Game2D().init("This is my digital canvas!", 1280, 960, false).run();
	jm::RotatingStarExample().init("Rotating Star Example!", 1280, 960, false).run();
	//jm::PrimitivesGallery().init("Primitive Gallery", 1280, 960, false).run();
	////jm::SolarSystem().run();
	////jm::FaceExample().run();
	////jm::WalkingPerson().run();
	////jm::TankExample().run();

	return 0;
}
