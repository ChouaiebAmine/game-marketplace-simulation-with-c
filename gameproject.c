#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Date{
    int day;
    int month;        
    int year;
    }date;
struct game{
    float price;
    char name[50];        
    date release;
    char* description;
    char* genre;
    int rate;
    };
struct user{
    char name[50];
    char password[50];
    int tag;
    float balance;
    
};

//best rated games function
void display_rated(struct game T[50]){
    struct game T2[10];
    struct game tmp[1];
    int j=0;
    int k=0;
    
    for(int i=0;i<10;i++){
        T2[i].rate=T[i].rate;
        strcpy(T2[i].name,T[i].name);
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(T2[j].rate<T2[i].rate){
                tmp[k]=T2[i];
                T2[i]=T2[j];
                T2[j]=tmp[k];
            }
        }
    }
    for(int i=0;i<4;i++){
        printf("|%s|rating:%d \t",T2[i].name,T2[i].rate);
    }
    printf("\n");
    
}
//end

//latest games function
void new(struct game T[50]){
    struct game T2[10];
    struct game tmp[1];
    int k=0;
    int j=0;
    for(int i=0;i<10;i++){
        T2[i]=T[i];
    }
    for(int i=0;i<10;i++){
        for(j=0;j<10;j++)
        {
            if(T2[j].release.year<T2[i].release.year){
                tmp[k]=T2[i];
                T2[i]=T2[j];
                T2[j]=tmp[k];
            }
            else if(T2[j].release.year==T2[i].release.year)
            {

                if(T2[j].release.month>T2[i].release.month)
                {
                    tmp[k]=T2[i];
                    T2[i]=T2[j];
                    T2[j]=tmp[k];
                }
                else if(T2[j].release.month==T2[i].release.month)
                {
                    if(T2[j].release.day<T2[i].release.day)
                    {
                        tmp[k]=T2[i];
                        T2[i]=T2[j];
                        T2[j]=tmp[k];
                    }
                }
            }
        }

    }
    for(int i=0;i<4;i++){
        printf("|%s|release date:%d/%d/%d\t",T2[i].name,T2[i].release.day,T2[i].release.month,T2[i].release.year);
    }
    printf("\n");
}
//end
//free games function
void display_free(struct game T[50]){
    struct game T2[10];
    int j=0;
    for(int i=0;i<10;i++){
        if(T[i].price==0){
            T2[j]=T[i];
            j++;
        }
    }
    for(int i=0;i<4;i++){
        printf("|%s| FREE      \t",T2[i].name);
    }
    printf("\n");
}
//end


