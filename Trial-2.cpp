#include <iostream>
#include<iomanip>
#include <string>
using namespace std;

int main() {
    string symptoms[10],home_remedies,reply,common_disease;
    int symptomCount = 0;


    cout << "Please enter your symptoms (up to 3, type 'done' when finished):" << endl;
    cout << "1. fever \n2. cough\n3. shortness of breath\n4.headache\n5.nausea\n6.vomiting\n7.abdominal pain\n8.diarrhea\n9.fever" << endl;
    for (int i = 0; i < 10; i++) {
        cout << i+1 << ": ";
        getline(cin, symptoms[i]);
        if (symptoms[i] == "done") {
            break;
        }
        symptomCount++;
    }

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
            cout<<"\ndrink plenty of fluids to avoid dehydration;\n you need to drink more than usual to replace the fluids lost from vomiting and diarrhoea – water is best,\n"<<endl;
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
    return 0;
}
