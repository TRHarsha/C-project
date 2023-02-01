#include <iostream>
#include<iomanip>
#include <string>
#include<stdio.h>

using namespace std;

struct patient{
	string name,blood_group,mobile_no;
	int age,adhar;
	struct medical_report;	
}details[20];

struct medical_report{
	string rep22,rep21,rep20;
};

int a=0,j,i,n,auth,m,total;

void new_patient(int i);
void search_patient(string phone_number,int i);
void edit_opt(int m);
void delete_info(int m);
void print_all(int total);
void simple_check();

void new_patient(int i){
	string number;
	cout<<"You are patient number: "<<i<<endl;
	cout<<"Enter your mobile number: ";
	cin>>details[i].mobile_no;
	cout<<"Enter your Name: ";
	cin>>details[a].name;
	cout<<"Enter your blood group ";
	cin>>details[a].blood_group;
	cout<<"Enter your age: ";
	cin>>details[a].age;
	cout<<"\n We will take last 4 digit of your Adhaar for safety reasons: ";
	cin>>details[a].adhar; 
	}

void search_patient(string phone_number,int i)
{
	string opt;
	for (j=0;j<i;j++)
	{
	if (phone_number==details[j].mobile_no)
	{
		cout<<"\nPATIENT DETAILS"<<endl;
		cout<<details[j].name<<endl;
		cout<<details[j].blood_group<<endl;
		cout<<details[j].age<<endl;
		m=j;
	}
	}
	cout<<"\n This is what we found in our Data Base\n";
	cout<<"Do you want to -edit- or -delete-"<<endl;
	cin>>opt;
	if(opt=="edit")
	{
	edit_opt(m);
	}
	else if(opt=="delete")
	{
	delete_info(m);
	}
}

void edit_opt(int m)
{
	int uopt;
	cout<<"Please provide us your ID proof(last 4 digit of Adhaar) to confirm your Patient ID: "<<m<<endl;
	cin>>auth;
	if(details[m].adhar==auth)
	{
	cout<<"\nTHANK YOU FOR CONFIRMATION\n"<<endl;
	cout<<"Choose which one do you want to edit \n1.Name\n2.Blood Group\n3.age\n"<<endl;
	cin>>uopt;
	switch(uopt)
	{
		case 1: cout<<"Name: ";
				cin>>details[m].name;
				break;
		case 2: cout<<"Blood Group: ";
				cin>>details[m].blood_group;
				break;
		case 3: cout<<"Age: ";
				cin>>details[m].age; 
				break;
	}
	}
	else
		cout<<"WRONG ID: PLEASE PROVIDE YOUR CORRECT ID PROOF";
}

