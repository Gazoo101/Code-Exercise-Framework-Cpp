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

	template <typename Functor, typename... Ts>
	void Execute( Functor&& f, Ts&& ... args );

private:

	std::ostringstream mStreamInputParams;
	std::ostringstream mStreamOutput;

	std::function<void( std::string const& str )> mPrintFunc;

	template <typename Type>
	void PrintToStream2( std::ostringstream& stream, Type value ) { stream << value; }

	template <typename Type>
	void PrintToStream2( std::ostringstream& stream, std::vector<Type> const& valueVec );
};


template <typename Functor, typename... Ts>
void TestHelper::Execute( Functor&& f, Ts&& ... args )
{
	mStreamInputParams.clear();
	mStreamInputParams.str( "" );

	mStreamOutput.clear();
	mStreamOutput.str( "" );

	// C++17 Fold expression which applies PrintToStream2() to every single argument in the variadic template pack.
	(PrintToStream2( mStreamInputParams, std::forward<Ts>( args ) ), ...);

	// Handle edge-case of 
	using ReturnType = std::invoke_result_t<Functor, Ts...>;
	if constexpr (std::is_same_v<void, ReturnType>)
	{
		f( std::forward<Ts>( args )... );
		mStreamOutput << "<Void>";
	}
	else {
		auto result = f( std::forward<Ts>( args )... );
		PrintToStream2( mStreamOutput, f( std::forward<Ts>( args )... ) );
	}

	std::string completeOutput = "Input: " + mStreamInputParams.str() + " | Output: " + mStreamOutput.str();

	mPrintFunc( completeOutput );
}


template <typename Type>
void TestHelper::PrintToStream2( std::ostringstream& stream, std::vector<Type> const& valueVec )
{
	stream << "[";
	std::copy( valueVec.begin(), valueVec.end(), std::ostream_iterator<Type>( stream, "," ) );
	stream << "], ";
}

