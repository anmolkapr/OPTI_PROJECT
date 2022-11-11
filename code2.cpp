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
    srand(time(0));

    bool completed[16];
    int skillreq[16];
    int skillcodecorr[16];
    int daysreq[16];
    int bbf[16];
    
   int contributors[5];
   //numofcontrubutirs = 5
   
   
    int contriava[5];
    int contritime[5];
    
    
    int iter ;
    int score[16];
    int contrialloted[5];
    int per[16] ; 
    int time = 0;
    int subtaskcomp[16];
    
    int maxiterans = INT_MIN;
    int maxalloted[16];
    
    for(iter =0 ;iter < rdmpopsize;iter++){
        
        for(i = 0 ; i < 16;i++){
            skillreq[i] = (i)%4 + 1;//required skill set of the project 
            skillcodecorr[i] = i%5 + 1;// has the skill name that has to be awssociated with the code 
            daysreq[i] = 5;
            bbf[i] = i + 8;
            score[i] = i + 1;
        }

        

        for(i =0 ; i < 5;i++){
            contributors[i] = 0;
            contriava[i] = 0 ;
            contritime[i] = 0;
            completed[i] = 0 ;
            contrialloted[i] = -1;
        }
        
        
        int j;
        for(j =0 ; j < 16;j++){
            per[j] = vp100[i][j];
        }

        
        for(i =0 ; i < 16;i++){
            subtaskcomp[i] = -1;
        }
        for(time = 0; time < 10;time++)
        {
            // making contributor available 
            for(j =0 ; j < 5;j++){
                if(time == contritime[j]){
                    int x = contrialloted[j];
                    subtaskcomp[x] = time;
                    // time at which it is completed
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
                    int minel = INT_MAX;
                    int index = -1;
                    for(k = 0 ; k < 5;k++){
                        if(contriava[k] == 0)// if the conritbutor is available 
                        {
                           int l;
                           for(l = 0 ; l < contributor[k].size();l++){
                              if(contributor[k][l].first == y && contributor[k][l].second >= x){
                                // if the skill is matching as well as we have that skill level to be greater than the required one 
                                  if(contributor[k][l].second > minel)
                                    {  minel = contributor[k][l].second;
                                       index = k;
                                    }
                              }
                            }
                        }
                    }  

                    if(index != -1)
                    {
                    // if we are able to find the required contributor  
                        contritime[index] += daysreq[subtask] ;
                        contriava[index] = 1;
                        contrialloted[index] = subtask ;
                    // given the subtask to the contributor
                    }

                    // assignment of the contributor to the subtask 
                    
                    
                    
                    }
                }
        }

        
    
        // SCORE CALCULATION 

        int finalscore = 0;
        for(i = 0 ; i < 16;i++){
            if(subtaskcomp[i] == -1){
                   continue;
        }else if(subtaskcomp[i] <= bbf[i]){
                finalscore += score[i];
            }else{
                finalscore += score[i] - (subtaskcomp[i] - bbf[i]); 
            }
        }
    
        int finalscore1 = finalscore;


        


        //GENERATION OF NEW POPULATION 
        int x = rand()%16;

        vector<int> newpop(16);
        int rep[16];

        for(i = 0 ; i < 16;i++){
            rep[i] = per[i];
        }

        for(i = 0 ; i < x;i++){
            newpop.push_back(per[i]);
        }

        for(i = 15; i >= 0 ;i--){
            newpop.push_back(per[i]);
            if(newpop.size() == 16)break;
        }


        for(i = 0 ; i < 16;i++){
            per[i] = newpop[i];
        }
        
        // allotment of the tasks to the contributors 

        for(time = 0; time < 10;time++)
        {
            // making contributor available 
            for(j =0 ; j < 5;j++){
                if(time == contritime[j]){
                    int x = contrialloted[j];
                    subtaskcomp[x] = time;
                    // time at which it is completed
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
                    int minel = INT_MAX;
                    int index = -1;
                    for(k = 0 ; k < 5;k++){
                        if(contriava[k] == 0)// if the conritbutor is available 
                        {
                           int l;
                           for(l = 0 ; l < contributor[k].size();l++){
                              if(contributor[k][l].first == y && contributor[k][l].second >= x){
                                // if the skill is matching as well as we have that skill level to be greater than the required one 
                                  if(contributor[k][l].second > minel)
                                    {  minel = contributor[k][l].second;
                                       index = k;
                                    }
                              }
                            }
                        }
                    }     
                    if(index != -1)
                    {
                    // if we are able to find the required contributor  
                        contritime[index] += daysreq[subtask] ;
                        contriava[index] = 1;
                        contrialloted[index] = subtask ;
                    // given the subtask to the contributor
                    }

                   
                     
                    
                    
                    }
                }
        }

        // SCORE CALCULATION 

        finalscore = 0;
        for(i = 0 ; i < 16;i++){
            if(subtaskcomp[i] == -1){
                   continue;
        }else if(subtaskcomp[i] <= bbf[i]){
                finalscore += score[i];
            }else{
                finalscore += score[i] - (subtaskcomp[i] - bbf[i]); 
            }
        }
    
        int finalscore2 = finalscore;


        if(finalscore2 > finalscore1){
            maxalloted[i] = per[i];
            maxiterans = finalscore2;
        }else{
            maxalloted[i] = rep[i];
            maxiterans = finalscore1;
        }
    }


    // we got the maximum permutation 
    // 
    
    for(i =0 ; i < 16;i++){
        per[i] = maxalloted[i];
    }

    for(i = 0 ; i < 16;i++){
            skillreq[i] = (i)%4 + 1;//required skill set of the project 
            skillcodecorr[i] = i%5 + 1;// has the skill name that has to be awssociated with the code 
            daysreq[i] = 5;
            bbf[i] = i + 8;
            score[i] = i + 1;
        }

        

        for(i =0 ; i < 5;i++){
            contributors[i] = 0;
            contriava[i] = 0 ;
            contritime[i] = 0;
            completed[i] = 0 ;
            contrialloted[i] = -1;
        }
        
        
        int j;
        for(j =0 ; j < 16;j++){
            per[j] = vp100[i][j];
        }

        
        for(i =0 ; i < 16;i++){
            subtaskcomp[i] = -1;
        }
        for(time = 0; time < 10;time++)
        {
            // making contributor available 
            for(j =0 ; j < 5;j++){
                if(time == contritime[j]){
                    int x = contrialloted[j];
                    subtaskcomp[x] = time;
                    // time at which it is completed
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
                    int minel = INT_MAX;
                    int index = -1;
                    for(k = 0 ; k < 5;k++){
                        if(contriava[k] == 0)// if the conritbutor is available 
                        {
                           int l;
                           for(l = 0 ; l < contributor[k].size();l++){
                              if(contributor[k][l].first == y && contributor[k][l].second >= x){
                                // if the skill is matching as well as we have that skill level to be greater than the required one 
                                  if(contributor[k][l].second > minel)
                                    {  minel = contributor[k][l].second;
                                       index = k;
                                    }
                              }
                            }
                        }
                    }  

                    if(index != -1)
                    {
                    // if we are able to find the required contributor  
                        contritime[index] += daysreq[subtask] ;
                        contriava[index] = 1;
                        contrialloted[index] = subtask ;
                    // given the subtask to the contributor
                    }

                    // assignment of the contributor to the subtask 
                    
                    
                    
                    }
                }
        }

        
    
        // SCORE CALCULATION 

        int finalscore = 0;
        for(i = 0 ; i < 16;i++){
            if(subtaskcomp[i] == -1){
                   continue;
        }else if(subtaskcomp[i] <= bbf[i]){
                finalscore += score[i];
            }else{
                finalscore += score[i] - (subtaskcomp[i] - bbf[i]); 
            }
        }





}
 






 