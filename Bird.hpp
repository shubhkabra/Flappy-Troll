//
//  Bird.hpp
//  FinalProject
//
//  Created by Shubhankar Kabra on 4/22/19.
//

#ifndef Bird_hpp
#define Bird_hpp

#include <stdio.h>
#include "ofxGui.h"

class Bird {
private:
    float velocity = 0.0;
    float accelaration = 0.0;
    float position = 0.0;
public:
    float gravityy = 25;
    ofRectangle body;
    //constructor for bird 
    Bird(ofRectangle v) : body(v) {};
    void SetAccelaration(float value);
    void SetVelocity(float value);
    void SetPosition(float value);
    
    float GetAccelaration();
    float GetPosition();
    float GetVelocity();
};
#endif /* Bird_hpp */
