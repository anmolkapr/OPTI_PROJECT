#include<bits/stdc++.h>
using namespace std;

///////////////////////////////////////////////SIDE VARAIBLES////////////////////////////////////////////////////////

int numofcontri;
vector<pair<string,int>> contri[5];
vector<pair<string,int>> projectskills [16];
int proj_bbfore[10];
int proj_days[10];
int numofproject= 3;
int t;
int iter;
int counterskill ;
bool optimised[3][3][3][10];
int tot;
vector<pair<int,int>> contributor[5];
int digit[7];
long int id=0;
map<int,vector<pair<int,int>>> skillmap;
int skillreq[16];
vector<int> skillcodecorr(16);
vector<int> daysreq(16);
vector<int> bbf(16);
int i,j;
int nskills;
int skillname, skilllevel, skillcode;
int skills;
int vp100[10000][16];
int rdmpopsize = 10000;
bool completed[16];
int contributors[5];
int contriava[5];
int contritime[5];

int score[16];
int contrialloted[5];
int per[16] ; 
int tmct ;
int subtaskcomp[16];
int maxiterans = INT_MIN;
int maxalloted[16];
int finalscore, finalscore1 ;
int totalsub = 0;
int maxtotal[16];
int maxtotalscore;
////////////////////////////////////////////////////////////INPUT FUNCTION////////////////////////////////////
void contributorInput(){
    cin >> numofcontri;
    for(i =0 ; i < numofcontri ; i++){
        cin >> nskills;                                                     
        for(j = 0 ; j < nskills;j++){     
            // skill name is coded to a number 
            cin >> skillname >> skilllevel;
            contributor[i].push_back({skillname,skilllevel});
        }
    }
}



void projectInput(){
    
    cin >> numofproject;
    
    for(i =0 ;i < numofproject;i++){
        int score1;
         cin >> proj_days[i] >> proj_bbfore[i];
         cin >> score1;
         cin >> skills;
         for(j =0 ; j < skills;j++){
            
            cin >> skillcode >> skilllevel;
            skillcodecorr[totalsub] = skillcode;
            skillreq[totalsub] = skilllevel;
            daysreq[totalsub] = proj_days[i];
            bbf[totalsub] = proj_bbfore[i];
            score[totalsub] = score1;
            totalsub++;
        
         }
         }
}

/////////////////////////////////////////////////////////////MAIN FUNCTIOn ///////////////////////////////////////////////////////

void randompopulationgenerator(){

    random_device rd;
    mt19937 g(rd());

    for(i =0 ; i < 10000;i++){
        for(j =0 ; j < totalsub;j++){
            vp100[i][j] = j + 1;
        }
    }
    
    
    
    for ( i = 0; i < rdmpopsize; i++){
        shuffle(vp100[i], vp100[i] + totalsub, g);
        for(j =0 ; j < totalsub;j++){
            vp100[i][j]--;
        }
    }
    


}


