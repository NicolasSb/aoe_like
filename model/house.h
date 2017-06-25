#ifndef HOUSE_H
#define HOUSE_H

#define HOUSE_HP 250

class House : public Building
{
public :
    House(int team);
    void printBuilding()const;
};

#endif // BARRACKS_H
