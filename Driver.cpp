/*
    Title:      Driver.cpp
    Purpose:    to drive
*/

#include "Tree.h"
#include "Fish.h"
#include <iostream>
using namespace std;


void makeContestants(BinaryTree * tree, int contestants);
void disqualifyfunct(BinaryTree * tree, int disq, int contestants);
int lateQueens(BinaryTree * tree, int contestants);

int main()
{
    int contestants;
    BinaryTree place; 
    float disqualify; 
    Fish skinny, curvy;
    
    cout << " _   _   _   _     _   _   _   _  " ;
    cout << " / \\ / \\ / \\ / \\   / \\ / \\ / \\ / \\  ";
    cout << "( F | i | s | h ) ( S | h | o | w ) "; 
    cout << "  \\_/ \\_/ \\_/ \\_/   \\_/ \\_/ \\_/ \\_/ "; 
    cout << "\n\nHosted by RuPaul the Queen Of The Drag Fishes!";

    cout << "\nHow many contestants showed up on time? (3-15)";
    cin >> contestants;
    while(contestants < 3 || contestants > 15)
    {
        cout << "\nSorry You Must Have 3-15 Contestants to Make A Good Show Darling!";
        cin >> contestants; 
    }
    makeContestants(&place, contestants);

    cout << "\n Well wasn't that Fish-tastic!!";
    cout << "Time to Disqualify ANY fishes with a Small Fin Size :("; 
    cout << "What Fin Size is too small for our drag contest? ";
    cin >> disqualify;  
    disqualifyfunct(&place, disqualify, contestants); 
    cout << "\nAnd life reminds me, again and again: You have to dismantle the old to make the space for something new.";
    cout << "\nNow of course we take fashionably late queens! Enter any last minute entries here: ";
    contestants = lateQueens(&place, contestants);
    cout << "May the Best Fish Win!";
    skinny = place.min();
    curvy = place.max();
    cout << "Our Curvy Lady is....";
    curvy.printFish(); 
    cout << "Our Skinny Queen is....";
    skinny.printFish(); 
    cout << "Excuses are for losers and winning is for winners like you!"; 
    cout << "Curvy Lady Placements: ";
    place.postOrder();
    cout << "Skinny Queen Placements: ";
    place.preOrder();
    cout << "Haters gonna hate, but here are the only words you need for them. Sashay, away. - RuPaul The Queen Of The Drag Fishes!";
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

void disqualifyfunct(BinaryTree * tree, int disq, int contestants)
{
    Fish temp; 

    for(int i =0; i<contestants; i++)
    {
        if(tree->getFishSize() < disq)
        {
            temp = tree->deleteNode();
            temp.printFish();
            cout << "\nhas been disqualified! Good God Girl, You Gotta Get A Grip!";
        }
    }
}

int lateQueens(BinaryTree * tree, int contestants)
{
    string name, type;
    float weight, finSize;
    int choice; 

    do{
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
        contestants = contestants+1; 

        cout << "Is another queen running behind? 1-yes 2-no";
        cin >> choice;
        while(choice < 1 || choice > 2)
        {
            cout << "It's simple darling! Yes(1) or No(2)";
            cin >> choice; 
        }

    }while(choice != 2);

    return contestants; 
}

