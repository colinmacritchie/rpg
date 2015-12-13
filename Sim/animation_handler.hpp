#ifndef ANIMATION_HANDLER_HPP
#define ANIMATION_HANDLER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Animation {

    public:

    unsigned int startFrame;
    unsigned int endFrame;

    float duration;

    Animation(unsigned int startFrame, unsigned int endFrame, float duration) {
        
        this->startFrame = startFrame;
        this->endFrame = endFrame;
        this->duration = duration;
    }

    unsigned int getLength() { return endFrame - startFrame + 1; }
};

class AnimationHandler {

    private:

    /* Araay of animation */
    std::vector<Animation> animations;

    /* Current time since the animation loop started */
    float t;

    int currentAnim;

    public:

    /* Add a new animation */
    void addAnim(const float dt);

    /* Chnage the animation, resetting t in the process */
    void changeAnim(unsigned int animNum);

    /* Current section of the textures that should be displayed */
    sf::IntRect bounds;

    /* Pixel dimensions of each individual frame */
    sf::IntRect frameSize;


    /* Constructor */
    AnimationHandler(){
        this->frameSize = frameSize;
        this->t = 0.0f;
        this->currentAnim = -1;
    }
};    

#endif /* ANIMATION_HELPER_HPP */
