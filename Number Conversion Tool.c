#include<stdio.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

void  long_sum()
{
    char a[10000],b[10000],r[10000];
    int i,j,c=0,l1,l2,s,k;

    printf("\nEnter first very long number : ");
    scanf("%s",a);
    printf("Enter second very long number : ");
    scanf("%s",b);
    l1 = strlen(a);
    l2 = strlen(b);
    i = l1-1;
    j = l2-1;
    k = l1 > l2 ? l1 : l2;
    r[k] = '\0';
    k--;
    while(i>=0 && j>=0)
    {
        s = (a[i]-48)+(b[j]-48)+c;
        r[k]= s%10+48;
        c = s/10;
        i--;
        j--;
        k--;
    }
    if (i >= 0)
    {
        while(i >= 0)
        {
            s=a[i]-48+c;
            r[k] = s%10+48;
            c=s/10;
            i--;
            k--;
        }
    }
    else if (j >= 0)
    {
        while(j >= 0)
        {
            s=b[i]-48+c;
            r[k] = s%10+48;
            c=s/10;
            j--;
            k--;
        }
    }
    if (c>0)
    {
        for (i=strlen(r); i>=0; i--)
            r[i+1]=r[i];
        r[0]=c+48;
    }
    printf("\nsummation = %s\n",r);
}

void bitwise_or()
{
    long long a,b;
    printf("Enter 1st Number : ");
    scanf("%lld",&a);
    printf("Enter 2nd Number : ");
    scanf("%lld",&b);
    printf("\nOr of Two Numbers : %lld\n", a|b);

    return 0;
}

void bitwise_and()
{
    long long a,b;
    printf("Enter 1st Number : ");
    scanf("%lld",&a);
    printf("Enter 2nd Number : ");
    scanf("%lld",&b);
    printf("\nAnd of Two Numbers : %lld\n", a&b);

    return 0;
}
void bitwise_xor()
{
    long long a,b;
    printf("Enter 1st Number : ");
    scanf("%lld",&a);
    printf("Enter 2nd Number : ");
    scanf("%lld",&b);
    printf("\nXor of Two Numbers : %lld\n", a^b);

    return 0;
}

void complement()
{
    long long a;
    printf("Enter Your Number : ");
    scanf("%lld",&a);
    printf("\nComplement of This Number : %lld\n",~a);

    return 0;
}
void left_shift()
{

    long long n;
    int a;
    printf("Enter Your Number : ");
    scanf("%lld",&n);
    printf("How much you want to left shift : ");
    scanf("%d",&a);
    for (int i=0; i<=a; ++i)
        printf("\nLeft shift by %d : %lld\n", i, n<<i);
    return 0;
}

void right_shift()
{
    long long n;
    int a;
    printf("Enter Your Number : ");
    scanf("%lld",&n);
    printf("How much you want to right shift : ");
    scanf("%d",&a);
    for (int i=0; i<=a; ++i)
        printf("\nRight shift by %d : %lld\n", i, n>>i);

    return 0;
}

void s_Complement()
{

    int n; // bit number
    printf("\nEnter the number of bits do you want to enter : ");
    scanf("%d",&n);
    char bin[n+1];
    char onescomp[n+1];
    char twoscomp[n+1];
    int carry=1;
    printf("\nEnter the binary number : ");
    scanf("%s", bin);
    printf("\nOnes complement of the binary number is : ");

    // Finding onescomp in C
    for(int i=0; i<n; i++)
    {
        if(bin[i]=='0')
            onescomp[i]='1';
        else if(bin[i]=='1')
            onescomp[i]='0';
    }
    onescomp[n]='\0';
    printf("%s",onescomp);


    printf("\nTwos complement of a binary number is : ");

// Finding twoscomp in C
    for(int i=n-1; i>=0; i--)
    {
        if(onescomp[i] == '1' && carry == 1)
        {
            twoscomp[i] = '0';
        }
        else if(onescomp[i] == '0' && carry == 1)
        {
            twoscomp[i] = '1';
            carry = 0;
        }
        else
        {
            twoscomp[i] = onescomp[i];
        }
    }
    twoscomp[n]='\0';
    printf("%s\n",twoscomp);
    return 0;

}


