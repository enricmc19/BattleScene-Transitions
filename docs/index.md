## Welcome to GitHub Pages

You can use the [editor on GitHub](https://github.com/enricmc19/BattleScene-Transitions/edit/main/docs/index.md) to maintain and preview the content for your website in Markdown files.

Whenever you commit to this repository, GitHub Pages will run [Jekyll](https://jekyllrb.com/) to rebuild the pages in your site, from the content in your Markdown files.

### Markdown

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for

```markdown
Syntax highlighted code block

# Header 1
## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

For more details see [GitHub Flavored Markdown](https://guides.github.com/features/mastering-markdown/).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/enricmc19/BattleScene-Transitions/settings/pages). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://docs.github.com/categories/github-pages-basics/) or [contact support](https://support.github.com/contact) and we’ll help you sort it out.


# Battle-Scene Transitions Research

Hello, my name is Enric Morales. I'm a student from the CITM (Image and Multimedia Technology Centre) of the UPC in Terrassa, and this is my own personal research under acknowledgement from my teacher Ramon Santamaría.

## What is a Battle-Transition?

Combat scene transitions are scene transitions from a segment of the gameplay or from a menu to a concrete scene, which in this case is a level or a battle scene, but transitions can be used either because we go to a different space, a different game mode or another completely different menu. Transitions are used all around every game in order to make the User Experience easier and comfortable than paying attention to a Power Point passing slides that change rudely from one to another without any care for what we see.

## How does a battle-transition work? A theorical explanation

Scene transitions work essentially as a distraction effect and a speed bump or slower. 

They are a time management tool in the same way as loading screens, although there is usually not much to do on a loading screen in an interactive way, at least until recent games from 2006 to nowadays interactive loading screens didn't have an extensive use. The difference between a transition is obviously the duration time, a super-extensive world that requires a certain power and load is camouflaged with a loading screen, while a simple pass to a different plant of a building in a top-down RPG from the 90's has not a huge load problem, so Screen Transitions are even used to set you into those long and boring loading screens with an animated bar and the charge percent which sometime add some images, lore from the game or brief tutorials that sometimes you never manage to read because loading time got faster than your reading time so you don't learn a game mechanic, at least not from that screen.

Scene Trransitions are usually short, but they are indicators that something different is starting, but in an environment which does not have to be much different from the one you are currently seeing. They are a step from one scene to another, which must leave the previous scene frozen and depending on what happens in the new scene, in this case the Battle-Scene, modify certain parameters of the previous scene in order to maintain consistency between what happens in one scene and the other.

So if you go to the battle screen, because you found a Pokemon, once you defeat or capture that Pokemon, once you get back to the gameplay or navigation screen in Pokemon's case, that creature, can't be there in that zone because in the battle-scene you decided what happenned to that creature in the game world itself.

As a videogame development student, I thought the best way to attack the process of creating a transition manager or scene manager is literally thinking about how transitions worked in theatres. Transitions in videogames can be explained as the same way in theatrical arts, because they tend to work in the same way.

## How does a battle-transition work? A practical explanation

Scene transitions can have a huge variability depending on the creativity and effort we put on them. Devs usually play with geometrical forms and it's colors, disposition, tone, brightness and movement.

I've looked for different styles of battle-transitions in videogames and I made a brief classification of two big groups of battle-transitions which I have called as it follows:

### The theatrical transition process but think like it's a game

So if a theatrical play has a stage with courtains, actors, background and some atrezzo.
In videogames we have: The scene itself, the actors are the player and tother characters in the world, and the background and atrezzo is set by the scene.

In a theatrical play a transition usually is made at the end of a scene, because their changes are guided by narrative.
In videogames transitions can be triggered by different factors such as entering to a building from outside, encountering a strange creature can cause a transition, grabbing an item can activate a transition, so we have even more possibilities.

In a theatrical play, courtains are attached to the stage, so when they close, they are pointing to the idea that when those courtains open up again, what you'll see, will be different to the previous scene.

In videogames we don't have courtains, so we create them with geometric forms, animations or textures and activate them. When a trigger is activated a chained screen states which follows the next order:

- Old scene (Gameplay/navigation in this case)
- Trigger (Something happens and activates the transition
- Pausing the action (Freeze previous scene)
- Easy in (Courtains
- Total blackness
- Easy out
- New Scene (Battle scene in this case)

This action chain tends to happen in every scene transition, but only if you are really changing from an scene, to another.


### HUD and Animations-centered transitions

This type of animation tends to be present in videogames where the direct action is a key factor of the game formula. In this case there's not usually a battle-scene, but a battle-state for the player itself. So we see that transition not properly in a screen effect, so we see the transition in the protagonist and the visual environment of the scene.

This kind of transitions happen when the player accesses a zone with enemies, changing the player state, because the combat system is integrated in the same scene

Practical exaamples of this kind of transitions are The Batman Arkham Trilogy, The Assassin's Creed saga, God of War, Prince of Persia, Call of Duty campaigns, The Division, Mad Max, Nier Automata, and a lot more...
