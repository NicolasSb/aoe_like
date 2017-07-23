#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "characterType.h"
#include "buildingType.h"
#include "resourceType.h"
#include "animalType.h"

/**
*   \file   list.c
*   \brief  implementation of lists that will be used for characters and buildings
*   \author Nicolas Sourbier
*   \date   25/03/2017
*   \note   test coverage with GCOV is 80 %
*/



/**
*   \brief to initialize a list
*   \param \a type the type of the list ( should be LIST_PERSO or LIST_BUILDING)
*/

List::List(List_type type)
{
    this->type = type;
    this->nbElts=0;
}



/**
*   \brief to insert an element at the first position
*   \param \a l the list we want to insert the \a p element
*/
void List::insert_first(void *p, int team)
{
    Element *new_element = (Element *) calloc(1, sizeof(Element));
    if (this && new_element != NULL)
    {
        new_element->pointer = p;
        new_element->next = this->first;
        new_element->team = team;
        this->first = new_element;

        ++(this->nbElts);
    }
    else
    {
        free(new_element);
    }
}


/**
*   \brief to insert an element at the last position
*   \param \a l the list we want to insert the \a p element
*/
void List::insert_last(void *p, int team)
{
    if (this && !(this->first))
    {
        this->insert_first(p, team);
    }
    else if (this && this->first)
    {
        Element *new_element = (Element *)calloc(1, sizeof(Element));
        Element *current = this->first;
        while(current->next)
        {
            current=current->next;
        }
        new_element->pointer = p;
        new_element->next=NULL;
        new_element->team = team;
        current->next=new_element;
        ++(this->nbElts);
    }
}


/**
*   \brief to free the list AND it's elements
*   \param \a l the list we want to free
*/
List::~List()
{
    if (this)
    {
        while(this->first)
        {
            this->delete_first();
        }
    }
}

static void deleteElement(int type, Element * toDel)
{
    if(toDel)
    {
        switch (type)
        {
        case LIST_PERSO:
            if(toDel->pointer)
                ((Character*)(toDel->pointer))->~Character();
            break;
        case LIST_BUILDING:
            if(toDel->pointer)
                ((Building*)(toDel->pointer))->~Building();
            break;
        case LIST_RESOURCE:
            if(toDel->pointer)
                ((Resource*)(toDel->pointer))->~Resource();
            break;
        case LIST_ANIMALS:
            if(toDel->pointer)
                ((Animal*)(toDel->pointer))->~Animal();
            break;
        }
        free(toDel);
    }
}

/**
*   \brief to delete the first element
*/
void List::delete_first()
{

    if (this->first)
    {
        Element *toDel = this->first;
        this->first = this->first->next;
        toDel->next=NULL;
        deleteElement(this->type, toDel);
        --(this->nbElts);
    }
}


/**
*   \brief to delete an element by searching it in the list
*   \param \a l the list where we want to delete the \a p element
*   \note If the element is not found, nothing will happen
*/
void List::deleteBySearch(void *p)
{
    if(this)
    {
        Element *previous = this->first;
        Element *current =this->first;
        if(this->first->pointer==p)
        {
            this->delete_first();
            current = NULL;
            previous = NULL;
        }

        if (current)
        {
            do
            {
                if (current->pointer == p)
                {
                    previous->next=current->next;
                    current->next=NULL;
                    deleteElement(this->type, current);
                }
                else
                {
                    previous=current;
                    current=current->next;
                }
            }
            while (current);
        }
    }
}


/**
*   \brief to delete the first element
*/
void List::remove_first()
{
    if (this && this->first != NULL)
    {
        this->first = this->first->next;
        --(this->nbElts);
    }
}


/**
*   \brief to delete an element by searching it in the list without freeing it
*   \param \a l the list where we want to delete the \a p element
*   \note If the element is not found, nothing will happen
*/
void List::removeBySearch(void *p)
{
    if(this)
    {
        Element *previous = this->first;
        Element *current =this->first;
        if(this->first->pointer==p)
        {
            this->remove_first();
            current = NULL;
            previous = NULL;
        }

        if (current)
        {
            do
            {
                if (current->pointer == p)
                {
                    previous->next=current->next;
                    --(this->nbElts);
                    break;
                }
                else
                {
                    previous=current;
                    current=current->next;
                }
            }
            while (current);
        }
    }
}

/**
*   \brief to free the list BUT NOT it's elements
*   \param \a l the list we want to free
*/
void List::emptyList()
{
    if (this)
    {
        while(this->first!=NULL)
        {
            this->remove_first();
        }
        free(this);
    }
}



