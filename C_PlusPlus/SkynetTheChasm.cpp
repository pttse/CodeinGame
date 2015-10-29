/**
 * C++ implementation of the "Skynet: The Chasm" in Codingame (https://www.codingame.com)
 * 
 * Author: Po Ting Tse
 * Date:   29th October, 2015
 * 
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>   

using namespace std;

int main()
{
    //commands of the bike
    const string SPEEDCOMMAND = "SPEED";
    const string SLOWCOMMAND = "SLOW";
    const string JUMPCOMMAND = "JUMP";
    const string WAITCOMMAND = "WAIT";
    
    //constraints of the inputs 
    int minSpeed = 0;
    int maxSpeed = 50;
    
    int minCoordX = 0;
    int maxCoordX = 100;
    
    int minRoad = 1;
    int maxRoad = maxCoordX;

    int minGap = 1;
    int maxGap = maxCoordX;
    
    int minPlatform = 1;
    int maxPlatform = 100;
    
    //initial parameters
    int road; // the length of the road before the gap.
    cin >> road; cin.ignore();
    int gap; // the length of the gap.
    cin >> gap; cin.ignore();
    int platform; // the length of the landing platform.
    cin >> platform; cin.ignore();

    //current decistion of the bike
    string currentDecision = WAITCOMMAND;
    
    //bool variables used for checking the given constraints
    bool isRoadValid = (road >= minRoad) && (road <= maxRoad) ;
    bool isGapValid =  (gap >= minGap) && (gap <= maxGap);
    bool isPlatformValid = (platform >= minPlatform) && (platform <= maxPlatform);
    
    //check whether the initial inputs are valid 
    if(isRoadValid && isGapValid && isPlatformValid){
    
        // game loop
        while (1) {
            
            int speed; // the motorbike's speed.
            cin >> speed; cin.ignore();
            int coordX; // the position on the road of the motorbike.
            cin >> coordX; cin.ignore();
    
            bool isSpeedValid = (speed >= minSpeed) && (speed < maxSpeed);
            bool isCoordXValid = (coordX >= minCoordX) && (coordX < maxCoordX);
            
            //check the inputs of speed of coordX
            if(isSpeedValid && isCoordXValid){
                //before reaching the gap 
                if( coordX <= (road - 1) ){
                    if( speed < (gap + 1)){
                        currentDecision = SPEEDCOMMAND;
                    }else if( (speed == (gap + 1)) && (coordX == road - 1) ){
                         currentDecision = JUMPCOMMAND;
                    }else if( speed == (gap+1)){
                        currentDecision = WAITCOMMAND;
                    }else{
                        currentDecision = SLOWCOMMAND;
                    }
                    
                }else{  //after jumping the gap
                       currentDecision = SLOWCOMMAND; //after jumping the gap, slow down anyway
                    
                }
                       
        
                cout << currentDecision << endl; // A single line containing one of 4 keywords: SPEED, SLOW, JUMP, WAIT.
            }//end if checking each round's inputs 
        } //end game loop
        
    }//end if-checking the initial input
} //end main method
