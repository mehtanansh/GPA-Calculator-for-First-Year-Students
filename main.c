#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Here are the Prototypes of the functions (Some functions are used directly as no values were passed)
int GP(int);
float CGPI_Calculations(int);
float SGPI_Calculations(int,int);
float YPI_Calculations();

//This is a Common Structure defined for the whole program
struct Details{
    char Name[100];
    long int Roll_No;
    long int Seat_No;
    int Branch;
    int sem;
    int group;
    int CA_Marks;
    int ESE_Marks;
    int TW_Marks;
    int Lab_TW_Marks;
    int Lab_Orals;
    }STD1;


//The main program is the body and the soul of the code
int main()
{
    fflush(stdin);
    system("cls");
    float QTR,STR,PTR;
    int IP,y,Co;
    printf("!!!!!!!!!*******POINTER CALCULATOR FOR F.Y.B.Tech STUDENTS studying in KJSCE*******!!!!!!!!!\n\n");
    printf("Name of the Student:\n");
    gets(STD1.Name);
    printf("\nRoll Number:\n");
    scanf("%ld", &STD1.Roll_No);
    printf("\nSeat Number:\n");
    scanf("%ld", &STD1.Seat_No);
    printf("\n!!\n*****\nWhile entering the branch Press:\n1: Computer Engineering\n2: Electronics Engineering\n3: Electronics & Telecommunication Engineering\n4: Information and Technology Engineering\n5: Mechanical Engineering\n*****\n!!\n\n");
    printf("Branch:\n");
    scanf("%d", &STD1.Branch);
    here:printf("\nPlease Select an option from the following menu:\n");
    printf("1 :- For Calculating SGPI(Semester Grade Pointer Index)\n");
    printf("2 :- For Calculating CGPI(Cumulative Grade Pointer Index)\n");
    printf("3 :- For Calculating YPI(Yearly Performance Index)\n");
    printf("4 :- For Viewing the Criteria for allotting Grade Points\n");
    printf("5 :- For Exiting the program\n");
    scanf("%d", &IP);
    {
        if(IP==1)
            {
                LOL: printf("Enter the Semester Number:\n!!**Note: This Calculator is for First Year Students so Semester 1 and 2 should only be entered.**!!\n");
                scanf("%d", &STD1.sem);
                {
                    if (STD1.sem==1 || STD1.sem==2)
                   {
                    goto READ;
                   }
                else
                   {
                    printf("Please Read the note carefully!\n");
                    goto LOL;
                   }
                }
                READ: printf("\n!!\n*****\nWhile entering the group Press:\n0: C-Group\n1: P-Group\n*****\n!!\n\n");
                printf("Group: \n");
                scanf("%d", &STD1.group);
                STR=SGPI_Calculations(STD1.group,STD1.sem);
                printf("The SGPI achieved by %s (Roll No.:%ld) is %f", STD1.Name,STD1.Roll_No,STR);
                printf("\n\nDo You want to continue ?\nIf Yes Press 0\nIf No Press any Number.\n");
                scanf("%d", &Co);
                {
                    if (Co==0)
                    {
                     goto here;
                    }
                    else
                    {
                        printf("Made By Roll Numbers: 1814090 & 1814105 as a Mini-Project.\nThankYou For Using This Calculator.\n");
                        exit (0);
                    }
                }
            }

        else if (IP==2)
            {
                printf("Enter the number of Semesters for which you want to calculate the CGPI:\n");
                scanf("%d", &y);
                QTR=CGPI_Calculations(y);
                printf("The CGPI achieved by %s (Roll No.: %ld) through-out %d semesters is: %f", STD1.Name, STD1.Roll_No, y, QTR);
                printf("\n\nDo You want to continue ?\nIf Yes Press 0\nIf No Press any Number.\n");
                scanf("%d", &Co);
                {
                    if (Co==0)
                    {
                     goto here;
                    }
                    else
                    {
                        printf("Made By Roll Numbers: 1814090 & 1814105 as a Mini-Project.\nThankYou For Using This Calculator.\n");
                        exit (0);
                    }
                }
            }

        else if(IP==3)
            {
                PTR=YPI_Calculations();
                printf("The YPI achieved by %s (Roll No.: %ld) is: %f", STD1.Name, STD1.Roll_No, PTR);
                printf("\n\nDo You want to continue ?\nIf Yes Press 0\nIf No Press any Number.\n");
                scanf("%d", &Co);
                {
                    if (Co==0)
                    {
                        goto here;
                    }
                    else
                    {
                        printf("Made By Roll Numbers: 1814090 & 1814105 as a Mini-Project.\nThankYou For Using This Calculator.\n");
                        exit (0);
                    }
                }
            }
        else if(IP==4)
            {
            criteria();
            printf("\n\nDo You want to continue ?\nIf Yes Press 0\nIf No Press any Number.\n");
                scanf("%d", &Co);
                {
                    if (Co==0)
                    {
                     goto here;
                    }
                    else
                    {
                        printf("Made By Roll Numbers: 1814090 & 1814105 as a Mini-Project.\nThankYou For Using This Calculator.\n");
                        exit (0);
                    }
                }

            }
        else if (IP==5)
            {
                exit(0);
            }

        else
            {
                printf("Enter a valid Number");
                goto here;
            }
    }
    return 0;

}


