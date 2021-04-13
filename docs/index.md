# Battle-Scene Transitions Research

Hello, my name is Enric Morales. I'm a student from the CITM (Image and Multimedia Technology Centre) of the UPC in Terrassa, and this is my own personal research under acknowledgement from my teacher [Ramón Santamaría](https://github.com/raysan5).

## What is a Battle-Transition?

Combat scene transitions are scene transitions from a segment of the gameplay or from a menu to a concrete scene, which in this case is a level or a battle scene, but transitions can be used either because we go to a different space, a different game mode or another completely different menu. Transitions are used all around every game in order to make the User Experience easier and comfortable than paying attention to a Power Point passing slides that change rudely from one to another without any care for what we see.

## How does a battle-transition work? A theorical explanation

Scene transitions work essentially as a distraction effect and a speed bump or slow pacer. 

They are a time management tool in the same way as loading screens, although there is usually not much to do on a loading screen in an interactive way, at least until recent games from nowadays interactive loading screens didn't have an extensive use. The difference between a transition is obviously the duration time, a super-extensive world that requires a certain power and load is camouflaged with a loading screen, while a simple pass to a different plant of a building in a top-down RPG from the 90's has not a huge load problem, so Screen Transitions are even used to set you into those long and boring loading screens with an animated bar and the charge percent which sometime add some images, lore from the game or brief tutorials that sometimes you never manage to read because loading time got faster than your reading time so you don't learn a game mechanic, at least not from that screen.

Scene Transitions are usually short, but they are indicators that something different is starting, but in an environment which does not have to be much different from the one you are currently seeing. They are a step from one scene to another, which must leave the previous scene frozen and depending on what happens in the new scene, in this case the Battle-Scene, modify certain parameters of the previous scene in order to maintain consistency between what happens in one scene and the other.

So if you go to the battle screen, because you found a Pokemon, once you defeat or capture that Pokemon, once you get back to the gameplay or navigation screen in Pokemon's case, that creature, can't be there in that zone because in the battle-scene you decided what happenned to that creature in the game world itself.

As a videogame development student, I thought the best way to attack the process of creating a transition manager or scene manager is literally thinking about how transitions worked in theatres. Transitions in videogames can be explained as the same way in theatrical arts, because they tend to work in the same way.

## How does a battle-transition work? A practical explanation

Scene transitions can have a huge variability depending on the creativity and effort we put on them. Devs usually play with geometrical forms and it's colors, disposition, tone, brightness and movement.

I've looked for different styles of battle-transitions in videogames and I made a brief classification of two big groups of battle-transitions which I have called as it follows:

### The theatrical transition process

So if a theatrical play has a stage with courtains, actors, background and some atrezzo.
In videogames we have: The scene itself, the actors are the player and tother characters in the world, and the background and atrezzo is set by the scene.

In a theatrical play a transition usually is made at the end of a scene, because their changes are guided by narrative.
In videogames transitions can be triggered by different factors such as entering to a building from outside, encountering a strange creature can cause a transition, grabbing an item can activate a transition, so we have even more possibilities.

In a theatrical play, courtains are attached to the stage, so when they close, they are pointing to the idea that when those courtains open up again, what you'll see, will be different to the previous scene.

In videogames we don't have courtains, so we create them with geometric forms, animations or textures and activate them. When a trigger is activated a chained screen states which follows the next order:

