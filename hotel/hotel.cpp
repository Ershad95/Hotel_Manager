#include "hotel.h"
fstream f("hotel.txt", ios::in | ios::out | ios::app);

int room[31] = { 0 };
int times[31] = { 0};
hotel::hotel()
{
	
	name[50] = { 0 };
	family[50] = { 0 };
	phone[12] = { 0 };
	ID[20] = { 0 };
	nationality[50] = { 0 };
	user[20] = { 0 };
	pass[20] = { 0 };
	room_no=0;
	full = 0;
	empty = 0;
	room_number = 0;
	persons = 0;
}


void hotel::cheack_menu(int x)
{
	switch (x){
	case 1:
		cout << "\n";
		cheackroom();
		room_number=setroom();
		setfile(name, family, phone, nationality, ID,time,data);
		cout << "your room number is     :  " << room_number;
		break;
	case 2:
		admin();
		break;
	case 3:
		cout << "\n";
		cheack_out();
		break;
	}

}

int hotel::id()
{
	char id[20]; int p=1, control=0,sum=0;
	cout << "please enter your ID (national code) : ";
	for (int i = 10; i >= 1; i--)
	{

		id[i] = _getche();
		id[i] -= 48;
		cout << "\b" << "*";

	}

	control = id[1];
	cout << "\n";
	for (int i = 10; i >= 2; i--){
		p = id[i] * i;
		sum = sum + p;
	}
	sum = sum % 11;
	sum = 11 - sum;
	if (sum == control)
	{
		return 1;
}
	return 0;

}


bool hotel::setfile(char name[50], char family[50], char phone[12], char nationality[50],char ID[10],char time[9],char data[9])
{
	fstream f2("hotel.txt", ios::in | ios::out);
	f2<<setw(2)<< "name" << setw(20) << "family" << setw(20) << "phone number"
		<<setw(20) << "nationality" << setw(20) <<"ID"<<setw(20)<<"time"<<setw(20)<<"data"<<"\n";
	
	f2 << "\n\n";

	f2.close();

	cout << "Number of persons : ";
	cin >> persons;

	for (int i = 1; i <= persons; i++)
	{
		//------------
		int x=id();
		if (x == 0)
		{
			system("color c");
			cout << "\n\nyour ID is incorrect...\n";
			system("pause");
		exit(0);
		}
		system("color a");
		cout << "\nyour ID is true...\n";
		cout << " " << i << ".\n";
		cout << "name :";
		cin >> name;
		cout << "family :";
		cin >> family;
		cout << "phone :";
		cin >> phone;
		cout << "nationality :";
		cin >> nationality;
		cout << "ID : ";
		cin >> ID;
		cout << "how many time stay in hotel ?";
		cin >> time_p;
		
		

		gettime();

		f <<setw(2)<< name << setw(20) << family << setw(20) <<
		phone << setw(20) << nationality << setw(26) <<ID <<setw(20)<<time<<setw(20)<<data<<"\n";

		f.close();
	}
	return true;
}


 int  hotel::menu()
 {
	 char ch;
	cout << "\n\n=>menu\n\n";
	cout << "1-Set Room...\n\n";
	cout << "2-Information Rooms(admin)...\n\n";
	cout << "3-Delivery Room...\n\n";
	//cout << "Exit > e" << "\n\n";
	cout << "your choise : ";
	ch=_getche();
	switch (ch)
	{
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case 'e':
	case 'E':
		return 0;
		break;
	}
	return 0;
}


 bool hotel::gettime()
 {
	 _tzset();
	 _strtime_s(time, 128);
	 _strdate_s(data, 128);
	 _tzset();
	 return true;
 }


int hotel::cheackroom()
 {

		for (int i = 1; i <= 30; i++)
		{
			if (room[i] == 0)
			{
				++empty;
			}
			if (room[i] == 1)
			{

				++full;
			}
		}
		
		if (full == 30)
			return 0;
		if (empty > 0)
		return 1;

	}
int hotel::setroom()
{
	
	if (cheackroom())
		for (int i = 1; i <= 30; i++)
		{
			if (room[i] == 0){
				room[i] = 1;
				times[i] = time_p;
				return i;
				
			}
			
			
	}
	if (!cheackroom()){
		cout << "we don't have empty room...";
	system("pause");
	return 0;
}


}
bool hotel::cheack_out()
{
	cout << "please enter your room number : ";
	cin >> room_number;
	int t=times[room_number];
	if (room_number >= 1 && room_number <= 30 && room[room_number] == 1 && times[room_number]!=0)
	{
		room[room_number] = 0;
		times[room_number] = 0;
		cout << " room number : "<<room_number<< "\n"<<setw(20)<<"room cheack out \n...we hope see you later...\n";
		
		return true;
}
	 else
		 cout << "enter correct room number....\n\n";
		
		 cheack_out();
		 return false;
	 }
 
hotel::~hotel()
{

}

bool hotel::admin()
{
	
	cout << "\nenter username : ";
	cin >> user;
	cout << "\nenter password : ";
	cin >> pass;

	int u = strcmp("ershad", user);
	int p = strcmp("raoufi", pass);
	if (u == 0 && p == 0){
		cout << "\nok\n";
		string f;
		fstream file("hotel.txt", ios::in);
		if (file.is_open()){
			while (file.good())
			{	
				getline(file,f);
				cout << f << endl;
			}
			file.close();
		}
		
		
		return true;
	}
	else
	{
		cout << "paas or user invliad...\n";
		admin();
		return false;
	}

}
