//https://www.codingame.com/ide/puzzle/dungeons-and-maps
//Fails for Di test case with time out

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
    int w;
    int h;
    cin >> w >> h; cin.ignore();
    int start_row;
    int start_col;
    cin >> start_row >> start_col; cin.ignore();
    int nr_maps;
    cin >> nr_maps; cin.ignore();
    vector<string> map_rows;
    int prev_path = 0;
    int map_idx = 0;
    for (int i = 0; i < nr_maps; i++) 
    {
        for (int j = 0; j < h; j++) 
        {
            string map_row;
            getline(cin, map_row);
            map_rows.push_back(map_row);
        }

        bool no_path = false;
        int path = 0;
        int kidx = start_row;
        int jidx = start_col;
        while( true )
        {
            if ( (kidx < 0 || kidx > h-1) || (jidx < 0 || jidx > w-1) )
            {
                no_path = true;
                break;
            } 

            const string curr_row = map_rows[kidx];
            char dir = curr_row[jidx];
            if ( dir == '#' || dir == '.' )
            {
                no_path = true;
                path = 0;
                break;
            }
            else if ( dir == 'T' )
            {
                path++;
                break;
            }
            else if ( dir == '>' )
            {
                path++;
                jidx++;
            }
            else if ( dir == '<' )
            {
                path++;
                jidx--;
            }
            else if ( dir == '^' )
            {
                path++;
                kidx--;
            }
            else if ( dir == 'v' )
            {
                path++;
                kidx++;
            }    
        }

        if ( !prev_path || (!no_path && (path <  prev_path)) )
        {
            map_idx = i;
            prev_path = path;
        }

        map_rows.clear();
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    if ( prev_path )
        cout << map_idx << endl;
    else 
        cout << "TRAP" << endl;
}


//Handling all test cases

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
    int w;
    int h;
    cin >> w >> h; cin.ignore();
    int start_row;
    int start_col;
    cin >> start_row >> start_col; cin.ignore();
    int nr_maps;
    cin >> nr_maps; cin.ignore();
    vector<string> map_rows;
    int prev_path = 0;
    int map_idx = 0;
    for (int i = 0; i < nr_maps; i++) 
    {
        for (int j = 0; j < h; j++) 
        {
            string map_row;
            getline(cin, map_row);
            map_rows.push_back(map_row);
        }

        bool path_found = false;
        bool no_path = false;
        int path = 0;
        int kidx = start_row;
        int jidx = start_col;
        int turn_count = 0;
        while( !no_path && !path_found )
        {
            if ( (kidx < 0 || kidx > h-1) || (jidx < 0 || jidx > w-1) )
                break;
            else if ( path && turn_count == 0 )
            {
                path = 0;
                break;
            }
        
            const string curr_row = map_rows[kidx];
            char dir = curr_row[jidx];
            switch(dir)
            {
                case '#':
                case '.':
                    path = 0;
                    no_path = true;
                    break;
                case 'T':
                    path++;
                    path_found = true;
                    break;
                case '>':
                    path++;
                    jidx++;
                    turn_count++;
                    continue;
                case '<':
                    path++;
                    jidx--;
                    turn_count--;
                    continue;
                case '^':
                    path++;
                    kidx--;
                    turn_count--;
                    continue;
                case 'v':
                    path++;
                    kidx++;
                    turn_count++;
                    continue;
            }  
        }

        if ( !prev_path || ( path_found && (path <  prev_path)) )
        {
            map_idx = i;
            prev_path = path;
        }

        map_rows.clear();
    }

    if ( prev_path )
        cout << map_idx << endl;
    else 
        cout << "TRAP" << endl;
}



