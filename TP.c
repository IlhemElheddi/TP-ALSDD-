/**.------------------------------------------Introduction--------------------------------------------.
|This program, developed by Ilhem Elheddi & Imane Madani, organizes registrations of student-athletes|
|for regional university games in the central region. It uses a matrix structure of linked linear    |
|lists to represent registrations for up to 20 sports events. Universities and sports events,        |
|listed alphabetically, are stored in tables named "tabuniv" and "tabepreuve" respectively.          |
|Each university can enroll 0 to 15 athletes per event. Athlete data, including numbers, surnames,   |
|and first names, are stored in Linked List-like structures. The matrix "tabjru" holds pointers to   |
|athlete records for each event and university combination. If no athletes are registered,           |
|the corresponding element contains NULL.                                                            |
|____________________________________________________________________________________________________|
*/






/********************************** NOTE:FOR BOOLEANS ******************************************/
/*In this program, we are assigning the boolean value of "true" to the numeral (1) and the boolean
 value of "false" to the numeral (0).*/
 /**********************************************************************************************/





/***BIBLIOGRAPHIES***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
/********************/




/******************* CONSTANTES & VARIABLES ******************/
#define KEY_UP 72 /*Used in the Menu*/
#define KEY_DOWN 80
#define KEY_ENTER 13
#define KEY_ESC 27
#define ANSI_COLOR_WHITE   "\x1b[97m"
#define ANSI_COLOR_LIGHT_BLUE   "\x1b[94m"
#define MAX_OPTIONS 10

#define MAX_LENGTH 25   /* Maximum length for randomly generated names */
#define MAX_EPR 20      /* Maximum number of events allowed */
#define MAX_NUMB 13500  /* Upper limit for serial numbers */
#define maxathletes 15  /* Maximum number of athletes */
#define ARRAY_SIZE 45   /* Total number of universities in the array */
#define MAX_LENGTH 100  /* Maximum length of university names */
#define NUM_NAMES 100   /* Total number of names */
int UNIV = 45;          /* Current maximum number of universities */
int EPR = 20;           /* Current maximum number of events */

/************************************************************/




/*********************** DECLARING NECESSARY STRUCTURE FOR THE ATHELETES ***********************/
typedef struct concurrents {
int num ;                    /* Serial number of the athlete */
char  nom [25];              /* Family name  of the athlete*/
char prenom [25];            /* Name of the athlete */
struct concurrents *next;    /* The pointer to the next node */
}concurrents;

typedef struct concurrents* ptr; /* Definition of the struct as a "ptr" for easier usage */
/********************************************************************************************/




/*********************************ABSTRETE MACHINE******************************************/

void aff_num (ptr p , int value){ /* To assign a number in the filed of numbers */
p->num=value;
};

void aff_nom (ptr p , char value[25] ){ /* To assign a surname in the filed of "NOM" */
 strcpy(p->nom, value);
};

void aff_prenom (struct concurrents *p , char value[25]){ /* To assign a name in the filed of "PRENOM" */
 strcpy(p->prenom, value);
};

void allouer (ptr* p){ /* To allocate a node */
*p=(struct concurrents*)malloc(sizeof(struct concurrents));
};

void aff_adr (ptr p, ptr r){ /* To assign an address in the address filed of a node */
 p->next = r;
};

void suivant (ptr* p){ /* Jump to the next node pointer */
*p=(*p)->next;
};

/****************************************END*************************************************/



/****************************************COLORS***********************************************/

void clearScreen() {
    system("cls");
}

