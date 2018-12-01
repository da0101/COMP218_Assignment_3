// COMP 218
// Danil Ulmashev
//
// A C++ program that sets a game of 23 where each player during the play is allowed to 
// remove 1 - 3 sticks from a pile until there is only one left. A player who is left to 
// remove the last stick loses the game.
//

// Adding libraries
#include <iostream>
#include <cstdlib>

using namespace std;

// Declaring functions
void printHeader();
void userTurn(bool playerOne);
void computerTurn();
int getUserPick();
int getComputerPick();

// Setting initial amount toothpicks at the beginning of the game
int toothPicks = 23;

// User names
string name1;
string name2;
bool multiplayer = false;

// main class
int main() {
    printHeader();
    return 0;
}

// Declaring function to set multiplayer or not
void setMultiplayer() {
    char answer;
    cout << "Multiplayer? <y/n>";
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {
        multiplayer = true;
    }
}

// Declaring function to set names for player 1 and 2
void setPlayerName(bool playerOne) {
    cout << "Welcome Player" << (playerOne ? "1" : "2") << " ... by the way what do I call you? ";
    if (playerOne) {
        cin >> name1;
    }
    else {
        cin >> name2;
    }
}

// Declaring funciton to print the header and rules of the game 
void printHeader() {
    string ch = "¦";
    cout << ch << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << ch << endl;
    cout << ch << "                  Welcome to \"23\"!                 " << ch << endl;
    cout << ch << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << ch << endl;
    cout << endl;

    // Calling program functions 
    setMultiplayer();
    setPlayerName(true);
    if (multiplayer) {
        setPlayerName(false);
    }


    cout << "_____________________________________________________" << endl;
    cout << endl;
    cout << "I have to tell you I am really good at this game :-) " << endl;
    cout << endl;
    cout << "Here are the rules: " << endl;
    cout << "       You can remove between 1 and 3 toothpicks " << endl;
    cout << "       You can't remove more toothpicks than exists in the pile" << endl << endl;

    // Checking if the user is ready to play
    while (true) {
        cout << "Are you ready? <y/n> ";
        char answer;
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            system("CLEAR");
            cout << "Here we go. May the best player win ... hahaha \n";
            userTurn(true);
            return;
        }
        if (answer == 'n' || answer == 'N') {
            cout << "Come back when you are ready :-) \n";
            return;
        }
        cout << "Please answer with y or n \n";
    }
}

// Getting player's name
string getPlayerName(bool playerOne) {
    if (playerOne) {
        return name1;
    }
    return name2;
}

// Declaring function for user's turn
void userTurn(bool playerOne) {

    cout << "User Turn - " << getPlayerName(playerOne) << endl;

    // No toothpicks left, User lost
    if (toothPicks < 1) {
        cout << ">>>>>        Nanananana " << getPlayerName(!playerOne) <<"! " << "There is no toothpick left. " << endl;
        cout << ">>>>>        I told you I was good." << endl << endl;
        return;
    }

    // One toothpick left, Computer lost
    if (toothPicks == 1) {
        cout << " >>>>>OK " << getPlayerName(!playerOne) << ". " << " There is one toothpick left and I have to remove it. " << endl;
        cout << " >>>>>You won this game!!!!!! " << endl << endl;
        return;
    }

    int userPick = getUserPick();
    toothPicks -= userPick;
    cout << "    ---->Toothpicks remaining: " << toothPicks << endl << endl;
    

    if (multiplayer) {
        userTurn(!playerOne);
    }
    else {
        computerTurn();
    }
}

// Declaring function for computer's turn
void computerTurn() {

    cout << "Computer Turn" << endl;

    // No toothpicks left, User lost
    if (toothPicks < 1) {
        cout << ">>>>>        Nanananana " << getPlayerName(true) <<"! " << "There is no toothpick left. " << endl;
        cout << ">>>>>        I told you I was good." << endl;
        return;
    }

    // One toothpick left, Computer lost
    if (toothPicks == 1) {
        cout << " >>>>>OK " << getPlayerName(true) << ". " << " There is one toothpick left and I have to remove it. " << endl;
        cout << " >>>>>You won this game!!!!!! " << endl << endl;
        return;
    }

    // More than one toothpick, let's play
    int compPicks = getComputerPick();
    toothPicks -= compPicks;
    cout << "I removed " << compPicks << " toothpicks. " << endl;
    cout << "    ---->Toothpicks remaining: " << toothPicks << endl << endl;

    if (toothPicks > 1) {
        userTurn(true);
        return;
    }
    if (toothPicks == 1) {
        cout << ">>>>>        Nanananana " << getPlayerName(true) <<"! " << "There is one toothpick left. " << endl;
        cout << ">>>>>        You don't have a choice... I told you I was good." << endl << endl;
    }
}

// Declaring function for picking user's the tooth picks.
int getUserPick() {

    int maxPick = 3;
    if (toothPicks < 3) {
        maxPick = toothPicks;
    }

    int userPick;
    cout << endl;
    cout << "how many toothpicks do you want to remove <1 to " << maxPick << " >? ";
    cin >> userPick;
    
    if (userPick > maxPick) {
        cout << endl;
        cout << "Your number is too large " << endl << endl;
        return getUserPick();
    }

    if (userPick < 1) {
        cout << endl;
        cout << "You need to remove atleast one toothpick " << endl << endl;
        return getUserPick();
    }

    return userPick;
}

// Declaring function for picking computer's the tooth picks.
int getComputerPick() {
    if (toothPicks == 3) {
        return 2;
    }
    if (toothPicks == 2) {
        return 1;
    }
    srand(time(0));
    return 1 + (rand() % 3);
}
