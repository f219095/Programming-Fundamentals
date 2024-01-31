#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<unistd.h>
using namespace std;

const int SIZE = 9;
int score=0;
int moves=10;

	
void wrapwrap(int board[][SIZE],int a,int b,int x,int y)
{
	if(a>=49 && a<=52 && b>=49 && b<=52)
	{
		for(int c=x;c>0;c--)
 				{
 					board[c+2][y]=board[c-3][y];
 					board[c+2][y+1]=board[c-3][y+1];
 					board[c+2][y-1]=board[c-3][y-1];
 					board[c+2][y+2]=board[c-3][y+2];
 					board[c+2][y-2]=board[c-3][y-2];
 					
 					
				 }
				   for(int b=0;b<5;b++)
				   {
				   	   board[b][y]=rand()%4+33;
				   	   board[b][y+1]=rand()%4+33;
				   	   board[b][y-1]=rand()%4+33;
				   	   board[b][y-2]=rand()%4+33;
				   	   board[b][y+2]=rand()%4+33;
				   	   
				   	
				   } 
				 
	}
}
void stripwrap(int board[][SIZE],int a,int b,int x,int y)
{
	if(((a>=37 && a<=40) || (a>=109 && a<=112)) && (b>=49 && b<=52)) 
	{
		for(int i=0;i<9;i++)
		{
			board[i][y]=rand()%4+33;
			board[i][y-1]=rand()%4+33;
			board[i][y+1]=rand()%4+33;
		}
		for(int j=x;j>0;j--)
		{
			for(int k=0;k<9;k++)
			{
			
			board[j+1][k]=board[j-2][k];
			
		    } 
		}
		for(int z=0;z<9;z++)
		{
			board[0][z]=rand()%4+33;
			board[1][z]=rand()%4+33;
			board[2][z]=rand()%4+33;
			
		}
    }
	
	
}
void wrapbomb(int board[][SIZE],int a,int b,int x,int y)
{
	
	if(a==43 && b>=49 && b<=52)
	{
		for(int c=x;c>0;c--)
 				{
 					board[c+2][y]=board[c-1][y];
 					board[c+2][y+1]=board[c-1][y+1];
 					board[c+2][y-1]=board[c-1][y-1];
 					
				 }
				   for(int b=0;b<3;b++)
				   {
				   	   board[b][y]=rand()%4+33;
				   	   board[b][y+1]=rand()%4+33;
				   	   board[b][y-1]=rand()%4+33;
				   	
				   } 
				 
	}
	if(b==43 && a>=49 && a<=52)
	{
		for(int c=x;c>0;c--)
 				{
 					board[c+2][y]=board[c-1][y];
 					board[c+2][y+1]=board[c-1][y+1];
 					board[c+2][y-1]=board[c-1][y-1];
 					
				 }
				   for(int b=0;b<3;b++)
				   {
				   	   board[b][y]=rand()%4+33;
				   	   board[b][y+1]=rand()%4+33;
				   	   board[b][y-1]=rand()%4+33;
				   	
				   } 
				 
	}
}
void stripbomb(int board[][SIZE],int a,int b,int x,int y)
{
	if((a==43 &&(b==37 || b==109)) || (b==43 &&(a==37 || a==109)))
	{
	
	for(int i=0;i<9;i++)
	{
		board[i][y]=rand()%4+33;
		
	}
	for(int j=x;j>0;j--)
	{
		for(int k=0;k<9;k++)
		{
		
		board[j][k]=board[j-1][k];
	    }
	}
	for(int i=0;i<9;i++)
	{
		board[0][i]=rand()%4+33;
	}
    }
	if((a==43 &&(b==38 || b==110)) || (b==43 &&(a==38 || a==110)))
	{
	
	for(int i=0;i<9;i++)
	{
		board[i][y]=rand()%4+33;
		
	}
	for(int j=x;j>0;j--)
	{
		for(int k=0;k<9;k++)
		{
		
		board[j][k]=board[j-1][k];
	    }
	}
	for(int i=0;i<9;i++)
	{
		board[0][i]=rand()%4+33;
	}
    }
	if((a==43 &&(b==39 || b==111)) || (b==43 &&(a==39 || a==111)))
	{
	
	for(int i=0;i<9;i++)
	{
		board[i][y]=rand()%4+33;
		
	}
	for(int j=x;j>0;j--)
	{
		for(int k=0;k<9;k++)
		{
		
		board[j][k]=board[j-1][k];
	    }
	}
	for(int i=0;i<9;i++)
	{
		board[0][i]=rand()%4+33;
	}
    }
	if((a==43 &&(b==40 || b==112)) || (b==43 &&(a==40 || a==112)))
	{
	
	for(int i=0;i<9;i++)
	{
		board[i][y]=rand()%4+33;
		
	}
	for(int j=x;j>0;j--)
	{
		for(int k=0;k<9;k++)
		{
		
		board[j][k]=board[j-1][k];
	    }
	}
	for(int i=0;i<9;i++)
	{
		board[0][i]=rand()%4+33;
	}
	
    }
}
void bombbomb(int board[][SIZE],int a,int b)
{
	if(a==43 && b==43)
	{
		int i,j,symbol;
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			do{
				
			symbol=rand()%4;
		      }while(board[i][j-1]-33==symbol || board[i-1][j]-33==symbol);
			switch(symbol)
			{
				case 0 :
				board[i][j]=33;
				break;
				case 1 :
				board[i][j]=34;
				break;
				case 2 :
				board[i][j]=35;
				break;
				case 3 :
				board[i][j]=36;
				break;
				
				default :
				cout<<"Error!"<<endl;
				break;
			 } 
		}
		
	 
	}
	}
}
 void plainbomb(int board[][SIZE],int a,int b)
 {
 	if(a==43)
 	{
 	
		
		 
 	   for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++)
			{
				
				if(board[i][j]==b)
				{
					for(int x=i;x>0;x--)
					{
						board[x][j]=board[x-1][j];
					}
					board[0][j]=rand()%4+33;
				}
			}
			
		}	
	}
	if(b==43)
 	{
 	
		
		 
 	   for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++)
			{
				
				if(board[i][j]==a)
				{
					for(int x=i;x>0;x--)
					{
						board[x][j]=board[x-1][j];
					}
					board[0][j]=rand()%4+33;
				}
			}
			
		}	
	}
    
 }
 
