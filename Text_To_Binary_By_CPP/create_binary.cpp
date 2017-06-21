#include<bits/stdc++.h>
#define ll long long
#define mx 10000
using namespace std;

string dic[mx];

ll total=1;


FILE *ptr_writefile;

void store(unsigned short z)
{
    fwrite(&z, sizeof(z), 1, ptr_writefile);
}

void string_op(string str)
{
    ll c=0;
    unsigned short n=0;
    for(ll i=0;i<str.size();i++)
    {
        if(str[i]=='1')
        {
            n+=powl(2,c);
        }
        c++;
        if(c==16)
        {
            store(n);
            c=0;
            n=0;
        }
    }
    if(c!=0)
    {
        store(n);
        c=0;
        n=0;
    }
}

void read_dictionary()
{
    ifstream fin;
    fin.open("Dictionary/dictionary.txt", ios::in);
    dic[32] = "00";
    dic[10] = "011000";
    string alpha,bit;
    ll x;
    while(fin >> alpha >> bit){
        total++;
        x=alpha[0]-'\0';
        dic[x]=bit;
    }
    fin.close();
}

string char_to_ascii(char ch)
{
    ll x=ch-'\0';
    return dic[x];
}

void read_input()
{
    ifstream fin;
    fin.open("Input/input.txt",ios::in);
    ptr_writefile=fopen("Binary_File/store.bin","wb");
    string str,bits="";
    while(getline(fin,str))
    {
        for(ll i=0;i<str.size();i++)
        {
            bits+=char_to_ascii(str[i]);
        }
        bits+=dic[10];
    }
    string_op(bits);
    fin.close();
}


int main()
{
    read_dictionary();
    read_input();
    return 0;
}
