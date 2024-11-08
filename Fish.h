/*
    Name: Fish.h
    Purpose: Is the Header file for Fish.h or the data class
*/

#ifndef Fish_H
#define Fish_H

#include <string>
#include<iomanip>
#include<iostream>
using namespace std; 

class Fish 
{
    private:
    string ownerName, typeOfFish;
    float weight, finSize;

    public:

    //Constructors
    Fish() //default
    {
        this->ownerName = " ";
        this->typeOfFish = " ";
        this->weight = 0;
        this->finSize = 0;
    }

    Fish(string on, string tf, float w, float fs) //Overloaded
    {
        this->ownerName = on;
        this->typeOfFish = tf;
        this->weight = w;
        this->finSize = fs;
    }

    //setters
    void setON(string n);
    void setTF(string f);
    void setW(float w);
    void setFS(float fs);

    //getters
    string getON() const;
    string getTF() const;
    float getW() const;
    float getFS() const;

    ~Fish()
    {
        //need to do
    }

};


#endif