#include<iostream>
using namespace std;
void display(char a[][3]){
	for(int i=0;i<3;i++){
			cout<<"\t"<<a[i][0]<<"\t"<<a[i][1]<<"\t"<<a[i][2]<<endl;
	}
}
bool check(char a[][3],char c){
	bool f1=true;
	bool f2=true;
	//linear check
	for(int i=0;i<3;i++){
		f1=f2=true;
		for(int j=0;j<3;j++){
			if(a[i][j]!=c) f1=false;
			if(a[j][i]!=c) f2=false;
		}
		if(f1||f2) return true;
	}
	//diagonal check
	f1=f2=true;
	for(int i=0;i<3;i++){
			if(a[i][i]!=c) f1=false;
			if(a[i][2-i]!=c) f2=false;
	}
	if(f1||f2) return true;
	return 0;
}
int main()
{
	char a[3][3],choice1,choice2,name1[100],name2[200];
	bool flag=true;
	
	for(int i=0;i<3;i++){ 
		for(int j=0;j<3;j++) 
			a[i][j]=0;
	}

	int r,c,r1,c1;
	cout<<"WELCOME TO TIC TAC TOE WORLD"<<endl;
	cout<<"Enter the name of player1:\t"<<endl;
	cin>>name1;
	cout<<"Enter the name of player2:\t"<<endl;
	cin>>name2;
	cout<<"The positioning of choices will be like this :"<<endl;
	cout<<"\t[1][1]\t[1][2]\t[1][3]"<<endl;
	cout<<"\t[2][1]\t[2][2]\t[2][3]"<<endl;
	cout<<"\t[3][1]\t[3][2]\t[3][3]"<<endl;
	while(flag){
		cout<<"\nNow choose your symbol, "<<name1<<" :";
		cin>>choice1;
		if(choice1=='X' || choice1=='O') flag=false; 
		else cout<<"INVALID \n";
	}
	if(choice1=='X') choice2='O';
	else choice2='X';

	cout<<name1<<"'s symbol is "<<choice1<<endl;
	cout<<name2<<"'s symbol is "<<choice2<<endl;
	
	cout<<"LET'S START THE GAME"<<endl;
	cout<<"ENTER YOUR TURN IN THIS WAY : [row]space[column]";

	//game loop
	for(int i=0;i<5;i++)
	{
		cout<<"\nIt's your turn, "<<name1<<" :";
		cin>>r>>c;
		while(a[r-1][c-1]!=0 || r<1 || r>3 || c<1 || c>3){
			cout<<"INVALID INPUT ENTER AGAIN : ";
			cin>>r>>c;
		}
		a[r-1][c-1]=choice1;
		display(a);
		if(check(a,choice1)){
			cout<<"CONGRATULATIONS "<<name1<<",YOU WON"<<endl;
			exit(0);
		}
		else if(i==4){
			cout<<"IT's A DRAW"<<endl;
			exit(0);
		}
		cout<<"\nIt's your turn, "<<name2<<" :";
		cin>>r1>>c1;
		while(r1==r&&c1==c || r1>3 || r1<1|| c1>3 || c1<1)
		{
			cout<<"INVALID INPUT,ENTER AGAIN : ";
			cin>>r1>>c1;
		}
		a[r1-1][c1-1]=choice2;
		display(a);
		if(check(a,choice2)){
			cout<<"CONGRATULATIONS "<<name2<<",YOU WON"<<endl;
			exit(0);
		}
		else if(i==5){	
			cout<<"IT's A DRAW"<<endl;
			exit(0);
		}
	}
	return 0;
}