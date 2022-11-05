#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double  

int numofcontri = 3;
vector<pair<string,int>> contri[3];
vector<pair<string,int>> projectskills [10];
int proj_bbfore[10];
int proj_days[10];
int numofproject= 3;
map<string,int> skillmap;
int counterskill ;
bool optimised[3][3][3][10];
int tot;

void contributorInput(){
    
    cin >> numofcontri;
    int i;
    for(i =0 ; i < numofcontri ; i++){
        int nskills;
        cin >> nskills;

        int j;
        for(j = 0 ; j < nskills;j++){
            string skillname;
            int skillevel;
            cin >> skillname >> skillevel;
            contri[i].push_back({skillname,skillevel});
            if(skillmap.count(skillname) == 0)
            { 
               skillmap[skillname] = counterskill;
              counterskill++;
            }
        }

    }
}

void projectInput(){
    
    cin >> numofproject;
    int i;
    for(i =0 ;i < numofproject;i++){
         cin >> proj_days[i] >> proj_bbfore[i];
         int skills;
         cin >> skills;
         int j;
         for(j =0 ; j < skills;j++){
            string skillname;
            int skillevel;
            cin >> skillname >> skillevel;
            projectskills[i].push_back({skillname,skillevel});
            if(skillmap.count(skillname) == 0)
            { 
               skillmap[skillname] = counterskill;
              counterskill++;
            }
         }
    }

}

int counter ;
void generaterandommatrix(){
    bool arr[tot];
    int i;
    int num = counter;
    
    for(i = 0 ; i < tot;i++){
        arr[i] = num & 1;
        num = num >> 1;
    }

    for(i =0 ; i < tot;i++){
        cout << arr[i] ;
    }
    cout << endl;
}

int main(){
   

    int i;
    counterskill = 0;

    // contributorInput();
    // projectInput();
    int time = 10 ;
    int skillsnum = skillmap.size();
     tot = numofcontri + numofproject + skillsnum + time ;
    counter = 0;
    for(counter = 0 ; counter < pow(2,tot) ;counter++){
        generaterandommatrix();
    }

    

}

 