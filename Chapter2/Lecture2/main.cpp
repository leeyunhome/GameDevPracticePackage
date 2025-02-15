#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include "Triangle.h"
#include "Circle.h"
#include "Box.h"
#define ARR_MAX_NUMBER 5
namespace jm
{
	class Example : public Game2D
	{
	public:
		
		Triangle my_tri[ARR_MAX_NUMBER];
		Circle my_cir[ARR_MAX_NUMBER];
		Box my_box[ARR_MAX_NUMBER];
		RandomNumberGenerator rnd;

		Example()
			: Game2D()
		{
			for (int iter = 0; iter < ARR_MAX_NUMBER; iter++)
			{
				my_tri[iter].init(Colors::gold, vec2{ -0.5f, 0.2f + iter * rnd.getFloat(-1.0f, 1.0f) }, 0.25f);
				my_cir[iter].init(Colors::olive, vec2{ 0.1f, 0.1f + iter * rnd.getFloat(-2.0f, 2.0f) }, 0.2f);
				my_box[iter].init(Colors::black, vec2{ 0.0f, 0.5f + iter * rnd.getFloat(-3.0f, 3.0f) }, 0.2f, 0.3f );
			}
			/*my_tri.init(Colors::gold, vec2{ -0.5f, 0.2f }, 0.25f);
			my_cir.init(Colors::olive, vec2{ 0.1f, 0.1f }, 0.2f);
			my_box.init(Colors::black, vec2{ 0.0f, 0.5f }, 0.2f, 0.3f);*/
		}

		void update() override
		{
			for (int i = 0; i < 5; ++i)
				my_tri[i].draw();

			for (int i = 0; i < 5; ++i)
				my_cir[i].draw();

			for (int i = 0; i < 5; ++i)
				my_box[i].draw();

			//my_tri.draw();
			//my_cir.draw();
			//my_box.draw();

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
