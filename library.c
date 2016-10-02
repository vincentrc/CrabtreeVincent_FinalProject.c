#define _CRT_SECURE_NO_WARNINGS
#include "prj2.h"
#include <math.h>
#include <time.h>
#include "prj1.h"

char *author_source[]={"Horace Greeley", "Sigourney Weaver", "Wendy Morse", "Cora Simmons", "Phil Donahue", "Dan Crane", "Willie Daniels", "Carl Lewis","Joe Crabb", "Buster Keaton", "Dawn Harris", "Rene Williamson", "Pat Lane", "Jose Richards", "Edward Morris", "Nathan Nevins", "John Doe", "Jane Eyre", "Wednesday Adams", "Annette Wendt", "Yannick Noah", "Christopher Columbus", "George Sims", "Anna Washington", "Marie Curie", "Rhonda White", "Susan Nash", "Mary Wright", "Lily Langely","John Thompson", "Ray Reynolds"};

char *title_source[]={ "Angel Of Eternity", "Baker Of The Stockades", "Dogs Of The Nation", "Aliens Of Perfection", "Wives And Giants", "Enemies And Companions", "Annihilation Of Gold", "Obliteration Of Water", "Signs In My Dreams", "Healing The Abyss", "Defender Of Moondust", "Creature With A UFO", "Droids Of Sunshine", "Armies Of The Moon", "Invaders And Rebels", "Creatures And Emperors", "Planet Of Aliens", "Element Of Moondust", "Hidden In Robotic Control", "Confused By The Immortals", "Freaks Of The Decade", "Children Per Continent", "Animals Of The Revolution", "Crustaceans Of The Caves", "Rats And Spices", "Men And Friends", "Cars Of The Jungle", "Working Of The Future", "Ancient New Earth", "Political Aliens"};

char *borrower_source[]={"Farhad Akbar", "Bassam Awad Alanazi", "NONE", "NONE", "Roger Cungtha Biak", "NONE", "Christian Curtis Collier", "NONE","NONE", "Tanner Durnil", "Melissa Gudeman", "NONE", "NONE", "Daniel Patrick Kobold Jr", "Travis Lee Leondis", "Cleopatrio Soares Neto", "Daniel Biaklian Sang", "NONE", "Bryant Bernard", "NONE", "Joaquin John Garcia", "NONE", "NONE", "Jacob Austin Shebesh", "D'Artagnan S. Engle", "NONE", "You Zhou", "SYAMIL ALI", "NONE","Joi Ashlyn Officer", "NONE"};

char * code_source[]={"000", "100", "200", "300", "400", "500", "600", "700","800", "900" };

char * age_source[]={ "10","4", "10", "11", "12", "10", "2", "10", "6", "10", "1", "13", "3", "4", "6", "5", "3", "4", "6", "5", "10", "10", "10", "10","10","10", "9", "2", "8", "13"};



void assignData(struct book *  V)

{
	static int done=0;
	int titleStrings, authorStrings, borrowerStrings ;
	int i,j;

	if(!done)
	{
		done =1;
		srand(time(NULL));
	}

	titleStrings=sizeof(title_source)/sizeof(char*);
    authorStrings=sizeof(author_source)/sizeof(char*);
	borrowerStrings=sizeof(borrower_source)/sizeof(char*);
	
	

	strcpy(V->Title, title_source[rand()%titleStrings]);
	strcpy(V->Author, author_source[rand()%authorStrings]);
    strcpy(V->BorrowerName, borrower_source[rand()%borrowerStrings]);
		
	V->ID = rand() % 9000 + 1000;
		if ((strcmp (V->BorrowerName, "NONE")) == 0)
		      V->BorrowingAge = 0 ; 
		
		else 
		{
			j=rand()%12;
			V->BorrowingAge = atoi (age_source[j]);
		}
		
				
		
		j=rand()%10;

		V->SubjectCode = atoi (code_source[j]);
	
		V->nextbook=NULL;


}

struct book * genNewBook(struct book * H)
{
	static int xv=1;
	int num;
	static int size= 4;
	struct book *head=NULL;
	struct book *ptr, *temp;
	int i;


	if(xv)
	{
		xv=0;
		srand(xv);
	}

	num = size + rand()%size;
	size=2;
	head=(struct book *) malloc(sizeof(struct book));
	assignData(head);
	

	ptr=head;
	for(i=1;i<num;i++)
	{
		temp=(struct book *) malloc(sizeof(struct book));
		assignData(temp);
		
		ptr->nextbook=temp;
		ptr=temp;
		
	}                  

	ptr=head;
	

	head = sortByID(head);
	
	return head;
}


struct book * sortByID (struct book * head)

{
	struct book * ptr=head;
	int num=0;
	int i;
	struct book *tmp, *stmp;

	while(ptr!=NULL)
	{
		num++;
		ptr=ptr->nextbook;
	}

	ptr=head;
	for(i=0; i<num-1; i++)
	{
		ptr=head;
		for( ; ptr->nextbook !=NULL; )
		{
			if(ptr->ID > ptr->nextbook->ID)
			{
				if(ptr==head)
				{
					head=ptr->nextbook;
					tmp=head->nextbook;
					head->nextbook=ptr;
					ptr->nextbook=tmp;

				}
				else
				{
					tmp=head;
					while(tmp->nextbook !=ptr)
					tmp=tmp->nextbook;
					stmp=ptr->nextbook->nextbook;
					tmp->nextbook=ptr->nextbook;
					ptr->nextbook->nextbook=ptr;
					ptr->nextbook=stmp;
					
				}

			}
			else
				ptr=ptr->nextbook;


		}
	}


	return head;
}


