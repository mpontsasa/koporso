#include <list>
#include <iostream>
#include "ScreenRoot.h"
#include "ScreenObject.h"

void ScreenObject::draw()
{
    drawThis(); //draw this object to screen
    auto dinIter = dinamicObjectList.begin();   //Iterator for list of dynamic sub-objects
    auto statIter = staticObjectList.begin();


    while(dinIter != dinamicObjectList.end() && statIter != staticObjectList.end()) //While there are static and dynamic objects to, draw the one in the back
    {

        if ((*dinIter) -> getFront() < (*statIter) -> getBack())
        {
            (*dinIter) -> draw();
            dinIter ++;
        }
        else
        {
            (*statIter) -> draw();
            statIter ++;
        }
    }
    while (dinIter != dinamicObjectList.end())  //draw remaining dynamic screen objects
    {
        (*dinIter) -> draw();
        dinIter ++;
    }
    while (statIter != staticObjectList.end()) //draw remaining static screen objects
    {
            (*statIter) -> draw();
            statIter ++;
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

void ScreenObject::oneElementSort_din()
{
    auto iter = dinamicObjectList.begin();
    iter ++;
    for (;iter != dinamicObjectList.end(); iter ++)
    {

        auto last = iter;
        last --;
        if ((*iter) ->getFront() < (*last) ->getFront())
        {
            ScreenObject *swc = *iter;
            *iter = *last;
            *last = swc;
        }
    }

    iter = dinamicObjectList.end();
    iter --;
    if (iter != dinamicObjectList.begin())
        iter --;

    for (;iter != dinamicObjectList.begin(); iter --)
    {
        auto next = iter;
        next ++;
        if ((*iter) ->getFront() > (*next) ->getFront())
        {
            std::cout << "2\n";
            ScreenObject *swc = *iter;
            *iter = *next;
            *next = swc;
        }
    }
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

void ScreenRoot::addFixedGround(FixedGround *theGround_)
{
    theGround = theGround_;
}

void ScreenRoot::wipeRoot()
{
    for(auto iter = dinamicObjectList.begin(); iter != dinamicObjectList.end(); iter++)
    {
        delete *iter;
    }
    for(auto iter = staticObjectList.begin(); iter != staticObjectList.end(); iter++)
    {
        delete *iter;
    }
    dinamicObjectList.erase(dinamicObjectList.begin(),dinamicObjectList.end());
    staticObjectList.erase(staticObjectList.begin(),staticObjectList.end());
    background = NULL;
}
