#ifndef TOWER_H
#define TOWER_H

#define TOWER_HP 400

class Tower : public Building
{
public :
    Tower(int team);
    void printBuilding()const;
};

#endif // BARRACKS_H
