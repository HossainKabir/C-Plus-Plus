#include <iostream>
#include <string>
#include <fstream>

#define SIZE 5

using namespace std;

class studentinfo{
private:
	string Sname, Fname, Mname, HD, SCUname, Depet, GCno, Hid;
	int Rno;
	float cgpa;
public:
	studentinfo();
	~studentinfo();
	void setSN(string s);
	void setFN(string f);
	void setMN(string m);
	void setHD(string hd);
	void setSCUn(string scu);
	void setDEPT(string d);
	void setGCno(string gc);
	void setHID(string id);
	void setROOMno(int r);
	void setCGPA(float c);


	string getSN();
	string getFN();
	string getMN();
	string getHD();
	string getSCUn();
	string getDEPT();
	string getGCno();
	string getHID();
	int    getROOMno();
	float  getCGPA();
	void   performance();
	void   Show();

};


studentinfo::studentinfo() {}
studentinfo :: ~studentinfo() {}


void studentinfo::setSN(string s){ Sname = s; }
void studentinfo::setFN(string f){ Fname = f; }
void studentinfo::setMN(string m){ Mname = m; }
void studentinfo::setHD(string hd){ HD = hd; }
void studentinfo::setSCUn(string scu){ SCUname = scu; }
void studentinfo::setDEPT(string d){ Depet = d; }
void studentinfo::setGCno(string gc){ GCno = gc; }
void studentinfo::setHID(string id){ Hid = id; }
void studentinfo::setROOMno(int r){ Rno = r; }
void studentinfo::setCGPA(float c){cgpa=c;}


string studentinfo::getSN(){ return Sname; }
string studentinfo::getFN(){ return Fname; }
string studentinfo::getMN(){ return Mname; }
string studentinfo::getHD(){ return HD; }
string studentinfo::getSCUn(){ return SCUname; }
string studentinfo::getDEPT(){ return Depet; }
string studentinfo::getGCno(){ return GCno; }
string studentinfo::getHID(){ return Hid; }
int    studentinfo::getROOMno(){ return Rno; }
float  studentinfo::getCGPA() {return cgpa;}


void studentinfo::Show(){
	cout << " Student Name :" << getSN() << endl;
	cout << " Student's Father Name :" << getFN() << endl;
	cout << " Student's Mother Name :" << getMN() << endl;
	cout << " Student's Home District Name :" << getHD() << endl;
	cout << " Student's School/College/University Name :" << getSCUn() << endl;
	cout << " Student's Department Name :" << getDEPT() << endl;
	cout << " Student's Guardian contact Number :" << getGCno() << endl;
	cout << " Student's Hostel ID :" << getHID() << endl;
	cout << " Student's Room NO :" << getROOMno() << endl;
}

void studentinfo :: performance(){
   cout << "student's Name :"<<getSN()<<endl;
   cout << " Student's School/College/University Name :" << getSCUn() << endl;
   cout << " Student's Department Name :" << getDEPT() << endl;
   cout << "Student's GPA/CGPA :"<<getCGPA()<<"\n\n"<<endl;
}


class studentDB{
private:
	studentinfo s[SIZE];
	int top;
public:
	studentDB();
	~studentDB();
	int search1(string n);
	int search2(string m);
	void AdmitStudent();
	void SearchStudent();
	void AboutHostel();
	void InternalSystem();
	void Controler();
	int emptyroom();
};



studentDB::studentDB(){ top = 0; }
studentDB :: ~studentDB(){}
int studentDB::search1(string n){
	for (int i = 0; i<top; i++){
		if (s[i].getHID() == n) return i;
	}
	return -1;
}

int studentDB::search2(string m){
	for (int i = 0; i<top; i++){
		if (s[i].getSN() == m)return i;
	}
	return -1;
}

int studentDB::emptyroom(){
	int i;
		if (top==SIZE){
			cout << "Full...no empty  room found..\n\n" << endl;
		}
		else{
			 i = SIZE - top;
			cout << "Number of empty room:\t" <<i<< endl;
		}
		return i;
}

