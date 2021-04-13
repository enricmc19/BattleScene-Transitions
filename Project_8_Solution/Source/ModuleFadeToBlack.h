#ifndef __MODULEFADETOBLACK_H__
#define __MODULEFADETOBLACK_H__

#include "Module.h"
#include "easings.h"
#include "SDL\include\SDL_rect.h"

class ModuleFadeToBlack : public Module
{
public:
	//Constructor
	ModuleFadeToBlack(bool startEnabled);

	//Destructor
	~ModuleFadeToBlack();

	// Called when the module is activated
	// Enables the blending mode for transparency
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the fade logic
	Update_Status Update() override;

	// Called at the end of the application loop
	// Performs the render call of a black rectangle with transparency
	Update_Status PostUpdate() override;

	// Called from another module
	// Starts the fade process which has two steps, fade_out and fade_in
	// After the first step, the modules should be switched
	bool FadeToBlack(Module* toDisable, Module* toEnable, float frames = 90);
    int animID = 0;
private:

	enum Fade_Step
	{
		NONE,
		TO_BLACK,
		FROM_BLACK
	} currentStep = Fade_Step::NONE;

	// A frame count system to handle the fade time and ratio
	Uint32 framesCounter = 0;
	Uint32 maxFadeFrames = 0;
	

	// The rectangles of the screen, used to render the animation
	SDL_Rect screenRect;
	SDL_Rect transit1;
	SDL_Rect transit2;
	SDL_Rect transit3;
	SDL_Rect transit4;
	SDL_Rect transit5{-SCREEN_WIDTH};
	SDL_Rect transit6{2*SCREEN_WIDTH};
	

	// The modules that should be switched after the first step
	Module* moduleToEnable = nullptr;
	Module* moduleToDisable = nullptr;

	void transition1();
	void transition2();
	void transition3();
	void transition4();
};

#endif //__MODULEFADETOBLACK_H__