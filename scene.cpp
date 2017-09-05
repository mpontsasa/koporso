#include "scene.h"

Scene::Scene()
{

}

void Scene::addFixedGround(FixedGround *fg)
{
    fixedGrounds.push_back(fg);
}

void addStandardSO(StandardSO *sso)
{
    standardSOs.push_back(sso);
}
