#include <stdio.h>
#include <stdlib.h>

int main()
{
    int theGuess,hundrestDigit,tensDigit,unitsDigit,point=105,indexOfRequestedNumbers=0,requestedNumbers[647]={};
    for(int threeDigitNumber=100; threeDigitNumber<=999; threeDigitNumber++)
    {
        hundrestDigit = threeDigitNumber/100;
        tensDigit = (threeDigitNumber/10)%10;
        unitsDigit = threeDigitNumber%10;
        if(hundrestDigit!=tensDigit && hundrestDigit!=unitsDigit && tensDigit!=unitsDigit)
        {
            requestedNumbers[indexOfRequestedNumbers]=threeDigitNumber;
            indexOfRequestedNumbers++;
        }
    }
//---------------------------------------PC'nin tuttugu random sayi-----------------------------------------------------------------
    int swapVariable1,swapVariable2,randomNumber,numberOfComputers,swapVariable3;
    srand(time(NULL));
    for(int indexOfRequestedNumbers=1; indexOfRequestedNumbers<=647; indexOfRequestedNumbers++)
    {
        swapVariable1 = rand()%647;
        swapVariable2 = rand()%647;
        swapVariable3 = requestedNumbers[swapVariable1];
        requestedNumbers[swapVariable1] = requestedNumbers[swapVariable2];
        requestedNumbers[swapVariable2] = swapVariable3;
    }
    randomNumber = rand()%647;
    numberOfComputers = requestedNumbers[randomNumber];

//---------------------------------------oyun basliyor------------------------------------------------------------------------------
    int hundreds,tens,units,hundreds1,tens1,units1,finishIt=0;
    while(finishIt==0)
    {
        here:
        printf("Guess!\n");
        scanf("%d",&theGuess);
        if(theGuess<100 || theGuess>999)
        {
            printf("You entered the wrong number,Please enter 3 digits with different numbers.\n");
            goto here;
        }
        hundreds=theGuess/100;
        tens=(theGuess/10)%10;
        units=theGuess%10;
        hundreds1=numberOfComputers/100;
        tens1=(numberOfComputers/10)%10;
        units1=numberOfComputers%10;

        if(hundreds==tens || tens==units || hundreds==units)
        {
            printf("You entered the wrong number,Please enter 3 digits with different numbers.\n");
            goto here;
        }
        point -=5;
        if(hundreds==hundreds1 && tens==tens1 && units==units1)
        {
            finishIt = 1;
            printf("+1 +1 +1\n");
            printf("YOU WON! POINT:%d\n",point);
            break;
        }

        if(hundreds==hundreds1)
        {
            printf("+1 ");
        }
        if(tens==tens1)
        {
            printf("+1 ");
        }
        if(units==units1)
        {
            printf("+1 ");
        }
        if(hundreds==tens1)
        {
            printf("-1 ");
        }
        if(hundreds==units1)
        {
            printf("-1 ");
        }
        if(tens==hundreds1)
        {
            printf("-1 ");
        }
        if(tens==units1)
        {
            printf("-1 ");
        }
        if(units==hundreds1)
        {
            printf("-1 ");
        }
        if(units==tens1)
        {
            printf("-1 ");
        }
        else if(hundreds!=hundreds1 && tens!=tens1 && units!=units1 && hundreds!=tens1 && tens!=hundreds1 && units!=hundreds1 && hundreds!=units1 && tens!=units1 && units!=tens1)
        {
            printf("0");
        }
        printf("\n");

    }
    printf("%d\n",requestedNumbers[randomNumber]);
    return 0;
}
