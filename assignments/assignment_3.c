#include <stdio.h>


struct mission{
    char *_teendo,*_idopont;
};

int isValidTime(char* s){
    int i = 0;
    while(s[i]!='\0') ++i;
    if(i!=5) return 1;

    if(!((s[0]>=48 && s[0]<=50)  &&
         (s[1]>=48 && s[1]<=57)  &&
         (s[2]== ':')            &&
         (s[3]>=48 && s[3]<=53)  &&
         (s[4]>=48 && s[4]<=57)))
         return 1;
    if(s[0]==50 && !(s[1]>=48 && s[1]<=51)) return 1;
    
    return 0;
    
}
int isValidTodo(char* s){
    int i  =0;
    // vegig iteralunk a string elemein, amíg el nem érjük a \0 karaktert,
    // ha az egyik karakter ascii kódja nem eleme a a-zA-Z tömböknek akkor kilépünk
    while(s[i]!='\0'){
        if(!((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122))) return 1;
        ++i;
    }
    return 0;
}

int main(int argc, char **argv){

    if(argc<2 || argc%2==0){
        printf("Hibás bemenet!\n");
        return -1;
    }
    
    struct mission missions[(argc-1)/2];
    int j = 0;
    for(int i = 1;i<argc;++i){

        char* idopont = argv[i];
        i++;    
        char* teendo = argv[i];
    
        if( isValidTime(idopont) || isValidTodo(teendo)){
            printf("Hibas bemenet!\n");
        }else{  
            missions[j]._idopont = idopont;
            missions[j]._teendo = teendo;
            ++j;
        }
    }

    // fájlba írás
    FILE *f = fopen("todolist.txt","w");
    for(unsigned int i = 0;i<(sizeof missions / sizeof missions[0]);++i){
        fprintf(f,"%s - %s\n",missions[i]._idopont,missions[i]._teendo);
    }
    fclose(f);   
}
