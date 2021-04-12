#include "ModuleFadeToBlack.h"

#include "Application.h"
#include "ModuleRender.h"
#include "easings.h"
#include "ModuleRender.h"

#include "SDL/include/SDL_render.h"



ModuleFadeToBlack::ModuleFadeToBlack(bool startEnabled) : Module(startEnabled)
{
	screenRect = {0, 0, SCREEN_WIDTH * SCREEN_SIZE, SCREEN_HEIGHT * SCREEN_SIZE};
}

ModuleFadeToBlack::~ModuleFadeToBlack()
{

}

bool ModuleFadeToBlack::Start()
{
	LOG("Preparing Fade Screen");

	// Enable blending mode for transparency
	SDL_SetRenderDrawBlendMode(App->render->renderer, SDL_BLENDMODE_BLEND);

	return true;
}

Update_Status ModuleFadeToBlack::Update()
{
	// Exit this function if we are not performing a fade
	if (currentStep == Fade_Step::NONE) return Update_Status::UPDATE_CONTINUE;

	if (currentStep == Fade_Step::TO_BLACK)
	{
		++framesCounter;
		if (framesCounter >= maxFadeFrames)
		{
			// TODO 1: Enable / disable the modules received when FadeToBlacks() gets called
			moduleToDisable->Disable();
			moduleToEnable->Enable();
			animID++;

			currentStep = Fade_Step::FROM_BLACK;
		}
	}
	else
	{
		--framesCounter;
		if (framesCounter <= 0)
		{
			currentStep = Fade_Step::NONE;
		}
	}

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleFadeToBlack::PostUpdate()
{
	// Exit this function if we are not performing a fade
	if (currentStep == Fade_Step::NONE) 
	return Update_Status::UPDATE_CONTINUE;
	
	switch (animID)
	{
	case 0:
		transition1();
		break;
	case 1:
		transition2();
		break;
	case 2:
		transition3();
		break;
	};

	//float fadeRatio = (float)framesCounter / (float)maxFadeFrames;

	// Render the black square with alpha on the screen
	//SDL_SetRenderDrawColor(App->render->renderer, 255, 0, 0, (Uint8)(fadeRatio * 255.0f));
	//SDL_RenderFillRect(App->render->renderer, &screenRect);
	

	return Update_Status::UPDATE_CONTINUE;
}

bool ModuleFadeToBlack::FadeToBlack(Module* moduleToDisable, Module* moduleToEnable, float frames)
{
	bool ret = false;

	// If we are already in a fade process, ignore this call
	if(currentStep == Fade_Step::NONE)
	{
		currentStep = Fade_Step::TO_BLACK;
		framesCounter = 0;
		maxFadeFrames = frames;

		// TODO 1: We need to keep track of the modules received in FadeToBlack(...)
		this->moduleToDisable = moduleToDisable;
		this->moduleToEnable = moduleToEnable;

		ret = true;
	}

	return ret;
}

void ModuleFadeToBlack::transition1()
{
	SDL_SetRenderDrawColor(App->render->renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(App->render->renderer, &transit1);
    transit1.x = 0;
	transit1.y = 0;
	transit1.h = EaseBounceInOut(framesCounter,SCREEN_HEIGHT/8, SCREEN_HEIGHT, 60);
	transit1.w = EaseBounceInOut(framesCounter, SCREEN_WIDTH/8, SCREEN_WIDTH, 60);
		
}

void ModuleFadeToBlack::transition2()
{
	float fadeRatio = (float)framesCounter / (float)maxFadeFrames;
	SDL_SetRenderDrawColor(App->render->renderer, 255, 0, 0, (Uint8)(fadeRatio * 255.0f));
	SDL_RenderFillRect(App->render->renderer, &screenRect);
}

void ModuleFadeToBlack::transition3()
{
	SDL_SetRenderDrawColor(App->render->renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(App->render->renderer, &transit1);
	SDL_SetRenderDrawColor(App->render->renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(App->render->renderer, &transit2);
	SDL_SetRenderDrawColor(App->render->renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(App->render->renderer, &transit3);
	SDL_SetRenderDrawColor(App->render->renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(App->render->renderer, &transit4);

    transit1.x = 0;
	transit1.y = 0;
	transit1.h = EaseBounceInOut(framesCounter, SCREEN_HEIGHT/8, SCREEN_HEIGHT, 60);
	transit1.w = EaseBounceInOut(framesCounter, SCREEN_WIDTH/8, SCREEN_WIDTH, 60);
	
    transit2.x = 384 * SCREEN_SIZE;
	transit2.y = 240 * SCREEN_SIZE;
	transit2.h = EaseBounceInOut(framesCounter, SCREEN_HEIGHT/8, -SCREEN_HEIGHT, 60);
	transit2.w = EaseBounceInOut(framesCounter, SCREEN_WIDTH/8, -SCREEN_WIDTH, 60);
	
    transit3.x = 0 * SCREEN_SIZE;
	transit3.y = 240 * SCREEN_SIZE;
	transit3.h = EaseBounceInOut(framesCounter, SCREEN_HEIGHT/8, -SCREEN_HEIGHT, 60);
	transit3.w = EaseBounceInOut(framesCounter, -SCREEN_WIDTH/8 , SCREEN_WIDTH, 60);
	
    transit4.x = 384 * SCREEN_SIZE;
	transit4.y = 0 * SCREEN_SIZE;
	transit4.h = EaseBounceInOut(framesCounter, -SCREEN_HEIGHT/8, SCREEN_HEIGHT, 60);
	transit4.w = EaseBounceInOut(framesCounter, SCREEN_WIDTH/8, -SCREEN_WIDTH, 60);
	
}

void ModuleFadeToBlack::transition4()
{
	
}
