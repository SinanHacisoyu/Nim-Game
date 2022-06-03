# include <iostream>
using namespace std;

//Sinan Hacisoyu

void displayStatus(int firstRow, int secondRow, int thirdRow, int fourthRow);
void gameFunction();

int main() {
    cout<<"Welcome to matchsticks!"<<endl;
    cout<<"Select the Game Mode:  1)Against Computer   2)Two Players"<<endl;
    int selection;
    cin>>selection;
    if (selection == 2) {
        gameFunction();
    } else {
        //Computer
    }
}

void gameFunction() {
    int firstRow = 1;
    int secondRow = 3;
    int thirdRow = 5;
    int fourthRow = 7;
    int total = 16;
    int fourCount = 2;
    int twoCount = 2;
    int oneCount = 4;
    string turn;
    
    //Multiplayer - two player plays against each other
    // assigning names to user1 and user2 and user1 starts to play
    string user1, user2;
    cout<<"Enter User 1 Name: "<<endl;
    cin>>user1;
    cout<<endl<<"Enter User 2 Name:"<<endl;
    cin>>user2;
    cout<<"Game Starts "<<endl;
    turn = user1;

    while (total>=1) { // running until 1 stick left in the game
        cout<<"Current Status:"<<endl;
        displayStatus(firstRow, secondRow, thirdRow, fourthRow); // showing the stick table

        // selecting row and amount to delete the desired number of sticks
        int selectedRow, selectedAmount;
        cout<<"Turn: "<<turn<<endl;
        cout<<"Enter the number of row"<<endl;
        cin>>selectedRow;
        cout<<"Enter the amount of sticks that you want to pull"<<endl;
        cin>>selectedAmount;
        cout<<"Turn: "<<turn<<" has chose Row: "<<selectedRow<<"  Amount: "<<selectedAmount<<endl;

        // according to selected row and amount, deleting the desired number of sticks
        if (selectedRow == 1) {
            firstRow -= selectedAmount;
        } else if (selectedRow == 2) {
            secondRow -= selectedAmount;
        } else if (selectedRow == 3) {
            thirdRow -= selectedAmount;
        } else {
            fourthRow -= selectedAmount;
        }
        total = total - selectedAmount; // to continue and finish the game: If 1 stick left, finish the game otherwise continue
        if (turn == user1) { // to change the turn of the player in every selection of sticks
            turn = user2;
        } else {
            turn = user1;
        }

        if (total <= 1) { // defining the winner
            string winner;
            if (turn == user1) { //if the game stops when the turn of user1, user2 wins bcs user1 have last stick
                winner = user2;
            } else { //if the game stops when the turn of user2, user1 wins bcs user1 have last stick
                winner = user1;
            }
            cout<<endl<<"Winner is: "<<winner<<endl; 
            cout<<"Play Again?"<<endl; // to play the game again
            string yesno;
            cin>>yesno;
            if (yesno == "yes") {
                gameFunction();
            }
            break;
        }
    } 
}

void displayStatus(int firstRow, int secondRow, int thirdRow, int fourthRow) {
    // creating sticks according to rows
    for(int i=0; i<firstRow; i++) { //first row 1 stick
        cout<<"|";
    }
    cout<<endl;
    for(int i=0; i<secondRow; i++) { //second row 3 stick
        cout<<"|";
    }
    cout<<endl;
    for(int i=0; i<thirdRow; i++) { //third row 5 stick
        cout<<"|";
    }
    cout<<endl;
    for(int i=0; i<fourthRow; i++) { //fourth row 7 stick
        cout<<"|";
    }
    cout<<endl;
}