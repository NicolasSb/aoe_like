#ifndef LIST_H
#define LIST_H


typedef struct Element Element;
struct Element
{
    void *pointer;
    Element *next;
    int team;
};
enum List_type{LIST_BUILDING, LIST_PERSO, LIST_RESOURCE, LIST_ANIMALS};
class List
{
protected :
    Element *first;
    int nbElts;
    List_type type;

public :
    List();
    List(List_type i);

    void insert_first(void *p, int team);
    void insert_last(void *p, int team);

    void delete_first();
    void deleteBySearch(void *p);

    void emptyList();
    ~List();
    List * sortList();

private :
    void remove_first();
    void removeBySearch(void *p);
    void* findElement(int d);
    int* saveListDist();
};

#endif
