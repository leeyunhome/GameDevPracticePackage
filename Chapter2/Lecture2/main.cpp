#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include "Triangle.h"
#include "Circle.h"
#include "Box.h"

namespace jm
{
	class Example : public Game2D
	{
	public:
		Triangle my_tri;
		Circle my_cir;
		Box my_box;

		Example()
			: Game2D()
		{
			my_tri.init(Colors::gold, vec2{ -0.5f, 0.2f }, 0.25f);
			my_tri.color = Colors::gold;
			my_tri.pos = vec2{ -0.5f, 0.2f };
			my_tri.size = 0.25f;

			my_cir.init(Colors::olive, vec2{ 0.1f, 0.1f }, 0.2f);
			my_cir.pos = vec2{ 0.1f, 0.1f };
			my_cir.color = Colors::olive;
			my_cir.size = 0.2f;

			my_box.init(Colors::black, vec2{ 0.0f, 0.5f }, 0.2f, 0.3f);
		}

		void update() override
		{
			my_tri.draw();
			my_cir.draw();
			my_box.draw();

			// blue box
			//beginTransformation();
			//{
			//	translate(vec2{ 0.5f, 0.0f });
			//	drawFilledBox(Colors::blue, 0.25f, 0.3f);
			//}
			//endTransformation();
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
