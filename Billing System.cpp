#include<bits/stdc++.h>
using namespace std;

class shopping
{
	private:
		int pcode;
		float price;
		float discount;
		string pname;
		
		public:
			void menu();
			void Admin();
			void buyer();
			void add();
			void edit();
			void rem();
			void list();
			void receipt();
			
};

void shopping :: menu()
{
	m:
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t#########################################################\n";
	cout<<"\t\t\t#                                                       #\n";
	cout<<"\t\t\t#                      HOME PAGE                        #\n";
	cout<<"\t\t\t#                                                       #\n";
	cout<<"\t\t\t#########################################################\n";
	cout<<"\t\t\t\t                                      \n";
	cout<<"\t\t\t\t|  1. Press 1 to access Admin site      |\n";
	cout<<"\t\t\t\t|                                       |\n";
	cout<<"\t\t\t\t|  2. Press 2 to access Customer site   |\n";
	cout<<"\t\t\t\t|                                       |\n";
	cout<<"\t\t\t\t|  3. Press 3 for Exit                  |\n";
	cout<<"\t\t\t\t|                                       |\n";
	cout<<"\n\t\t\t Please enter your choice accordingly: ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"\t\t\t Please Login to access your dashboard \n";
			cout<<"\n\t\t\t Enter Yout registered Email-id: ";
			cin>>email;
			cout<<"\n\t\t\t Enter your Password: ";
			cin>>password;
			
			if(email=="shantanu@gmail.com" && password=="Shantanu_001")
			{
				cout<<"\n\n\t\t\tLogin Successful...\n\n";
				Admin();
			}
			else
			{
				cout<<"\n\n\t\t\tInvalid Email/Password\n\n";
			}
			break;
	
	
	case 2:
		{
			buyer();
			
		}
	
	case 3:
		{
			exit(0);
		}
		
		default :
			{
				cout<< "Please select from the given options";
				
			}
			
	
}
goto m;
}

void shopping:: Admin()
{
	m:
	int choice;
	cout<<"\n\n\n\t\t\t|              Admin Dashboard                |";
	cout<<"\n\t\t\t|---------------------------------------------|";
	cout<<"\n\t\t\t|     1. Press 1 to Add the product           |";
	cout<<"\n\t\t\t|                                             |";
	cout<<"\n\t\t\t|     2. Press 2 to edit the product details  |";
	cout<<"\n\t\t\t|                                             |";
	cout<<"\n\t\t\t|     3. Press 3 to Delete the product        |";
    cout<<"\n\t\t\t|                                             |";
    cout<<"\n\t\t\t|     4. Press 4 to go back to home page      |";
    
    cout<<"\n\n\t\t\t Please enter your choice from above list: ";
    cin>>choice;
    
    switch(choice)
    {
    	case 1:
    		add();
    		break;
    		
    	case 2:
    		edit();
    		break;
    		
    	case 3:
    		rem();
    		break;
    		
    	case 4:
    		menu();
    		break;
    		
    	default :
    		cout<<"Invalid choice!\nTry again";
    		
	}
	goto m;
}

void shopping:: buyer()
{
	m:
	int choice;
	cout<<"\n\n\n\t\t\t|           Customer Dashboard            |\n\n";
	cout<<"\t\t\t##########################################\n";
	cout<<"\t\t\t#                                        #\n";
	cout<<"\t\t\t#    1. Press 1 to Buy product           #\n";
	cout<<"\t\t\t#                                        #\n";
	cout<<"\t\t\t#    2. Press 2 to Go back to home page  #\n";
	cout<<"\t\t\t#                                        #\n";
	cout<<"\t\t\t##########################################\n";
	cout<<"\n\t\t\t Please Enter your choice from above List : ";
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
			
		case 2:
			menu();
			
		default :
			
			cout<<"invalid choice!\n Try Again";
			
	}
	
	goto m;
	
	
}

void shopping ::add()
{
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\n\t\t\t|              Add new product                |\n\n";
	cout<<"\n\t\t\t Enter Product ID: ";
	cin>>pcode;
	cout<<"\n\t\t\t Enter Product Name: ";
	cin>>pname;
	cout<<"\n\t\t\t Enter Product Price: ";
	cin>>price;
	cout<<"\n\t\t\t Enter Discount percentage on this product (Type only Numerical digit): ";
	cin>>discount;
	
	data.open("database.txt",ios::in);
	
	if(!data)
	{
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
		data.close();
	}
	else
	{
		data>>c>>n>>p>>d;
		
		while(!data.eof())
		{
			if(c ==pcode)
			{
				token++;
				
			}
			data>>c>>n>>p>>d;
		}
		data.close();
		
		
	
	
	if(token==1)
	 goto m;
	else{
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
		data.close();
		
	}
}
	cout<<"\n\n\t\t Product Added Successfully !";
}

