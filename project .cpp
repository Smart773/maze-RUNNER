//******************** Maze Runner **********************
//usama bin waseem(045)
// umair (048)
//ibrahem(73)
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string>
#include <iterator>
#include <list>
#include <fstream>

using namespace std;
string filename;
int slp=0;
void SetWindow(int Width, int Height)
    {
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
    }

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void menu();
void Instruction();
void color(int a);
void sortdec(int *s,int a);
void sleep(int x);
void menuG();
class Useracc{
    private:
    string *userName;
    string *password;
    protected: 
    string *fname;
    string *lname;
    public:
    // void setfname(string n){*fname=n;}
    // void setlname(string n){*lname=n;}
    void setuser(string n){*userName=n;}
    void setpass(string p){*password=p;}
    string getuser(){return(*userName);}
    string getpass(){return(*password);}
    Useracc(){
        userName=new string;
        password=new string;
        fname=new string;
        lname=new string;
    }

    ~Useracc(){
        
        delete userName ;
        delete password ;
        delete fname;
        delete lname;
    }
 
};

class login: public Useracc{
    private:
    string *pss,*usr;
    string n,p;
    bool called;
    public:
     void createaccount(){
         called=true;
        cout<<"Entere your First name: ";
        cin>>*fname;
        cout<<"Entere your last name: ";
        cin>>*lname;
        cout<<"create a user name: ";
        cin>>n;
        for (int i = 0; n[i]!= '\0'; i++)
    {
        if(((n[i]>=65&&n[i]<=90)||(n[i]>=97&&n[i]<=112))||(n[i]>=48&&n[i]<=57));
        else 
        {cout<<"Username don't consist of ,./ space !@#$%^&*()_+-\nre-Enter the user name: ";
        cin>>n;}
    }
        // if((*n>='a'&&*n<='z')||(*n>='A'&&*n<='Z')||(*n>='0'&&*n<='9'));
        setuser(n);
        cout<<"create a password:  ";
        cin>>p;
        setpass(p); 

        filename=getuser()+"_record.txt";
        ofstream player((filename.c_str()),ios::out);
        player<<*fname<<" "<<*lname<<" \n1 0 100 3";
        player.close();

        fstream user(("accINFO.txt"),ios::binary | ios::out | ios::app);
        if (called)user<<getuser()<<" "<<getpass()<<endl;   
        user.close();
    };



    bool loginaccount(){
        called=false;
        int a;
       do{
        cout<<"Enter a user name: ";
        cin>>*usr;
        cout<<"Entere a password:  ";
        cin>>*pss;
        
        setpass(*pss);
        setuser(*usr);

     ifstream user(("accINFO.txt"),ios::binary | ios::in);
     for(;!user.eof();){   
            // check();
            user>>n>>p;
        if(getpass()==p && getuser()==n){
            filename=getuser()+"_record.txt";
            a=3;
            return true;}
        }
        a++;
        cout<<"remaing Attempts"<<3-a<<endl;
        
        system("pause");
        system("cls");
        cout<<"wrong inputs\nre-";
     }while(a!=3);
        system("cls");
             return false;
        
    };
    
    login(){
      pss=new string;
      usr=new string;      
      
      
      
      fstream user(("accINFO.txt"),ios::binary | ios::out |ios :: app);
      if(!(user.is_open())){
          cout<<"ERROR in ACCinfo Exiting ...";
          exit(5000);
      }
      user.close();
        
    };
    ~login(){
    delete usr;
    delete pss;
    };
};

class TIME{
    private:
   
    int sec1; //seconds
    int min; //minutes
    int sec;
    int hr;

    public:
        TIME(){
            sec1 = 0; //seconds
            min = 0; //minutes
            sec=0;
        }

        void reSET(){
            sec1 = 0; //seconds
            min = 0; //minutes
            sec=0;
        }

