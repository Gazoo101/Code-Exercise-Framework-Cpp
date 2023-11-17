// Copyright (c) 2023, Lasse Farnung Laursen
// This code is licensed under MIT license (see LICENSE.txt for details)
// This file is a part of Cinder-CEF, https://github.com/Gazoo101/Code-Exercise-Framework-Cpp
// 
// std.dev
#include <vector>
#include <iostream>

// 3rd Party

// 1st Party
#include "Framework/TestHelper.h"

#include "TaskExample.h"

namespace {

int Task1Integer( int value )
{
	return 101;
}

std::vector<int> Task2Vector( std::vector<int> const& valueVec )
{
	return std::vector<int> { 1, 2, 3, 4, 5 };
}

int Task3VectorIntFloat( std::vector<int> const& valueVec, int valueInt, float valueFloat )
{
	return 123.32;
}

std::string Task4VectorReference( std::vector<int> & A )
{
	return "Task4VectorReference output.";
}

int Task5String( std::string const& text )
{
	return 123;
}

std::string Task6StringReference( std::string & text )
{
	return "Task6StringReference output.";
}

std::vector<int> Task6ThreeVectors( std::string const& S, std::vector<int>& P, std::vector<int>& Q )
{
	return std::vector<int> { 1, 2, 3, 4, 5 };
}

void Task7Void()
{
	int horse = 2;
}

}

void TaskExample::RunTest()
{
	using VectorInt = std::vector<int>;

	mTestHelper.Execute( Task1Integer, 99099 );
	mTestHelper.Execute( Task2Vector, VectorInt{ 10, 20, 30, 40, 50 } );
	mTestHelper.Execute( Task3VectorIntFloat, VectorInt{ 10, 20, 30, 40, 50 }, 88488, 342.33 );

	// If the function to execute strictly requires a reference, we can *not* use a list initializer as it cannot be
	// bound to an l-value. We must instead, define a variable that is then passed.
	auto vecThatCanBeReferenced = VectorInt{ 1, 2, 3, 4, 5 };
	mTestHelper.Execute( Task4VectorReference, vecThatCanBeReferenced );

	mTestHelper.Execute( Task5String, "Task5String text input" );

	// Just as with the std::vector, if the function requires a string reference, we must define a variable to hold our string.
	std::string task6Text = "hippedy hop";
	mTestHelper.Execute( Task6StringReference, task6Text );


	mTestHelper.Execute( Task7Void );
}