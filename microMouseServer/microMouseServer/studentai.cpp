
#include "micromouseserver.h"

void microMouseServer::studentAI()
{
/*
 * The following are the eight functions that you can call. Feel free to create your own fuctions as well.
 * Remember that any solution that calls moveForward more than once per call of studentAI() will have points deducted.
 *
 *The following functions return if there is a wall in their respective directions
 *bool isWallLeft();
 *bool isWallRight();
 *bool isWallForward();
 *
 *The following functions move the mouse. Move forward returns if the mouse was able to move forward and can be used for error checking
 *bool moveForward();
 *void turnLeft();
 *void turnRight();
 *
 * The following functions are called when you need to output something to the UI or when you have finished the maze
 * void foundFinish();
 * void printUI(const char *mesg);
*/
    void threePaths() {
        int goneL = 0; //tracker for # times mouse has gone left path
        int goneF = 0; //tracker for # times mouse has gone forward path
        int goneR = 0; //tracker for # times mouse has gone right path
        if (!isWallLeft() && goneL < goneF && goneL < goneR) { //opportunity to move left
            turnLeft();
            moveForward();
            goneL += 1;
        } else if (!isWallForward() && goneF < goneR) { //opportunity to move forward
            moveForward();
            goneF += 1;
        } else { //opportunity to move right
            turnRight();
            moveForward();
            goneR += 1;
    }
    }

    void onlyOnePath() {
        if (!isWallLeft() && isWallForward() && isWallRight()) { //only left
            turnLeft();
            moveForward();
        } else if (!isWallForward() && isWallRight()) { //only forward
            moveForward();
        } else { //only right
            turnRight();
            moveForward();
        }
    }

    void noPath() { //mouse has hit a dead end and there are no possible direction paths except to turn around
        turnLeft();
        turnLeft();
        moveForward();
    }

    void main(){
        if (!isWallLeft() && !isWallForward() && !isWallRight()) {
            threePaths();
        } else if (!isWallLeft() || !isWallForward() || !isWallRight()){
            onlyOnePath();
        } else {
            noPath();
            }
    }


}


