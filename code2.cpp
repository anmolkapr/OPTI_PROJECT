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

int digit[7];
long int id=0;

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

int randomarray[362881][9];
int ctr ;

void permute(string &a, int l, int r)
{
	if (l == r)
		{
      int i;
      for(i = 0 ; i < a.length();i++){
          randomarray[ctr][i] = a[i] - 'A';
      }
      ctr++;
    } 
	else
	{
		for (int i = l; i <= r; i++)
		{
      swap(a[l], a[i]);
			permute(a, l+1, r);
			swap(a[l], a[i]);
		}
	}
}

void allpermgenerator(){
    string s = "ABCDEFGHI";
    permute(s,0,9 - 1);
}



vector<int> randompermgenerator(int x){
    
    vector<int> v ;
    int i;
    for(i = 0 ;i < 9;i++){
        v.push_back(randomarray[x][i]);
    }
    return v;
}

int randomstartpop[10001][9];

void randompopulationgenerator(){
    int i;
    for(i =0 ; i < 10000;i++){
        
        digit[6]=rand()%29+1;

        for (int i=5; i>=0; i--) {
            digit[i]=rand()%10+1;
        } 

        long int x= digit[6]*pow(10,6) + digit[5]*pow(10,5) + digit[4]*pow(10,4) + digit[3]*pow(10,3)+digit[2]*pow(10,2) + digit[1]*10+digit[0]; 

        x = x%362880;
        
        vector<int> ans = randompermgenerator(x);
       
        for(int j =0 ; j < 9;j++){
            randomstartpop[i][j] = ans[j];
        }

    }
}

int main(){
   

    int i;
    counterskill = 0;

    // contributorInput();
    // projectInput();
    int time = 10 ;
    int skillsnum = skillmap.size();
     tot = numofcontri + numofproject + skillsnum + time ;
   

    allpermgenerator();
    
    // for(i = 0 ;i < 362881;i++){
       int j;
       i = 362;
    //    if(randomarray[i][0] == 1) cout << i << endl;;
       for(j = 0 ; j < 9;j++){
         cout << randomarray[i][j] ;
       }
       
        cout << endl;
    
   
    srand(static_cast<unsigned>(std::time(nullptr)));


    //BEGININNING OF THE RANDOM POPULATION GENERATOR (METAHEURISTIC APPORACH )
    randompopulationgenerator();

    for(i = 0 ; i< 10000;i++){
        int j;
        for(j =0 ; j < 9;j++){
            cout << randomstartpop[i][j] << ' ';
        }
        cout << endl;
    }
    

    
    



}

 