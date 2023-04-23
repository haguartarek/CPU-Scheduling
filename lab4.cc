#include <iostream>
#include <queue>
#include <bits/stdc++.h>
#include<vector>
#include <string>
using namespace std;
int tim; 
int number;
struct process{
    char process;
    int arrivaltime;
    int servicetime;
    int remainingtime;
    int level;

};
struct aging {
char process;
int arrivaltime;
int priority;
int firstflag;
};

struct info{
    char process;
    int waitingtime;
    int executiontime;
    int turnaround;
    float ratioo;
    int emptyy1;
    int emptyy2;
    int arrivaltime;
};
struct com{
bool operator ()(process  a , process b)
{
    return a.servicetime > b.servicetime;
}
};
struct com2{
bool operator ()(info  a , info b)
{
    return a.ratioo < b.ratioo;
}
};
struct com3{
bool operator () (process a,process b){

        return a.remainingtime > b.remainingtime  || (a.remainingtime==b.remainingtime && a.arrivaltime>b.arrivaltime);
}
};
struct com4{
bool operator () (aging a,aging b){
	return a.priority < b.priority || (a.priority==b.priority && a.firstflag > b.firstflag);

}
};
bool operator == (const aging &p1, const aging &p2)
{
   if( p1.process==p2.process)
     return true;
   else
     return false;
}
bool operator == (const process &p1, const process &p2)
{
   if( p1.process==p2.process)
     return true;
   else
     return false;
}

bool searchvalue(process arr[],int size,process value)
{
     for(int i=0;i<size;i++)
     {
         if(arr[i].process==value.process)
         {
            return 1;
         }
     }
     return 0;
     cout<<"value do not exist"<<endl;
}
int returnindex_aging(aging arr[],int size,aging value){
    for (int i=0;i<size;i++){
        if (arr[i].process==value.process){
            return i;
        }
    }
    return 0;
}
int returnindex(process arr[],int size,process value){
    for (int i=0;i<size;i++){
        if (arr[i].process==value.process){
            return i;
        }
    }
    return 0;
}
bool searchvalue1(info arr[],int size,process value)
{
     for(int i=0;i<size;i++)
     {
         if(arr[i].process==value.process)
         {
            return 1;
         }
     }
     return 0;
}


void print_non_preemptive(info a[]){
    int i=0;
    int j=0;
for (i=0;i<number;i++){
         cout << "\n";
        cout << a[i].process;
        cout << "     ";
     for(j=0;j<tim;j++){
        while (a[i].emptyy1!=0){
        cout << "| ";
        a[i].emptyy1--;
    }
    while (a[i].waitingtime!=0){
        cout << "|.";
        a[i].waitingtime--;
    }
     while (a[i].executiontime!=0){
        cout << "|*";
        a[i].executiontime--;
    }
     while (a[i].emptyy2!=0){
        cout << "| ";
        a[i].emptyy2--;
    }
     }
     cout << "| ";
}
cout << "\n";
cout << "------------------------------------------------";
cout << "\n\n";
memset(a,0,number);
}

void printFCFS (queue<process> q){      //Done
    info a [number];
    int i,j;
    for (i=0;i<number;i++){
        a[i].waitingtime=0;
        a[i].emptyy1=0;
        a[i].emptyy2=0;
        a[i].executiontime=0;
    }
    int finish=0;
    int count=0;
    process x;
    cout << "FCFS  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 \n";
    cout << "------------------------------------------------";
    for (j=0;j<number;j++){
        x=q.front();
        q.pop();
        //cout << x.process;
        count=0;
        for (i=0;i<tim;i++){
            if (i>=x.arrivaltime && i<finish){
                //cout << "|."; //entered el ready queue
                a[j].process=x.process;
                a[j].waitingtime++;
                a[j].arrivaltime=x.arrivaltime;
            }
            else if (i>=finish && count<x.servicetime){
                //dor el process el gayya
                count++;
                //cout << "|*";
                a[j].process=x.process;
                a[j].executiontime++;
                a[j].arrivaltime=x.arrivaltime;
            }
            else {
               // cout << "| ";
               if (i<x.arrivaltime){
                 a[j].emptyy1++;
               }
               else{
                 a[j].emptyy2++;
               }
                a[j].process=x.process;
                a[j].arrivaltime=x.arrivaltime;
            }
        }
        finish=finish+x.servicetime;
    }
    print_non_preemptive(a);
    memset(a,0,number);
}
bool compare( process a, process b){
 if(a.arrivaltime < b.arrivaltime)
  return 1;
 else
  return 0;
}
bool compare3(process a,process b){
    if (a.level < b.level || (a.level==b.level && a.arrivaltime<b.arrivaltime))
        return 1;
    else
        return 0;

}
bool compare4( aging a, aging b){
 if(a.arrivaltime < b.arrivaltime)
  return 1;
 else
  return 0;
}
void FCFSstat(process Array[]){       //Done

    sort (Array,Array+number,compare);
    int i,j;
    int flag=0;
    int sum=0;
    float sum2=0;
    float sum3=0;
    float arr[number];
    cout << "FCFS";
    for (i=0;i<6;i++){
            flag=0;
            cout << "\n";
            if (i==0){
            cout << "Process    ";
            }
            if (i==1){
            cout << "Arrival    ";
            }
            if (i==2){
            cout << "Service    ";
            }
            if (i==3){
            cout << "Finish     ";
            }
             if (i==4){
            cout << "Turnaround ";
            }
             if (i==5){
            cout << "NormTurn   ";
            }
        for (j=0;j<number;j++){
        if (i==0){         // Process
            cout << "|  ";
            cout << Array[j].process;
            cout << "  ";
        }
        if (i==1){           // Arrival
            cout << "|  ";
            cout << Array[j].arrivaltime;
            cout << "  ";
        }
        if (i==2){          // Servicetime
            cout << "|  ";
            cout << Array[j].servicetime;
            cout << "  ";
            if (j==number-1){
                cout << "| Mean";
                flag=1;
            }
        }
            if (i==3){        //finish
            if ((Array[j].servicetime+sum)< 10){
            sum=Array[j].servicetime+sum;
            arr[j]=sum;
           cout << "|  ";
            cout << arr[j];
            cout << "  ";

            }
            else {
            sum=Array[j].servicetime+sum;
            arr[j]=sum;
           cout << "| ";
            cout << sum;
            cout << "  ";
            }
            if (j==number-1){
                cout << "|-----";
                flag=1;

            }
        }
        if (i==4){     //Turnaround

            if ((arr[j]-Array[j].arrivaltime)< 10){
           cout << "|  ";
            cout << arr[j]-Array[j].arrivaltime;
            cout << "  ";
            sum2=sum2+arr[j]-Array[j].arrivaltime;
            }
            else {
           cout << "| ";
            cout << arr[j]-Array[j].arrivaltime;
             sum2=sum2+arr[j]-Array[j].arrivaltime;
             cout << "  ";
            }
            if (j==number-1){
                std::cout << std::setprecision(2) << std::fixed;
                 cout << "| ";
                 std::cout << sum2/number ;
                flag=1;
            }

        }
        if (i==5){

            std::cout << std::setprecision(2) << std::fixed;
            cout << "|";
            cout << " ";
            std::cout <<(arr[j]-Array[j].arrivaltime)/ Array[j].servicetime;
            sum3=sum3+(arr[j]-Array[j].arrivaltime)/ Array[j].servicetime;

        flag=1;
         if (j==number-1){
                std::cout << std::setprecision(2) << std::fixed;
                 cout << "| ";
                 std::cout << sum3/number ;
                flag=1;
            }

        }

    }

        cout << "|";


}
	cout << "\n\n";
}

