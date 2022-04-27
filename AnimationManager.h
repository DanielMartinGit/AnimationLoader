#pragma once
#include <iostream>
#include <vector>
#include "Framework/Animation.h"
#include "Framework/GameObject.h"
#include "nlohmann/json.hpp"
#include <fstream>

// @author Daniel Martin

class AnimationManager
{
	public:
		AnimationManager(); // Default constructor
		AnimationManager(Animation* currentAnim, GameObject* entity, int numberOfAnimations); // Overloaded Constructor 

		void loadInResources(const std::string spriteSheetPath, const std::string spriteSheetCoordsPath); // Used to load in required resources
		void setupAnimation(std::string animationName, int animationNumber); // Used to setup animations

		void animateEntity(float dt); // Call to animate entity
		
		void setAnimation(int animation) { currentAnim = &animations[animation]; } // call to set the entities animation
		sf::Texture& getSpriteSheet() { return spriteSheet; } // returns the loaded spritesheet
		Animation& getCurrentAnimation() { return *currentAnim; } // returns the current animation playing
		std::vector<Animation> getAnimations() { return animations; }

	private:
		struct frame // struct holidng information for each frame of animation created 
		{
			int frameNumber = 0;
			int x = 0;
			int y = 0;
			int width = 0;
			int height = 0;
		};

		nlohmann::json file; // JSON file variable to hold loaded JSON

		std::vector<Animation> animations; // vector to store all animations loaded for entity (0-idle_handgun, 1-move_handgun, 2-reload_handgun, 3-shoot_handgun)

		Animation* currentAnim; // stores the current animation playing
		GameObject* entity; // stores the entity using the AnimationManager

		sf::Texture spriteSheet; // used to store the loaded spritesheet for animations
};