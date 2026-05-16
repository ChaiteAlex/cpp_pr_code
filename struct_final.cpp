// Structures.cpp : Этот файл содержит тему структур

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int SIZE = 20;

enum fl_type : char { e, c, t, d };
char types[4][8]{ "Default", "Charter", "Transit", "Docking" };

struct fltime { // Описываем отдельную структуру для времени(отправления/прибытия и полета)
	int day, month, year, hours, minutes;
};

struct flight
{
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
	int buf, start_in = 1, end_in = SIZE;

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

		cout << "Error! Index out of range: " << id_ed << " must be in range 1 to " << SIZE;
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

void bbl_sort(flight unsort_list[SIZE]) {

	cout << "\n\t-----------Creating sorted copy by duration-----------\n\n";

	// СОЗДАЁМ КОПИЮ МАССИВА
	flight sorted_list[SIZE];

	// Копируем все элементы
	for (int i = 0; i < SIZE; i++) {
		sorted_list[i] = unsort_list[i];
	}

	// СОРТИРУЕМ КОПИЮ по длительности полета
	flight buf;
	bool swapped;

	for (int i = 0; i < SIZE - 1; i++) {
		swapped = false;

		for (int j = 0; j < SIZE - i - 1; j++) {
			// Пропускаем пустые записи
			if (sorted_list[j].flight_message.empty() || sorted_list[j + 1].flight_message.empty()) {
				continue;
			}

			// Переводим время в минуты для сравнения
			int dur1 = sorted_list[j].t_duration.hours * 60 + sorted_list[j].t_duration.minutes;
			int dur2 = sorted_list[j + 1].t_duration.hours * 60 + sorted_list[j + 1].t_duration.minutes;

			if (dur1 > dur2) {
				buf = sorted_list[j];
				sorted_list[j] = sorted_list[j + 1];
				sorted_list[j + 1] = buf;
				swapped = true;
			}
		}

		if (!swapped) break;
	}

	cout << "\tSorting completed!\n\n";

	// Выводим ОТСОРТИРОВАННУЮ КОПИЮ (исходный массив не меняется)
	cout << "\t=== SORTED COPY (by duration) ===\n\n";

	for (int i = 0; i < SIZE; i++) {
		if (!sorted_list[i].flight_message.empty()) {
			cout << "\t[" << i + 1 << "] " << sorted_list[i].flight_message << endl;
			printf("\t   Duration: %i hours %i minutes\n",
				sorted_list[i].t_duration.hours,
				sorted_list[i].t_duration.minutes);
			printf("\t   Price: %.2f RUB\n", sorted_list[i].price);
			cout << "\t   Type: " << types[sorted_list[i].flight_type] << "\n";
			cout << endl;
		}
	}

	cout << "\n\tNOTE: Original array remains unchanged!\n";
	cout << "\tPress Enter to continue...";
	cin.ignore();
	cin.get();
}

// ==================== НОВЫЕ ФУНКЦИИ ДЛЯ ФИЛЬТРАЦИИ ЧАРТЕРНЫХ РЕЙСОВ ====================

// Функция для фильтрации чартерных рейсов с ценой более N рублей
void filter_charter_by_price(flight source[], flight dest[], int& dest_count, double min_price) {
	dest_count = 0;

	for (int i = 0; i < SIZE; i++) {
		if (!source[i].flight_message.empty() &&
			source[i].flight_type == c &&
			source[i].price > min_price) {
			dest[dest_count] = source[i];
			dest_count++;
		}
	}

	cout << "\n\tFiltered " << dest_count << " charter flights with price > " << min_price << " RUB\n";
}

// Функция для вывода отфильтрованных данных (оберточная функция)
void display_filtered_charter_flights(flight source[]) {
	cout << "\n\t-----------Filtered Charter Flights by Price-----------\n\n";

	double min_price;
	cout << "\tEnter minimum price (RUB): ";
	cin >> min_price;

	if (min_price < 0) {
		cout << "\t\t\tError! Price cannot be negative!\n";
		return;
	}

	flight filtered_flights[SIZE];
	int filtered_count = 0;

	filter_charter_by_price(source, filtered_flights, filtered_count, min_price);

	if (filtered_count == 0) {
		cout << "\n\tNo charter flights found with price > " << min_price << " RUB\n\n";
	}
	else {
		cout << "\n\t=== Charter Flights with price > " << min_price << " RUB ===\n\n";
		cout << "\tTotal found: " << filtered_count << " flights\n\n";

		// Выводим отфильтрованные данные
		for (int i = 0; i < filtered_count; i++) {
			cout << "\t[" << i + 1 << "] " << filtered_flights[i].flight_message << endl;
			printf("\t   Departure: %02i.%02i.%04i %02i:%02i\n",
				filtered_flights[i].t_departure.day,
				filtered_flights[i].t_departure.month,
				filtered_flights[i].t_departure.year,
				filtered_flights[i].t_departure.hours,
				filtered_flights[i].t_departure.minutes);
			printf("\t   Arrival:   %02i.%02i.%04i %02i:%02i\n",
				filtered_flights[i].t_arrival.day,
				filtered_flights[i].t_arrival.month,
				filtered_flights[i].t_arrival.year,
				filtered_flights[i].t_arrival.hours,
				filtered_flights[i].t_arrival.minutes);
			printf("\t   Duration:  %i hours %i minutes\n",
				filtered_flights[i].t_duration.hours,
				filtered_flights[i].t_duration.minutes);
			printf("\t   Price:     %.2f RUB\n", filtered_flights[i].price);
			cout << "\t   Type:      " << types[filtered_flights[i].flight_type] << "\n";
			cout << endl;
		}

		// Дополнительная статистика
		double total = 0, min_price_found = filtered_flights[0].price, max_price_found = filtered_flights[0].price;
		for (int i = 0; i < filtered_count; i++) {
			total += filtered_flights[i].price;
			if (filtered_flights[i].price < min_price_found) min_price_found = filtered_flights[i].price;
			if (filtered_flights[i].price > max_price_found) max_price_found = filtered_flights[i].price;
		}

		cout << "\t--- Statistics ---\n";
		printf("\tAverage price: %.2f RUB\n", total / filtered_count);
		printf("\tMinimum price: %.2f RUB\n", min_price_found);
		printf("\tMaximum price: %.2f RUB\n", max_price_found);
		cout << endl;
	}

	cout << "\n\tPress Enter to continue...";
	cin.ignore();
	cin.get();
}

// Альтернативная версия с предустановленным порогом (если не хотите запрашивать у пользователя)
void display_filtered_charter_flights_fixed(flight source[], double min_price = 5000.0) {
	cout << "\n\t-----------Filtered Charter Flights by Price-----------\n\n";
	cout << "\tMinimum price threshold: " << min_price << " RUB\n\n";

	flight filtered_flights[SIZE];
	int filtered_count = 0;

	filter_charter_by_price(source, filtered_flights, filtered_count, min_price);

	if (filtered_count == 0) {
		cout << "\n\tNo charter flights found with price > " << min_price << " RUB\n\n";
	}
	else {
		cout << "\t=== Charter Flights with price > " << min_price << " RUB ===\n\n";
		cout << "\tTotal found: " << filtered_count << " flights\n\n";
		display_list(filtered_flights, 0, filtered_count);
	}

	cout << "\n\tPress Enter to continue...";
	cin.ignore();
	cin.get();
}

// Проверка, оканчивается ли пункт назначения на "инск"
bool ends_with_insk(const string& message) {
	// Ищем позицию " - " в строке
	size_t pos = message.find(" - ");
	if (pos == string::npos) return false;

	// Получаем пункт назначения (часть после " - ")
	string destination = message.substr(pos + 3);

	// Проверяем окончание
	if (destination.length() >= 4) {
		string ending = destination.substr(destination.length() - 4);
		return (ending == "инск" || ending == "Инск");
	}
	return false;
}

// Фильтрация рейсов: пункт назначения оканчивается на "инск" И рейс стыковочный (тип Transit - t)
void filter_flights(flight source[], flight dest[], int& dest_count) {
	dest_count = 0;

	for (int i = 0; i < SIZE; i++) {
		if (!source[i].flight_message.empty()) {
			if (ends_with_insk(source[i].flight_message) && source[i].flight_type == t) {
				dest[dest_count] = source[i];
				dest_count++;
			}
		}
	}

	cout << "\n\tFiltered " << dest_count << " flights (ending with 'инск' and connecting/transit)\n";
}

// Сортировка массива по времени полета (пузырьком)
void sort_by_duration(flight list[], int count) {
	if (count <= 1) return;

	bool swapped;
	flight buf;

	// Лямбда-функция для перевода времени полета в минуты
	auto get_duration_minutes = [](const flight& f) -> int {
		return f.t_duration.hours * 60 + f.t_duration.minutes;
		};

	for (int i = 0; i < count - 1; i++) {
		swapped = false;

		for (int j = 0; j < count - i - 1; j++) {
			if (get_duration_minutes(list[j]) > get_duration_minutes(list[j + 1])) {
				// Обмениваем структуры целиком
				buf = list[j];
				list[j] = list[j + 1];
				list[j + 1] = buf;
				swapped = true;
			}
		}

		if (!swapped) break;
	}

	cout << "\n\tSorted " << count << " flights by duration\n";
}

// Вывод данных по конкретному рейсу
void display_single_flight(flight list[], int index) {
	if (index < 0 || index >= SIZE || list[index].flight_message.empty()) {
		cout << "\t\t\tError! Flight not found!\n";
		return;
	}

	cout << "\n\t=== Flight Data ===\n\n";
	cout << "Route:\t\t" << list[index].flight_message << endl;
	printf("Departure:\t%02i.%02i.%04i %02i:%02i\n",
		list[index].t_departure.day, list[index].t_departure.month,
		list[index].t_departure.year, list[index].t_departure.hours,
		list[index].t_departure.minutes);
	printf("Arrival:\t%02i.%02i.%04i %02i:%02i\n",
		list[index].t_arrival.day, list[index].t_arrival.month,
		list[index].t_arrival.year, list[index].t_arrival.hours,
		list[index].t_arrival.minutes);
	printf("Duration:\t%i hours %i minutes\n",
		list[index].t_duration.hours, list[index].t_duration.minutes);
	printf("Price:\t\t%.2f RUB\n", list[index].price);
	cout << "Type:\t\t" << types[list[index].flight_type] << endl;
	cout << endl;
}

// Проверка, вылетает ли рейс утром (с 6:00 до 11:59)
bool is_morning_flight(const flight& f) {
	return (f.t_departure.hours >= 6 && f.t_departure.hours <= 11);
}

// Вывод 2 чартерных рейсов, вылетающих утром
void display_two_charter_morning(flight list[]) {
	int found = 0;

	cout << "\n\t=== First 2 Charter Morning Flights ===\n\n";

	for (int i = 0; i < SIZE && found < 2; i++) {
		if (!list[i].flight_message.empty() &&
			list[i].flight_type == c &&
			is_morning_flight(list[i])) {

			found++;
			cout << "[" << found << "] " << list[i].flight_message << endl;
			printf("\tDeparture: %02i.%02i.%04i %02i:%02i\n",
				list[i].t_departure.day, list[i].t_departure.month,
				list[i].t_departure.year, list[i].t_departure.hours,
				list[i].t_departure.minutes);
			printf("\tDuration: %i hours %i minutes\n",
				list[i].t_duration.hours, list[i].t_duration.minutes);
			printf("\tPrice: %.2f RUB\n", list[i].price);
			cout << endl;
		}
	}

	if (found == 0) {
		cout << "\tNo charter morning flights found!\n\n";
	}
	else if (found < 2) {
		cout << "\tFound only " << found << " charter morning flight(s)\n\n";
	}
}

// Главная функция для выполнения всех задач
void demonstrate_tasks(flight lis[]) {
	cout << "\n\t-----------Executing Tasks-----------\n\n";

	// TASK 1: Filter flights ending with "инск" and connecting (type t)
	flight filtered_flights[SIZE];
	int filtered_count = 0;

	filter_flights(lis, filtered_flights, filtered_count);

	if (filtered_count > 0) {
		cout << "\n\tFiltered flights (ending with 'инск' + connecting):\n";
		display_list(filtered_flights, 0, filtered_count);

		// TASK 2: Sort filtered array by duration
		sort_by_duration(filtered_flights, filtered_count);

		cout << "\n\tSorted filtered flights by duration:\n";
		display_list(filtered_flights, 0, filtered_count);

		// TASK 3: Display data for a specific flight
		cout << "\n\tDisplay data for specific flight (first filtered flight):\n";
		if (filtered_count > 0) {
			display_single_flight(filtered_flights, 0);
		}
	}
	else {
		cout << "\tNo flights match the filter criteria!\n\n";
	}

	// TASK 4: Display 2 charter flights that depart in the morning
	display_two_charter_morning(lis);

	cout << "\n\tPress Enter to continue...";
	cin.ignore();
	cin.get();
}

// ==================== КОНЕЦ НОВЫХ ФУНКЦИЙ ====================

void menu_init(flight lis[]) {
    char chs_in;
    
    cout << "\n\n\tWelcome! ";
    
    while(1>0){
        cout << "\n\n\t-----------Enter a character of an command for your session-----------\n\n";
        cout << "\t (D)isplay - Display list of flight\n";
        cout << "\t (U)pdate - Update list\n";
        cout << "\t (S)ort - Sort list by the bubble sorting\n";
        cout << "\t (E)xecute - Execute tasks (filter, sort, display)\n";
        cout << "\t (C)harter - Filter charter flights by price\n";
        cout << "\t (L)oad - Load data from file\n";    
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

		case 'E':
		case 'e':
		{
			demonstrate_tasks(lis);
			break;
		}

		case 'C':  // ← НОВЫЙ CASE
		case 'c':
		{
			display_filtered_charter_flights(lis);
			break;
		}

		case 'Q':
		case 'q':
			cout << "Exiting...\n";
			exit(0);

		case 'L':
        case 'l':
            {
            fupdate(lis, "myfile.txt");
            break;
            }
		default:
			cout << "\t\t\tError! incorrect character: '" << chs_in << "' is must be d / u / s / e / c / q \n\n";
		}
	}
}