bool compare2( info a, info b){
 if(a.arrivaltime < b.arrivaltime)
  return 1;
 else
  return 0;
}
void statsnonpreemptive(info a[],process Array[],string name){
    int i,j;
    int flag=0;
    int sum=0;
    float sum2=0;
    float sum3=0;
    float turn[number];
    float arrayy[number];
    cout << name;
    for (i=0;i<6;i++){
            flag=0;
            cout << "\n";
            if (i==0){
            cout << "Process    ";
            }
            if (i==1){
            cout << "Arrival    ";
            }
            if (i==2){
            cout << "Service    ";
            }
            if (i==3){
            cout << "Finish     ";

            }
             if (i==4){
            cout << "Turnaround ";
            }
             if (i==5){
            cout << "NormTurn   ";
            }
        for (j=0;j<number;j++){
        if (i==0){         // Process
            cout << "|  ";
            cout << Array[j].process;
            cout << "  ";
        }
        if (i==1){           // Arrival
            cout << "|  ";
            cout << Array[j].arrivaltime;
            cout << "  ";
        }
        if (i==2){          // Servicetime
            cout << "|  ";
            cout << Array[j].servicetime;
            cout << "  ";
            if (j==number-1){
                cout << "| Mean";
                flag=1;

            }
        }
            if (i==3){        //finish
            if ((a[j].emptyy1+a[j].waitingtime+a[j].executiontime)< 10){
            sum=a[j].emptyy1+a[j].waitingtime+a[j].executiontime+sum;
           arrayy[j]=sum;
           cout << "|  ";
            cout << a[j].emptyy1+a[j].waitingtime+a[j].executiontime;
            cout << "  ";
            }
            else {
            sum=a[j].emptyy1+a[j].waitingtime+a[j].executiontime+sum;
            arrayy[j]=sum;
           cout << "| ";
            cout << a[j].emptyy1+a[j].waitingtime+a[j].executiontime;
            cout << "  ";
            }
            if (j==number-1){
                cout << "|-----";
                flag=1;

            }
        }
        if (i==4){     //Turnaround

            if ((a[j].emptyy1+a[j].waitingtime+a[j].executiontime-Array[j].arrivaltime)< 10){
           cout << "|  ";
            cout << a[j].emptyy1+a[j].waitingtime+a[j].executiontime-Array[j].arrivaltime;
            turn[j]= a[j].emptyy1+a[j].waitingtime+a[j].executiontime-Array[j].arrivaltime;
            sum2=sum2+a[j].emptyy1+a[j].waitingtime+a[j].executiontime-Array[j].arrivaltime;
            cout << "  ";
            }
            else {
           cout << "| ";
            cout << a[j].emptyy1+a[j].waitingtime+a[j].executiontime-Array[j].arrivaltime;
             turn[j]= a[j].emptyy1+a[j].waitingtime+a[j].executiontime-Array[j].arrivaltime;
             sum2=sum2+a[j].emptyy1+a[j].waitingtime+a[j].executiontime-Array[j].arrivaltime;
             cout << "  ";
            }
            if (j==number-1){
              std::cout << std::setprecision(2) << std::fixed;
                 cout << "| ";
                 std::cout << sum2/number ;
                flag=1;
            }

        }
        if (i==5){
            std::cout << std::setprecision(2) << std::fixed;
            cout << "|";
            cout << " ";
            std::cout <<turn[j]/ a[j].executiontime;
            sum3=sum3+turn[j]/ a[j].executiontime;
        flag=1;
         if (j==number-1){
                std::cout << std::setprecision(2) << std::fixed;
                 cout << "| ";
                 std::cout << sum3/number ;
                flag=1;
            }

        }
        }
        cout << "|";
    }
    cout << "\n\n";
}
void SPN (process Array[], int sflag){    // Done
    info a[number];
    int i,j;
    int finish=0;
    int n=number;
    sort(Array,Array+n,compare);
    queue <process> q; //queue that holds order of execution
    priority_queue <process, vector<process>, com>q1; //priority queue to hold the lowest remaining time
 process x,d;
    int count=0;

    int k;
    process arr[number];
    for (i=0;i<number;i++){
         if (Array[i].arrivaltime<=finish){
            for (k=i;k<number;k++){
                if (Array[k].arrivaltime<=finish){
                    if (searchvalue(arr,number,Array[k])==1){
                        continue;
                    }
                    else{
                    q1.push({Array[k].process,Array[k].arrivaltime,Array[k].servicetime});
                    }
                }
            }
            x=q1.top(); //haygebly el E
            q.push({x.process,x.arrivaltime,x.servicetime});
            arr[i]=x;
            q1.pop();
            finish=finish+x.servicetime;
         }
    }
for (i=0;i<number;i++){
        a[i].waitingtime=0;
        a[i].emptyy1=0;
        a[i].emptyy2=0;
        a[i].executiontime=0;
    }
     finish=0;
     count=0;
    for (j=0;j<number;j++){
        x=q.front();
        q.pop();
        count=0;
        //cout << "\t";
        for (i=0;i<tim;i++){
            if (i>=x.arrivaltime && i<finish){
                //cout << "|."; //entered el ready queue
                a[j].process=x.process;
                a[j].waitingtime++;
                a[j].arrivaltime=x.arrivaltime;
            }
            else if (i>=finish && count<x.servicetime){
                //dor el process el gayya
                count++;
                //cout << "|*";
                a[j].process=x.process;
                a[j].executiontime++;
                a[j].arrivaltime=x.arrivaltime;
            }
            else {
               // cout << "| ";
               if (i<x.arrivaltime){
                 a[j].emptyy1++;
               }
               else{
                 a[j].emptyy2++;
               }
                a[j].process=x.process;
                a[j].arrivaltime=x.arrivaltime;
            }
        }
        finish=finish+x.servicetime;
    }
    sort(a,a+number,compare2);
    if (sflag==1){
    cout << "SPN   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 \n";
    cout << "------------------------------------------------";
        print_non_preemptive(a);
        memset(a,0,number);
    }
   //
   else {
    sort (Array,Array+number,compare);
    string name="SPN";
    statsnonpreemptive(a,Array,name);
   }

    }

