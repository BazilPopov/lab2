#include <iostream>
#include <stdio.h>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

 
struct stek
{
    int value;
    struct stek *next;                      // указатель на следующий элемент списка (стека)
};
 
void push(stek* &NEXT, const int VALUE)
{
    stek *MyStack = new stek;               // объявляем новую динамическую переменную типа stek
    MyStack->value = VALUE;                 // записываем значение, которое помещается в стек
    MyStack->next = NEXT;                   // связываем новый элемент стека с предыдущим
    NEXT = MyStack;                         // новый элемент стека становится его вершиной
}
 
int pop(stek* &NEXT)
{
    char temp = NEXT->value;                 // извлекаем в переменную temp значение в вершине стека
    stek *MyStack = NEXT;                   // запоминаем указатель на вершину стека, чтобы затем
                                            // освободить выделенную под него память
    NEXT = NEXT->next;                      // вершиной становится предшествующий top элемент
    delete MyStack;                         // освобождаем память, тем самым удалили вершину
    return temp;                            // возвращаем значение, которое было в вершине
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