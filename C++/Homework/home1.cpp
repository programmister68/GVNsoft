#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

int push (int arrq[], int longq, int ranks) {
    arrq [longq]=ranks;
    int k=longq;
    for (k; k>0; k) {
        if (arrq[k]<arrq[(k-1)/2]) {
            swap (arrq[k], arrq[(k-1)/2]);
            k-=1;
            k/=2;
        }
        else break;
    }
}

int cut (int arrq[], int longq, int a) {
    swap (arrq[a], arrq[longq]);
    longq--;
    for (a; a>=0; a) {
        if  (longq>=(a*2)+1 and longq>=(a*2)+2) {
            if (arrq[(a*2)+1]<=arrq[(a*2)+2]) {
                if (arrq[a]>=arrq[(a*2)+1]) {
                    swap (arrq[a], arrq[(a*2)+1]);
                    a*=2;
                    a+=1;
                    }
                else break;
            }
            else {
                if (arrq[a]>=arrq[(a*2)+2]) {
                    swap (arrq[a], arrq[(a*2)+2]);
                    a*=2;
                    a+=2;
                }
                else break;
            }
        }
        else {
            if (longq>(a*2)+1) break;
            else {
                if (arrq[a]>=arrq[(a*2)+1]) {
                    swap (arrq[a], arrq[(a*2)+1]);
                    break;
                }
            else break;
            }
        }
    }
}


int main()
{
    setlocale (LC_ALL, "rus");
    SetConsoleCP (1251) ;
    SetConsoleOutputCP (1251);
    srand (time(0));
    int size=10000;
    int *arrq = new int [size];
    int longq=-1, served, allvipqueue=0, allmidqueue=0, alllowqueue=0, servedbefore=0, n=1, timevip=0, timelow=0, timemid=0, timework=0, timeserved=0, rejectionmid=0, rejectionlow=0, skippedlow=0, skippedmid=0, dts1, dts2, dtv1, dtv2, dtl1, dtl2, dtm1, dtm2;
    for (int k=0; k<size; k++) arrq[k]=100;
    string change;
for (int g=1; g>0; g) {
    cout << "введите диапазон времени обслуживания клиентов - ";
    cin >> dts1 >> dts2;
    dts2++;
    dts2-=dts1;
    cout << "dipazone time vip - ";
    cin >> dtv1 >> dtv2;
    dtv2++;
    dtv2-=dtv1;
    cout << "dipazone time mid - ";
    cin >> dtm1 >> dtm2;
    dtm2++;
    dtm2-=dtm1;
    cout << "dipazone time low - ";
    cin >> dtl1 >> dtl2;
    dtl2++;
    dtl2-=dtl1;
    cout << "Изменить текущие данные? (да, нет)  ";
    for (int i=1; i>0; i) {
        cin >> change;
        if (change=="да" or change=="нет" or change=="yes" or change=="no") break;
        else cout << "вы ввели неверное слово, введите да или нет ";
    }

    if (change=="нет" or change=="no") break;

    if (change=="да" or change=="yes") system ("cls");
}
    for (served=0; served<1001; served) {
        size=10000+longq;
        if (servedbefore!=arrq[0] and timeserved!=0) {
            if (servedbefore==3) {rejectionlow++; timeserved=0;}
            if (servedbefore==2) {rejectionmid++; timeserved=0;}
        }
        if (timeserved==0 and (arrq[0]==1 or arrq[0]==2 or arrq[0]==3))
            timeserved=dts1+rand()%dts2;
        for (int s=1; s<=longq; s++) {
            if (arrq[s]==1) allvipqueue++;
            if (arrq[s]==2) allmidqueue++;
            if (arrq[s]==3) alllowqueue++;
        }
        if (rejectionlow%3==0 and rejectionlow!=0)  {
            skippedlow++;
            rejectionlow-=3;
            for (int s=0; s<=longq; s++) {
                if (arrq[s]==3) {
                    cut (arrq, longq, s);
                }
            }
            arrq[longq]=100;
            longq--;
        }
        if (rejectionmid%3==0  and rejectionmid!=0) {
            skippedmid++;
            rejectionmid-=3;
            for (int s=0; s<=longq; s++) {
                if (arrq[s]==3) {
                    cut (arrq, longq, s);
                }
            }
            arrq[longq]=100;
            longq--;
        }
        if (served/n==100) {
            int totaltime;
            totaltime=allvipqueue+allmidqueue+alllowqueue;
            int clients;
            clients=(n*100)+longq+1;
            n++;
            cout << "avg ppl in queue - " << totaltime/(float)timework << endl;
            cout << "avg VIP in queue - " << allvipqueue/(float)timework << endl;
            cout << "avg mid in queue - " << allmidqueue/(float)timework << endl;
            cout << "avg low in queue - " << alllowqueue/(float)timework << endl;
            cout << "avg waiting time - " << totaltime/(float)clients << endl;
            cout << "served - " << served << endl;
            cout << "amout of skipped clients - " << skippedlow+skippedmid << endl;
            cout << "amout of skipped mid - " << skippedmid << endl;
            cout << "amout skipped low - " << skippedlow << endl;
            cout << "all clients - " << clients << endl;
            cout << "working time - " << timework << endl << endl << endl;
        }
        if (arrq[0]==1 or arrq[0]==2 or arrq[0]==3) timeserved--;
        if (timeserved==0 and (arrq[0]==1 or arrq[0]==2 or arrq[0]==3)) {
            served++;
            cut (arrq, longq, 0);
            longq--;
        }
        timework++;
        servedbefore=arrq[0];
        if (timevip==0) {timevip=dtv1+rand()%dtv2;}
        timevip--;
        if (timevip==0) {longq++; push (arrq, longq, 1);}
        if (timemid==0) timemid=dtm1+rand()%dtm2;
        timemid--;
        if (timemid==0) {longq++; push (arrq, longq, 2);}
        if (timelow==0) timelow=dtl1+rand()%dtl1;
        timelow--;
        if (timelow==0) {longq++; push (arrq, longq, 3);}
    }
    delete [] arrq;
    return 0;
}
