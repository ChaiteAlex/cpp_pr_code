// Structures.cpp : Этот файл содержит тему структур

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int SIZE = 25;

enum fl_type : char { e, c, t, d };
char types[4][8]{"Default", "Charter", "Transit", "Docking"};

struct fltime { // Описываем отдельную структуру для времени(отправления/прибытия и полета)
	int day, month, year, hours, minutes;
};

struct flight {

	string flight_message;	// путь сообщения полета
	fltime t_departure;
	fltime t_arrival;			// Время
	fltime t_duration;
	double price;				// Стоимость
	fl_type flight_type;		// Тип рейса

};

void display_list(flight flight_list[], int start, int end)
{
	if (start >= 0 && start < SIZE && end >= start && end <= SIZE)
		for (int i = start; i < end; i++) {
			if (!(flight_list[i].flight_message.empty())) {
				cout << i + 1 << ":\tПуть сообщения:\t" << flight_list[i].flight_message << endl;
				printf("\t\tВремя Отправления:\t%02i.%02i.%i %02i:%02i\n", flight_list[i].t_departure.day, flight_list[i].t_departure.month, flight_list[i].t_departure.year, flight_list[i].t_departure.hours, flight_list[i].t_departure.minutes);
				printf("\t\tВремя Прибытия:\t%02i.%02i.%i %02i:%02i\n", flight_list[i].t_arrival.day, flight_list[i].t_arrival.month, flight_list[i].t_arrival.year, flight_list[i].t_arrival.hours, flight_list[i].t_arrival.minutes);
				printf("\t\tВремя полета:\t%i часов %i минут\n", flight_list[i].t_duration.hours, flight_list[i].t_duration.minutes);
				printf("\t\tСтоимость билета:\t%.2f Рублей\n", flight_list[i].price);
				if (flight_list[i].flight_type != 0) cout << "\t\tТип рейса:\t" << types[flight_list[i].flight_type] << "\n";
				cout << "\n\n";
			}
		}
	else {
		cout << "\t\t\tError! Out of range - ";
		if (start < 0 || start >= SIZE)
			cout << "Start index is out of range! (must be between 1 and " << SIZE << ")";
		else if (end < start || end > SIZE)
			cout << "End index is out of range! (must be between start range and " << SIZE << ")";
		cout << "\n\n";
	}
}

void disp_init(flight lis[]) {
	
	char ques;
	int buf,start_in = 1, end_in = SIZE;

	cout << "\tDo you want show the list from your start and end?(y/n): ";
	cin >> ques;

	if (ques == 'y')
	{
		cout << "\t\tStart index(numeration start from 1): ";
		cin >> start_in;
		cout << "\t\tEnd index(you can enter 0 to skip end index): ";
		cin >> buf;
		cout << endl;

		if (buf != 0) end_in = buf;
	}
	else cout << "Default mode!";
		
	display_list(lis, start_in - 1, end_in);
}

