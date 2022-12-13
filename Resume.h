#include<iostream>
using namespace std;
struct Resume
{
    Resume* next;
    Resume* prior;
    int num;
    Resume();
    Resume(int item, Resume* priorlink = NULL, Resume* nextlink = NULL);
};

Resume::Resume()
{
    prior = NULL;
    next = NULL;
}

Resume::Resume(int item, Resume* priorlink, Resume* nextlink)
{
    num = item;
    prior = priorlink;
    next = nextlink;
}