       void  timer(){
    

        {
            sec++;
               this->min=this->sec/60;
            this->sec1=this->sec%60;
            // convet(sec);
       
        }

        };

        friend ostream &operator<<( ostream &output, const TIME &T ) { 


                if(T.min<10)cout<<"0";
                output<<T.min<<":";
                if(T.sec1<10)cout<<"0";
            output<<T.sec1<<"     ";
        
         return output;            
      }
        void convet(int s){
            TIME r;
           r.min=s/60;
            r.sec1=s%60;

            if(r.min<10)cout<<"0";
                cout<<r.min<<":";
                if(r.sec1<10)cout<<"0";
            cout<<r.sec1<<endl;;
        
            }
        
        int getsec(){
            return sec;
        }

    };

class status{
    private:
    string name;
    long int score;
    int hp;
    short life;
    string level;
    int key;
    TIME time1;
    string data;
    list <int> scoreDATA;
    list <int> timeDATA;
    list <int> :: iterator s; 
    list <int> :: iterator t; 
    public:
    status(){
        hp=100;
        key=0;
        data="data";
    }
     string getlevel(){
        return level;
    }
        void updateLevel(){
           
            level[0]++;
        ofstream player((filename.c_str()),ios::out);
        player<<name<<" "<<level<<" "<<score<<" "<<hp<<" "<<life<<" ";
        player.close();  
        }
        void updatehp(int x){
            for (int i = 1; i <= 10; i++)
        {
            hp=hp-2;
            showHP(x+5);
            sleep(3);
        }
            
        }

        bool updatelife(int x){
            if(hp<=0){
                life--;
                hp=100;
                showlife(x+5);
                }
            if(life<=0){
                    GameOver();
                    return false;
            }

            return true;

        }
            void updateTime(int x){
                if(slp%40==0)
                {time1.timer();
                showTIME(x);}
            }
    void getstatus(){
        string a;
        ifstream player((filename.c_str()),ios::in);
        player>>name>>a>>level>>score>>hp>>life;
        name=name+" "+a;
        player.close();     
    }
    void showname(int x){
        color(2); gotoxy(x,5);
        cout<<"player name: ";
        color(15);cout<< name;   
    }
    void showlevel(int x){
        color(3); gotoxy(x,6);//7
        cout<<"Current Level: ";
        color(15); cout<<level;
    }
    void showScore(int x){
        color(4); gotoxy(x,7);//8
        cout<<"Score: ";
        color(15); cout<<score;
    }

    void showTIME(int x){
        // Current Level: 1         Time:
        color(4); gotoxy(x+5,19);//8
        cout<<"Time: ";
        color(15); cout<<time1<<"  ";
    }
    void showHP(int x){
            color(5); gotoxy(x,8);//9
        cout<<"HP: ";
        color(15);cout<<hp<<" ";
    }
    void showkey(int x){
         color(13); gotoxy(x,10);//11
        cout<<"Key: ";
        color (15); cout<<key<<endl;
    }
    void showlife(int x){
         color(12); gotoxy(x,9);//10
        cout<<"Life: ";
        color (15); cout<<life<<endl;
    }
    void icrementScore(int x){
        for (int i = 1; i <= 10; i++)
        {
            score++;
            showScore(x+5);
            sleep(5);
        }

    }
    void icrementKey(int x){

            key++;
            showkey(x+5);

    }
    int getkey(){
        return key;
    }
    void showStatus(int x, int y){
        x=y+5;
        int i=1;
        color(14);
        gotoxy(x,1);
        cout<<"##############################################";
        gotoxy(x,2);
        cout<<"#######";color(9);
        cout<<"     M A Z E   R U N N E R ";color(14);
        cout<<"    ########";
        gotoxy(x,3);
        cout<<"##############################################";color(15);
        gotoxy(x,4);color(5);
        cout<<"--------S T A T U S---------";
        showname(x);
        showTIME(x);
        showlevel(x);
        showScore(x);
        showHP(x);
        showlife(x);
        showkey(x);
        gotoxy(x,11);
        color(5);
        cout<<"------I N S T R U C T I O N-------";
        color(6);
        gotoxy(x,12);
        cout<<"press ";
        color(10);cout<<"W";
        color(6);cout<<" for Up ";
        color(10);cout<<"A";
        color(6);cout<<" for Left ";
        color(10);cout<<"D";
        color(6);cout<<" for Right ";
        color(10);cout<<"S";
        color(6);cout<<" for Down";
        gotoxy(x,13);
        color(9);cout<<(char)177<<" -> YOU";
        gotoxy(x,14);
        color(4);cout<<(char)220<<" -> Enemy";
        gotoxy(x,15);
        color(8);cout<<(char)233<<" -> Score item";
        gotoxy(x,16);
        color(10);cout<<(char)183<<" -> Keys";

        
        gotoxy(x,18);
        color(6);cout<<"Note: " ;
        color(4);cout<<"Pick up keys for going out of the maze";

        
        color(15);
    }

