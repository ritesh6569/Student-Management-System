#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include<iomanip>
using namespace std;
class Student{
	public:
void create()
{
	fstream fout;

	fout.open("student.csv", ios::out | ios::app);

	int ID;
	string Class;
	char grade;
	string name;

	    cout<<"Enter The name of the student : ";
	  	getline(cin,name);
		getline(cin,name);
		cout<<"Enter the ID of the student : ";
		cin>>ID;
		cout<<"Enter the Class of the student : ";
		getline(cin,Class);
		getline(cin,Class);
		cout<<"Enter the Grade of the student = ";
		cin>>grade;
			
		fout << name << ","<< ID << ","<< Class << ","<< grade<<endl;
	fout.close();
	Option(); 
	
}

void read_record()
{
	fstream fin;

	fin.open("student.csv", ios::in);

	string  ID;
	int count = 0;
	cout << "Enter the ID "
		<< "of the student to display details: ";
	 cin >> ID;
	vector<string> row;
	string line, word;

	while (getline(fin,line)) {

		row.clear();
		
		stringstream s(line);

		
		while (getline(s, word, ',')) {

			row.push_back(word);
			
		}

		string ID2 = row[1];

		if (ID2 == ID) {
            count = 1;
			cout << "Name : " << row[0] << "\n";
			cout << "ID : " << row[1] << "\n";
			cout << "Class : " << row[2] << "\n";
			cout << "Grade : " << row[3] << "\n";
			break;
		}
	}
	if (count == 0){
		cout << "Record not found\n";
	}
	Option(); 
}

void update_recode()
{
	fstream fin, fout;

	fin.open("student.csv", ios::in);

	fout.open("studentnew.csv", ios::out);

	int ID, ID1,count = 0, i;
	string change;
	char grade;
	int index;
	string line, word;
	vector<string> row;

	cout << "Enter the ID "
		<< "of the record to be updated: ";
	cin >> ID;
    
	cout<<"Choose option which you want to change "<<endl;
	cout<<endl;
	cout<<" 1 : Name "<<endl;
	cout<<" 2 : ID "<<endl;
	cout<<" 3 : class "<<endl;
	cout<<" 4 : grade "<<endl;
	int k;
	cout <<"Enter choice: ";
	cin>>k;

	switch(k)
	{
		case 1:
		 index = 0;
          break;

		 case 2:
		 index = 1;
		  break;
		  
		 case 3:
		 index = 2;
		  break;
		  
         case 4:
		 index =3;
		  break;
		   
		default :
         cout << "Wrong choice.Enter again\n";
		 update_recode();
	}

	cout << "Enter change: ";
	getline(cin,change);
	getline(cin,change);
	
	while (!fin.eof()) {

		row.clear();

		getline(fin, line);
		stringstream s(line);

		while (getline(s, word, ',')) {
			row.push_back(word);
		}

		ID1 = stoi(row[1]);
		int row_size = row.size();

		if (ID1== ID) {
			count = 1;
			stringstream convert;

			convert << change;

			row[index] = convert.str();

			if (!fin.eof()) {
				for (i = 0; i < row_size - 1; i++) {
					fout << row[i] << ", ";
				}

				fout << row[row_size - 1] << "\n";
			}
		}
		else {
			if (!fin.eof()) {
				for (i = 0; i < row_size - 1; i++) {
					fout << row[i] << ", ";
				}
				fout << row[row_size - 1] << "\n";
			}
		}
		if (fin.eof())
			break;
	}
	if (count == 0)
		cout << "Record not found\n";

	fin.close();
	fout.close();

	remove("student.csv");

	rename("studentnew.csv", "student.csv");
	Option(); 
}

void delete_record()
{

	fstream fin, fout;

	fin.open("student.csv", ios::in);

	fout.open("studentnew.csv", ios::out);

	int ID, ID1, count = 0, i;
	int index;
	string line, word;
	vector<string> row;

	cout << "Enter the ID "
		<< "of the record to be deleted: ";
	cin >>ID;

	while (!fin.eof()) {

		row.clear();
		getline(fin, line);
		stringstream s(line);

		while (getline(s, word, ',')) {
			row.push_back(word);
		}

		int row_size = row.size();
		ID1 = stoi(row[1]);

		if (ID1 != ID) {
			if (!fin.eof()) {
				for (i = 0; i < row_size - 1; i++) {
					fout << row[i] << ", ";
				}
				fout << row[row_size - 1] << "\n";
			}
		}
		else {
			count = 1;
		}
		if (fin.eof())
			break;
	}
	if (count == 1)
		cout << "Record deleted\n";
	else
		cout << "Record not found\n";

	fin.close();
	fout.close();

	remove("student.csv");

	rename("studentnew.csv", "student.csv");
	Option();
}

void Option(){
        int k;
        
        cout << "   PRESS 1 : Menu " << endl;
        cout << "   PRESS 2 : Exit " << endl;
        cin >> k;
        switch (k)
        {
        case 1:
          For_student();
          break;
        case 2:
          return;
          break;
        default:
          cout << "You entered wrong number" << endl;
          Option();        
          break;
        }
    }

void For_student()
{
	cout<<" 1 : Create a Student profile "<<endl;
	cout<<" 2 : Read the Student Record  "<<endl;
	cout<<" 3 : update Student Record "<<endl;
	cout<<" 4 : Delete Student Record "<<endl;
	cout<<endl;
	int k;
	cout<<" Enter the option : ";
	cin>>k;
	cout<<endl;
	switch(k)
	{
		case 1:
		 create();
          break;

		 case 2:
		 read_record();
		  break;
		  
		 case 3:
		 update_recode();
		  break;
		  
         case 4:
		 delete_record();
		  break;

		  default:
		  cout<<"Plz choice correct option :";
		  break;
	}
}

};


int main()
{
	Student A;
	A.For_student();
	return 0;   
}