int main(){
    counterskill = 0;

    contributorInput();
    projectInput();
    
    
    
    int val[rdmpopsize];
   
    
    
    randompopulationgenerator();
    
    srand(time(0));

     // checking of random population 

    // rdmpopsize = 1;
    int arr[rdmpopsize];
    
    maxtotalscore = 0;
    rdmpopsize = 10000;
    
    for(iter = 0 ;iter < rdmpopsize;iter++){
        
        for(i =0 ; i < numofcontri;i++){
            contributors[i] = 0;
            contriava[i] = 0 ;
            contritime[i] = 0;
            contrialloted[i] = -1;
        }
        
        for(j = 0 ;j < totalsub;j++){
            completed[j] = 0 ;
            /// all the contributors are available 
            per[j] = vp100[iter][j];
            subtaskcomp[i] = -1;
        }
        
        
        
     
        for(tmct = 0; tmct < 100;tmct++)
        {
            // making contributor available 
            
            for(j =0 ; j < numofcontri;j++){
                if(tmct == contritime[j]){
                    int x = contrialloted[j];
                    // subtaks a contributor is alloted 
                    subtaskcomp[x] = tmct;
                    // time at which it is completed
                    contriava[j] = 0;
                    contrialloted[j] = -1;
                }
            }
             

            for(j = 0 ; j < totalsub;j++){
                if(completed[per[j]])continue;
                else { 
                    
                    int subtask = per[j];
                    int x = skillreq[subtask];
                    int y = skillcodecorr[subtask];
                    int k;
                    int minel = INT_MAX;
                    int index = -1;
                    
                    for(k = 0 ; k < numofcontri;k++){
                        if(contriava[k] == 0)// if the conritbutor is available 
                        {
                           int l;

                           for(l = 0 ; l < contributor[k].size();l++){
                              if(contributor[k][l].first == y && contributor[k][l].second >= x){
                                // if the skill is matching as well as we have that skill level to be greater than the required one 
                                  if(contributor[k][l].second < minel)
                                    {  
                                       minel = contributor[k][l].second;
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
                        completed[subtask] = 1;
                    // given the subtask to the contributor
                    }

                    // assignment of the contributor to the subtask 
                    
                    
                    
                    }
                } 
           
        }

       
        
        
    
        // SCORE CALCULATION 

        finalscore = 0;
       
        for(i = 0 ; i < totalsub;i++){
            
            if(subtaskcomp[i] == -1){
                   continue;
        }else if(subtaskcomp[i] <= bbf[i]){
                finalscore += score[i];
            }else{
                finalscore += score[i] - (subtaskcomp[i] - bbf[i]); 
            }
        } 
         
        
        
        finalscore1 = finalscore;
        
        int per1[totalsub];
        for(i = 0 ;i < totalsub;i++){
            per1[i] = per[i];
        }
        


        //GENERATION OF NEW POPULATION 
       int x = rand()%totalsub;

       vector<int> newpop(totalsub);
       int rep[totalsub];

        for(i = 0 ; i < totalsub;i++){
            rep[i] = per[i];
        }
        int ct = 0;
       
        for(i = x - 1 ; i >= 0;i--){
   
            newpop[ct] = per[i];
            ct++;
        }
       
       

        for(i = totalsub - 1; i >= 0 ;i--){
             newpop[i] = per[ct];
             ct++;
      
            if(i==x)break;
        }
        


        for(i = 0 ; i < totalsub;i++){
            per[i] = newpop[i];
        }


        
    for(i =0 ; i < numofcontri;i++){
            contributors[i] = 0;
            contriava[i] = 0 ;
            contritime[i] = 0;
            contrialloted[i] = -1;
        }
        
        for(j = 0 ;j < totalsub;j++){
            completed[j] = 0 ;
            // all the contributors are available 
            per[j] = vp100[iter][j];
            subtaskcomp[i] = -1;
        }
        
        
     
        for(tmct = 0; tmct < 100;tmct++)
        {
            // making contributor available 
            for(j =0 ; j < numofcontri;j++){
                if(tmct == contritime[j]){
                    int x = contrialloted[j];
                    // subtaks a contributor is alloted 
                    subtaskcomp[x] = tmct;
                    // time at which it is completed
                    contriava[j] = 0;
                    contrialloted[j] = -1;
                }
            }
             

            for(j = 0 ; j < totalsub;j++){
                if(completed[per[j]])continue;
                else { 
                    
                    int subtask = per[j];
                    int x = skillreq[subtask];
                    int y = skillcodecorr[subtask];
                    int k;
                    int minel = INT_MAX;
                    int index = -1;
                    
                    for(k = 0 ; k < numofcontri;k++){
                        if(contriava[k] == 0)// if the conritbutor is available 
                        {
                           int l;

                           for(l = 0 ; l < contributor[k].size();l++){
                              if(contributor[k][l].first == y && contributor[k][l].second >= x){
                                // if the skill is matching as well as we have that skill level to be greater than the required one 
                                  if(contributor[k][l].second < minel)
                                    {  
                                       minel = contributor[k][l].second;
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
                        completed[subtask] = 1;
                    // given the subtask to the contributor
                    }

                    // assignment of the contributor to the subtask 
                    
                    
                    
                    }
                } 
           
        }


        
        
    
        // SCORE CALCULATION 

        finalscore = 0;

        for(i = 0 ; i < totalsub;i++){
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
            if(maxtotalscore < finalscore2)
             {
                for(i = 0 ; i < totalsub;i++){
                maxtotal[i] = per[i];
                }
                maxtotalscore = finalscore2;
            }
        }else{
            if(maxtotalscore < finalscore1)
            { 
                for(i = 0 ; i < totalsub;i++){
                maxtotal[i] = per1[i];
                }
               maxtotalscore = finalscore1;
        }}
        
        arr[iter] = max(finalscore1,finalscore2);

        
        
        
    }

    


    

   

       


}



 






 