//The Function YPI_Calculations is defined to calculate YPI(Yearly Performance Index)
float YPI_Calculations()
{
    system ("cls");
    float SGPI_1,SGPI_2,YPI;
    printf("Enter the SGPI achieved in Semester 1:\n");
    scanf("%f", &SGPI_1);
    printf("Enter the SGPI achieved in Semester 2:\n");
    scanf("%f", &SGPI_2);
    YPI=(SGPI_1+SGPI_2)/2;
    return YPI;
}


//The Function SGPI_Calculation is defined to calculate SGPI(Semester Grade Pointer Index)
float SGPI_Calculations(int Group, int Sem)
{
    system("cls");
    printf("Please Verify Your Subjects:\n");
    if (Group==0)
    {
        if(Sem==1)
    {
        int BCCI,WICB,CA,CSA,ECB,PCB,NZC;
        float ICC;
        printf("Your subjects are:\nAM-1\nEC\nEEEE\nED\nCS\nWorkshop-I");
        printf("\nWe hope the subjects displayed are same as your subjects.\nSo let us count the pointers achieved by %s\n", STD1.Name);
        BCCI=AM();
        WICB=EC();
        PCB=EEEE();
        CSA=ED();
        CA=CS();
        ECB=WS();
        ICC=((float)(BCCI+PCB+WICB+CA+CSA+ECB)/22);
        return ICC;
    }
    else
    {
        int BCCI,WICB,CA,CSA,ECB,PCB,NZC;
        float ICC;
        printf("Your subjects are:\nAM-2\nEP\nEM\nPIC\nEVS\nWS-II\nIAP");
        printf("\nWe hope the subjects displayed are same as your subjects.\nSo let us count the pointers achieved by %s\n", STD1.Name);
        BCCI=AM();
        WICB=EP();
        PCB=EM();
        CSA=PIC();
        CA=EVS();
        ECB=WS();
        NZC=IAP();
        ICC=((float)BCCI+NZC+PCB+WICB+CA+CSA+ECB)/24;
        return ICC;
    }
    }
    else
    {
        if(Sem==1)
    {
        int BCCI,WICB,CA,CSA,ECB,PCB,NZC;
        float ICC;
        printf("Your Subjects are:\nAM-1\nEP\nEM\nPIC\nEVS\nWorkshop-I");
        printf("\nWe hope the subjects displayed are same as your subjects.\nSo let us count the pointers achieved by %s\n", STD1.Name);
        BCCI=AM();
        WICB=EP();
        PCB=EM();
        CSA=PIC();
        CA=EVS();
        ECB=WS();
        ICC=((float)BCCI+NZC+PCB+WICB+CA+CSA+ECB)/24;
        return ICC;
    }
        else
    {
        int BCCI,WICB,CA,CSA,ECB,PCB,NZC;
        float ICC;
        printf("Your Subjects are:\nAM-2\nEC\nEEEE\nED\nCS\nWorkshop-II\nIAP");
        printf("\nWe hope the subjects displayed are same as your subjects.\nSo let us count the pointers achieved by %s\n", STD1.Name);
        BCCI=AM();
        WICB=EC();
        PCB=EEEE();
        CSA=ED();
        CA=CS();
        ECB=WS();
        NZC=IAP();
        ICC=((float)BCCI+NZC+PCB+WICB+CA+CSA+ECB)/24;
        return ICC;
    }
    }
}
//These Functions are defined to calculate the Grade Pointers achieved in all subjects
int AM()
{
    int TH,K,L,OP,SGPI_AM,UP;
    float R;
    printf("For Applied Mathematics:\n");
    printf("Enter the CA Marks (Out of 50):\n");
    scanf("%d", &STD1.CA_Marks);
    printf("Enter the End Semester Exam Marks(Out of 100):\n");
    scanf("%d", &STD1.ESE_Marks);
    printf("Enter the Average Tutorial Marks (Out of 25):\n");
    scanf("%d", &STD1.TW_Marks);
    R=(STD1.ESE_Marks)/2;
    K=round(R);
    TH=K+STD1.CA_Marks;
    UP=GP(TH);
    L=(STD1.TW_Marks)*4;
    OP=GP(L);
    SGPI_AM=((UP)*4+OP);
    {
    if(OP==0)
        {KT();
        exit (0);}
    else
    return SGPI_AM;
    }
}

