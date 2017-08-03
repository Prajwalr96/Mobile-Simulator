#include<iostream>
#include<limits>
#include<fstream>
#include<stdexcept>
#include<stdio.h>
#include<conio.h>                   //contains delay(),getch(),gotoxy(),etc.
#include<stdlib.h>		    // contains exit();
#include<string.h>
#include<cctype>                   //contains toupper(), tolower(),etc
#include<iomanip>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>

//#include<graphics.h>
#include<windows.h>
using namespace std;



//----------------------------------------------------------------------------
struct console
  {
  console( unsigned width, unsigned height )
    {
    SMALL_RECT r;
    COORD      c;
    hConOut = GetStdHandle( STD_OUTPUT_HANDLE );
    if (!GetConsoleScreenBufferInfo( hConOut, &csbi ))
      throw runtime_error( "You must be attached to a human." );

    r.Left   =
    r.Top    = 0;
    r.Right  = width -1;
    r.Bottom = height -1;
    SetConsoleWindowInfo( hConOut, TRUE, &r );

    c.X = width;
    c.Y = height;
    SetConsoleScreenBufferSize( hConOut, c );
    }

  ~console()
    {
    SetConsoleTextAttribute(    hConOut,        csbi.wAttributes );
    SetConsoleScreenBufferSize( hConOut,        csbi.dwSize      );
    SetConsoleWindowInfo(       hConOut, TRUE, &csbi.srWindow    );
    }

  void color( WORD color = 0x05 )
    {
    SetConsoleTextAttribute( hConOut, color );
    }

  HANDLE                     hConOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
};

//----------------------------------------------------------------------------
console con( 30, 15);

//----------------------------------------------------------------------------
class mob
{
public:     time_t t=time(0);
			struct tm *now=localtime(&t);
			void menu();
			void dial();
			void start();
			void password();
			void home();
};
void all();
void call();

