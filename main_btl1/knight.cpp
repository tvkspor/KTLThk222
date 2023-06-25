#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}
void read(string file_input, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue, string* event, int& count_event, string &needfile)
{
    string* data1 = new string[1000];
    int * data2 = new int[1000];
    ifstream f(file_input);
    string x;
    int i = 0;  
    while (f>>x)
    {       
            data1[i] = x;
            i++;
    }
    needfile = data1[i-1];
    for (int j = 0; j < 5; j++)
    {
                int tran = 0;
                tran = stoi(data1[j]);
                data2[j] = tran;
    }
    count_event = i-6;
    /*for (int t = 0; t < i; t++)
    {
        cout << data1[t] << " ";
    }
    cout << endl;*/
    HP = data2[0]; level = data2[1]; remedy = data2[2]; maidenkiss = data2[3]; phoenixdown = data2[4];
    for (int n = 0; n < i-6; n++)
    {
        event[n] = data1[n + 5];
    }
    f.close();
}
void solvefile(string& needfile,string &file1, string &file2 ,string &file3)
{
    string s1 = needfile;
    file1 = s1.erase(s1.find(","));
    string s3 = needfile;
    string s4 = s3.erase(0, (file1.length() + 1));
    file2 = s4.erase(s4.find(","));
    string s6 = needfile;
    file3 = s6.erase(0, (file1.length() + file2.length() + 2));
}
void readsclepius(string &file2, int* w,int& acount)
{
    int* data1 = new int[1000];
    ifstream f(file2);
    int x;
    int i = 0;
    while (f >> x)
    {
        data1[i] = x;
        i++;
    }
    acount = i;
    for (int n = 0; n < i; n++)
    {
        w[n] = data1[n];
    }
    f.close();
}
void readmerlinpack(string &file3, string*d, int& mcount)
{
    string* data1 = new string[1000];
    ifstream f(file3);
    f >> mcount;
    string line;
    getline(f, line);
    for (int i = 0; i < mcount; i++)
    {
        getline(f, line);
        d[i] = line;
    }
    /*for (int i = 0; i < mcount; i++)
    {
        cout << d[i] << endl;
    }*/
    f.close();
}
void readmushghost(string &file1, int*m, int& count)
{  
    string* data1 = new string[1000];
    ifstream f(file1);
    string x;
    int i = 0;
    while (f >> x)
    {
        data1[i] = x;
        i++;
        
    }
    m[0] = stoi(data1[0]);
    string s1 = data1[1];
    int n = 1;
    while (s1.find(",") != string::npos)
    {
        string s3 = s1;
        string s2 = s3.erase(s3.find(","));
        s1.erase(0, s2.length() + 1);
        m[n] = stoi(s2);
        n++;
    }
    m[n] = stoi(s1);
    count = n+1;
   /* for (int j = 0; j <= n; j++)
    {
        cout << m[j]<<",";
    }*/
    f.close();
}
void asclepius(int a[], int& acount, int& remedy, int& maidenkiss, int& phoenixdown,int&meeetas)
{
    int d = 1;
    for (int i = 1; i <= a[0]; i++)
    { 
        int c = 0;
        for (int j = 1; j <= a[1]; j++)
        {
            if (a[j + d] == 16 && c < 3) { remedy++; c++; }
            if (a[j + d] == 17 && c < 3) { maidenkiss++; c++; }
            if (a[j + d] == 18 && c < 3) { phoenixdown++; c++; }
        }
        d = d + a[1];
    }
    meeetas++;
}

