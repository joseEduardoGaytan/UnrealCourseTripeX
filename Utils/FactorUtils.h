#include "iostream";
#include "vector";

using namespace std;

bool IsPrimeNumber(int evaluatedNumber)
{
    bool bIsPrimeNumber = true;

    if(evaluatedNumber == 1){
        bIsPrimeNumber = false;
    }

    for(int i=2; i < evaluatedNumber; i++)
    {
        bool bIsDivisible = evaluatedNumber % i == 0;

        if(bIsDivisible){
            return false;
        }
    }

    return bIsPrimeNumber;

}

/*
    Get all the prime numbers from one number up the specified number
*/
vector<int> GetPrimeNumberList(int from,int to)
{
    vector<int> PrimeNumbers;

    for(int i = from; i <= to; i++)
    {
        bool bIsPrimeNumber = IsPrimeNumber(i);
        if(bIsPrimeNumber){
            PrimeNumbers.push_back(i);
        }
    }

    return PrimeNumbers;

}

void GetPrimeFactor(int NumberToBeDivided, vector<int> PrimeNumbers, vector<int> &PosiblePrimeFactors)
{    

    if(NumberToBeDivided > 0){            
        for(int i = 0; i < PrimeNumbers.size(); i++)
        {
            int ExactDivision = NumberToBeDivided % PrimeNumbers[i] == 0;

            if(ExactDivision){
                int DivisionResult = NumberToBeDivided / PrimeNumbers[i];
                std::cout << "\n " << "; Devide: " << NumberToBeDivided << "; Divisor: " << PrimeNumbers[i] << "; Remainder: " << DivisionResult;
                
                //if the remainder is int then we continue, if not we continue with the next number
                if(DivisionResult == (int)DivisionResult){
                    PosiblePrimeFactors.push_back(PrimeNumbers[i]);

                    GetPrimeFactor(DivisionResult, PrimeNumbers, PosiblePrimeFactors);

                    break;
                }      
            }

        }     
    } 
}

vector<int> GetPrimesFactorsList(int Number)
{
    vector<int> PosiblePrimeFactors;
    vector<int> PrimeNumbers = GetPrimeNumberList(2, Number);
    
    GetPrimeFactor(Number, PrimeNumbers, PosiblePrimeFactors);

    std::cout << "\n Prime Numbers: ";

    for(int i = 0; i < PosiblePrimeFactors.size(); i++)
    {
        std::cout << PosiblePrimeFactors[i];
    }
    
    return PosiblePrimeFactors;   

}


unsigned long intfibdijkstra(unsigned long n) {
    static std::vector<unsigned long> values = {0,1,1};
    if (n == 0 ) {
        return values[n];
    }
    if (n < values.size() && values[n] != 0 ) {
        return values[n];
    }
    if (values.capacity() < n){
        values.reserve(n);
    }
    if (values.size() < n){
        values.resize(n);
    }
    if (n%2==0){
       unsigned long num = n/2;
       if (values[num-1]==0)
           values.at(num-1)=intfibdijkstra(num-1);
       if (values[num]==0)
           values.at(num)=intfibdijkstra(num);
       return (2*values[num-1]+values[num])*values[num];
    }
    else {
        unsigned long num = (n+1)/2;
        if (values[num-1]==0)
            values.at(num-1)=intfibdijkstra(num-1);
        if (values[num]==0)
            values.at(num)=intfibdijkstra(num);
        return values[num-1]*values[num-1]+values[num]*values[num];
    }
}

/*vector<int> GetFactorsList(int number)
{

}*/
