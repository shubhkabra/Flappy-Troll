//
//  Bird.cpp
//  FinalProject
//
//  Created by Shubhankar Kabra on 4/22/19.
//

#include "Bird.hpp"
#include "ofApp.h"



void Bird::SetAccelaration(float value) {
    
    if (value >= gravityy) {
        accelaration = gravityy;
        
    }
    accelaration = value;
}



void Bird::SetVelocity(float value) {
    velocity = value;
}

void Bird::SetPosition(float value) {
    position = value;
}

float Bird::GetAccelaration() {
    return accelaration;
    
}

float Bird::GetVelocity() {
    return velocity;
}

float Bird::GetPosition() {
    return position;
}
