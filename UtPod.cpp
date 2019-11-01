//
// Created by mehah on 11/1/2019.
//

#include "UtPod.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include<ctime>
using namespace std;


UtPod::UtPod()
{
    songs = NULL;
    memSize = MAX_MEMORY;
    srand(time(NULL));
}

UtPod::UtPod(int size)
{
    songs = NULL;
    if(size<=0 || size> MAX_MEMORY)
    {
        memSize = MAX_MEMORY;
    }
    else
        memSize = size;
}

int UtPod::addSong(Song const &s)
{
    Song t = s;
    if(t.getSize()<getRemainingMemory())
    {
        SongNode *temp = new SongNode();
        temp -> next = songs;
        temp ->s = s;
        songs = temp;
        return SUCCESS;
    }
    return NO_MEMORY;
}

int UtPod::removeSong(Song const &s)
{
    SongNode *temp = songs;
    if(temp -> s == s)
    {
        SongNode *t = temp;
        songs = songs -> next;
        delete t;
        return 0;
    }
    while(temp -> next != NULL)
    {
        if(temp -> next -> s == s)
        {
            if(temp -> next -> next == NULL)
            {
                SongNode *t = temp->next;
                temp -> next = NULL;
                delete t; 
            }
                
            else
            {
                SongNode *t = temp->next;
		temp->next->s = temp->next->next->s;
                temp->next = temp->next->next;
                delete t;
                
            }
            return SUCCESS;
        }
        temp = temp -> next;
    }

    return NOT_FOUND;
}

void UtPod::shuffle()
{
    SongNode *temp = songs;
    int count = 1;
    while(temp->next != NULL)
    {
        count++;
        temp = temp ->next;
    }
    if(count >= 2)
    {
        for(int i = 0; i < 2*count; i++)
        {
            int random1 = rand() % count;
            int random2 = rand() % count;
            if(random1 != random2)
            {
                SongNode *ptr1 = songs;
                SongNode *ptr2 = songs;
                for(int j = 0; j < random1; j++)
                {
                    ptr1 = ptr1 -> next;
                }
                for(int k = 0; k < random2; k++)
                {
                    ptr2 = ptr2 -> next;
                }
                Song t = ptr1 -> s;
                ptr1 -> s = ptr2 -> s;
                ptr2 -> s = t;

            }
        }

    }
}

void UtPod::showSongList()
{
    SongNode *temp = songs;
    while(temp != NULL)
    {
        cout<< temp -> s.getTitle() << " "<< temp -> s.getArtist() << " "<< temp -> s.getSize() << "\n";
        temp = temp ->next;
    }
}

void UtPod::sortSongList()
{

    for(SongNode *p1 = songs; p1!=NULL; p1=p1->next)
    {
        for(SongNode *p2 = p1 -> next; p2!=NULL; p2=p2->next)
        {
            if (p2->s<p1->s)
            {
                Song t = p1->s;
                p1->s = p2 -> s;
                p2 -> s = t;
            }
        }
    }

}

void UtPod::clearMemory()
{
    SongNode *empty = songs;
    SongNode *front = songs ->next;
    while(front -> next != NULL)
    {
        delete(empty);
        empty = front;
        front = front -> next;
    }
    delete(empty);
    delete(front);
}

int UtPod::getRemainingMemory()
{
    SongNode *temp = songs;
    int memory = 0;
    while(temp != NULL)
    {
        memory += temp -> s.getSize();
        temp = temp ->next;
    }
    return memSize - memory;
}

UtPod::~UtPod(){
    clearMemory();
}
