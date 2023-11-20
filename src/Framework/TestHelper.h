// Copyright (c) 2023, Lasse Farnung Laursen
// This code is licensed under MIT license (see LICENSE.txt for details)
// This file is a part of Cinder-CEF, https://github.com/Gazoo101/Code-Exercise-Framework-Cpp
#pragma once

#include <vector>
#include <sstream>
#include <functional>


class TestHelper {
public:
	TestHelper();
	TestHelper( std::function<void( std::string const& str )> const& printFunc );
	~TestHelper() = default;

	template <typename Functor, typename... Types>
	void Execute( Functor&& f, Types&& ... args );

	template <typename ResultType, typename Functor, typename... Types>
	void ExecuteWithResult( ResultType && expectedResult, Functor&& f, Types&& ... args );

private:

	std::ostringstream mStreamInputParams;
	std::ostringstream mStreamOutput;

	std::ostringstream mStreamExpectedResult;

	std::function<void( std::string const& str )> mPrintFunc;

	template <typename Type>
	void PrintToStream( std::ostringstream& stream, Type value )
	{
		stream << value;
	}

	template <typename Type>
	void PrintToStream( std::ostringstream& stream, std::vector<Type> const& valueVec );
};


template <typename Functor, typename... Types>
void TestHelper::Execute( Functor&& function, Types&& ... args )
{
	mStreamInputParams.clear();
	mStreamInputParams.str( "" );

	mStreamOutput.clear();
	mStreamOutput.str( "" );

	// C++17 Fold expression which applies PrintToStream() to every single argument in the variadic template pack.
	(PrintToStream( mStreamInputParams, std::forward<Types>( args ) ), ...);

	// Handle edge-case of 
	using ReturnType = std::invoke_result_t<Functor, Types...>;
	if constexpr (std::is_same_v<void, ReturnType>)
	{
		function( std::forward<Types>( args )... );
		mStreamOutput << "<Void>";
	}
	else {
		auto result = function( std::forward<Types>( args )... );
		PrintToStream( mStreamOutput, function( std::forward<Types>( args )... ) );
	}

	std::string completeOutput = "Input: " + mStreamInputParams.str() + " | Output: " + mStreamOutput.str();

	mPrintFunc( completeOutput );
}

template <typename ResultType, typename Functor, typename... Types>
void TestHelper::ExecuteWithResult( ResultType&& expectedResult, Functor&& function, Types&& ... args )
{
	Execute( function, std::forward<Types>( args )... );

	ResultType calculatedResult = function( std::forward<Types>( args )... );

	if (expectedResult == calculatedResult)
	{
		mPrintFunc( "Pass!" );
	}
	else {
		mPrintFunc( "Fail!" );
	}
}

template <typename Type>
void TestHelper::PrintToStream( std::ostringstream& stream, std::vector<Type> const& valueVec )
{
	stream << "[";
	std::copy( valueVec.begin(), valueVec.end(), std::ostream_iterator<Type>( stream, "," ) );
	stream << "], ";
}

