/*
    Title:      Driver.cpp
    Purpose:    User interface and interactions 
*/

#include "Tree.h"
#include "Fish.h"
#include <iostream>
using namespace std;


void makeContestants(BinaryTree * tree, int contestants);
int lateQueens(BinaryTree * tree, int contestants, float disq);

int main()
{
    int contestants, choice;
    BinaryTree place; 
    float disqualify; 
    Fish skinny, curvy;
    
    //print out art
    cout << "\n  _   _   _   _     _   _   _   _  " ;
    cout << "\n / \\ / \\ / \\ / \\   / \\ / \\ / \\ / \\  ";
    cout << "\n( F | i | s | h ) ( S | h | o | w ) "; 
    cout << "\n \\_/ \\_/ \\_/ \\_/   \\_/ \\_/ \\_/ \\_/ "; 
    cout << "\n\nHosted by RuPaul the Queen Of The Drag Fishes!";

    cout << "\nHow many contestants showed up on time? (3-15)\n";
    cin >> contestants;
    while(contestants < 3 || contestants > 15)
    {
        cout << "\nSorry You Must Have 3-15 Contestants to Make A Good Show Darling!";
        cin >> contestants; 
    }
    makeContestants(&place, contestants); //calls function to get all contestants

    cout << "\nWell wasn't that Fish-tastic!!\n";
    cout << "\nTime to Disqualify ANY fishes with a Small Fin Size :(\n"; 
    cout << "\nWhat Fin Size is too small for our drag contest? ";
    cin >> disqualify;  
    place.disqualify(place.getRoot(), disqualify); // calls function to  disqualify 
    cout << "\nAnd life reminds me, again and again: You have to dismantle the old to make the space for something new.";
    cout << "\nNow of course we take fashionably late queens! \n\nEnter any last minute entries here: ";
    contestants = lateQueens(&place, contestants, disqualify);

    //getting and printing all results 
    cout << "\nMay the Best Fish Win!";
    skinny = place.min(place.getRoot());
    curvy = place.max(place.getRoot());
    cout << "\nOur Curvy Lady is....";
    curvy.printFish();  
    cout << "\nOur Skinny Queen is....";
    skinny.printFish(); 
    cout << "\n\nExcuses are for losers and winning is for winners like you!\n"; 
    cout << "Placements by weight:  \n";
    place.inOrder(place.getRoot());
    cout << "If you would like to see pre or post order: choose 1-Pre 2-Post 3-No";
    cin >> choice;
    while(choice == 1 || choice == 2)
    {
        if(choice == 1)
        {
            place.preOrder(place.getRoot());
        }
        else if(choice == 2)
        {
            place.postOrder(place.getRoot());
        }
        cout << "\nIf you would like to see pre or post order: choose 1-Pre 2-Post 3-No";
        cin >> choice; 
    }

    cout << "\n\nHaters gonna hate, but here are the only words you need for them. Sashay, away. \n\t- RuPaul The Queen Of The Drag Fishes!";
}

/********************************************************
 * makeContestants
 * gets all initial contestants by using a for loop
 *******************************************************/
void makeContestants(BinaryTree * tree, int contestants)
{
    string name, type;
    float weight, finSize; 

    for( int i =0; i<contestants; i++)
    {
        cin.ignore(); 
        cout << "\nOwner of Fish: ";
        getline(cin, name);
        cout << "Type Of Fish: ";
        getline(cin, type);
        cout << "Weight on Scale: ";
        cin >> weight;
        cout << "Length of Fin: ";
        cin >> finSize; 

        Fish newFish(name, type, weight, finSize);

        tree->insertNode(newFish); 
    }

    return; 
}

/********************************************************
 * lateQueens
 * gets all last minute additions
 *******************************************************/
int lateQueens(BinaryTree * tree, int contestants, float dis)
{
    string name, type;
    float weight, finSize;
    int choice; 

    do{
        cin.ignore();
        cout << "\nOwner of Fish: ";
        getline(cin, name);
        cout << "Type Of Fish: ";
        getline(cin, type);
        cout << "Weight on Scale: ";
        cin >> weight;
        cout << "Length of Fin: ";
        cin >> finSize; 
        
        Fish newFish(name, type, weight, finSize);

        if(newFish.getFS() < dis)
        {
            cout << "Queen Your Fins Are Tooooo Small\n";
            newFish.printFish(); 
            cout << "\nhas been disqualified! Good God Girl, You Gotta Get A Grip!";
        }
        else
        {
        tree->insertNode(newFish);
        contestants = contestants+1; 
        }

        cout << "\nIs another queen running behind? 1-yes 2-no\n";
        cin >> choice;
        while(choice < 1 || choice > 2)
        {
            cout << "It's simple darling! Yes(1) or No(2)\n";
            cin >> choice; 
        }

    }while(choice != 2);

    return contestants; 
}