void green() { /* Change text color to Green */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void white() { /* Change text color to White */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
};

void blue() { /* Change text color to Blue */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
};

void gray() { /* Change text color to Gray */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
};

void red() { /* Change text color to Red */
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
};

/*******************************************************************************************/



/****************************************WELCOME********************************************/

void welcome(){ /* The interface of the program */

white(); /* Changing the text color to white */
    printf("\n\t\t\t\t      Higher School of computer science \n",130,130);


blue(); /* Changing the text color to blue */
    printf("\t\t\t              _________       _______       _____    \n");
    printf("\t\t\t             |_   ___  |     /  ___  |     |_   _|   \n");
    printf("\t\t\t               | |_  \\_|    |  (__ \\_|       | |    \n");
    printf("\t\t\t               |  _|  _      \'.___`-.        | |     \n");
    printf("\t\t\t              _| |___/ |    |`\\____) |      _| |_    \n");
    printf("\t\t\t             |_________|    |_______.\'     |_____|   \n\n");


white();
  printf("\t\t\t\tCPI - 1st preparatory  - university year 2023/2024 \n", 138, 130, 130);


  blue();
  printf("\t\t\t ___________________________________________________________________\n"); Sleep(50);
  printf("\t\t\t|                                                                   |\n");Sleep(50);
  printf("\t\t\t| DIRECTED BY :                                                     |\n");Sleep(50);
  printf("\t\t\t|");Sleep(50);
  white();
  printf("                ELHEDDI ILHEM                                      ");Sleep(50);
  blue();
  printf("|\n");Sleep(50);
  blue();
  printf("\t\t\t|                             &                                     |\n");Sleep(50);
  printf("\t\t\t|");Sleep(50);
  white();
  printf("                               MADANI IMANE                        ");Sleep(50);
  blue();
  printf("|\n");Sleep(50);
  blue();
  printf("\t\t\t|                                                                   |\n");Sleep(50);
  printf("\t\t\t|                                                                   |\n");Sleep(50);
  printf("\t\t\t|                  SECTION: ");Sleep(50);
  gray();
  printf("C");Sleep(50);
  blue();
  printf("            GROUP: ");Sleep(50);
  gray();
  printf("12");Sleep(50);
  blue();
  printf("                  |\n");Sleep(50);
  printf("\t\t\t|                                                                   |\n");Sleep(50);
  printf("\t\t\t|                    \tTP1 : The linked lists                      |\n", 130, 130);Sleep(50);
  printf("\t\t\t|                                                                   |\n");Sleep(50);
  printf("\t\t\t|            \t   < MANIPULATION OF LINKED LISTS >                 |\n");Sleep(50);
  printf("\t\t\t|                                                                   |\n");Sleep(50);
  printf("\t\t\t|                                                                   |\n");Sleep(50);
  printf("\t\t\t| FRAMED BY :");Sleep(50);
  white();
  printf(" Mr KERMI ADEL                                         ");Sleep(50);
  blue();
  printf("|\n");Sleep(50);
  printf("\t\t\t|___________________________________________________________________|\n");Sleep(50);


 gray();  /* Changing the text color to gray */
 printf("PRESS ENTER TO CONTINUE...");
  while (getch() != KEY_ENTER); /* Wait for Enter key press*/
  clearScreen();
    white();
    printf("\t\t\t            ,----,                 \n"); Sleep(200);
    printf("\t\t\t          ,/   .`|   ,-.----.      \n"); Sleep(200);
    printf("\t\t\t        ,`   .'  :   \\    /  \\     \n"); Sleep(200);
    printf("\t\t\t      ;    ;     /   |   :    \\    \n"); Sleep(200);
    printf("\t\t\t    .'___,/    ,'    |   |  .\\ :   \n"); Sleep(200);
    printf("\t\t\t    |    :     |     .   :  |: |   \n"); Sleep(200);
    printf("\t\t\t    ;    |.';  ;     |   |   \\ :   \n"); Sleep(200);
    printf("\t\t\t    `----'  |  |     |   : .   /   \n"); Sleep(200);
    printf("\t\t\t        '   :  ;     ;   | |`-'    \n"); Sleep(200);
    printf("\t\t\t        |   |  '     |   | ;       \n"); Sleep(200);
    printf("\t\t\t        '   :  |     :   ' |       \n"); Sleep(200);
    printf("\t\t\t        ;   |.'      :   : :       \n"); Sleep(200);
    printf("\t\t\t        '---'        |   | :       \n"); Sleep(200);
    printf("\t\t\t                     `---'.|       \n"); Sleep(200);
    printf("\t\t\t                       `---`       \n"); Sleep(200);


    printf("\t\t\t\t\t\t\t            ,----..         ,---, \n"); Sleep(200);
    printf("\t\t\t\t\t\t\t           /   /   \\     ,`--.' | \n"); Sleep(200);
    printf("\t\t\t\t\t\t\t          /   .     :   /    /  : \n"); Sleep(200);
    printf("\t\t\t\t\t\t\t         .   /   ;.  \\ :    |.' ' \n"); Sleep(200);
    printf("\t\t\t\t\t\t\t        .   ;   /  ` ; `----':  | \n"); Sleep(200);
    printf("\t\t\t\t\t\t\t        ;   |  ; \\ ; |    '   ' ; \n"); Sleep(200);
    printf("\t\t\t\t\t\t\t        |   :  | ; | '    |   | | \n"); Sleep(200);
    printf("\t\t\t\t\t\t\t        .   |  ' ' ' :    '   : ; \n"); Sleep(200);
    printf("\t\t\t\t\t\t\t        '   ;  \\; /  |    |   | ' \n"); Sleep(200);
    printf("\t\t\t\t\t\t\t         \\   \\  ',  /     '   : | \n"); Sleep(200);
    printf("\t\t\t\t\t\t\t          ;   :    /      ;   |.' \n"); Sleep(200);
    printf("\t\t\t\t\t\t\t           \\   \\ .'       '---'   \n"); Sleep(200);
    printf("\t\t\t\t\t\t\t            `---`                 \n"); Sleep(200);


    clearScreen();


   printf("\n\n\n\n\n");
   printf("\t\t                     ,--,                                                   \n");
   Sleep(200);
   printf("\t\t                  ,---.'|                                                   \n");
   Sleep(200);
   printf("\t\t   ,---,          |   | :        .--.--.          ,---,           ,---,      \n");
   Sleep(200);
   printf("\t\t  '  .' \\         :   : |       /  /    '.      .'  .' `\\       .'  .' `\\    \n");
   Sleep(200);
   printf("\t\t /  ;    '.       |   ' :      |  :  /`. /    ,---.'     \\    ,---.'     \\   \n");
   Sleep(200);
   printf("\t\t:  :       \\      ;   ; '      ;  |  |--`     |   |  .`\\  |   |   |  .`\\  |  \n");
   Sleep(200);
   printf("\t\t:  |   /\\   \\     '   | |__    |  :  ;_       :   : |  '  |   :   : |  '  |  \n");
   Sleep(200);
   printf("\t\t|  :  ' ;.   :    |   | :.'|    \\  \\    `.    |   ' '  ;  :   |   ' '  ;  :  \n");
   Sleep(200);
   printf("\t\t|  |  ;/  \\   \\   '   :    ;     `----.   \\   '   | ;  .  |   '   | ;  .  | \n");
   Sleep(200);
   printf("\t\t'  :  | \\  \\ ,'   |   |  ./      __ \\  \\  |   |   | :  |  '   |   | :  |  ' \n");
   Sleep(200);
   printf("\t\t|  |  '  '--'     ;   : ;       /  /`--'  /   '   : | /  ;    '   : | /  ;  \n");
   Sleep(200);
   printf("\t\t|  :  :           |   ,/       '--'.     /    |   | '` ,/     |   | '` ,/   \n");
   Sleep(200);
   printf("\t\t|  | ,'           '---'          `--'---'     ;   :  .'       ;   :  .'     \n");
   Sleep(200);
   printf("\t\t`--''                                         |   ,.'         |   ,.'       \n");
   Sleep(200);
   printf("\t\t                                              '---'           '---'         \n\n\n\n\n");
   Sleep(1000);


  gray();


  printf("PRESS ENTER TO CONTINUE...");
  while (getch() != KEY_ENTER); /* Wait for Enter key press*/

  blue();

 clearScreen();


 /* Instructions provided to assist users in effectively utilizing the menu */
 printf("\n                    ************************Menu Usage Guide:***********************\n\n");
 white();
 printf("                                  1. Use arrow keys to navigate menu.\n");
 printf("                                  2. Press Enter to select highlighted option.\n");
 printf("                                  3. Mouse input supported: Click on option.\n");
 printf("                                  4. Interactive interface for easy selection.\n");
 printf("                                  5. Convenient way to interact with program.\n\n\n");

 gray();


 printf("PRESS ENTER TO CONTINUE...");
  while (getch() != KEY_ENTER); /* Wait for Enter key press*/


  blue();

};

/**************************************************************************************************/




/*******************************************MENU***************************************************/

void displayMenu(int numOptions, int highlightedOption) {

/* The menu, offering users the ability to select their desired options */

   int i;

    blue();
    printf("\n");
    printf("       _ __ ___   ___ _ __  _   _  \n");
    printf("      | '_ ` _ \\ / _ \\ '_ \\| | | | \n");
    printf("      | | | | | |  __/ | | | |_| | \n");
    printf("      |_| |_| |_|\\___|_| |_|\\__,_| \n\n");


    for (i = 1; i < numOptions; i++) {

        if (i == highlightedOption) {
            printf(ANSI_COLOR_LIGHT_BLUE "[-->] ");
        } else {
            printf(ANSI_COLOR_WHITE "[ ] ");
        }  white();
        if (i == 1) {
            printf("1.Create Tabjru.\n");
        } else if (i == 2) {
            printf("2.Insert a new athelet.\n");
        } else if (i == 3) {
            printf("3.Display the players of a given etablissement.\n");
        } else if (i == 4) {
            printf("4.Check if an event has no players.\n");
        } else if (i == 5) {
            printf("5.Display all the players.\n");
        } else if (i == 6) {
            printf("6.Delete an etablissement.\n");
        } else if (i == 7) {
            printf("7.Delete an athelete.\n");
        } else if (i == 8) {
            printf("8.Delete an event without players.\n");
        } else {
            printf("9.Exit.\n");
            blue();
        }
    }
};

int getMenuChoice() {

    int ch = 0;

    do {
        ch = getch();
        switch (ch) {
            case KEY_UP:
                return -1;
            case KEY_DOWN:
                return 1;
            case KEY_ENTER:
                return 0;
            case KEY_ESC:
                return -2;
        }
    } while (1);
};
/**************************************************************************************************/








/**===================================================================================================
=====================================|first procedure|================================================
======================================|CREATE TABJRU|=================================================*/


/**--------------------------------1-declaring different names -------------------------------------*/

char arabian_names[NUM_NAMES][MAX_LENGTH] = {
   "Abdelkader", "Samia", "Kamel", "Djamila", "Fares", "Aziz", "Akrem", "Slimani", "Hamid", "Belkacem",
    "Morad", "Said", "Boudjemaa", "Adlene", "Lakhdar", "Belaid", "Mokrane", "sirine", "Benali", "Farid",
    "Ferial", "Houda", "Wahiba", "Anis", "Amira", "Bilal", "Khaled", "Farida", "Khaled", "Karima",
    "Ali", "Salima", "Omar", "Nadia", "Yousef", "Houria", "Ahmed", "Hadjer", "Sofiane", "Sana",
    "Mohamed", "Laila", "Reda", "Nawel", "Amine", "Yasmina", "Mehdi", "Malika", "Karim", "Amel",
    "Rachid", "Rym", "Said", "Ines", "Nasser", "Nadia", "Mounir", "Fatma", "Nabil", "Fatiha",
    "Hassan", "Zineb", "Zakaria", "Asma", "Anis", "Sabrina", "Tarek", "Amina", "Nacer", "Dina",
    "Adel", "Fella", "Tarek", "Nadia", "Kacem", "Sidali", "Walid", "Latifa", "Noureddine", "Rabia",
    "Amar", "Ilhem", "Hichem", "Saida", "Lotfi", "Sihem", "Soufiane", "Soraya", "Yacine", "Wafa","Lina",
    "Nadir","Ayoub","Adel","haithem","Samy","imane","Ilhem","Nora","Anissa","Rida"
};

/**----------------------------------------------End 1------------------------------------------------*/


/**--------------------------------2-declaring different family names ----------------------------------*/

char family_names[NUM_NAMES][MAX_LENGTH] = {
    "ABDELKADER", "AIT AHMED", "AIT BOUGMEZ", "AIT HAMOU", "AIT OUAKLI", "AIT YAHIA", "BENAISSA", "BENALI", "BENAMAR", "BENATIA",
"BENAYAD", "BENAYOUN", "BENAOUDA", "BENAOUISSEF", "BENAYAD", "BENAYOUN", "BENDIDA", "BENFIFI", "BENHAMOU", "BENKHEIRA",
"BENMESSAOUD", "BENNACEUR", "BENNAI", "BENNAY", "BENNOUR", "BENTAIBI", "BENTALEB", "BERRABAH", "BOUAMAMA", "BOUCHOUICHA",
"BOUDIAF", "BOUFENAR", "BOUGHERARA", "BOUKERZAZA", "BOUMAZA", "BOUMEDINE", "BOURAS", "BOUROUIBA", "BOUZID", "CHEBLI",
"CHERGUI", "CHERIF", "DADOUNE", "DJELLAB", "FERHATI", "GHAZI", "GOUCEM", "GUENDOUZ", "GUERROUDJ", "GUEZZI",
"HADJ", "HAMDANI", "HAMDAD", "HAMDACHE", "HAMMOUCHE", "HAMROUCHE", "HAMOUCHE", "HANNACHE", "HANNAT", "HANNOUCHE",
"KACEM", "KACI", "KADER", "KADI", "KAHLOUCHE", "KARA", "KERBOUCHE", "KERRACH", "KERROUCHE", "KHELILI",
"LOUNIS", "LOUCIF", "MAZOUZI", "MEGHICHI", "MERABET", "MERZOUGUI", "MESSAOUDI", "MOUACI", "NACERI", "OUADAH",
"OUAMRANE", "OUALI", "RABAH", "RAHAL", "RAMDANI", "REMILA", "REZZOUG", "SADI", "SADMI", "SAHNOUNE",
"SAHRAOUI", "SAID", "SAIDI", "SAKER", "SEDIKI", "SEGHIR", "SENOUNCI", "SLIMANI", "TALEB", "ZAOUI"
};

/**---------------------------------------------end 2 ----------------------------------------------------*/


/**-----------------------3-Outputs a random integer with chosen max and min-------------------------------*/

int generateRandomInt(int min, int max) {

    return min + rand() % (max - min + 1);

};

/**-----------------------------------------------End 3--------------------------------------------------*/


/**-----------------------------4-Checks if a number already exists---------------------------------------*/

int exist (int num,int T[],int size){

int i ;

for (i=0;i<=size;i++){ /*Searches in the 'tabnombre' array to determine if the number has already been used */
    if (num==T[i])
        return 1;

}
return 0;
};

/**----------------------------------------------End 4--------------------------------------------------*/


/**-----------------------------5-Outputs a name from the list (Array)--------------------------------*/

void getArabianName(int index, char name[]) {

    if (index >= 0 && index < NUM_NAMES) {
        strcpy(name, arabian_names[index]);
    } else {
        strcpy(name, ""); /* Empty string for out-of-range index */
    }
};

/**---------------------------------------------End 5-------------------------------------------------*/



/**-------------------------6-Outputs a Familyname form the list (array)-----------------------------*/

void getFamilyName(int index, char name[]) {

    if (index >= 0 && index < NUM_NAMES) {
        strcpy(name, family_names[index]);
    } else {
        strcpy(name, ""); /* Empty string for out-of-range index*/
    }
};

/**--------------------------------------------End 6------------------------------------------------*/


/**------------------------------7- CREATION OF TABEPREUVE-------------------------------------------*/

void sports_tab(char tabepreuve[EPR][50], int num_sports) {

    int i;

    /*Events list */
    char sportss[20][50] = {
     "aviron", "athletisme", "badminton", "basketball", "boxe", "cyclisme",
     "echecs", "escrime", "football", "gymnastique", "halterophilie" , "handball",
      "judo", "karate", "natation","taekwondo", "tennis", "tennis de table", "tir a l'arc", "volleyball"};
           for (i =0; i<= num_sports && i <=EPR; i++) {
        strncpy(tabepreuve[i], sportss[i], 50);
      };
};

/**-------------------------------------------END 7--------------------------------------------------*/

/**----------------------------------------8- CREATION OF TABUNIV-------------------------------------*/

void univ_tab(char tabuniv[UNIV][100],int num_univ) {

    int i ;

    /*Universities List */
    char univ[45][100] = {
        "Centre universitaire d'Aflou",
        "Centre Universitaire d'Illizi-Cheikh Amoud ben Mokhtar",
        "Centre universitaire de Tipaza Abdallah Morsli",
        "Ecole des hautes etudes commerciales",
        "Ecole Nationale Polytechnique",
        "Ecole nationale superieure agronomique_Khalef Abdellah alias Kasdi Merbah",
        "Ecole nationale superieure d'hydraulique Arbaoui Abdellah",
        "Ecole nationale superieure d'informatique",
        "Ecole nationale superieure de journalisme et des sciences de l'information",
        "Ecole nationale superieure de management",
        "Ecole Nationale Superieure de Technologie",
        "Ecole nationale superieure des sciences de la mer et de l'amenagement du littoral",
        "Ecole Nationale Superieure des sciences politiques",
        "Ecole Nationale Superieure des Technologies Avancees",
        "Ecole nationale superieure des travaux publics _ Francis Jeanson",
        "Ecole Nationale Superieure en Mathematique",
        "Ecole nationale superieure en statistique et en economie appliquee",
        "Ecole Nationale Superieure en Intelligence Artificielle",
        "Ecole nationale superieure veterinaire _ Rabie Bouchama",
        "Ecole normale superieure de Bouzareah _ Cheikh Mubarak Ben Mohamed Brahimi El Mili",
        "Ecole Normale Superieure de Kouba _ Mohamed Bachir El Ibrahimi",
        "Ecole normale superieure de Laghouat _ Taleb Abderrahmane",
        "Ecole Polytechnique d'architecture et d'Urbanisme-Hocine Ait Ahmed",
        "Ecole Superieure de Commerce_Mouloud Kacem Nait Belkacem",
        "Ecole Superieure de Gestion et d'Economie Numerique",
        "Ecole Superieure des Sciences appliquees d'Alger",
        "Ecole Superieure des Sciences de l'Aliment et des Industries Agroalimentaires d'Alger",
        "Ecole Superieure en Sciences et Technologies de l'Informatique et du Numerique de Bejaia",
        "Universite d'Alger 1 Benyoucef Benkhedda",
        "Universite d'Alger 2_ Abou el Kacem Saadallah",
        "Universite d'Alger 3_ Brahim Soltane Chaibout",
        "Universite de Bejaia _ Abderrahmane Mira",
        "Universite de Blida 2 _ Lounici Ali",
        "Universite de Ghardaia",
        "Universite de la Formation Continue",
        "Universite de Tamenghasset",
        "Universite de Tizi Ouzou _ Mouloud Maamer",
        "Universite des sciences et de la technologie d'Alger, Houari Boumediene",
        "Universite de Blida 1 _ Saad Dahlab",
        "Universite de Bouira _ Akli Mohand Oulhadj",
        "Universite de Boumerdes _ M'hamed Bougara",
        "Universite de Djelfa Ziane Achour",
        "Universite de Khemis Miliana _ Djilali Bounaama",
        "Universite de Laghouat _ Amar Telidji",
        "Universite Medea _ Yahia Fares"
    };
    for ( i = 0; i <= num_univ && i <=UNIV; i++) {
        strncpy(tabuniv[i], univ[i], 100);
    }
};

/**------------------------------------------END 8----------------------------------------------*/




/**************************************Create TABJRU************************************************/

void create_tabjru(ptr t[21][46], int tabnombre[13500], int *size, char sport[EPR][50], char univ[UNIV][100]) {

    int i, j, k, n, a, d, mat;
    ptr P, Q;
    char name1[MAX_LENGTH];  /* Athlete's first name*/
    char name2[MAX_LENGTH];  /* Athlete's family name*/


    /* Creating a table of sports (tabepreuve) with 20 elements*/
    sports_tab(sport, 19);

    /* Creating a table of universities (tabuniv) with 45 elements*/
    univ_tab(univ, 44);


    /* Loop over each event and university to populate the matrix */
    for (i = 1; i <= EPR; i++) {
        for (j = 1; j <= UNIV; j++) {
            t[i][j] = NULL;  /* Initializing the head of the linked list to NULL*/
            n = generateRandomInt(0, 15);  /* Generating a random number of nodes for each linked list*/

            /* Generating random names for the athlete*/
            for (k = 1; k <= n; k++) {
                allouer(&P);  /* Allocating memory for a new node*/
                aff_adr(P, NULL);  /* Setting the next pointer of the node to NULL */
                a = generateRandomInt(0, 99);  /* Generating random numbers for names */
                d = generateRandomInt(0, 99);

                /* Getting random name and family name*/
                getArabianName(a, name1);
                getFamilyName(d, name2);

                /* Generating a unique serial number for the athlete*/
                do {
                    mat = generateRandomInt(1, 13500);
                } while (exist(mat, tabnombre, *size) == 1);

                /* Adding the serial number to the tabnombre array*/
                tabnombre[*size] = mat;
                (*size)++;

                /* Setting the attributes of the node (name, serial number)*/
                aff_nom(P, name2);  /* Setting the family name*/
                aff_prenom(P, name1);  /* Setting the first name*/
                aff_num(P, mat);  /* Setting the serial number*/

                /* Adding the node to the linked list*/
                if (t[i][j] == NULL)
                    t[i][j] = P;  /* If head is NULL, update head*/
                else
                    aff_adr(Q, P);  /* If not, update the next pointer of the previous node*/

                Q = P;  /* Moving to the next node*/
            }
        }
    }
    green();
    printf("Creation has been successfully completed.\n");
    /* Displays the success message upon successful completion of the operation */
};

/**----------------------------------------------End 7------------------------------------------------


/**==================================== END PROCEDURE ONE =============================================
/**====================================================================================================*/








/**====================================================================================================
==========================================|SECOND PROCEDURE|===========================================
/*==========================================INSERT ATLETHE============================================*/


/**-------------------------------------1-FINDING THE LENGTH OF The Linked list------------------------------------*/

int length_llc(ptr p) {

    int count = 0;

    /* Iterate through the linked list until reaching the end (NULL)*/
while (p != NULL) {
    /* Increment the count for each node visited*/
    count++;
    /* Move to the next node*/
    p = p->next;
}
/* Return the total count, which represents the length of the linked list*/
return count;
};
/**-----------------------------------------------End 1-------------------------------------------------*/


/******************************************INSERT AN ATHLETE-*********************************************/

void inserath(int numath, char nomath[25], char prenomath[25], int numet, int numep, ptr t[21][46], int tabnombre[13500], int *size) {

    ptr p, r;
    blue();
    /* Check if the university exists*/
    if (numet > UNIV || numet < 1) {
        printf("University doesn't exist !!\n");
    }
    else {
        /* Check if the event exists*/
        if (numep > EPR || numep < 1) {
            printf("Sport doesn't exist !!\n");
        }
        else {
            /* Check if the serial number is valid*/
            if (numath > 13500) {
                printf("Number too big (>13500)!!\n");
            }
            else {
                /* Check if the serial number is already used*/
                if (exist(numath, tabnombre, *size) == 1) {
                    printf("The number exists.\n");
                }
                else {
                    p = t[numep][numet]; /* Get the head pointer for the specified event and university*/
                    int n = length_llc(p); /* Calculate the current number of athletes*/

                    /* Check if there is space for another athlete*/
                    if (n == 15) {
                        red();
                        printf("Unable to insert. Overflow occurred!\n");
                    }
                    else {
                        /* Allocate memory for the new athlete node*/
                        ptr newNode;
                        allouer(&newNode);
                        /* Set the attributes of the new athlete*/
                        aff_num(newNode, numath);
                        aff_nom(newNode, nomath);
                        aff_prenom(newNode, prenomath);
                        aff_adr(newNode, p);
                        /* Update the head pointer to point to the new node*/
                        t[numep][numet] = newNode;
                        /* Store the serial number in the array*/
                        tabnombre[*size] = numath;
                        /* Increment the size of the array*/
                        (*size)++;
                        green();
                        printf("Insertion has been successfully completed.\n");
                        /* Displays the success message upon successful completion of the operation */
                    }
                }
            }
        }
    }
};
/**------------------------------------------------End -------------------------------------------------------*/


/**=========================================|END PROCEDURE TWO|==================================================
/**==============================================================================================================*/








/**==============================================================================================================
==============================================|PROCEDURE 3|-=====================================================
================================================LISTATHET========================================================*/


/*-------------------------1-FINDING CORRECPONDING INDEX OF A SPECIFIC UNIVERSITY-------------------------------*/

int numuniv(char University[100], char u[UNIV][100]) {

    int i;

    for (i=0;i<UNIV;i++){
        if(strcmp(u[i],University)==0){
                return i ;

        }
    }
    return -1;
};

/*-----------------------------------------------------END 1--------------------------------------------------*/



/*********************************DISPLAY ATHELETE OF GIVEN UNIVERSITY**********************************************/

void listathet(ptr tab[21][46], char university[90], char t[EPR][50], char u[UNIV][100]) {

    int i, univ;
    ptr p;

    univ = numuniv(university,u); /* Fetch the index of the specified university*/

    if (univ == -1) { /* Check if the university doesn't exist*/
        blue();
        printf("University doesn't exist!"); /* Display error message*/
    } else {

         /* If the university exists*/
         blue();
        printf("\n------------- Displaying the players -------------\n\n");
        printf("%s: \n\n", u[univ]); /* Display the name of the university*/

        for (i = 0; i < EPR; i++) { /* Iterate through each event*/
            p = tab[i + 1][univ + 1];
            blue();
            printf("\n%d/- %s:\n", i + 1, t[i]);

            while (p != NULL) { /* Iterate through the linked list of athletes for the current event and university*/

            white();
            printf("The number:");
            gray();
            printf("%d -- ",p->num);
            white();
            printf("Surname:");
            gray();
            printf("%s -- ",p->nom);
            white();
            printf("Name:");
            gray();
            printf("%s.",p->prenom);
            printf("\n");

                p = p->next; /* Move to the next athlete in the linked list*/

        }}}};

/**------------------------------------------------END------------------------------------------------------*/


/**=========================================|END PROCEDURE THREE|==================================================
===================================================================================================================*/








/**============================================================================================================
=============================================|PROCEDURE 4|==================================================
==============================================WITHOUTATH=====================================================*/

int withoutath(int ne, ptr tab[21][46]) {

    int i, trouv;

    trouv = 1; /* Initialize trouv to true*/
    i = 1;

if ((ne<1)||(ne>20)) {
    white();
    printf("Please verify the number of the event again!\n");
    trouv=-1;}

 else {
    while ((trouv == 1) && (i <= 45)) {

        if (tab[ne][i] == NULL) {
             /* If the linked list for the current event and university is NULL, move to the next column*/
            i++;
        }   else {
            trouv = 0; /* If a non-NULL linked list is found, set trouv to false and exit the loop*/
        }
    }};
    return trouv;
}

/**------------------------------------------------END ------------------------------------------------------*/


/**=========================================|END PROCEDURE FOUR|==================================================
==================================================================================================================*/








/*============================================================================================================
  =============================================|PROCEDURE 5|==================================================
  ================================================LISTJRU=====================================================*/

void listju (ptr tab[21][46],char epr[EPR][50],char univ[UNIV][100]){ /* displaying the "tabjru" matrix */

int i,j;
ptr p ;

 blue();
 printf("------------------DISPLAYING ALL THE PLAYERS--------------------\n\n");

for (i=0;i<EPR;i++){
  blue();
  printf("%d- %s:\n\n",i+1,epr[i]);

  for (j=0;j<UNIV;j++) {
  p=tab[i+1][j+1];
  blue();
  printf("%d- %s:\n",j+1,univ[j]);

    while (p!=NULL){
    white();
    printf("The number:");
    gray();
    printf("%d -- ",p->num);
    white();
    printf("Surname:");
    gray();
    printf("%s -- ",p->nom);
    white();
    printf("Name:");
    gray();
    printf("%s.",p->prenom);
    printf("\n");

    p=p->next;}
    printf("\n");
    }
    gray();
    printf("PRESS ENTER FOR NEXT THE EVENT...\n\n");
  while (getch() != KEY_ENTER); /* Wait for Enter key press*/}};

/*-------------------------------------------------END -----------------------------------------------------*/

/**=========================================|END PROCEDURE FIVE|==================================================
==================================================================================================================*/










/**============================================================================================================
   =============================================|PROCEDURE 6|==================================================
   ===============================================DELETEATH====================================================*/

/*---------------------------------------1-SHIFTING A 1D ARRAY --------------------------------------------*/

void leftShift_Strings(char array[][MAX_LENGTH], int startIndex) {

    int i ;  /*Start shifting from startIndex to the left*/

       for (i = startIndex; i < ARRAY_SIZE - 1; ++i) {

       strcpy(array[i], array[i + 1]); /* Copy the next string to the current position*/
       }
    array[ARRAY_SIZE - 1][0] = '\0';    /* Empty the last element*/
};

/*-------------------------------------------------END 1-----------------------------------------------------*/


/*---------------------------------2- SHIFTING COLUMNS OF A 2D ARRAY  ---------------------------------------*/

void shiftColumns(ptr tab[21][46], int index){

    int i, j;

/* Iterate over each column from the index of the deleted university to the end.*/
    for(i=index; i<=UNIV; i++) {
        /* Iterate over each row representing an event.*/
        for (j = 1; j <= EPR; j++) {
            /* Shift the pointer in each cell of the current column to the left.*/
            tab[j][i] = tab[j][i + 1];
        }
    }
};

/*-------------------------------------------------END2-----------------------------------------------------*/


/*-------------------------------------------3-displaying tabuniv--------------------------------------------*/

list_tabuniv(char t[46][100]){

int i;
  blue();
printf("\n--------------List of available universities :-----------------\n");
white();
for (i=0;i<UNIV;i++){
    printf("%d-%s \n",i+1,t[i]);
}
};

/*-------------------------------------------------END 3-----------------------------------------------------*/

void Deleteath (char etablissement[100],ptr tab[21][46],char u[UNIV][100],int tabnombre[13500], int *size ){

int index,i,j ;
ptr p,temp;

index=numuniv(etablissement,u); /* Determine the index of the university in the array of university names.*/

    if (index==-1){
                             /*The university doesn't exist*/
    printf("University doesn't exist!!");
       }else {                     /*The university  exists */

       leftShift_Strings(u,index);/* Shifts an array of strings to the left by a specified amount */

       for (i=1;i<=EPR;i++){      /*Iterate over each row corresponding to a specific event.*/
       p=tab[i][index+1];
       if (p==NULL){

          }else {
                                /* Free the memory associated with each node in the linked list*/
             while(p!=NULL){

                    for ( j = 0; j < *size; j++) { /*Delete the Serial number from tabnombre */
                 if (tabnombre[j] == p->num) {
                tabnombre[j] = -1;
            }}
             temp=p;
             p=p->next;
             free(temp);
             /* Remove the athlete's number from tabnombre */
        }
             }}
      shiftColumns(tab,index);
      UNIV --;
      green();
      printf("Deletion has been successfully completed.\n");
      /* Displays the success message upon successful completion of the operation */
      }
      };
/*-------------------------------------------------END -----------------------------------------------------*/

/**=========================================|END PROCEDURE SIX|==================================================
=================================================================================================================*/









/*============================================================================================================
//=============================================|PROCEDURE 7|==================================================
//================================================DELATH======================================================*/


/*-----------------------------------------------DELETE ATHELETE----------------------------------------------*/

 void Delath(int numath, int numet, int numep, ptr tab[21][46], int tabnombre[13500], int *size) {

    ptr p, prec, temp;
    prec = NULL;
    int i,j;
    int trouv = 0;

    blue();

    /* Check if the university number is valid. */
    if (numet > UNIV || numet < 1) {
        printf("University doesn't exist!!");
        return;
    }

    /* Check if the event number is valid. */
    if (numep > EPR || numep < 1) {
        printf("Sport doesn't exist!!");
        return;
    }

    /* Check if the athlete number is within the valid range. */
    if (numath > 13500) {
        printf("Number too big (>13500)!!");
        return;
    }

    /* Check if the athlete number exists in the tabnombre array. */
    if (exist(numath, tabnombre, *size) == 0) {
        printf("The number doesn't exist");
        return;
    }

    /* Retrieve the pointer to the first athlete in the specified university and event. */
    p = tab[numep][numet];

    if (p == NULL) {
        red();
        printf("Please verify the event or the sport(there are no athletes registered here)! ");
        return;
    }

    /* If the athlete to be deleted is the first node. */
    if (p->num == numath) {
        for ( j = 0; j < *size; j++) {
            if (tabnombre[j] == numath) {
                tabnombre[j] = -1;
            }
        }
        temp = p;
        suivant(&p); /* Move to the next athlete. */
        free(temp); /* Free the memory of the deleted athlete. */
        tab[numep][numet] = p; /* Update the pointer to the first athlete. */
        green();
        printf("Deletion has been successfully completed.\n");
        /* Displays the success message upon successful completion of the operation */
        return;
    }

    while (p != NULL) {
        if (p->num == numath) {
            trouv = 1;
            break; /* Break the loop once the athlete is found. */
        }
        prec = p;
        suivant(&p);
    }

    if (trouv == 0) {
        red();
        printf("The athlete with the provided number wasn't found in the specified university and event!\n");
        return; /* Exit the function if athlete not found in the specified university and event. */
    }

    temp = p;
    suivant(&p);
    aff_adr(prec, p);
    free(temp);

    /* Remove the athlete's number from tabnombre */
    for ( j = 0; j < *size; j++) {
            if (tabnombre[j] == numath) {
                tabnombre[j] = -1;
            }
        }

    green();
    printf("Deletion has been successfully completed.\n");
    /* Displays the success message upon successful completion of the operation */
}


/*---------------------------------------------------END------------------------------------------------*/

/**=======================================|END PROCEDURE SEVEN|================================================
/*=============================================================================================================*/










/*============================================================================================================
//=============================================|PROCEDURE 8|==================================================
//============================================ DELEMPTYLINES=================================================*/


/*------------------------------------------------SHIFTING LINES--------------------------------------------*/

void shiftLines(ptr tab[21][46], int index) {

    int i, j;

    /* Iterate over each row starting from the index of the deleted event.*/
    for (i = index; i < 21; i++) {
        /* Iterate over each column representing athletes in the event.*/
        for (j = 1; j <= 46; j++) {
            /* Shift the data in each cell of the current row to the row above.*/
            tab[i][j] = tab[i + 1][j];
        }
    }
}

/*------------------------------------------------END---------------------------------------------------------*/



/***********************************DELETING  WHERE NO ATHLETE IS PARTICIPATING********************************/

void delemptylines(ptr tab[21][46], char epr[21][100]) {

    int i;

    /* Iterate over each event.*/
    for (i = 1; i <= 20; i++) {
        /* Check if the event has no athletes.*/
        if (withoutath(i, tab) == 1) {
            leftShift_Strings(epr, i); /* Shift event names to fill the gap left by deleted event.*/
            shiftLines(tab, i); /* Shift event data to fill the gap left by deleted event.*/
            EPR--; /* Decrement the total number of events.*/
        }
    }

     blue();
    /* Check if any empty lines were deleted.*/
    if (EPR != 20) {
        printf("Deletion has been successfully completed.\n");
        /* Displays the success message upon successful completion of the operation */
    } else {
        printf("No empty lines found!\n");
    }
}

/*-----------------------------------------------------END ------------------------------------------------*/

/**=======================================|END PROCEDURE EIGHT|================================================
/*=============================================================================================================*/










/*============================================================================================================
/*======================================================MAIN==================================================
  ============================================================================================================*/

int main (){


    /*------------------------------------------DEACLARTION--------------------------------------------------*/

      ptr tabjru[21][46];      /* Matrix representing athlete data for each event */
      int tabnombre[13500];    /* Array for serial number verification */
      int fin_tab = 0;         /* Effective size of the tabnombre array */
      char tabepreuve[21][50]; /* Array representing sports */
      char tabuniv[46][100];   /* Array representing universities */
      int number, univ, epr, ne;   /* Variables for numbers, universities, and events */

    /*------------------------------------------------------------------------------------------------------*/


    int stat=0; /* Displays an error message if attempting manipulations on 'tabjuro' without creating it first */
    int answer;  /*To confirm the need of deletion */
    int numOptions = MAX_OPTIONS;  /* Used in menu manipulation */
    int choice = 1;
    int arrow;

    char name[25],familyname[25];  /* Athlete's information */
    char etablissment1[100],etablissment2[100]; /* Used to input university name */


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


   welcome(); /* Displaying the interface */



    do {
        clearScreen();
        displayMenu(numOptions, choice);
        arrow = getMenuChoice();
        if (arrow == -1 && choice > 1) { /* Process choice */
            choice--;
        } else if (arrow == 1 && choice < numOptions) {
            choice++;
        } else if (arrow == 0) {
         switch (choice) {


        case 1:
            stat=1;

      /*Set the 'stat' flag to indicate that Option 1 (Create tabjru) is selected.
       This ensures subsequent cases execute correctly, as it's necessary to create 'tabjru' first.*/


            /*Process option 1*/
    blue();
    printf("\t\t        __________________________________________________________________________\n");
    printf("\t\t\        |                       1/- Create tabjru:                               |\n");
    printf("\t\t\t|Tabjru represents a matrix of linked lists, where each cell contains a  |\n");
    printf("\t\t\t|linked list. Each linked list can accommodate a maximum of 15 athletes  |\n");
    printf("\t\t\t|            associated with a specific university and sport.            |\n");
    printf("\t\t\t|________________________________________________________________________|\n\n");
    printf("                                                                                  Maxepr20\n");
    printf("     TABJRU     ------------------------------------------------------------------------\n");
    printf("                |     |     |     |     |     |     |     |     |     |     |     |     |  Maxuniv 45\n");
    printf("                -------------------------------------------------------------------------\n");
    printf("                |     |     |     |     |     |     |     |     |     |     |     |     |\n");
    printf("                -------------------------------------------------------------------------\n");
    printf("                |     |     |     |     |     |     |     |     |     |     |     |     |\n");
    printf("                -------------------------------------------------------------------------\n");
    printf("                                 ____________________        _________________         _________________                \n");
    printf("                                |    |    |          |       |   |   |        |       |   |   |         |               \n");
    printf("                      HEAD--->  |Num |name|Familyname|------>|   |   |        |------>|   |   |         |------[        \n");
    printf("                                |____|___ |__________|       |___|___|________|       |___|___|_________|               \n\n");

    white();
    create_tabjru(tabjru,tabnombre,&fin_tab,tabepreuve,tabuniv);

    break;


        case 2:

            if (stat==0){
                    red();
                printf("\nAttention: Please create Tabjru first.\n"); /*Warning message */
                blue();}
            else {blue();

            /*Process option 2*/

            printf("\t\t        __________________________________________________________________\n");
    printf("\t\t\        |                       2/- Insertath:                            |\n");
    printf("\t\t\t| By specifying a university and event, we insert a new athlete,  |\n");
    printf("\t\t\t|        displaying error messages if any issues arise.           |\n");
    printf("\t\t\t|_________________________________________________________________|\n\n");
    printf("                                 ____________________                \n");
    printf("                                |    |    |          |                    \n");
    printf("                   NEWATH--->   |Num |name|Familyname|------[     \n");
    printf("                                |____|___ |__________|                   \n\n");

     white();

    printf("============================================The information needed:============================================\n");

    /*Inputing athlete's information */

    blue();
    printf("->The number of the athlete(max13500):\n");
    white();
    scanf("%d",&number);
    blue();
    printf("->The Name of the athelete:\n");
    white();
    scanf("%s",name);
    blue();
    printf("->The Familyname of the athlete:\n");
    white();
    scanf("%s",familyname);
    blue();
    printf("->The number of the university:\n");
    white();
    scanf("%d",&univ);
    blue();
    printf("->The number of the event:\n");
    white();
    scanf("%d",&epr);
    printf("==================================================================================================================\n\n");

    inserath(number,familyname,name,univ,epr,tabjru,tabnombre,&fin_tab);}

    break;

        case 3:

            /*Process option 3*/
            if (stat==0){
                    red();
                printf("Attention: Please create Tabjru first.\n");
                blue();}
            else {blue();
            printf("\t\t        _________________________________________________________________________\n");
   printf("\t\t\        |                       3/- Listathet:                                  |\n");
   printf("\t\t\t|     This function demonstrates each event where at least one athlete  |\n");
   printf("\t\t\t|     from the institution is registered. Then displays anunsorted   |\n");
   printf("\t\t\t|  list of athletes, including their numbers, surnames,and first names  |\n");
   printf("\t\t\t|If the institution is unrecognized, an error message will be displayed.|\n");
   printf("\t\t\t|_______________________________________________________________________|\n\n");

   list_tabuniv(tabuniv);

   white();
   printf("============================================The information needed:============================================\n");

   /*Inputing athlete's information */

   blue();

   printf("->Enter the name of the university please:\n");

   white();

   fgets(etablissment1,100,stdin);
   etablissment1[strcspn(etablissment1,"\n")]='\0';

   listathet(tabjru,etablissment1,tabepreuve,tabuniv);}

            break;


        case 4:

            /*Process option 4*/
             if (stat==0){
                red();
                printf("Attention: Please create Tabjru first.\n");
                blue();}

                else {
      blue();
      printf("\t\t        __________________________________________________________________\n");
      printf("\t\t\        |                       4/- withoutath:                           |\n");
      printf("\t\t\t| This function returns TRUE only if there are no athletes        |\n");
      printf("\t\t\t| registered for a specific event (denoted by event number ne).   |\n");
      printf("\t\t\t| In other words, it checks if the line contains only NULL values |\n");
      printf("\t\t\t|_________________________________________________________________|\n\n");
      printf("     TABJRU     ------------------------------------------------------------------------\n");
      red();
      printf("                |NULL |NULL |NULL |NULL |NULL |NULL |NULL |NULL |NULL |NULL |NULL |NULL |  TRUE \n");
      blue();
      printf("                -------------------------------------------------------------------------\n");
      printf("                |     |     |     |NULL |     |     |     |     |NULL |     |     |     |  False\n");
      printf("                -------------------------------------------------------------------------\n");

      white();

      printf("============================================The information needed:============================================\n");



      blue();
      printf("Enter the Event's number:");
      white();
      scanf("%d",&ne);

      answer=withoutath(ne,tabjru);

      blue();
      if (answer==1){
        printf("There is no athlete registered in this event.\n");
      }else {
          if (answer==0){
           printf("There are at least one athlete registered in this event.\n");}
            }};

      break;


        case 5:

            /*Process option 5*/
             if (stat==0){
                red();
                printf("Attention: Please create Tabjru first.\n");
                blue();}
                else {

                blue();
      printf("\t\t        ______________________________________________________________________\n");
      printf("\t\t\        |                          5/- Listju:                                |\n");
      printf("\t\t\t| This procedure presents the complete contents of the tabjru matrix  |\n");
      printf("\t\t\t| event-wise. For each event where at least one athlete is registered,|\n");
      printf("\t\t\t| it displays the event's name. Then, for each institution that has   |\n");
      printf("\t\t\t| registered athletes in that event, it shows the institution's name  |\n");
      printf("\t\t\t| along with the details of the registered athletes.                  |\n");
      printf("\t\t\t|_____________________________________________________________________|\n\n");

      listju(tabjru,tabepreuve,tabuniv);}

      break;



        case 6:
            /*Process option 6*/

             if (stat==0){
                    red();
                printf("Attention: Please create Tabjru first.\n");
                blue();}

                else
            {blue();
           printf("\t\t        ________________________________________________________________________\n");
      printf("\t\t\        |                          6/- Deleteath:                                 |\n");
      printf("\t\t\t| This operation removes an institution from the tabjru and tabuniv    |\n");
      printf("\t\t\t| structures. It happens when the institution declares its decision,   |\n");
      printf("\t\t\t| for financial reasons, to withdraw from participating in the regional|\n");
      printf("\t\t\t| university games.                                                    |\n");
      printf("\t\t\t|______________________________________________________________________|\n\n");
      printf("     TABJRU     ------------------------------------------------------------------------\n");
      red();
      printf("          ----> |/////|/////|/////|/////|/////|/////|/////|/////|/////|/////|/////|/////|  Centre universitaire d'Aflou \n");
      blue();
      printf("                -------------------------------------------------------------------------\n");
      printf("                |     |     |     |     |     |     |     |     |     |     |     |     |\n");
      printf("                -------------------------------------------------------------------------\n\n\n");
      printf("     TABUNIV     -------------------------------------------------------------------------------------------------\n");
      red();
      printf("            ----> |Centre universitaire d'Aflou|     |     |     |     |     |     |     |     |     |     |     |  \n,");
      blue();
      printf("                --------------------------------------------------------------------------------------------------\n\n");
      blue();

      list_tabuniv(tabuniv);

      white();
            printf("\n=================================The information needed:=================================\n");

      blue();
      printf("->Enter the name of the university please:\n");

      white();
      fgets(etablissment2,100,stdin);
      etablissment2[strcspn(etablissment2,"\n")]='\0';

      printf("===============================================================================================\n");

      red();

      /* Confirmation of deletion */

      printf("Could you affirm your intention to delete?\n");
      printf("0-> NO.\n");
      printf("1-> YES.\n");
      printf("Your answer(0,1): ");

      white();
      scanf("%d",&answer);
      printf("-----------------------------------------------------------------------------------------------\n");
      if (answer==1){
      Deleteath(etablissment2,tabjru,tabuniv,tabnombre,&fin_tab);}}
      break;




        case 7:
            /*Process option 7*/
                if (stat==0){
                        red();
                 printf("Attention: Please create Tabjru first.\n");
                blue();}

                else {blue();
       printf("\t\t        ______________________________________________________________________\n");
       printf("\t\t\        |                          7/-Delath:                                 |\n");
       printf("\t\t\t| This function is designed to eliminate a disqualified or injured    |\n");
       printf("\t\t\t| athlete, identified by their unique identifier, institution number, |\n");
       printf("\t\t\t| and event number.                                                   |\n");
       printf("\t\t\t|_____________________________________________________________________|\n\n");

     printf("                           ____________________        ____________________            _________________                \n");
    printf("                          |    |    |          |       |    |    |          |          |   |   |         |               \n");
    printf("                HEAD--->  |    |    |          |       |Num |name|Familyname|     |--->|   |   |         |------[        \n");
    printf("                          |____|___ |__________|       |____|___ |__________|     |    |___|___|_________|               \n");
    printf("                                    |                                             |                                        \n");
    printf("                                    |                                             |                                        \n");
    printf("                                    |---------------------------------------------|\n");
    printf("                                                                                                                            \n");

            white();
             printf("\n==============================The information needed:======================================\n");

            blue();
             printf("->The number of the athlete(max13500):\n");

           white();
            scanf("%d",&number);

            blue();
            printf("->The number of the university:\n");

            white();
            scanf("%d",&univ);

            blue();
            printf("->The number of the event:\n");

            white();
            scanf("%d",&epr);

             printf("============================================================================================\n");

             red();

             /* Confirmation of deletion */

      printf("Could you affirm your intention to delete?\n");
      printf("0-> NO.\n");
      printf("1-> YES.\n");
      printf("Your answer(0,1): ");

      white();
      scanf("%d",&answer);
            printf("---------------------------------------------------------------------------------------------\n");
      if(answer==1){
             Delath(number,univ,epr,tabjru,tabnombre,&fin_tab);}};
            break;


        case 8:

            /*Process option 8*/
             if (stat==0){
                  red();
                 printf("Attention: Please create Tabjru first.\n");
                blue();}
                else {blue();

            printf("\t\t        ___________________________________________________________________________\n");
    printf("\t\t\        |                               8/- Delemptylines:                        |\n");
   printf("\t\t\t|       This function removes all events that have not received any       |\n");
   printf("\t\t\t|                                 registrations.                          |\n");
    printf("\t\t\t|_________________________________________________________________________|\n\n");
     printf("     TABJRU     ------------------------------------------------------------------------\n");
    gray();
    printf("                |NULL |NULL |NULL |NULL |NULL |NULL |NULL |NULL |NULL |NULL |NULL |NULL |  To delete \n");
    blue();
    printf("                -------------------------------------------------------------------------\n");
    printf("                |     |     |     |NULL |     |     |     |     |NULL |     |     |     |  To not delete\n");
   printf("                -------------------------------------------------------------------------\n");

            blue();
         delemptylines(tabjru,tabepreuve);};
            break;
        case 9:
           red();
            printf("Exiting...");
           gray();
            break;

        default:
            printf("Invalid choice.\n");
            break;
         }

            if (choice != numOptions-1) {
                gray();
                printf("\nPress any key to return to the menu...");
                getch();
            }else if (choice == 9) {
                printf("\nPress Enter to exit...");
                while (getch() != KEY_ENTER); /* Wait for Enter key press*/
                arrow = -2; /* Force exit the loop*/
        }}

    } while (arrow != -2);


    return 0;
    };