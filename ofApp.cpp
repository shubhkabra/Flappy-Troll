#include "ofApp.h"
#include "Bird.hpp"
#include "Pipe.hpp"

//--------------------------------------------------------------
    void ofApp::setup(){
        upper_pipe_image.load("flappytoppipe.png");
        lower_pipe_image.load("flappybottompipe.png");
        bird_image.load("meme.jpg");
        game_over.load("gameover.png");
        start_screen_image.load("FlappyTroll.png");
        sound.load("shootingstars.mp3");
        sound.setVolume(default_volume);
        sound.play();
        sound.setLoop(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    if (startscreen) {
        startscreen = false;
    }
        if (start) {
            ResetGame();
            start = false;
        }
        if (state == BIRD_FLYING) {
            //I set the accelaration to zero to halt the accelaration
            //Negation of velocity in order to change the position
            bird.SetAccelaration(zero_value);
            bird.SetVelocity(-gravity / velocity_factor);
            //Call for moving pipes
            MovePipes();
            //Check for intersectionn
            if (Intersection()) {
                state = GAME_ENDED;
            }
            //Check for if more pipes are required
            if (upper_pipe.body.getMinX() <= zero_value) {
                CreatePipes();
            }
        } else if (state == BIRD_FALLING) {
            //Called all calculating methods in order to determine position.
            bird.SetAccelaration(gravity);
            bird.SetVelocity(CalculateVelocity());
            bird.SetPosition(CalculatePosition());
            //setting the position of bird
            bird.body.setY(bird.GetPosition());
            MovePipes();
            //checking for intersectionn
            if (Intersection()) {
                state = GAME_ENDED;
                
            }
            //checking if pipe disappeared from the screen
            if (upper_pipe.body.getMinX() <= zero_value) {
                CreatePipes();
            }
            
        }
    //using the logic below to keep the bird within the screen
        if (bird.body.getY() <= zero_value || bird.body.getY() >= ofGetHeight()) {
            int y = (int) bird.body.getY() % ofGetHeight();
            bird.body.setY(y);
        }
}

//--------------------------------------------------------------
//drawing all the elements on the screen
void ofApp::draw(){
    if (state == GAME_START) {
        //checkinng for start of the game and drwaing start screen in the background.
        //kept it as a background in order to keep the immemdiateness and trolling nature of the game.
        start_screen_image.draw(ofRectangle(zero_value,zero_value, ofGetWidth(), ofGetHeight()));
    }
    start_screen_image.draw(ofRectangle(zero_value,zero_value, ofGetWidth(), ofGetHeight()));
    bird_image.draw(bird.body);
    upper_pipe_image.draw(upper_pipe.body);
    lower_pipe_image.draw(lower_pipe.body);
    if (state == GAME_ENDED) {
        //string messages for when the game is over and a game over image.
        ofDrawBitmapString(GenerateGrade(), string_scaling_factor, string_scaling_factor);
        game_over.draw(ofRectangle(ofGetWidth() / screen_scaling_factor, ofGetHeight() / screen_scaling_factor, game_over_sign_size, game_over_sign_size));
        ofDrawBitmapString("Press F1 to restart", ofGetWidth() - string_scaling_factor - string_scaling_factor, ofGetHeight() - string_scaling_factor);
    }
    
}

//--------------------------------------------------------------
//checking for what key is pressed and reacting and assigning states accordingly
void ofApp::keyPressed(int key){
    if (key == OF_KEY_LEFT_SHIFT) {
        state = GAME_RUNNING;
    }
    //handling the score by checking for alternating pattern of the keys
    if (key == OF_KEY_UP) {
        temp_bool = true;
        state = BIRD_FLYING;
    } else if (key == OF_KEY_DOWN) {
        if (temp_bool) {
            point_count++;
            temp_bool = false;
        }
        state = BIRD_FALLING;
    }
    if (key == OF_KEY_F1) {
        ResetGame();
    }
}

//--------------------------------------------------------------
//checking for intersection
bool ofApp::Intersection() {
    if ( bird.body.intersects(upper_pipe.body) || bird.body.intersects(lower_pipe.body)) {
        return true;
    }
    return false;
}
//--------------------------------------------------------------
//used fundamental equations of kinematics to determine velocity, accelaration and position.
float ofApp::CalculateVelocity() {
    float toreturn = bird.GetVelocity() + bird.GetAccelaration();
    return toreturn;
}
//--------------------------------------------------------------
float ofApp::CalculatePosition() {
    float toreturn = bird.GetPosition() + bird.GetVelocity();
    return toreturn;
}
//--------------------------------------------------------------
float ofApp::CalculateAccelaration() {
    float temp = bird.GetAccelaration() + gravity;
    return temp;
}

//--------------------------------------------------------------
//Creating pipes of varied height for the game.
void ofApp::CreatePipes() {
    int randomno = ofRandom(min_pipe_height,max_pipe_height);
    lower_pipe  = Pipe(ofRectangle(ofGetWidth(), ofGetHeight() - randomno + pipe_height_scaling_factor, pipe_width, ofGetHeight() - randomno));
    upper_pipe = Pipe(ofRectangle(ofGetWidth(), zero_value, pipe_width , randomno));
}

//--------------------------------------------------------------
void ofApp::CreateBird() {
        bird = Bird(ofRectangle(ofGetWidth() / screen_scaling_factor, bird.GetPosition(), bird_size, bird_size));
    }



//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
//Method called if the game is reset
void ofApp::ResetGame() {
    point_count = zero_value;
    state = BIRD_FALLING;
    bird.SetAccelaration(gravity);
    bird.SetPosition(ofGetHeight() / position_scaling_factor);
    CreatePipes();
    CreateBird();
}
//--------------------------------------------------------------
//determining the grade based upon score.
std::string ofApp::GenerateGrade() {
    point_count = point_count * point_multiplying_factor;
    if (point_count >= grade_A) {
        return grade_A_message;
    } else if (point_count >= grade_B) {
        return grade_B_message;
    } else if (point_count > grade_C) {
        return grade_C_message;
    } else if (point_count >= grade_D){
        return grade_D_message;
    } else {
        return failed_message;
    }
}
//--------------------------------------------------------------
//method used to move pipes, I simply reassign the x coordinate of pipes.
void ofApp::MovePipes() {
    upper_pipe.body.setX(upper_pipe.body.getX() - ofGetElapsedTimef() * elapsed_time_factor);
    lower_pipe.body.setX(lower_pipe.body.getX() - ofGetElapsedTimef() * elapsed_time_factor);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
