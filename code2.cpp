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
// map<string,int> skillmap;
int counterskill ;
bool optimised[3][3][3][10];
int tot;
vector<pair<int,int>> contributor[5];
int digit[7];
long int id=0;
map<int,vector<pair<int,int>>> skillmap;
void contributorInput(){
    
    cin >> numofcontri;
    int i;
    for(i =0 ; i < numofcontri ; i++){
        int nskills;
        cin >> nskills;                                                     
        int j;
        for(j = 0 ; j < nskills;j++){
            int skillcode, skilllevel;
            cin >> skillcode >> skilllevel; 
            contributor[i].push_back({skillcode,skilllevel});
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
            int skillcode;
            int skillevel;
            cin >> skillcode >> skillevel;
        //     projectskills[i].push_back({skillname,skillevel});
        //     if(skillmap.count(skillname) == 0)
        //     { 
        //        skillmap[skillname] = counterskill;
        //       counterskill++;
        //     }
        //  }
         }
    }

}



int main(){
    counterskill = 0;

    // contributorInput();
    // projectInput();
    int i , j;
    random_device rd;
    mt19937 g(rd());
    int vp100[10000][16];
    int i , j;
    for(i =0 ; i < 10000;i++){
        for(j =0 ; j < 16;j++){
            vp100[i][j] = j + 1;
        }
    }
    
    int rdmpopsize = 10000;
    for ( i = 0; i < rdmpopsize; i++){
        shuffle(vp100[i], vp100[i] + 16, g);
    }

    int t;
    int iter;
    
    bool completed[16];
    int skillreq[16];
    int skillcodecorr[16];
    int daysreq[16];
    int bbf[16];
    for(i = 0 ; i < 16;i++){
        skillreq[i] = (i)%4 + 1;//required skill set of the project 
        skillcodecorr[i] = i%5 + 1;// has the skill name that has to be awssociated with the code 
        daysreq[i] = 5;
        bbf[i] = i + 8;
    }
    
   int contributors[5];
   //numofcontrubutirs = 5
   
   for(i =0 ; i < 5;i++){
      contributors[i] = 0;
      
   }
    for(i = 0 ; i < 16;i++){
       completed[i] = 0 ;
    }

    int contriava[5];\
    int contritime[5];
    for(i = 0 ; i < 5;i++){
        contriava[i] = 0 ;
        contritime[i] = 0;
    }
    
    int iter ;
    for(iter =0 ;iter < rdmpopsize;iter++){

        int per[16] ;
        int j;
        for(j =0 ; j < 16;j++){
            per[j] = vp100[i][j];
        }

        int time = 0;
        for(time = 0; time < 10;time++)
        {

            // making contributor available 
            for(j =0 ; j < 5;j++){
                if(time == contritime[j]){
                    contriava[j] = 0;
                }
            }

        for(j = 0 ; j < 16;j++){
            if(completed[j])continue;
            else { 
                int subtask = per[j];
                int x = skillreq[subtask];
                int y = skillcodecorr[subtask];
                int k;
                int minel = INT_MIN;
                int index = -1;
                for(k = 0 ; k < 5;k++){
                    if(contriava[k] == 0)
                    {int l;
                    for(l = 0 ; l < contributor[k].size();l++){
                        if(contributor[k][l].first == y && contributor[k][l].second >= x){
                            minel = contributor[k][l].second;
                            index = k;
                        }
                    } }
                } 
                if(index != -1)
                {
                    contritime[index] += daysreq[subtask] ;
                    contriava[index] = 1;
                }
                
                

                
                
            }
        }}




    }


    




}

 