    void cleainglevel(){
        int x=35;
        
        system("cls");
        gotoxy(x,2);
        color(10);cout<<"C O N G R A T U L A T I O N S";
        gotoxy(x,3);
        color(6);cout<<level<<" L E V E L  I S  C L E A R E D";
        gotoxy(x,4);
        cout<<"S O l V E D  i n   ";
        color(15);cout<<time1;
        
        gotoxy(x,5);
        color(4);cout<<"S C O R E   ";
        color(15);cout<<score;
        cout<<endl<<endl<<endl;



        {
            key=0;
            score=0;
            life=3;
            hp=100;
            slp=0;
            time1.reSET();
        }

        system("pause");
        system("cls");

        cout<<"press 1 to restart ";
    }
    void gameCompleted(){
        if(level=="5"){
        int x=35;
        
        system("cls");
        gotoxy(x,2);
        color(10);cout<<"C O N G R A T U L A T I O N S";
        gotoxy(x,3);
        color(6);cout<<level<<" G A M E  I S  C L E A R E D";
       
        
        gotoxy(x,5);
        color(4);cout<<"W E     H O P E     Y O U     E N J O Y E D      O U R    G A M E ";
        color(15);
        gotoxy(x,8);
        cout<<" E X I T I N G   T H E   G A M E ";



        {
            key=0;
            score=0;
            life=3;
            hp=100;
            slp=0;
            level="1";
            time1.reSET();
        }
            system("pause");
       exit(50);
        }
    }
    void GameOver(){
        int x=35;
        
        system("cls");
        gotoxy(x,2);
        color(10);cout<<"B E T T E R   L U C K   N E X T  T I M E ";
        gotoxy(x,4);
        color(4); cout<<"R E - S E T T I N G  L E V E L ";
        color(15);

        


        {
            level=1;
            score=0;
            life=3;
            hp=100;
            slp=0;
            key=0;
            time1.reSET();
        }

        system("pause");
        system("cls");
    }
    
