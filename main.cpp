#include <iostream>
#include <stdio.h>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

 
struct stek
{
    int value;
    struct stek *next;                
};
 
void push(stek* &NEXT, const int VALUE)
{
    stek *MyStack = new stek;              
    MyStack->value = VALUE;                
    MyStack->next = NEXT;               
    NEXT = MyStack;                      
}
 
int pop(stek* &NEXT)
{
    char temp = NEXT->value;              
    stek *MyStack = NEXT;                  
                                           
    NEXT = NEXT->next;                   
    delete MyStack;                      
    return temp;                          
}
 
int main()
{
    stek *p=0;
    string s,u;
    ifstream ifs("input.txt");
    while(ifs)
        {
            ifs >> s;
        }
    cout << s << endl;
 

    int g,i,o,k=0,open=0,close=0;
    g=s.size();
    
    for (i=0; i<g;i++)
    {
        if (s[i]=='{' || s[i]=='(' || s[i]=='[')
        {open++;
            push(p,s[i]); o=i;
        }
        else 
            {
                if (s[i]=='}' || s[i]==')' || s[i]==']')
                    {close++;
                    if (s[i]==')')
                    {
                        u=pop(p);
                        if (u=="(")
                        {}
                        else { cout << "Последовательность не верна на "<< o+1<< "элементе. Скобка '" << u << "' закрывается скобкой ')'"<<endl;k++;}
                    }
                    if (s[i]=='}')
                    {
                        u=pop(p);
                        if (u=="{")
                        {}
                        else { cout << "Последовательность не верна на "<< o+1<< "элементе. Скобка '" << u << "' закрывается скобкой '}'"<<endl;k++;}
                    }
                    if (s[i]==']')
                    {
                        u=pop(p);
                        if (u=="[")
                        {}
                        else { cout << "Последовательность не верна на "<< o+1<< " элементе. Скобка '" << u << "' закрывается скобкой ']'"<<endl;k++;}
                    }
                    }
            }
    }  
    if (open==close){
    if (k==0){
    cout << "Ваша последовательность скобок идеальна!!!!";
    }
    else {cout << "На этом проверка последовательности прекращена!";}}
    else {cout << "Последовательность не полна! открывающихся скобок больше, чем закрывающихся!";}
    return 0;
}
