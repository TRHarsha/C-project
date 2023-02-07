#include <iostream>
#include<iomanip>
#include <string>
#include<stdio.h>
#include<ctime>
#include<sstream>
#include <cstdlib>

using namespace std;

struct patient{
	string name,blood_group,mobile_no;
	int age,adhar;
	struct medical_report;	
}details[20];

struct medical_report{
	string con_doc,spc,ap_date,ap_mdate;
}report[20];


string cart_name[20],specialisation;;
char buf[80];
int a=0,j,i,n,auth,m,total,u,q;
float amt,cart_price[20],cart_qty[20];

	
string tablet_list[20]={"Atenolol","Levothyroxine","Cetirizine","Pantoprazole","Lansoprazole","Metformin","Amoxicillin","Diclofenac","Ibuprofen","Paracetamol"};
float tablet_price[20]={2.85,35,1,0.94,3,1.75,7,1.73,2,1.84};

string syrup_list[20]={"Paracetamol","Dextromethorphan","Chlorpheniramine Maleate","Ambroxol","Cetirizine","Montelukast","Domperidone","Metronidazole","Azithromycin","Cefixime"};
float syrup_price[20]={38.30,89.50,70.00,85.90,88.00,128.00,125.00,17.32,120.00,85.90};

string dermatologist[20]={"Dr. Prithvi Raj K A","Dr L Seetharam","Sahyadri Skin Clinic","Vaani Clinic"};
string cardiologist[]={"Dr.Mahesh Murthy"," Malnad Heart care", "CATH LAB"};
string neurologist[]={"Dr Satvik P G,Bharat Neuro Clinic"," Dheemahi Child Neurology & Development Center","Chitta Manasika And Nara Roga Aspathri"};
string oncologist[]={"Dr. Prashanth Shivappa","Malnad Cancer Hospital","N.S. Vidya Narayanmurthy Shimoga Cancer Medicine","Dr Aparna Sreevatsa"};
string orthopedist[]={"Aradhana Orthopaedic Center","Malnad Orthopaedic Centre","Punam Orthopaedic and Fracture Clinic","Bhagyaram Orthopaedic Center","Ashoka Sanjeevini Hospital"};
string pediatrician[]={"Dr. Dhananjaya Sarji","Chirayush Children'S Hospital","Dr. Gopalakrishna Shanbhag","Sarji Hospital"};


int main();
void new_patient(int i);
void search_patient(string phone_number,int i);
void edit_opt(int m);
void delete_info(int m);
void print_all(int total);
void simple_check();
void print_med();
void record_date(int q);
void appointment();
void gen_prep(int q);

