#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define N_CARDSET	1
#define N_CARD	52
#define N_DOLLAR	50

#define N_MAX_CARDNUM
#define N_MAX_USER
#define N_MAX_CARDHOLD
#define N_MAX_GO
#define N_MAX_BET

#define N_MIN_ENDCARD

//card tray object
int CardTray[N_CARDSET*N_CARD];
int cardIndex=0;

//player info
int dollar[N_MAX_USER];
int n_user;

//yard info
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];
int cardSum[N_MAX_USER];
int bet[N_MAX_USER];
int gameEnd=0;

//card array controllers

//mix the card sets and put in the tray
int mixCardTray(int index){
	int Card[52]={1,2,3,4,5,6,7,8,9,10,10,10,10,
					1,2,3,4,5,6,7,8,9,10,10,10,10,
					1,2,3,4,5,6,7,8,9,10,10,10,10,
					1,2,3,4,5,6,7,8,9,10,10,10,10};
	return Card[index];
}
				
//playing game fuctions
//player setting
int configUser(){
	int user=0;
	printf("���� ���� �ο�:");
	scanf("%d",&user, sizeof(user));
	while (1){
		if (user>5 || user<1)
		{
			printf("���� �ο��� 1~5�� �̾���մϴ�. ");
			scan("%d", &user, sizeof(user)); 
		}
	else {
		break;
	}	
} 
return user;	
}

//offering initial 2 cards
void offerCards(void) {
	int i;
	//1. give two cards for each player
	for(i=0; i<n_user; i++)
	{
		cardhold[i][0]= pullCard();
		cardhold[i][1]= pullCard(); 
	}
	//2.give two cards for the dealer
	cardhold[n_user][0] = pullCard();
	cardhold[n_user][1] =pullCard();
	
	return;
}

void printUSerCardStatus(int user, int cardcnt){
	int i;
	
	printf(" -> card:");
	for(i=0; i<cardcnt; i++)
		printCard(cardhold[user][i]);
	scanf("\t:::");
}

int main(int argc, char *argv[]) {
	int roundIndex=0;
	int MAX_USER;
	int i;
	int j;
	
	srand((unsigned)time(NULL));
	
	//set the number of plyers
	MAX_USER = configUser();
	
	printf("�����ο�: %d\n", MAX_USER);
	int *pUserNum;
	
	for(i=0; i<MAX_USER; i++)
	{
		pUserNum[i]=0;
	} 
	
	//Game initialization
	//1. player's dollar
	int saveNum[52];
	int count=0;
	//2.card tray
	int isSame=0;
	int gameCount=1;
	int endCount=0;
	
	srand((unsigned)time(NULL));
	while(1){
		isSame =0;
		
		printf("%d����\n", gameCount);
		
		for(j=0;j<MAX_USER;j++){
			isSame=0;
			
			int temp=rand()%52;
			for(i=0;i<count;i++)
			{
				if (temp ==saveNum[i])
				{
					isSame=1;
					j--;
					continue;
				}
			}
			if (isSame ==0)
			{
				printf("%d���� ����\n",j+1);
				printf("ī�带 �̽��ϴ�\n");
				if(gameCount >1)
				{
					printf("�����ðڽ��ϱ�?(y/n)");
					char c;
					c=getchar();
					scan("%c",&c,sizeof(c));
					if(c!='y')
					{
						endCount++;
						continue;
					}
				}
				
				saveNum[count]= temp;
				int num= mixCardTray(temp);
				
				if(num==1)
				{
					int a=0;
					printf("A�� �̾Ҿ��. 1�Ǵ� 11�߿� ��������. (1/11�߿� �ϳ� �Է�)\n");
					scanf("%d",&a,sizeof(a));
					while (a!=1 &&a!=11)
					{
						printf("1/11���� �ϳ� �Է�\n");
						scanf("%d",&a, sizeof(a));
					}
					printf("����ī��=%d, ����:%d\n",num, a);
					pUserNum[j]=pUserNum[j]+a;
					printf("����:%d\n",pUserNum[j]);
				}
				else
				{
					printf("����ī��=%d\n",num);
					pUserNum[j]=pUserNum[j]+num; 
					printf("����ī��:%d, ����:%d\n",num, pUserNum[j]);
					count++; 
				}
			}
		}
printf("\n---------------------------------------\n");

	gameCount ++;
	
	if (endCount== MAX_USER)
		break;
	endCount=0;	
}
printf("game count: %d\n", gameCount);
printf("�� ��������\n");
	for(i=0;i<MAX_USER;i++)
	{
		printf("%d��° ��������:%d\n", i+1, pUserNum[i]);
	}
	
	printf("--------------------------------result\n");	
	int disNum[5]={0};
	int subCount= 0;
	int idx =0;
	int min=0;
	bool is winner = false;
	for(i=0; i<MAX_USER; i++)
	{ 
		if (pUserNum[i]>21)
		{
			printf("%d��° ���� ������ Ż��\n",i+1);
		}
		else if (pUserNum[i] <21)
		{
			disNum[i]=21- pUserNum[i];
		}
	}
	
	min=disNum[0];
	
	for(i=0; i<MAX_USER; i++)
	{
		if (disNum[i]>0)
		{
			min=disNum[i];
			idx=i;
		}
	}
}
if (!isWinner)
{
	printf("%d��°���� ����\n", idx+1);
}
 
//Game Start -------
//do {

//	betDollar();
// 	offerCards(); //1. give cardsj to all the players

// printCardInitialStatus();
//	printf("\n-----------------------GAME start--------------------\n");

//	//each player's turn
//	for ()// each player
//	{ 
//		while () //do until the player dies or player says stop
//		{
//			//print current card status printUserCardStatus();
//		//check the card status ::: calcStepResult()
//		//GO? STOP? ::: getAction()
//		//check if the turn ends or not
//		}
//	}
 
//	//result
// checkResult();
//} while (gameEnd==0);

//checkWinner();
free(pUserNum);
system("pause");	
return 0;
}