void edit_data(flight lis[], char arg) {

	int id_ed;
	
	cout << "\nEnter a num of flight(listing start from 1): ";
		cin >> id_ed;
		if (id_ed < 1 || id_ed > SIZE) {

			cout << "Error! Index out of range: " << id_ed << " must be in range 1 to 25";
			return;
		}
		
		id_ed -= 1;
	
	cout << endl;
	display_list(lis, id_ed, id_ed + 1);

	switch (arg)
	{
		case 'n':
		{
			cout << "\tOld message : " << lis[id_ed].flight_message << "\n\n";
			cout << "\tEnter a new naming of flight(max name length: 80): ";
			cin >> lis[id_ed].flight_message;
			cout << "\n\tDone! New name/message : " << lis[id_ed].flight_message << "\n\n";

			break;
		}

		case 'd':
		{
			char chs_flag = 'n';
			int day = 1, month = 1, year = 1, hour = 1, minutes = 1;
			cout << "\tDo you want change departure date?(y/n): ";
			cin >> chs_flag;

			if (chs_flag == 'y') {

				while (1 != 0)
				{
					cout << "\n\nEnter a new departure date(Example: 22/11/3333): ";
					scanf_s("%i/%i/%i", &day, &month, &year);

					if (day < 1 || day > 31) {
						cout << "\t\t\tError! incorrect 'day' it must be between 1 to 31\n\n";
						continue;
					}
					if (month < 1 || month > 12) {
						cout << "\t\t\tError! incorrect 'month' it must be between 1 to 12\n\n";
						continue;
					}
					if (year < 0) {
						cout << "\t\t\tError! Sounds like someone gonna flight before our era :). But you gotta write again\n\n";
						continue;
					}
					break;
				}

				while (1 != 0) {
					cout << "\n\nEntet a new departure time(Example: 11:11): ";
					scanf_s("%i:%i", &hour, &minutes);

					if ( hour < 0 || hour >= 24) {
						cout << "\t\t\tError! Incorrect 'hour' it must be between 0 to 23\n\n";
						continue;
					}
					if (minutes < 0 || minutes >= 60) {
						cout << "\t\t\tError! Incorrect 'minutes' it must be between 0 to 59\n\n";
						continue;
					}
					break;
				}


				lis[id_ed].t_departure.day = day;
				lis[id_ed].t_departure.month = month;
				lis[id_ed].t_departure.year = year;
				lis[id_ed].t_departure.hours = hour;
				lis[id_ed].t_departure.minutes = minutes;

				printf("\tDone!New departure date/time :\t%02i/%02i/%i %02i:%02i\n\n", lis[id_ed].t_departure.day, lis[id_ed].t_departure.month, lis[id_ed].t_departure.year, lis[id_ed].t_departure.hours, lis[id_ed].t_departure.minutes);
			}

			cout << "Do you want change arrival date?(y/n): ";
			cin >> chs_flag;
			if (chs_flag == 'y') {

				while (1 != 0)
				{
					cout << "\n\nEnter a new arrival date(Example: 22/11/3333): ";
					scanf_s("%i/%i/%i", &day, &month, &year);

					if (day < 1 || day > 31) {
						cout << "\t\t\tError! incorrect 'day' it must be between 1 to 31\n\n";
						continue;
					}
					if (month < 1 || month > 12) {
						cout << "\t\t\tError! incorrect 'month' it must be between 1 to 12\n\n";
						continue;
					}
					if (year < 0) {
						cout << "\t\t\tError! Sounds like someone gonna flight before our era :). But you gotta write it again...\n\n";
						continue;
					}

					while (1 != 0) {
						cout << "\n\nEntet a new arrival time(Example: 11:11): ";
						scanf_s("%i:%i", &hour, &minutes);

						if (hour < 0 || hour >= 24) {
							cout << "\t\t\tError! Incorrect 'hour' it must be between 0 to 23\n\n";
							continue;
						}
						if (minutes < 0 || minutes >= 60) {
							cout << "\t\t\tError! Incorrect 'minutes' it must be between 0 to 59\n\n";
							continue;
						}
						break;
					}



					lis[id_ed].t_arrival.day = day;
					lis[id_ed].t_arrival.month = month;
					lis[id_ed].t_arrival.year = year;
					lis[id_ed].t_arrival.hours = hour;
					lis[id_ed].t_arrival.minutes = minutes;

					printf("\nDone!New arrival date/time :\t%02i/%02i/%i %02i:%02i\n\n", lis[id_ed].t_arrival.day, lis[id_ed].t_arrival.month, lis[id_ed].t_arrival.year, lis[id_ed].t_arrival.hours, lis[id_ed].t_arrival.minutes);
				}
			}
			cout << "\tDo you want change duration time?(y/n): ";
			cin >> chs_flag;

			if (chs_flag == 'y') {
				
				while (1 != 0) {
					cout << "Enter a duration time(Example '1:22'): ";
					scanf_s("%i:%i", &hour, &minutes);

					if (hour < 0 || hour >= 24) {
						cout << "\t\t\tError! Incorrect 'hour' it must be between 0 to 23\n\n";
						continue;
					}
					if (minutes < 0 || minutes >= 60) {
						cout << "\t\t\tError! Incorrect 'minutes' it must be between 0 to 59\n\n";
						continue;
					}
					break;
				}

				lis[id_ed].t_duration.hours = hour;
				lis[id_ed].t_duration.minutes = minutes;

				printf("\nDone! New duration time :\t%i hours %i minutes\n\n", lis[id_ed].t_duration.hours, lis[id_ed].t_duration.minutes);
			}

			break;
			}

		case 'p':
		{
			cout << "\nOld price : " << lis[id_ed].price << endl;
			cout << "\n Enter a new pricing(max chars length: 80): ";
			cin >> lis[id_ed].price;
			cout << "\nDone! New price : " << lis[id_ed].price << endl;

			break;
		}
			
		case 't': 
		{
			char typing = 'e';

			cout << "Old type of flight : " << types[lis[id_ed].flight_type] << endl;
			cout << "\tChoose a type:\n\n" << "\t c - Charter\n" << "\t t - Transit\n" << "\t d - Docking\n";
			cout << "\n Enter a char of type above: ";
			cin >> typing;

			switch (typing)
			{
			case 'E':
			case 'e':
				lis[id_ed].flight_type = fl_type::e;
				break;
			case 'C':
			case 'c':
				lis[id_ed].flight_type = fl_type::c;
				break;
			case 'T':
			case 't':
				lis[id_ed].flight_type = fl_type::t;
				break;
			case 'D':
			case 'd':
				lis[id_ed].flight_type = fl_type::d;
				break;
			default:
				cout << "Invalid choice! Type unchanged.\n";
				return;
			}

			cout << "\nDone! New type : " << types[lis[id_ed].flight_type] << endl;

			break;
			}
	}

}