int EP()
{
    int TH,K,L,OP,RP,SGPI_AM;
    float R;
    printf("For Engineering Physics:\n");
    printf("Enter the CA Marks(Out of 50):\n");
    scanf("%d", &STD1.CA_Marks);
    printf("Enter the End Semester Exam Marks(Out of 100):\n");
    scanf("%d", &STD1.ESE_Marks);
    printf("Enter the Term Work Marks(Out of 50):\n");
    scanf("%d", &STD1.Lab_TW_Marks);
    R=(STD1.ESE_Marks)/2;
    K=round(R);
    TH=K+STD1.CA_Marks;
    L=(STD1.Lab_TW_Marks)*2;
    OP=GP(TH);
    RP=GP(L);
    SGPI_AM=((OP*4)+RP);
    {
    if(OP==0 || RP==0)
        {
            KT();
            exit (0);
        }
    else
    return SGPI_AM;
    }
}


int EC()
{
    int TH,K,L,OP,RP,SGPI_AM;
    float R;
    printf("For Engineering Chemistry:\n");
    printf("Enter the CA Marks(Out of 50):\n");
    scanf("%d", &STD1.CA_Marks);
    printf("Enter the End Semester Exam Marks(Out of 100): \n");
    scanf("%d", &STD1.ESE_Marks);
    printf("Enter the Term Work Marks(Out of 50):\n");
    scanf("%d", &STD1.Lab_TW_Marks);
    R=(STD1.ESE_Marks)/2;
    K=round(R);
    TH=K+STD1.CA_Marks;
    L=(STD1.Lab_TW_Marks)*2;
    OP=GP(TH);
    RP=GP(L);
    SGPI_AM=((OP*4)+RP);
    {
    if(OP==0 || RP==0)
        {
            KT();
            exit (0);
        }
    else
        return SGPI_AM;
    }
}

