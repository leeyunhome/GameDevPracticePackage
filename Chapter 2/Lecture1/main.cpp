#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include "House.h"

namespace jm
{
	class Example : public Game2D
	{
	public:
		//House house1, house2, house3;
		House house[3];

		Example()
			: Game2D()
		{
			house[0] = House{ vec2(0.0f, 0.0f), 0.0f, Colors::red };
			house[1] = House{ vec2(-0.5f, 0.0f), 0.0f, Colors::blue };
			house[2] = House{ vec2(0.5f, 0.0f), 10.0f, Colors::black };
		}

		void update() override
		{
			for (int i = 0; i < 3; ++i)
				house[i].draw();			
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