void sign_up(struct user lib[10],int position){
    struct user new;
    printf("enter username:\n");
    scanf("%s",new.name);
    printf("enter password:\n");
    scanf("%s",new.password);
    printf("enter balance:\n");
    scanf("%f",&new.balance);
    strcpy(lib[position].name,new.name);
    strcpy(lib[position].password,new.password);
    lib[position].balance=new.balance;
    lib[position].tag= position+1;
}
void main()
{
    
//var
    char* games[]={"Elden Ring","Minecraft:Java Edition","Forza horizon 5","FIFA23","Candy Crush Saga","Halo infinite","Red Dead Redemeption 2","God Of War","Apex Legends","Rocket League"};
    int i;
    int n=0;
    int op; 
    struct game T[50];
//end

//0:elden,1:mine,2:forza,3:fifa,4:candy,5:Halo infinite,6:RDR2,7:GOW,8:apex

//name of the games
   for (i=0;i<10;i++)
   {
    strcpy(T[i].name,games[i]);
   }
    
//end

//date of the games
    T[0].release.day=25;
    T[0].release.month=2;
    T[0].release.year=2022;

    T[1].release.day=18;
    T[1].release.month=11;
    T[1].release.year=2011;

    T[2].release.day=5;
    T[2].release.month=9;
    T[2].release.year=2021; 

    T[3].release.day=27;
    T[3].release.month=9;
    T[3].release.year=2022;

    T[4].release.day=12;
    T[4].release.month=4;
    T[4].release.year=2012;

    T[5].release.day=15;
    T[5].release.month=11;
    T[5].release.year=2021;

    T[6].release.day=26;
    T[6].release.month=10;
    T[6].release.year=2018;

    T[7].release.day=20;
    T[7].release.month=4;
    T[7].release.year=2018;

    T[8].release.day=4;
    T[8].release.month=2;
    T[8].release.year=2019;

    T[9].release.day=7;
    T[9].release.month=7;
    T[9].release.year=2015;
//end      
    
//price of the games
    T[0].price = 59.99;
    T[1].price = 26.95;
    T[2].price = 59.55;
    T[3].price = 99.99;
    T[4].price = 0;
    T[5].price = 0;
    T[6].price = 59.99;
    T[7].price = 49.99;
    T[8].price = 0;
    T[9].price = 0;
//end

//description of the games
    T[0].description="Elden Ring is an action role-playing game played in a third person perspective,with gameplay \nfocusing on combat and exploration. It features elements similar to those found in other games developed by FromSoftware, such as the \nDark Souls series, Bloodborne, and Sekiro: Shadows Die Twice.\n";
    T[1].description="In Minecraft, players explore a blocky, procedurally generated, three-dimensional world \nwith virtually infinite terrain and may discover and extract raw materials, craft tools and items, and build structures, earthworks, and machines.\n";
    T[2].description="Forza Horizon 5 is a racing video game set in an open world environment based \nin a fictional representation of Mexico. The game has the largest map \nin the entire Forza Horizon series";
    T[3].description="FIFA 23 features both men's and women's World Cup game modes, replicating the 2022 \nFIFA World Cup and the 2023 FIFA Women's World Cup.\n";
    T[4].description="Candy Crush Saga is a match three game, where the core gameplay is \nbased on swapping two adjacent candies among several on the gameboard \nto make a row or column of at least three matching-colored candies.";
    T[5].description="Halo Infinite is a first-person shooter available on Microsoft Windows, Xbox One, Xbox Series X and Series S";
    T[6].description="After a robbery goes badly wrong in the western town of Blackwater, Arthur Morgan and the Van der Linde gang are forced to flee. With federal agents and the best bounty hunters in the nation massing on their heels";
    T[7].description="His vengeance against the Gods of Olympus years behind him, Kratos now lives as a man in the realm of Norse Gods and monsters";
    T[8].description="Apex Legends is an online multiplayer battle royale game featuring squads of three players using pre-made characters with distinctive abilities, called Legends, similar to those of hero shooters.";
    T[9].description="Rocket League is a fantastical sport-based video game, developed by Psyonix (it's “soccer with cars”). It features a competitive game mode based on teamwork and outmaneuvering opponents";
//end

//rate of the games
    T[0].rate=94;
    T[1].rate=93;
    T[2].rate=92;
    T[3].rate=77;
    T[4].rate=79;
    T[5].rate=80;
    T[6].rate=97;
    T[7].rate=93;
    T[8].rate=88;
    T[9].rate=86;
//end

//Var2
    int log;
    struct user lib[10];
    struct user input;
    struct game collection[10];
    int check=1,check2=1;
    int pos=0;
    int check3=0;
    int change;
    int position=0;
    
    int reload2=0;
    int off2=1;
    int reload=0;
    int h=0;
    char* word;
    int sim[6];
    int off=1;
    int bmenu=1;
    int buyy=1;
    int bought=0;
    int coll=1;
    char* claim= (char*)malloc(10*sizeof(char));
    char* search= (char*)malloc(100*sizeof(char));
//end var2

//login
    while(off2 != 0){
        do{
            check=1;
            check2=1;
            check3=0;
            printf("1>login\n2>sign up\n3>exit\n");
            scanf("%d",&log);
            if(log==3){
                off2=0;
            }
            if ((log != 1) && (log != 2) && (log != 3)) {
                printf("Invalid input. Please enter 1,2 or 3.\n");
            }
        }while((log !=  1) && (log != 2) && (log != 3));
        if(off2 != 0){
            if(log == 1){
                off=1;
                while((check !=0) &&(check2 !=0))
                {
                    printf("username:\n");
                    scanf("%s",input.name);
                    printf("password:\n");
                    scanf("%s",input.password);
                    check3++;
                    for(i=0;i<10;i++)
                    {
                        check=strcmp(input.name,lib[i].name);
                        check2=strcmp(input.password,lib[i].password);
                        if ((check ==0 ) && (check2==0)){
                            pos=i;
                            ;
                            break;
                        }
                    }
                    if (check3 >=3){
                        printf("enter 2 to signup:\n");
                        scanf("%d",&change);
                        if (change==2){
                            check=0;
                            check2=0;
                            sign_up(lib,position);
                            position++;
                            
                        }
                    }
                }
            }
            
            else if(log==2){
                sign_up(lib,position);
                position++;
                off=1;
            }
            
            for(i=0;i<10;i++){
                if(i == position){
                    printf("\t \t \t \e[1m WELCOME %s#%d \t your balance: \e[m %.2f $ \n",lib[pos].name,lib[pos].tag,lib[pos].balance);
                }
            }
        //end login
            
            while(off != 0){
        //menu
                reload++;
                if (reload>0){
                    printf("Acc:%s#%d \t \t balance:%.2f$\n",lib[pos].name,lib[pos].tag,lib[pos].balance);
                }
                printf("\e[1m MOST RATED GAMES: \e[m\n");
                display_rated(T);
                printf("\n \n");
                printf("\e[1m LATEST PC GAMES: \e[m\n"); 
                new(T);
                printf("\n \n");
                printf("\e[1m TOP FREE GAMES: \e[m \n");
                display_free(T);
                
                printf("\n \n "); 
        //end menu
        
                printf("Enter 'off' to sign off:\n");
                printf("Search games:\n");
                scanf("%s",search);
                off=strcmp(search,"off");
                if(off != 0)
                {
                    for(i=0;i<10;i++)
                    {
                    sim[i]=0;
                    h=strlen(T[i].name);
                    word=T[i].name;
                    for(int j=0;j<h;j++)
                    {
                        if (search[j]==word[j])
                        {
                            sim[i]++;
                        }
                    }
                    
                    }
                
                    printf("\e[1m you may be searching for these: \e[m \n");
                    for(i=0;i<10;i++){
                        if (sim[i]>=2){
                            printf("%d>%s\n",i+1,T[i].name);
                        }
                    }
                    printf("enter the number to see the details of the game:\n");
                    scanf("%d",&op);
                    printf("\n");
                    for(i=0;i<10;i++){
                        if(op==i+1)
                        {
                            
                            printf("\e[1m Name: \e[m <%s> \n",T[i].name);
                            printf("\e[1m Release Date:  \e[m %d/%d/%d\n",T[i].release.day,T[i].release.month,T[i].release.year);
                            printf("\e[1m Cost: \e[m %.2f\n",T[i].price);
                            printf("\e[1m Rating: \e[m %d \n",T[i].rate);
                            printf("\n");
                            printf("\e[1m Description: \e[m %s \n",T[i].description);
                            printf("buy item by inserting 'claim':\n");
                            printf("back to menu (0):\n");
                            printf("see your collection by inserting collection:\n");
                            scanf("%s",claim);
                            buyy=strcmp(claim,"claim");
                            bmenu=strcmp(claim,"0");
                            coll=strcmp(claim,"collection");
                            if( buyy==0 ){
                                if(lib[pos].balance>=T[i].price){
                                    lib[pos].balance= lib[pos].balance - T[i].price;
                                    strcpy(collection[bought].name,T[i].name);
                                    strcpy(T[i].name,games[i]);
                                    bought++;
                                    
                                }
                                else{
                                    printf(" the transaction is declined(recharge)\n");
                                }
                            }
                            else if( bmenu==0 ){
                                off=1;
                            }
                            else if(coll==0){
                                printf("\e[1m Your Collection:\e[m\n");
                                for(i=0;i<bought;i++){
                                    printf("%d> %s\n",i+1,collection[i].name);
                                    
                                }
                            }
                        printf("-------------------------------------------------------------------------\n");  
                        }
                    }
                }

            }
                
        }

    }

}