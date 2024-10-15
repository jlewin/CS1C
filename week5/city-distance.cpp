#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

  // The string that simulates the input (e.g., what would be entered by the user)
    string test_input = "4 4.5 6.8 3.4 -0.3 76.7 9 -34 -25.5";
    
    // Create a string stream from the test input
    istringstream input_stream(test_input);
    
    // Redirect std::cin to read from input_stream instead of the actual standard input
    cin.rdbuf(input_stream.rdbuf());

    cout << "Enter the number of cities: ";
    int cityCount;
    cin >> cityCount;

    double cities[cityCount][2];
    double travelLengths[cityCount];

    cout << "Enter the coordinates of the cities: ";
    for (int r = 0; r < cityCount; r++) {
        for (int c = 0; c < 2; c++) {
            cin >> cities[r][c];
        }
    }

    double shortestTravel = std::numeric_limits<double>::max();
    int shortestIndex = 0;

    // Calcuculate travel to other cities
    for (int i = 0; i < cityCount; i++) {
        travelLengths[i] = 0;
        
        for (int j = 0; j < cityCount; j++) {
            if (j != i) {
                double deltaX = cities[i][0] - cities[j][0];
                double deltaY = cities[i][1] - cities[j][1];
                double distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2)); 

                travelLengths[i] += abs(distance);
            }
        }

        if (travelLengths[i] < shortestTravel) {
            shortestTravel = travelLengths[i];
            shortestIndex = i;
        }
    }

    double* coords = cities[shortestIndex];

    cout << "The central city is at " << fixed << setprecision(1)
         << "(" << coords[0] << ", " << coords[1] <<")" << endl;

    cout << "The total distance to all other cities is " << travelLengths[shortestIndex] << endl;

    return 0;
}