void shopping ::edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\n\t\t\t|              Edit the Product Details              |\n\n";
	cout<<"\n\t\t\t Product ID :\t";
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\nFile doesn't exist! ";
	}
	else{
		
		data1.open("database1.txt", ios::app|ios::out);
		
		data>>pcode>>pname>>price>>discount;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\t\t\t Enter Product new ID :";
				cin>>c;
				cout<<"\n\t\t\t Enter Product Name :";
				cin>>n;
				cout<<"\n\t\t\t Enter Product Price :";
				cin>>p;
				cout<<"\n\t\t\t Enter Discount percentage on this product (Type only Numerical digit) :";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t\t Product Details Updated Successfully ";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
				
			}
			data>>pcode>>pname>>price>>discount;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Error! Record not found!";
		}
	}
	
	
	
}
void shopping::rem()
{
	
	fstream data,data1;
	int pkey;
	int token=0;

	cout<<"\n\n\n\t\t\t|              Delete product            |\n\n";
	cout<<"\n\n\t\t\t Product Id :";
	cin>>pkey;
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"Product doesn't exist";
		
	}
	
	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>discount;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t\t\t Product removed succesfully";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
				
			}
			data>>pcode>>pname>>price>>discount;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Product not found";
		}
	}
}

void shopping:: list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n\t\t\t|                       Available Products                   |\n";
	cout<<"\n\n\t\t\t--------------------------------------------------------------\n";
	cout<<"\t\t\tProduct ID\tProduct Name\tProduct Price\n";
	cout<<"\n\t\t\t----------------------------------------------------------------\n";
	data>>pcode>>pname>>price>>discount;
	while(!data.eof())
	{
		cout<<"\t\t\t"<<pcode<<"\t\t"<<pname<<"\t\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>discount;
		
	}
	data.close();
}

void shopping::receipt() 
	{
		system("cls");
		fstream data;
		
		int arrc[100],arrq[100];
		char choice;
		int c=0;
		float amount=0;
		float discount=0;
		float total=0;
		cout<<"\n\n\t\t\t Receipt ";
		data.open("database.txt",ios::in);
		if(!data)
		{
			cout<<"\n\n\t\t\t No product Found! Come back later";
		}
		else
		{
			data.close();                                   
			list();
			cout<<"\n\t\t\t----------------------------\n";
			cout<<"\t\t\t                                ";
			cout<<"\n\t\t\t    Please place the order  ";
			cout<<"\n\t\t\t                            ";
			cout<<"\n\t\t\t----------------------------\n";
			do
			{
				m:
				cout<<"\n\n\t\t\t Product ID : ";
				cin>>arrc[c];
				cout<<"\n\t\t\t Product Quantity : ";
				cin>>arrq[c];
				for(int i=0;i<c;i++)
				{
					if(arrc[c] == arrc[i])
					{
						cout<<"\n\n\t\t\t Duplicate Product ID. Please try again!";
						goto m;
					}
				}
				c++;             
				cout<<"\n\n\t\t\t Want to buy another product? Press y for yes and n for no : ";
				cin>>choice;	
			}
			
			while(choice == 'y');
			system("cls");
			
			cout<<"\n\n\t\t\t__________RECEIPT______________\n";
			cout<<"\t\t\t"<<"\nProduct ID\tProduct Name\tQuantity \tPrice \tTotal Amount \tFinall Amount with Discount\n";
			
			
			for(int i=0;i<c;i++) 
			{
				data.open("database.txt",ios::in);
				data>>pcode>>pname>>price>>discount;
				while(!data.eof())
				{
					if(pcode == arrc[i])   
					{
						amount = price*arrq[i];
						discount = amount - (amount*discount/100);
						total =total+ discount;
						cout<<"\t\t\t"<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<discount;	
					}
					   data>>pcode>>pname>>price>>discount;  
				}
				data.close();
			}
			cout<<"\n\n\t\t\t*****************************************";
			cout<<"\n\t\t\t Total Amount : "<<total;
		}
	}
int main()
{
	shopping s;
	s.menu();
	return 0;
}

