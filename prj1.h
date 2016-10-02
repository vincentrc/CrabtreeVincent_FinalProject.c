#include "prj.h"

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