void trace(info a[], process Array[], string name){
    cout << name;
    cout << "0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 \n";
    cout << "------------------------------------------------";
    int sum=0;
    int flag=0;
     int i,j;
    for (i=0;i<number;i++){
        sum=0;
        flag=0;
        cout << "\n";
        cout << Array[i].process;
        cout << "     ";
    for (j=0;j<tim;j++){
    if (Array[i].process==a[j].process){
        cout << "|*";
        sum ++;
        flag =1 ;
    }
    else if (flag==1){
        if (sum==Array[i].servicetime){
            cout << "| ";
        }
        else {
            cout << "|.";
        }
    }
        else {
                if (Array[i].arrivaltime<=j){
                    cout << "|.";
                }
                else {
            cout << "| ";
                }
        }
    }
    cout << "| ";
    }
    cout << "\n";
    cout << "------------------------------------------------";
	cout << "\n\n";
	memset(a,0,tim);

}
void stats (info a[],process Array[],int finisharray[], string name){
    int sum=0;
    int flag=0;
    int i,j;
    int flag2=0;
    int sum5=0;
    float sum2=0;
    float sum3=0;
    float turn[number];
    float arrayy[number];
    cout << name;
    for (i=0;i<6;i++){
            flag2=0;
            cout << "\n";
            if (i==0){
            cout << "Process    ";
            }
            if (i==1){
            cout << "Arrival    ";
            }
            if (i==2){
            cout << "Service    ";
            }
            if (i==3){
            cout << "Finish     ";
            }
             if (i==4){
            cout << "Turnaround ";
            }
             if (i==5){
            cout << "NormTurn   ";
            }
        for (j=0;j<number;j++){
        if (i==0){         // Process
            cout << "|  ";
            cout << Array[j].process;
            cout << "  ";
        }
        if (i==1){           // Arrival
            cout << "|  ";
            cout << Array[j].arrivaltime;
            cout << "  ";
        }
        if (i==2){          // Servicetime
            cout << "|  ";
            cout << Array[j].servicetime;
            cout << "  ";
            if (j==number-1){
                cout << "| Mean";
                flag2=1;

            }
        }
            if (i==3){        //finish
            if (finisharray[j]< 10){
            sum5=finisharray[j]+sum;
           arrayy[j]=sum;
           cout << "|  ";
            cout << finisharray[j];
            cout << "  ";
            }
            else {
            sum5=finisharray[j]+sum;
            arrayy[j]=sum;
           cout << "| ";
            cout << finisharray[j];
            cout << "  ";
            }
            if (j==number-1){
                cout << "|-----";
                flag2=1;
            }
        }
        if (i==4){     //Turnaround

            if ((finisharray[j]-Array[j].arrivaltime)< 10){
            cout << "|  ";
            turn[j]= finisharray[j]-Array[j].arrivaltime;
            cout << finisharray[j]-Array[j].arrivaltime;
            cout << "  ";
            sum2=sum2+finisharray[j]-Array[j].arrivaltime;
            }
            else {
           cout << "| ";
             turn[j]= finisharray[j]-Array[j].arrivaltime;
             cout << finisharray[j]-Array[j].arrivaltime;
             cout << "  ";
             sum2=sum2+finisharray[j]-Array[j].arrivaltime;
            }
            if (j==number-1){
                std::cout << std::setprecision(2) << std::fixed;
                 if (sum2/number <10){
                 cout << "| ";
                 }
                 else{
                 cout << "|";
                 }
                 std::cout << sum2/number ;
                flag2=2;
            }
        }
        if (i==5){

            std::cout << std::setprecision(2) << std::fixed;
            cout << "|";
            cout << " ";
            std::cout << turn[j] / a[j].executiontime;
            sum3=sum3+turn[j]/ a[j].executiontime;
        flag2=2;
         if (j==number-1){
                std::cout << std::setprecision(2) << std::fixed;
                if (sum3/number <10){
                 cout << "| ";
                 }
                 else{
                 cout << "|";
                 }
                 std::cout << sum3/number ;
                flag2=2;
            }
        }
        }
        cout << "|";
    }
	cout << "\n\n";

}
void SRT(process Array[],int flag){
	
        int i,j;
        int finisharray[number];
        memset(finisharray,0,sizeof(finisharray));
        info a[tim];
        //sort array acc to arrival time
        sort (Array,Array+number,compare);
        int finish=0,count=0;
        process x,d;
        int k;
        memset(a,0,sizeof(a));
        priority_queue <process, vector<process>, com3>q1; //priority queue and sorts least remaining time as the highest priority
        queue <process> q;
        for (i=0;i<number;i++){
        a[i].waitingtime=0;
        a[i].emptyy1=0;
        a[i].emptyy2=0;
        a[i].executiontime=Array[i].servicetime;
    }
        for (i=0;i<tim;i++){
                for (j=0;j<number;j++){
                	
                    if (Array[j].arrivaltime<=finish && Array[j].remainingtime>0){
                    q1.push({Array[j].process,Array[j].arrivaltime,Array[j].servicetime,Array[j].remainingtime});
                    }
                }
                    finish++;
                    x=q1.top(); //to get the top of the priority queue
                    k=returnindex(Array,number,x);
                    Array[k].remainingtime--;
                    x.remainingtime--;
                    if (Array[k].remainingtime==0){
                        finisharray[k]=finish;
                    }
                    q.push({x.process,x.arrivaltime,x.servicetime,x.remainingtime});
                    a[i].process=x.process;
                    while (!q1.empty()){
                        q1.pop();
                    }
                   
        }
    i=0;
    while (!q.empty()){
        x=q.front();
       a[i].process=x.process;
        q.pop();
        i++;
    }
    sort(Array,Array+number,compare);
    string name="SRT   ";
    if (flag==1){
    trace(a,Array,name);
    memset(a,0,tim);
    }
    else{
    name="SRT";
   stats(a,Array,finisharray,name);
    }

}


