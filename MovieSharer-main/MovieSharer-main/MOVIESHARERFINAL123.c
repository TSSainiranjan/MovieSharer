#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
void reccomend ();
void func_register ();
void new_user();
void old_user();
void sharer();
void custom();
void genrelang();
void rating();
int input(char arr[30][50], int *p);
int logic(char array[30][50], char pick[30][50],int selmo[70],int dl,int size,int *p);
void output(int post,int selmo[post],char arr[30][50],int dl);
//creating a structure for storing values of different datatypes
struct login
{
  int randomvalue;  
  int choice;
  char *moviedataset[10];
  char uname[50];
  int pwd;
  int ans;
  char QRcode[20];
  char array[30][50],pick[30][50];//change the abstraction use files
  char username[15];
  char password[12];
}*l1;
int main()
{
    int choice;
    //asking user whether he/she is old/new user
    printf("Press 1 if you are a old user and 2 if you are a new user.\nEnter your choice:");
    scanf("%d",&choice);
    if(choice==1)
    old_user();//goes to old user function
    else if(choice==2)
    new_user();//goes to new user function
    else
    printf("You have entered a wrong choice!!!");
    return 0;
}
void reccomend ()
{
    l1=(struct login*)malloc(sizeof(struct login));
  srand ( time(NULL) );
 
  l1->moviedataset[0] = "Mission Impossible";
  l1->moviedataset[1] = "Mission Impossible 2";
  l1->moviedataset[2] = "mission impossible 4";
  l1->moviedataset[3] = "Mission Impossible 5";
  l1->moviedataset[4] = "Conjuring 2";
  l1->moviedataset[5] = "Free Guy";
  l1->moviedataset[6] = "Dead Silence";
  l1->moviedataset[7] = "Inside Out";
  l1->moviedataset[8] = "Bourne Identity";
  l1->moviedataset[9] = "Mission Impossible 6";
  do
    {
      l1->randomvalue = rand()%10;
      printf("%s\n", l1->moviedataset[l1->randomvalue]);
      printf("Would you like to watch this movie[1 for Yes/0 for No]\n");
      scanf("%d", &l1->choice);
    }  while(l1->choice == 0);
    sharer();
}
void func_register ()//we use switch case to call functions based on cases in a sentinel loop, we added a log out function
{
  int ch,choice;
  l1=(struct login*)malloc(sizeof(struct login));
  l1->ans = 0;
  while (l1->ans != 5)
    {
      printf("\nPress 1 to look at movies by genre/language\n Press 2 to look at movies by ratings\n Press 3 to recieve a random reccomendation\n Press 4 to custom select\n Press 5 to Logout\n");
      scanf("%d",&l1->ans);
      switch(l1->ans){
        case 1: genrelang();
                break;
        case 2: rating();
                break;
        case 3: reccomend();
                break;
        case 4: custom();
                break;
        case 5: printf("You have been logged out!");
                break;
        default: printf("INVALID CHOICE");
                break;
      }
      }
    
printf("\nPress 1 if you want to login again and any other key if you wish to leave moviesharer:");
    scanf("%d",&choice);
    if(choice==1)
    {
    	//asking the user whether he/she is a old/new user
    	printf("Press 1 if you are a old user and 2 if you are a new user.\nEnter your choice:");
    	scanf("%d",&ch);
    	if(ch==1)
    	old_user();
    	else if(ch==2)
    	new_user();
    	else
    	printf("Invalid choice!");
	}
	else
	printf("Thank you, visit again!!");

}    
void sharer() {
	l1=(struct login*)malloc(sizeof(struct login));//the memory is allocated to l1
	int x=10;	
	printf("Scan QRcode: 123xyz\n"); //as we cannot implement an actual QR code;
	while (x!=0)
	{
	printf("Enter the QRcode: ");
	scanf("%s",l1->QRcode);	
	if (strcmp(l1->QRcode,"123xyz")==0)//comparing both the strings
	{
		printf("QRcode scanned successfully!\n");
		printf("The movie is shared via wifi-direct :)");
		x=0;
    }
    else
    {
        printf("Invalid QRcode :(");       
    }
	}
}



