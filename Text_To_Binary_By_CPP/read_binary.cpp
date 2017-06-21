#include <bits/stdc++.h>
#define ll long long
#define mx 10000
using namespace std;

FILE *ptr_readfile;

string dic[mx];

ll total=1;

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

string binary_format(unsigned short z)
{
    string str="";
    ll c=0;
    while(z)
    {
        c++;
        if(z%2==0)
            str+="0";
        else
            str+="1";
        z/=2;
    }
    for(ll i=c;i<16;i++)
        str+="0";
    return str;
}

void convert_original_msg(string str)
{
    freopen("Output/output.txt","w",stdout);
    string txt="";
    str+="0";
    char ch;
    for(ll i=0;i<str.size();i++)
    {
        txt+=str[i];
        if(txt=="00" && str[i+1]=='0')
        {

        }
        else
        {
            for(ll j=0;j<=255;j++)
            {
                if(dic[j]!="" && txt==dic[j])
                {
                    if(j==10)
                        cout<<endl;
                    else
                    {
                        ch=j+'\0';
                        cout<<ch;
                    }
                    txt="";
                }
            }
        }
    }
}

void read_binary()
{
    string bits="";
    ptr_readfile=fopen("Binary_File/store.bin","rb");
    if (!ptr_readfile)
    {
        printf("Unable to open file!");
    }
    else
    {
        unsigned short z;
        while(fread(&z,sizeof(z),1,ptr_readfile)==1)
        {
            bits+=binary_format(z);
        }
    }
    convert_original_msg(bits);
}


int main()
{
    read_dictionary();
    read_binary();

    return 0;
}