    void read(int s[] ,int t[],string d){
            
        ifstream read((d).c_str());
        for (int i = 0; i < 10; i++)
            read>>s[i];
            
        for (int i = 0; i < 10; i++)
            read>>t[i];

            read.close();
            
        sortdec(s,10);
        sortdec(t,10);

        for (int i = 0; i < 10; i++)
        {
            if(score>s[i]){
                s[9]=score;
                sortdec(s,10);
                break;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            if(time1.getsec()>t[i]){
                t[9]=time1.getsec();
                sortdec(t,10);
                break;
            }
        }


    }
    void showRecordScore(string x){
         data="data";
            data=data+x+".txt";
         int s[10];
         int t[10];
        read(s,t,data);
        cout<<"Top 10 Hight Score are :"<<endl;
        cout<<"---------------------------------------------"<<endl;
        for (int i = 0; i < 10; i++)
        {
            cout<<i+1<<":  "<<s[i]<<endl;
        }
    }
    void showRecordTime(string x){
         
         data="data";
            data=data+x+".txt";
         int s[10];
         int t[10];
        read(s,t,data);
        cout<<"Top 10 fastest time are :"<<endl;
        cout<<"---------------------------------------------"<<endl;
        for (int i = 0; i < 10; i++)
        {
            cout<<i+1<<":  ";
            time1.convet(t[i]);
        }
    }
    void updateRecord(){
            data="data";
            data=data+level+".txt";
       
       
         int s[10];
         int t[10];
       read(s,t,data);

          ofstream write((data).c_str());
        
       
        for (int i = 0; i < 10; i++)
            write<<s[i]<<endl;
        
        for (int i = 0; i < 10; i++)
            write<<t[i]<<endl;

        write.close();
    }


};

class player{
    private:
        int *location;
    public:
    player(){
        location = new int[2];
            
    }
    int *getloaction(){
        return location;
    }

    void setlocation(){
         location[0]=1;
            location[1]=1;
    }
    
    bool WIN(int x,int y){
        if(location[0]==x-2&&location[1]==y-2){
            return true;
        }
        return false;
    }
    
void swapv(int **z,int *a,int b){
        int temp=0;
        
        temp=z[a[0]][a[1]+b];
        z[a[0]][a[1]+b]=z[a[0]][a[1]];
        z[a[0]][a[1]]=temp;

            color(6);
        gotoxy(a[1]+b,a[0]);
        cout<<(char)z[a[0]][a[1]+b];
        gotoxy(a[1],a[0]);
        cout<<(char)z[a[0]][a[1]];

        a[1]=a[1]+b;
        
    color(15);
    };

    // **********************cheat move ment****************
void cheatmove(int **z,int *a,int x,int y){
        int temp=0;
        temp=z[x-3][y-2];
        z[x-3][y-2]=z[a[0]][a[1]];
        z[a[0]][a[1]]=temp;

        gotoxy(x-3,y-2);
        cout<<(char)z[x-3][y-2];
        gotoxy(a[1],a[0]);
        cout<<(char)z[a[0]][a[1]];

        a[1]=y-2;
        a[0]=x-3;
        

    };
    void swaph(int **z,int *a,int b){
        int temp=0;
        temp=z[a[0]+b][a[1]];
        z[a[0]+b][a[1]]=z[a[0]][a[1]];
        z[a[0]][a[1]]=temp;

            color(6);
        gotoxy(a[1],a[0]+b);
        // if(z[a[0]+b][a[1]]==220)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12+b);
        // else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        cout<<(char)z[a[0]+b][a[1]];
        gotoxy(a[1],a[0]);
        cout<<(char)z[a[0]][a[1]];
        a[0]=a[0]+b;
       
            color(15);
    }

    bool pl_collied(int **map){
                if(map[location[0]+1][location[1]]==220) return true;
                if(map[location[0]-1][location[1]]==220) return true;
                if(map[location[0]][location[1]+1]==220) return true;
                if(map[location[0]][location[1]+1]==220) return true;
       
       
       
        return false;
    };
    
        
    ~player(){

      for(int i = 0; i < 1; i++)
        
            delete [] location;
    }

};

class enemy{

    private:
    int **En_poition;
    int Total_En;
     int p[30];
     int limit;
    public:
    friend int n();
        enemy(){
            Total_En=30;
            limit=0;
            En_poition = new int*[Total_En];
             for(int i = 0; i < Total_En; i++)
                En_poition[i] = new int[2];

             for(int i = 0; i < Total_En; i++)
                    p[i]=1;
            
        }
        ~enemy(){

            for (int i = 0; i < Total_En; i++)
                delete En_poition[i];
                delete [] En_poition;
        }
        