void fupdate(flight mas[SIZE], string filename) {
	
	cout << "\n\t-----------Loading data from file-----------\n\n";
	
	ifstream fin;
	fin.open(filename);
	
	if (!fin.is_open()) {
		cout << "\t\t\tError! Cannot open file: " << filename << endl;
		cout << "\t\t\tCheck if file exists and try again.\n\n";
		return;
	}
	
	cout << "\tFile opened successfully!\n\n";
	
	int records_loaded = 0;
	string line;
	
	// Временные переменные для чтения
	string temp_message;
	int d_day, d_month, d_year, d_hours, d_minutes;
	int a_day, a_month, a_year, a_hours, a_minutes;
	int dur_hours, dur_minutes;
	double temp_price;
	string temp_type;
	
	// Пропускаем возможный BOM в файле (для UTF-8)
	char bom_check;
	fin.peek();
	
	while (!fin.eof() && records_loaded < SIZE) {
		
		// Читаем маршрут (может содержать пробелы)
		if (!getline(fin, temp_message)) break;
		
		// Пропускаем пустые строки
		if (temp_message.empty()) continue;
		
		// Читаем дату отправления
		if (!(fin >> d_day >> d_month >> d_year >> d_hours >> d_minutes)) {
			cout << "\t\t\tWarning! Invalid departure date format at record " << records_loaded + 1 << ". Skipped.\n";
			fin.clear();
			fin.ignore(1000, '\n');
			continue;
		}
		
		// Читаем дату прибытия
		if (!(fin >> a_day >> a_month >> a_year >> a_hours >> a_minutes)) {
			cout << "\t\t\tWarning! Invalid arrival date format at record " << records_loaded + 1 << ". Skipped.\n";
			fin.clear();
			fin.ignore(1000, '\n');
			continue;
		}
		
		// Читаем длительность
		if (!(fin >> dur_hours >> dur_minutes)) {
			cout << "\t\t\tWarning! Invalid duration format at record " << records_loaded + 1 << ". Skipped.\n";
			fin.clear();
			fin.ignore(1000, '\n');
			continue;
		}
		
		// Читаем цену
		if (!(fin >> temp_price)) {
			cout << "\t\t\tWarning! Invalid price format at record " << records_loaded + 1 << ". Skipped.\n";
			fin.clear();
			fin.ignore(1000, '\n');
			continue;
		}
		
		// Читаем тип рейса
		if (!(fin >> temp_type)) {
			cout << "\t\t\tWarning! Invalid flight type at record " << records_loaded + 1 << ". Skipped.\n";
			fin.clear();
			fin.ignore(1000, '\n');
			continue;
		}
		
		// Пропускаем оставшийся перевод строки после типа
		fin.ignore(1000, '\n');
		
		// Проверка валидности данных
		bool valid = true;
		
		if (d_day < 1 || d_day > 31) {
			cout << "\t\t\tWarning! Record " << records_loaded + 1 << ": Invalid departure day (" << d_day << "). Skipped.\n";
			valid = false;
		}
		if (d_month < 1 || d_month > 12) {
			cout << "\t\t\tWarning! Record " << records_loaded + 1 << ": Invalid departure month (" << d_month << "). Skipped.\n";
			valid = false;
		}
		if (d_year < 0) {
			cout << "\t\t\tWarning! Record " << records_loaded + 1 << ": Invalid departure year (" << d_year << "). Skipped.\n";
			valid = false;
		}
		if (a_day < 1 || a_day > 31) {
			cout << "\t\t\tWarning! Record " << records_loaded + 1 << ": Invalid arrival day (" << a_day << "). Skipped.\n";
			valid = false;
		}
		if (a_month < 1 || a_month > 12) {
			cout << "\t\t\tWarning! Record " << records_loaded + 1 << ": Invalid arrival month (" << a_month << "). Skipped.\n";
			valid = false;
		}
		if (a_year < 0) {
			cout << "\t\t\tWarning! Record " << records_loaded + 1 << ": Invalid arrival year (" << a_year << "). Skipped.\n";
			valid = false;
		}
		if (d_hours < 0 || d_hours >= 24) {
			cout << "\t\t\tWarning! Record " << records_loaded + 1 << ": Invalid departure hours (" << d_hours << "). Skipped.\n";
			valid = false;
		}
		if (d_minutes < 0 || d_minutes >= 60) {
			cout << "\t\t\tWarning! Record " << records_loaded + 1 << ": Invalid departure minutes (" << d_minutes << "). Skipped.\n";
			valid = false;
		}
		if (a_hours < 0 || a_hours >= 24) {
			cout << "\t\t\tWarning! Record " << records_loaded + 1 << ": Invalid arrival hours (" << a_hours << "). Skipped.\n";
			valid = false;
		}
		if (a_minutes < 0 || a_minutes >= 60) {
			cout << "\t\t\tWarning! Record " << records_loaded + 1 << ": Invalid arrival minutes (" << a_minutes << "). Skipped.\n";
			valid = false;
		}
		if (dur_hours < 0 || dur_hours > 48) {
			cout << "\t\t\tWarning! Record " << records_loaded + 1 << ": Invalid duration hours (" << dur_hours << "). Skipped.\n";
			valid = false;
		}
		if (dur_minutes < 0 || dur_minutes >= 60) {
			cout << "\t\t\tWarning! Record " << records_loaded + 1 << ": Invalid duration minutes (" << dur_minutes << "). Skipped.\n";
			valid = false;
		}
		if (temp_price < 0) {
			cout << "\t\t\tWarning! Record " << records_loaded + 1 << ": Invalid price (" << temp_price << "). Skipped.\n";
			valid = false;
		}
		
		// Конвертируем тип рейса
		fl_type temp_fl_type;
		if (temp_type == "e" || temp_type == "E" || temp_type == "Default") {
			temp_fl_type = fl_type::e;
		} else if (temp_type == "c" || temp_type == "C" || temp_type == "Charter") {
			temp_fl_type = fl_type::c;
		} else if (temp_type == "t" || temp_type == "T" || temp_type == "Transit") {
			temp_fl_type = fl_type::t;
		} else if (temp_type == "d" || temp_type == "D" || temp_type == "Docking") {
			temp_fl_type = fl_type::d;
		} else {
			cout << "\t\t\tWarning! Record " << records_loaded + 1 << ": Unknown type '" << temp_type << "'. Set to Default.\n";
			temp_fl_type = fl_type::e;
		}
		
		// Если данные валидны, записываем в массив
		if (valid) {
			mas[records_loaded].flight_message = temp_message;
			mas[records_loaded].t_departure = {d_day, d_month, d_year, d_hours, d_minutes};
			mas[records_loaded].t_arrival = {a_day, a_month, a_year, a_hours, a_minutes};
			mas[records_loaded].t_duration = {0, 0, 0, dur_hours, dur_minutes};
			mas[records_loaded].price = temp_price;
			mas[records_loaded].flight_type = temp_fl_type;
			
			records_loaded++;
		}
	}
	
	fin.close();
	
	cout << "\n\t-----------Loading completed!-----------\n\n";
	cout << "\tRecords loaded successfully: " << records_loaded << " from " << filename << endl;
	
	// Очищаем остальные записи (помечаем как пустые)
	for (int i = records_loaded; i < SIZE; i++) {
		mas[i].flight_message.clear();
	}
	
	cout << "\n\tDo you want to display loaded list?(y/n): ";
	char show;
	cin >> show;
	
	if (tolower(show) == 'y') {
		cout << endl;
		display_list(mas, 0, SIZE);
	}
	
	cout << "\n\tPress Enter to continue...";
	cin.ignore();
	cin.get();
}