//Using iterators
//
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
    int w;
    int h;
    cin >> w >> h; cin.ignore();
    int start_row;
    int start_col;
    cin >> start_row >> start_col; cin.ignore();
    int nr_maps;
    cin >> nr_maps; cin.ignore();
    vector<string> map_rows;
    int prev_path = 0;
    int map_idx = 0;
    for (int i = 0; i < nr_maps; i++) 
    {
        for (int j = 0; j < h; j++) 
        {
            string map_row;
            getline(cin, map_row);
            map_rows.push_back(map_row);
        }

        bool path_found = false;
        bool no_path = false;
        int path = 0;
        int kidx = start_row;
        int jidx = start_col;
        int turn_count = 0;
        while( !no_path && !path_found )
        {
            if ( (kidx < 0 || kidx > h-1) || (jidx < 0 || jidx > w-1) )
                break;
            else if ( path && turn_count == 0 )
            {
                path = 0;
                break;
            }
        
            const string curr_row = *(map_rows.begin()+ kidx);
            char dir = *(curr_row.begin()+ jidx);
            switch(dir)
            {
                case '#':
                case '.':
                    path = 0;
                    no_path = true;
                    break;
                case 'T':
                    path++;
                    path_found = true;
                    break;
                case '>':
                    path++;
                    jidx++;
                    turn_count++;
                    continue;
                case '<':
                    path++;
                    jidx--;
                    turn_count--;
                    continue;
                case '^':
                    path++;
                    kidx--;
                    turn_count--;
                    continue;
                case 'v':
                    path++;
                    kidx++;
                    turn_count++;
                    continue;
            }  
        }

        if ( !prev_path || ( path_found && (path <  prev_path)) )
        {
            map_idx = i;
            prev_path = path;
        }

        map_rows.clear();
    }

    if ( prev_path )
        cout << map_idx << endl;
    else 
        cout << "TRAP" << endl;
}

//taking care of circularr paths
//
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
    int w;
    int h;
    cin >> w >> h; cin.ignore();
    int start_row;
    int start_col;
    cin >> start_row >> start_col; cin.ignore();
    int nr_maps;
    cin >> nr_maps; cin.ignore();
    vector<string> map_rows;
    int prev_path = 0;
    int map_idx = 0;
    for (int i = 0; i < nr_maps; i++) 
    {
        for (int j = 0; j < h; j++) 
        {
            string map_row;
            getline(cin, map_row);
            map_rows.push_back(map_row);
        }

        bool path_found = false;
        bool no_path = false;
        int path = 0;
        int kidx = start_row;
        int jidx = start_col;
        vector<pair<int,int>> pos_travelled;
        while( !no_path && !path_found )
        {
            if ( (kidx < 0 || kidx > h-1) || (jidx < 0 || jidx > w-1) )
                break;
        
            const string curr_row = *(map_rows.begin()+ kidx);
            char dir = *(curr_row.begin()+ jidx);
            switch(dir)
            {
                case '#':
                case '.':
                    path = 0;
                    no_path = true;
                    break;
                case 'T':
                    path++;
                    path_found = true;
                    break;
                case '>':
                {
                    path++;
                    jidx++;
                    pair pos = pair( jidx, kidx );
                    if ( std::find(pos_travelled.begin(),pos_travelled.end(),pos) == pos_travelled.end() )
                        pos_travelled.push_back(pair(jidx,kidx));
                    else
                    {
                        path = 0;
                        no_path = true;
                    }
                    continue;
                }
                case '<':
                {
                    path++;
                    jidx--;
                    pair pos = pair( jidx, kidx );
                    if ( std::find(pos_travelled.begin(),pos_travelled.end(),pos) == pos_travelled.end() )
                        pos_travelled.push_back(pair(jidx,kidx));
                    else
                    {
                        path = 0;
                        no_path = true;
                    }
                    continue;
                }
                case '^':
                {
                    path++;
                    kidx--;
                    pair pos = pair( jidx, kidx );
                    if ( std::find(pos_travelled.begin(),pos_travelled.end(),pos) == pos_travelled.end() )
                        pos_travelled.push_back(pair(jidx,kidx));
                    else
                    {
                        path = 0;
                        no_path = true;
                    }
                    continue;
                }
                case 'v':
                {
                    path++;
                    kidx++;
                    pair pos = pair( jidx, kidx );
                    if ( std::find(pos_travelled.begin(),pos_travelled.end(),pos) == pos_travelled.end() )
                        pos_travelled.push_back(pair(jidx,kidx));
                    else
                    {
                        path = 0;
                        no_path = true;
                    }
                    continue;
                }
            }  
        }

        if ( !prev_path || ( path_found && (path <  prev_path)) )
        {
            map_idx = i;
            prev_path = path;
        }

        map_rows.clear();
    }

    if ( prev_path )
        cout << map_idx << endl;
    else 
        cout << "TRAP" << endl;
}