        int getenemycount( string a){
            return(int)a[0]-48;
        }
       void genrateEnemy(int **z,int x,int y,int a){
         limit=a+(4+a);
        int r,k;
        srand(time(0));
        for (int i = 0; i <=limit; i++)
        while(true)
        {   
             r=rand()%x; 
             k=rand()%y;
            if(z[r][k]==32&&(z[r+1][k]!=291&&z[r-1][k]!=291)){

             z[r][k]=220;
                En_poition[i][0]=r;
                En_poition[i][1]=k;
                    break;
            }
        
        }
    }
     void swapv(int **z,int **em,int b){
        int temp=0;
        temp=z[em[b][0]+p[b]][em[b][1]];
        z[em[b][0]+p[b]][em[b][1]]=z[em[b][0]][em[b][1]];
        z[em[b][0]][em[b][1]]=temp;


        gotoxy(em[b][1],em[b][0]+p[b]);
        // if(z[em[b][0]+p[b]][em[b][1]]==220)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12+p[b]);
        // else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        cout<<(char)z[em[b][0]+p[b]][em[b][1]];
        gotoxy(em[b][1],em[b][0]);
        cout<<(char)z[em[b][0]][em[b][1]];
        em[b][0]=em[b][0]+p[b];
       
    };

     void vertEnemy(int **map){
         
            for(int i=0;i<= limit; i++) {  

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3+p[i]);
                if(map[En_poition[i][0]+p[i]][En_poition[i][1]]==32)
                {
                swapv(map,En_poition,i);
                }
                else if(map[En_poition[i][0]+p[i]][En_poition[i][1]]!=32){p[i] *=  -1;
                }
                sleep(2);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            }
            }

};

class ScoreItem{
    private:
    int **poition;
    int Total_En;
     int p[30];
     int limit;
    public:
    friend int n();
        ScoreItem(){
            Total_En=30;
            limit=0;
            poition = new int*[Total_En];
             for(int i = 0; i < Total_En; i++)
                poition[i] = new int[2];

             for(int i = 0; i < Total_En; i++)
                    p[i]=1;
            
        }
        ~ScoreItem(){

            for (int i = 0; i < Total_En; i++)
                delete poition[i];
                delete [] poition;
        }
        
        int getscorecount( string a){
            return(int)a[0]-48;
        }
       void genratescore(int **z,int x,int y,int a){
         limit=a+4;
        int r,k;
        srand(time(0));
        for (int i = 0; i <=limit; i++)
        while(true)
        {   
             r=rand()%x; 
             k=rand()%y;
            if(z[r][k]==32&&(z[r+1][k]!=291&&z[r-1][k]!=291)){

             z[r][k]=233;
                poition[i][0]=r;
                poition[i][1]=k;
                    break;
            }
        
        }
    }
    void collectv(int **z,int *a,int b){
        int temp=0;
        
        temp=z[a[0]][a[1]+b];
        z[a[0]][a[1]+b]=z[a[0]][a[1]];
        z[a[0]][a[1]]=32;

        gotoxy(a[1]+b,a[0]);
        cout<<(char)z[a[0]][a[1]+b];
        gotoxy(a[1],a[0]);
        cout<<(char)z[a[0]][a[1]];

        a[1]=a[1]+b;
        
    };
    void collecth(int **z,int *a,int b){
        int temp=0;
        temp=z[a[0]+b][a[1]];
        z[a[0]+b][a[1]]=z[a[0]][a[1]];
        z[a[0]][a[1]]=32;

        gotoxy(a[1],a[0]+b);
        cout<<(char)z[a[0]+b][a[1]];
        gotoxy(a[1],a[0]);
        cout<<(char)z[a[0]][a[1]];
        a[0]=a[0]+b;
       
    };
};

class key{
    private:
    int **poition;
    int Total_En;
     int p[30];
     int limit;
    public:
    friend int n();
        key(){
            Total_En=30;
            limit=0;
            poition = new int*[Total_En];
             for(int i = 0; i < Total_En; i++)
                poition[i] = new int[2];

             for(int i = 0; i < Total_En; i++)
                    p[i]=1;
            
        }
        ~key(){

            for (int i = 0; i < Total_En; i++)
                delete poition[i];
                delete [] poition;
        }
        
