#include<bits/stdc++.h>
using namespace std;

///////////////////////////////////////////////SIDE VARAIBLES////////////////////////////////////////////////////////

int numofcontri = 5;
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
    
    
    
    // for(i =0 ;i < totalsub;i++){
    //     cout << daysreq[i] << " ";
    //     cout << bbf[i] << " ";
    //     cout << score[i] << " ";
    //     cout << skillcodecorr[i] << ' ';
    //     cout << skillreq[i] << " ";
        
    //     cout << endl;
    // }
    
    
   
    
    
    randompopulationgenerator();
    
    srand(time(0));

    // checking of random population 
   
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
        
        for(j =0 ; j < totalsub;j++){
            cout << per[j] << ' ';
        }
        cout << endl;
     
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
            //    cout << "time " << tmct << endl;
            //     for(i =0 ; i < numofcontri ;i++){
            //         cout   << contrialloted[i] << ' '  ;
            //     }
            //      cout << endl;
            //     for(i = 0 ; i < totalsub;i++){
            //         cout << completed[i] <<  ' ';
            //     }
            //     cout << endl;
            //     cout << endl;
        }

        for(i = 0 ; i < totalsub;i++){
           cout << subtaskcomp[i] << ' ';
        }
        cout << endl;
       
        
        // for(i = 0 ; i < totalsub;i++){
        //     cout << per[i] << ' ';
        // }
        // cout << endl;
    
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
        
        cout << finalscore1 << endl;
        cout << endl;
        


    //     //GENERATION OF NEW POPULATION 
    //     int x = rand()%16;

    //     vector<int> newpop(16);
    //     int rep[16];

    //     for(i = 0 ; i < 16;i++){
    //         rep[i] = per[i];
    //     }

    //     for(i = 0 ; i < x;i++){
    //         newpop.push_back(per[i]);
    //     }

    //     for(i = 15; i >= 0 ;i--){
    //         newpop.push_back(per[i]);
    //         if(newpop.size() == 16)break;
    //     }


    //     for(i = 0 ; i < 16;i++){
    //         per[i] = newpop[i];
    //     }
        
    //     // allotmctent of the tasks to the contributors 

    //     for(tmct = 0; tmct < 10;tmct++)
    //     {
    //         // making contributor available 
    //         for(j =0 ; j < 5;j++){
    //             if(tmct == contritime[j]){
    //                 int x = contrialloted[j];
    //                 subtaskcomp[x] = tmct;
    //                 // time at which it is completed
    //                 contriava[j] = 0;
    //             }
    //         }

    //         for(j = 0 ; j < 16;j++){
    //             if(completed[j])continue;
    //             else { 
    //                 int subtask = per[j];
    //                 int x = skillreq[subtask];
    //                 int y = skillcodecorr[subtask];
    //                 int k;
    //                 int minel = INT_MAX;
    //                 int index = -1;
    //                 for(k = 0 ; k < 5;k++){
    //                     if(contriava[k] == 0)// if the conritbutor is available 
    //                     {
    //                        int l;
    //                        for(l = 0 ; l < contributor[k].size();l++){
    //                           if(contributor[k][l].first == y && contributor[k][l].second >= x){
    //                             // if the skill is matching as well as we have that skill level to be greater than the required one 
    //                               if(contributor[k][l].second > minel)
    //                                 {  minel = contributor[k][l].second;
    //                                    index = k;
    //                                 }
    //                           }
    //                         }
    //                     }
    //                 }     
    //                 if(index != -1)
    //                 {
    //                 // if we are able to find the required contributor  
    //                     contritime[index] += daysreq[subtask] ;
    //                     contriava[index] = 1;
    //                     contrialloted[index] = subtask ;
    //                 // given the subtask to the contributor
    //                 }

                   
                     
                    
                    
    //                 }
    //             }
    //     }

    //     // SCORE CALCULATION 

    //     finalscore = 0;
    //     for(i = 0 ; i < 16;i++){
    //         if(subtaskcomp[i] == -1){
    //                continue;
    //     }else if(subtaskcomp[i] <= bbf[i]){
    //             finalscore += score[i];
    //         }else{
    //             finalscore += score[i] - (subtaskcomp[i] - bbf[i]); 
    //         }
    //     }
    
    //     int finalscore2 = finalscore;


    //     if(finalscore2 > finalscore1){
    //         maxalloted[i] = per[i];
    //         maxiterans = finalscore2;
    //     }else{
    //         maxalloted[i] = rep[i];
    //         maxiterans = finalscore1;
    //     }
    // }


    // // we got the maximum permutation 
    // // 
    
    // for(i =0 ; i < 16;i++){
    //     per[i] = maxalloted[i];
    // }

    // for(i = 0 ; i < 16;i++){
    //         skillreq[i] = (i)%4 + 1;//required skill set of the project 
    //         skillcodecorr[i] = i%5 + 1;// has the skill name that has to be awssociated with the code 
    //         daysreq[i] = 5;
    //         bbf[i] = i + 8;
    //         score[i] = i + 1;
    //     }

        

    //     for(i =0 ; i < 5;i++){
    //         contributors[i] = 0;
    //         contriava[i] = 0 ;
    //         contritime[i] = 0;
    //         completed[i] = 0 ;
    //         contrialloted[i] = -1;
    //     }
        
        
    
    //     for(j =0 ; j < 16;j++){
    //         per[j] = vp100[i][j];
    //     }

        
    //     for(i =0 ; i < 16;i++){
    //         subtaskcomp[i] = -1;
    //     }
    //     for(tmct = 0; tmct < 10;tmct++)
    //     {
    //         // making contributor available 
    //         for(j =0 ; j < 5;j++){
    //             if(tmct == contritime[j]){
    //                 int x = contrialloted[j];
    //                 subtaskcomp[x] = tmct;
    //                 // time at which it is completed
    //                 contriava[j] = 0;
    //             }
    //         }

    //         for(j = 0 ; j < 16;j++){
    //             if(completed[j])continue;
    //             else { 
    //                 int subtask = per[j];
    //                 int x = skillreq[subtask];
    //                 int y = skillcodecorr[subtask];
    //                 int k;
    //                 int minel = INT_MAX;
    //                 int index = -1;
    //                 for(k = 0 ; k < 5;k++){
    //                     if(contriava[k] == 0)// if the conritbutor is available 
    //                     {
    //                        int l;
    //                        for(l = 0 ; l < contributor[k].size();l++){
    //                           if(contributor[k][l].first == y && contributor[k][l].second >= x){
    //                             // if the skill is matching as well as we have that skill level to be greater than the required one 
    //                               if(contributor[k][l].second > minel)
    //                                 {  minel = contributor[k][l].second;
    //                                    index = k;
    //                                 }
    //                           }
    //                         }
    //                     }
    //                 }  

    //                 if(index != -1)
    //                 {
    //                 // if we are able to find the required contributor  
    //                     contritime[index] += daysreq[subtask] ;
    //                     contriava[index] = 1;
    //                     contrialloted[index] = subtask ;
    //                 // given the subtask to the contributor
    //                 }

    //                 // assignment of the contributor to the subtask 
                    
                    
                    
    //                 }
    //             }
    //     }

        
    
    //     // SCORE CALCULATION 

    //      finalscore = 0;
    //     for(i = 0 ; i < 16;i++){
    //         if(subtaskcomp[i] == -1){
    //                continue;
    //     }else if(subtaskcomp[i] <= bbf[i]){
    //             finalscore += score[i];
    //         }else{
    //             finalscore += score[i] - (subtaskcomp[i] - bbf[i]); 
    //         }
       }





}
 






 
