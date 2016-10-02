/*
Program Name: Final Project
Author's Name: Vincent Crabtree
Class Day & Time: T/Th 3:00pm
*/


#define _CRT_SECURE_NO_WARNINGS
#include "prj1.h"
#include "prj2.h"

int isSubstring(char *str1, char *str2);
void checkFirst(char *str);


struct book * processBook (struct book * head)
{
	struct book *ptr;
	int choice, ID;
	char keyword[50], name[50];
	while(1)
	{
		printf("\n\nEnter 1 to process by ID or 2 to process by keyword:\n");
		if(scanf("%d", &choice)==1)
		{
			getchar();
			if(choice!=1&&choice!=2)
			{
				printf("\n\nInvalid input, please try again:\n\n");
				continue;
			}
			else
				break;
		}
	}

	if(choice==1)
	{
		while(1)
		{
			printf("\nPlease enter the ID:\n");
			scanf("%d", &ID);
			getchar();
			ptr=findBookbyID (head,ID);
			if(ptr==NULL)
			{
				printf("Try again:\n");
				continue;
			}
			else
				break;
		}
	}
	else if(choice==2)
	{
		while(1)
		{
			printf("\nPlease enter a keyword:\n");
			gets(keyword);
			ptr=findBookbyKeywords(head,keyword);
			if(ptr==NULL)
			{
				printf("Try again:\n");
				continue;
			}
			else
				break;

		}
	}
	if(strcmp(ptr->BorrowerName,"NONE")==0)
	{
		printf("\n\nPlease enter your name:\n");
		gets(name);
		strcpy(ptr->BorrowerName,name);
		ptr->BorrowingAge=1;
		
	}
	else
	{
		printf("\nThat book is currently checked out\n\n");
	}
	displayList (head);
	return head;
}

void displayList (struct book * head)
{
	struct book *ptr;
	printf("\n");
	printf("ID:   Title:                     "
"Author:              Code:  Borrower Name:               Age:");
	printf("\n\n");
	for(ptr=head;ptr!=NULL;ptr=ptr->nextbook)
	{
		printf("%4d  %-25s  %-21s  %3d  %-30s  %-3d", ptr->ID, ptr->Title, 
			ptr->Author,ptr->SubjectCode, ptr->BorrowerName,
			ptr->BorrowingAge);
		printf("\n");
	}

	printf("\n");
	
}

struct book * findBookbyID (struct book * head, int ID)
{
	struct book *ptr;
	for(ptr=head;ptr!=NULL;ptr=ptr->nextbook)
	{
		if(ptr->ID==ID)
			return ptr;
	}
	printf("\n\nNo book could be found with that ID\n");
	return NULL;
}

struct book * findBookbyKeywords(struct book * head, char * title)
{
	struct book *ptr;
	for(ptr=head;ptr!=NULL;ptr=ptr->nextbook)
	{
		if(isSubstring(ptr->Title,title)==1)
		{
			return ptr;
		}
	}
	printf("\n\nNo book could be found with that keyword\n");
	return NULL;
}

struct book * addNewbook (struct book * head)
{
	//Declarations
	char title[50], author[50];
	int subjectCode, ID;
	struct book *newNode;
	struct book *ptr;


	//User Input
	printf("\nPlease enter the book title:\n");
	gets(title);
	checkFirst(title);
	printf("\nPlease enter the book's author:\n");
	gets(author);
	printf("\nPlease enter the subject code:\n");
	scanf("%d", &subjectCode);
	getchar();
	printf("\nPlease enter the book's four digit ID:\n");
	scanf("%d", &ID);
	getchar();

	//Assign Data
	newNode=(struct book*)malloc(sizeof(struct book));
	strcpy(newNode->Author,author);
	strcpy(newNode->Title, title);
	strcpy(newNode->BorrowerName,"NONE");
	newNode->ID=ID;
	newNode->SubjectCode=subjectCode;
	newNode->BorrowingAge=0;
	


	//Add New Book
	ptr=head;
	while(ptr->nextbook!=NULL)
	{
		ptr=ptr->nextbook;
	}
	newNode->nextbook=NULL;
	ptr->nextbook=newNode;
	

	//Sort
	head=sortByID(head);
	return head;
}

struct book *  deleteBook (struct book * head, int ID_to_go)
{
	struct book *ptr, *prev, *temp;
	ptr=head;
	prev=head;
	while(ptr!=NULL)
	{
		if(ptr->ID==ID_to_go)
		{
			if(ptr==head)
			{
				head=ptr->nextbook;
				free(ptr);
				return head;
			}
			else
			{
				temp=ptr->nextbook;
				prev->nextbook=temp;
				free(ptr);
				return head;
			}
			
			
		}
		else
		{
			prev=ptr;
			ptr=ptr->nextbook;
		}
	}
	printf("\n\nInvalid ID\n\n");
	
