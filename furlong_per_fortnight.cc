//https://www.codingame.com/ide/puzzle/furlongs-per-fortnight

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


vector<pair<string,int>> slicing(const vector<pair<string,int>>& arr,
                    int X, int Y)
{
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y;
    vector<pair<string,int>> result(Y - X);
    copy(start, end, result.begin());
    return result;
}

float calculateFactor(const vector<pair<string,int>>& arr, const string& from, const string& to)
{
    float factor = 1.f;
    if ( from != to )
    {
        auto from_dist_idx = std::distance(arr.begin(), std::find_if(arr.begin(), arr.end(),
                [&](const auto& pair) { return pair.first == from; }) );
        auto to_dist_idx = std::distance(arr.begin(), std::find_if(arr.begin(), arr.end(),
                [&](const auto& pair) { return pair.first == to; }) );
            
        bool dist_up = from_dist_idx > to_dist_idx;
        
        int dist_start = dist_up ? to_dist_idx : from_dist_idx;
        int dist_stop = dist_up ? from_dist_idx : to_dist_idx;

        vector<pair<string,int>>dist_slice = slicing( arr, dist_start, dist_stop );
        
        for ( int distidx=0; distidx<dist_slice.size(); distidx++ )
        {
            int currfac = dist_slice[distidx].second;
            factor = dist_up ? factor/currfac : factor*currfac;
        }
    }

    return factor;
}


int main()
{
    string a_speed;
    getline(cin, a_speed);
    vector<pair<string,int>> distances;
    distances.push_back(pair("miles",8));
    distances.push_back(pair("furlongs",10));
    distances.push_back(pair("chains",22));
    distances.push_back(pair("yards",3));
    distances.push_back(pair("feet",12));
    distances.push_back(pair("inches",1));

    vector<pair<string,int>> times;
    times.push_back(pair("fortnight",2));
    times.push_back(pair("week",7));
    times.push_back(pair("day",24));
    times.push_back(pair("hour",60));
    times.push_back(pair("minute",60));
    times.push_back(pair("second",1));

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    int spacecal = 0;
    string inputspeed;
    string fromdiststr;
    string fromtimestr;
    string todiststr;
    string totimestr;

    int postoskip = 11;
    string str;
    for ( int idx=0; idx<a_speed.size(); idx++ )
    {
        char ch = a_speed[idx];
        if ( ch == ' ' )
        {
            spacecal++;
            if ( spacecal == 1 )
                inputspeed = str;
            else if ( spacecal == 2 )
            {
                fromdiststr = str;
                idx += 4;
            }
            else if ( spacecal == 3 )
            {
                fromtimestr = str;
                idx += postoskip;
            }
            else if ( spacecal == 4 )
            {
                todiststr = str;
                idx += 4;
            }

            str.clear();
            continue;
        }

        str += ch;     
    }

    totimestr = str;
    int speed = stoi(inputspeed);

    const float distfac = calculateFactor( distances, fromdiststr, todiststr );

    float timefac = calculateFactor( times, fromtimestr, totimestr );

    float convfac = distfac / timefac;
    float conv_speed = speed * convfac;
    cout.setf(ios::fixed);
    cout << setprecision(1) << conv_speed << " " << todiststr << " per " << totimestr <<endl; 
}