void FCFS(process Array[]){
// function sorts processes according to arrival time and places them in a queue
    int i;
    int x= number;
    queue<process>q;
    sort(Array,Array+x,compare);
        for (i=0;i<x;i++){
        q.push({Array[i].process,Array[i].arrivaltime,Array[i].servicetime});
    }
    //printFCFS computes arrival,finish,wait & readinness of each process
    printFCFS(q);
    }
void HRRN(process Array[], int sflag ){   // Done
    info a[number]; //array checks and calculates empty slots of each process & waiting time
    int i,j;
    for (i=0;i<number;i++){
        a[i].waitingtime=0;
        a[i].emptyy1=0;
        a[i].emptyy2=0;
        a[i].executiontime=0;
        a[i].arrivaltime=0;
        a[i].ratioo=0;
    }
    info arr[number];
    info x;
    int finish=0,count=0;
    sort(Array,Array+number,compare);
    queue <info> q;
    info x1;
    priority_queue <info, vector<info>, com2>q1; //ratio is calculated and prioritized in priority queue
    for (i=0;i<number;i++){
            if (Array[i].arrivaltime<=finish){
            for (j=i;j<number;j++){
                    if (Array[j].arrivaltime<=finish){
                    if (searchvalue1(arr,number,Array[j])==1){
                        continue;
                    }

                a[j].process=Array[j].process;
                a[j].arrivaltime=Array[j].arrivaltime;
                a[j].executiontime=Array[j].servicetime;
                a[j].waitingtime=finish-a[j].arrivaltime;
                a[j].ratioo=(a[j].waitingtime+a[j].executiontime)/a[j].executiontime;
                a[j].emptyy2=tim-finish;
                q1.push({a[j].process,a[j].waitingtime,a[j].executiontime,a[j].turnaround,a[j].ratioo,a[j].emptyy1,a[j].emptyy2,a[j].arrivaltime});

                    }
            }
             x=q1.top(); 
            q.push({x.process,x.waitingtime,x.executiontime,x.turnaround,x.ratioo,x.emptyy1,x.emptyy2,x.arrivaltime});
            arr[i]=x;
            while (!q1.empty()){
                q1.pop();
            }
           finish=finish+x.executiontime;
            }
        }

      for (i=0;i<number;i++){
        a[i].waitingtime=0;
        a[i].emptyy1=0;
        a[i].emptyy2=0;
        a[i].executiontime=0;
    }
     finish=0;
     count=0;
     //compute values of each process arrival time and wait and place them in info array
     //then call non_prememptive function to print or stats
    for (j=0;j<number;j++){
        x=q.front();
        q.pop();
        count=0;
        //cout << "\t";
        for (i=0;i<tim;i++){
            if (i>=x.arrivaltime && i<finish){
                //cout << "|."; //entered el ready queue
                a[j].process=x.process;
                a[j].waitingtime++;
                a[j].arrivaltime=x.arrivaltime;
            }
            else if (i>=finish && count<x.executiontime){
                //dor el process el gayya
                count++;
                //cout << "|*";
                a[j].process=x.process;
                a[j].executiontime++;
                a[j].arrivaltime=x.arrivaltime;
            }
            else {
               // cout << "| ";
               if (i<x.arrivaltime){
                 a[j].emptyy1++;
               }
               else{
                 a[j].emptyy2++;
               }
                a[j].process=x.process;
                a[j].arrivaltime=x.arrivaltime;
            }
        }
        finish=finish+x.executiontime;
    }
    sort(a,a+number,compare2);
    if (sflag==1){
    cout << "HRRN  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 \n";
    cout << "------------------------------------------------";
        print_non_preemptive(a);
        memset(a,0,tim);

}
 else {
    sort (Array,Array+number,compare);
    string name="HRRN";
    statsnonpreemptive(a,Array,name);
   // int i,j;
 }

}