bool check(int option,int element,int column)
{
	if(option==1 && column==0) 
				{
				 cout<<"Invalid"<<endl;
				 return false;
				}
				
				if(option==2 && column==8)
				{
				
				  cout<<"Invalid"<<endl;
				 return false;
				    
		     	}
			
				if(option==3 && element ==0)
				{
				cout<<"Invalid"<<endl;
				 return false;
			
				
			    }
				if(option== 4 && element==8) 
				{
				  cout<<"Invalid"<<endl;
				 return false;
			    }
				if(option>4)
				{
				cout<<"Error!"<<endl;
				return false;
          		}
          		else 
          		return true;
}
void gameheader(){
	cout<<endl;
	
	cout<<"**************************************************"<<endl;

	cout<<endl;
	cout << "\n\t\t\t   _____                _          _____                _     " << endl;
                    cout << "\t\t\t  / ____|              | |        / ____|              | |    " << endl;
                    cout << "\t\t\t | |     __ _ _ __   __| |_   _  | |     _ __ _   _ ___| |__  " << endl;
                    cout << "\t\t\t | |    / _` | '_ \\ / _` | | | | | |    | '__| | | / __| '_ \\ " << endl;
                    cout << "\t\t\t | |___| (_| | | | | (_| | |_| | | |____| |  | |_| \\__ \\ | | |" << endl;
                    cout << "\t\t\t  \\_____\\__,_|_| |_|\\__,_|\\__, |  \\_____|_|   \\__,_|___/_| |_|" << endl;
                    cout << "\t\t\t                           __/ |                              " << endl;
                    cout << "\t\t\t                          |___/                               " << endl;
	cout<<"This program will randomly initilize your game board using"<<endl;
	cout<<"a set of 4 characters (!,<<static_cast<char>(Double Quote)<<,#,$) that a player will win"<<endl;
	cout<<"if he/she gain specific points in finite moves"<<endl;
	//cout<<"Press L to REload the previous game"<<endl;
	cout<<endl;
	usleep(3000000);
	
	  
	for (int k = 5; k > 0; k--) 
	           {
                   system("cls"); 
                    cout << "\n\n\n\n\n\t\t\t\t\t\tGame starts in: " << k << endl << endl;
                    cout << "\n\n\n\t\t\t     It is recommended that you play the game in fullscreen\n";
                    cout << "\n\t\t\t     YOU NEED TO SCORE 200 PLUS \n";
                    // cout << "\n\t\t\t     Press S to save the game \n";
                    cout << "\n\t\t\t     You have a total of 20 moves and  too much time\n";
                   
					usleep(3000000);
                }
                system("cls");
               
	
}
void createBoard(int board[][SIZE])
{
	int i,j,symbol;
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			do{
				
			symbol=rand()%4;
		      }while(board[i][j-1]-33==symbol || board[i-1][j]-33==symbol);
			switch(symbol)
			{
				case 0 :
				board[i][j]=33;
				break;
				case 1 :
				board[i][j]=34;
				break;
				case 2 :
				board[i][j]=35;
				break;
				case 3 :
				board[i][j]=36;
				break;
				
				default :
				cout<<"Error!"<<endl;
				break;
			 } 
		}
		
	 
	}
	return;
	
}
void displayboard(int board[][SIZE])
{
	
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	
	int letter =65;
	cout<<"                    ...Initializing Board...."<<endl;
	cout<<"                    ....MOVES REMAINING..... "<<moves<<endl;
	cout<<"                    .........SCORE..........."<<score<<endl;
	cout<<"                        1 2 3 4 5 6 7 8 9"<<endl;
	cout<<"                        *****************"<<endl;
	for(int i=0;i<SIZE;i++)
	{
		
	    cout<<"                    "<<static_cast<char>(letter)<<" | ";
	    
	
	for(int j=0;j<SIZE;j++)
	{
	    cout<<static_cast<char>(board[i][j])<<" ";
	}
	cout<<"|\n";
	letter++;
	
    }
   cout<<"                        *****************"<<endl;
  return;
  }
  void swapboard(int board[][SIZE])
  {
  	char row,column,option;
  	int element=0,a,b,answer;
  	do
  {
  	if(element!=0)
  	{
  	   cout<<"Error WroNG Value Plz Enter Again"<<endl;	
	}
	cout<<"Enter the Row Alphabet for which element you want to excess"<<endl;
  	cin>>row;
  	cout<<"Enter the Column Number for which element you want to excess"<<endl;
  	cin>>column;
  	
  	element++;
  }while((row<65 || row>73) || (column<48 || column >57));
    column=static_cast<int>(column-48);
  	element=static_cast<int>(row-65);
  	column=column-1;
  	 a=board[element][column];
  	 
  	do{
	  
	cout<<"Enter the number"<<endl;
  	cout<<"1. To move Left"<<endl;
  	cout<<"2. To move Right"<<endl;
  	cout<<"3. To move Up"<<endl;
  	cout<<"4. To move Down"<<endl;
  	cin>>option;
  	option=option-48;
  	answer=check(option,element,column);
  	
  	}while(!answer);
  	
			
				if(option==1) 
				{
				b=board[element][column-1];
				board[element][column-1]=a;
				board[element][column]=b;
				
				}
				
				if(option==2)
				{
				
				b=board[element][column+1];
				board[element][column+1]=a;
				board[element][column]=b;
				
		     	}
			
				if(option==3)
				{
				
				b=board[element-1][column];
				board[element-1][column]=a;
				board[element][column]=b;
				
				
			    }
				if(option== 4) 
				{
				b=board[element+1][column];
				board[element+1][column]=a;
				board[element][column]=b;
				
			    }
			
			plainbomb(board,a,b);
			bombbomb(board,a,b);
			stripbomb(board,a,b,element,column);
			wrapbomb(board,a,b,element,column);
			stripwrap(board,a,b,element,column);
	        wrapwrap(board,a,b,element,column);
  	return;
  }
 
  void newboard(int board [][SIZE])
  {
  	for(int i=0;i<SIZE;i++)
  	 {
  	 	for(int j=0;j<SIZE;j++)
  	 	{
  	 		if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j==0  && i==0)
  	 		 { 
  	 		    
  	 		      if(board[i][j]==33 || board[i][j]==34 )
  	 		      {
  	 		      	score=score+1000;
				  }
				  else if(board[i][j]==35  )
  	 		      {
  	 		      	score=score+40;
				  }
				 else if(board[i][j]==36  )
  	 		      {
  	 		      	score=score+50;
				  }
  	 		      board[i][j]=rand()%4+33;
  	 		      board[i+1][j]=rand()%4+33;
  	 		      board[i+2][j]=rand()%4+33;
  	 		      
				  
  	 		      
		     }
		     
		     

  	 		      
		     
		    if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j==0 && i!=0 )
  	 		 { 
  	 		     
  	 		     if(board[i][j]==33 || board[i][j]==34 )
  	 		      {
  	 		      	score=score+30;
				  }
				  else if(board[i][j]==35  )
  	 		      {
  	 		      	score=score+40;
				  }
				 else if(board[i][j]==36  )
  	 		      {
  	 		      	score=score+50;
				  }
  	 		      for(int k=i;k>0;k--)
				 {
				   
				   board[k+2][j]=board[k-1][j];
				   
				   
 
  	 		     }
  	 		      board[0][j]=rand()%4+33;
  	 		      board[1][j]=rand()%4+33;
  	 		      board[2][j]=rand()%4+33;
  	 		     
  	 		      
		     }
		      if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j!=0 && i!=0 )
  	 		 { 
  	 		 
  	 		     if(board[i][j]==33 || board[i][j]==34 )
  	 		      {
  	 		      	score=score+30;
				  }
				  else if(board[i][j]==35  )
  	 		      {
  	 		      	score=score+40;
				  }
				 else if(board[i][j]==36  )
  	 		      {
  	 		      	score=score+50;
				  }
  	 		     for(int k=i;k>0;k--)
				 {
				   
				   board[k+2][j]=board[k-1][j];
				   
				   
 
  	 		     }
  	 		      board[0][j]=rand()%4+33;
  	 		      board[1][j]=rand()%4+33;
  	 		      board[2][j]=rand()%4+33;
  	 		      

  	 		      
		     }
		      if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j!=0 && i==0 )
  	 		 { 
  	 		     if(board[i][j]==33 || board[i][j]==34 )
  	 		      {
  	 		      	score=score+30;
				  }
				  else if(board[i][j]==35  )
  	 		      {
  	 		      	score=score+40;
				  }
				 else if(board[i][j]==36  )
  	 		      {
  	 		      	score=score+50;
				  }
  	 		      board[i][j]=rand()%4+33;
  	 		      board[i+1][j]=rand()%4+33;
  	 		      board[i+2][j]=rand()%4+33;
  	 		      

  	 		      
		     }
		     
		     if(board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2]  && i==0)
		     
		     {
		     	 if(board[i][j]==33 || board[i][j]==34 )
  	 		      {
  	 		      	score=score+30;
				  }
				  else if(board[i][j]==35  )
  	 		      {
  	 		      	score=score+40;
				  }
				 else if(board[i][j]==36  )
  	 		      {
  	 		      	score=score+50;
				  }
		     	  board[i][j]=rand()%4+33;
  	 		      board[i][j+1]=rand()%4+33;
  	 		      board[i][j+2]=rand()%4+33;
  	 		      
		     	
			 }
			 
			  if(board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2] && i!=0 )
  	 		 { 
  	 		      if(board[i][j]==33 || board[i][j]==34 )
  	 		      {
  	 		      	score=score+30;
				  }
				  else if(board[i][j]==35  )
  	 		      {
  	 		      	score=score+40;
				  }
				 else if(board[i][j]==36  )
  	 		      {
  	 		      	score=score+50;
				  }
  	 		      for(int k=i;k>0;k--)
				 {
				   board[k][j]=board[k-1][j];
  	 		       board[k][j+1]=board[k-1][j+1];
  	 		       board[k][j+2]=board[k-1][j+2];
  	 		     }
  	 		      board[0][j]=rand()%4+33;
  	 		      board[0][j+1]=rand()%4+33;
  	 		      board[0][j+2]=rand()%4+33;
  	 		      
  	 		      
		     }
			 
	 }
  }
}
  void stripcandy(int board[][SIZE])
  {
  	
  	 for(int i=0;i<SIZE;i++)
  	 {
  	 	for(int j=0;j<SIZE;j++)
  	 	{
  	 		if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j==0 &&i==0 && board[i][j]==board[i+3][j] && board[i][j]==33 && j<7)
  	 		 { 
  	 		      board[i][j]=rand()%4+33;
  	 		      board[i+1][j]=rand()%4+33;
  	 		      board[i+2][j]=rand()%4+33;
  	 		      board[i+3][j]=37;
		     }
		    if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j==0 &&i==0 && board[i][j]==board[i+3][j] && board[i][j]==34 && j<7 ) 
  	 		 { 
  	 		      board[i][j]=rand()%4+33;
  	 		      board[i+1][j]=rand()%4+33;
  	 		      board[i+2][j]=rand()%4+33;
  	 		      board[i+3][j]=38;
		     }
		    if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j==0 &&i==0 && board[i][j]==board[i+3][j] && board[i][j]==35 && j<7)
  	 		 { 
  	 		      board[i][j]=rand()%4+33;
  	 		      board[i+1][j]=rand()%4+33;
  	 		      board[i+2][j]=rand()%4+33;
  	 		      board[i+3][j]=39;
		     }
		     	if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j==0 &&i==0 && board[i][j]==board[i+3][j] && board[i][j]==36 && j<7 )
  	 		 { 
  	 		      board[i][j]=rand()%4+33;
  	 		      board[i+1][j]=rand()%4+33;
  	 		      board[i+2][j]=rand()%4+33;
  	 		      board[i+3][j]=40;
		     }
		     if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j==0 && i!=0 && board[i][j]==board[i+3][j] && board[i][j]==36 && j<7 )
  	 		 { 
  	 		     board[i+3][j]=40;
  	 		      for(int k=i;k>0;k--)
				 {
				   
				   board[k+2][j]=board[k-1][j];
				   
				   
 
  	 		     }
  	 		      board[0][j]=rand()%4+33;
  	 		      board[1][j]=rand()%4+33;
  	 		      board[2][j]=rand()%4+33;
  	 		    
  	 		    
  	 		   
		     }
		     if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j==0 && i!=0 && board[i][j]==board[i+3][j] && board[i][j]==35 && j<7 )
  	 		 { 
  	 		     board[i+3][j]=39;
  	 		      for(int k=i;k>0;k--)
				 {
				   
				   board[k+2][j]=board[k-1][j];
				   
				   
 
  	 		     }
  	 		      board[0][j]=rand()%4+33;
  	 		      board[1][j]=rand()%4+33;
  	 		      board[2][j]=rand()%4+33;
  	 		    
  	 		   
		     }
		     if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j==0 && i!=0 && board[i][j]==board[i+3][j] && board[i][j]==34 && j<7 )
  	 		 { 
  	 		     board[i+3][j]=38;
  	 		      for(int k=i;k>0;k--)
				 {
				   
				   board[k+2][j]=board[k-1][j];
				   
				   
 
  	 		     }
  	 		      board[0][j]=rand()%4+33;
  	 		      board[1][j]=rand()%4+33;
  	 		      board[2][j]=rand()%4+33;
  	 		    
  	 		   
		     }
		     if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j==0 && i!=0 && board[i][j]==board[i+3][j] && board[i][j]==33 && j<7)
  	 		 { 
  	 		     board[i+3][j]=37;
  	 		      for(int k=i;k>0;k--)
				 {
				   
				   board[k+2][j]=board[k-1][j];
				   
				   
 
  	 		     }
  	 		      board[0][j]=rand()%4+33;
  	 		      board[1][j]=rand()%4+33;
  	 		      board[2][j]=rand()%4+33;
  	 		      
  	 		    
  	 		   
		     }
		     
		     
		     if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j!=0 && i==0  && board[i][j]==board[i+3][j]  && board[i][j]==33 && j<7)
  	 		 { 
  	 		      board[i][j]=rand()%4+33;
  	 		      board[i+1][j]=rand()%4+33;
  	 		      board[i+2][j]=rand()%4+33;
                  board[i+3][j]=37;
  	 		      
		     }
		     if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j!=0 && i==0  && board[i][j]==board[i+3][j]  && board[i][j]==34 && j<7)
  	 		 { 
  	 		      board[i][j]=rand()%4+33;
  	 		      board[i+1][j]=rand()%4+33;
  	 		      board[i+2][j]=rand()%4+33;
                  board[i+3][j]=38;
  	 		      
		     }
		     if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j!=0 && i==0  && board[i][j]==board[i+3][j]  && board[i][j]==35 && j<7 )
  	 		 { 
  	 		      board[i][j]=rand()%4+33;
  	 		      board[i+1][j]=rand()%4+33;
  	 		      board[i+2][j]=rand()%4+33;
                  board[i+3][j]=39;
  	 		      
		     }
		     if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j!=0 && i==0  && board[i][j]==board[i+3][j]  && board[i][j]==36 && j<7)
  	 		 { 
  	 		      board[i][j]=rand()%4+33;
  	 		      board[i+1][j]=rand()%4+33;
  	 		      board[i+2][j]=rand()%4+33;
                  board[i+3][j]=40;
  	 		      
		     }
		     
		     
		     if(board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2] && board[i][j]==board[i][j+3]  && i==0 && board[i][j]==33 && i<7)
		     
		     {
		     	  board[i][j]=109;
		     	  board[i][j+1]=rand()%4+33;
  	 		      board[i][j+2]=rand()%4+33;
  	 		      board[i][j+3]=rand()%4+33;
		     	
			 }
			 if(board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2] && board[i][j]==board[i][j+3]  && i==0 && board[i][j]==34 && i<7)
		     
		     {
		     	  board[i][j]=110;
		     	  board[i][j+1]=rand()%4+33;
  	 		      board[i][j+2]=rand()%4+33;
  	 		      board[i][j+3]=rand()%4+33;
		     	
			 }
			 if(board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2] && board[i][j]==board[i][j+3]  && i==0 && board[i][j]==35 && i<7)
		     
		     {
		     	  board[i][j]=111;
		     	  board[i][j+1]=rand()%4+33;
  	 		      board[i][j+2]=rand()%4+33;
  	 		      board[i][j+3]=rand()%4+33;
		     	
			 }
			 if(board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2] && board[i][j]==board[i][j+3]  && i==0 && board[i][j]==36 && i<7)
		     
		     {
		     	  board[i][j]=112;
		     	  board[i][j+1]=rand()%4+33;
  	 		      board[i][j+2]=rand()%4+33;
  	 		      board[i][j+3]=rand()%4+33;
		     	
			 }
			 
			  if( board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2] && board[i][j]==board[i][j+3]  && i!=0 && board[i][j]==36 && i<7)
  	 		 { 
  	 		      board[i][j]=112;
  	 		      for(int k=i;k>0;k--)
				 {
				   board[k][j+1]=board[k-1][j+1];
  	 		       board[k][j+2]=board[k-1][j+2];
  	 		       board[k][j+3]=board[k-1][j+3];
  	 		     }
  	 		      board[0][j+1]=rand()%4+33;
  	 		      board[0][j+2]=rand()%4+33;
  	 		      board[0][j+3]=rand()%4+33;
  	 		      
		     }
			 if( board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2] && board[i][j]==board[i][j+3]  && i!=0 && board[i][j]==35 && i<7)
  	 		 { 
  	 		      board[i][j]=111;
  	 		       for(int k=i;k>0;k--)
				 {
				   board[k][j+1]=board[k-1][j+1];
  	 		       board[k][j+2]=board[k-1][j+2];
  	 		       board[k][j+3]=board[k-1][j+3];
  	 		     }
  	 		      board[0][j+1]=rand()%4+33;
  	 		      board[0][j+2]=rand()%4+33;
  	 		      board[0][j+3]=rand()%4+33;
  	 		      
		     }
		     if( board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2] && board[i][j]==board[i][j+3]  && i!=0 && board[i][j]==34 && i<7)
  	 		 { 
  	 		      board[i][j]=110;
  	 		       for(int k=i;k>0;k--)
				 {
				   board[k][j+1]=board[k-1][j+1];
  	 		       board[k][j+2]=board[k-1][j+2];
  	 		       board[k][j+3]=board[k-1][j+3];
  	 		     }
  	 		      board[0][j+1]=rand()%4+33;
  	 		      board[0][j+2]=rand()%4+33;
  	 		      board[0][j+3]=rand()%4+33;
  	 		      
		     }
		      if( board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2] && board[i][j]==board[i][j+3]  && i!=0 && board[i][j]==33  && i<7)
  	 		 { 
  	 		      board[i][j]=109;
  	 		      for(int k=i;k>0;k--)
				 {
				   board[k][j+1]=board[k-1][j+1];
  	 		       board[k][j+2]=board[k-1][j+2];
  	 		       board[k][j+3]=board[k-1][j+3];
  	 		     }
  	 		      board[0][j+1]=rand()%4+33;
  	 		      board[0][j+2]=rand()%4+33;
  	 		      board[0][j+3]=rand()%4+33;
		     }
		      if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j!=0 && i!=0 &&  board[i][j]==board[i+3][j] && board[i][j]==33 && j<7)
  	 		 { 
  	 		     
  	 		      board[i+3][j]=37;
  	 		     for(int k=i;k>0;k--)
				 {
				   
				   board[k+2][j]=board[k-1][j];
				   
				   
 
  	 		     }
  	 		      board[0][j]=rand()%4+33;
  	 		      board[1][j]=rand()%4+33;
  	 		      board[2][j]=rand()%4+33;
  	 		       

  	 		      
		     }
		     if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j!=0 && i!=0 &&  board[i][j]==board[i+3][j] && board[i][j]==34 && j<7)
  	 		 { 
  	 		      board[i+3][j]=38;
  	 		      for(int k=i;k>0;k--)
				 {
				   
				   board[k+2][j]=board[k-1][j];
				   
				   
 
  	 		     }
  	 		      board[0][j]=rand()%4+33;
  	 		      board[1][j]=rand()%4+33;
  	 		      board[2][j]=rand()%4+33;
  	 		      

  	 		      
		     }
		     if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j!=0 && i!=0 &&  board[i][j]==board[i+3][j] && board[i][j]==35&& j<7)
  	 		 { 
  	 		     board[i+3][j]=39;
  	 		       for(int k=i;k>0;k--)
				 {
				   
				   board[k+2][j]=board[k-1][j];
				   
				   
 
  	 		     }
  	 		      board[0][j]=rand()%4+33;
  	 		      board[1][j]=rand()%4+33;
  	 		      board[2][j]=rand()%4+33;
  	 		      
		     }
			 if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j!=0 && i!=0 &&  board[i][j]==board[i+3][j] && board[i][j]==36&& j<7)
  	 		 { 
  	 		     board[i+3][j]=40;
  	 		      
  	 		       for(int k=i;k>0;k--)
				 {
				   
				   board[k+2][j]=board[k-1][j];
				   
				   
 
  	 		     }
  	 		      board[0][j]=rand()%4+33;
  	 		      board[1][j]=rand()%4+33;
  	 		      board[2][j]=rand()%4+33;
		     }
			 
	 }
  	

}
  
  }