int EEEE()
{
    int TH,K,L,OP,RP,SGPI_AM;
    float R;
    printf("For Elements of Electrical and Electronics Engineering:\n");
    printf("Enter the CA Marks(Out of 50):\n");
    scanf("%d", &STD1.CA_Marks);
    printf("Enter the End Semester Exam Marks(Out of 100):\n");
    scanf("%d", &STD1.ESE_Marks);
    printf("Enter the Term Work Marks(Out of 50):\n");
    scanf("%d", &STD1.Lab_TW_Marks);
    R=(STD1.ESE_Marks)/2;
    K=round(R);
    TH=K+STD1.CA_Marks;
    L=(STD1.Lab_TW_Marks)*2;
    OP=GP(TH);
    RP=GP(L);
    SGPI_AM=((OP*3)+RP);
    {
    if(OP==0 || RP==0)
        {
            KT();
            exit (0);
        }
    else
        return SGPI_AM;
    }
}

int EM()
{
    int TH,K,L,OP,RP,SGPI_AM;
    float R;
    printf("For Engineering Mechanics:\n");
    printf("Enter the CA Marks(Out of 50):\n");
    scanf("%d", &STD1.CA_Marks);
    printf("Enter the End Semester Exam Marks(Out of 100): \n");
    scanf("%d", &STD1.ESE_Marks);
    printf("Enter the Term Work Marks (Out of 50):\n");
    scanf("%d", &STD1.Lab_TW_Marks);
    R=(STD1.ESE_Marks)/2;
    K=round(R);
    TH=K+STD1.CA_Marks;
    L=(STD1.Lab_TW_Marks)*2;
    OP=GP(TH);
    RP=GP(L);
    SGPI_AM=((OP*3)+RP);
    {
    if(OP==0 || RP==0)
        {
            KT();
            exit (0);
        }
    else
        return SGPI_AM;
    }
}

int ED()
{
    int TH,K,L,OP,RP,SGPI_AM;
    float R;
    printf("For Engineering Drawing:\n");
    printf("Enter the CA Marks(Out of 50):\n");
    scanf("%d", &STD1.CA_Marks);
    printf("Enter the End Semester Exam Marks(Out of 100): \n");
    scanf("%d", &STD1.ESE_Marks);
    printf("Enter the Term Work Marks(Out of 50):\n");
    scanf("%d", &STD1.Lab_TW_Marks);
    R=(STD1.ESE_Marks)/2;
    K=round(R);
    TH=K+STD1.CA_Marks;
    L=(STD1.Lab_TW_Marks)*2;
    OP=GP(TH);
    RP=GP(L);
    SGPI_AM=((OP*3)+RP);
    {
    if(OP==0 || RP==0)
        {
            KT();
            exit (0);
        }
    else
        return SGPI_AM;
    }
}

int PIC()
{
    int TH,K,L,OP,RP,SGPI_AM;
    float R;
    printf("For Programming in C (Language):\n");
    printf("Enter the CA Marks(Out of 50):\n");
    scanf("%d", &STD1.CA_Marks);
    printf("Enter the End Semester Exam Marks(Out of 100): \n");
    scanf("%d", &STD1.ESE_Marks);
    printf("Enter the Term Work Marks(Out of 50):\n");
    scanf("%d", &STD1.Lab_TW_Marks);
    R=(STD1.ESE_Marks)/2;
    K=round(R);
    TH=K+STD1.CA_Marks;
    L=(STD1.Lab_TW_Marks)*2;
    OP=GP(TH);
    RP=GP(L);
    SGPI_AM=((OP*3)+RP);
    return SGPI_AM;
    {
    if(OP==0 || RP==0)
        {
            KT();
            exit (0);
        }
    else
        return SGPI_AM;
    }
}

int EVS()
{
    int PO,LO;
    printf("For Environmental Science:\n");
    printf("Enter the CA marks(Out of 100):\n");
    scanf("%d", &STD1.CA_Marks);
    LO=GP(STD1.CA_Marks);
    PO=LO*2;
    if(PO==0)
        {
            KT();
            exit (0);
        }
    else
        return PO;
}