void RR(process Array[], int quant, int sflag){
	//takes quantum specified at input
     int i,j;
     info a[tim];
       // memset(a,0,sizeof(a));
        sort (Array,Array+number,compare);
  vector<process> vect;
        int finish=0,count=0;
        int finisharray[number]; //computes finish time of each process
        process x;
        int k=0;
        int d=0;
        queue <process> q;
          queue <process> q1;
        for (i=0;i<number;i++){
        a[i].waitingtime=0;
        a[i].emptyy1=0;
        a[i].emptyy2=0;
        a[i].executiontime=Array[i].servicetime;
    }
         for (i=0;i<number;i++){
        finisharray[i]=0;
    }

     for (i=0;i<tim;i++){

                k=0;

                for (j=0;j<number;j++){

                 vector<process>::iterator flag = find(vect.begin(),vect.end(),Array[j]);
                    if (Array[j].arrivaltime <=i  && flag==vect.end()){
                    q1.push({Array[j].process,Array[j].arrivaltime,Array[j].servicetime,Array[j].remainingtime});
                    vect.insert(vect.begin(),Array[j]);
                    }
                    if (  Array[j].arrivaltime <= i+quant  && flag==vect.end()){
                         q1.push({Array[j].process,Array[j].arrivaltime,Array[j].servicetime,Array[j].remainingtime});
                     vect.insert(vect.begin(),Array[j]);
                    }
                }
                    x=q1.front();
                    q1.pop();
                     if (x.remainingtime < quant ){

                        while (k < x.remainingtime){
                         q.push({x.process,x.arrivaltime,x.servicetime,x.remainingtime});
                         k++;
                         i++;

                        }
                        i=i-1;
                        d=returnindex(Array,number,x);
                        finisharray[d]=i+1;
        
                        x.remainingtime=0;

                    }
                         else {


                        while (k<quant){
                            q.push({x.process,x.arrivaltime,x.servicetime,x.remainingtime});
                            x.remainingtime--;
                            k++;
                            i++;
                        }
                        i=i-1;
                        if (x.remainingtime==0){
                        d=returnindex(Array,number,x);
                        finisharray[d]=i+1;
                            continue;
                        }
                        else {
                        q1.push({x.process,x.arrivaltime,x.servicetime,x.remainingtime});
                        vect.insert(vect.begin(),x);
                        }
                    }
                      finish++;

                    }
    i=0;
    while (!q.empty()){
        x=q.front();
        q.pop();
        a[i].process=x.process;
        i++;
    }
    sort(Array,Array+number,compare);
    string name="RR-";
    stringstream ss;
    ss << quant;
    string str = ss.str();
    name.append(str);
    if (sflag==1){
    name=name+"  ";
        trace(a,Array,name);
    }
      else {
          stats(a,Array,finisharray,name);
      }
      memset(a,0,tim);


}