void bomb(int board[][SIZE])
{
	for(int i=0;i<SIZE;i++)
	 {
  	 	for(int j=0;j<SIZE;j++)
  	 	{
  	 		if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j==0  && i==0 && board[i][j]==board[i+3][j] && board[i][j]==board[i+4][j] )
  	 		 { 
  	 		      board[i][j]=rand()%4+33;
  	 		      board[i+1][j]=rand()%4+33;
  	 		      board[i+2][j]=rand()%4+33;
  	 		      board[i+3][j]=rand()%4+33;
  	 		      board[i+4][j]=43;
  	 		      
  	 		      
		     }
		     
		     

  	 		      
		     
		    if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j==0 && i!=0   && board[i][j]==board[i+3][j] && board[i][j]==board[i+4][j])
  	 		 { 
  	 		     board[i+4][j]=43;
  	 		      for(int k=i;k>0;k--)
				 {
				   
				   board[k+3][j]=board[k-1][j];
				   
				   
 
  	 		     }
  	 		      board[0][j]=rand()%4+33;
  	 		      board[1][j]=rand()%4+33;
  	 		      board[2][j]=rand()%4+33;
  	 		      board[3][j]=rand()%4+33;
  	 		      
		     }
		      if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j!=0 && i!=0  && board[i][j]==board[i+3][j] && board[i][j]==board[i+4][j])
  	 		 { 
  	 		    board[i+4][j]=43;
  	 		      for(int k=i;k>0;k--)
				 {
				   
				   board[k+3][j]=board[k-1][j];
 
  	 		     }
  	 		      board[0][j]=rand()%4+33;
  	 		      board[1][j]=rand()%4+33;
  	 		      board[2][j]=rand()%4+33;
  	 		      board[3][j]=rand()%4+33;
  	 		      
		     }
		      if(board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && j!=0 && i==0 && board[i][j]==board[i+3][j] && board[i][j]==board[i+4][j]  )
  	 		 { 
  	 		      board[i][j]=rand()%4+33;
  	 		      board[i+1][j]=rand()%4+33;
  	 		      board[i+2][j]=rand()%4+33;
  	 		      board[i+3][j]=rand()%4+33;
  	 		      board[i+4][j]=43;

  	 		      
		     }
		     
		     if(board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2]  && i==0  && board[i][j]==board[i+3][j] && board[i][j]==board[i][j+4])
		     
		     {
		     	  board[i][j]=43;
  	 		      board[i][j+1]=rand()%4+33;
  	 		      board[i][j+2]=rand()%4+33;
		     	  board[i][j+3]=rand()%4+33;
		     	  board[i][j+4]=rand()%4+33;
		     	  
			 }
			 
			  if(board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2] && i!=0  && board[i][j]==board[i][j+3] && board[i][j]==board[i][j+4] )
  	 		 { 
  	 		      board[i][j]=43;
  	 		      for(int k=i;k>0;k--)
				 {
				   board[k][j+1]=board[k-1][j+1];
  	 		       board[k][j+2]=board[k-1][j+2];
  	 		       board[k][j+3]=board[k-1][j+3];
  	 		       board[k][j+4]=board[k-1][j+4];
  	 		     }
  	 		      board[0][j+1]=rand()%4+33;
  	 		      board[0][j+2]=rand()%4+33;
  	 		      board[0][j+3]=rand()%4+33;
  	 		      board[0][j+4]=rand()%4+33;
  	 		      
  	 		      
  	 		      
		     }
			 
	 }
  }
}
void wrappedcandy(int board[][SIZE])
{
	
	for(int i=0;i<SIZE;i++)
  	 {
  	 	for(int j=0;j<SIZE;j++)
  	 	{
  	 		if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2] && board[i][j]==33 )
  	 		 { 
  	 		      board[i][j]=49;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i;b>0;b--)
				  {
				  	board[b][j+1]=board[b-1][j+1];
				  	board[b][j+2]=board[b-1][j+2];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j+2]=rand()%4+33;
				  
				  
		     }
		     if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2] && board[i][j]==34 )
  	 		 { 
  	 		      board[i][j]=50;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				 
				  for(int b=i;b>0;b--)
				  {
				  	board[b][j+1]=board[b-1][j+1];
				  	board[b][j+2]=board[b-1][j+2];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j+2]=rand()%4+33;
				  
				  
		     }
		     
		     if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2] && board[i][j]==35 )
  	 		 { 
  	 		      board[i][j]=51;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i;b>0;b--)
				  {
				  	board[b][j+1]=board[b-1][j+1];
				  	board[b][j+2]=board[b-1][j+2];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j+2]=rand()%4+33;
				  
				  
		     }
		     
		     if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2] && board[i][j]==36 )
  	 		 { 
  	 		      board[i][j]=52;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i;b>0;b--)
				  {
				  	board[b][j+1]=board[b-1][j+1];
				  	board[b][j+2]=board[b-1][j+2];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j+2]=rand()%4+33;
				  
				  
		     }
		     
		     if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i][j-1] && board[i][j]==board[i][j-2] && board[i][j]==33 )
  	 		 { 
  	 		      board[i][j]=49;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j-2]=board[b-1][j-2];
				  }
				  board[0][j-1]=rand()%4+33;
				  board[0][j-2]=rand()%4+33;
				  
				  
		     }
		      if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i][j-1] && board[i][j]==board[i][j-2] && board[i][j]==34 )
  	 		 { 
  	 		      board[i][j]=50;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j-2]=board[b-1][j-2];
				  }
				  board[0][j-1]=rand()%4+33;
				  board[0][j-2]=rand()%4+33;
				  
				  
		     }
		      if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i][j-1] && board[i][j]==board[i][j-2] && board[i][j]==35)
  	 		 { 
  	 		      board[i][j]=51;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j-2]=board[b-1][j-2];
				  }
				  board[0][j-1]=rand()%4+33;
				  board[0][j-2]=rand()%4+33;
				  
				  
		     }
		      if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i][j-1] && board[i][j]==board[i][j-2] && board[i][j]==36 )
  	 		 { 
  	 		      board[i][j]=52;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				 
				  for(int b=i;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j-2]=board[b-1][j-2];
				  }
				  board[0][j-1]=rand()%4+33;
				  board[0][j-2]=rand()%4+33;
				  
				  
		     }
		     if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-2][j-1] && board[i][j]==board[i-2][j-2] && board[i][j]==33 )
  	 		 { 
  	 		      board[i][j]=49;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				 
				  for(int b=i-2;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j-2]=board[b-1][j-2];
				  }
				  board[0][j-1]=rand()%4+33;
				  board[0][j-2]=rand()%4+33;
				  
				  
		     }
		     if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-2][j-1] && board[i][j]==board[i-2][j-2] && board[i][j]==34 )
  	 		 { 
  	 		      board[i][j]=50;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i-2;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j-2]=board[b-1][j-2];
				  }
				  board[0][j-1]=rand()%4+33;
				  board[0][j-2]=rand()%4+33;
				  
				  
		     }
		     if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-2][j-1] && board[i][j]==board[i-2][j-2] && board[i][j]==35 )
  	 		 { 
  	 		      board[i][j]=51;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i-2;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j-2]=board[b-1][j-2];
				  }
				  board[0][j-1]=rand()%4+33;
				  board[0][j-2]=rand()%4+33;
				  
				  
		     }
		     
		     if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-2][j-1] && board[i][j]==board[i-2][j-2] && board[i][j]==36)
  	 		 { 
  	 		      board[i][j]=52;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i-2;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j-2]=board[b-1][j-2];
				  }
				  board[0][j-1]=rand()%4+33;
				  board[0][j-2]=rand()%4+33;
				  
				  
		     }
		     
		     
             if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-2][j+1] && board[i][j]==board[i-2][j+2] && board[i][j]==33)
  	 		 { 
  	 		      board[i][j]=49;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i-2;b>0;b--)
				  {
				  	board[b][j+1]=board[b-1][j+1];
				  	board[b][j+2]=board[b-1][j+2];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j+2]=rand()%4+33;
				  
				  
		     }

             if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-2][j+1] && board[i][j]==board[i-2][j+2] && board[i][j]==34)
  	 		 { 
  	 		      board[i][j]=50;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i-2;b>0;b--)
				  {
				  	board[b][j+1]=board[b-1][j+1];
				  	board[b][j+2]=board[b-1][j+2];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j+2]=rand()%4+33;
				  
				  
		     }
         if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-2][j+1] && board[i][j]==board[i-2][j+2] && board[i][j]==35)
  	 		 { 
  	 		      board[i][j]=51;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				 
				  for(int b=i-2;b>0;b--)
				  {
				  	board[b][j+1]=board[b-1][j+1];
				  	board[b][j+2]=board[b-1][j+2];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j+2]=rand()%4+33;
				  
				  
		     }

       if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-2][j+1] && board[i][j]==board[i-2][j+2] && board[i][j]==36)
  	 		 { 
  	 		      board[i][j]=52;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i-2;b>0;b--)
				  {
				  	board[b][j+1]=board[b-1][j+1];
				  	board[b][j+2]=board[b-1][j+2];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j+2]=rand()%4+33;
				  
				  
		     }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
             if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-2][j+1] && board[i][j]==board[i-2][j-1] && board[i][j]==33)
  	 		 { 
  	 		      board[i][j]=49;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i-2;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j+1]=board[b-1][j+1];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j-1]=rand()%4+33;
				  
				  
		     }
		     if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-2][j+1] && board[i][j]==board[i-2][j-1] && board[i][j]==34)
  	 		 { 
  	 		      board[i][j]=50;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i-2;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j+1]=board[b-1][j+1];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j-1]=rand()%4+33;
				  
				  
		     }
		     if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-2][j+1] && board[i][j]==board[i-2][j-1] && board[i][j]==35)
  	 		 { 
  	 		      board[i][j]=51;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i-2;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j+1]=board[b-1][j+1];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j-1]=rand()%4+33;
				  
				  
		     }
		     if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-2][j+1] && board[i][j]==board[i-2][j-1] && board[i][j]==36)
  	 		 { 
  	 		      board[i][j]=52;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i-2;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j+1]=board[b-1][j+1];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j-1]=rand()%4+33;
				  
				  
		     }
		     //
			 if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i][j+1] && board[i][j]==board[i][j-1] && board[i][j]==33)
  	 		 { 
  	 		      board[i][j]=49;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j+1]=board[b-1][j+1];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j-1]=rand()%4+33;
				  
				  
		     }
		      if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i][j+1] && board[i][j]==board[i][j-1] && board[i][j]==34)
  	 		 { 
  	 		      board[i][j]=50;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j+1]=board[b-1][j+1];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j-1]=rand()%4+33;
				  
				  
		     }
		      if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i][j+1] && board[i][j]==board[i][j-1] && board[i][j]==35)
  	 		 { 
  	 		      board[i][j]=51;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j+1]=board[b-1][j+1];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j-1]=rand()%4+33;
				  
				  
		     }
		      if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i][j+1] && board[i][j]==board[i][j-1] && board[i][j]==36)
  	 		 { 
  	 		      board[i][j]=52;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j+1]=board[b-1][j+1];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j-1]=rand()%4+33;
				  
				  
		     }
		     //
		      if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-1][j+1] && board[i][j]==board[i-1][j+2] && board[i][j]==33)
  	 		 { 
  	 		      board[i][j]=49;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i-1;b>0;b--)
				  {
				  	board[b][j+1]=board[b-1][j+1];
				  	board[b][j+2]=board[b-1][j+2];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j+2]=rand()%4+33;
				  
				  
		     }
		     if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-1][j+1] && board[i][j]==board[i-1][j+2] && board[i][j]==34)
  	 		 { 
  	 		      board[i][j]=50;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i-1;b>0;b--)
				  {
				  	board[b][j+1]=board[b-1][j+1];
				  	board[b][j+2]=board[b-1][j+2];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j+2]=rand()%4+33;
				  
				  
		     }
		     if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-1][j+1] && board[i][j]==board[i-1][j+2] && board[i][j]==35)
  	 		 { 
  	 		      board[i][j]=51;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i-1;b>0;b--)
				  {
				  	board[b][j+1]=board[b-1][j+1];
				  	board[b][j+2]=board[b-1][j+2];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j+2]=rand()%4+33;
				  
				  
		     }
		     if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-1][j+1] && board[i][j]==board[i-1][j+2] && board[i][j]==36)
  	 		 { 
  	 		      board[i][j]=52;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i-1;b>0;b--)
				  {
				  	board[b][j+1]=board[b-1][j+1];
				  	board[b][j+2]=board[b-1][j+2];
				  }
				  board[0][j+1]=rand()%4+33;
				  board[0][j+2]=rand()%4+33;
				  
				  
		     }
		     //
		     if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-1][j-1] && board[i][j]==board[i-1][j-2] && board[i][j]==33)
  	 		 { 
  	 		      board[i][j]=49;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i-1;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j-2]=board[b-1][j-2];
				  }
				  board[0][j-1]=rand()%4+33;
				  board[0][j-2]=rand()%4+33;
				  
				  
		     }
		     if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-1][j-1] && board[i][j]==board[i-1][j-2] && board[i][j]==34)
  	 		 { 
  	 		      board[i][j]=50;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i-1;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j-2]=board[b-1][j-2];
				  }
				  board[0][j-1]=rand()%4+33;
				  board[0][j-2]=rand()%4+33;
				  
				  
		     }
		     if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-1][j-1] && board[i][j]==board[i-1][j-2] && board[i][j]==35)
  	 		 { 
  	 		      board[i][j]=51;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i-1;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j-2]=board[b-1][j-2];
				  }
				  board[0][j-1]=rand()%4+33;
				  board[0][j-2]=rand()%4+33;
				  
				  
		     }
		     if(board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-1][j-1] && board[i][j]==board[i-1][j-2] && board[i][j]==36)
  	 		 { 
  	 		      board[i][j]=52;
  	 		      for(int a=i-1;a>0;a--)
  	 		      {
  	 		      	board[a][j]=board[a-1][j];
  	 		    
				  }
				  board[0][j]=rand()%4+33;
				  
				  for(int b=i-1;b>0;b--)
				  {
				  	board[b][j-1]=board[b-1][j-1];
				  	board[b][j-2]=board[b-1][j-2];
				  }
				  board[0][j-1]=rand()%4+33;
				  board[0][j-2]=rand()%4+33;
				  
				  
		     }
		     
  	 		      
	}
		    
}
 } 
 void plainstrip(int board[][SIZE])
 {
 	for(int i=0;i<SIZE;i++)
  	 {
  	 	for(int j=0;j<SIZE;j++)
  	 	{
  	 		if(((board[i][j]==109 && board[i][j+1]==33 && board[i][j+2]==33) || (board[i][j]==33 && board[i][j+1]==33 && board[i][j+2]==109) || (board[i][j]==33 && board[i+1][j]==109 && board[i+2][j]==33)) ||((board[i][j]==109 && board[i+1][j]==33 && board[i+2][j]==33) || (board[i][j]==33 && board[i][j+1]==33 && board[i+2][j]==109) || (board[i][j]==33 && board[i+1][j]==109 && board[i+2][j]==33)))
 	
 	         {
 	         	for(int a=i;a>0;a--)
 	         	{
				  
 	         		for(int b=0;b<9;b++)
 	         		{
 	         			board[a][b]=board[a-1][b];
					  }
 	         		
 	         		
			   }
 	         	
 	         	
 	         	for(int c=0;c<9;c++)
 	         	{
 	         		board[0][c]=rand()%4+33;
				}
 	         	
 	         	
			  }
			  if(((board[i][j]==110 && board[i][j+1]==34 && board[i][j+2]==34) || (board[i][j]==34 && board[i][j+1]==34 && board[i][j+2]==110) || (board[i][j]==34 && board[i+1][j]==110 && board[i+2][j]==34)) ||((board[i][j]==110 && board[i+1][j]==34 && board[i+2][j]==34) || (board[i][j]==34 && board[i][j+1]==34 && board[i+2][j]==110) || (board[i][j]==34 && board[i+1][j]==110 && board[i+2][j]==34)))
 	
 	         {
 	         	for(int a=i;a>0;a--)
 	         	{
 	         		for(int b=0;b<9;b++)
 	         		{
 	         			board[a][b]=board[a-1][b];
					  }
 	         		
 	         		
			   }
 	         	
 	         	
 	         	for(int c=0;c<9;c++)
 	         	{
 	         		board[0][c]=rand()%4+33;
				  }
 	         	
 	         	
			  }
			  	if(((board[i][j]==111 && board[i][j+1]==35 && board[i][j+2]==35) || (board[i][j]==35 && board[i][j+1]==35 && board[i][j+2]==111) || (board[i][j]==35 && board[i+1][j]==111 && board[i+2][j]==35)) ||((board[i][j]==111 && board[i+1][j]==35 && board[i+2][j]==35) || (board[i][j]==35 && board[i][j+1]==35 && board[i+2][j]==111) || (board[i][j]==35 && board[i+1][j]==111 && board[i+2][j]==35)))
 	
 	         {
 	         	for(int a=i;a>0;a--)
 	         	{
 	         		for(int b=0;b<9;b++)
 	         		{
 	         			board[a][b]=board[a-1][b];
					  }
 	         		
 	         		
			   }
 	         	
 	         	
 	         	for(int c=0;c<9;c++)
 	         	{
 	         		board[0][c]=rand()%4+33;
				  }
 	         	
 	         	
			  }
			  if(((board[i][j]==112 && board[i][j+1]==36 && board[i][j+2]==36) || (board[i][j]==36 && board[i][j+1]==36 && board[i][j+2]==112) || (board[i][j]==36 && board[i+1][j]==112 && board[i+2][j]==36)) ||((board[i][j]==112 && board[i+1][j]==36 && board[i+2][j]==36) || (board[i][j]==36 && board[i][j+1]==36 && board[i+2][j]==112) || (board[i][j]==36 && board[i+1][j]==112 && board[i+2][j]==36)))
 	
 	         {
 	         	for(int a=i;a>0;a--)
 	         	{
 	         		for(int b=0;b<9;b++)
 	         		{
 	         			board[a][b]=board[a-1][b];
					  }
 	         		
 	         		
			   }
 	         	
 	         	
 	         	for(int c=0;c<9;c++)
 	         	{
 	         		board[0][c]=rand()%4+33;
				  }
 	         	
 	         	
			  }
 	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 	         if(((board[i][j]==37 && board[i][j+1]==33 && board[i][j+2]==33) || (board[i][j]==33 && board[i][j+1]==33 && board[i][j+2]==37) || (board[i][j]==33 && board[i+1][j]==37 && board[i+2][j]==33)) ||((board[i][j]==37 && board[i+1][j]==33 && board[i+2][j]==33) || (board[i][j]==33 && board[i][j+1]==33 && board[i+2][j]==37) || (board[i][j]==33 && board[i+1][j]==37 && board[i+2][j]==33)))
 	         {
 	         	
 	         	
 	         	
 	         	for(int c=0;c<9;c++)
 	         	{
 	         		board[i][c]=rand()%4+33;
				  }
 	         	
 	         	
			  }
			  
			 if(((board[i][j]==39 && board[i][j+1]==35 && board[i][j+2]==35) || (board[i][j]==35 && board[i][j+1]==35 && board[i][j+2]==39) || (board[i][j]==35 && board[i+1][j]==39 && board[i+2][j]==35)) ||((board[i][j]==39 && board[i+1][j]==35 && board[i+2][j]==35) || (board[i][j]==35 && board[i][j+1]==35 && board[i+2][j]==39) || (board[i][j]==35 && board[i+1][j]==39 && board[i+2][j]==35)))
 	
 	         {
 	         	
 	         	
 	         	
 	         	for(int c=0;c<9;c++)
 	         	{
 	         		board[i][c]=rand()%4+33;
				  }
 	         	
 	         	
			  }
			  if(((board[i][j]==38 && board[i][j+1]==34 && board[i][j+2]==34) || (board[i][j]==34 && board[i][j+1]==34 && board[i][j+2]==38) || (board[i][j]==34 && board[i+1][j]==38 && board[i+2][j]==34)) ||((board[i][j]==38 && board[i+1][j]==34 && board[i+2][j]==34) || (board[i][j]==34 && board[i][j+1]==34 && board[i+2][j]==38) || (board[i][j]==34 && board[i+1][j]==38 && board[i+2][j]==34)))
 	          {
 	          	for(int c=0;c<9;c++)
 	         	{
 	         		board[i][c]=rand()%4+33;
				  }
 	          	
			   }
			  
 	
 	        if(((board[i][j]==40 && board[i][j+1]==36 && board[i][j+2]==36) || (board[i][j]==36 && board[i][j+1]==36 && board[i][j+2]==40) || (board[i][j]==36 && board[i+1][j]==40 && board[i+2][j]==36)) ||((board[i][j]==40 && board[i+1][j]==36 && board[i+2][j]==36) || (board[i][j]==36 && board[i][j+1]==36 && board[i+2][j]==40) || (board[i][j]==36 && board[i+1][j]==40 && board[i+2][j]==36)))
 	
 	         
			  
 	         {
 	         	
 	         	
 	         	
 	         	for(int c=0;c<9;c++)
 	         	{
 	         		board[i][c]=rand()%4+33;
				  }
 	         	
 	         	
			  }
 	
 	
 	
        }
    }
 }
 void plainwrapcandy(int board[][SIZE])
 {
 	for(int i=0;i<SIZE;i++)
 	{
 		for(int j=0;j<SIZE;j++)
 		{
 			if((board[i][j]==49 && board[i][j+1]==33 && board[i][j+2]==33) || (board[i][j]==33 && board[i][j+1]==33 && board[i][j+2]==49) || (board[i][j]==33 && board[i][j+1]==49 && board[i][j+2]==33)) 
 			{
 				
 				for(int a=i;a>0;a--)
 				{
 					board[a+2][j]=board[a-1][j];
 					board[a+2][j+1]=board[a-1][j+1];
 					board[a+2][j-1]=board[a-1][j-1];
 					
				 }
				   for(int b=0;b<3;b++)
				   {
				   	   board[b][j]=rand()%4+33;
				   	   board[b][j+1]=rand()%4+33;
				   	   board[b][j-1]=rand()%4+33;
				   	  
				   	
				   	
				   	
				   } 
				 
 				
			}
				if((board[i][j]==50 && board[i][j+1]==34 && board[i][j+2]==34) || (board[i][j]==34 && board[i][j+1]==34 && board[i][j+2]==50) || (board[i][j]==34 && board[i][j+1]==50 && board[i][j+2]==34)) 
 			{
 				
 				for(int a=i;a>0;a--)
 				{
 					board[a+2][j]=board[a-1][j];
 					board[a+2][j+1]=board[a-1][j+1];
 					board[a+2][j-1]=board[a-1][j-1];
 					
				 }
				   for(int b=0;b<3;b++)
				   {
				   	   board[b][j]=rand()%4+33;
				   	   board[b][j+1]=rand()%4+33;
				   	   board[b][j-1]=rand()%4+33;
				   	  
				   	
				   	
				   	
				   } 
				 
 				
			}
				if((board[i][j]==51 && board[i][j+1]==35 && board[i][j+2]==35) || (board[i][j]==35 && board[i][j+1]==35 && board[i][j+2]==51) || (board[i][j]==35 && board[i][j+1]==51 && board[i][j+2]==35)) 
 			{
 				for(int a=i;a>0;a--)
 				{
 					board[a+2][j]=board[a-1][j];
 					board[a+2][j+1]=board[a-1][j+1];
 					board[a+2][j-1]=board[a-1][j-1];
 					
				 }
				   for(int b=0;b<3;b++)
				   {
				   	   board[b][j]=rand()%4+33;
				   	   board[b][j+1]=rand()%4+33;
				   	   board[b][j-1]=rand()%4+33;
				   	  
				   	
				   	
				   	
				   } 
 				
				 
 				
			}
				if((board[i][j]==52 && board[i][j+1]==36 && board[i][j+2]==36) || (board[i][j]==36 && board[i][j+1]==36 && board[i][j+2]==52) || (board[i][j]==36 && board[i][j+1]==52 && board[i][j+2]==36)) 
 		{
 				
 				for(int a=i;a>0;a--)
 				{
 					board[a+2][j]=board[a-1][j];
 					board[a+2][j+1]=board[a-1][j+1];
 					board[a+2][j-1]=board[a-1][j-1];
 					
				 }
				   for(int b=0;b<3;b++)
				   {
				   	   board[b][j]=rand()%4+33;
				   	   board[b][j+1]=rand()%4+33;
				   	   board[b][j-1]=rand()%4+33;
				   	  
				   	
				   	
				   	
				   } 
				   
				 
 				
			}
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if((board[i][j]==49 && board[i+1][j]==33 && board[i+2][j]==33) || (board[i][j]==33 && board[i+1][j]==33 && board[i+2][j]==49) || (board[i][j]==33 && board[i+1][j]==49 && board[i+2][j]==33))
	        {
	        	
	        	for(int a=i;a>0;a--)
 				{
 					board[a+2][j]=board[a-1][j];
 					board[a+2][j+1]=board[a-1][j+1];
 					board[a+2][j-1]=board[a-1][j-1];
 					
				 }
				   for(int b=0;b<3;b++)
				   {
				   	   board[b][j]=rand()%4+33;
				   	   board[b][j+1]=rand()%4+33;
				   	   board[b][j-1]=rand()%4+33;
				   	  
				   	
				   	
				   	
				   } 
				 
 				
			}
			if((board[i][j]==50 && board[i+1][j]==34 && board[i+2][j]==34) || (board[i][j]==34 && board[i+1][j]==34 && board[i+2][j]==50) || (board[i][j]==34 && board[i+1][j]==50 && board[i+2][j]==34))
	        {
	        	
	        	for(int a=i;a>0;a--)
 				{
 					board[a+2][j]=board[a-1][j];
 					board[a+2][j+1]=board[a-1][j+1];
 					board[a+2][j-1]=board[a-1][j-1];
 					
				 }
				   for(int b=0;b<3;b++)
				   {
				   	   board[b][j]=rand()%4+33;
				   	   board[b][j+1]=rand()%4+33;
				   	   board[b][j-1]=rand()%4+33;
				   	  
				   	
				   	
				   	
				   } 
				 
 				
			}
			if((board[i][j]==51 && board[i+1][j]==35 && board[i+2][j]==35) || (board[i][j]==35 && board[i+1][j]==35 && board[i+2][j]==51) || (board[i][j]==35 && board[i+1][j]==51 && board[i+2][j]==35))
	        {
	        	
	        	for(int a=i;a>0;a--)
 				{
 					board[a+2][j]=board[a-1][j];
 					board[a+2][j+1]=board[a-1][j+1];
 					board[a+2][j-1]=board[a-1][j-1];
 					
				 }
				   for(int b=0;b<3;b++)
				   {
				   	   board[b][j]=rand()%4+33;
				   	   board[b][j+1]=rand()%4+33;
				   	   board[b][j-1]=rand()%4+33;
				   	  
				   	
				   	
				   	
				   } 
				 
 				
			}
			if((board[i][j]==52 && board[i+1][j]==36 && board[i+2][j]==36) || (board[i][j]==36 && board[i+1][j]==36 && board[i+2][j]==52) || (board[i][j]==36 && board[i+1][j]==52 && board[i+2][j]==36))
	        {
	        	
	        	for(int a=i;a>0;a--)
 				{
 					board[a+2][j]=board[a-1][j];
 					board[a+2][j+1]=board[a-1][j+1];
 					board[a+2][j-1]=board[a-1][j-1];
 					
				 }
				   for(int b=0;b<3;b++)
				   {
				   	   board[b][j]=rand()%4+33;
				   	   board[b][j+1]=rand()%4+33;
				   	   board[b][j-1]=rand()%4+33;
				   	  
				   	
				   	
				   	
				   } 
				 
 				
			}
			
		}
	}
 	 
 	 
 }
 
 void saveboard(int board[][SIZE])
 {
 	ofstream fout("candy.txt");
 	ofstream fout2("candy2.txt");
 	fout2<<moves;
 	fout2<<endl;
 	fout2<<score;
 	

 	for(int i=0;i<SIZE;i++)
 	{
 			for(int j=0;j<SIZE;j++)
 		{
 			fout<<board[i][j];
 			fout<<endl;
 		}
		 
	}
	fout.close();
 }
 
