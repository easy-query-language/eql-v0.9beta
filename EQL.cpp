#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <direct.h>
#include <stdlib.h>

using namespace std;

class EQL
{
private:
    char table[200][200][50];char tem[50];char c[100], rw[100], cl[100], str[50]; int row, col, nvar;char d[100], e[100], rwd[100], cld[100], rwe[100], cle[100];
public:
    int gtt1; long gtt2; double gtt3;char gtt4[50]; int nrow, ncol;char spc[20];
    void crt__dat(char var[100])
    {
        mkdir("C:/EQL");
        mkdir("C:/EQL/Projects");
        strcpy(c,"C:/EQL/Projects/");
        strcat(c,var);
        mkdir(c);
    }
    void crt__tab(char var[100],int ro,int co)
    {
        strcat(c,"/");
        strcat(c,var);
        strcpy(rw,c);
        strcpy(cl,c);
        strcat(c,".dat");
        strcat(rw,".row");
        strcat(cl,".col");
        ofstream outfile(c);
        ofstream outrow(rw);
        ofstream outcol(cl);
        row=ro;col=co;
        outrow<<row;
        outcol<<col;
        cout<<endl;
        for(int i=0;i<row;i++)
        {
            for(int j=-1;j<col;j++)
            {
                if(j>=0)
                {
                    cout<<"Enter data at ("<<i<<","<<j<<"): ";
                }
                if(j>=0)
                {
                    gets(str);
                }
                else if(i==0 && j==-1)
                {
                    gets(str);
                }
                if(j>=0)
                {
                    strcpy(table[i][j],str);
                    outfile<<table[i][j]<<endl;
                }
            }

        }
    }
    void opn__dat(char var[100])
    {
        strcpy(c,"C:/EQL/Projects/");
        strcat(c,var);
    }
    void opn__tab(char var[100])
    {
        row=0; col=0;int q=0;
        strcat(c,"/");
        strcat(c,var);
        strcpy(rw,c);
        strcpy(cl,c);
        strcat(c,".dat");
        strcat(rw,".row");
        strcat(cl,".col");
        ifstream infile(c);
        ifstream inrow(rw);
        ifstream incol(cl);
        inrow>>row;incol>>col;
        if(row==0||col==0)
        {
            cout<<"Error opening table\n";
        }
        else
        {
            for(int i=0;i<row;i++)
            {
                for (int j=0;j<col;j++)
                {
                    infile.getline(table[i][j],50,'\n');
                }
            }
            for(int i=0;i<col;i++)
            {
                for (int j=0;j<row;j++)
                {
                    int z=strlen(table[j][i]);
                    char b[10];
                    if(z>q)
                    {
                        q=z;
                        itoa(q,b,10);
                        strcpy(spc,"");
                        strcpy(spc,"%-");
                        strcat(spc,b);
                        strcat(spc,"s");
                    }
                }
            }
            for(int i=0;i<row;i++)
            {
                cout<<"|";
                for (int j=0;j<col;j++)
                {
                    printf(spc,table[i][j]);
                    cout<<"|";
                }
                cout<<endl;
            }
            cout<<"Table opened\n";
        }
    }
    void del__dat(char var[100])
    {
        strcpy(c,"C:/EQL/Projects/");
        strcat(c,var);
        rmdir (c);
    }
    void del__tab(char var[100])
    {
        strcat(c,"/");
        strcat(c,var);
        strcpy(rw,c);
        strcpy(cl,c);
        strcat(c,".dat");
        strcat(rw,".row");
        strcat(cl,".col");
        remove (c);
        remove (rw);
        remove (cl);
    }
    void add__row(char var[100])
    {
        ofstream outfile(c);
        ofstream outrow(rw);
        nvar = atoi(var);nrow= row+nvar;
        outrow<<nrow;
        for(int i=0;i<nrow;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i<row)
                {
                        outfile<<table[i][j]<<endl;
                }
                else
                {
                        cout<<"Enter data at ("<<i<<","<<j<<"): ";
                        gets(str);
                        strcpy(table[i][j],str);
                        outfile<<table[i][j]<<endl;
                }
            }
        }
    }
    void add__col(char var[100])
    {
        ofstream outfile(c);
        ofstream outcol(cl);
        nvar = atoi(var);ncol=col+nvar;
        outcol<<ncol;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<ncol;j++)
            {
                if(j<col)
                {
                        outfile<<table[i][j]<<endl;
                }
                else
                {
                    cout<<"Enter data at ("<<i<<","<<j<<"): ";
                    gets(str);
                    strcpy(table[i][j],str);
                    outfile<<table[i][j]<<endl;
                }
            }
        }
    }
    void del__row(char var[100])
    {
        ofstream outfile(c);
        ofstream outrow(rw);
        nvar = atoi(var);int nrow=row-1;
        outrow<<nrow;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i!=nvar)
                {
                    outfile<<table[i][j]<<endl;
                }
            }
        }
    }
    void del__col(char var[100])
    {
        ofstream outfile(c);
        ofstream outcol(cl);
        nvar = atoi(var);int ncol=col-1;
        outcol<<ncol;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(j!=nvar)
                {
                    outfile<<table[i][j]<<endl;
                }
            }
        }
    }
    void upd__cel(char var[100],char v3[50])
    {
        ofstream outfile(c);
        char v1[100], v2[100];
        for(int i=0; i<100; i++)
        {
            if(var[i]==',')
            {
                strncpy(v1,var,i);
                strncpy(v2,var+i+1,100-i-1);
            }
        }
        int i,j;
        i=atoi(v1); j=atoi(v2);
        strcpy(table[i][j],v3);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                outfile<<table[i][j]<<endl;
            }
        }
    }
    void dt__find(char var[100])
    {
        cout<<"Found "<<"'"<<var<<"'"<<" at:  ";
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<col;j++)
            {
                if(strcmp(table[i][j],var)==0)
                {
                    cout<<"("<<i<<","<<j<<")  ";
                }
            }
        }
        cout<<endl;
    }
    void dt__rplc(char var[100])
    {
        ofstream outfile(c);
        char v1[100], v2[100];
        for(int i=0; i<100; i++)
        {
            if(var[i]==',')
            {
                strncpy(v1,var,i);
                strncpy(v2,var+i+1,100-i-1);
            }
        }
        dt__find(v1);
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<col;j++)
            {
                if(strcmp(table[i][j],v1)==0)
                {
                    strcpy(table[i][j],v2);
                }
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                outfile<<table[i][j]<<endl;
            }
        }
    }
    void srt__asc(char var[100])
    {
        ofstream outfile(c);
        nvar=atoi(var);
        for(int m=1;m<row;m++)
        {
        for (int k=0;k<row;k++)
        {
            if(strcmp(table[k][nvar],table[m][nvar])>0)
            {
                for(int l=0;l<col;l++)
                {
                    strcpy(tem,table[m][l]);
                    strcpy(table[m][l],table[k][l]);
                    strcpy(table[k][l],tem);
                }
            }
        }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                outfile<<table[i][j]<<endl;
            }
        }
    }
    void srt__dsc(char var[100])
    {
        ofstream outfile(c);
        nvar=atoi(var);
        for(int m=1;m<row;m++)
        {
        for (int k=0;k<row;k++)
        {
            if(strcmp(table[k][nvar],table[m][nvar])<0)
            {
                for(int l=0;l<col;l++)
                {
                    strcpy(tem,table[m][l]);
                    strcpy(table[m][l],table[k][l]);
                    strcpy(table[k][l],tem);
                }
            }
        }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                outfile<<table[i][j]<<endl;
            }
        }
    }
    int col__sum(char var[100])
    {
        nvar=atoi(var); int tot=0;
        for (int i=0;i<row;i++)
        {
            tot=tot+atoi(table[i][nvar]);
        }
        return tot;
    }
    void get__dtt(char var[100],char v4[100])
    {
        ofstream outfile(c);
        char v1[100], v2[100];
        for(int i=0; i<100; i++)
        {
            if(var[i]==',')
            {
                strncpy(v1,var,i);
                strncpy(v2,var+i+1,100-i-1);
            }
        }
        int i,j;
        i=atoi(v1); j=atoi(v2);
        if(strcmp(v4,"int")==0)
        {
            gtt1=atoi(table[i][j]);
        }
        else if(strcmp(v4,"long")==0)
        {
            gtt2=atol(table[i][j]);
        }
        else if(strcmp(v4,"double")==0)
        {
            gtt3=atof(table[i][j]);
        }
        else if(strcmp(v4,"string")==0)
        {
            strcpy(gtt4,table[i][j]);
        }
    }
    void mrg__tab(char var[100], char uid[50], char name[100])
    {
        char v1[100], v2[100]; int u=0;
        for(int i=0; i<100; i++)
        {
            if(var[i]==',')
            {
                strncpy(v1,var,i);
                strncpy(v2,var+i+1,100-i-1);
            }
        }
        strcpy(d,"C:/EQL/Projects/");
        strcat(d,v1);
        strcat(d,"/");
        strcpy(e,d);
        strcat(d,v2);
        strcat(e,name);
        strcpy(rwd,d);
        strcpy(cld,d);
        strcpy(rwe,e);
        strcpy(cle,e);
        strcat(d,".dat");
        strcat(rwd,".row");
        strcat(cld,".col");
        strcat(e,".dat");
        strcat(rwe,".row");
        strcat(cle,".col");
        ifstream id(d);
        ifstream rd(rwd);
        ifstream cd(cld);
        rd>>nrow;cd>>ncol;
        if(nrow==row)
        {
            ncol=ncol+col;
            for(int i=0;i<row;i++)
            {
                for(int j=col;j<ncol;j++)
                {
                    id.getline(table[i][j],50,'\n');
                }
            }
            for (int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    for(int k=col;k<ncol;k++)
                    {
                        if(strcmp(table[0][j],uid)==0)
                        {
                            if(strcmp(table[0][k],uid)==0)
                            {
                                if(strcmp(table[i][j],table[i][k])==0)
                                {
                                    u=k;
                                }
                                else{u=-1;break;}
                            }
                        }
                    }
                }
            }
            if(u>=0)
            {
                ncol=ncol-1;
                ofstream oe(e);
                ofstream re(rwe);
                ofstream ce(cle);
                re<<row;ce<<ncol;
                for(int i=0;i<row;i++)
                {
                    for(int j=0;j<(ncol+1);j++)
                    {
                        if(j!=u)
                        {
                            oe<<table[i][j]<<endl;
                        }
                    }
                }
                cout<<"Tables merged\n";
            }
            else
            {
                cout<<"Incompatible table types\n";
            }
        }
        else
        {
            cout<<"Incompatible table types\n";
        }
    }
};
int main()
{
    cout<<"\n(c) 2018 Soujatya Sarkar via MIT License. Welcome to EASY QUERY LANGUAGE (EQL) v0.9 Beta.\n\n\n";
    for(;;)
    {
        EQL obj;
        char com[100], str[50]; int x; int row,col; char table[200][200][50];
        char var[100], cod[100], v3[50];
        system("Title EQL");
        system("Color F0");
        cout<<"EQL>> ";
        gets(com);
        if(strcmp(com,"exit__sys")==0)
        {
            cout<<"\nEQL Console Terminated.\n\nPress any key to exit.....\n";
            cin.get();
            break;
        }
        else if(strcmp(com,"license")==0)
        {
            cout<<"\nEASY QUERY LANGUAGE v0.9 Beta License Statement (MIT License)\n\nCopyright (c) 2018 Soujatya Sarkar\n\nPermission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the 'Software'), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, but not sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:\n\nThe above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.\n\nTHE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.\n\n";
            continue;
        }
        strncpy(cod,com,8);
        strncpy(var,com+9,91);
        if(strcmp(cod,"crt__dat")==0)
        {
            obj.crt__dat(var);
            cout<<"Database created\n";
        }
        else if(strcmp(cod,"crt__tab")==0)
        {
            cout<<"Enter no. of rows: ";
            cin>>row;
            cout<<"Enter no. of columns: ";
            cin>>col;
            obj.crt__tab(var,row,col);
            cout<<"Table created\n";
        }
        else if(strcmp(cod,"opn__dat")==0)
        {
            obj.opn__dat(var);
            cout<<"Database opened\n";
        }
        else if(strcmp(cod,"opn__tab")==0)
        {
            obj.opn__tab(var);
        }
        else if(strcmp(cod,"del__tab")==0)
        {
            obj.del__tab(var);
            cout<<"Table deleted\n";
        }
        else if(strcmp(cod,"del__dat")==0)
        {
            obj.del__dat(var);
            cout<<"Database deleted\n";
        }
        else if(strcmp(cod,"add__row")==0)
        {
            obj.add__row(var);
            cout<<"Rows added\n";
        }
        else if(strcmp(cod,"add__col")==0)
        {
            obj.add__col(var);
            cout<<"Columns added\n";
        }
        else if(strcmp(cod,"del__row")==0)
        {
            obj.del__row(var);
            cout<<"Row deleted\n";
        }
        else if(strcmp(cod,"del__col")==0)
        {
            obj.del__col(var);
            cout<<"Column deleted\n";
        }
        else if(strcmp(cod,"upd__cel")==0)
        {
            cout<<"Enter new data:";
            gets(v3);
            obj.upd__cel(var,v3);
            cout<<"Cell updated\n";
        }
        else if(strcmp(cod,"dt__find")==0)
        {
            obj.dt__find(var);
            cout<<"Data positions found\n";
        }
        else if(strcmp(cod,"dt__rplc")==0)
        {
            obj.dt__rplc(var);
            cout<<"Data replaced at found positions\n";
        }
        else if(strcmp(cod,"srt__asc")==0)
        {
            obj.srt__asc(var);
            cout<<"Table Sorted\n";
        }
        else if(strcmp(cod,"srt__dsc")==0)
        {
            obj.srt__dsc(var);
            cout<<"Table Sorted\n";
        }
        else if(strcmp(cod,"col__sum")==0)
        {
            x=obj.col__sum(var);
            cout<<"Sum :"<<x<<"\n";
            cout<<"Column Sum done\n";
        }
        else if(strcmp(cod,"get__dtt")==0)
        {
            char v4[100];
            cout<<"Enter data type:";
            gets(v4);
            obj.get__dtt(var,v4);
            if(strcmp(v4,"int")==0)
            {
                cout<<obj.gtt1<<endl;
            }
            else if(strcmp(v4,"long")==0)
            {
                cout<<obj.gtt2<<endl;
            }
            else if(strcmp(v4,"double")==0)
            {
                cout<<obj.gtt3<<endl;
            }
            else if(strcmp(v4,"string")==0)
            {
                cout<<obj.gtt4<<endl;
            }
        }
        else if(strcmp(cod,"mrg__tab")==0)
        {
            char uid[50]; char name[50];
            cout<<"Enter unique column: ";gets(uid);
            cout<<"Enter name of new file: ";gets(name);
            obj.mrg__tab(var,uid,name);
        }
        else
        {
            cout<<"Enter correct syntax\n";
            cout<<"Interpretation Error occurred\n";
        }
    }
    return 0;
}