bool prime(int a)
{
    if (a < 2) return false;
    if (a == 2) return true;
    for (int i = 2; i < a; i++) 
    {
        if (a % i == 0)
        return false;
    }
    return true;
}
int fibonacci(int a)
{
    int f0 = 1;
    int f1 = 1;
    int fn = 2; 
    if (a == 1||a==2) return 1;
    while(fn<a)
    {
            f0 = f1;
            f1 = fn;
            fn = f0 + f1;
    }
    return f1;
}
int Max1(int a[], int &count)
{   
    int csmax=1;
    int max = a[1];
    for (int i = 2; i < count; i++)
        if (max <= a[i])
        {
            max = a[i]; csmax = i;
        }
    return csmax-1;
}
int Max3(int a[], int& count)
{
    int csmax = 1;
    int max = a[1];
    for (int i = 2; i < count; i++)
        if (max < a[i])
        {
            max = a[i]; csmax = i;
        }
    return csmax - 1;
}
int Min1(int a[], int& count)
{
    int csmin = 1;
    int min = a[1];
    for (int i = 2; i < count; i++)
        if (min >= a[i])
        {
            min = a[i]; csmin = i;
        }
    return csmin-1;
}
int Min3(int a[], int& count)
{
    int csmin = 1;
    int min = a[1];
    for (int i = 2; i < count; i++)
        if (min > a[i])
        {
            min = a[i]; csmin = i;
        }
    return csmin - 1;
}
int mountain(int a[], int& count)
{   
    int o, p;
    if (a[0] == 1 )
    {
        return (a[1] + 0);
    }
    if (a[1] - a[2] > 0)
    {
        for (int i = 1; i < count-1; i++)
        {
            if (a[i] - a[i + 1] <= 0) return -5;
        }
        return (a[1] + 0);
    }
    if (a[1] - a[2] < 0)
    {   
        if (count == 3)  return(a[2] + 1);
        int s = 0;
        for (int i = 2; i < count - 1; i++)
        {
            if (a[i] == a[i + 1]) return -5;
            if ((a[i - 1] - a[i]) * (a[i] - a[i + 1]) < 0)
            {
                o = a[i]; p = i-1; s++;
            }
        }
            if (s == 1) return (o + p);
            if (s == 0) return (a[count - 1] + count - 2);
            else return -5;
    }
    return -5;
}
void merlincheck(string a[], int& mcount, int&HP, int&meetme)
{    
    for (int i = 0; i < mcount; i++)
    {   
        string s = a[i];
        int m1=0, e1=0, r1=0, l1=0, o1=0, n1=0;
        if ((0 <= a[i].find("merlin") && a[i].find("merlin") < a[i].length()) || (0 <= a[i].find("Merlin") && a[i].find("Merlin") < a[i].length())) { HP = HP + 3; }
        else
        {
            for (int j = 0; j < a[i].length(); j++)
            {
                if (s[j] == 'M' || s[j] == 'm') m1++;
                if (s[j] == 'E' || s[j] == 'e') e1++;
                if (s[j] == 'R' || s[j] == 'r') r1++;
                if (s[j] == 'L' || s[j] == 'l') l1++;
                if (s[j] == 'I' || s[j] == 'i') o1++;
                if (s[j] == 'N' || s[j] == 'n') n1++;
            }
            if (m1 >= 1 && e1 >= 1 && r1 >= 1 && l1 >= 1 && o1 >= 1 && n1 >= 1) {HP = HP + 2; }
        }
    }
    meetme++;
}
void check(int MaxHP, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int &rescue, int&tiny, int&fog,int&foglevel)
{ 
    if (HP <= 0 && phoenixdown >= 1) 
    {
        HP = MaxHP; phoenixdown = phoenixdown - 1; tiny = -1; if (fog > 0) { level = foglevel; } fog = -1;
    }
    if (fog > 0 && maidenkiss >= 1) { level = foglevel; fog = -1; maidenkiss = maidenkiss - 1; }
    if (tiny > 0 && remedy >= 1) { HP = HP * 5; tiny = -1; remedy = remedy - 1; }
    if (HP <= 0 && phoenixdown == 0){ rescue = 0;}
    if (HP > MaxHP) { HP = MaxHP; }
    if (level > 10) { level = 10; }
    if (remedy > 99) { remedy = 99; }
    if (maidenkiss > 99) { maidenkiss = 99; }
    if (phoenixdown > 99) { phoenixdown = 99; }
}