void old_user()
{
    l1=(struct login*)malloc(sizeof(struct login));//the memory is allocated to l1
    
	//asking the user to enter username and password
	printf("Enter your username:\n");
    scanf("%s",&l1->username); //accessing the pointer through "->"
 
    printf("Enter your password:\n");
    scanf("%s",&l1->password);
 
 //comparing the strings of both username and password
    if(strcmp(l1->username,"sainiranjan")==0){
        if(strcmp(l1->password,"123")==0){
        printf("\nWelcome.Login Success!");
        func_register(); //goes to register function
        }
        else if(strcmp(l1->password,"123")!=0){
            printf("WRONG PASSWORD TRY AGAIN!!!");
            old_user(); //if the password is wrong, it goes back to the old user function again
        }
}
    else if(strcmp(l1->username,"sainiranjan")!=0)
    {
 
 //the same process continues as the previous one
    if(strcmp(l1->username,"greeshmanth")==0){
        if(strcmp(l1->password,"456")==0){ 
        printf("\nWelcome.Login Success!");
        func_register();
        }
        else if(strcmp(l1->password,"123")!=0){
            printf("WRONG PASSWORD TRY AGAIN!!!");
            old_user();
        }
}
    else if(strcmp(l1->username,"greeshmanth")!=0){ 
    if(strcmp(l1->username,"pradyumna")==0){
        if(strcmp(l1->password,"789")==0){
        printf("\nWelcome.Login Success!");
        func_register();
        }
        else if(strcmp(l1->password,"123")!=0){
            printf("WRONG PASSWORD TRY AGAIN!!!");
            old_user();
        }
}
    else if(strcmp(l1->username,"pradyumna")!=0){
    if(strcmp(l1->username,"sravya")==0){
        if(strcmp(l1->password,"012")==0){
        printf("\nWelcome.Login Success!");
        func_register();
	}
    else if(strcmp(l1->password,"123")!=0){
            printf("WRONG PASSWORD TRY AGAIN!!!\n");
            old_user();
        }
}
//if the inputed username is not matching the available usernames, it shows "invalid"
    else if(strcmp(l1->username,"sravya")!=0){
        printf("INVALID CREDENTIALS"); 
    }
}
    }
    }
     
}
void new_user()
{
    l1=(struct login*)malloc(sizeof(struct login));
  printf("Please enter your username\n");
  scanf("%s", l1->uname);
  printf("Hello %s!\n", l1->uname);
  printf("please enter your password(integer):\n");
  scanf("%d",&l1->pwd);
  printf("Thanks you have successfully registered with us!\n");
  func_register();
}
void rating()
{
    struct Sort
{
    char *name;
    int id;
    float srratings, grratings, saratings, prratings;
};
    struct Sort arr[20], temp;
    int i, j, n;
    char uname[50];
    printf("Whose top rated movies do you want to see?");
    scanf("%s",uname);
    printf("Enter number of movies: ");
    scanf("%d", &n);
    // struct Sort arr[n];
    //structure declaration
    arr[0].id = 1;
    arr[0].name = "Home Alone";
    arr[0].srratings = 3.6;
    arr[0].grratings = 4.5;
    arr[0].saratings = 2.7;
    arr[0].prratings = 3.3;

    arr[1].id = 2;
    arr[1].name = "Mr. Bean's Holiday";
    arr[1].srratings = 3.8;
    arr[1].grratings = 4.8;
    arr[1].saratings = 2.0;
    arr[1].prratings = 3.2;

    arr[2].id = 3;
    arr[2].name = "Baby's Day Out";
    arr[2].srratings = 3.3;
    arr[2].grratings = 4.1;
    arr[2].saratings = 1.6;
    arr[2].prratings = 2.7;

    arr[3].id = 4;
    arr[3].name = "Monty Python's Holy Grail";
    arr[3].srratings = 2.6;
    arr[3].grratings = 4.9;
    arr[3].saratings = 4.4;
    arr[3].prratings = 3.7;

    arr[4].id = 5;
    arr[4].name = "The Dictator";
    arr[4].srratings = 1.7;
    arr[4].grratings = 1.8;
    arr[4].saratings = 4.8;
    arr[4].prratings = 1.3;

    arr[5].id = 6;
    arr[5].name = "Inferno";
    arr[5].srratings = 4.5;
    arr[5].grratings = 2.5;
    arr[5].saratings = 1.3;
    arr[5].prratings = 4.6;

    arr[6].id = 7;
    arr[6].name = "The Da Vinci Code";
    arr[6].srratings = 3.6;
    arr[6].grratings = 4.5;
    arr[6].saratings = 4.9;
    arr[6].prratings = 3.3;

    arr[7].id = 8;
    arr[7].name = "Angels and Demons";
    arr[7].srratings = 2.6;
    arr[7].grratings = 3.4;
    arr[7].saratings = 2.9;
    arr[7].prratings = 3.2;

    arr[8].id = 9;
    arr[8].name = "Coco";
    arr[8].srratings = 1.7;
    arr[8].grratings = 3.0;
    arr[8].saratings = 1.4;
    arr[8].prratings = 4.8;

    arr[9].id = 10;
    arr[9].name = "The Lion King";
    arr[9].srratings = 2.9;
    arr[9].grratings = 4.5;
    arr[9].saratings = 2.3;
    arr[9].prratings = 1.0;

    arr[10].id = 11;
    arr[10].name = "Spider-man-Into the Spider-verse";
    arr[10].srratings = 2.8;
    arr[10].grratings = 1.3;
    arr[10].saratings = 3.9;
    arr[10].prratings = 3.7;

    arr[11].id = 12;
    arr[11].name = "Rush Hour";
    arr[11].srratings = 1.3;
    arr[11].grratings = 2.0;
    arr[11].saratings = 4.8;
    arr[11].prratings = 4.9;

    arr[12].id = 13;
    arr[12].name = "Mission Impossible";
    arr[12].srratings = 4.3;
    arr[12].grratings = 2.9;
    arr[12].saratings = 3.1;
    arr[12].prratings = 2.7;

    arr[13].id = 14;
    arr[13].name = "The Spy Next Door";
    arr[13].srratings = 3.6;
    arr[13].grratings = 4.5;
    arr[13].saratings = 2.7;
    arr[13].prratings = 3.3;

    arr[14].id = 15;
    arr[14].name = "Arrival";
    arr[14].srratings = 4.8;
    arr[14].grratings = 2.7;
    arr[14].saratings = 4.1;
    arr[14].prratings = 5.0;

    arr[15].id = 16;
    arr[15].name = "Inception";
    arr[15].srratings = 4.6;
    arr[15].grratings = 4.7;
    arr[15].saratings = 2.7;
    arr[15].prratings = 4.5;

    arr[16].id = 17;
    arr[16].name = "Interstellar";
    arr[16].srratings = 5.0;
    arr[16].grratings = 2.1;
    arr[16].saratings = 1.2;
    arr[16].prratings = 2.6;
    if (strcmp(uname, "sainiranjan") == 0)
    {
        for (i = 0; i < n - 1; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (arr[i].saratings < arr[j].saratings) //bubble sort algorithm for each persons ratings
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        printf("\n\n%s's top %d movies\n",uname, n);
        for (i = 0; i < n; i++)
        {
            printf("%s, Ratings = %0.1f \n", arr[i].name, arr[i].saratings);
        }
    }
    else if (strcmp(uname, "sravya") == 0)
    {
        for (i = 0; i < n - 1; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (arr[i].srratings < arr[j].srratings)
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        printf("\n\n%s's top %d movies\n",uname, n);
        for (i = 0; i < n; i++)
        {
            printf("%s, Ratings = %0.1f \n", arr[i].name, arr[i].srratings);
        }
    }
    else if (strcmp(uname, "pradyumna") == 0)
    {
        for (i = 0; i < n - 1; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (arr[i].prratings < arr[j].prratings)
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        printf("\n\n%s's top %d movies\n",uname, n);
        for (i = 0; i < n; i++)
        {
            printf("%s, Ratings = %0.1f \n", arr[i].name, arr[i].prratings);
        }
    }
    else if (strcmp(uname, "greeshmanth") == 0)
    {
        for (i = 0; i < n - 1; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (arr[i].grratings < arr[j].grratings)
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        printf("\n\n%s's top %d movies\n",uname, n);
        for (i = 0; i < n; i++)
        {
            printf("%s, Ratings = %0.1f \n", arr[i].name, arr[i].grratings);
        }
    }
    else{
        printf("Username not found");//in case a new user selects rating function
    }
}
void genrelang()
{
    struct Sort { 
    char* name; 
    int id; 
    char* genre;
    char* language; 
}; 
    struct Sort arr[20] ,temp;
    int i , j,n,m;
    char uname[50];
    printf("Press 1 For Genre\nPress 2 For Language\n");
    scanf("%d",&m);
    printf("Enter The Number Of Movies: ");
    scanf("%d",&n);
    //struct Sort arr[n];
    
    arr[0].id = 1; 
    arr[0].name = "Chhichhore"; 
    arr[0].genre = "comedy"; 
    arr[0].language = "hindi";
    
    arr[1].id = 2;
    arr[1].name = "Bangalore Days"; 
    arr[1].genre = "comedy"; 
    arr[1].language = "malayalam";
    
    arr[2].id = 3; 
    arr[2].name = "Hero"; 
    arr[2].genre = "comedy"; 
    arr[2].language = "telugu";
    
    arr[3].id = 4; 
    arr[3].name = "Don"; 
    arr[3].genre = "comedy"; 
    arr[3].language = "tamil";
    
    arr[4].id = 5; 
    arr[4].name = "Bahubali"; 
    arr[4].genre = "action"; 
    arr[4].language = "telugu";
    
    arr[5].id = 6; 
    arr[5].name = "Top Gun"; 
    arr[5].genre = "action"; 
    arr[5].language = "english";
    
    arr[6].id = 7; 
    arr[6].name = "Twenty Four"; 
    arr[6].genre = "science fiction"; 
    arr[6].language = "tamil";
    
    arr[7].id = 8; 
    arr[7].name = "The Big Bang Theory"; 
    arr[7].genre = "science fiction"; 
    arr[7].language = "english";
    
    arr[8].id = 9; 
    arr[8].name = "Mission Impossible"; 
    arr[8].genre = "thriller"; 
    arr[8].language = "english";
    
    arr[9].id = 10; 
    arr[9].name = "John Wick"; 
    arr[9].genre = "thriller"; 
    arr[9].language = "english";
    
 switch(m){
    case 1: printf("Enter The Genre : ");
    scanf("%s",uname);
    for(i=0;i<9;i++)
  {
  if (strcmp(uname,arr[i].genre)==0 && n)
   {
    printf("%s\n",arr[i].name);
    n--;
  }
 }
 break;
    case 2: printf("Enter the Language : ");
    scanf("%s",uname);
    for(i=0;i<9;i++)
  {
  if (strcmp(uname,arr[i].language)==0 && n)
   {
    printf("%s\n",arr[i].name);
    n--;
  }
 }
    break;
 }    
}
 
int input(char arr[30][50], int *p)
{
    int i = 0;
    char x = 'c';
    while(x == 'c')
    {
        printf("please enter the movie name : \n");
        scanf("%s", arr[i]);
        i++;
        strcpy(arr[i],";");
        i++;
        //printf("%c",x);
        while(x == 'c')
        {
            printf("enter genre : \n");
            scanf("%s", arr[i]);
            i = i + 1;
            printf("Type c if you want to add more genres, else type e : ");
            scanf("\n%c", &x);
            if(x != 'e')
            {
                strcpy(arr[i],"@");
                i++;
            }
            //printf("%c",x);
        }
        printf("Type c if you wish to add more movies, else type e : ");
        scanf("\n%c",&x);
    }
    *p = i ;
}


int logic(char arr[30][50], char pick[30][50],int selmo[70],int dl,int size,int *p)
{
	int q, w, sm, post;
	sm = 0 ;
	for(q=0; q<=dl-1 ; q++)
	{
		for(w=0; w<=size-1 ; w++)
		{
			if(strcmp(pick[q],arr[w]) == 0)
			{
				post = w;
				while(!(strcmp(arr[w],";")==0))
				{
					w= w-1;
				}
				// after while loop gets completed, the value of w is the value of the index of the semicolon
				w = w - 1;
				// after the operation the value of w is the value of movie index
				// w is the index of the row which is the index of the movie
				selmo[sm] = w;
				//selmo stores the value of the index of the movie
				//the values are repeated if the movie genres match multiple times with the user preference.
				//printf("%d\n",selmo[sm]);
				sm = sm + 1;
				w = post;
			}
		}
	}
	*p = sm;
	//we use pointers so that when the function is over, the variable in which we are storing the value doesn't get destroyed
}

void output(int post,int selmo[post],char arr[30][50],int dl)
{
	int sm, q;
	float to,f;
	for(sm = 0 ; sm <=post-1 ; sm++ )
	{
	   // printf("_");
		f = 1;
		// f= 1 is declared because
		for(q = sm+1 ; q<=post-1 ; q++)
		{
	    //printf("=======================");
			if(selmo[sm] == selmo[q])
			{
	  //  printf("+++++++++++++++++++");
				f = f+1;
				
				selmo[q] = -4;
			}
		}
		if(selmo[sm] != -4)
		{
	    to = f/dl;
			printf("%s = %f%% \n",arr[selmo[sm]],(f/dl)*100);
		}
	}
}
void custom()
{
    int j,i,post,selmo[70];
    int size;
    char arr[30][50],pick[30][50];
     input(arr, &size);
    
   printf("how many genres would like to see in this movie : ");
    int dl;
    scanf("%d",&dl);
    
    printf("What combination of genres would you like to watch ? \n");
    for(i = 0;i<=dl-1;i++)
    {
        scanf("%s",pick[i]); // pick is an array of genre preference given by the user
    }
    int sm = 0 ;
    logic(arr,pick,selmo,dl,size,&post);
    printf("The following movies have matched your preference of genres:\n");
    output(post,selmo,arr,dl);
}