void new_patient(int i){
	string number;
	cout<<"You are patient number: "<<i<<endl;
	cout<<"Enter your mobile number: ";
	cin>>details[a].mobile_no;
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
	int found=0;
	for (j=0;j<i;j++)
	{
		if (phone_number==details[j].mobile_no)
		{
			found=1;
			cout<<"\nPATIENT DETAILS"<<endl;
			cout<<details[j].name<<endl;
			cout<<details[j].blood_group<<endl;
			cout<<details[j].age<<endl;
			m=j;
			break;
		}
	}

	if (found==1)
	{
		cout<<"Do you want to -edit- or -delete- or Fix an -appointment-"<<endl;
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
	else if(found==0)
	{
		cout<<"\n NEW PATIENT REGISTER \n"<<endl;
		++a;
		new_patient(a);
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

void print_med()
{
	cout<<"\t_______________________________________________________________________________"<<endl;
	cout<<"\t|  	           TABLETS		 |	            SYRUP   		|"<<endl;
	cout<<"\t|   GENERIC NAME     | Price per unit    |   GENERIC NAME     | Price per 100ml |"<<endl;
	cout<<"\t_______________________________________________________________________________"<<endl;
		for (j=0;j<10;j++)
		{
			cout<<"\t"<<tablet_list[j]<<"\t\t   "<<tablet_price[j]<<"\t\t "<<syrup_list[j]<<" 			"<<syrup_price[j]<<endl;
		}
		cout<<"\t___________________________________________________________________________\n"<<endl;
}

void medical_store()
{
	string drug_type,drug_name,ans;
	int qty,found=0;
	print_med();
	cout<<"Do you want to buy TABLETS or SYRUP"<<endl;
	cout<<"type DONE once you have added "<<endl;
	cin>>drug_type;
	if(drug_type=="TABLETS")
	{
		cout<<"\t Tablet Name: ";
		cin>>drug_name;
		for(i=0;i<=10;i++)
		{
			if(tablet_list[i]==drug_name)
			{
			found=1;
			cout<<"\t Rs/unit:"<<tablet_price[i]<<"\t Qty:";
			cin>>qty;
			cout<<"\t Price:"<<qty*tablet_price[i]<<endl;
			amt=amt+(qty*tablet_price[i]);
			cart_name[u]=drug_name;
			cart_price[u]=tablet_price[i];
			cart_qty[u]=qty;
			u=u+1;
			cout<<"Items in cart: "<<u<<endl;
			cout<<"Do you want to checkout: ";
			cin>>ans;
			if (ans=="yes")
			{
				cout<<"\n"<<endl;
				for(i=0;i<u;i++)
				{
				cout<<cart_name[i]<<"\t"<<cart_price[i]<<"\t"<<cart_qty[i]<<"\t"<<float(cart_qty[i]*cart_price[i])<<endl;
				}
				cout<<"_________________________________________________________________________________________"<<endl;
				cout<<"BILL AMOUNT:                                     Rs."<<amt<<endl;
				cout<<"18% GST APPLIED                                  Rs."<<float (0.18*amt)<<endl;
				cout<<"TOTAL AMOUNT(INCLUDING TAX):                     Rs."<<float (amt+(0.18*amt))<<endl;
				cout<<"ROUND OFF AMOUNT                                 Rs."<<int (amt+(0.18*amt))<<endl;
				cout<<"_________________________________________________________________________________________"<<endl;
				cout<<"PROCEED TO PAYMENT \n"<<endl;
			break;
			}
			else
			{
			medical_store();
			}
			}
		}
		if(found==0)
		{
			cout<<"<<<<<<<<<<<<<<< NOT FOUND >>>>>>>>>>>>>>>>>>>"<<endl;
			medical_store();
		}
	}
	else if(drug_type=="SYRUP")
	{
		cout<<"\t Syrup Name: ";
		cin>>drug_name;
		for(i=0;i<10;i++)
		{
			if(syrup_list[i]==drug_name)
			{
			found=1;
			cout<<"\t Rs/unit:"<<syrup_price[i]<<"\t Qty:";
			cin>>qty;
			cout<<"\t"<<qty*syrup_price[i];
			amt=amt+(qty*syrup_price[i]);
			cart_name[u]=drug_name;
			cart_price[u]=syrup_price[i];
			cart_qty[u]=qty;
			u=u+1;
			cout<<"\nItems in cart: "<<u<<endl;
			cout<<"Do you want to checkout: ";
			cin>>ans;
			
			if (ans=="yes")
			{
				cout<<"\n"<<endl;
				for(i=0;i<u;i++)
				{
				cout<<cart_name[i]<<"\t"<<cart_price[i]<<"\t"<<cart_qty[i]<<"\t"<<cart_qty[i]*cart_price[i]<<endl;
				}
				cout<<"_________________________________________________________________________________________"<<endl;
				cout<<"BILL AMOUNT:                                     Rs."<<amt<<endl;
				cout<<"18% GST APPLIED                                  Rs."<<float (0.18*amt)<<endl;
				cout<<"TOTAL AMOUNT(INCLUDING TAX):                     Rs."<<float (amt+(0.18*amt))<<endl;
				cout<<"ROUND OFF AMOUNT                                 Rs."<<int (amt+(0.18*amt))<<endl;
				cout<<"_________________________________________________________________________________________"<<endl;
				cout<<"PROCEED TO PAYMENT\n"<<endl;
			}
			else
			{
			medical_store();
			}
			}
		}
		if(found==0)
		{
			cout<<"<<<<<<<<<<<<<<< NOT FOUND >>>>>>>>>>>>>>>>>>>/n"<<endl;
			medical_store();
		}
	}
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

void record_date(int q)
{
	
	time_t now = time(0);
	tm now_tm = *localtime(&now);
	
	strftime(buf, sizeof(buf), "%d-%m-%Y", &now_tm);
	report[q].ap_mdate=buf;	
}

void appointment()
{
	int select,token;
	string reply;
	cout<<"1.Fix new appointment \n 2.Check an appointment\n"<<endl;
	cin>>select;
	switch(select)
	{
		case 1:	cout<<"Enter patient id: ";
				cin>>q;
				cout<<details[q].name<<"\t"<<details[q].blood_group<<"\t"<<details[q].age<<endl;
				cout<<"Enter the specialisation of the doctor: ";
				cin>>report[q].spc;
				specialisation=report[q].spc;
			if (specialisation == "dermatologist")
			{
    			srand(time(NULL));
    			int randomIndex = rand() % 4;
    			cout << dermatologist[randomIndex] << endl;
    			report[q].con_doc=dermatologist[randomIndex];
			}
			else if (specialisation == "cardiologist")
			{
    			srand(time(NULL));
    			int randomIndex = rand() % 3;
    			cout << cardiologist[randomIndex] << endl;
    			report[q].con_doc=cardiologist[randomIndex];
    			break;
			}
			else if (specialisation == "neurologist")
			{
			    srand(time(NULL));
    			int randomIndex = rand() % 3;
    			cout << neurologist[randomIndex] << endl;
    			report[q].con_doc=neurologist[randomIndex];
			}
			else if (specialisation == "oncologist")
			{
    			srand(time(NULL));
    			int randomIndex = rand() % 4;
    			cout << oncologist[randomIndex] << endl;
    			report[q].con_doc=oncologist[randomIndex];
			}
			else if (specialisation == "orthopedist")
			{
    			srand(time(NULL));
    			int randomIndex = rand() % 5;
    			cout << orthopedist[randomIndex] << endl;
    			report[q].con_doc=orthopedist[randomIndex];
			}
			else if (specialisation == "pediatrician")
			{
			    srand(time(NULL));
			    int randomIndex = rand() % 4;
    			cout << pediatrician[randomIndex] << endl;
    			report[q].con_doc=pediatrician[randomIndex];
			}
			else
			{
    			cout << "Invalid specialisation entered." << endl;
    			break;
			}
			cout<<"Do you want us to make an Appointment"<<endl;
			cin>>reply;
			if(reply=="yes")
			{
				cout<<"Confirming your APPOINTMENT"<<endl;
				cout<<"Enter the date of Appointment [dd-mm-yyyy format]: ";
				cin>>report[q].ap_date;	
				record_date(q);
				break;
			}
			else
			break;
	case 2: cout<<"Enter patient id: ";
			cin>>q;
			cout<<details[q].name<<"\t"<<details[q].blood_group<<"\t"<<details[q].age<<endl;
			if(report[q].ap_date==report[q].ap_mdate)
			{
				token=token+1;
				cout<<"YOUR TOKEN NO. "<<token<<"\n"<<endl;
				break;
			}
			else
			{
				cout<<"YOU HAVE NO APPOINTMATE FOR TODAY\n"<<endl;
				break;
			}
	}
}

void gen_prep(int q)
{
	cout<<"Hello "<<details[q].	name<<","<<endl;
	cout<<"      "<<details[q].mobile_no<<","<<endl;
	cout<<" Age: "<<details[q].age<<endl<<"Blood Group: "<<details[q].blood_group<<"\n"<<endl;
	cout<<"Your MEDICAL REPORT is "<<endl;
	cout<<"Consult Doctor:     "<<report[q].con_doc<<endl;
	specialisation=report[q].spc; 
	cout<<"Specialization:     "<<specialisation<<"\n"<<endl;
	cout<<"Appointment date:   "<<report[q].ap_date<<endl;
	cout<<"Appointment made on:"<<report[q].ap_mdate<<endl;
	cout<<"\n Prescription \n"<<endl;
	if (specialisation == "cardiologist") {
        cout << "Prescribe daily dose of aspirin." << endl;
        cout << "Refer to an echocardiogram." << endl;
    }
	else if (specialisation == "dermatologist") {
        cout << "Prescribe a topical ointment." << endl;
        cout << "Advise to avoid excessive sun exposure." << endl;
    }
	else if (specialisation == "neurologist") {
        cout << "Prescribe a daily dose of anti-seizure medication." << endl;
        cout << "Refer for an MRI." << endl;
    }
	else if (specialisation == "oncologist") {
        cout << "Prescribe a course of chemotherapy." << endl;
        cout << "Refer for radiation therapy." << endl;
    }
	else if (specialisation == "orthopedist") {
        cout << "Prescribe physical therapy sessions." << endl;
        cout << "Refer for an X-ray." << endl;
    }
	else if (specialisation == "pediatrician") {
        cout << "Prescribe a daily dose of pediatric multivitamins." << endl;
        cout << "Advise on maintaining a balanced diet." << endl;
    }
    
    cout<<"\nClick -ENTER- to verify your PRESCRIPTION"<<endl;
    	string str;
    	while(1){
		getline(cin,str);
		if(str ==" ")
		{
    	cout<<"______________________________"<<endl;
    	cout<<"| THANK YOU FOR VERIFYING :) |"<<endl;
    	cout<<"``````````````````````````````"<<endl;
    	exit(0);
		}
	}
	
}

int main(){
	string phone_number;
	int choice;
	for(;;)
	{
		cout<<"\nEnter the choice\n"<<endl<<"1.Simple Check"<<endl<<"2. New Patient"<<endl<<"3. Search Phone Number"<<endl<<"4.Print All Patient List"<<endl<<"5.Appointment Related"<<endl<<"6. Purchase Medicine Online"<<endl<<"7. Prescription "<<endl<<"9.exit\n"<<endl;
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
			case 5: cout<<"\n APPOINTMENTS \n "<<endl;
					appointment();
					break;
			case 6: cout<<"\n WELCOME TO MEDICAL STORE\n"<<endl;
					medical_store();
					break;
			case 7: cin>>q;
					gen_prep(q);
					break;
			case 9: cout<<"Thank You for visiting"<<endl;
					exit(0);
					break;
			default: cout<<"Enter valid choice"<<endl;			
		} 
	}
}
