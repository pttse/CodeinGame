/**
 * C++ implementation of the "Power of Thor" in Codingame (https://www.codingame.com)
 * 
 * Author: Po Ting Tse
 * Date:   27th October, 2015
 * 
 **/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//check whether the input coordinates are valid
bool checkWithinMap(int currentX, int currentY){
    
    int maxMapX = 40;
    int minMapX = 0;
    
    int maxMapY = 18;
    int minMapY = 0;
    
    bool isWithinTheMap = false;
    
    //check xcorridinates
     if((currentX >= minMapX) && (currentX < maxMapX)){
        //check y-coordinates
        if((currentY >= minMapY) && (currentY < maxMapY)){
             isWithinTheMap =  true;
         }
     }
     
     return isWithinTheMap;
    
}


//the main game logic for each round
int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();

    int thorX = initialTX; // set Thor's current X position to initial
    int thorY = initialTY; // set Thor's current Y position to initial
    
    
    //check constraints of the light in the map 
    if(checkWithinMap(lightX,lightY) && checkWithinMap(initialTX,initialTY)){
        
        // game loop
        while (1) {
            int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
            cin >> remainingTurns; cin.ignore();
    
            // Write an action using cout. DON'T FORGET THE "<< endl"
            // To debug: cerr << "Debug messages..." << endl;
            string directionX = "";
            string directionY = "";
            
            /////x position part 
            
            //if the light is on the left of the current position
            if(thorX > lightX ){
                //check if moving to left is valid 
                if(checkWithinMap(thorX-1, 0)){
                    //-1 x-position
                    thorX--;
                    //add the direction to the left(ie w)
                    directionX = "W";
                }
                
            }else if(thorX < lightX){ //the light is on the right
                //check if moving to right is valid 
                if(checkWithinMap(thorX+1, 0)){
                    //+1 x-position
                    thorX++;
                    //add the direction to right (ie E)
                    directionX = "E";
                }//end checking 
            }
            
            ///y position part 
            //if the light is on the upper of the current position
            if(thorY > lightY ){
                //check if moving to left is valid 
                if(checkWithinMap(0, thorY-1)){
                    //-1 y-position
                    thorY--;
                    //add the direction to the left(ie N)
                    directionY = "N";
                }
            }else if(thorY < lightY){ //if the light bwlow the current position
                //check if moving to right is valid 
                if(checkWithinMap(0, thorY+1)){
                    //+1 y-position
                    thorY++;
                    //add the direction to right (ie S)
                    directionY = "S";
                }//end checking 
            }
            
            cout << directionY + directionX << endl; // A single line providing the move to be made: N NE E SE S SW W or NW
        }//end while loop of each round 



    }//end-if, checking the cooridinates


}//end main function

