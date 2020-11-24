#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Person {
    char _name[30];
    unsigned _age;
    char _job[30];
};

void fail(void) { fprintf(stderr,"Memory could not be allocated"); exit(EXIT_FAILURE); }
void exitLoop(int *f){ *f=0; }

void addPerson(struct Person **P,unsigned *size, unsigned *count){

    char name[30], age[4], job[30];
    scanf("%s",name);
    scanf("%s",age);
    scanf("%s",job);

    if((strcmp(name,"changed"))==0 && (strcmp(age,"my"))==0 && (strcmp(job,"mind"))==0) return;

    while(strlen(name) > 30 || atoi(age) > 110 || atoi(age)==0 || strlen(job) > 30){
        fprintf(stderr,"You probably mistyped some data. Please repeat it!\n");
        scanf("%s",name);scanf("%s",age);scanf("%s",job);
    }
    if((*count)%5==0 && (*count)>5){ 
        (*size)+=5;
        struct Person *tmp = (struct Person*)realloc(*P,(*size)*sizeof(struct Person));
        if(tmp!=NULL){
            *P=tmp;
        }
    }
    ++(*count);
    strcpy((*P)[*count-1]._name,name);
    (*P)[*count-1]._age=atoi(age);
    strcpy((*P)[*count-1]._job,job);
}
// void deletePerson(struct Person **P,unsigned *size, unsigned *count){
//     char name[30];
//     scanf("%s",name);
//     while(strlen(name) > 30){
//         printf("That name is waay too long... Try again!\n");
//     }
    
// }

void listPeople(struct Person *P,unsigned count){
    if(count>0){

        printf("{\n");
        for(int i = 0;i<count;++i)
            if(i==count-1) printf("    { Name: \"%s\", \tAge: %d, Job: \"%s\" }\n",P[i]._name,P[i]._age,P[i]._job);
            else printf("    { Name: \"%s\", \tAge: %d, Job: \"%s\" },\n",P[i]._name,P[i]._age,P[i]._job);
        printf("}\n");
    }
}

// This function is needed because the scanf("%s",command) would read multiple string because it does not ignore whitespaces 
// char * readCommand(){
//     char  *line, character;
//     int c = 0;
//     do{
//         scanf("%c",&character)   ;
//            line[c]   = character;
//            c++;
//     } while(character != '\n');
//     line[--c] = '\0';
//     return line;
// }

// GLOBAL VARIABLES //
struct Person *People;
unsigned arraySize,numberOfPeople;

// MAIN //
int main(){

    arraySize =10;
    numberOfPeople = 0;
    People = (struct Person*)calloc(arraySize,sizeof(struct Person));

    if(People==NULL)fail();

    
    char* command;
    int flag = 1;

    while(flag){
        
        scanf("%s",command);
        // command=readCommand();
        
        if(strcmp(command,"x")==0){
            exitLoop(&flag);
        }else if(strcmp(command,"a")==0){
            addPerson(&People,&arraySize,&numberOfPeople);
        }
        // else if(strcmp(command,"d")==0){
        //     // deletePerson(People,arraySize,numberOfPeople);
        // }
        else if(strcmp(command,"c")==0){
            system("clear");
        }
        else if(strcmp(command,"l")==0){
            listPeople(People,numberOfPeople);
        }else {
            //d - Delete the last person\n
            fprintf(stderr,"ERROR! Please type a valid character!\nx - Exit the program\na - Add a person\nl - List the people\nc - Clear terminal\n");     
        }
        
    }

    free(People);
    People=NULL;
    return EXIT_SUCCESS;
}