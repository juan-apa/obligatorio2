#include "String.h"

void String_crear(String &s)
{
    s=new char[1];
    s[0]='\0';
}

void String_dest(String &s)
{
    delete[] s;
    s=NULL;
}

int String_lar(String s)
{
    int i=0;
    while(s[i]!='\0')
    {
        i++;
    }
    return i;
}

void String_cop(String &s1, String s2)
{
	int i=0;
	int largo= String_lar(s2)+1;//por el \0
	String_dest(s1);
    s1= new char[largo];
    while(s2[i]!='\0')
    {
        s1[i]=s2[i];
        i++;
	}
	s1[i]='\0';
}

void String_cargar(String &s)//ASUMO QUE EL STRING YA VIENE CREADO.!
{
    char *saux = new char[MAX];
    char aux;
    int i=0;
    scanf("%c", &aux);
    while(aux!='\n' && i<MAX-1)
    {
        saux[i]=aux;
        scanf("%c", &aux);
        i++;
    }
    saux[i]='\0';
    String_cop(s, saux);
    String_dest(saux);
}

void String_mostrar(String s)
{
    for(int i=0; i<String_lar(s); i++)
    {
        printf("%c", s[i]);
    }
}

void String_con(String &s1, String s2)//PONE S2 AL FINAL DE S1. S2 NO SE DESTRUYE.
{
    char* saux= new char[MAX];
    int i=0, j=0;
    for(i=0; i<String_lar(s1); i++)
    {
        saux[i]=s1[i];
    }
    while(i<MAX-1 && s2[j]!='\0')
    {
        saux[i]=s2[j];
        i++;
        j++;
    }
    saux[i]='\0';
    String_cop(s1, saux);
    String_dest(saux);
}

void String_swp(String &s1, String &s2)
{
    /*if(strDin_lar(s1)>strDin_lar(s2))
    {
        String saux= new char[strDin_lar(s1)];
    }
    else
    {
        String saux= new char[strDin_lar(s2)];
    }*/
    String saux;
    String_crear(saux);
    String_cop(saux, s1);
    String_cop(s1, s2);
    String_cop(s2, saux);
    String_dest(saux);
}

bool String_men(String s1, String s2)
{
    int i=0;
    bool menor=false, caso=false;
    while(s1[i]!='\0' && s2[i]!='\0' && caso==false)
    {
        if(s1[i]!=s2[i])
        {
            caso=true;
        }
        i++;
    }
    if(caso==true)
    {
        if(s1[i-1]<s2[i-1])
        {
            menor=true; //s1<s2
        }
        else
        {
            menor=false; //s1>s2
        }
    }
    if(caso==false)
    {
        if(s1[i]=='\0' && s2[i]!='\0') menor=true;
        if(s1[i]!='\0' && s2[i]=='\0') menor=false;
        //if(texto0[i]=='\0' && texto1[i]=='\0') caso=3;
    }
    return menor;
}

bool String_eq(String s1, String s2)
{
    int i=0;
    bool igual=true;
    if(String_lar(s1)==String_lar(s2))
    {
        while(s1[i]!='\0' && igual==true)
        {
            if(s1[i]!=s2[i])
                igual=false;
            i++;
        }
    }
    else
        igual=false;
    return igual;
}
