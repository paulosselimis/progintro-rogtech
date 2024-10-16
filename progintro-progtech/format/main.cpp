#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int i=0, j=0, sum=0, avg=0, aken=0, bken=0, kensum=0, rest=0, A, x=0, m=0, words;
    char c[100000][20], a;

 while (true)
    {
        a=getchar();
        if (a==EOF){
            break;
        }

       else if (a==' ' || a=='\t' || a=='\n')
        {
            if (j==0){
                i--;
            }
            i++;
            j=0;
        }
        else{
            c[i][j] = a;
            j++;
                }
    }

    words=i;
    i=0;
    while (m<words)
    {

        sum=avg=aken=kensum=rest=bken=0;

    while (true)
        {
            sum+=strlen(c[i]);
            if (sum<=60)
            {
                sum++;
                i++;
            }
            else{
                    break;
            }
        }

        for (int t=m+1;t<i-1;t++)
        {
            kensum+=strlen(c[t]);
        }
        avg=60-strlen(c[m])-strlen(c[i-1]);
        bken=i-m-1;
        aken=avg-kensum;
        rest=aken-bken;
        if (rest==0)
        {
            if (m==words-1)
            {
                cout<<c[m]<<endl;
                return 0;
            }
            else{
                cout<<c[m]<<" ";
            }
            for (int t=m+1;t<i-1;t++)
            {
                if (t==words-1)
                {
                    cout<<c[t]<<endl;
                    return 0;
                }
                else
                    cout<<c[t]<<" ";
            }
            cout<<c[i-1]<<endl;
        }
        else
        {
            x=rest/bken;
              A=rest%bken;
            if (x==0)
            {
                x=rest%bken;
                if (m==words-1)
                {
                    cout<<c[m]<<endl;
                    return 0;
                }
                else{
                    cout<<c[m]<<" ";
                }
                for (int t=m+1;t<i-1-x;t++)
                {
                    if (t==words-1)
                    {
                        cout<<c[t]<<endl;
                        return 0;
                    }
                    else{
                         cout<<c[t]<<" ";
                    }
                }

                for (int t=i-1-x;t<i-1;t++)
                {
                    if (t==words-1)
                    {
                        cout<<c[t]<<endl;
                        return 0;
                    }
                    else{
                        cout<<c[t]<<" "<<" ";
                    }
                }
                cout<<c[i-1]<<endl;
            }
            else if (x!=0)
            {
                if (m==words-1)
                {
                    cout<<c[m]<<endl;
                    return 0;
                }
                else{
                    cout<<c[m];
                    for(int u=0;u<x+1;u++){
                                 cout<<" ";
                     }

                }
                for (int t=m+1;t<i-1-A;t++)
                {
                    if (t==words-1)
                    {
                        cout<<c[t]<<endl;
                        return 0;
                    }
                    else{
                        cout<<c[t];
                     for(int u=0;u<x+1;u++){
                                 cout<<" ";
                     }
                    }
                }
                for (int t=i-1-A;t<i-1;t++)
                {
                    if (t==words-1)
                    {
                        cout<<c[t]<<endl;
                        return 0;
                    }
                    else{
                        cout<<c[t];
                     for(int u=0;u<x+2;u++){
                                 cout<<" ";
                     }
                    }
                }
                cout<<c[i-1]<<endl;
            }
        }
    m=i;
    }
    return 0;
}
