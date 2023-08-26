//https://www.codingame.com/ide/puzzle/temperatures

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
    int n; // the number of temperatures to analyse
    cin >> n;
    cin.ignore();
    if ( n == 0 )
    {
        cout << 0;
        return 1;
    }
    
    vector<int> temps;
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
        temps.push_back(t);
    }

    sort(temps.begin(),temps.end());
    int prev_diff = abs(temps[0]);
    int closest_temp = temps[0];
    for ( int idx=1; idx<temps.size(); idx++ )
    {
        int curr = temps[idx];
        if ( prev_diff >= abs(curr) )
        {
            prev_diff = abs(curr);
            closest_temp = curr;
        }
        else
            break;
    }
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << closest_temp << endl;
}
