/*
    Title:      Driver.cpp
    Purpose:    to drive
*/

#include "Tree.h"
#include "Fish.h"
#include <iostream>
using namespace std;

int main()
{
    int contestants;
    BinaryTree place; 
    
    cout << " _   _   _   _     _   _   _   _  " ;
    cout << " / \\ / \\ / \\ / \\   / \\ / \\ / \\ / \\  ";
    cout << "( F | i | s | h ) ( S | h | o | w ) "; 
    cout << "  \\_/ \\_/ \\_/ \\_/   \\_/ \\_/ \\_/ \\_/ "; 

    cout << "\nHow many contestants showed up on time? (3-15)";
    cin >> contestants;
    while(contestants < 3 || contestants > 15)
    {
        cout << "\nSorry You Must Have 3-15 Contestestants to Make A Good Show Darling!";
        cin >> contestants; 
    }
    makeContestants(&place, contestants);

    cout << "\n Well wasn't that Fish-tastic!!";
    cout << "Time to Disqualify ANY fishes with a Small Fin Size :("; 
}


void makeContestants(BinaryTree * tree, int contestants)
{
    string name, type;
    float weight, finSize; 

    for( int i =0; i<contestants; i++)
    {
        cout << "Owner of Fish: ";
        getline(cin, name);
        cout << "Type Of Fish: ";
        getline(cin, type);
        cout << "Weight on Scale: ";
        cin >> weight;
        cout << "Length of Fin: ";
        cin >> finSize; 

        Fish newFish(name, type, weight, finSize);

        tree->insert(newFish); 
    }

    return; 
}