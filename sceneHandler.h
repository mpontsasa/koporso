#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

std::vector<std::string>& split(const std::string& str, char delim, std::vector<std::string>& elems );

enum className
{Background_enum,Creature_enum,Thing_enum,FixedGround_enum};

className strToClass(std::string x);


void loadSceneFromFile(std::string inputFileLocation);
///calls ScreenRoot::WipeRoot()
///MUST BE CALLED BEFORE ADDING THE PROTAGONIST
