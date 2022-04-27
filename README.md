# AnimationLoader
This Animation Loader was written during my first year of University.

# About
This tool was used during my First year in University. My initial problem was that my sprite sheet had around 10-13 animations, each with 1-15 frames. Handling all this by hand would have been time consuming and I would have never got any work done. This is where I came up with the solution to write a class that handles loading in the frames and setting up the animations for me. 

# Steps taken
1) Design the API for the class and what its functions would be 
2) Find a tool that would take all the individual sprites and put them all into a single spritesheet
3) Have each sprites x, y, width and height exported into a txt file 
4) Sort the frames information into a JSON format for easy readability 
5) Assign each Animation a name and each frame with a number with the corresponding x, y, width and height
6) Load each frame to do with an animation into the class and assign them to a new Animation object 
7) Add the finished animation to a Vector to store

# API
Loading the Spritesheet with the corresponding JSON file - animManager.loadInResources("Resources/Sprites/Animations/Player/playerSpritesheet.png", "Resources/Sprites/Animations/Player/Spritesheet.json");

Loading each animation inside the JSON into the animation loader, passing in the Animation name and the index used to store the animation - 
animManager.setupAnimation("idle_knife", 0);
animManager.setupAnimation("shoot_handgun", 5);
animManager.setupAnimation("reload_handgun", 6);
animManager.setupAnimation("shoot_rifle", 9);
animManager.setupAnimation("reload_rifle", 10);