        int getkeycount( string a){
            return(int)a[0]-48;
        }
        int getlimit(){
                return limit;
        }
       void genratekey(int **z,int x,int y,int a){
         limit=a+2;
        int r,k;
        srand(time(0));
        for (int i = 0; i <limit; i++)
        while(true)
        {   
             r=rand()%x; 
             k=rand()%y;
            if(z[r][k]==32&&(z[r+1][k]!=291&&z[r-1][k]!=291)){

             z[r][k]=183;
                poition[i][0]=r;
                poition[i][1]=k;
                    break;
            }
        
        }
    }
    void collectv(int **z,int *a,int b){
        int temp=0;
        
        temp=z[a[0]][a[1]+b];
        z[a[0]][a[1]+b]=z[a[0]][a[1]];
        z[a[0]][a[1]]=32;

        gotoxy(a[1]+b,a[0]);
        cout<<(char)z[a[0]][a[1]+b];
        gotoxy(a[1],a[0]);
        cout<<(char)z[a[0]][a[1]];

        a[1]=a[1]+b;
        
    };
    void collecth(int **z,int *a,int b){
        int temp=0;
        temp=z[a[0]+b][a[1]];
        z[a[0]+b][a[1]]=z[a[0]][a[1]];
        z[a[0]][a[1]]=32;

        gotoxy(a[1],a[0]+b);
        cout<<(char)z[a[0]+b][a[1]];
        gotoxy(a[1],a[0]);
        cout<<(char)z[a[0]][a[1]];
        a[0]=a[0]+b;
       
    };
};

class mazemap{
    private:
    status st;
    player ply;
    enemy em;
    key ky;
    ScoreItem sr;
    int sizeX;
    int sizeY;
    int **map;
    string levelfile;
    public:
    mazemap(){
            st.getstatus();        
            levelfile="level_"+st.getlevel();
            levelfile=levelfile+".txt";
         ifstream Map(((levelfile).c_str()),ios::in);
         Map>>sizeX>>sizeY;
         map = new int*[sizeX];
         for(int i = 0; i < sizeX; i++)
                map[i] = new int[sizeY];
        for (int i = 0; i < sizeX; i++)
        for (int j = 0; j < sizeY; j++)
            if(!Map.eof())Map>>map[i][j];
        
        Map.close();
        
    }
    void loadlevel(){
        // cout<<"getting new level <<endl";
            st.getstatus();        
            levelfile="level_"+st.getlevel();
            levelfile=levelfile+".txt";
         ifstream Map(((levelfile).c_str()),ios::in);
         Map>>sizeX>>sizeY;
        for (int i = 0; i < sizeX; i++)
        for (int j = 0; j < sizeY; j++)
            if(!Map.eof())Map>>map[i][j];
        
        Map.close();
        
        
    }
    void showMap(){
                loadlevel();
                ply.setlocation();
                ky.genratekey(map,sizeX,sizeY,sr.getscorecount(st.getlevel()));
                sr.genratescore(map,sizeX,sizeY,sr.getscorecount(st.getlevel()));
                em.genrateEnemy(map,sizeX,sizeY,em.getenemycount(st.getlevel()));
        for (int i = 0; i < sizeX; i++){
            for (int j = 0; j < sizeY; j++){
                    if(map[i][j]==233)color(13);
                    else if(map[i][j]==183)color(8);
                    else color(15);
                cout<<(char)map[i][j];
            }
          cout<<endl;
        }

            cout<<em.getenemycount(st.getlevel())<<levelfile<<st.getkey()<<" "<<ky.getlimit()<<endl;
        st.showStatus(sizeX,sizeY);
    }
        bool checkV(int *z,int a,int f){
            z=ply.getloaction();
        if(map[z[0]][z[1]+a]==f) return true;
        return false;
    }
        bool checkH(int *z,int a,int f){
        if(map[z[0]+a][z[1]]==f) return true;
        return false;
    }
     