void decimal_to_any_base(int n,int b)
{
    int i,r,digit,p,j=0;
    char a[100];
    p=n;
    while(p!=0)
    {
        r=p%b;
        digit='0'+r;
        if(digit>'9')
            digit=digit+7;
        a[j]=digit;
        j++;
        p=p/b;
    }
    if (b==2) printf("Binary Number : ");
    else if (b==8) printf("Octal Number : ");
    else if (b==16) printf("Hexadecimal Number : ");
    else   printf("%d Base Number : ",b);

    for(i=j-1; i>=0; --i)
    {
        printf("%c",a[i]);
    }
    printf("\n");
}


int any_base_to_decimal(int a, int c)
{
    char ch,ch1;
    unsigned int h;
    int n,n1;
    if (a==16)
    {
        printf("Enter Your Number : ");
        scanf("%x",&h);  // Input number
    }
    else
    {
        printf("Enter Your Number : ");
        scanf("%lld",&n);  // Input number


        long long dec = 0, i = 0, r;  // 1*2^3 + 1*2^2 + 0*2^1 + 1*2^0
        while (n != 0)
        {
            r = n % 10;   // 1 1 0 1
            n /= 10;       // 1 1 0
            dec += r * pow(a, i);
            ++i;
        }
        return dec;

    }
    return h;
}



int main()
{
    printf("\t                           ..:: NUMBER CONVERSION TOOL ::..                              \n\n");

    for (;;)
    {

        long long a,c,count=0,p,f,r;
        char ch,ch1;
        int sml=2;
        printf("\n[1] Number Converter\n");
        printf("[2] 2's Complement\n");
        printf("[3] Binary Operation\n");
        printf("[4] Long Arithmetic Summation\n");
        printf("\nEnter Your Choice : ");
        scanf("%lld",&p);
        if(p==1)
        {
            printf("\n\nEnter Base : ");
            scanf("%lld",&a);   // Input number base
            printf("In which base you want to convert : ");
            scanf("%lld",&c);
            if (c==10) // any base to decimal
            {
                long long ans = any_base_to_decimal(a,c);
                printf("Decimal Number : %lld\n",ans);

            }
            else  //any base to any base
            {
                long long ans1 = any_base_to_decimal(a,c);
                decimal_to_any_base(ans1,c);

            }
        }
        else if (p==2)
        {
            s_Complement();

        }
        else if (p==3)
        {

            printf("\n[1] Bitwise Or\n");
            printf("[2] Bitwise And\n");
            printf("[3] Bitwise Xor\n");
            printf("[4] Complement\n");
            printf("[5] Left Shift\n");
            printf("[6] Right Shift\n");
            printf("\nEnter Your Choice : ");
            scanf("%d",&r);
            if (r==1)
                bitwise_or();

            if (r==2)
                bitwise_and();

            if (r==3)
                bitwise_xor();

            if (r==4)
                complement();

            if (r==5)
                left_shift();

            if (r==6)
                right_shift();

        }
        else
        {
            long_sum();
        }
        printf("\nPress C to continue or Press Q to exit\n");
        scanf("%c%c",&ch1,&ch);
        for (;;)
        {
            if (ch=='C')
            {
                break;
            }
            if (ch=='Q')
            {
                printf("\nHow was the tool : \n[1]Excellent\t[2]Average\t[3]Poor\n");
                printf("\nEnter you valuable choice : ");
                scanf("%lld",&f);
                printf("\n\t                            Thanks for using our tool ");
                printf("%c \n\n",sml);
                break;
            }
            else
                printf("Invalid Entry, Try Again\n");
                printf("\nPress C to continue or Press Q to exit\n");
                scanf("%c%c",&ch1,&ch);
        }
        if (ch=='Q')
            break;

    }
    getch();
    return 0;
}