void fight(string*event,int n,int &level,int &HP,int&arthur,int&lancelot)
{   
    
    float a = 0;
    if (event[n] == "1") a = 1;
    else if (event[n] == "2") a = 1.5;
    else if (event[n] == "3") a = 4.5;
    else if (event[n] == "4") a = 7.5;
    else if (event[n] == "5") a = 9.5;
    int b = (n+1) % 10;
    int level0 = (n+1) > 6 ? (b > 5 ? b : 5) : b;
    if (level > level0 || arthur==1||lancelot==1) { level++; }
    else if (level < level0) { HP = HP - a * level0 * 10; }
}
void fightSaman (string* event, int n, int& level, int& HP,int &tiny,int& remedy,int &arthur,int &lancelot)
{   
    int b = (n + 1) % 10;
    int level0 = (n + 1) > 6 ? (b > 5 ? b : 5) : b;
    if (level > level0||arthur==1||lancelot==1) { level=level+2;}
    else if (level < level0 && remedy >= 1) { remedy--; }
    else if (level < level0 && remedy == 0) { if (HP < 5) HP = 1; else HP = HP / 5; tiny = 4; }
}
void fightVajsh(string* event, int n, int& level, int& HP, int& fog, int& maidenkiss,int& foglevel,int &arthur,int &lancelot)
{
    int b = (n + 1) % 10;
    int level0 = (n + 1) > 6 ? (b > 5 ? b : 5) : b;
    if (level > level0||arthur==1||lancelot==1) { level = level + 2; }
    else if (level < level0 && maidenkiss >= 1) { maidenkiss--; }
    else if (level < level0 && maidenkiss == 0) { foglevel = level;level = 1; fog = 4; }
}
void mushmario(int& level, int& HP, int& phoenixdown)
{
    int n1 = ((level + phoenixdown) % 5 + 1) * 3;
    int s1=0;
    for (int i = 99; i >= 0; i = i - 2)
    {
        if (n1 > 0)
        {
            s1 = s1 + i; n1--;
        }
        else break;
    }
    HP = HP + (s1 % 100);
    int t2 = HP + 1;
    while (prime(t2)==0) 
    { 
        t2++; 
    }
    HP = t2; 
}
void mushfibo(int& HP)
{
    HP = fibonacci(HP);
}
void adventureToKoopa(string file_input, int& HP, int& level, int& remedy, int& maidenkiss,
    int& phoenixdown, int& rescue)
{
    string needfile;
    string file1, file2, file3;
    string* event;
    event = new string[1000];
    int* m;
    m = new int[1000];
    int* l;
    l = new int[1000];
    string* d;
    d = new string[1000];
    int* w;
    w = new int[1000];
    rescue = -1;
    int count;
    int count_event;
    int mcount;
    int acount;
    int tiny=-1;
    int fog = -1;
    int foglevel = 0;
    int meetas = 0;
    int meetme = 0;
    int arthur = 0;
    int lancelot = 0;
    read(file_input,HP,level,remedy,maidenkiss,phoenixdown,rescue,event,count_event,needfile);
    solvefile(needfile, file1, file2, file3);
    int MaxHP = HP;
    if (MaxHP == 999) { arthur = 1; }
    if (prime(MaxHP)) { lancelot = 1; }
    for (int n = 0; n < count_event; n++)
    { 
        if (event[n] == "0") { rescue = 1; display(HP, level, remedy, maidenkiss, phoenixdown, rescue); break; }
        if (event[n] == "1" || event[n] == "2" || event[n] == "3" || event[n] == "4" || event[n] == "5") 
        {  
            fight(event, n, level, HP,arthur,lancelot);
        }
        if (event[n] == "6" && tiny<=0 && fog<=0) 
        { 
            fightSaman(event, n, level, HP, tiny, remedy,arthur,lancelot); 
        }
        if (event[n] == "7" && fog <= 0 && tiny <= 0)
        {
            fightVajsh(event, n, level, HP, fog, maidenkiss,foglevel,arthur,lancelot);
        }
        if (event[n] == "11")
        {
            mushmario(level, HP, phoenixdown);
        }  
        if (event[n] == "12")
        {
            mushfibo(HP);
        }
        if (event[n].length() > 2)
        {
            readmushghost(file1,m,count);
            for (int i = 2; i < event[n].length(); i++)
            { 
                if (HP <= 0 && phoenixdown >= 1) { HP = MaxHP; phoenixdown--;}
                if (HP <= 0 && phoenixdown == 0) { rescue = 0; break; }
                switch (event[n][i]) 
                {
          case 49:
              HP = HP - (Max1(m, count) + Min1(m, count));
              if (HP > MaxHP)  HP = MaxHP;
               break;
          case 50:
              HP = HP- mountain(m, count);
              if (HP > MaxHP)  HP = MaxHP;
              break;
          case 51:
              for (int j = 1; j < count; j++)
              {
                  if (m[j] < 0) { l[j] = (17 * -m[j] + 9) % 257; }
                  if (m[j] >= 0) { l[j] = (17 * m[j] + 9) % 257; }
              }
              HP = HP - (Max3(l, count) + Min3(l, count));
              if (HP > MaxHP)  HP = MaxHP;
              break;
          default:
              for (int i = 1; i <count; i++)
              {
                  if (m[i] < 0) { l[i] = (17 * -m[i] + 9) % 257; }
                  if (m[i] >= 0) { l[i] = (17 * m[i] + 9) % 257; }
              }
              if (count == 2) HP = HP + 12;
              if (count == 3) 
              {
                  if (l[1] > l[2]) HP = HP - l[2] - 1;
                  else if (l[1] < l[2]) HP = HP - l[1];
                  else HP = HP + 12;
              }
              if (count>3)
                {
                  if (l[1] == l[2] && l[2] == l[3]) HP = HP + 12;
                  else if (l[1] == l[2]) 
                  {
                      if (l[1] > l[3]) { HP = HP - l[3] - 2; }
                      else HP = HP - l[1];
                  }
                  else if (l[1] == l[3])
                  {
                      if (l[1] > l[2]) HP = HP - l[2] - 1;
                      else HP = HP - l[1];
                  }
                  else if (l[3] == l[2])
                  {
                      if (l[1] > l[2]) HP = HP - l[2] - 1;
                      else HP = HP - l[1];
                  }
                  else
                  {
                      int n, k;
                      if (l[1] > l[2]) { n = 1; k = 2; }
                      else { n = 2; k = 1; }
                      if (l[n] < l[3]) { HP = HP - l[n] - (n - 1); }
                      else
                      {
                          if (l[3] > l[k]) { HP = HP - l[3] - 2; }
                          else { HP = HP - l[k] - (k - 1); }
                      }
                  }
                }
              if (HP > MaxHP)  HP = MaxHP;
               }
            }
        }
        if (event[n] == "15")
        {
            remedy++;
        }
        if (event[n] == "16")
        {
            maidenkiss++;
        }
        if (event[n] == "17")
        {
            phoenixdown++;
        }
        if (event[n] == "18" && meetme==0 )
        {
            readmerlinpack(file3, d, mcount);
            merlincheck(d, mcount,HP,meetme);
        }
        if (event[n] == "19" && meetas==0)
        {
            readsclepius(file2, w,acount);
            asclepius(w, acount, remedy,maidenkiss, phoenixdown,meetas);

        }
        if (event[n] == "99")
        {
            if (arthur == 1 || (lancelot == 1 && level >= 8) || level == 10) { level=10; }
            else { rescue = 0; display(HP, level, remedy, maidenkiss, phoenixdown, rescue); break; }
        }
        check(MaxHP, HP, level, remedy, maidenkiss, phoenixdown,rescue,tiny,fog,foglevel);
        if (rescue == 0) { display(HP, level, remedy, maidenkiss, phoenixdown, rescue); break; }
        tiny--;
        fog--;
        if (tiny == 0) { HP = HP * 5; if (HP > MaxHP) HP = MaxHP; }
        if (fog == 0) { level = foglevel; }
        if (n==(count_event-1) && rescue == -1) { rescue = 1; display(HP, level, remedy, maidenkiss, phoenixdown, rescue); }
        else { display(HP, level, remedy, maidenkiss, phoenixdown, rescue); }        
    } 
}