#pragma hdrstop

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>
#include <TimerUnit.cpp>

template<class _InIt,  class _Ty>  inline
 _InIt
 find_A(_InIt _First, _InIt _Last, const _Ty& _Val)

 {   // find first matching _Val
	 _DEBUG_RANGE(_First, _Last);
	 for (; _First != _Last; ++_First)
	 if  (*_First == _Val)   break;
	 return (_First);
 }


template<typename _InputIterator, typename _Tp>  inline
_InputIterator
find_B(_InputIterator __first, _InputIterator __last, const _Tp& __val)

{    while (   __first != __last  &&
			!(*__first == __val))
			 ++__first;
	 return __first;
 }

 const int N = 10000;

int main()
{
	//srand(0);
	Timer                       timer;
	std::vector<int>::iterator  X;
	std::random_device          rd;
	std::mt19937                g    ( rd() );

	std::vector<int>            v    ( N    );
	std::iota( v.begin(), v.end(), 0);

	std::vector<int>            v2   ( v    );
	std::shuffle ( v2.begin(), v2.end(), g );

	std::cout << "\n";

	timer.start();
	for (int i=0; i < N; ++i) 	{ X = std::find( v.begin(), v.end(), v2[i] );  *X = 0; }
	timer.stop();
	std::cout << "std::find : " <<  timer.elapsedSeconds() << "\n";


	timer.start();
	for (int i=0; i < N; ++i) 	{ X = find_A   ( v.begin(), v.end(), v2[i] );  *X = 0; }
	timer.stop();
	std::cout << "\n";
	std::cout << "find A    : " <<  timer.elapsedSeconds() << "\n";


	timer.start();
	for (int i=0; i < N; ++i) 	{ X = find_B   ( v.begin(), v.end(), v2[i] );  *X = 0; }
	timer.stop();
	std::cout << "\n";
	std::cout << "find B    : " <<  timer.elapsedSeconds() << "\n";

	std::cout << "\n";
	int x; std::cin >> x;

	return 0;
}
