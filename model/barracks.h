#ifndef BARRACKS_H
#define BARRACKS_H

#define BARRACKS_HP 400

class Barrack : public Building
{
public :
    Barrack(int team);
    void printBuilding()const;
};

#endif // BARRACKS_H
