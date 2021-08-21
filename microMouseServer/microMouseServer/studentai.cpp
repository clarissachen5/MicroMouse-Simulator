
#include "micromouseserver.h"

int timesLeft = 0;


int timesForward = 0;


int timesRight = 0;


int countL = 0;

int xPos = 0; //for keeping tracks of mouse's x position
int yPos = 0; //for keeping tracks of mouse's y position
int mouthDirection = 0; //tracks direction of mouse, 0 = north, 1 = east, 2 = south, 3 = west
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



    int mazeData[20][20]; //initialize array


    if (mouthDirection == 0) { //setting values for times directions when mouse is facing north
        timesLeft = mazeData[xPos-1][yPos];
        timesForward = mazeData[xPos][yPos+1];
        timesRight = mazeData[xPos+1][yPos];
    }

    if (mouthDirection == 1) { //setting values for times directions when mouse is facing east
        timesLeft = mazeData[xPos][yPos+1];
        timesForward = mazeData[xPos+1][yPos];
        timesRight = mazeData[xPos][yPos-1];
    }

    if (mouthDirection == 2) { //setting values for times directions when mouse is facing south
        timesLeft = mazeData[xPos+1][yPos];
        timesForward = mazeData[xPos][yPos-1];
        timesRight = mazeData[xPos-1][yPos];
    }

    if (mouthDirection == 3) { //setting values for times directions when mouse is facing west
        timesLeft = mazeData[xPos][yPos-1];
        timesForward = mazeData[xPos-1][yPos];
        timesRight = mazeData[xPos][yPos+1];
    }





    if (!isWallLeft() &&
       !(timesLeft >= timesForward && !isWallForward()) &&
       !(timesLeft >= timesRight && !isWallRight())
       )
    {
        turnLeft();
        moveForward();


        if (mouthDirection == 0) {
            xPos -= 1; //mouse goes left so x position decreases by 1
        }
        if (mouthDirection == 1) {
            yPos += 1;
        }
        if (mouthDirection == 2) {
            xPos += 1;
        }
        if (mouthDirection == 3) {
            yPos -= 1;
        }

        countL += 1;
        mazeData[xPos][yPos] += 1;
        if (mouthDirection - 1 < 0) {
            mouthDirection = 3;
        }
        else {
            mouthDirection -= 1;
        }
    }

    else if (!isWallForward() &&
             !(timesForward >= timesRight && !isWallRight())
             )
    {
        moveForward();


        if (mouthDirection == 0) {
            yPos += 1;
        }
        if (mouthDirection == 1) {
            xPos += 1;
        }
        if (mouthDirection == 2) {
            yPos -= 1;
        }
        if (mouthDirection == 3) {
            xPos -= 1;
        }
        countL = 0;
        mazeData[xPos][yPos] += 1;
    }

    else if (!isWallRight())
    {
        turnRight();
        moveForward();

        if (mouthDirection == 0) {
            xPos += 1;
        }
        if (mouthDirection == 1) {
            yPos -= 1;
        }
        if (mouthDirection == 2) {
            xPos -= 1;
        }
        if (mouthDirection == 3) {
            yPos += 1;
        }

        countL = 0;
        mazeData[xPos][yPos] += 1;
        if (mouthDirection + 1 > 3) {
            mouthDirection = 0;
        }
        else {
            mouthDirection += 1;
        }
    }

    else
    {
        if (mouthDirection == 0) {
            yPos -= 1;
            mouthDirection = 2;
        }
        if (mouthDirection == 1) {
            xPos -= 1;
            mouthDirection = 3;
        }
        if (mouthDirection == 2) {
            yPos += 1;
            mouthDirection = 0;
        }
        if (mouthDirection == 3) {
            xPos += 1;
            mouthDirection = 1;
        }

        turnRight();
        turnRight();
        moveForward();
        countL = 0;
    }

    if (countL == 3) { //need three left moves in a row to know finish has been reached
        foundFinish();
        printUI("finished maze");
    }


}


