//https://www.codingame.com/ide/puzzle/rectangle-partition
//timing out for high density case
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

vector<int> calculate_DifferentLengthCombinations(const vector<int>& lengths )
{
    vector<int> length_segs;
    for ( int idx=0; idx<lengths.size()-1; idx++ )
    {
        const int begin = lengths[idx];
        for ( int kidx=idx+1;kidx<lengths.size(); kidx++ )
        {
            const int end = lengths[kidx];
            
            length_segs.push_back( end-begin );
        }
    }

    sort( length_segs.begin(), length_segs.end() );
    return length_segs;
}

int main()
{
    int w;
    int h;
    int count_x;
    int count_y;
    
    cin >> w >> h >> count_x >> count_y; cin.ignore();
    vector<int> space_x(count_x+2);
    space_x[0] = 0;
    vector<int> space_y(count_y+2);
    space_y[0] = 0;
    for (int i = 0; i < count_x; i++) 
    {
        int x;
        cin >> x; cin.ignore();
        space_x[i+1] = x;
    }

    space_x[count_x+1] = w;
    
    
    for (int i = 0; i < count_y; i++) 
    {
        int y;
        cin >> y; cin.ignore();
        space_y[i+1] = y;
    }

    space_y[count_y+1] = h;

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    vector<int> length_segs_x = calculate_DifferentLengthCombinations(space_x);
    vector<int> length_segs_y = calculate_DifferentLengthCombinations(space_y);

    int nr_squares = 0;
    for ( int idx=0; idx<length_segs_x.size(); idx++ )
    {
        const int x = length_segs_x[idx];
        for ( int kidx=0; kidx<length_segs_y.size(); kidx++ )
        {
            const int y = length_segs_y[kidx];
            if ( x == y )
                nr_squares++;
        }
    }

    cout << nr_squares  << endl;
}
