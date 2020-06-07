/*
Question: Calculate minimum amount of energy required for the company’s drone to complete its flight.

YOU NEED TO KNOW THE LEAST DEFICIENT ENERGY LEVEL THAT DRONE CAN HAVE, charge the drone with that energy at start. It will not crash.

Energy consumption:
- Burns 1 kWh (kilowatt-hour is an energy unit) for every mile it ascends
- Gains 1 kWh for every mile it descends. 
- Flying sideways neither burns nor adds any energy.

Input: Given an array route of 3D points.
        route = [ [0,   2, 10],
                  [3,   5,  0],
                  [9,  20,  6],
                  [10, 12, 15],
                  [10, 10,  8] ]

output: 5 # less than 5 kWh and the drone would crash before the finish
          # line. More than `5` kWh and it’d end up with excess energy

Desired: implement a function calcDroneMinEnergy that computes and returns the minimal amount of energy the drone would need to complete its route. Assume that the drone starts its flight at the first point in route.


*************Logic*******************
- Ignore x,y coordinates. Only focus on z coordinates.
- Drone starts from 10, decends to 0, climbs 6, climbs 15, decends to 8. We need to find energy to be filled at start so that drone never finds energy deficient.

        |            15 t=15-6=9
        |           /  \e=4-9=-5        >>>Max deficient energy is -5. Drone should start with +5.
  e=0 10|          /    \
        |\        /      \
        | \     6         \
        |  \   /t=6-0      8 t=8-15=-7
        |   \ /e=10-6=4      e=-5-(-7)=2
        -----0-----------------
            t=0-10
            e=e-t=+10
*************************************
*/

#include<stdio.h>

int calcDroneMinEnergy(size_t routeLength, int route[routeLength][3])
{
/* Solution-1:  
        int e =0, t=0, least=0;
        for(int i=1;i<routeLength;i++){
                t = route[i][2] - route[i-1][2];
                e = e - t;
                if(e<least)
                        least=e;
        }
        //printf("least=%d\n",least);
        return -least;
*/
/*Solution-2:
 //Find max z-coordinate present in Array. Subtract from z-coordinate at index 0.
 */
}

int main() {

        return 0;
}
