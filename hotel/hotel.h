#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <sys/types.h>
#include <sys/timeb.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define max 30

class hotel
{
private:
	
	int persons;
	int time_p;
	char user[20], pass[20];
    int full;
    int empty;
	int room_number;
	char name[50];
	char family[50];
	char phone[12];
	char nationality[50];
	char ID[20];
	bool admin();
	int id();
	int cheackroom();
	int setroom();
	bool cheack_out();
	bool gettime();
	bool setfile(char name[50], char family[50], char phone[12], char nationality[50], char ID[20], char time[128], char data[128]);
	char time[9];
	char data[9];
	int room_no;

	
public:
    int menu();
    void cheack_menu(int x);
	hotel();
	~hotel();
};

