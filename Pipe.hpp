//
//  Pipe.hpp
//  FinalProject
//
//  Created by Shubhankar Kabra on 4/22/19.
//

#ifndef Pipe_hpp
#define Pipe_hpp

#include <stdio.h>
#include "ofxGui.h"
#include <vector>

class Pipe {
public:
    ofRectangle body;
    //constructor for pipe
    Pipe(ofRectangle v) : body(v) {};
    
};
#endif /* Pipe_hpp */
