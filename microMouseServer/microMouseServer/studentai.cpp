
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

// unislanded maze
    if(!isWallLeft())
    {
        turnLeft();
        moveForward();
    }
    else if (!isWallForward())
    {
        moveForward();
    }
    else if (!isWallRight())
    {
        turnRight();
        moveForward();
    }
    else
    {
        turnRight();
        turnRight();
        moveForward();
    }
//end of unislanded maze code



}

//islanded maze code
int timesLeft() {
    return 0;
}

int timesForward() {
    return 0;
}

int timesRight() {
    return 0;
}


if (!isWallLeft() && (timesLeft() <= timesForward() && !isWallForward()) && (timesLeft()<= timesRight() && !isWallRight()))
{
    turnLeft();
    moveForward();
}

else if (!isWallForward() && (timesForward() <= timesRight() && !isWallRight()))
{
    moveForward();
}

else if (!isWallRight())
{
    turnRight();
    moveForward();
}

else
{
    turnRight();
    turnRight();
    moveForward();
}


//end of islanded maze code


void threePaths()
{
    int goneL = 0; //tracker for # times mouse has gone left path
    int goneF = 0; //tracker for # times mouse has gone forward path
    int goneR = 0; //tracker for # times mouse has gone right path
    if (!isWallLeft() && goneL < goneF && goneL < goneR)
    { //opportunity to move left
        turnLeft();
        moveForward();
        goneL += 1;
    }
    else if (!isWallForward() && goneF < goneR)
    { //opportunity to move forward
        moveForward();
        goneF += 1;
    }
    else
    { //opportunity to move right
        turnRight();
        moveForward();
        goneR += 1;
    }
}

void twoPaths() {
    if (!isWallLeft()) {
        turnLeft();
        moveForward();
    } else {
        moveForward(); //if there is a left wall, there will be no forward wall
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
    if (!isWallLeft() && !isWallForward() && !isWallRight()) { //three direction paths
        threePaths();
    } else if (!isWallLeft() && !isWallForward() || !isWallLeft() && !isWallRight() || !isWallForward() && !isWallRight()) { //two direction paths
        twoPaths();
    } else if (!isWallLeft() || !isWallForward() || !isWallRight()){
        onlyOnePath();
    } else {
        noPath();
        }
}