void * List::findElement(int d)
{
    int dist = 0;
    if (this)
    {
        Element *current = this->first;
        switch (this->type)
        {
        case LIST_BUILDING:
            if (current)
            {
                do
                {
                    Building *tmp = (Building *)current->pointer;
                    dist = tmp->getDistToCam();
                    if (dist==d)
                        return current;
                }
                while((current = current->next));
            }
            break;
        case LIST_PERSO:
            if (current)
            {
                do
                {
                    Character *tmp = (Character *)current->pointer;
                    if (tmp)
                    {
                        dist = tmp->getDistToCam();
                        if (dist==d)
                            return current;
                    }
                }
                while((current = current->next));
            }
            break;
        case LIST_RESOURCE:
            if (current)
            {
                do
                {
                    Resource *tmp = (Resource *)current->pointer;
                    dist = tmp->getDistToCam();
                    if (dist==d)
                        return current;
                }
                while((current = current->next));
            }
            break;
        case LIST_ANIMALS:
            if (current)
            {
                do
                {
                    Animal *tmp = (Animal *)current->pointer;
                    dist = tmp->getDistToCam();
                    if (dist==d)
                        return current;
                }
                while((current = current->next));
            }
            break;
        }
    }
    return NULL;
}

int* List::saveListDist()
{
    const int nb =this->nbElts;
    int *tabDist=(int *)malloc(sizeof(int)*nb);
    if (this)
    {
        int i;
        Element *current = this->first;
        switch (this->type)
        {
        case LIST_BUILDING:
            i=0;
            if (current)
            {
                do
                {
                    Building *tmp = (Building *)current->pointer;
                    tabDist[i]=tmp->getDistToCam();
                    ++i;
                }
                while((current=current->next));
            }
            break;
        case LIST_PERSO:
            i=0;
            if (current)
            {
                do
                {
                    Character *tmp = (Character *)current->pointer;
                    if (tmp)
                        tabDist[i]=tmp->getDistToCam();
                    ++i;
                }
                while((current=current->next));
            }
            break;
        case LIST_RESOURCE:
            i=0;
            if (current)
            {
                do
                {
                    Resource *tmp = (Resource *)current->pointer;
                    tabDist[i]=tmp->getDistToCam();
                    ++i;
                }
                while((current=current->next));
            }
            break;
        case LIST_ANIMALS:
            i=0;
            if (current)
            {
                do
                {
                    Animal *tmp = (Animal *)current->pointer;
                    tabDist[i]=tmp->getDistToCam();
                    ++i;
                }
                while((current=current->next));
            }
            break;
        }
        return tabDist;
    }
    return NULL;
}

static int compare (void const *a, void const *b)
{
    int const *pa = (int const *) a;
    int const *pb = (int const *)b;
    return *pb - *pa;
}

List *List::sortList()
{

    if (this)
    {
        int nbElt = this->nbElts;
        int i;
        int *a;
        switch(this->type)
        {
        case LIST_BUILDING:
            {
            List res(LIST_BUILDING);
            a = this->saveListDist();
            qsort(a, this->nbElts, sizeof(int), compare);
            for(i=0; i<nbElt; i++)
            {
                Element *e =(Element *) this->findElement(a[i]);
                Building *b = (Building *) e->pointer;
                if (e)
                {
                    res.insert_last((void *)b, e->team);
                    this->removeBySearch(e->pointer);
                    e->pointer=NULL;
                    e->next=NULL;
                    free(e);
                }
            }
            free(a);
            this->emptyList();
            return &res;
            }
        case LIST_PERSO:
            {
            List res(LIST_PERSO);
            a = this->saveListDist();
            qsort(a, this->nbElts, sizeof(int), compare);
            for(i=0; i<nbElt; i++)
            {
                Element *e = (Element *) this->findElement(a[i]);
                if (e)
                {
                    Character *p = (Character*)e->pointer;
                    res.insert_last((void*) p, e->team);
                    this->removeBySearch((void*) p);
                    e->pointer=p=NULL;
                    e->next=NULL;
                    free(e);
                }
            }
            free(a);
            this->emptyList();
            return &res;
            }
        case LIST_RESOURCE:
            {
            List res(LIST_RESOURCE);
            a =this-> saveListDist();
            qsort(a, this->nbElts, sizeof(int), compare);   /* a completer tester et vérifier*/
            for(i=0; i<nbElt; i++)
            {
                Element *e =(Element *) this->findElement(a[i]);
                Resource *r = (Resource *)e->pointer;
                if (e)
                {
                    res.insert_last((void*)r, e->team);
                    this->removeBySearch((void*)r);
                    e->pointer=NULL;
                    e->next=NULL;
                    free(e);
                }
            }
            free(a);
            this->emptyList();
            return &res;
            }
        case LIST_ANIMALS:
            {
            List res(LIST_ANIMALS);
            a = this->saveListDist();
            qsort(a, this->nbElts, sizeof(int), compare);   /* a completer tester et vérifier*/
            for(i=0; i<nbElt; i++)
            {
                Element *e = (Element*) this->findElement(a[i]);
                Animal *ani = (Animal *)e->pointer;
                if (e)
                {
                    res.insert_last((void*)ani, e->team);
                    this->removeBySearch((void*)ani);
                    e->pointer=NULL;
                    e->next=NULL;
                    free(e);
                }
            }
            free(a);
            this->emptyList();
            return &res;
            }

        }
    }
    return (List*) NULL;
}
