#ifndef PREDICTION
#define PREDICTION

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

vector<double> lane_speeds; //Vector or stored average speed of lanes


// Boolean return to tell us if a sensed vehicle is in the same lane as our lane
bool vehicleInOurLane(int our_lane_id, int lane_width, double targets_d)
{
    int lane_center = 2 + our_lane_id*lane_width;

    if (targets_d < (lane_center + 2) && targets_d > (lane_center - 2))
    {
        return true;
    }

    else
    {
        return false;
    }

}



// Boolean return to tell us if a sensed vehicle is in the adjacent lane
bool vehicleInTargetLane(int target_lane_id, int lane_width, double targets_d)
{
    int lane_center = 2 + target_lane_id*lane_width;

    if (targets_d < (lane_center + 2) && targets_d > (lane_center - 2))
    {
        return true;
    }

    else
    {
        return false;
    }

}

int identifyObjectLane(double d)
{
    int lane;
    if (d > 0 && d < 4)
    {
        lane = 0;
    }
    if (d > 4 && d < 8)
    {
        lane = 1;
    }
     if (d > 8 && d < 12)
    {
        lane = 2;
    }   

    return lane;

}


bool vehicleInBlindSpot( double object_position, double car_s, int object_lane, int car_lane, int blind_zone)
{

    //determine the lane of the vehicle
    if (car_lane != object_lane && abs(car_s - object_position) < blind_zone )
    {
        return true;
    } 
    else
    {
        return false;
    }
}

////THIS fuNCTIoN is NOT WORKING< The INDEXES ARE MESSED UP
vector<double> laneSpeedEstimator(vector<double> object_speeds, vector<double> target_d , vector<double> targets_s, double car_s, int num_of_lanes)
{
    //double closest_target = 100000000;
    double target_position;
    int key;
    vector<double> speeds;
    double lane;
    for (int i = 0; i< num_of_lanes; i++)
    {
        double closest_target = 100000000;
/*         cout << " i queals" << i << endl;
        cout << "object speed size list is: " << object_speeds.size() << endl; */
        for (int j = 0; j < object_speeds.size(); j++)
        {
            lane = identifyObjectLane(target_d[j]);
            //cout << " the targets lane is: " << lane << endl;
/*             cout << " j eaquals" << j << endl;
            cout << " the targets positions" << targets_s[j] << endl; */
            if (targets_s[j] > car_s && i == lane )
            {
                //cout << " j eaquals" << j << endl;
                if (closest_target > targets_s[j])
                {
                    closest_target = targets_s[j];
                }
                //cout << "new closest Target:" << closest_target << endl;
                key = j;
            }
 /*            lane = identifyObjectLane(target_d[i]);
            cout << "object lane = " <<lane << endl;
            cout << "index = " << j << endl;
            if (identifyObjectLane(target_d[j]) == i)
            {
                cout << "/n/n/n/n CLOSEST TARGET IS GETTING TO HEREEEEEE " << endl;
                
                if (j == 0);
                {
                    closest_target = targets_s[j];
                    cout << "J values is" << j <<endl;

                    
                }

                cout << " closest target calue is : " << closest_target << endl;
                cout << " new target calue is : " << targets_s[j] << endl;
                if (j >= 1 &&  targets_s[j] < closest_target)
                {
                    key = j ;
                    cout << " key ran" << endl;
                } */
           // }
            //closest_target = targets_s[j]
            
           ///////////////////////////////  cout << "The closest target in lane " << lane << " is " << closest_target << endl;
            
        }
        //cout << "\n\n\n\n" << endl;
        //speeds.push_back(2.0);
       // cout << " Speed of closes vehicle is :: " << object_speeds[key] << endl;
        speeds.push_back(closest_target);

    }
        
        return speeds;
}

/* double mergeWindow(int search_lane, double our_position, double target_position, bool search_direction)
{
    
} */



#endif

