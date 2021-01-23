//#pragma once

#include "ofMain.h"
#include "Pipe.hpp"
#include "Bird.hpp"

enum GameState{
    GAME_START,
    GAME_RUNNING,
    GAME_PAUSED,
    BIRD_FLYING,
    BIRD_FALLING,
    GAME_ENDED
};

class ofApp : public ofBaseApp{
    
	public:
        ofImage bird_image;
        ofImage upper_pipe_image;
        ofImage start_screen_image;
        ofImage lower_pipe_image;
        ofImage game_over;
        ofSoundPlayer sound;
        int point_count = 0;
        float default_volume = 0.5;
        float zero_value = 0.0;
        bool temp_bool =  false;
        float gravity = 25;
        bool start = true;
        bool startscreen = true;
        float velocity_factor = 3.0;
        float game_over_sign_size = 500;
        float score_text_size = 300;
        float string_scaling_factor = 100;
        float min_pipe_height = 100;
        float max_pipe_height = 250;
        float position_scaling_factor = 2;
        float elapsed_time_factor = 0.64;
        float pipe_height_scaling_factor = 50;
        float bird_size = 150;
        float pipe_width = 100;
        float screen_scaling_factor = 3;
        float point_multiplying_factor = 5;
        float grade_A = 85;
        float grade_B = 70;
        float grade_C = 40;
        float grade_D = 25;
        std::string grade_A_message = "You got an A, good job!";
        std::string grade_B_message = "You got a B, good!";
        std::string grade_C_message = "C+ is not too bad but you can do  better";
        std::string grade_D_message = "You managed to pass the class";
        std::string failed_message = "you failed, rip";
        GameState state = GAME_START;
        Bird bird = Bird(ofRectangle(0,0,0,0));
        Pipe upper_pipe = Pipe(ofRectangle(0,0,0,0));
        Pipe lower_pipe = Pipe(ofRectangle(0,0,0,0));
        void CreatePipes();
        void Jump();
        void ResetGame();
        std::string GenerateGrade();
        bool Intersection();
        void setup();
        void update();
        void draw();
        void MovePipes();
        void CreateBird();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        float CalculateAccelaration();
        float CalculatePosition();
        float CalculateVelocity();
		
};
