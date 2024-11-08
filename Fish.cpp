  /*
    Name: Fish.cpp
    Purpose: Holds all Functions needed for class Fish
  */
  
  #include "Fish.h"

    //setters
    void Fish::setON(string n)
    {
        this->ownerName = n;
    }
    void Fish::setTF(string f)
    {
        this->typeOfFish = f;
    }
    void Fish::setW(float w)
    {
        this->weight = w;
    }
    void Fish::setFS(float fs)
    {
        this->finSize = fs;
    }

    //getters
    string Fish::getON() const
    {
        return this->ownerName;
    }
    string Fish::getTF() const
    {
        return this->typeOfFish;
    }
    float Fish::getW() const
    {
        return this->weight;
    }
    float Fish::getFS() const
    {
        return this->finSize;
    }