void update_init(flight old_list[]) {
	
	bool flag = 0;
	cout << "\n\t-----------Entering in edit mode-----------\n";

	while (flag == 0) {
		char updt_chs_in;
		cout << "\n\tChoose operation for a single flight: \t\n\n";
		cout << "\t (N)ame - Edit naming of flight\n";
		cout << "\t (D)ate - Edit time of departure/arrival/duration\n";
		cout << "\t (P)rice - Edit price of flight\n";
		cout << "\t (T)ype - Change type of flight\n";
		cout << "\t (Q)uit - Exit from edit mode\n\n";

		cout << "Enter a character: ";
		cin >> updt_chs_in;

		switch (updt_chs_in) 
		{
		case 'N':
		case 'n':
			edit_data(old_list, 'n');
			break;
		case 'D':
		case 'd':
			edit_data(old_list, 'd');
			break;
		case 'P':
		case 'p':
			edit_data(old_list, 'p');
			break;
		case 'T':
		case 't':
			edit_data(old_list, 't');
			break;
		case 'Q':
		case 'q':
			flag = 1;
			cout << "Exiting from edit mode...\n\n";
			break;
		}
		


	}

}

void bbl_sort(flight unsort_list[], char sort_arg = 'd') {
	flight buf{ "e",{0,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}, e };

	switch (sort_arg)
	{

	case 'd':
	case 'n':
	case 'N':
		{
			
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < (SIZE - i); j++) {
				cout << "s";
				if (unsort_list[i].flight_message.compare(unsort_list[j].flight_message) == 1) {

					buf = unsort_list[j];
					unsort_list[j] = unsort_list[i];
					unsort_list[i] = buf;
				}
			}
		}

		}







	}

	display_list(unsort_list, 0, SIZE);

}

void menu_init(flight lis[]) {

	char chs_in;
	
	cout << "\n\n\tWelcome! ";
	
	while(1>0){
		cout << "\n\n\t-----------Enter a character of an command for your session-----------\n\n";
		cout << "\t (D)isplay - Display list of flight\n";
		cout << "\t (U)pdate - Update list\n";
		cout << "\t (S)ort - Sort list by the bubble sorting\n";
		cout << "\t (Q)uit - Quit from the program\n\n";
		
		cout << "\tEnter a character: ";
		cin >> chs_in;
		cout << endl;

		switch (chs_in)
		{

		case 'D':
		case 'd':

			{
			disp_init(lis);
			break;
			}

		case 'U':
		case 'u':

			{
			update_init(lis);
			break;
			}

		case 'S':
		case 's':

			{
			bbl_sort(lis);
			break;
			}

		case 'Q':
		case 'q':
			cout << "Exiting...\n";
			exit(0);

		default:
			cout << "\t\t\tError! incorrect character: '" << chs_in << "' is must be d / u / s / q \n\n";

		}
	}
}

/*void fupdate(flight mas[SIZE], string filename ) { // Unfinished code

	ifstream fin;
	string str;
	fin.open("myfile.txt"); // ansi для русского текста
		if (fin.is_open()) {
		while (!fin.eof())
		{
			fin >> str;
		
		}
	}
		fin.close();
}*/

int main()
{
	setlocale(LC_ALL, "Ru");

	flight flight_list[SIZE]{
		{"Челябинск - Санкт-Петербург", {16,04,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 12998.99, c},
		{"Челябинск - Уфа", {18,04,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 12998.99, c},
		{"Челябинск - Жуково", {16,04,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 12998.99, c},
		{"Якутск - Санкт-Петербург", {12,04,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 12998.99, c},
		{"Курган - Казань", {5,05,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 12998.99, c},
		{"Челябинск - Санкт-Петербург", {16,04,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 12998.99, c},
		{"Челябинск - Санкт-Петербург", {22,04,2026,14,10}, {22,04,2026,21,55}, {0,0,0,5,55}, 12998.99, },
		{"Челябинск - Санкт-Петербург", {11,04,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 12998.99, c},
		{"Москва - Санкт-Петербург", {16,04,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 12998.99, },
		{"Рязань - Санкт-Петербург", {30,04,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 12998.99, c},
		{"Севастополь - Санкт-Петербург", {12,05,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 12998.99, t},
		{"Челябинск - Санкт-Петербург", {11,05,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 12998.99, d},
		{"Карачево - Тольятти", {16,04,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 12998.99, c},
		{"Name1 - Name", {10,02,2024,14,10}, {16,04,2026,21,55}, {0,0,0,10,5}, 1298.99, d},
		{"Name2 - Name", {11,03,2025,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 12998.99, t},
		{"Name3 - Name", {12,05,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 12998.99, c},
		{"Name4 - Name", {13,07,2027,14,10}, {16,04,2026,21,55}, {0,0,0,3,45}, 12138.99, c},
		{"Name - Name", {16,04,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 12998.99, t},
		{"Name - Name", {16,04,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 14498.99, c},
		{"Name - Name", {16,04,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 12998.99, t},
		{"Name - Name", {16,04,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 1512998.99, c},
		{"Name - Name", {16,04,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 132248.99, c},
		{"Name - Name", {16,04,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 12998.99, c},
		{"Name - Name", {16,04,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 415998.99, c},
		{"Name - Name", {16,04,2026,14,10}, {16,04,2026,21,55}, {0,0,0,5,55}, 132248.99, c}
	};

	menu_init(flight_list);

	//	fupdate(flight_list, "myfile.txt");

	return 0;
};
