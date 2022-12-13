#pragma once
#include<iostream>
#include"Resume.h"
class Interview
{
private:
    Resume* head = nullptr;
    int length = 0;
    int OriginLength = 0;
public:
    Interview();
    ~Interview();
    void GetResume1();
    void GetResume2();
    void GetXY(Resume* X, Resume* Y) const;
    void InsertResume(Resume*& x, int& e);
    void TranverseX(Resume*& x,int n);
    void TranverseY(Resume*& y,int n);
    void TakeResume(Resume*& x, Resume*& y);
};

Interview::Interview()
{
    cout << "输入简历总数:" << endl;
    cin >> length;
    OriginLength = length;
    Resume* p = head = new Resume;
    p->num = 1;
    for (int i = 1; i < length; i++)
    {
        p->next = new Resume(i + 1, p);
        p = p->next;
    }
    head->prior = p;
    p->next = head;
}

Interview::~Interview()//由于用了new额外开了空间
{
    if (length!=0&&head!=nullptr)
        delete head;
    length=0;
    OriginLength=0;
}

void Interview::TranverseX(Resume*& x,int n)
{
    for(int i=0;i<n;i++)
    {
        x=x->next;
    }
}

void Interview::TranverseY(Resume*& y,int n)
{
    for(int i=0;i<n;i++)
    {
        y=y->prior;
    }
}

void Interview::InsertResume(Resume*& x, int& e)
{
    if (x->next != x || x->prior != x)
    {
        Resume* q = new Resume;
        q->num = e + 1;
        q->next = x->next;
        q->prior = x;
        x->next->prior = q;
        x->next = q;
        length++;
        OriginLength++;
    }

}

void Interview::TakeResume(Resume*& x, Resume*& y)
{
    Resume* tempx = x, * tempy = y;
    if (x != y)
    {
        x->prior->next = x->next;
        x->next->prior = x->prior;
        y->next->prior = y->prior;
        y->prior->next = y->next;
        if(x->next==y||y->prior==x)//当X的下一个指向Y时如果不加以判断会XY先走后删除tempx时直接把Y当前所指的结点删了
        {
            x=x->next->next;
            y=y->prior->prior;
        }
        else
        {
            x = x->next;
            y = y->prior;
        }
        delete tempx;
        length--;
        delete tempy;
        length--;
    }
    else//当X，Y指向同一个结点时如果不加以判断会导致同一个结点删除两次从而产生错误
    {
        x->prior->next = x->next;
        y->next->prior = y->prior;
        x->next->prior = x->prior;
        y->prior->next = y->next;
        x = x->next;
        y = y->prior;
        delete  tempx;
        length--;
    }

}

void Interview::GetXY(Resume* X, Resume* Y) const
{
    if (X->num == Y->num)
        cout << X->num;
    else
        cout << X->num << "," << Y->num;
}

void Interview::GetResume2()
{
    int M = 0, K = 0;
    cout << "输入X所要取的简历:" << endl;
    cin >> K;
    cout << "输入Y所要取的简历:" << endl;
    cin >> M;
    if  (K<0||K>length||M<0||M>length)//异常处理
    {
        cout<<"所取简历不在范围内"<<endl;
        return;
    }
    Resume* Y = head, * X = head;
    for (int i = 1; i < length; i++)
        Y = Y->next;
    while (X->next->next!= X or X->prior->prior!= X)//介于输出格式的要求最后一组数据没有；
    {
        TranverseX(X,K-1);
        TranverseY(Y,M-1);
        GetXY(X, Y);
        cout << ";";
        InsertResume(X, OriginLength);
        TakeResume(X, Y);
    }
    GetXY(X, Y);
    cout << endl;
}

void Interview::GetResume1()
{
    int M = 0, K = 0;
    cout << "输入X所要取的简历:" << endl;
    cin >> K;
    cout << "输入Y所要取的简历:" << endl;
    cin >> M;
    if  (K<0||K>length||M<0||M>length)//异常处理
    {
        cout<<"所取简历不在范围内"<<endl;
        return;
    }
    Resume* Y = head, * X = head;
    for (int i = 1; i < length; i++)
        Y = Y->next;
    while (X->next->next!= X or X->prior->prior!= X)//介于输出格式的要求最后一组数据没有；
    {   
        TranverseX(X,K-1);
        TranverseY(Y,M-1);
        GetXY(X, Y);
        cout << ";";
        TakeResume(X, Y);
    }
    GetXY(X, Y);
    length--;
    cout << endl;
}