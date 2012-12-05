//============================================================================
// Name        : LongestCommonSubSeq.cpp
// Author      : Ashish Gaurav
// Version     :
// Copyright   : Your copyright notice
// Description : Find the longest common subsequence b/w given two sequences
//               DPA = Dynamic Programming Array (just a funky name)
//============================================================================

#include <iostream>
#include <cstdlib>
#define N 10
#define M 10
#define maX(a,b)  ( (a) > (b) ? (a) : (b))
using namespace std;

template<class T>
int LCSeq(const T* seq1, const T* seq2, int seqLentgh1, int seqLentgh2)
    {
    int ii, si, sj;
    int LCS_DPA[M+1][2] =
	{
	0
	};
    //int* LCS_DPA = (int*) malloc(sizeof(int) * seqLentgh1 * 2);

    for (si = seqLentgh1; si >= 0; si--)
	{
	ii = si&1;
	for (sj = seqLentgh2; sj >= 0; sj--)
	    {
	    if (si == seqLentgh1 || sj == seqLentgh2)
		{
		LCS_DPA[sj][ii] = 0;
		continue;
		}
	    if (seq1[si] == seq2[sj])
		LCS_DPA[sj][ii] = LCS_DPA[sj + 1][1 - ii] + 1;
	    else
		{
		LCS_DPA[sj][ii] = maX(LCS_DPA[sj+1][ii],LCS_DPA[sj][1-ii]);
		}
	    }
	}

    return LCS_DPA[0][0];
    }
;
template <class T>
int LCSeq2D(const T* seq1, const T* seq2, int seqLentgh1, int seqLentgh2)
    {
    int si, sj;
    int LCS_DPA[M+1][N+1];
    //int* LCS_DPA = (int*) malloc(sizeof(int) * seqLentgh1 * 2);

    for (si = seqLentgh1; si >= 0; si--)
	{

	for (sj = seqLentgh2; sj >= 0; sj--)
	    {
	    if (si == seqLentgh1 || sj == seqLentgh2)
		{
		LCS_DPA[si][sj] = 0;
		continue;
		}
	    if (seq1[si] == seq2[sj])
		LCS_DPA[si][sj] = LCS_DPA[si + 1][sj+1] + 1;
	    else
		{
		LCS_DPA[si][sj] = max(LCS_DPA[si+1][sj],LCS_DPA[si][sj+1]);
		}
	    }
	}

    return LCS_DPA[0][0];
    }
;

int main()
    {
    int seq1[N], seq2[M], mi;
    cout << endl;
    for (mi = 0; mi < N; mi++)
	{
	seq1[mi] = rand() % 20;
	cout << seq1[mi] << " ";
	}
    cout << endl;
    for (mi = 0; mi < M; mi++)
	{
	seq2[mi] = rand() % 20;
	cout << seq2[mi] << " ";
	}
    cout << endl << LCSeq(seq1, seq2, N, M);
    return 0;
    }
