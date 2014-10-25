
#include <iostream>
#include <vector>
using namespace std;
#define N 3

vector<int> permutation(N);
vector<int> used(N, 0);

void try1(int which,int what)
{
	permutation[which] = what;
	used[what] = 1;

	if (which == N-1){
		for(auto i:permutation)
		{
			cout<<i<<"\t";
		}
//	outputPermutation();
	}
	else
	{
	// try all possibilities for the next element
		for (int next=0; next<N; next++){
			if (!used[next]){
				try1(which+1, next);
			}
		}
	}
	used[what] = 0;
}

int main() {
	// try all possibilities for the first element
	for (int first = 0; first < N; first++) {
		try1(0,first);
		cout<<endl;
	}
}
