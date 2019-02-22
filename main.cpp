#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main() {
    cout << "Caleb Stinebaugh\n";
    cout << "Programming Foundations 1 Homework 3, 2/22/2019.\n";

    // Animals and Boxes
    int camels, mules;
    cout << "You are about to begin your busy day of thieving.\n";
    cout << "You will need animals to help you carry away your loot.\n";

    cout << "Enter the number of camels you have: \n";
    cin >> camels;
    while (camels <= 0) {
        cout << "Please enter a positive amount!\n";
        cin >> camels;
    }
    cout << "Enter the number of mules you have: \n";
    cin >> mules;
    while (mules <= 0) {
        cout << "Please enter a positive amount!\n";
        cin >> mules;
    }
    int tripBoxes = (camels * 6)+(mules * 4);
    cout << "With " << camels << " camels and " << mules << " mules, you can carry at most "
         << (tripBoxes) << " boxes of treasure per trip\n";


    //Loot Cave Loop
    int numChamb,totalCaveBoxes;
    char caveAns;
    cout << "There is a cave up ahead that may have treasure. Do you want to enter it? Enter y or n: \n";
    cin >> caveAns;
    while (caveAns != 'y' && caveAns != 'n') {
        cout << "Please enter y or n!\n";
        cin >> caveAns;
    }
    while (caveAns == 'y') {
        cout << "How many chambers did you find? Enter a positive number between 1-10: \n";
        cin >> numChamb;
        while (numChamb <= 0 || numChamb > 10) {
            cout << "Please enter a positive number\n";
            cin >> numChamb;
        }
        for (int room = 1; room <= numChamb; room++) {
            int caveBox = (rand() % 100) + 1;
            totalCaveBoxes += caveBox;
            cout << "In chamber number " << room << " you found " << caveBox << " boxes!\n";
        }
        cout << "There are " << totalCaveBoxes << " boxes in this cave.\n";

        //trips
        int tripsTaken = (totalCaveBoxes / tripBoxes);
        if ((totalCaveBoxes % tripBoxes) == 0)
            cout << "You can transfer all the boxes in " << tripsTaken << " trip(s).\n";
        else
            cout << "You can transfer all the boxes in " << tripsTaken + 1 << " trip(s).\n";

        //time
        int userDist, totalDist;
        cout << "Calculating the time...\n"
             << "How many miles away from your cave are you? Enter a positive integer: \n";
        cin >> userDist;
        while (userDist <= 0) {
            cout << "Please enter a positive number!\n";
            cin >> userDist;
        }
        if (tripsTaken == 1)
            totalDist = userDist;
        else
            totalDist = userDist + (tripsTaken) * userDist * 2;
        float userTime = totalDist / 5;;
        cout << "Including the return trips to get more gold, you will need to travel " << totalDist << " miles.\n"
             << "At 5 mpg that will take " << userTime << " hours.\n";
        cout << "Do you want to enter another cave? \n" << "Enter y or n: \n";
        cin >> caveAns;
    }
    if (caveAns == 'n'){
        cout << "Your thieving days are over!\n";
    }
    return 0;
}