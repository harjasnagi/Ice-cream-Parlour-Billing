#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
using namespace std;
class icecream
{
	public:
		char name[20];
		long code;
		int price;
		void input()
		{
			cout<<"\t\t\t\tEnter item code: ";
			cin>>code;
		}
		void input1()
		{
			cout<<"\t\t\t\tEnter item name: ";
			cin>>name;
			cout<<"\t\t\t\tEnter item price: ";
			cin>>price;
		}
		void output()
		{
			cout<<endl<<"\t\t\t\tItem Name: "<<name<<endl;
			cout<<"\t\t\t\tItem Code: "<<code<<endl;
			cout<<"\t\t\t\tItem price: "<<price<<endl;
		}
};

int main()
{
	icecream obj;
	
	int co_de,code1,i,j=0,flag,item1,id,pass,price1,k=0,q=0,l=0,m=0;
	char rname[20],radd[20],a[20],yesno,g;
	int z,b,c,h=0;
	char ch;
	while(1)
	{
		//system("cls");
		Home:
			
		cout<<endl<<"\t\t**************************************************"<<endl;
		cout<<"\t\t\t\tLOWELY ICE CREAM"<<endl<<"\t\t\t\t"<<"  "<<"Shop No. 999"<<endl<<"\t\t\t"<<"     "<<"(designed by 11801373)"<<endl<<endl;
		cout<<"\t\t\t\t1.Administration"<<endl<<"\t\t\t\t2.Billing"<<endl<<"\t\t\t\t3.Last order"<<endl<<"\t\t\t\t4.Exit";
		cout<<endl<<"\t\t\t\tChoose:";
		cin>>z;
		cout<<endl;
		if(z<5)  
		{
			switch(z)
			{
				case 1:																								////////  ADMINISTRTION
				{
					cout<<endl<<"\t\t\t\tAuthorized access for staff only"<<endl;
					cout<<endl<<"\t\t\t\tUser id: ";
					cin>>id;
					if(id!=123)
					{
						cout<<"\t\t\t\tWrong id";
						cout<<endl<<"\t\t\t\tPress to continue";
						getch();
					}
						
					if(id==123)
					{
						cout<<"\t\t\t\tPasscode: ";
						cin>>pass;
					}
					if(id==123 && pass==123)		
					{
						cout<<endl;	
						Admin:
						system("cls");
						cout<<endl<<"\t\t**************************************************"<<endl;
						cout<<"\t\t\t\tLOWELY ICE CREAM"<<endl<<"\t\t\t\t"<<"  "<<"Shop No. 999"<<endl<<"\t\t\t"<<"     "<<"(designed by 11801373)"<<endl<<endl;
						
						cout<<"\t\t\t"<<"    "<<" => Administration:"<<endl;
						cout<<"\t\t\t\t1.Show all items"<<endl<<"\t\t\t\t2.Search item by code"<<endl<<"\t\t\t\t3.Search item by price"<<endl<<"\t\t\t\t4.Add item"<<endl<<"\t\t\t\t5.Delete item"<<endl<<"\t\t\t\t6.Go Back HOME"<<endl;
						cout<<"\t\t\t\tChoose: ";
						cin>>z;
						if(z<7) 
						{
							cout<<endl;
							switch(z)
							{
								case 1:
								{
									system("cls");
									cout<<endl<<"\t\t**************************************************"<<endl;
									cout<<"\t\t\t\tLOWELY ICE CREAM"<<endl<<"\t\t\t\t"<<"  "<<"Shop No. 999"<<endl<<"\t\t\t"<<"     "<<"(designed by 11801373)"<<endl<<endl;
									fstream fin;
									fin.open("all.txt",ios::in | ios::binary);
									while( fin.read((char*)&obj,sizeof(obj)) )
									{
										obj.output();
									}
									fin.close();
								}
								cout<<endl<<"\t\t\t\tPress to continue";
								getch();
								system("cls");
								goto Admin;
								
								case 2:
								{
									cout<<"\t\t\t\tEnter Code: ";
									cin>>co_de;
									fstream fin;
									fin.open("all.txt",ios::in);
									while(( fin.read((char*)&obj,sizeof(obj) )))
									{	
										if(obj.code==co_de)
										{
											obj.output();
											l=1;
										}
									}
									if(l!=1)
									{
										cout<<"\t\t\t\tNot found"<<endl;
									}	
									fin.close();
								}
								cout<<endl<<"\t\t\t\tPress to continue";
								getch();
								system("cls");
								goto Admin;
								
								case 3:
								{
									cout<<"\t\t\t\tEnter price: ";
									cin>>price1;
									fstream fin;
									fin.open("all.txt",ios::in);
									while(( fin.read((char*)&obj,sizeof(obj) )))
									{	
										if(obj.price==price1)
										{
											obj.output();
											m=1;
										}
									}
									if(m!=1)
									{
										cout<<"\t\t\t\tNot found"<<endl;
									}	
									fin.close();
								}
								cout<<endl<<"\t\t\t\tPress to continue";
								getch();
								system("cls");
								goto Admin;
								
								case 4:
								{
									fstream fout;
									i=0;
									fout.open("all.txt",ios::in | ios::binary);
									while( fout.read((char*)&obj,sizeof(obj)) )
									{	
										a[i]=obj.code;
										i++;
									}
									fout.close();
									fout.open("all.txt",ios::app | ios::binary | ios::in);
									obj.input();
									j=0,flag=0;
							
									while(j<i)
									{
										if(obj.code==a[j])
										{
											flag++;
										}
										j++;
									}
									if(flag>0)
									{
										cout<<"\t\t\t\tSorry, details already exist"<<endl;
									}
									if(flag==0)
									{
										obj.input1();
										fout.write( (char*)&obj,sizeof(obj) );
									}
								}
								cout<<endl<<"\t\t\t\tPress to continue";
								getch();
								system("cls");
								goto Admin;
								
								case 5:
								{
									fstream oopen;
									oopen.open("all.txt",ios::in | ios::binary);
									while( oopen.read((char*)&obj,sizeof(obj)) )
									{
										obj.output();
									}
									oopen.close();
									
									fstream fin;
									fin.open("all.txt",ios::in | ios::binary);
									fstream temp2("bye.txt",ios::out | ios::binary);
									cout<<endl<<"\t\t\t\tEnter code u wanna delete=";
									cin>>code1;
									while( fin.read((char*)&obj,sizeof(obj)) )
									{
										if(obj.code!=code1)
											temp2.write((char*)&obj,sizeof(obj));
									}
									fin.close();
									temp2.close();
									remove("all.txt");
									rename("bye.txt","all.txt");
								}
								cout<<endl<<"\t\t\t\tPress to continue";
								getch();
								system("cls");
								goto Admin;
								
								
								case 6:
								{
									break;
								}
							}
						}
						else if(z>6)
						{
							cout<<"\t\t\t\tIncorrect Input"; 
							cout<<endl<<"\t\t\t\tPress to continue";
							getch();
							//system("cls");
							cout<<endl<<endl;
							goto Admin;
						}
					}
					if(id==123 && pass!=123)
					{
						cout<<endl<<"\t\t\t\tWrong passcode";
						cout<<endl<<"\t\t\t\tPress to continue";
						getch();
					}
				}
				//getch();o
				system("cls");
				goto Home;
				case 2:																												///////// BILLING STARTS
				{
					system("cls");
					cout<<endl<<"\t\t**************************************************"<<endl;
					cout<<"\t\t\t\tLOWELY ICE CREAM"<<endl<<"\t\t\t\t"<<"  "<<"Shop No. 999"<<endl<<"\t\t\t"<<"     "<<"(designed by 11801373)"<<endl<<endl;
					Bill:
					cout<<"\t\t\t"<<"    "<<" => Billing:"<<endl<<endl;
					cout<<"\t\t\t\tMenu:";
					fstream fin;
					fin.open("all.txt",ios::in | ios::binary);
					while( fin.read((char*)&obj,sizeof(obj)) )
					{
						obj.output();
					}
					fin.close();
				
					Buy:
					fstream b;
					b.open("all.txt",ios::in | ios::binary);
					fstream b2("buy.txt",ios::out | ios::binary);
					
					cout<<endl<<"\t\t\t\tEnter code of item u want=";
					cin>>item1;
					while( b.read((char*)&obj,sizeof(obj)) )
					{
						if(obj.code==item1)
						b2.write((char*)&obj,sizeof(obj));
					}
					b.close();
					b2.close();	
					
					cout<<"\t\t\t\tAnyting else? (y/n): ";
					cin>>yesno;
					if(yesno=='y'||yesno=='Y')
					{
						goto Buy;
						item1=0;
					}
					
					
					cout<<endl<<"\t\t\t"<<"    "<<" => RECIEPT:"<<endl;
					fstream bc;
					bc.open("buy.txt",ios::in | ios::binary);
					while( bc.read((char*)&obj,sizeof(obj)) )
					{
						obj.output();
						k+=obj.price;
					}
					cout<<endl<<"\t\t\t\tSubtotal: Rs. "<<k;
					bc.close();
					getch();
				}
				//getch();
				system("cls");
				goto Home;
				case 3:
				{
					cout<<"\t\t\t"<<"    "<<" => RECIEPT:"<<endl;
					fstream bc;
					bc.open("buy.txt",ios::in | ios::binary);
					while( bc.read((char*)&obj,sizeof(obj)) )
					{
						obj.output();
						q+=obj.price;
					}
					cout<<endl<<"\t\t\t\tSubtotal: Rs. "<<q;
					bc.close();
					cout<<endl<<"\t\t\t\tPress to continue";
					getch();
				}
				system("cls");
				goto Home;
				case 4:
				{
					system("cls");
					cout<<endl<<"\t\t**************************************************"<<endl;
					cout<<"\t\t\t\tLOWELY ICE CREAM"<<endl<<"\t\t\t\t"<<"  "<<"Shop No. 999"<<endl<<"\t\t\t"<<"     "<<"(designed by 11801373)"<<endl<<endl;
					cout<<endl<<endl<<"\t\t\t\tLogging Out..."<<endl<<"\t\t\t\tHave a good day"<<endl<<endl<<endl;
					exit(1);
				}
			} 
		} 
		else if(z>4)
		{
			cout<<"\t\t\t\tIncorrect Input"; 
			cout<<endl<<"\t\t\t\tPress to continue";
			getch();
			system("cls");
		}
			
	}
	
	return 0;
}


