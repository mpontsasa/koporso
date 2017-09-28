#include <list>
#include <iostream>
#include "ScreenRoot.h"
#include "ScreenObject.h"

void ScreenObject::draw()
{
    drawThis(); //draw this object to screen
    auto dinIter = dinamicObjectList.begin();   //Iterator for list of dynamic sub-objects
    auto statIter = staticObjectList.begin();

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

ScreenRoot& ScreenRoot::access()
{
    static ScreenRoot root;
    return root;
}


void ScreenRoot::addBackground(Background *background_)
{
    background = background_;
}
