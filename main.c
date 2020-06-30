#include "funkcje.h"

int main(int argc, char **argv)
{
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    char wejscie[50];
    char wyjscie[50];
    int a[3]={1,1,0};

    for(int i=0;i<argc-1;i++)
    {  if (moje_strcmp(argv[i],"-i")) {zamiana(wejscie,argv[i+1]);a[0]=0;}
	   if (moje_strcmp(argv[i],"-o")) {zamiana(wyjscie,argv[i+1]);a[1]=0;}
	   if (moje_strcmp(argv[i+1],"-h")) {a[2]=1;}}
    if(a[0]||a[1]||a[2])
    {printf("%s\n%s\n","Nazwa pliku wejsciowego jest podawana w linii polecen po przelaczniku -i, wyjsciowego po przelaczniku -o. Przykladowe wywolanie programu:","program.exe -o wyjscie -i wejscie");
        if(a[0]||a[1]){return 0;}}

    FILE* plik = fopen(wejscie,"r");
    if(!plik){printf("%s%s\n","Blad: Nie znaleziono pliku wejsciowego o nazwie ",wejscie);return 0;}

	slowo_type* pocz = NULL;
	slowo_type* ogon = NULL;
	slowa_type* glowa = NULL;

    char c;
	while ((c=fgetc(plik)) != EOF) {

		while ((c != ' ') && ((c) != EOF)) {
        pushback(&pocz,&ogon,c);
		c = fgetc(plik);
       }
		if (palindrom(pocz, ogon)) { dodaj(&glowa, pocz); }
		else zwolnij2(pocz);
	   pocz = ogon = NULL;
   }
    fclose(plik);

    drukarka(glowa,wyjscie);
    zwolnij1(glowa);

    return 0;
}