void studentDB :: AdmitStudent(){

		cout <<"Before admit a student please chack room capacity.\n\n"<<endl;

		cout <<"press 1: for search room capacity."<<endl;
		cout <<"press 2: for ignore Search. \n\n"<<endl;
		int c;
		cin >>c;
		switch (c){
		case 1:
			emptyroom();

        {if (top==SIZE){
          cout <<" /n/nSorry , No seat capacity available in our hostel."<<endl;
          cout <<" Please contact with us after a month…..!"<<endl;
         }
	else
	{
      cout <<"Please enter student's full information\n\n"<<endl;
	  string S;string F;string M;string H;string SC;string D;string GC;string j;
		int r;
		float c;
		cout <<"Enter student Name :";
		cin >>S;
		cout <<"Enter student's Father Name :";
		cin >>F;
		cout <<"Enter student's Mother Name :";
		cin >>M;
		cout <<"Enter student's Home District Name :";
		cin >>H;
		cout <<"Enter student's School/College/University Name :";
		cin >>SC;
		cout <<"Enter student's Department Name :";
		cin >>D;
		cout <<"Enter student's Guardian contact Number :";
		cin >>GC;
		cout <<"Enter student's Hostel ID :";
		cin >>j;
		cout <<"Enter student's Room NO :";
		cin >>r;
		cout <<"Enter Student GPA/CGPA :";
        cin >>c;
		s[top].setSN(S);
		s[top].setFN(F);
		s[top].setMN(M);
		s[top].setHD(H);
		s[top].setSCUn(SC);
		s[top].setDEPT(D);
		s[top].setGCno(GC);
		s[top].setHID(j);
		s[top].setROOMno(r);
		s[top].setCGPA(c);
		top++;
	   }
	}
            break;
        case 2:
            break;
		default:
		    cout <<"Wrong number press."<<endl;
			break;
		}


    }
void studentDB::AboutHostel(){
	   string s;
  ifstream ifile ("Final hostel facilities.txt");
  if (ifile.is_open())
  {
    while ( getline (ifile,s) )
    {
      cout << s << '\n';
    }
    ifile.close();
  }

  else cout << "Unable to open file"<<endl;
}

void studentDB::SearchStudent(){
	cout << "\tpress 1: for room search.\n" << endl;
	cout << "\tpress 2: for student info search.\n" << endl;
	cout << "\tpress 3: for ignore search.\n" << endl;

	int x;
	cin >> x;
	switch (x){
	case 1:
		{
			string id;
			cout << "Enter Hostel ID to know room no :";
			cin >> id;
			int a = search1(id);
			if (a > -1){
				cout << "This student staying in .." << s[a].getROOMno() << ".. NO room." << endl;
			}
			else
				cout << id << " .. Did not found with any hostel id.\n\n" << endl;

		}
		break;
	case 2:
	{
            string sn;
			cout << "Enter student name to see all information :";
			cin >> sn;
			int b = search2(sn);
			if (b > -1){
				s[b].Show();
			}
			else
				cout << sn << "..  Did not match with any student name." << endl;
		}
		break;
	case 3:
		break;
	default:
		cout << "Wrong number press.\n\n" << endl;

	}

}
void studentDB::InternalSystem(){
    cout << "Press 1: to see all Student's Academic Performance.\n"<<endl;
	cout << "press 2: to delete a student's information.\n" << endl;
	int x;
	cin >> x;
	switch (x){
	    	case 1:
	    for (int i=0;i<top;i++){
            s[i].performance();
	    }
	     break;
	case 2:
		cout << "Enter student's id:" << endl;
		string id;
		cin >> id;
		 int i = search1(id);
		if (i > -1){
			for (int j = 0; j < top; j++)
				s[j] = s[j + 1];
				cout << "Information of.. " << s[i].getSN() << "..is deleted from history." << endl;
		}
			else{
                cout <<"Did't found this:.. "<<id<<" ..ID no."<<endl;
			}
			break;
           }
        }

void studentDB::Controler(){

    cout <<"\t\tWELCOME\n"<<endl;
    cout <<"\tHostel Management System\n\n"<<endl;
	char ch = '\0';
	while (ch != 'n' && ch != 'N'){

		int c;
		cout << "\tpress 1 for Admit a student.\n" << endl;
		cout << "\tpress 2 for search student info.\n" << endl;
		cout << "\tpress 3 for About Hostel.\n" << endl;
		cout << "\tpress 4 for Internal System.\n" << endl;
		cout << "\tpress 5 for exit.\n" << endl;

		cin >> c;

		switch (c){
		case 1:
			AdmitStudent();
			break;

		case 2:
			SearchStudent();
			break;

		case 3:
			AboutHostel();
			break;

		case 4:
			InternalSystem();
			break;
        case 5:
            break;

		default:
			cout << "Wrong number pressed." << endl;
			break;
		}
		cout <<"\n\n\t\tpress n: to exit "<<endl;
		cout <<"\t\tpress c: to continue program" << endl;
		cin >> ch;
	}
}




int main()
{
	studentDB *p;
	p = new studentDB[SIZE];
	p-> Controler();

	return 0;
}