	return head;
}

void sendReminder (struct book * head)
{
	struct book *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->BorrowingAge==10)
		{
			printf("%s, you borrowed the book %s 10 days ago."
				" You have 4 days left to return it.\n\n", ptr->BorrowerName, ptr->Title);
		}
		ptr=ptr->nextbook;
	}
}

struct book * addReturnedBook(struct book * head, int return_book_ID)
{
	struct book *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->ID==return_book_ID)
		{
			ptr->BorrowingAge=0;
			strcpy(ptr->BorrowerName,"NONE");
			return head;
		}
		else
			ptr=ptr->nextbook;
				
	}
	printf("\n\nInvalid ID\n\n");
	return head;
}

struct book * sortByAlphabeticalOrder (struct book * head)
{
	int x, y, numNodes=0;
	struct book *ptr, *prev, *temp;
	ptr=head;
	prev=head;
	while(ptr!=NULL)
	{
		numNodes++;
		ptr=ptr->nextbook;
	}
	
	
		for(y=0;y<=(numNodes*numNodes);y++)
		{
			ptr=head;
			prev=head;
			while(ptr->nextbook!=NULL)
			{
				if(strcmp(ptr->Title,ptr->nextbook->Title)>0)
				{
					if(ptr==head)
					{
						head=ptr->nextbook;
						temp=head->nextbook;
						head->nextbook=ptr;
						ptr->nextbook=temp;
						break;
					}
					else
					{
						temp=ptr->nextbook->nextbook;
						prev->nextbook=ptr->nextbook;
						ptr->nextbook->nextbook=ptr;
						ptr->nextbook=temp;
						break;
					}
				}
				else
				{
					prev=ptr;
					ptr=ptr->nextbook;
				}
			}
		}
    return head;
}

void subjectSummary (struct book * head)
{
   int gw=0, pp=0, r=0, ss=0, l=0, ps=0, t=0, ar=0, lit=0, hg=0;
   struct book *ptr;
   ptr=head;

   while(ptr!=NULL)
   {
	   if(ptr->BorrowingAge==0)
	  {
		   if(ptr->SubjectCode==000)
			   gw++;
		   else if(ptr->SubjectCode==100)
			   pp++;
		   else if(ptr->SubjectCode==200)
			   r++;
		   else if(ptr->SubjectCode==300)
			   ss++;
		   else if(ptr->SubjectCode==400)
			   l++;
		   else if(ptr->SubjectCode==500)
			   ps++;
		   else if(ptr->SubjectCode==600)
			   t++;
		   else if(ptr->SubjectCode==700)
			   ar++;
		   else if(ptr->SubjectCode==800)
			   lit++;
		   else if(ptr->SubjectCode==900)
			   hg++;

	  }
	   ptr=ptr->nextbook;
	   
   }
	printf("\n\nBelow are the number of books cuurently available in"
		   " each subject:\n\n");
	   printf("General Works: %d\nPhilosophy and psychology: %d\n"
		   "Religion: %d\nSocial sciences: %d\nLanguage: %d\nPure Science: %d\n"
		   "Technology: %d\nArts & recreation: %d\nLiterature: %d\nHistory "
		   "& Geography: %d\n\n", gw, pp, r, ss, l, ps, t, ar, lit, hg);
}

void terminateWrite (struct book * head)
{
	FILE *tptr;
	struct book *ptr;
   tptr=fopen("Booklist.txt","w");
   ptr=head;
   while(ptr!=NULL)
   {
	   fprintf(tptr,"%4d  %-25s  %-21s  %3d  %-30s  %-3d", ptr->ID, ptr->Title, 
			ptr->Author,ptr->SubjectCode, ptr->BorrowerName,
			ptr->BorrowingAge);
	   fprintf(tptr,"\r\n");
	   ptr=ptr->nextbook;
   }
   fclose(tptr);
   freeList(head);
}

struct book *  freeList(struct book * head)
{
      struct book *ptr, *temp;
	  ptr=head;
	  while(ptr!=NULL)
	  {
		 temp=ptr;
		 ptr=ptr->nextbook;
		 free(temp);
	  }
	  return NULL;
}

int isSubstring(char *str1, char *str2)
{
	while(*str1!='\0')
	{
		if(*str1!=*str2)
		{
			str1++;
		}
		else if(*str1==*str2)
		{
			str1++;
			str2++;
			while(*str2!='\0')
			{
				if(*str1!=*str2)
					return 0;
				else if(*str1==*str2)
				{
					str1++;
					str2++;
				}
			}
			return 1;
		
		}
	}
	return 0;
}

void checkFirst(char *str)
{
	if(*str>='a'&&*str<='z')
	{
		*str-=32;
	}
	
	
}