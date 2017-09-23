#include <list>
#include <iostream>
#include "ScreenRoot.h"
#include "ScreenObject.h"

void ScreenObject::draw()
{
    drawThis(); //draw this object to screen
    auto dinIter = dinamicObjectList.begin();   //Iterator for list of dynamic sub-objects
    auto statIter = staticObjectList.begin();
    auto groundIter = groundObjectList.begin();

    //std::cout<<"\n"<<*dinIter<<" "<<*statIter<<'\n';


    while (groundIter != groundObjectList.end())
    {
        (*groundIter) -> draw();
        groundIter ++;
    }
    while (statIter != staticObjectList.end())
    {
        (*statIter) -> draw();
        statIter ++;
    }
    while (dinIter != dinamicObjectList.end())
    {
        (*dinIter) -> draw();
        dinIter ++;
    }
    /*while(dinIter != dinamicObjectList.end() || statIter != staticObjectList.end() || groundIter != groundObjectList.end()) //While there are any objects, draw the one in the back
    {

        if (statIter != staticObjectList.end() &&
        (dinIter == dinamicObjectList.end() ||
        (*dinIter) -> zValue >= (*statIter) -> zValue))  //if the first static obj is behind the first dynamic
        {
            if(groundIter == groundObjectList.end() ||
               (*groundIter) -> getFront() < (*statIter) -> getBack())    //if the ground is behind the static obj
            {
                (*statIter) -> draw();
                statIter ++;
            }
            else if((*groundIter) -> getBack() > (*statIter) -> getFront()) //if the static obj is behind the ground
            {
                (*groundIter) -> draw();
                groundIter ++;
            }
            else if ((*statIter) -> getTop() <= (*groundIter) -> getTop())   //if the static obj is below the ground obj
            {
                (*groundIter) -> draw();
                groundIter ++;
            }
            else    //if the static obj is below the ground obj
            {
                (*statIter) -> draw();
                statIter ++;
            }
        }
        else if (dinIter == dinamicObjectList.end())    //if the first dynamic obj is behind the first static
        {
            if(groundIter == groundObjectList.end() ||
               (*groundIter) -> getFront() < (*dinIter) -> getBack())    //if the ground is behind the static obj
            {
                (*dinIter) -> draw();
                dinIter ++;
            }
            else if((*groundIter) -> getBack() > (*dinIter) -> getFront()) //if the static obj is behind the ground
            {
                (*groundIter) -> draw();
                groundIter ++;
            }
            else if ((*dinIter) -> getTop() <= (*groundIter) -> getTop())   //if the static obj is below the ground obj
            {
                (*groundIter) -> draw();
                groundIter ++;
            }
            else    //if the static obj is below the ground obj
            {
                (*dinIter) -> draw();
                dinIter ++;
            }
        }
        else    // if only ground objects are left
        {
            (*groundIter) -> draw();
            groundIter ++;
        }
    }*/
}

void ScreenObject::addStaticSo(ScreenObject *so_)
{
    staticObjectList.push_back(NULL);

    auto li = staticObjectList.end();  //list iterator
    auto li2 = li;       //LIST ITERATOR 2
    li2 --; // li2 points to last member
    li2 --; //li2 points to semi-last member
    li --;  // li points to last member

    while(li != staticObjectList.begin() && (*li2) -> zValue > so_ -> zValue)
    {
        (*li) = (*li2);
        li --;
        li2--;
    }
    (*li) = so_;

}

void ScreenObject::addDinamicSo(ScreenObject *so_)
{
    dinamicObjectList.push_back(NULL);

    auto li = dinamicObjectList.end();  //list iterator
    auto li2 = li;       //LIST ITERATOR 2
    li2 --; // li2 points to last member
    li2 --; //li2 points to semi-last member
    li --;  // li points to last member

    while(li != dinamicObjectList.begin() && (*li2) -> zValue > so_ -> zValue)
    {
        (*li) = (*li2);
        li --;
        li2--;
    }
    (*li) = so_;
}

void ScreenObject::addGroundSo(ScreenObject *so_)
{
    dinamicObjectList.push_back(NULL);

    auto li = groundObjectList.end();  //list iterator
    auto li2 = li;       //LIST ITERATOR 2
    li2 --; // li2 points to last member
    li2 --; //li2 points to semi-last member
    li --;  // li points to last member

    while(li != groundObjectList.begin() && (*li2) -> zValue > so_ -> zValue)
    {
        (*li) = (*li2);
        li --;
        li2--;
    }
    (*li) = so_;
}

ScreenRoot& ScreenRoot::access()
{
    static ScreenRoot root;
    return root;
}


void ScreenRoot::addBackground(Background *background_)
{
    background = background_;
}
