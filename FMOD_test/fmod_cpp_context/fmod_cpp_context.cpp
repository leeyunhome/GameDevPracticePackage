//#include "fmod.h"  // c-context
#include "fmod.hpp"
#include <iostream>

using namespace std;

int main()
{
	cout << "FMOD cpp conext example" << endl;

	FMOD::System     *system(nullptr);
	FMOD::Sound      *sound(nullptr);
	FMOD::Channel    *channel(nullptr);
	FMOD_RESULT       result;
	unsigned int      version;
	void             *extradriverdata(nullptr);

	result = FMOD::System_Create(&system);
	if (result != FMOD_OK) return -1;
	
	result = system->getVersion(&version);
	if (result != FMOD_OK) return -1;
	else printf("FMOD version %08x\n", version);

	result = system->init(32, FMOD_INIT_NORMAL, extradriverdata);
	if (result != FMOD_OK) return -1;

	result = system->createSound("swish.wav", FMOD_LOOP_NORMAL, 0, &sound);
	if (result != FMOD_OK) return -1;

	result = system->playSound(sound, 0, false, &channel);
	if (result != FMOD_OK) return -1;

	bool playing = false;

	while (true)
	{
		result = system->update();
		if (result != FMOD_OK) return -1;

		/*if (channel)
		{
			FMOD::Sound *currentsound = 0;

			result = channel->isPlaying(&playing);

			if (!playing) break;
		}*/

		cout << "0 pause, 1 resume" << endl;

		int i;
		cin >> i;

		if (i == 0)
			channel->setPaused(true);
		else if (i == 1)
			channel->setPaused(false);
	}
}
