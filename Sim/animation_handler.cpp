#include <SFML/Graphics.hpp>
#include <vector>

#include "animation_handler.hpp"

void AnimationHandler::update(const float dt){
    if(currentAnim >= this->animations.size() || currentAnim < 0) return;

    float duration = this->aniamtions[currentAnim].duration;

    /* Check if the animation has progressed to a new frame and if so */
    /* change to the next frame */
    if(int((t + dt) / duration) > int(t / duration)){
        
        /* Calculate the frame number */
        int frame = int((t + dt) / duration);

        /* Adjust for looping */
        frame %= this->animations[currentAnim].getLength();

        /* Set the sprite to the new frame */
        sf::IntRect rect = this->frameSize;
        rect.left = rect.width * frame;
        rect.top = rect.height * this->currentAnim;
        this->bounds = rect;
    }

    /* Increment the time elapsed */
    this->t += dt;
    /* Adjust for looping */
    if(this->t > duration * this->animation[currentAnim].getLength()){
        this->t = 0.0f;
    }

    return;
}

void AnimationHandler::changeAnim(unsigned int animID) {
    
    /* Do not change the animation if the animation is currently active or */
    /* the new animation does not exist */


}