//coordinates
void gotoxy(short x, short y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void mob::start()
{
	mob m;
	system("cls");
	char alpha[20]="WALLIE";
	gotoxy(11,6);
	//for(int i=0;i<30;i++)
	{
	//memmove(alpha+1,alpha,strlen(alpha));
	cout<<"W";
	Sleep(500);
	cout<<"A";
	Sleep(500);
	cout<<"L";
	Sleep(500);
	cout<<"L";
	Sleep(500);
	cout<<"I";
	Sleep(500);
	cout<<"E";
	Sleep(500);
	system("cls");
	gotoxy(11,6);
	cout<<alpha<<'\r';
	gotoxy(7,7);
	cout<<"I AM THE FUTURE";
	//alpha[i]='\0';
	Sleep(2000);
	}
	system("cls");
	gotoxy(6,6);
	cout<<"WELCOME TO THE FUTURE";
	Sleep(2000);
	m.password();
}
void mob::password()
{
	system("cls");
	string pass="";
	char ch,ch1;
	gotoxy(11,6);
	cout<<now->tm_mday<<'-'<<(now->tm_mon+1)<<'-'<<(now->tm_year+1900)<<endl;
	gotoxy(12,7);
	cout<<now->tm_hour<<':'<<now->tm_min<<endl;
	ch1=getch();
	if(ch1!=13)
	{
		system("cls");
		gotoxy(11,5);
		cout<<"press enter"<<endl;
		Sleep(500);
		return password();
	}
	system("cls");
	gotoxy(11,6);
	cout<<"PASSWORD"<<endl;
	ch=getch();
	gotoxy(13,7);
	while(ch!=13)
	{
		pass.push_back(ch);
		cout<<"*";
		ch=getch();
	}
	if(pass=="1234")
	{
		mob m;
	    m.menu();
	}
	else
	{
		gotoxy(11,5);
		cout<<"try again";
		Sleep(500);
		return password();
	}
}
void mob::menu()
{
	system("cls");
	gotoxy(1,1);
	cout<<".:!";
	gotoxy(23,1);
	cout<<now->tm_hour<<':'<<now->tm_min<<endl;
	gotoxy(0,2);
	cout<<"------------------------------"<<endl;
	gotoxy(0,11);
	cout<<"------------------------------"<<endl;
	gotoxy(1,12);
	cout<<"::";
	gotoxy(1,13);
	cout<<":";
	gotoxy(1,14);
	cout<<"::";
	gotoxy(12,12);
	cout<<" / \\";
	gotoxy(12,13);
	cout<<"/ _ \\";
	gotoxy(12,14);
	cout<<" | |";
	gotoxy(23,13);
	cout<<" <<***";
	gotoxy(23,14);
	cout<<"   ***";
/*	gotoxy(12,14);
	cout<<" | |";*/
/*	gotoxy(23,12);
	cout<<"    _";
	gotoxy(23,13);
	cout<<"   ...";
	gotoxy(23,14);
	cout<<"   [*]";*/
	int c,h,l;
	char ch;
	mob m;
	ch=getch();
	if(ch==99)
	{
		call();
		
	}
	else if(ch==104)
	{
		all();
		//m.home()
	}	 
	else if(ch==108)
	{
		m.password();
	}
	else 
	{
		m.menu();
	}
}
void mob::home()
{
	system("cls");
	string pass="";
	char ch;
	mob m;
	gotoxy(14,6);
	cout<<"ON\n";
	ch=getch();
	if(ch!=13)
	{
		gotoxy(12,6);
		cout<<"TRY AGAIN"<<endl;
		Sleep(1000);
		m.home();
	}
	else
	{
	system("cls");
	m.start();
}
/*	system("cls");
	char ch;
	//connect con;
	mob m;
	gotoxy(12,6);
	cout<<"PHONEBOOK"<<endl;
	ch=getch();
	if(ch=13)
	{
		phbook();
		return;
	}	
	if(ch=83||115)
	{
		cout<<"GAMES\n";
		if(ch=13)
		game();
		system("cls");
		else if(ch=87||119)
		m.home();
	}*/
}
/////////////////////////////phonebook////////////////////////////////////////
class phoneBook:public mob
{
	char name[20],phno[15];
    public: void getdata();
    		void showdata();
    		void maindata();
    		void dialdata();
            char *getname()
			{ 
			return name;
			}
    		char *getphno()
			{ 
			return phno; 
			}
    		void update(char *nm,char *telno)
			{
        	strcpy(name,nm);
        	strcpy(phno,telno);
    		}
};

void phoneBook::getdata()
{
    cout<<"\nEnter Name : ";
    cin>>name;
    cout<<"Enter Phone No. : ";
    cin>>phno;
}

void phoneBook::showdata()
{
cout<<endl;
cout<<setw(20)<<name<<endl;
cout<<"\t"<<setw(15)<<phno<<endl;
}
void phoneBook::dialdata()
{
	phoneBook rec;
    fstream file;
    file.open("phone.dat", ios::ate | ios::in | ios::out | ios::binary);
    char ch,nm[20],telno[6];
    int choice,found=0;
    system("cls");
	gotoxy(9,3);
	cout<<"============\n";
	gotoxy(9,4);
	cout<<"|	    |\n";
	gotoxy(9,5);
	cout<<"============\n";
	gotoxy(10,4);
	cout<<"";
	//Search name on basis of tel. no
                 cin>>telno;
                 file.seekg(0,ios::beg);
                 found=0;
                 while(file.read((char *) &rec, sizeof(rec)))
                 {
                    if(strcmp(telno,rec.getphno())==0)
                    {
                        found=1;
                        rec.showdata();
                    }
                 }
                 file.clear();
                 if(found==0)
                 cout<<"\n\n---Record Not found---\n";
                 getch();    
}
void phoneBook::maindata()
{
	phoneBook rec;
    fstream file;
    file.open("phone.dat", ios::ate | ios::in | ios::out | ios::binary);
    char ch,nm[20],telno[6];
    int choice,found=0;
    while(1){
        system("cls");
        cout<<"\n*****Phone Book*****\n";
        cout<<"1) Add New Record\n";
        cout<<"2) Display All Records\n";
        cout<<"3) Search Telephone No.\n";
        cout<<"4) Search Person Name\n";
        cout<<"5) Update Telephone No.\n";
        cout<<"6) Exit\n";
        cout<<"Choose your choice : ";
        cin>>choice;
        switch(choice){
            case 1 : //New Record
                 rec.getdata();
                 cin.get(ch);
                 file.write((char *) &rec, sizeof(rec));
                 break;

            case 2 : //Display All Records
                 file.seekg(0,ios::beg);
                 cout<<"\n\nRecords in Phone Book\n";
                 while(file){
                    file.read((char *) &rec, sizeof(rec));
                    if(!file.eof())
                    rec.showdata();
                 }
                 file.clear();
                 getch();
                 break;

            case 3 : //Search Tel. no. when person name is known.
                 cout<<"\n\nEnter Name : ";
                 cin>>nm;
                 file.seekg(0,ios::beg);
                 found=0;
                 while(file.read((char *) &rec, sizeof(rec)))
                 {
                    if(strcmp(nm,rec.getname())==0)
                    {
                        found=1;
                        rec.showdata();
                    }
                 }
                 file.clear();
                 if(found==0)
                    cout<<"\n\n---Record Not found---\n";
                 getch();
                 break;

            case 4 : //Search name on basis of tel. no
                 cout<<"\n\nEnter Telephone No : ";
                 cin>>telno;
                 file.seekg(0,ios::beg);
                 found=0;
                 while(file.read((char *) &rec, sizeof(rec)))
                 {
                    if(strcmp(telno,rec.getphno())==0)
                    {
                        found=1;
                        rec.showdata();
                    }
                 }
                 file.clear();
                 if(found==0)
                    cout<<"\n\n---Record Not found---\n";
                 getch();
                 break;

            case 5 : //Update Telephone No.
                 cout<<"\n\nEnter Name : ";
                 cin>>nm;
                 file.seekg(0,ios::beg);
                 found=0;
                 int cnt;
                 cnt=0;
                 while(file.read((char *) &rec, sizeof(rec)))
                 {
                    cnt++;
                    if(strcmp(nm,rec.getname())==0)
                    {
                        found=1;
                        break;
                    }
                 }
                 file.clear();
                 if(found==0)
                 {
				  cout<<"\n\n---Record Not found---\n";
                  Sleep(2000);
                 }
                 else
                 {
                    int location = (cnt-1) * sizeof(rec);
                    cin.get(ch);
                    if(file.eof())
                        file.clear();

                    cout<<"Enter New Telephone No : ";
                    cin>>telno;
                    file.seekp(location);
                    rec.update(nm,telno);
                    file.write((char *) &rec, sizeof(rec));
                    file.flush();
                 }
                 break;
            case 6 : goto out;
        }
    }
out:
file.close();
char ch1;
	mob m;
	ch1=getch();
	if(ch1==104)
	{
		m.menu();
	}
	else if(ch1==8)
	{
		all();
	}
	else
	{
		rec.maindata();
	}
}

//////////////////////////////game///////////////////////////////////////////////
class Games:public mob
{
	public: void play();
};
void Games::play()
{
	system("cls");
	char ch1;
	mob m;
	const int MAX_WRONG = 8;  

    vector<string> words; 
    words.push_back("PIZZA");
    words.push_back("BACON");
    words.push_back("STIMULATED");

    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0];            
    int wrong = 0;                               
    string soFar(THE_WORD.size(), '-');          
    string used = "";                            
    cout<<"    Welcome to Hangman!";
	cout<<"\n   -------------------\n\n";
	cout<<"You have exactly "<<(MAX_WRONG - wrong)<<" guesses\n";
	cout<<"        GOODLUCK!";
	ch1=getch();
	if(ch1==8)
  	{
  	all();		
	}
	Sleep(3000);
	system("cls");
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout<<"\nYou've used the\n";
		cout<<"following letters:\n"<<used<< endl;
        cout<<"So far, the word is:"<<soFar<<endl;
        char guess;
        cout<<"\n\nEnter your guess:";
        cin>>guess;
        guess=toupper(guess); //make uppercase since secret word in uppercase
        while(used.find(guess)!=string::npos)
        {
            cout<<"\nYou've already guessed"<<guess<<endl;
            cout<<"Enter your guess:";
            cin>>guess;
            guess=toupper(guess);
        }
        used+=guess;
        if(THE_WORD.find(guess)!=string::npos)
        {
            cout<<"That's right! "<<guess<<" is in the word\n";
            for(unsigned int i=0;i<THE_WORD.length();++i)
			{
                if(THE_WORD[i]==guess)
				{
                    soFar[i]=guess;
				}
			}
        }
        else
        {
			++wrong;
            cout<<"Sorry, "<<guess<<" isn't in the word.\n";
			cout<<"You have "<<(MAX_WRONG - wrong)<<" guesses left.\n";
        }
    }
    if(wrong==MAX_WRONG)
	{
        cout<<"Game over, you've been hanged!";	
	}
    else
	{
        cout<<"Congratulation!\n";
		cout<<"You've successfully\n"; 
		cout<<"guessed the secret word!";
	}
	//This is a little something i like to do at the end of my games ;)
    cout<<"\nThe word was "<<THE_WORD<<"\n\n";
	int rate;
	cout<<"Please take a moment\n";
	cout<"of your time\n";
	cout<<"and rate the game\n";
	cout<<"1 - It was fun!\n";
	cout<<"2 - It was ok\n";
	cout<<"3 - It was bad\n";
	cin>>rate;
	switch (rate)
	{
	case 1: cout<<"We are so glad to hear that!\n";
			cout<<"Thanks for the positive feedback!\n"; break;
	case 2: cout<<"We'll do better next time\n";
			cout<<"Thanks for your feedback!\n"; break;
	case 3: cout<<"We are terribly sorry about that\n";
			cout<<"We'll do better next time\n"; break;
	default: cout<<"Good-bye\n"; break; 
	}
	//system("pause");
	
	ch1=getch();
	if(ch1==8)
  	{
  	m.menu();		
	}
    //return;
}
class Connect:public mob,public phoneBook,public Games
{
	public: void phbook();
			void game();
			void jump();
};
void Connect::phbook()
{
	phoneBook pb;
	pb.maindata();
}
void Connect::game()
{
	Games g;
	g.play();	
}

void all()
{
	system("cls");
	char ch,ch1;
	mob m;
	Connect c;
	Games g;
	phoneBook p;
	gotoxy(10,6);
	cout<<"PHONEBOOK"<<endl;
	ch1=getch();
	if(ch1==13)
	{
		c.phbook();
	}
	else if(ch1==8)
  	{
  	m.menu();		
	}
	else if(ch1!=13)
	{	
		system("cls");
		gotoxy(12,6);
		cout<<"GAMES\n";
		ch=getch();
		while(ch!=13)
		{
		all();
		}
		c.game();
	}
  	else if(ch1==8)
  	{
	  	m.menu();		
	}
	else
	{
		m.menu();
	}
}
void call()
{
phoneBook pb;
pb.dialdata();
}
int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0B);
	system("cls");
	char ch;
	mob m;
	Connect c;
	Games g;
	phoneBook p;
	m.home();	
  	cin.ignore( numeric_limits <streamsize> ::max(), '\n' );
  	return 0;
}