void delete_info(int m)
{
	int k;
	cout<<"Please provide us your ID proof(last 4 digit of Adhaar) to confirm your Patient ID: "<<m<<endl;
	cin>>auth;
	if(details[m].adhar==auth)
		{
		cout<<"\nTHANK YOU FOR CONFIRMATION\n"<<endl;
		while(k<=total)
		{
			details[m].mobile_no=details[m+1].mobile_no;
			details[m].name=details[m+1].name;
			details[m].blood_group=details[m+1].blood_group;
			details[m].age=details[m+1].age;
			details[m].adhar=details[m+1].adhar;
			k++;
		}
		cout<<"\n Deleted Successfully\n"<<endl;
		total=total-1;
		a=a-1;
		}
		else
		cout<<"WRONG ID: PLEASE PROVIDE YOUR CORRECT ID PROOF";
}
void print_all(int total)
{
		cout<<"\t|ID.NO |       NAME     |"<<"\t"<<"Blood Group  |"<<"\t"<<"  AGE  |"<<endl;
		cout<<"\t________________________________________________________"<<endl;
		for (j=1;j<=total;j++)
		{
			cout<<"\t|"<<j<<"\t\t"<<details[j].name<<"\t\t"<<details[j].blood_group<<"\t\t"<<details[j].age<<"     |"<<endl;
		}
		cout<<"\t________________________________________________________\n"<<endl;
}
void simple_check() {
    string symptoms[10],home_remedies,reply,common_disease;
    int symptomCount = 0;


    cout << "Please enter your symptoms (up to 3):" << endl;
    cout << "1. fever \n2. cough\n3. shortness of breath\n4.headache\n5.nausea\n6.vomiting\n7.abdominal pain\n8.diarrhea\n9.fever\n" << endl;
        cout<<"1: ";
		cin>>symptoms[0];
		symptomCount = 1;
		cout<<"2: ";
        cin>>symptoms[1];
        symptomCount = 2;
		cout<<"3: ";
        cin>>symptoms[2];
        symptomCount = 3;
        
    cout << "Possible diseases based on your symptoms:" << endl;
    if (symptomCount == 0) {
        cout << "No symptoms entered, unable to provide suggestions." << endl;
    } else if (symptoms[0] == "fever" && symptoms[1] == "cough" && symptoms[2] == "shortness of breath") {
        cout << "Asthma \nAsthma is a condition in which your airways narrow and swell and may produce extra mucus." << endl;
        common_disease="Asthma";
    } else if (symptoms[0] == "headache" && symptoms[1] == "nausea" && symptoms[2] == "vomiting") {
        cout << "- Migraine\n A migraine is a headache that can cause severe throbbing pain or a pulsing sensation, usually on one side of the head." << endl;
        common_disease="Migraine";
    } else if (symptoms[0] == "abdominal pain" && symptoms[1] == "diarrhea" && symptoms[2] == "fever") {
        cout << "- Gastroenteritis \nViral gastroenteritis is an intestinal infection that includes signs and symptoms such as watery diarrhea, stomach cramps, nausea or vomiting, and sometimes fever." << endl;
        common_disease="Gastroenteritis";
    } else {
        cout << "Sorry, there are no common diseases associated with your symptoms.\n\n\n" << endl;
    }
    cout<<"Do you want us to suggest some home remedies?\n"<<endl;
    cin>>reply;
    if(reply=="yes")
    {
        if(common_disease== "Gastroenteritis")
        {
            cout<<"\ndrink plenty of fluids to avoid dehydration;\n you need to drink more than usual to replace the fluids lost from vomiting and diarrhoea ? water is best,\n"<<endl;
            cout<<"but you could also try fruit juice and soup.\n take paracetamol for any fever or aches and pains.get plenty of rest.\n"<<endl;
        }
        else if(common_disease== "Migraine")
        {
            cout<<"\nScalp Massages. Applying pressure to muscles can help with relieving tension and stress, which are common migraine triggers."<<endl;
            cout<<"Sleep. Too much or too little sleep can cause migraine attacks\n"<<endl;
        }
        else if(common_disease=="Asthma")
        {
            cout<<"\nCaffeinated tea or coffee. The caffeine in black or green tea and coffee is believed to help treat asthma."<<endl;
            cout<<"Eucalyptus essential oil. According to a 2013 research review, essential oils have anti-inflammatory properties that may help treat asthma.\n"<<endl;
        }
    }
    else
        cout<<"thank you"<<endl;
}

int main(){
	string phone_number;
	int choice;
	for(;;)
	{
		cout<<"\nEnter the choice\n"<<endl<<"1.Simple Check"<<endl<<"2. New Patient"<<endl<<"3. Search Phone Number"<<endl<<"4.Print All Patient List"<<endl<<"9.exit\n"<<endl;
		cin>>choice;
		switch (choice)
		{
			case 1: simple_check();
					break;
			case 2: ++a;
					new_patient(a);
					total=a;
            		break;
            case 3: i=a+1;
            		cout<<"Mobile Number: ";
					cin>>details[i].mobile_no;
					phone_number=details[i].mobile_no;
					search_patient(phone_number,i);
					break;
			case 4: cout<<"\n COMPLETE PATIENT DETAILS\n "<<endl;
					print_all(total);
					break;
			case 9: cout<<"Thank You for visiting"<<endl;
					exit(0);
					break;
			default: cout<<"Enter valid choice"<<endl;			
		} 
	}
}