void feedback(process Array[],int sflag){
    int i,j;
    queue <process>q0,q1,q2,q3,q4,order; //5 regular queues are created to indicate level at which process is at
    process d;
    info a[tim];
    int finisharray[number]; //compute finish time of each process
    sort(Array,Array+number,compare);
    //memset(a,0,number);
    for (i=0;i<number;i++){
        a[i].waitingtime=0;
        a[i].emptyy1=0;
        a[i].emptyy2=0;
        a[i].executiontime=Array[i].servicetime;
    }
    int finish=0;
    int k;
    process x;
    int count=-1;
    bool insert=false;
    for (i=0;i<tim;i++){
            sort(Array,Array+number,compare3);
            //at each second, processes are sorted according to their levels and if they share the same level then the earliest arrival time has the higher priority
            count=-1;
            for (j=0;j<number;j++){

                if (Array[j].arrivaltime<=finish && Array[j].servicetime>=Array[j].remainingtime  && Array[j].level==0){
                Array[j].remainingtime--;
                finish++;
                for (k=0;k<number;k++){
                    if (Array[k].arrivaltime<=finish && Array[k].remainingtime>0){
                        count++;
                    }
                }
                if (count ==0){
                    Array[j].level=0;
                }
                else{
                    Array[j].level=1;
                }
                q0.push({Array[j].process,Array[j].arrivaltime,Array[j].servicetime,Array[j].remainingtime,Array[j].level});
                if (Array[j].remainingtime==0){
                    d=Array[j];
                    sort(Array,Array+number,compare);
                    k=returnindex(Array,number,d);
                    finisharray[k]=finish;
                }
                break;

                }
             else if (Array[j].remainingtime>0 && Array[j].level==1 && Array[j].arrivaltime<=finish){
                Array[j].remainingtime--;
                Array[j].level=2;
                finish++;
                q1.push({Array[j].process,Array[j].arrivaltime,Array[j].servicetime,Array[j].remainingtime,Array[j].level});
                if (Array[j].remainingtime==0){
                    d=Array[j];
                    sort(Array,Array+number,compare);
                    k=returnindex(Array,number,d);
                    finisharray[k]=finish;
                }
                break;
            }
            else if (Array[j].remainingtime>0 && Array[j].arrivaltime<=finish && Array[j].level==2){
                Array[j].remainingtime--;
                Array[j].level=3;
                q2.push({Array[j].process,Array[j].arrivaltime,Array[j].servicetime,Array[j].remainingtime,Array[j].level});
                finish++;
                if (Array[j].remainingtime==0){
                    d=Array[j];
                    sort(Array,Array+number,compare);
                    k=returnindex(Array,number,d);
                    finisharray[k]=finish;
                }
                break;
            }
            else if (Array[j].remainingtime>0 && Array[j].arrivaltime<=finish && Array[j].level==3){
                Array[j].remainingtime--;
                Array[j].level=4;
                q3.push({Array[j].process,Array[j].arrivaltime,Array[j].servicetime,Array[j].remainingtime,Array[j].level});
                finish++;
                if (Array[j].remainingtime==0){
                    d=Array[j];
                    sort(Array,Array+number,compare);
                    k=returnindex(Array,number,d);
                    finisharray[k]=finish;
                }
                break;
            }
            else if (Array[j].remainingtime>0 && Array[j].arrivaltime<=finish && Array[j].level==4){
                Array[j].remainingtime--;
                Array[j].level=5;
                q4.push({Array[j].process,Array[j].arrivaltime,Array[j].servicetime,Array[j].remainingtime,Array[j].level});
                finish++;
                if (Array[j].remainingtime==0){
                    d=Array[j];
                    sort(Array,Array+number,compare);
                    k=returnindex(Array,number,d);
                    finisharray[k]=finish;
                }
                break;

            }
            else if (Array[j].remainingtime>0 && Array[j].arrivaltime<=finish && Array[j].level==5){
                Array[j].remainingtime--;
                q4.push({Array[j].process,Array[j].arrivaltime,Array[j].servicetime,Array[j].remainingtime,Array[j].level});
                finish++;
                if (Array[j].remainingtime==0){
                    d=Array[j];
                    sort(Array,Array+number,compare);
                    k=returnindex(Array,number,d);
                    finisharray[k]=finish;
                }
                break;
            }

        }
        while (!q0.empty()){
            x=q0.front();
            order.push({x.process,x.arrivaltime,x.servicetime,x.remainingtime,x.level});
            q0.pop();
        }
        while (!q1.empty()){
            x=q1.front();
            order.push({x.process,x.arrivaltime,x.servicetime,x.remainingtime,x.level});
            q1.pop();
        }
        while (!q2.empty()){
            x=q2.front();
            order.push({x.process,x.arrivaltime,x.servicetime,x.remainingtime,x.level});
            q2.pop();
        }
        while (!q3.empty()){
            x=q3.front();
            order.push({x.process,x.arrivaltime,x.servicetime,x.remainingtime,x.level});
            q3.pop();
        }
        while (!q4.empty()){
            x=q4.front();
            order.push({x.process,x.arrivaltime,x.servicetime,x.remainingtime,x.level});
            q4.pop();
        }
    }
    sort(Array,Array+number,compare);
    i=0;
   while (!order.empty()){
        x=order.front();
        order.pop();
        a[i].process=x.process;
       // cout << "\n";
       // cout<< x.process;
        i++;
    }
    string name="FB-1";
    if (sflag==1){
    name=name+"  ";
    trace(a,Array,name);
    }
    else{
    stats(a,Array,finisharray,name);
    }
}

