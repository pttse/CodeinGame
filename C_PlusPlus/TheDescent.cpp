/**
 * C++ implementation of the "The Descent" in Codingame (https://www.codingame.com)
 * 
 * Author: Po Ting Tse
 * Date:   28th October, 2015
 * 
 **/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    const string FIRECOMMAND = "FIRE"; //command for fire the mountain
    const string HOLDCOMMAND = "HOLD"; //command for HOLD (ship is not firing).
    
    int maxSpaceX = 7;
    int minSpaceX = 0;
    
    int maxSpaceY = 10;
    int minSpaceY = 0;
    
    int maxHeightMountain = maxSpaceY - 1;
    int minHeightMountain = minSpaceY;
    
    // game loop
    while (1) {
        int spaceX; //current horizontal coordinate of the ship, from 0(leftmost) to rightmost(7)
        int spaceY; //current altitude of the ship goes down from 10 (toppest) to 1 (just above ground).
        
        int tallestMountainPos = 0;
        int tallestMountainHeight = 0;
        //input of the parameters
        cin >> spaceX >> spaceY; cin.ignore();
        
        //check if the inputs spaceX and spaceY are valid
        if( (spaceX >= minSpaceX) && (spaceX <= maxSpaceX) 
            && (spaceY >= minSpaceY) && (spaceY <= maxSpaceY)){
                
            //input height of each mountain
            for (int i = 0; i < 8; i++) {
                int mountainH; // represents the height of one mountain, from 9 to 0. Mountain heights are provided from left to right.
                cin >> mountainH; cin.ignore();
                
                //check if the input of mountainH is valid
                if( (mountainH >=minHeightMountain) && (mountainH <=maxHeightMountain) ){
                    //get the tallest moutain among 
                    if(mountainH > tallestMountainHeight){
                        tallestMountainPos = i;
                        tallestMountainHeight = mountainH;
                    }
                }    
            }//end for each mountain height
            
            string fireDecision = HOLDCOMMAND;
            
            //only fire when the ship is under the moutain
            if(spaceX == tallestMountainPos){
                fireDecision = FIRECOMMAND;
            }
            // Write an action using cout. DON'T FORGET THE "<< endl"
            // To debug: cerr << "Debug messages..." << endl;
            //cerr << "Debug messages..." << endl;
            //cerr << spaceX << endl;
            //cerr << tallestMountainPos << endl;
            
            cout << fireDecision << endl; // either:  FIRE (ship is firing its phase cannons) or HOLD (ship is not firing).
        
        }//end-if checking spaceX and spaceY
                
    }//end while loop
        
}//end main method