- Old scene (Gameplay/navigation in this case)
- Trigger (Something happens and activates the transition)
- Pausing the action (Freeze previous scene)
- Easy in (Courtains go to the center till we see no stage)
- Total blackness
- Easy out (Courtains return to a position wich let's us see the next scene)
- New Scene (Battle scene in this case)

This action chain tends to happen in every scene transition, but only if you are really changing from an scene, to another.

For example we see this kind of transition in games like Final Fantasy, Pokemon or Octopath Traveller

They can use a high variability of transitions, from fade to black, or playing with the position of the hud menu


### Player state transitions

This type of animation tends to be present in videogames where the direct interaction is a key factor of the game formula. In this case there's not usually a battle-scene, but a battle-state for the player itself. So we see that transition not properly in a screen effect, so we see the transition in the protagonist and the visual environment of the scene.

This kind of transitions happen when the player accesses a zone with enemies, changing the player state, because the combat system is integrated in the same scene.

Music gets higher volume, it's in someway a kind off like hearing somebody say "Let the games begin" like in some kind of Smack Down Event or a show similar to that.

The point here is to set a mood for that moment and then calm so we make the stress go up, fight, defeat and when defeated the enemy calm down the action.

Practical examples of this kind of transitions are The Batman Arkham Trilogy, The Assassin's Creed saga, God of War on PS4, Prince of Persia, Call of Duty campaigns, The Division, Mad Max, Nier Automata, and a lot more...

## Transition Examples

[Octopath Traveller](https://www.youtube.com/watch?v=kCtt-gomGE4)

[Final Fantasy VII](https://www.youtube.com/watch?v=KhSicdniIng)

[Prince of Persia: Two Thrones](https://www.youtube.com/watch?v=Yg0WVESEn6I)

[Batman Arkham Asylum](https://www.youtube.com/watch?v=yj4Qw6PMlvk)

[Assassin's Creed Unity](https://www.youtube.com/watch?v=WGRSIIrPISE)

[Pokemon Battle Transition Evolution](https://www.youtube.com/watch?v=FM--loS9hIk)

[Pokemon Sapphire](https://www.youtube.com/watch?v=z-ktLPl9aRg&t=6609s)

[Mad Max](https://www.youtube.com/watch?v=E5lDmbqMqvo)

[Persona 5](https://www.youtube.com/watch?v=f3bVM2mxh4k)

[Dragon Quest Evolution](https://www.youtube.com/watch?v=krWnXelYEKQ)

## Conclusions

During my research I found different forms of making transitions, either in films or videogames and found reddit discussions about how to make transitions or what's the most used or seen in both arts. And most of the people agree that it isn't needed a great effort on it, it's just a bunch of seconds for taking the player/spectator from point A to B or viceversa. So doesn't matter how simple or complicated while it makes the transition smooth without converting the transition itself into an entire videoclip, making the player loose the focus.

In brief words: Try to make it easy, keep it smooth, but remember sky is the limit, so at least make transitions according to what you're going to explain and if you want to make it a big bigger give it a try.

## Code

These are the libraries included in teh ModuleFadeToBlack.cpp
 ```
 #include "ModuleFadeToBlack.h"

#include "Application.h"
#include "ModuleRender.h"
#include "easings.h"
#include "ModuleRender.h"

#include "SDL/include/SDL_render.h"
 ```
 
 All the next lines work because of the existence of the FadeToBlack function, which sets the modules that have to be enabled or disabled and set the transition frame value
 
 ```
 bool ModuleFadeToBlack::FadeToBlack(Module* moduleToDisable, Module* moduleToEnable, float frames)
{
	bool ret = false;

	// If we are already in a fade process, ignore this call
	if(currentStep == Fade_Step::NONE)
	{
		currentStep = Fade_Step::TO_BLACK;
		framesCounter = 0;
		maxFadeFrames = frames;

		// We need to keep track of the modules received in FadeToBlack(...)
		this->moduleToDisable = moduleToDisable;
		this->moduleToEnable = moduleToEnable;

		ret = true;
	}

	return ret;
}
```
 The update process consists in stablish if a fade it's going to happen with the Fade_Steps, so if Fade_Step is ```TO_BLACK``` we disable the actual scene and enable the next one, so the Post Update can draw the transition. The variable animID is changed in order to never get a value over the number of transitions we have and play them correctly.
 ```
 Update_Status ModuleFadeToBlack::Update()
{
	// Exit this function if we are not performing a fade
	if (currentStep == Fade_Step::NONE) return Update_Status::UPDATE_CONTINUE;

	if (currentStep == Fade_Step::TO_BLACK)
	{
		++framesCounter;
		if (framesCounter >= maxFadeFrames)
		{
			
			moduleToDisable->Disable();
			moduleToEnable->Enable();
			

			currentStep = Fade_Step::FROM_BLACK;
		}
	}
	else
	{
		--framesCounter;
		if (framesCounter <= 0)
		{
			animID++;
			if (animID > 3) 
			{
				animID = 0;
			}
			currentStep = Fade_Step::NONE;
		}
	}

	return Update_Status::UPDATE_CONTINUE;
}
````
The post update calls our self made transition functions depending on the animID value

```
Update_Status ModuleFadeToBlack::PostUpdate()
{
	// Exit this function if we are not performing a fade
	if (currentStep == Fade_Step::NONE) 
	return Update_Status::UPDATE_CONTINUE;
	
	if(animID==0)
	{
		transition1();
	}
	else if (animID == 1) 
	{
		transition2();
	}
	else if (animID == 2) 
	{
		transition3();
	}
	else if (animID == 3) 
	{
		transition4();
	}
	else if (animID > 3) 
	{
		animID == 0;
	}
	
	return Update_Status::UPDATE_CONTINUE;
 ```

And these are the transition functions made with easings and a fade to black

```
void ModuleFadeToBlack::transition1() //Left upper edge of the screen square covers all the screen and goes backwards
{
	SDL_SetRenderDrawColor(App->render->renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(App->render->renderer, &transit1);
    transit1.x = 0;
	transit1.y = 0;
	transit1.h = EaseBounceInOut(framesCounter,SCREEN_HEIGHT/8, SCREEN_HEIGHT, 45);
	transit1.w = EaseBounceInOut(framesCounter, SCREEN_WIDTH/8, SCREEN_WIDTH, 45);
		
}

void ModuleFadeToBlack::transition2() // Fade to black
{
	float fadeRatio = (float)framesCounter / (float)maxFadeFrames;
	SDL_SetRenderDrawColor(App->render->renderer, 255, 0, 0, (Uint8)(fadeRatio * 255.0f));
	SDL_RenderFillRect(App->render->renderer, &screenRect);
}

void ModuleFadeToBlack::transition3() // All four edges merge overlapping the screen
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
	transit1.h = EaseBounceInOut(framesCounter, SCREEN_HEIGHT/8, SCREEN_HEIGHT, 45);
	transit1.w = EaseBounceInOut(framesCounter, SCREEN_WIDTH/8, SCREEN_WIDTH, 45);
	
    transit2.x = 384 * SCREEN_SIZE;
	transit2.y = 240 * SCREEN_SIZE;
	transit2.h = EaseBounceInOut(framesCounter, SCREEN_HEIGHT/8, -SCREEN_HEIGHT, 45);
	transit2.w = EaseBounceInOut(framesCounter, SCREEN_WIDTH/8, -SCREEN_WIDTH, 45);
	
    transit3.x = 0 * SCREEN_SIZE;
	transit3.y = 240 * SCREEN_SIZE;
	transit3.h = EaseBounceInOut(framesCounter, SCREEN_HEIGHT/8, -SCREEN_HEIGHT, 45);
	transit3.w = EaseBounceInOut(framesCounter, -SCREEN_WIDTH/8 , SCREEN_WIDTH, 45);
	
    transit4.x = 384 * SCREEN_SIZE;
	transit4.y = 0 * SCREEN_SIZE;
	transit4.h = EaseBounceInOut(framesCounter, -SCREEN_HEIGHT/8, SCREEN_HEIGHT, 45);
	transit4.w = EaseBounceInOut(framesCounter, SCREEN_WIDTH/8, -SCREEN_WIDTH, 45);
	
}

void ModuleFadeToBlack::transition4() //Trying to make two rectangles move to screen centre and get back
{
	SDL_SetRenderDrawColor(App->render->renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(App->render->renderer, &transit5);
	SDL_SetRenderDrawColor(App->render->renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(App->render->renderer, &transit6);

	transit5.h = SCREEN_HEIGHT / 2 * SCREEN_SIZE;
	transit5.w= EaseLinearInOut(framesCounter, 0, SCREEN_WIDTH*SCREEN_SIZE, 45);
	transit5.x = 0 * SCREEN_SIZE;
	transit5.y = 0 * SCREEN_SIZE;		

	transit6.h = SCREEN_HEIGHT / 2 * SCREEN_SIZE;
	transit6.w = EaseLinearOut(framesCounter, SCREEN_WIDTH*SCREEN_SIZE, -SCREEN_WIDTH * SCREEN_SIZE, 45);
	transit6.x = SCREEN_WIDTH * SCREEN_SIZE;
	transit6.y = SCREEN_HEIGHT/2 * SCREEN_SIZE;
	
}
```
## Documentation

[Transition Guidelines Examples](http://www.davetech.co.uk/screentransitions)

[Transitions Discussion Reddit](https://www.reddit.com/r/letsplay/comments/3y8w1y/lets_talk_transitions/)
