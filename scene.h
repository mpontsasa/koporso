#ifndef SCENE_H
#define SCENE_H
#include <list>

class Scene
{
public:
    Scene();
    void addFixedGround(FixedGround *fg);
    void addStandardSO(StandardSO *sso);

    bool hit(sf::Vector2i){return true;}
    void drawThis(){}

protected:
    std::list<FixedGround*> fixedGrounds;  //list of fixed grounds on the scene
    std::list<StandardSO*> standardSOs;   //standardSOs on the Scene
private:
};

#endif // SCENE_H
