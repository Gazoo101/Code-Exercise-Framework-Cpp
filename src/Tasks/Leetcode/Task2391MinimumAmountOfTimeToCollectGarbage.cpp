// Copyright (c) 2023, Lasse Farnung Laursen
// This code is licensed under MIT license (see LICENSE.txt for details)
// This file is a part of Cinder-CEF, https://github.com/Gazoo101/Code-Exercise-Framework-Cpp
// 
// std.dev
#include <vector>

// 3rd Party

// 1st Party
#include "Task2391MinimumAmountOfTimeToCollectGarbage.h"

namespace {

using namespace std;

auto MinutesForCollection( std::string const& garbage )
{
	int metal = 0;
	int paper = 0;
	int glass = 0;

	for (auto const& garb : garbage)
	{
		switch (garb)
		{
		case 'M':
			metal++;
			break;
		case 'P':
			paper++;
			break;
		case 'G':
			glass++;
			break;
		}
	}

	return std::make_tuple( metal, paper, glass );
}

int garbageCollection( vector<string>& garbage, vector<int>& travel )
{
	int indexLastHouseMetal = 0;
	int indexLastHousePaper = 0;
	int indexLastHouseGlass = 0;

	int timeMetal = 0;
	int timePaper = 0;
	int timeGlass = 0;

	int accMetal = 0;
	int accPaper = 0;
	int accGlass = 0;

	// Garbage is guaranteed to always be 2 long
	auto [metal, paper, glass] = MinutesForCollection( garbage[0] );
	timeMetal += metal;
	timePaper += paper;
	timeGlass += glass;

	for (int i = 1; i < garbage.size(); ++i)
	{
		accMetal += travel[i - 1];
		accPaper += travel[i - 1];
		accGlass += travel[i - 1];

		auto [metal, paper, glass] = MinutesForCollection( garbage[i] );

		if (metal > 0)
		{
			timeMetal += accMetal + metal;
			accMetal = 0;
		}

		if (paper > 0)
		{
			timePaper += accPaper + paper;
			accPaper = 0;
		}

		if (glass > 0)
		{
			timeGlass += accGlass + glass;
			accGlass = 0;
		}
	}

	return timeMetal + timePaper + timeGlass;
}

}

void TaskTask2391::RunTest()
{
	using VectorInt = std::vector<int>;
	using VectorString = std::vector<string>;

	// Update framework to contain expected outcome
	// Input: garbage = ["G", "P", "GP", "GG"], travel = [2, 4, 3]
	// Output : 21

	mTestHelper.Execute( garbageCollection, VectorString{ "G", "P", "GP", "GG" }, VectorInt{ 2, 4, 3 } );
	mTestHelper.ExecuteWithResult( 21, garbageCollection, VectorString{ "G", "P", "GP", "GG" }, VectorInt{ 2, 4, 3 } );
	mTestHelper.ExecuteWithResult( 37, garbageCollection, VectorString{ "MMM", "PGM", "GP" }, VectorInt{ 3,10 } );
}