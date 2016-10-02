#define  _CRT_SECURE_NO_WARNINGS

#include "prj.h"
#include "prj1.h"
#include "prj2.h"
#include <ctype.h>


void printMainMenu();

struct book * processBook (struct book * head);
void displayList (struct book * head);
struct book * findBookbyID (struct book * head, int ID);
struct book * findBookbyKeywords(struct book * head, char * keywords);
struct book * addNewbook (struct book * head);
struct book *  deleteBook (struct book * head, int ID_to_go);
void sendReminder (struct book * head);
struct book * addReturnedBook(struct book * head, int return_book_ID);
struct book * sortByAlphabeticalOrder (struct book * head);
void subjectSummary (struct book * head);
void terminateWrite (struct book * head);
struct book *  freeList(struct book * head);





int main()
{
	struct book *head=NULL;
	char buffer[75];
	char X;
	int ID_to_go;
	int return_book_ID;
	head= genNewBook (head);
	

	while(head !=NULL)
	{
	
		printMainMenu();
		printf(">>>>> Enter a command ");
		X=getchar ();
		fflush(stdin);
		X=toupper(X);
	
		switch(X){
			case 'P':
//			Process book
				displayList(head);
				head=processBook (head);
				fflush(stdin);
			break;
			case 'D':
//			Display list
				displayList(head);
				fflush(stdin);
			break;
			case 'A':
//		Add new book
				head=addNewbook (head);
				displayList(head);
				fflush(stdin);
			break;
			case 'L':
//		Delete book
				displayList(head);
				printf(">>>>> Choose a book ID\n");
				ID_to_go= atoi(gets(buffer));
				head=deleteBook (head, ID_to_go);
				displayList(head);
				fflush(stdin);
			break;
			case 'R':
//		Send reminder

				displayList(head);
				sendReminder(head);
				fflush(stdin);
			break;
			case 'B':
//		Add returned book
			
				displayList(head);
				printf(">>>>> Choose a book ID\n");
				return_book_ID= atoi(gets(buffer));
				head=addReturnedBook (head, return_book_ID);
				displayList(head);
				fflush(stdin);
			break;
			case 'T':
//		Sort list by ID
//completed by JG
				head=sortByID(head);
				displayList(head);
				fflush(stdin);
			break;
			case 'O':
//		Sort list by alphabetical order

				head=sortByAlphabeticalOrder (head);
				displayList(head);
				fflush(stdin);
			break;
			case 'J':
//		Subject summary
				displayList(head);
				subjectSummary (head);
				fflush(stdin);
			break;
			case 'Q':
//		Terminate
				terminateWrite (head);
				head = freeList(head);
				fflush(stdin);
			break;
		}

	}
	return 0;
}
void printMainMenu()
{
	printf("*******************************************************\n");
	printf("*******************************************************\n");
	printf("                Main Menu\n");
	printf("*******************************************************\n");
	printf("\tP\t\tProcess Book\n");
	printf("\tD\t\tDisplay List\n");
	printf("\tA\t\tAdd New Book\n");
	printf("\tL\t\tDelete Book\n");
	printf("\tR\t\tSend Reminder\n");
	printf("\tB\t\tAdd Returned Book\n");
	printf("\tO\t\tSort list by Alphabetical Order\n");
	printf("\tJ\t\tSubject Summary\n");
	printf("\tT\t\tSort list by ID\n");
	printf("\tQ\t\tTerminate\n");
	printf("*******************************************************\n");
	printf("*******************************************************\n");

}
