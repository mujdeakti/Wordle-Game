#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>//renklendirme için gerekli olan küütphane 
#include<time.h>
#include<math.h>


char words[][5]={"BADGE","HOMER","TRAIN","HAIRY","STORY","TRASH","HAILE","KYLIE","ROUSE","KENNY"};
char word[5], guessedWord[5],knownLetters[5],table[6][5];
int indis,idx,conslusion;

 void wordDerivation()
 { 
   srand(time(0));
   indis=rand()%10;
   int i=0;
   while(i<5)
   {
    word[i]=words[indis][i];
    i++;
   }
   idx=0;
   conslusion=0;
    }
 void colorBlue()
 {
  HANDLE renk=GetStdHandle( STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(renk,FOREGROUND_BLUE);
 }
 void colorNormal()
 {
    HANDLE renk=GetStdHandle( STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(renk,FOREGROUND_INTENSITY);
 }
 int fillInTable()
 {
    int i, conslusion=1;//kullanıcıdan alınan tahmin uretilen kelimenin bes harfine de esitse 
  for(i=0;i<5;i++)
  {
    if(word[i]!=guessedWord[i])
    {
        conslusion=0;
        knownLetters[i]='-';
    }
    else
    knownLetters[i]=guessedWord[i];
    table[idx][i]=guessedWord[i];//tablodaki idx in i . değerine kullanıcıdan aldığım i. degeri atadım
  }
  idx++;
  return conslusion;
 }
 void printTable()
 {
    int i,j;
printf("\n\tWORLDE TR\n");
    for(i=0;i<6;i++)
    {
        printf("\t");
        for(j=0;j<5;j++)
        {
            if(i==idx-1)
            {
                if(word[j]==guessedWord[j])
                {
                    printf("[");
                    colorBlue();
                    printf("%c",table[i][j]);
                    colorNormal();
                    printf("]");
                }
                else
                printf("[%c]",table[i][j]);
            }
            else
            printf("[%c]",table[i][j]);
            colorNormal();
        }
        printf("\n");
    }
    colorBlue();
    colorNormal();
 }

int main()
{    
    int counter=0,m,conslusion;
    wordDerivation();
    printTable();
    while(counter<6)
    {
       printf("Tahmininizi Giriniz:",(counter+1));
       scanf("%5s",guessedWord);
       strupr(guessedWord);
       m=strlen(guessedWord);
       if(m!=5)
       {
        printf("Girdiğiniz kelime 5 harften fazla olamaz!");
        continue;
       }
       conslusion=fillInTable();
       printTable();
       if(conslusion==1)
       break;
       counter++;
    }
    if(conslusion==1)
     {
        printf("Your Win..Word:\n");
       colorBlue();
        printf("%s",word); 
        colorNormal();
    }
    else{
       printf("Your Lose...Word:\n");
        colorBlue();
        printf("%s",word); 
        colorNormal();
    }
    return 0;
}