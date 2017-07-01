#ifndef ANIMAL_T_H
#define ANIMAL_T_H

#define WOLF_SPEED 2
#define BOAR_SPEED 1
#define SHEEP_SPEED 1
#define STAG_SPEED 2

#define WOLF_DAMMAGE 10
#define BOAR_DAMMAGE 7
#define SHEEP_DAMMAGE 0
#define STAG_DAMMAGE 0

#define WOLF_HP 30
#define BOAR_HP 30
#define SHEEP_HP 5
#define STAG_HP 20

#define WOLF_MEAT 60
#define BOAR_MEAT 60
#define SHEEP_MEAT 150
#define STAG_MEAT 300


class Boar : public Animal
{
public :
    Boar();
};

class Sheep: public Animal
{
public :
    Sheep();
};

class Stag: public Animal
{
public :
    Stag();
};

class Wolf : public Animal
{
public :
    Wolf();
};




#endif
