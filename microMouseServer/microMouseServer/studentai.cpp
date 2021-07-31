
#include "micromouseserver.h"

int timesLeft() {
    return 0;
}

int timesForward() {
    return 0;
}

int timesRight() {
    return 0;
}

int finish() { //counts how many times there are two adjacent walls (need to have three in a row and a single wall to reach the finish)
    return 0;
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

    //code for checking if close to finish
    if ((isWallLeft() && isWallForward()) ||
        (isWallForward() && isWallRight()))
    {
        finish() += 1;   //increasing finish counter
    }

    if (finish() == 3 &&
            ((isWallLeft() && !isWallForward() && !isWallRight()) ||
             (isWallForward() && !isWallLeft() && !isWallRight()) ||
             (isWallRight() && !isWallLeft() && !isWallForward())
             ))
    {
        foundFinish();
        printUI(const char "finished");
    }
    //end of code for checking if close to finish


    if (!isWallLeft() &&
       !(timesLeft() >= timesForward() && !isWallForward()) &&
       !(timesLeft()>= timesRight() && !isWallRight())
       )
    {
        turnLeft();
        moveForward();
    }

    else if (!isWallForward() &&
             !(timesForward() >= timesRight() && !isWallRight())
             )
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




}


