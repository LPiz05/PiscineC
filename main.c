#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element element;
typedef struct Attr Attr;

struct element{
    char* open; // balise ouvrante 
    char* content;
    char* close; // balise de fermeture
    int* parent; // adresse de la structure du parent ( question 3)
    int* attributsAmount; //taille du tableau
    struct Attr ** attributs;
};

struct Attr {
    char * name;
    char * value;
} ;

void fermetureFichier(FILE*);
void baliseOuvrante(FILE * ,element*); // lecture de la balise ouvrante
void baliseFermante(FILE * ,element*);
void lecturecontent(FILE *, element*); // lecture du content entre 2 balises
void decoupeAttribut(FILE *,char*, element*,int ); // découper le nom attribut et valeur attribut
void lectureFichier(FILE* , element*); // fonction qui regroupe toute les autres f° de lecture
void AfficherFichier(element*); 

void fermetureFichier(FILE* f){
    fclose(f);
    printf(" \n Fermeture du fichier!\n");
}

void baliseOuvrante(FILE *f, element *tab){ // detection de la balise ouvrante et stockage du nom de la balise
    char a = (char)fgetc(f);
    char nomBalise[50];
    int compteur = 0;
    int posedeAtt=0; // 0 si faux, 1 si vrai
    while ( a != '<'){ // recherche balise d'ouverture
        a = (char)fgetc(f);
    }
    char c = (char)fgetc(f);
    while ( c != '>'){
        nomBalise[compteur]=c;
        compteur++;
        c = (char)fgetc(f);

        if(c==' ' && posedeAtt == 0)
        {
            posedeAtt=1;
            nomBalise[compteur]='\0';
        }
        if(posedeAtt==1)
        {
            tab->open = malloc(sizeof(char )* strlen(nomBalise));
            strcpy(tab->open ,nomBalise);
            compteur = 0;
            posedeAtt = 2;
        }
    }
    nomBalise[compteur] = '\0';
     if( posedeAtt==0){
         tab->open = malloc(sizeof(char )* strlen(nomBalise));
         strcpy(tab->open ,nomBalise);
     }else{
         char * tempo = &nomBalise;
         //decoupeAttribut(f,tempo, tab, compteur);
     }
}

void lecturecontent(FILE *f, element *tab){ // lecture des donnée jusque detection de la balise de fermeture ( </ )
    char a = (char)fgetc(f);
    char content[30]; // variable temporaire de stockage d'information
    int i =0;
    while ( a != '<'){
       /* if(i==0 && content[i]== ' ')
        {
            a = (char)fgetc(f);

        }*/
        a = (char)fgetc(f);
        content[i] = a;

        i++;
    }
    content[i-2]='\0';
    tab->content = malloc(sizeof(char )* strlen(content));
    strcpy(tab->content ,content);

}

void decoupeAttribut(FILE *f, char *nomBalise ,element *tab, int longeur) { // NE FONCTIONNE PAS
    char nomAtt[30];
    char valeurAtt[30];
    int compteur = 0;
    int nombreAtt = 0;
    Attr tempo[10];
    int i = 0;
    int fin = 0;
    while (fin == 0|| i<longeur){
        while (nomBalise[i] != '=') {
            if (nomBalise[i] == '\0') {
                fin = 1;
            } else {
                i++;
                if(nomBalise[i] != '='){
                    nomAtt[compteur] = nomBalise[i];
                    compteur++;
                }
            }
        }
        compteur = 0;
        while (nomBalise[i] != ' ') {
            if (nomBalise[i] == '\0' || nomBalise[i]=='>') {
                fin = 1;
                break;
            } else {
                i++;
                valeurAtt[compteur] = nomBalise[i];
                compteur++;
            }
        }
        compteur = 0;
        struct Attr monAttr;
        monAttr.name = nomAtt;
        monAttr.value = valeurAtt;
        tempo[nombreAtt] = monAttr;
        nombreAtt++;
    }

    tab->attributs = malloc(sizeof( Attr )* nombreAtt); //nombreAtt = nombre d'attribut
    for (int i=0; i<nombreAtt;i++)
    {
        Attr  *att = &tempo[i];
        strcpy(tab->attributs[nombreAtt] , att);
    }
    tab->attributsAmount = malloc(sizeof(int* )* nombreAtt);
    tab->attributsAmount= nombreAtt;
}


void baliseFermante(FILE * f,element* tab){;
    char nomBalise[30];
    int compteur = 0;
    char c = (char)fgetc(f);
    while ( c != '>'){
        nomBalise[compteur]= c;
        compteur ++;
        c = (char)fgetc(f);
    }
    nomBalise[compteur]='\0';
    tab->close = malloc(sizeof(char *)* strlen(nomBalise));
    strcpy(tab->close,nomBalise);
}


void lectureFichier(FILE* f, element *tab){

    baliseOuvrante(f,tab);
    lecturecontent(f,tab);
    baliseFermante(f,tab);
}

void AfficherFichier(element *tab)
{
    printf(" \n %s", tab->open);
    printf(" \n %s", tab->content);
    printf(" \n %s", tab->close);
}


int main() {
    int fin = 0;
    int* finFichier = &fin;

    element rien;
    element *test = &rien; // tableau de struct
    FILE* f = fopen("test.txt","r");
    element tab[10];
    int index = 0; // represente les index du tableau de struct
    element *pointeur = &tab[0];
    if (f!= NULL){
        printf("Le fichier est ouvert !\n");
    }else{
        printf("Probleme de l'ouverture du fichier!\n");
        return 0;
    }
    lectureFichier(f,pointeur);
    AfficherFichier(pointeur);
    char c = (char)fgetc(f);
    int ligne = 0;
    while (c != EOF) 
    {
        while ( c  != '\n') // sup les caractère en trop hors des balises
        {
            c = (char)fgetc(f);
        }
            ligne ++;
            pointeur = &tab[ligne];
            lectureFichier(f,pointeur);
            AfficherFichier(pointeur);

    }
    fermetureFichier(f);
    return 0;
}