    void genrateEXIT(){
        gotoxy(sizeY-2,sizeX-2);
        color(68);cout<<" ";
        gotoxy(sizeY-2,sizeX-2);
        color(34);cout<<" ";
        gotoxy(sizeY-2,sizeX-2);
        color(127);cout<<" ";

        color(15);
    };
    void enemymove(){
        em.vertEnemy(map);
    }
    void timev(){
        
        
            st.updateTime(sizeY);
        

    }
  bool  action(char a){

        if(st.getkey()>=ky.getlimit()){
            genrateEXIT();
            if(ply.WIN(sizeX,sizeY)){
                st.updateRecord();
                st.cleainglevel();
                st.gameCompleted();
                st.updateLevel();
                cout<<"Next level is "<<st.getlevel()<<endl;
                return false;
            }
            };
            if(ply.pl_collied(map)){

                st.updatehp(sizeY);
                return st.updatelife(sizeY);
                };
    switch (a)
        {
            case 'a'://left
            if(checkV(ply.getloaction(),-1,32))
            {
             ply.swapv(map,ply.getloaction(),-1);
             
            }
            else if(checkV(ply.getloaction(),-1,233)){
                sr.collectv(map,ply.getloaction(),-1);
                st.icrementScore(sizeY);
            }
            else if(checkV(ply.getloaction(),-1,183)){
                sr.collectv(map,ply.getloaction(),-1);
                st.icrementKey(sizeY);
            }

            break;
        
        case 'd'://right
            if(checkV(ply.getloaction(),1,32))
            {
             ply.swapv(map,ply.getloaction(),1);
             
            }
            else if(checkV(ply.getloaction(),1,233)){
                sr.collectv(map,ply.getloaction(),1);
                st.icrementScore(sizeY);
            }
            else if(checkV(ply.getloaction(),1,183)){
                sr.collectv(map,ply.getloaction(),1);
                st.icrementKey(sizeY);
            }
        
            break;
        
        case 'w'://up
            
            if(checkH(ply.getloaction(),-1,32))
            {
             ply.swaph(map,ply.getloaction(),-1);
             
            }
            else if(checkH(ply.getloaction(),-1,233)){
                sr.collecth(map,ply.getloaction(),-1);
                st.icrementScore(sizeY);
            }
            else if(checkH(ply.getloaction(),-1,183)){
                sr.collecth(map,ply.getloaction(),-1);
                st.icrementKey(sizeY);
            }

            break;
        case 's'://down
            
            if(checkH(ply.getloaction(),1,32))
            {
             ply.swaph(map,ply.getloaction(),1);
             
            }
            else if(checkH(ply.getloaction(),1,233)){
                sr.collecth(map,ply.getloaction(),1);
                st.icrementScore(sizeY);
            }
            else if(checkH(ply.getloaction(),1,183)){
                sr.collecth(map,ply.getloaction(),1);
                st.icrementKey(sizeY);
            }
            break;
        case 'k'://************** cheat key increment***************************
            st.icrementKey(sizeY);
            break;
        case 'o'://*************** cheat score increment **************************
            st.icrementScore(sizeY);
        
            break;
        case 'l'://*********************cheat lose hp ******************************
            st.updatehp(sizeY);
            st.updatelife(sizeY);

            break;
         case 'm'://*************************cheat move near to the gate**********************
            ply.cheatmove(map,ply.getloaction(),sizeX,sizeY);
         break;
        default:
            break;
        }
        return true;
    }

};