int CS()
{
    int LO,PO;
    printf("For Communication Skills:\n");
    printf("Enter the CA marks(Out of 100):\n");
    scanf("%d", &STD1.CA_Marks);
    LO=GP(STD1.CA_Marks);
    PO=LO*2;
    if(PO==0)
        {
            KT();
            exit (0);
        }
    else
    return PO;
}

int WS()
{
    int FT,UTR,UTR_WS;
    printf("For Workshop Practicals:\n");
    printf("Enter the Marks Obtained(Out of 50):\n");
    scanf("%d", &STD1.TW_Marks);
    FT=((STD1.TW_Marks)*2);
    UTR=GP(FT);
    UTR_WS=(UTR*2);
    if(UTR_WS==0)
        {
            KT();
            exit (0);
        }
    else
    return UTR_WS;
}

int IAP()
{
    int HT,VTR,VTR_IAP;
    printf("For Industrial Application Course:\n");
    printf("Enter the Marks Obtained (Out of 50):\n");
    scanf("%d", &STD1.TW_Marks);
    HT=(STD1.TW_Marks)*2;
    VTR=GP(HT);
    VTR_IAP=(VTR*2);
    if(VTR_IAP==0)
        {
            KT();
            exit (0);
        }
    else
    return VTR_IAP;
}

//The Function GP is for counting the GP
int GP (int count)
{
    int x;
    {
    if (count>=85)
        x=10;
    else if (75<=count && count<85)
        x=9;
    else if (70<=count && count<75)
        x=8;
    else if (60<=count && count<70)
        x=7;
    else if (50<=count && count<60)
        x=6;
    else if (45<=count && count<50)
        x=5;
    else if (40<=count && count<45)
        x=4;
    else
        x=0;
    }
    return x;
}


//The function CGPI_Calculations is for calculating the CGPI (Average of SGPIs for n semesters)
float CGPI_Calculations(int u)
{
    system("cls");
    int i;
    float t=0,P[10],CGPI_Avg;
    for (i=0;i<u;i++)
    {
          printf("Enter the SGPI achieved in Semester %d:\n", i+1);
          scanf("%f", &P[i]);
    }
    for (i=0;i<u;i++)
    {
        t=t+P[i];
    }
    CGPI_Avg=t/u;
    return CGPI_Avg;
}


//A special Function KT is defined so that it gets displayed if a student unluckily gets a KT in any subject
int KT()
{
int r;
printf("We are extremely sorry but you have a KT in this Subject(Pls contact the exam cell for further info). Due to this you would have to re-appear for this exam.\nFor now or for this semester, your SGPI can't be calculated.");
printf("Do you want to Continue with this calculator for other calculations??\nIf Yes Press 0\nIf No Press Any other Number\n");
scanf("%d", &r);
if(r==0)
{
main();
}
else
{
 printf("Made By Roll Numbers: 1814090 & 1814105 as a Mini-Project.\nThankYou For Using This Calculator.\n");
}
return 0;
}


//This Function shows the criteria for allotting the Grade Points
int criteria()
{
    system("cls");
    printf("HERE IS THE CRITERIA FOR ALLOTTING GRADE POINTS\n");
    printf("PERCENTAGE MARKS\tGRADE POINT\tLETTER GRADE\n"
    ">=95 and <=100\t\t10\t\tAP\n"
    ">=85 and <95\t\t10\t\tAA\n"
    ">=75 and <85\t\t9\t\tAB\n"
    ">=70 and <75\t\t8\t\tBB\n"
    ">=60 and <70\t\t7\t\tBC\n"
    ">=50 and <60\t\t6\t\tCC\n"
    ">=45 and <50\t\t5\t\tCD\n"
    ">=40 and <45\t\t4\t\tDD\n"
    ">=0 and <40\t\t0\t\tFF\n"
    "XX - IF ABSENT\n");
}
