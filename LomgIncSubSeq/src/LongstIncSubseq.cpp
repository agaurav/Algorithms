//============================================================================
// Name        : LongstIncSubseq.cpp
// Author      : Ashish Gaurav
// Version     :
// Copyright   : Your copyright notice
// Description : To find the length of longest increasing subsequence in agiven number sequence
//============================================================================

#include <iostream>
#include <cstdlib>
#include <bitset>

#define N 11
using namespace std;

template<class T>
void LIS(const T* numSequence, int* ISlengthArray, int num_count)
    {
    int i, j;
    for (i = num_count - 1; i >= 0; i--)
	{
	ISlengthArray[i] = 1;
	for (j = i+1; j < num_count; j++)
	    {
	    if (numSequence[j] > numSequence[i] && ISlengthArray[j] >= ISlengthArray[i] )
		{
		ISlengthArray[i] = ISlengthArray[j] + 1;

		}
	    }
	}

    }
;

int main()
    {
    bitset<100> b1;
    int seq[N];
    int subSeqL[N];
    int mi,mj;
    for(mi = 0; mi < N; mi++ )
	{
	seq[mi] = rand()%10;
	}
    cout << endl;
    LIS(seq,subSeqL,N);
    for(mi = 0; mi < N; mi++ )
    	{
    	cout << seq[mi] <<" ";
    	}
    cout<<endl;

    for(mi = 0; mi < N; mi++ )
        	{
        	cout << subSeqL[mi]<< " ";
        	}
    return 0;
    }