void feedback2i(process Array[],int sflag){
    int i,j;
    queue <process>q0,q1,q2,q3,q4,order;
    process d;
    info a[tim];
    sort(Array,Array+number,compare);
    memset(a,0,number);
    for (i=0;i<number;i++){
        a[i].executiontime=Array[i].servicetime;
    }
    int finisharray[number];
    int finish=0;
    int k;
    process x;
    int count=-1;
    bool insert=false;
    int counting=0;
    int quantum;
    for (i=0;i<tim;i++){
            sort(Array,Array+number,compare3);
            count=-1;
            quantum=0;
            counting=0;
            for (j=0;j<number;j++){

                if (Array[j].arrivaltime<=finish && Array[j].remainingtime>0  && Array[j].level==0){
                Array[j].remainingtime--;
                finish++;
                for (k=0;k<number;k++){
                    if (Array[k].arrivaltime<=finish && Array[k].remainingtime>0){
                        count++;
                    }
                }
                if (count ==0){
                    Array[j].level=0;
                }
                else{
                    Array[j].level=1;
                }
                q0.push({Array[j].process,Array[j].arrivaltime,Array[j].servicetime,Array[j].remainingtime,Array[j].level});
                  if (Array[j].remainingtime==0){
                    d=Array[j];
                    sort(Array,Array+number,compare);
                    k=returnindex(Array,5,d);
                    finisharray[k]=finish;
                }
                break;

                }
             else if (Array[j].remainingtime>0 && Array[j].level==1 && Array[j].arrivaltime<=finish){
                counting=0;
                quantum=2;
                while (Array[j].remainingtime>0 && quantum>0){
                    Array[j].remainingtime--;
                    counting++;
                    quantum--;
                }
                Array[j].level=2;
                finish+=counting;
                while(counting>0){
                q1.push({Array[j].process,Array[j].arrivaltime,Array[j].servicetime,Array[j].remainingtime,Array[j].level});
                counting--;
                }
                 if (Array[j].remainingtime==0){
                    d=Array[j];
                    sort(Array,Array+number,compare);
                    k=returnindex(Array,number,d);
                    finisharray[k]=finish;
                }
                break;
            }
            else if (Array[j].remainingtime>0 && Array[j].arrivaltime<=finish && Array[j].level==2){
                counting=0;
                quantum=4;
                while (Array[j].remainingtime>0 && quantum>0){
                Array[j].remainingtime--;
                counting++;
                quantum--;
                }
                Array[j].level=3;
                finish+=counting;
                while (counting>0){
                q2.push({Array[j].process,Array[j].arrivaltime,Array[j].servicetime,Array[j].remainingtime,Array[j].level});
                counting--;
                }
                  if (Array[j].remainingtime==0){
                    d=Array[j];
                    sort(Array,Array+number,compare);
                    k=returnindex(Array,number,d);
                    finisharray[k]=finish;
                }
                break;
            }
            else if (Array[j].remainingtime>0 && Array[j].arrivaltime<=finish && Array[j].level==3){
                counting=0;
                quantum=8;
                while (Array[j].remainingtime>0 && quantum>0){
                    Array[j].remainingtime--;
                    counting++;
                    quantum--;
                }
                finish+=counting;
                Array[j].level=4;
                while (counting>0){
                q3.push({Array[j].process,Array[j].arrivaltime,Array[j].servicetime,Array[j].remainingtime,Array[j].level});
                counting--;
                }
                  if (Array[j].remainingtime==0){
                    d=Array[j];
                    sort(Array,Array+number,compare);
                    k=returnindex(Array,number,d);
                    finisharray[k]=finish;
                }
                break;
            }
            else if (Array[j].remainingtime>0 && Array[j].arrivaltime<=finish && Array[j].level==4){
                counting=0;
                quantum=16;
                while (Array[j].remainingtime>0 && quantum>0){
                    Array[j].remainingtime--;
                    counting++;
                    quantum--;
                }
                finish+=counting;
                Array[j].level=5;
                while (counting>0){
                q4.push({Array[j].process,Array[j].arrivaltime,Array[j].servicetime,Array[j].remainingtime,Array[j].level});
                counting--;
                }
                  if (Array[j].remainingtime==0){
                    d=Array[j];
                    sort(Array,Array+number,compare);
                    k=returnindex(Array,number,d);
                    finisharray[k]=finish;
                }
                break;

            }
            else if (Array[j].remainingtime>0 && Array[j].arrivaltime<=finish && Array[j].level==5){
                counting=0;
                quantum=16;
                while (Array[j].remainingtime>0 && quantum>0){
                Array[j].remainingtime--;
                counting++;
                quantum--;
                }
                finish+=counting;
                while (counting>0){
                q4.push({Array[j].process,Array[j].arrivaltime,Array[j].servicetime,Array[j].remainingtime,Array[j].level});
                counting--;
                }
                  if (Array[j].remainingtime==0){
                    d=Array[j];
                    sort(Array,Array+number,compare);
                    k=returnindex(Array,number,d);
                    finisharray[k]=finish;
                }
                break;
            }

        }
        while (!q0.empty()){
            x=q0.front();
            order.push({x.process,x.arrivaltime,x.servicetime,x.remainingtime,x.level});
            q0.pop();
        }
        while (!q1.empty()){
            x=q1.front();
            order.push({x.process,x.arrivaltime,x.servicetime,x.remainingtime,x.level});
            q1.pop();
        }
        while (!q2.empty()){
            x=q2.front();
            order.push({x.process,x.arrivaltime,x.servicetime,x.remainingtime,x.level});
            q2.pop();
        }
        while (!q3.empty()){
            x=q3.front();
            order.push({x.process,x.arrivaltime,x.servicetime,x.remainingtime,x.level});
            q3.pop();
        }
        while (!q4.empty()){
            x=q4.front();
            order.push({x.process,x.arrivaltime,x.servicetime,x.remainingtime,x.level});
            q4.pop();
        }
    }
    sort(Array,Array+number,compare);
    i=0;
   while (!order.empty()){
        x=order.front();
        order.pop();
        a[i].process=x.process;
        i++;
    }
    string name="FB-2i";
    if (sflag==1){
    name=name+" ";
    trace(a,Array,name);
    }
    else{
    stats(a,Array,finisharray,name);
    }
}

