/*This program will generate a program that estimates the value of π using a Monte Carlo simulation

Created: 11-2-15
Modified: 11-9-15

Yuri Khechoyan
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define sqr2(x) ((x) *(x))
#define MAXNUM 10000 //The Maximum # of darts will be Ten Million - Will give the PI answer of 3.1409

//Declaring the Variables
int insideCircle(float xcoord, float ycoord){
    float distance = sqrt(pow((1-xcoord), 2)+pow((1-ycoord), 2));

        if (distance<=1){
            return 1;
        }
            else{
                return 0;
            }
    }

void getrandomXY(float *xcoord, float *ycoord);


int main (void){
    srand(time(NULL));
    float xcoord = 0;
    float ycoord = 0;
    getrandomXY(&xcoord, &ycoord);

        int i;
        float circle = 0;
    float square = 0;

        //Depending where the "dart" falls, it either adds one to the circle or the square
                 for(i=0; i<MAXNUM; i++){
                        getrandomXY(&xcoord, &ycoord);

                int result=insideCircle(xcoord, ycoord);
                printf("%d",result);
                if (result==1){
                    circle++;
                 }
                 }

                //Calculating the equation of PI
            float PI = 4*(circle / MAXNUM);

            printf("PI is %.4f \n", PI); //After PI calculation, answer will be formatted this way

            return 0; //Program has executed and terminates with a 0
}

        void getrandomXY(float *xcoord, float *ycoord){

            //Generating Random Number
        *xcoord = 2.0*((float)rand()/ RAND_MAX);
        *ycoord = 2.0*((float)rand()/ RAND_MAX);

        }

/*

void getRandomXY(*float x, *float y)
gives a random (x,y) pair
returns whether the point is inside the circle (0->false, 1->true)



Pi = 4 x (Number of Darts in Circle) / (Number of Darts in Square)

*/
