#include"Interview.h"
#include<iostream>

int main()
{     
    Interview a;
    cout<<"1.ÃæÊÔ1"<<endl;
    cout<<"2.ÃæÊÔ2"<<endl;
    int n;
    cin>>n;
    switch(n)
    {
        case 1:
            a.GetResume1();
            break;
        case 2:
            a.GetResume2();
            break;
    }
    system("pause");
    return 0;

}