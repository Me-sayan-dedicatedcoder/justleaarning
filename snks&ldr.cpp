#include<iostream>
#include<cstdlib>
# include <string.h>
# include <conio.h>
#include<time.h>
using namespace std;
class Snke_ldr_Hangman{
	private:
		int p1,p2;
		int s1,s2;
		//defines positions of snake mouth
		int snke_hd[10]={12,21,33,39,54,67,71,78,92,98};
		//defines positions of snake tail
		int snke_fl[10]={3,9,6,23,15,52,18,65,11,50};
		//defines positions of Ladder's starting lower end
		int ldr_tl[10]={8,14,28,30,32,38,53,64,72,80};
		//defines positions of Ladder's upper end
		int ldr_up[10]={22,55,91,41,99,74,90,96,79,93};
		int ch;
		const int MAXLENGTH=80;
		const int MAX_TRIES=5;
		const int MAXROW=7;
	public: 
		//To get input from users
		void getData();
		void pl_vs_cmp();
		void multiplr_pl(); 
		void Hangman();
		int letterFill (char, char[], char[]);
		void initUnknown (char[], char[]);
		
};



void Snke_ldr_Hangman::getData(){
	cout<<"\a";
	cout<<".................................WELCOME TO THE GAME OF SNAKES & LADDERS................................"<<endl<<endl;
	p1=0;
	p2=0;
	
	cout<<"Enter 1 to Play against computer(Single)//Enter 2 to play multiplayer(2 Players)//Enter 3 to Play Hangman: ";
	cin>>ch;
	if(ch==1)
		pl_vs_cmp();
	else if(ch==2)
		multiplr_pl();
	else if(ch==3)
		Hangman();
	
}
void Snke_ldr_Hangman::pl_vs_cmp(){
	srand(time(0));
	int i=0;
	
	cout<<"ladders are on Position : ";
	for(i=0;i<10;i++)
		cout<<ldr_tl[i]<<"-"<<ldr_up[i]<<","<<endl;
	cout<<"........................Come on man, Climb..................."<<endl;
	cout<<endl<<"Snakes are on Position : ";
	for(i=0;i<10;i++)
		cout<<snke_hd[i]<<"-"<<snke_fl[i]<<","<<endl;
	cout<<"......................\aBe Careful\a...........................";
	char c=' ';
	
	while(p1!=100 && p2!=100){
		
		cout<<endl<<endl<<"enter d to defensive(1,2,3) a to attacking(4,5,6): ";
		cin>>c;
		if(c=='d'||c=='D')
			s1=rand()%3+1;
		else if(c=='a'||c=='A')
			s1=rand()%3+4;
		cout<<endl<<"your Roll: "<<s1;
		p1=p1+s1;
		if(p1>100)
			p1=p1-s1;
		cout<<endl<<"you are at: "<<p1;
		for(i=0;i<10;i++){
			if(p1==ldr_tl[i]){
				p1=ldr_up[i];
				cout<<endl<<"you are up the ladder";
				cout<<endl<<"you are at: "<<p1;
			}
			else if(p1==snke_hd[i]){ 
				p1=snke_fl[i];
				cout<<endl<<"you have been eaten up by the snake";
				cout<<endl<<"you are at: "<<p1;
			}
		}
		
		
		
		s2=rand()%6+1;
		cout<<endl<<"my Roll: "<<s2;
		p2=p2+s2;
		if(p2>100)
			p2=p2-s2;
		cout<<endl<<"I am at: "<<p2;
		for(i=0;i<10;i++){
			if(p2==ldr_tl[i]){
				p2=ldr_up[i];
				cout<<endl<<"I am up the Ladder";
				cout<<endl<<"I am at: "<<p2;
			}
			else if(p2==snke_hd[i]){
				p2=snke_fl[i];
				cout<<endl<<"Eaten up By a snake  ";
				cout<<endl<<"I am at: "<<p2;
			}
		}
		
		
		
		
	}
	cout<<endl<<endl<<endl<<endl;
	if(p1>p2)
		cout<<endl<<".............................You Have Won The Match Master!!!!.............................";
	else
		cout<<endl<<".............................I Have Won The Match you Loser!!!................................";
}