void  loadboard(int board[][SIZE])
 {
 	
 	int v=0;
    ifstream fin("candy.txt");
    ifstream fin2("candy2.txt");
    
	fin2>>moves;
    fin2>>score;
    
 	for(int i=0;i<SIZE;i++)
 	{
 	
 		for(int j=0;j<SIZE;j++)
 		{
 			fin>>v;
 			board[i][j]=v;
	    }
	    
	}
	fin.close();
	fin2.close();
 }
 

int main(){
	system("COLOR 09");
	srand(time(NULL));
	int board[SIZE][SIZE];
	int a=0;
	cout<<"ENTER THE OPTION"<<endl;
	cout<<"1.Load New Game"<<endl;
	cout<<"2.Load previous Game"<<endl;
	cin>>a;
		
	gameheader();

	if(a==1)
	{
	createBoard(board);
	saveboard(board);
	}
	else
	
{
		loadboard(board);
		
}
	
	displayboard(board);
	
	
	for(int i=moves;i>0;i--)
	{
    
		moves--;
	swapboard(board);
    system("cls");
	bomb(board);
	wrappedcandy(board);
	stripcandy(board);
	newboard(board);
	
	plainstrip(board);
	plainwrapcandy(board);
	displayboard(board);
	saveboard(board);
	
   }
   if(score>200)
   {
   	 cout<<"YOU WIN CONGRATULATIONS"<<endl;
   	 
   }
   else 
      cout<<"YOU LOOSE OOOPS TRY AGAIN"<<endl;
      
   cout << "\t\t\t\t\t  ______      _ _   " << endl;
            cout << "\t\t\t\t\t |  ____|    (_) |  " << endl;
            cout << "\t\t\t\t\t | |__  __  ___| |_ " << endl;
            cout << "\t\t\t\t\t |  __| \\ \\/ / | __|" << endl;
            cout << "\t\t\t\t\t | |____ >  <| | |_ " << endl;
            cout << "\t\t\t\t\t |______/_/\\_\\_|\\__|" << endl;
}
