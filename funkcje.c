#include "funkcje.h"

void pushback(slowo_type** head, slowo_type** tail, char literka)
{
	if (!*head)
	{
		*tail = *head = (slowo_type*)malloc(sizeof(slowo_type));
		(*head)->litera = literka;
		(*head)->pNext = NULL;
	}
	else {
		slowo_type* current = (slowo_type*)malloc(sizeof(slowo_type));
		current->litera = literka;
		current->pPrev = *tail;
		current->pNext = NULL;
		(*tail) = (*tail)->pNext = current;
	}
}

int porownanie(slowo_type *head1, slowo_type *head2)
{
    while(head2)
    {
        if(!head1) return 1;
        else if (head1->litera!=head2->litera)
        {return head1->litera<head2->litera ? 1 : 0;}
		head2=head2->pNext;
        head1=head1->pNext;
    } return 0;
}

void dodaj(slowa_type **glowa, slowo_type* wyrazik)
{
	if (!*glowa || porownanie(wyrazik, (*glowa)->wyraz))
	{
		slowa_type* tmp = *glowa;
		*glowa = (slowa_type*)malloc(sizeof(slowa_type));
		(*glowa)->wyraz = wyrazik;
		(*glowa)->pNext = tmp;
	}
	else
	{
		slowa_type* current = *glowa;
		while (current->pNext != NULL && !porownanie(wyrazik, (current)->pNext->wyraz)) { current = current->pNext; }
		slowa_type* tmp = current->pNext;
		current->pNext = (slowa_type*)malloc(sizeof(slowa_type));
		current->pNext->wyraz = wyrazik;
		current->pNext->pNext = tmp;
		return;
	}
}

void drukarka(slowa_type *glowa, char* output)
{
    FILE* fp=fopen(output,"w");
    while(glowa)
    {
        slowo_type *current=glowa->wyraz;
        while(current)
        {
          fprintf(fp,"%c", (current->litera));
		  current = current->pNext;
        }
        fprintf(fp,"%c",' ');
		glowa = glowa->pNext;
    }
    fclose(fp);
    return;
}


int palindrom(slowo_type *glowa, slowo_type *ogon)
{
   while(glowa){
       if(glowa->litera!=ogon->litera){
        return 0;} ogon=ogon->pPrev;
	   glowa = glowa->pNext;
    }
    return 1;
}

void zamiana(char* destination, const char* source)
{
	while ((*destination++ = *source++) != '\0');
}

int moje_strcmp(char string1[], char string2[] )
{
    for (int i = 0;;i++)
    {
        if (string1[i]!=string2[i]) {return 0;}
        if (string1[i]=='\0') {return 1;}
    }
}

void zwolnij1(slowa_type* glowa) {
	slowa_type *p;
	while (glowa) {
		zwolnij2(glowa->wyraz);
		p = glowa->pNext;
		free(glowa);
		glowa = p;
	}
}

void zwolnij2(slowo_type *glowa)
{
	slowo_type *p;
	while (glowa) {
		p = glowa->pNext;
		free(glowa);
		glowa = p;
	}
}