void Aging(aging Array[], int quant){
	
        int i,j,k,h;
        int first=0;
        aging a[tim];
        aging test;
        int priorities[number]; //array to hold changing priorities of each process as it executes/waits
        sort (Array,Array+number,compare4);
        for (i=0;i<number;i++){
            priorities[i]=Array[i].priority;
        }
        vector<aging> vect;
        int finish=0,count=0;
        aging x;
        queue <aging> q;  
        queue <aging> q4; //output queue a.k.a order of execution
        int flag;
        aging x1;
        priority_queue <aging, vector<aging>, com4>q1;     //ready queue
        for (i=0;i<tim;i++){
                 for ( unsigned f=0;f<vect.size();f++){
                        if (vect.at(f).process==x.process){

                    }
                    else{
                  vect.at(f).priority++;

                  while (!q1.empty()){
                    q1.pop();
                }
                 for (unsigned b=0;b<vect.size();b++){
                        if (vect.at(b).process==x.process){
                            continue;
                        }
                        else{
                  q1.push({vect.at(b).process,vect.at(b).arrivaltime,vect.at(b).priority,vect.at(b).firstflag});
                }
                 }
                    }
                }
                if (i!=0){
                first=first+1;
                x.firstflag=first;
                q1.push({x.process,x.arrivaltime,x.priority,first});
                  for (unsigned p=0;p<vect.size();p++){
                 if (vect.at(p).process==x.process){
                    vect.at(p).firstflag=x.firstflag;
                 }
                }
                 vector<aging>::iterator flag = find(vect.begin(),vect.end(),x);
                 if (flag==vect.end()){
                     vect.insert(vect.begin(),x);
                 }
                }

                k=0;
                 for (j=0;j<number;j++){
                    vector<aging>::iterator flag = find(vect.begin(),vect.end(),Array[j]);
                    if (Array[j].arrivaltime <=i  && flag==vect.end()){
                  first=first+1;
                    Array[j].firstflag=first;
                    q1.push({Array[j].process,Array[j].arrivaltime,Array[j].priority,Array[j].firstflag});

                    vect.insert(vect.begin(),Array[j]);

                    }
                 }

                x=q1.top();
                q1.pop();
                while (k<quant){
                 q4.push({x.process,x.arrivaltime,x.priority,x.firstflag});
                 k++;
                 i++;
                }
                i=i-1;
                k=returnindex_aging(Array,number,x);
                Array[k].priority=priorities[k];
                x.priority=Array[k].priority;

                 for (unsigned t=0;t<vect.size();t++){
                 if (vect.at(t).process==x.process){
                    vect.at(t).priority=x.priority;
                 }
                }

                for (j=0;j<number;j++){
                     vector<aging>::iterator flag = find(vect.begin(),vect.end(),Array[j]);
                    if (  Array[j].arrivaltime <= i+quant  && flag==vect.end()){
                           first=first+1;
                    Array[j].firstflag=first;

                    q1.push({Array[j].process,Array[j].arrivaltime,Array[j].priority,Array[j].firstflag});
                    vect.insert(vect.begin(),Array[j]);
                    }
                }

                 }
        i=0;
    while (!q4.empty()){
        x=q4.front();
        q4.pop();
        a[i].process=x.process;
        i++;
    }
 cout << "Aging ";
    cout << "0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 \n";
    cout << "------------------------------------------------";
    int sum=0;
     flag=0;
    for (i=0;i<number;i++){
        sum=0;
        flag=0;
        cout << "\n";
        cout << Array[i].process;
        cout << "     ";
    for (j=0;j<tim;j++){
    if (Array[i].process==a[j].process){
        cout << "|*";
        sum ++;
        flag =1 ;
    }
    else if (flag==1){


            cout << "|.";

    }
        else {
                if (Array[i].arrivaltime<=j){
                    cout << "|.";
                }
                else {
            cout << "| ";
                }
        }
    }
    cout << "| ";
    }
    cout << "\n";
    cout << "------------------------------------------------";
 cout << "\n\n";
}

int main()
{
    int i;
    int flag;
    char input[100];
    cin.getline(input,100);
    char *point=strtok(input,"\n");
    if(strcmp(point,"trace")==0){
        flag=1;
    }
    else{
        flag=0;
    }

    int policy[28];
    int quantum[28];
    int k=0;
    int j;
    string policies;
    cin.getline(input,100);
    point=strtok(input,"\n");
    stringstream ss(input);
    while(getline(ss,policies,',')){
        policy[k]=policies[0]-'0';
        if (policies[1]=='-'){
            quantum[k]=policies[2]-'0';
        }
        else {
            quantum[k]=0;
        }
        k++;
    }
 

    cin.getline(input,100);
    point=strtok(input,"\n");
    tim=atoi(point);

    cin.getline(input,100);
    point=strtok(input,"\n");
    number=atoi(point);
    process Array[number];
    aging Agingarr[number];
    for(i=0;i<number;i++){
        cin.getline(input,100);
        point=strtok(input,",");
        Agingarr[i].process=Array[i].process=point[0];
        point=strtok(NULL,",");
        Agingarr[i].arrivaltime=Array[i].arrivaltime=atoi(point);
        point=strtok(NULL,"\n");
        Agingarr[i].priority=Array[i].servicetime=Array[i].remainingtime=atoi(point);
        Array[i].level=0;
        Agingarr[i].firstflag=0;
    }
    int d=0;
    while (k>=1){
    switch(policy[d]){
    case 1:
        if (flag==1){
            FCFS(Array);
            k--;
            d++;
        }
        else{
            FCFSstat(Array);
            k--;
            d++;
        }
        break;
    case 2:
    	for(i=0;i<number;i++){
    		Array[i].remainingtime=Array[i].servicetime;
    	}
        RR(Array,quantum[d],flag);
        k--;
        d++;
        break;
    case 3:
    	for(i=0;i<number;i++){
    		Array[i].remainingtime=Array[i].servicetime;
    	}
        SPN(Array,flag);
        k--;
        d++;
        break;
    case 4:
    	for(i=0;i<number;i++){
    		Array[i].remainingtime=Array[i].servicetime;
    	}
        SRT(Array,flag);
        k--;
        d++;
        break;
    case 5:
    	for(i=0;i<number;i++){
    		Array[i].remainingtime=Array[i].servicetime;
    	}
        HRRN(Array,flag);
        k--;
        d++;
        break;
    case 6:
   	 for(i=0;i<number;i++){
    		Array[i].remainingtime=Array[i].servicetime;
    		Array[i].level=0;
    	}
        feedback(Array,flag);
        k--;
        d++;
        break;
    case 7:
    	for(i=0;i<number;i++){
    		Array[i].remainingtime=Array[i].servicetime;
    		Array[i].level=0;
    	}
        feedback2i(Array,flag);
        d++;
        k--;
        break;
    case 8:
    	Aging(Agingarr,quantum[d]);
    	k--;
    	d++;
    	break;
    }
    }
    return 0;
}

