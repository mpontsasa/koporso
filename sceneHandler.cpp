#include "sceneHandler.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Background.h"
#include "ScreenRoot.h"
#include "Creature.h"
#include "Thing.h"




std::vector<std::string>& split(const std::string& str, char delim, std::vector<std::string>& elems )
{

    std::stringstream ss(str+' ');
    std::string item;
    while(std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}
///^^^copied shamelessly from stackoverflow, splits first argument according to second argument and puts the elements into third argument
///could be rewritten into void form




className strToClass(std::string x)
{
    if(x == "Background") return Background_enum;
    else if(x == "Creature") return Creature_enum;
    else if(x == "Thing") return Thing_enum;
    else if(x == "FixedGround") return FixedGround_enum;
    else return Background_enum;///will never execute unless file is written incorrectly, could be reformatted into error handling
}
///^^^convert a string into the corresponding enum type
///used for a switch() in the file loader function

void loadSceneFromFile(std::string inputFileLocation)
{
    ScreenRoot::access().wipeRoot();
    //std::cout << inputFileLocation;
    std::ifstream inputFile(inputFileLocation);
    std::string inputString;
    //getline(inputFile,inputString);
    //std::cout << inputString;
    //std::cout << "jenfjenf";

    getline(inputFile,inputString);
    while(inputString != "END")
    {
        std::vector<std::string> objectData;
        split(inputString,';',objectData);
        //std::cout << objectData[0];
        switch(strToClass(objectData[0]))
        {
        case Background_enum:
            {

                std::string image = objectData[1];
                int x = stoi(objectData[2]); ///conversion from string to integer, mingw needs patching in order to work
                int y = stoi(objectData[3]);
                int z = stoi(objectData[4]);
                float ratio_x = stof(objectData[5]);

                Background* background = new Background(image.c_str(),x,y,z,ratio_x);
                (ScreenRoot::access()).addBackground(background);

            }
            break;
        case Creature_enum:
            {
                std::string image = objectData[1];
                int x = stoi(objectData[2]);
                int y = stoi(objectData[3]);
                int z = stoi(objectData[4]);
                int height = stoi(objectData[5]);
                int width = stoi(objectData[6]);
                Creature* creature = new Creature(image.c_str(),x,y,z,height,width);
                (ScreenRoot::access()).addStaticSo(creature);
            }
            break;
        case Thing_enum:
            {
                std::string image = objectData[1];
                int x = stoi(objectData[2]);
                int y = stoi(objectData[3]);
                int depth = stoi(objectData[4]);
                Thing* thing = new Thing(image.c_str(),x,y,depth);
                (ScreenRoot::access()).addStaticSo(thing);
            }
            break;
        case FixedGround_enum:
            {
                std::string image = objectData[1];
                int x = stoi(objectData[2]);
                int y = stoi(objectData[3]);
                int z = stoi(objectData[4]);
                int width = stoi(objectData[5]);
                int height = stoi(objectData[6]);
                FixedGround* theGround = new FixedGround(image.c_str(),x,y,z,width,height);
                (ScreenRoot::access()).addFixedGround(theGround); ///this is for the initialization of the protagonist
                (ScreenRoot::access()).addStaticSo(theGround);

            }
            break;
        }


        getline(inputFile,inputString);
    }
}
