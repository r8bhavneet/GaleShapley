#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <random> 
using namespace std;

#define N 5


void galeShapley(map<char, vector<char>>& hospitalPrefs, 
                 map<char, vector<char>>& medStudentPrefs){

    map<char, char> medStudentMatch;  
    
    queue<char> freeHospitals;
    for(auto& hospital : hospitalPrefs){
        freeHospitals.push(hospital.first);
    }

    map<char,int> nextProposal;
    for(auto& hospital : hospitalPrefs){
        nextProposal[hospital.first] = 0;
    }

    while (!freeHospitals.empty()) {
        char hospital = freeHospitals.front();
        freeHospitals.pop();

        char medStudent = hospitalPrefs[hospital][nextProposal[hospital]];
        nextProposal[hospital]++;

        if (medStudentMatch.find(medStudent) == medStudentMatch.end()) {
            medStudentMatch[medStudent] = hospital;
        }else{
            char currentHospital = medStudentMatch[medStudent];

            auto& prefs = medStudentPrefs[medStudent];
            if (find(prefs.begin(), prefs.end(), hospital) < find(prefs.begin(), prefs.end(), currentHospital)) {
                medStudentMatch[medStudent] = hospital;
                freeHospitals.push(currentHospital);
            } else{
                freeHospitals.push(hospital);
            }
        }
    }

    for (auto& match : medStudentMatch) {
        cout << "Med student " << match.first << " is matched with hospital " << match.second << endl;
    }

}


int main() {
    
    vector<char> medStudents = {'W', 'X', 'Y', 'Z', 'V'}; 
    map<char, vector<char>> hospitalPrefs;
    
    random_device rd; 
    mt19937 g(rd());

    for (char hospital = 'A'; hospital <= 'E'; ++hospital) {
        vector<char> shuffledMedStudents = medStudents; 
        shuffle(shuffledMedStudents.begin(), shuffledMedStudents.end(), g); 
        
        hospitalPrefs[hospital] = shuffledMedStudents; 
    }

    vector<char> hospitals = {'A', 'B', 'C', 'D', 'E'};
    map<char, vector<char>> medStudentPrefs;

    for (char medStudent = 'W'; medStudent <= 'V'; ++medStudent) {
        vector<char> shuffledHospitals = hospitals; 
        shuffle(shuffledHospitals.begin(), shuffledHospitals.end(), g); 
        
        hospitalPrefs[medStudent] = shuffledHospitals; 
    }
    galeShapley(hospitalPrefs, medStudentPrefs);

    return 0;
}
