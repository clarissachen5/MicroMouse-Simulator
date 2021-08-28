
#include "micromouseserver.h"
void offset(int mouthDirection, int *xPos, int *yPos){
    if (mouthDirection == 0) {
        *yPos += 1; //mouse goes left so x position decreases by 1
    }
    if (mouthDirection == 1) {
        *xPos += 1;
    }
    if (mouthDirection == 2) {
        *yPos -= 1;
    }
    if (mouthDirection == 3) {
        *xPos -= 1;
    }
}

void turnMouthLeft(int *mouth){
    *mouth -=1;
    if(*mouth < 0) {
        *mouth = 3;
    }
}

void turnMouthRight(int *mouth){
    *mouth += 1;
    if(*mouth > 3) {
        *mouth = 0;
    }
}
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


    int timesLeft;
    int timesForward;
    int timesRight;
    static int countL = 0;

    static int xPos = 0; //for keeping tracks of mouse's x position
    static int yPos = 0; //for keeping tracks of mouse's y position
    static int mouthDirection = 0; //tracks direction of mouse, 0 = north, 1 = east, 2 = south, 3 = west
    static int mazeData[20][20] ={{0}}; //initialize array


    if (mouthDirection == 0) { //setting values for times directions when mouse is facing north
        if (isWallLeft()) {
            timesLeft = 1000000;
        }
        else {
            timesLeft = mazeData[(xPos-1)][yPos];
        }
        if (isWallForward()) {
            timesForward = 1000000;
        }
        else {
              timesForward = mazeData[xPos][(yPos+1)];
        }
        if (isWallRight()) {
            timesRight = 1000000;
        }
        else {
            timesRight = mazeData[(xPos+1)][yPos];
        }
    }

    if (mouthDirection == 1) { //setting values for times directions when mouse is facing east
        if (isWallLeft()) {
            timesLeft = 1000000;
        }
        else {
             timesLeft = mazeData[xPos][(yPos+1)];
        }
        if (isWallForward()) {
            timesForward = 1000000;
        }
        else {
            timesForward = mazeData[(xPos+1)][yPos];
        }
        if (isWallRight()) {
            timesRight = 1000000;
        }
        else {
            timesRight = mazeData[xPos][(yPos-1)];
        }
    }

    if (mouthDirection == 2) { //setting values for times directions when mouse is facing south
        if (isWallLeft()) {
            timesLeft = 1000000;
        }
        else {
           timesLeft = mazeData[(xPos+1)][yPos];
        }
        if (isWallForward()) {
            timesForward = 1000000;
        }
        else {
            timesForward = mazeData[xPos][(yPos-1)];
        }
        if (isWallRight()) {
            timesRight = 1000000;
        }
        else {
            timesRight = mazeData[(xPos-1)][yPos];
        }
    }

    if (mouthDirection == 3) { //setting values for times directions when mouse is facing west
        if (isWallLeft()) {
            timesLeft = 1000000;
        }
        else {
            timesLeft = mazeData[xPos][(yPos-1)];
        }
        if (isWallForward()) {
            timesForward = 1000000;
        }
        else {
            timesForward = mazeData[(xPos-1)][yPos];
        }
        if (isWallRight()) {
            timesRight = 1000000;
        }
        else { 
            timesRight = mazeData[xPos][(yPos+1)];
        }
    }





    if (!isWallLeft() &&
       !(timesLeft >= timesForward && !isWallForward()) &&
       !(timesLeft >= timesRight && !isWallRight())
       )
    {
        turnLeft();
        moveForward();
        countL += 1;
        turnMouthLeft(&mouthDirection);
        offset(mouthDirection, &xPos, &yPos);
        mazeData[xPos][yPos] += 1;

    }

    else if (!isWallForward() &&
             !(timesForward >= timesRight && !isWallRight())
             )
    {
        moveForward();
        countL = 0;
        offset(mouthDirection, &xPos, &yPos);
        mazeData[xPos][yPos] += 1;
    }

    else if (!isWallRight())
    {
        turnRight();
        moveForward();
        turnMouthRight(&mouthDirection);
        offset(mouthDirection, &xPos, &yPos);
        countL = 0;
        mazeData[xPos][yPos] += 1;
    }

    else
    {
        turnRight();
        turnRight();
        turnMouthRight(&mouthDirection);
        turnMouthRight(&mouthDirection);

        moveForward();
        countL = 0;
        offset(mouthDirection, &xPos, &yPos);
    }

    if (countL == 3) { //need three left moves in a row to know finish has been reached
        foundFinish();
        printUI("finished maze");
    }


}


