#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tag Tag;
typedef struct Attr Attr;

struct Tag{
    char* start; // balise ouvrante + parametre)
    char* content;
    char* close; // balise de fermeture
    int* childTags ; // adresse de la structure du parent ( question 3)
    int* childsAmount; //taille du tableau
    struct Attr ** attributs;
};

struct Attr {
    char * name;
    char * value;
} ;

void fermetureFichier(FILE*);
void baliseOuvrante(FILE * ,Tag*); // lecture de la balise ouvrante
void baliseFermante(FILE * ,Tag*);
void lecturecontent(FILE *, Tag*); // lecture du content entre 2 balises
void decoupeAttribut(FILE *,char*, Tag*,int ); // découper le nom attribut et valeur attribut
void lectureFichier(FILE* ,  Tag*); // fonction qui regroupe toute les autre f° de lecture
void AfficherFichier(Tag*); // uniquement pour Tester

void fermetureFichier(FILE* f){
    fclose(f);
    printf(" \n Fermeture du fichier!\n");
}

void baliseOuvrante(FILE *f, Tag *tab){ // detection de la balise ouvrante et stockage du nom de la balise
    char a = (char)fgetc(f);
    char nomBalise[50]; // variable temporaire de stockage d'information
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
            tab->start = malloc(sizeof(char )* strlen(nomBalise));
            strcpy(tab->start ,nomBalise);
            compteur = 0;
            posedeAtt = 2;
        }
    }
    nomBalise[compteur] = '\0';
     if( posedeAtt==0){
         tab->start = malloc(sizeof(char )* strlen(nomBalise));
         strcpy(tab->start ,nomBalise);
     }else{
         char * tempo = &nomBalise;
         decoupeAttribut(f,tempo, tab, compteur);
     }
}

void lecturecontent(FILE *f, Tag *tab){ // lecture des donnée jusque detection de la balise de fermeture ( </ )
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

void decoupeAttribut(FILE *f, char *nomBalise ,Tag *tab, int longeur) {
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
                nomAtt[compteur] = nomBalise[i];
                compteur++;
            }
        }
        nomAtt[compteur-1]='\0';
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
        valeurAtt[compteur]='\0';
        compteur = 0;
        struct Attr monAttr;
       // monAttr.name = nomAtt;
        //monAttr.value = valeurAtt;

        char *test = nomAtt;
        char  *teeest = valeurAtt;
        tempo[nombreAtt].name= (char *) test;
        tempo[nombreAtt].value= (char *) teeest;
        nombreAtt++;

    }
//
    tab->attributs = malloc(sizeof( Attr )* nombreAtt);
    for (int y=0; y<nombreAtt;y++)
    {
        tab->attributs[y] = &tempo[y];
    }
    //tab->attributsAmount= nombreAtt;
}


void baliseFermante(FILE * f,Tag* tab){;
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


void lectureFichier(FILE* f, Tag *tab){

    baliseOuvrante(f,tab);
    lecturecontent(f,tab);
    baliseFermante(f,tab);
}

void AfficherFichier(Tag *tab)
{
    printf(" \n %s", tab->start);
    printf(" \n %s", tab->content);
    printf(" \n %s", tab->close);
}


int main() {
    int fin = 0;
    int* finFichier = &fin;

    /*Tag rien;
    Tag *test = &rien; // tableau de struct*/

    FILE* f = fopen("test.txt","r");
    Tag tab[10];
    int index = 0; // represente les index du tableau de struct
    Tag *pointeur = &tab[0];
    if (f!= NULL){
        printf("Le fichier est ouvert !\n");
    }else{
        printf("Probleme de l'ouverture du fichier!\n");
        return 0;
    }

    lectureFichier(f,pointeur);
    AfficherFichier(pointeur);
    char c = ' ';
    //char c = (char)fgetc(f);
    int ligne = 0;
    while (c != EOF)
    {

        c = (char)fgetc(f);
       /* while ( c != EOF)
        {
            c = (char)fgetc(f);
        }*/
    if ( c == '\n')
    {
        ligne ++;
        pointeur = &tab[ligne];
        lectureFichier(f,pointeur);
        AfficherFichier(pointeur);
    }

    }
    fermetureFichier(f);
    return 0;
}
