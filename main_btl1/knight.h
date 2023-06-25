#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void read(string file_input, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue, string* event, int& count_event,string &needfile);
void solvefile(string& needfile, string& file1, string& file2, string& file3);
void readsclepius(string &file2, int* w, int& acount);
void readmerlinpack(string &file3, string* d, int& mcount);
void readmushghost(string &file1, int* m, int& count);
void asclepius(int a[], int& acount, int& remedy, int& maidenkiss, int& phoenixdown, int& meeetas);
bool prime(int a);
int fibonacci(int a);
int Max1(int a[], int& count);
int Max3(int a[], int& count);
int Min1(int a[], int& count);
int Min3(int a[], int& count);
int mountain(int a[], int& count);
void merlincheck(string a[], int& mcount, int& HP, int& meetme);
void check(int MaxHP, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue, int& tiny, int& fog, int& foglevel);
void fight(string* event, int n, int& level, int& HP, int& arthur, int& lancelot);
void fightSaman(string* event, int n, int& level, int& HP, int& tiny, int& remedy, int& arthur, int& lancelot);
void fightVajsh(string* event, int n, int& level, int& HP, int& fog, int& maidenkiss, int& foglevel, int& arthur, int& lancelot);
void mushmario(int& level, int& HP, int& phoenixdown);
void mushfibo(int& HP);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);

#endif // __KNIGHT_H__