int main(){

    menu();

    return(0);
}

 void menu(){
    login log;
    char choice;
       do{
           system("cls");
            cout<<"press "<<endl
            <<"1 for creating account"<<endl
            <<"2 for login"<<endl
            <<"0 Exit"<<endl;
            cin>>choice;
            switch (choice)
            {
                case '1':
                    log.createaccount();

                break;
        
                case '2':
                    if(log.loginaccount())
                    menuG();

                break;
                case '0':
                    exit(0);
                default:
                    cout<<"invalid input";
                break;
            }
            system("pause");
        }while(choice!='0');
    }

string menuData(){
 string choice="z";
 char a;
       
       do{
            cout<<"press "<<endl
            <<"1 for level"<<endl
            <<"2 for level"<<endl
            <<"3 for level"<<endl
            <<"4 for level"<<endl
            <<"5 for level"<<endl
            <<"0 for previous menu"<<endl;
            cin>>a;
            if(a>='0'&&a<='5')
            choice[0]=a;
           system("cls");
       }while(choice=="z");

       return choice;    
}

void menuG(){
        mazemap game;
        status ss;
        char choice;
        do{
            system("cls");
        cout<<"press "<<endl
        <<"1 to start game"<<endl
        <<"2 check top 10 highest score"<<endl
        <<"3 check top 10 fastest taken time to solve maze "<<endl
        <<"4 back to login portal"<<endl
        <<"0 to exit from game"<<endl;
            A:
            cin>>choice;   
            system("cls");        
            switch (choice)
            {
                case '1':
                        Instruction();
                    game.showMap();
                    while(true){
                        game.timev();
                        game.enemymove();
                    if(_kbhit())
                    if(!(game.action(getch())))
                    {cout<<"press "<<endl
                        <<"1 to move to next level"<<endl
                        <<"4 back to login portal"<<endl
                        <<"0 to exit from game"<<endl;
                        goto A ;

                        }
                    }
                    // cout<<"working on class"<<endl;

                break;

        
                case '2':
                    cout<<"Top 10 Hight score"<<endl;
                  ss.showRecordScore(menuData());
                    

                break;
                case '3':
                    cout<<"Top 10 fastest Time"<<endl;
                  ss.showRecordTime(menuData());

                    
                case '4' :
                    cout<<"going back to login ";
                break;
                case '0':
                    exit(0);
                default:
                    cout<<"invalid input";
                break;
            }
            system("pause");
        }while(choice!='4');
    }
 
void color(int a){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
    };

void sleep(int x){
    Sleep(x);
slp=slp+x;
}
  
void Instruction(){
      

     int x=35;
        color(14);
        gotoxy(x,1);
        cout<<"##############################################";
        gotoxy(x,2);
        cout<<"#######";color(9);
        cout<<"     M A Z E   R U N N E R ";color(14);
        cout<<"    ########";
        gotoxy(x,3);
        cout<<"##############################################";color(15);
        gotoxy(x,5);
            color(13);
            cout<<"            I N S T R U C T I O N S         ";    
      gotoxy(x,7);
      color(10);
      cout<<"1. Player will have 3 lives.";
      gotoxy(x,8);
      color(11);
      cout<<"2. Every hit by an enemy will decrease the HP of the player.";
      color(9);
      gotoxy(x,9);
      cout<<"3. After all the HP is dropped, the Player will lose one life.";
      color(12);
      gotoxy(x,10);
      cout<<"4. There will be keys according to the level, after collecting";
      gotoxy(x,11);
      cout<<"   all the keys an exiting will be appear.";
        color(6);
      gotoxy(x,12);
      cout<<"5. There are a total of 5 levels, after completing one level ";
      gotoxy(x,13);
      cout<<"   difficulty of the next level will be increased.";
      color(15);
      cout<<endl<<endl;
      cout<<endl<<endl;
      system("pause");
      system("cls");
  }

void sortdec(int *s,int a){
    for(int i=0,temp=0;i<a;i++){		
        for(int j=i+1;j<a;j++){
            if(s[i]<s[j]){
                temp  =s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
}