void Snke_ldr_Hangman::multiplr_pl(){
	srand(time(0));
	int i=0;
	
	cout<<"ladders are on Position : ";
	for(i=0;i<10;i++)
		cout<<ldr_tl[i]<<"-"<<ldr_up[i]<<","<<endl;
	cout<<"........................Come on man, Climb..................."<<endl;
	cout<<endl<<"Snakes are on Position : ";
	for(i=0;i<10;i++)
		cout<<snke_hd[i]<<"-"<<snke_fl[i]<<","<<endl;
	cout<<"......................\aBe Careful\a...........................";
	char c1=' ';
	char c2=' ';
	
	while(p1!=100 && p2!=100){
		
		cout<<endl<<endl<<"Player1 enter d to defensive(1,2,3) a to attacking(4,5,6): ";
		cin>>c1;
		if(c1=='d'||c1=='D')
			s1=rand()%3+1;
		else if(c1=='a'||c1=='A')
			s1=rand()%3+4;
		cout<<endl<<"Player1's' Roll: "<<s1;
		p1=p1+s1;
		if(p1>100)
			p1=p1-s1;
		cout<<endl<<"Player1 is at: "<<p1;
		for(i=0;i<10;i++){
			if(p1==ldr_tl[i]){
				p1=ldr_up[i];
				cout<<endl<<"Player1 up the ladder";
				cout<<endl<<"Player1 is at: "<<p1;
			}
			else if(p1==snke_hd[i]){ 
				p1=snke_fl[i];
				cout<<endl<<"Player1 has been eaten up by the snake";
				cout<<endl<<"Player1 is at: "<<p1;
			}
		}
		
		cout<<endl<<endl<<"Player2 enter d to defensive(1,2,3) a to attacking(4,5,6): ";
		cin>>c2;
		if(c2=='d'||c2=='D')
			s2=rand()%3+1;
		else if(c2=='a'||c2=='A')
			s2=rand()%3+4;
		cout<<endl<<"Player2's' Roll: "<<s2;
		p2=p2+s2;
		if(p2>100)
			p2=p2-s2;
		cout<<endl<<"Player2 is at: "<<p2;
		for(i=0;i<10;i++){
			if(p2==ldr_tl[i]){
				p2=ldr_up[i];
				cout<<endl<<"Player2 up the ladder";
				cout<<endl<<"Player2 is at: "<<p2;
			}
			else if(p2==snke_hd[i]){ 
				p2=snke_fl[i];
				cout<<endl<<"Player2 has been eaten up by the snake";
				cout<<endl<<"Player2 is at: "<<p2;
			}
		}
	}
	cout<<endl<<endl<<endl<<endl;
	if(p1>p2)
		cout<<endl<<".............................Player1 Have Won The Match!!!!.............................";
	else
		cout<<endl<<".............................Player2 Have Won The Match!!!!................................";
}


void Snke_ldr_Hangman::Hangman(){
	srand(time(0));	
	char unknown[MAXLENGTH],word[MAXLENGTH];
	char letter;
	int num_of_wrong_guesses=0;
	char words[][MAXLENGTH] =
	{
	"India",
	"Pakistan",
	"Nepal",
	"Malaysia",
	"Philippines",
	"Australia",
	"Iran",
	"Ethiopia",
	"Oman",
	"Indonesia",
	"Canada",
	"England",
	"Brazil",
	"Argentina",
	"Germany",
	"France",
	"Italy",
	"Bulgaria",
	"Russia",
	"Mexico",
	"Bhutan",
	"China",
	"SriLanka",
	"Denmark",
	"Iceland",
	"NewZealand",
	"SouthAfrica",
	"WestIndies",
	"Zimbabwe",
	"Egypt",
	"Japan",
	"Mongolia"
	};
	//choose and copy a word from array of words randomly
	int n = rand()%32;
	strcpy(word,words[n]);	
	// Initialize the secret word with the * character.
	initUnknown(word, unknown);
	// welcome the user
	cout << "\n\n....................Welcome to hangman...Guess a country Name....................";
	cout << "\n\n....................Each letter is represented by a star.........................";
	cout << "\n\n....................You have to type only one letter in one try..................";
	cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	// Loop until the guesses are used up
	while(num_of_wrong_guesses < MAX_TRIES){	

		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		// Fill secret word with letter if the guess is correct,
		// otherwise increment the number of wrong guesses.
		if (letterFill(letter, word, unknown)==0)
		{	
			cout << endl << "Whoops! That letter isn't in there!" << endl;
			num_of_wrong_guesses++;
		}
		else 
			cout << endl << "You found a letter! Isn't that exciting!" << endl;
		// Tell user how many guesses has left.
		cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
		cout << " Guesses left." << endl;
		// Check if they guessed the word.
		if (strcmp(word, unknown) == 0)
		{
			cout << word << endl;
			cout << ".......................Yeah! You got it!............................";
			break;
		}
	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\n.............................Sorry, you lose...you've been hanged........................." << endl;
		cout << "The word was : " << word << endl;
	}
	
}
// Initialize the unknown word
void Snke_ldr_Hangman:: initUnknown(char word[], char unknown[]){

	int i;
	int length = strlen(word);
	for (i = 0; i < length; i++)
		unknown[i]='*';
	unknown[i]='\0';
}
/* Take a one character guess and the secret word, and fill in the
unfinished guessword. Returns number of characters matched.
Also, returns zero if the character is already guessed. */
int Snke_ldr_Hangman:: letterFill (char guess, char secretword[], char guessword[]){

	int i;
	int matches=0;
	for (i = 0; secretword[i]!='\0'; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
		 return 0;
		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}


int main(){
	Snke_ldr_Hangman ob;
	ob.getData();
	return 0;
}
