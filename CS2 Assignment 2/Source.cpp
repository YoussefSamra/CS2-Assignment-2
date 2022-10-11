#include "Person.h"



Person::Person() {
	ID = "";
	Name = "";
	age = 0;
}

Person::Person(string x, string y, int z) {
	Name = x;
	ID = y;
	age = z;
}

void Person::printinfo() {

	cout << endl;
	cout << "Name: " << Name << endl;
	cout << "ID: " << ID << endl;
	cout << "Age: " << age << endl;
	
	
};


bool Customer::operator>(Customer& a)
{
	if (CM.hours > a.CM.hours)
		return true;
	else return false;
}

bool Customer::operator<(Customer& a) {
	if (CM.hours < a.CM.hours)
		return true;
	else return false;

};																				
																								// Overloading the operands

bool Customer::operator==(Customer& a) {

	if (CM.hours == a.CM.hours && CM.minutes == a.CM.minutes)
		return true;
	else return false;

};

void Customer::printinfo() {

	cout << endl;
	cout << "Name: " << Name << endl;
	cout << "Age: " << age << endl;

}


void Mechanic::printinfo() {

	cout << endl;
	cout << "Name: " << Name << endl;
	cout << "ID: " << ID << endl;
	cout << "Age: " << age << endl;

}



string Customer::getMID() {
	return mechanicID;
}
appointment Customer::getAP() {
	return CM;
}
void Customer::setMID(string x) {
	mechanicID = x;
}
void Customer::setAP(int h, int m) {
	appointment x;
	if (h > 0 && h < 24 && m >= 0 && m < 60)
	{
		x.hours = h;
		x.minutes = m;
		CM = x;
		cout << endl << "Appointment For " << Name << " Succesfully Created: " << endl << "At " << x.hours << ":" << x.minutes << endl;


	}
	else cout << endl << "Time not applicable" << endl;   // If time is Out of normal range

}

void Mechanic::setAP(appointment a) {
	
	if (isAvailable(a) == true) {
		ap[index] = a;
	}
}

bool Mechanic::isAvailable(appointment b) {
	index = 0;
	
	for (int i = 0; i < 30; i++) {

		if (ap[i].hours == 0 && ap[i].minutes == 0)
		{
			index = i;  return true;
		}
		else if (b.hours == ap[i].hours && b.minutes == ap[i].minutes) {
			cout << endl << "Time Slot UnAvailable" << endl; return false;
		}
			 
	}


}

int Mechanic::getcounter() {
	return counter;
}
appointment Mechanic::getAP(int index) {
	if (index <= counter)
	{
		return ap[index - 1];
	}
	else cout << "Unavailble Index";
}
appointment Mechanic::getLatestAP() {
	return ap[counter - 1];
}
void Mechanic::setcounter(int x) {
	counter = x;
}


int main() {

	fstream MechanicT; MechanicT.open("Mechanic.txt", ios::in);   
	fstream CustomerT; CustomerT.open("Customer.txt", ios::in);   // To Input to file
	if (MechanicT.is_open() && CustomerT.is_open()) {
		cout << "Files opened Succesfully" << endl; char in;
		cout << "Do you wish to continue [Y or N]: "; cin >> in;

		if (in == 'Y') {
			system("CLS");
		}
		else exit(0);
	}
	else {
		cout << "Error opening input files"; exit(0);
	}

	vector<Mechanic> Mech;
	Mechanic tempM[10];

	vector<Customer> Cust;
	Customer tempC[30];

	////////////////////////////////////////////
	int xcounter = 0;
	while (MechanicT >> tempM[xcounter].Name >> tempM[xcounter].age >> tempM[xcounter].ID >> tempM[xcounter].counter) {
		Mech.push_back(tempM[xcounter]); xcounter++;
	}	Mechanic Mechanics[10]; // slots for 10 mechanics



	int fcounter = 0;
	for (const auto& mechanic : Mech) {
		Mechanics[fcounter].Name = mechanic.Name;
		Mechanics[fcounter].age = mechanic.age;
		Mechanics[fcounter].ID = mechanic.ID;
		Mechanics[fcounter].counter = mechanic.counter;

		fcounter++;

	}


	/*	for (int i = 0; i < 10; i++) {
			x[i].printinfo();
			cout << "Number of appointments: " << x[i].counter << endl;
			char input;
			cout << "Do you wish to continue: [Y or N]: "; cin >> input;                                              [test if it works]

			if (input == 'Y') {
				system("CLS");
			}
			else exit(0);
		}			                                                   								  	*/////////////////////////////////////////////


		//////////////////////////////////

	int xxcounter = 0;
	int ffcounter = 0;
	appointment app[24];
	while (CustomerT >> tempC[xxcounter].Name >> tempC[xxcounter].age >> tempC[xxcounter].hrs >> tempC[xxcounter].mins) {
		Cust.push_back(tempC[xxcounter]); xxcounter++;
	} Customer Customers[30];

	for (const auto& customer : Cust) {
		Customers[ffcounter].Name = customer.Name;
		Customers[ffcounter].age = customer.age;
		Customers[ffcounter].setAP(customer.hrs, customer.mins);

		ffcounter++;

	}char xt;
	cout << endl << "Do you wish to continue [Y or N]: "; cin >> xt;

	if (xt == 'Y') {
		system("CLS");
	}
	else exit(0);

	///////////////////////////////////////
	

	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 29; j++) {
			if (Customers[j] > Customers[j + 1]) {
				Customer temp = Customers[j];                               // Sorting Appointments
				Customers[j] = Customers[j + 1];
				Customers[j + 1] = temp;
				
			}
		}


	}


	
cout << endl << "Mechanics Available For Today: ";
for(int i = 0; i < 5; i++){
	Mechanics[i].printinfo();
}

char xyz;
cout <<  endl << "Do you wish to continue [Y or N]: "; cin >> xyz;

if (xyz == 'Y') {
	system("CLS");
}
else exit(0);

queue<Customer> CustomerQ;

fstream ListOfAppointment;
	ListOfAppointment.open("ListOfAppointments.txt");
	fstream file("ListOfAppointments.txt", ios::in);

for (int j = 0 ; j < 30; j++) {
	for (int i = 0; i < 5; i++)
	{
		if (Mechanics[i].isAvailable(Customers[j].getAP())) {
			
			CustomerQ.push(Customers[j]);
			cout << endl << "Customer " << j << " Succesfully Enqueued" << endl;
				Mechanics[i].setAP(Customers[j].getAP());
				Customers[j].setMID(Mechanics[i].ID);
			cout << "Customer " << j << " Succesfully Dequeued" << endl;
				CustomerQ.pop();
				

				// Checking availability then setting appointment from Customer To Mechanic

				ListOfAppointment << endl << Customers[j].Name << " Has been set to Mechanic: " << Mechanics[i].Name << " With ID: " << Mechanics[i].ID << endl;
				cout << endl << Customers[j].Name << " Has been set to Mechanic: " << Mechanics[i].Name << " With ID: " << Mechanics[i].ID << endl;
				  break;
			

		}	
	}
}
	


	return 0;
}