int main()
{
	setlocale(LC_ALL, "Ru");

	flight flight_list[SIZE]{
		// Рейсы, оканчивающиеся на "инск" И стыковочные (тип t) - БУДУТ ОТФИЛЬТРОВАНЫ
		{"Москва - Челябинск", {10,2,2024,9,10}, {10,2,2024,19,15}, {0,0,0,10,5}, 1298.99, t},
		{"Санкт-Петербург - Красноярск", {11,3,2025,14,10}, {12,3,2025,8,55}, {0,0,0,18,45}, 18998.99, t},
		{"Екатеринбург - Пермь", {12,5,2026,8,30}, {12,5,2026,10,45}, {0,0,0,2,15}, 3299.99, t},

		// Чартерные рейсы (тип c), вылетающие утром (6:00-11:59) - БУДУТ ВЫВЕДЕНЫ
		{"Москва - Сочи", {15,6,2026,7,30}, {15,6,2026,10,15}, {0,0,0,2,45}, 5999.99, c},
		{"Санкт-Петербург - Симферополь", {20,7,2026,8,15}, {20,7,2026,11,30}, {0,0,0,3,15}, 7499.99, c},
		{"Казань - Анапа", {25,8,2026,9,45}, {25,8,2026,12,00}, {0,0,0,2,15}, 4299.99, c},

		// Чартерные рейсы (тип c), вылетающие НЕ утром - НЕ БУДУТ ВЫВЕДЕНЫ
		{"Новосибирск - Тайланд", {05,7,2026,23,30}, {06,7,2026,8,45}, {0,0,0,14,15}, 35999.99, c},
		{"Владивосток - Китай", {12,8,2026,15,20}, {12,8,2026,17,50}, {0,0,0,2,30}, 18999.99, c},

		// Обычные рейсы (тип e - Default)
		{"Москва - Лондон", {01,4,2026,12,00}, {1,4,2026,16,30}, {0,0,0,4,30}, 24999.99, e},
		{"Санкт-Петербург - Париж", {05,4,2026,10,15}, {5,4,2026,14,45}, {0,0,0,4,30}, 22999.99, e},
		{"Екатеринбург - Дубай", {10,4,2026,11,00}, {10,4,2026,15,30}, {0,0,0,4,30}, 27999.99, e},
		{"Новосибирск - Стамбул", {15,4,2026,13,20}, {15,4,2026,17,50}, {0,0,0,4,30}, 19999.99, e},

		// Рейсы, оканчивающиеся на "инск" НО НЕ стыковочные (тип e или c) - НЕ БУДУТ ОТФИЛЬТРОВАНЫ
		{"Ростов-на-Дону - Челябинск", {20,4,2026,14,10}, {20,4,2026,21,55}, {0,0,0,7,45}, 8999.99, e},
		{"Нижний Новгород - Красноярск", {25,4,2026,9,00}, {25,4,2026,18,30}, {0,0,0,9,30}, 10999.99, c},

		// Стыковочные рейсы (тип t) НЕ оканчивающиеся на "инск" - НЕ БУДУТ ОТФИЛЬТРОВАНЫ
		{"Москва - Владивосток", {1,5,2026,15,00}, {2,05,2026,12,45}, {0,0,0,21,45}, 28999.99, t},
		{"Санкт-Петербург - Хабаровск", {10,5,2026,13,30}, {11,5,2026,10,15}, {0,0,0,20,45}, 26999.99, t},

		// Остальные рейсы для заполнения массива
		{"Казань - Минск", {18,5,2026,8,00}, {18,5,2026,10,30}, {0,0,0,2,30}, 5499.99, e},
		{"Самара - Уфа", {22,5,2026,16,15}, {22,5,2026,18,00}, {0,0,0,1,45}, 3299.99, c},
		{"Омск - Тюмень", {25,5,2026,11,30}, {25,5,2026,12,45}, {0,0,0,1,15}, 2499.99, e},
		{"Краснодар - Ростов-на-Дону", {28,5,2026,19,00}, {28,5,2026,20,30}, {0,0,0,1,30}, 1999.99, e},
	};

	menu_init(flight_list);

	//  fupdate(flight_list, "myfile.txt");

	return 0;
}
