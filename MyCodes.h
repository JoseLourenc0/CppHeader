#ifndef MYCODES_H_INCLUDED
#define MYCODES_H_INCLUDED
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
using namespace std;
fstream file;
int HowMany(){
    int i=0;
    bool b=true;
    while(b==true){
        string txt = "textfiles/textfile"+to_string(i)+".txt",line;
        file.open(txt,ios::in);
        if(file.is_open()){
            if(getline(file,line)){
                i++;
                if(line==""){
                    b=false;
                }
            }
        }else{
            b=false;
        }
        file.close();
    }
    return i;
}
void ReadFile(int n){
    n--;
    string txt = "textfiles/textfile"+to_string(n)+".txt",line;
    file.open(txt,ios::in);
    if(file.is_open()){
        while(getline(file,line)){
            cout<<line<<endl;
        }
    }else{
        cout<<"Couldn't reach your file"<<endl;
    }
    file.close();
}
void FilesList(){
    int i=0;
    bool b=true;
    cout<<"Files list:"<<endl;
    while(b==true){
        string txt = "textfiles/textfile"+to_string(i)+".txt",line;
        file.open(txt,ios::in);
        if(file.is_open()){
            if(getline(file,line)){
                i++;
                if(line!=""){
                    cout<<"File "<<i<<endl;
                }else{
                    b=false;
                }
            }
        }else{
            b=false;
        }
        file.close();
    }
}
void WriteNewFile(){
    int i=0,age=0;
    bool b=true;
    string name="";
    while(b==true){
        string txt = "textfiles/textfile"+to_string(i)+".txt",line;
        file.open(txt,ios::in);
        if(file.is_open()){
            if(getline(file,line)){
                i++;
                if(line==""){
                    b=false;
                }
            }
        }else{
            b=false;
        }
        file.close();
    }
    string txt="textfiles/textfile"+to_string(i)+".txt";
    file.open(txt,ios::out);
    cout<<"What's your name?"<<endl;
    cin>>name;
    file<<name<<"\n";
    cout<<"How old are you?"<<endl;
    cin>>age;
    file<<age;
    file.close();
}
void RegisterQuestion(){
    int i=0,k=0;
    bool b=true;
    string question,answer;
    char c,char_question[300],char_answer[300];
    while(b==true){
        string txt = "textfiles/textfile"+to_string(i)+".txt",line;
        file.open(txt,ios::in);
        if(file.is_open()){
            if(getline(file,line)){
                i++;
                if(line==""){
                    b=false;
                }
            }
        }else{
            b=false;
        }
        file.close();
    }
    string txt="textfiles/textfile"+to_string(i)+".txt";
    file.open(txt,ios::out);
    cout<<"Register your question: ";
    while((c=getch())!=13){ //13=ENTER
        char_question[k]=c;
        if(c!=8){
        k++;
        cout<<c;
        }else{
            k--;
            cout<<c<<" "<<c;
        }
    }
    char_question[k]='\0';
    question=char_question;
    file<<question<<"\n";
    k=0;
    cout<<"\nRegister your answer: ";
    while((c=getch())!=13){ //13=ENTER
        char_answer[k]=c;
        if(c!=8){
        k++;
        cout<<c;
        }else{
            k--;
            cout<<c<<" "<<c;
        }
    }
    char_answer[k]='\0';
    answer=char_answer;
    file<<answer;
    file.close();
    cout<<endl;
}
int RandomFile(){
    srand(time(NULL));
    int i=HowMany();
    int v=rand()%i+1;
    return v;
}
void SetColor(int ForgC){
        WORD wColor;
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
/*
Black        |   0
Blue         |   1
Green        |   2
Cyan         |   3
Red          |   4
Magenta      |   5
Brown        |   6
Light Gray   |   7 ==>Standard console font color
Dark Gray    |   8
Light Blue   |   9
Light Green  |   10
Light Cyan   |   11
Light Red    |   12
Light Magenta|   13
Yellow       |   14
White        |   15
By: Joss Bird -> https://stackoverflow.com/questions/29574849/how-to-change-text-color-and-console-color-in-codeblocks
*/
}
void TryQuestion(int number){
    number--;
    int i=0,k=0;
    string question,answer,useranswer;
    char c,char_answer[300];
    string txt = "textfiles/textfile"+to_string(number)+".txt",line;
    file.open(txt,ios::in);
    if(file.is_open()){
        while(getline(file,line)){
            if(i==0){
                question=line;
            }
            if(i==1){
                answer=line;
            }
            i++;
        }
    }else{
        cout<<"\t===Couldn't reach your file==="<<endl;
    }
    file.close();
    cout<<"\t=======================\n\t   Question number "<<++number<<"\n\t======================="<<endl;
    cout<<"Question: "<<question<<endl;
    cout<<"Answer: ";
    while((c=getch())!=13){ //13=ENTER
        char_answer[k]=c;
        if(c!=8){
        k++;
        cout<<c;
        }else{
            k--;
            cout<<c<<" "<<c;
        }
    }
    char_answer[k]='\0';
    useranswer=char_answer;
    cout<<endl;
    if(useranswer==answer){
        SetColor(2);
        cout<<"You're right, cool"<<endl;
        SetColor(7);
    }else{
        SetColor(12);
        cout<<"You're wrong"<<endl;
        SetColor(7);
    }
}

//TYPING CODES
void TypeWrite(string txt){
    for(int i=0;i<txt.size();i++){
        cout<<txt[i];
        Sleep(60);
    }
}
void TypeWriteWS(string txt,int t){
    for(int i=0;i<txt.size();i++){
        cout<<txt[i];
        Sleep(t);
    }
}
void CleanWindow(float t){
    Sleep(t*1000);
    system("cls");
}
void EraseText(int N){
    char c=8;
    for(int i=0;i<N;i++){
        cout<<c<<" "<<c;
    }
}
void TypeWriteEraseText(int N){
    char c=8;
    for(int i=0;i<N;i++){
        cout<<c<<" "<<c;
        Sleep(60);
    }
}
void TypeWriteEraseTextWS(int N,int t){
    char c=8;
    for(int i=0;i<N;i++){
        cout<<c<<" "<<c;
        Sleep(t);
    }
}
#endif // MYCODES_H_INCLUDED
