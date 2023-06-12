#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

float max_thrust_max_angle = 100/180.0;
int max_dist = 18357;
bool boost = false;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{

    // game loop
    while (1) {
        int x;
        int y;
        int next_checkpoint_x; // x position of the next check point
        int next_checkpoint_y; // y position of the next check point
        int next_checkpoint_dist; // distance to the next checkpoint
        int next_checkpoint_angle; // angle between your pod orientation and the direction of the next checkpoint
        cin >> x >> y >> next_checkpoint_x >> next_checkpoint_y >> next_checkpoint_dist >> next_checkpoint_angle; cin.ignore();
        int opponent_x;
        int opponent_y;
        cin >> opponent_x >> opponent_y; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        // cerr << "distance: " << next_checkpoint_dist << endl;

        if (!boost && next_checkpoint_dist > 10000 && (next_checkpoint_angle < 30 && next_checkpoint_angle > -30)){
            cout << next_checkpoint_x << " " << next_checkpoint_y << " BOOST" << endl;
            boost = true;
            continue;
        }

        int thrust = 0;
        if (next_checkpoint_angle < -90 || next_checkpoint_angle > 90){
            thrust = 50;
        }
        else{
            if (next_checkpoint_angle < 30 || next_checkpoint_angle > -30){
                if (500 <= next_checkpoint_dist && next_checkpoint_dist <= 2000){
                    thrust = min(100, (int)((next_checkpoint_dist+1000)*0.05));
                }
                else{
                    thrust = 100;
                }
            }
            else{
                
                if (500 <= next_checkpoint_dist && next_checkpoint_dist <= 2000){
                    thrust = min(100, (int)((next_checkpoint_dist+100)*0.025));
                }
                else{
                    thrust = min(100, (int)((180-next_checkpoint_angle)*max_thrust_max_angle));
                }
            }
        }

        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"
        cout << next_checkpoint_x << " " << next_checkpoint_y << " " << thrust << endl;
    }
    
}
