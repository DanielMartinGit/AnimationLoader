#include "AnimationManager.h"

AnimationManager::AnimationManager() { currentAnim = nullptr; entity = nullptr; }
AnimationManager::AnimationManager(Animation* currentAnimation, GameObject* entity, int numberOfAnimations)
{
	if (currentAnim == nullptr)
		std::cout << "Current Animation not set!";
	
	this->entity = entity; // sets the variable "entity" to the GameObject passed in the parameter
	currentAnim = currentAnimation; // Used to get access to the GameObjects "currentAnimation" variable

	for (size_t i = 0; i < numberOfAnimations; ++i) // loops throught until i is equal to "animationNumber"
	{
		Animation animation = Animation(); // creates a new Animation
		animation.setFrameSpeed(.5f / 10.0f); // sets the animations frame speed

		animations.push_back(animation); // pushes that created animation into the animations vector
	}
}

void AnimationManager::loadInResources(std::string spriteSheetPath, std::string spriteSheetCoordsPath) // method used for loading in all needed resources
{	
	if (!spriteSheet.loadFromFile(spriteSheetPath)) // if the spritesheet cannot be found
	{
		std::cout << "Spritesheet failed to load!"; // print out telling the user 
	}

	std::ifstream filePath(spriteSheetCoordsPath); // create a new ifStream called "filePath" and load in the file specified with "spriteSheetCoordsPath"
	filePath >> file; // copy all contents of the loaded file into the JSON
}

void AnimationManager::setupAnimation(std::string animationName, int animationNumber) // used to setup each animation passing in the name and index from "animations"
{
	if (animationNumber > animations.size()) // if the animation nummber entered is larger than the vector size
	{
		std::cout << "Player Animations size is less then animation number"; // tell the user
		return; // return out of method
	}

	for (int line = 0; line < file[animationName].size(); line++) // for loop used to iterate through the file using the animation name
	{
		frame currentFrame; // creates a new instance of the struct "frame" called "currentFrame"
		currentFrame.frameNumber = file[animationName][line]["frame"]; // sets the "currentFrame" frameNumber to the key "frame" from the object with the animation name
		currentFrame.x = file[animationName][line]["x"];  // sets the "currentFrame" x to the key "x" from the object with the animation name
		currentFrame.y = file[animationName][line]["y"];  // sets the "currentFrame" y to the key "y" from the object with the animation name
		currentFrame.width = file[animationName][line]["width"];  // sets the "currentFrame" frameNumber to the key "width" from the object with the animation name
		currentFrame.height = file[animationName][line]["height"];  // sets the "currentFrame" frameNumber to the key "height" from the object with the animation name
		std::cout << animationName << " frame loaded: " << currentFrame.frameNumber << std::endl;  // outputs what frame has been loaded to the console
		animations[animationNumber].addFrame(sf::IntRect(currentFrame.x, currentFrame.y, currentFrame.width, currentFrame.height));  // adds that current frame to the animations animation stored at the index "animationNumber"
	}

	std::cout << "\nNumber of Frames loaded: " << animations[animationNumber].getSize() << std::endl; // prints out how many frames have been loaded for this animation
}

void AnimationManager::animateEntity(float dt) // used to animate the entity
{
	currentAnim->animate(dt); // calls the current animations animate method
	entity->setTextureRect(currentAnim->getCurrentFrame()); // sets the entities textureRect to the current frame of the animation
}