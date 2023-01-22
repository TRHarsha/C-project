#include <iostream>
#include <string>
using namespace std;

int main() {
    string symptoms[10];
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
        cout << "- COVID-19" << endl;
    } else if (symptoms[0] == "headache" && symptoms[1] == "nausea" && symptoms[2] == "vomiting") {
        cout << "- Migraine" << endl;
    } else if (symptoms[0] == "abdominal pain" && symptoms[1] == "diarrhea" && symptoms[2] == "fever") {
        cout << "- Gastroenteritis" << endl;
    } else {
        cout << "Sorry, there are no common diseases associated with your symptoms." << endl;
    }
    return 0;
}
