//https://www.codingame.com/ide/puzzle/power-of-thor-episode-1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/
string dirCalculator( int& initial_tx, int& initial_ty, int light_x, int light_y )
{
    string dir;
    if ( initial_tx == light_x )
    {
        if ( initial_ty > light_y )
            dir = "N";
        else
            dir = "S";
    }
    else
    {
        const float tan = (float)(light_y - initial_ty) / (light_x - initial_tx );
        if ( tan == 0 )
        {
            if ( initial_tx < light_x )
                dir = "E";
            else
                dir = "W";
        }
        else if ( tan < 0 )
        {
            if ( initial_ty > light_y )
            {
                dir = "NE";
                initial_tx++;
                initial_ty--;
            }
            else
            {
                dir = "SW";
                initial_tx--;
                initial_ty++;
            }
        }
        else if ( tan > 0 )
        {
            if ( initial_ty > light_y )
            {
                dir = "NW";
                initial_tx--;
                initial_ty--;
            }
            else
            {
                dir = "SE";
                initial_tx--;
                initial_ty++;
            }
        }        
    }

    return dir;
}


int main()
{
    int light_x; // the X position of the light of power
    int light_y; // the Y position of the light of power
    int initial_tx; // Thor's starting X position
    int initial_ty; // Thor's starting Y position
    cin >> light_x >> light_y >> initial_tx >> initial_ty; cin.ignore();

    // game loop
     
    while (1) {
        int remaining_turns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remaining_turns; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // A single line providing the move to be made: N NE E SE S SW W or NW
        string dir = dirCalculator( initial_tx, initial_ty, light_x, light_y );
        cout << dir  << endl;
    }
}
