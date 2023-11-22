// Copyright (c) 2023, Lasse Farnung Laursen
// This code is licensed under MIT license (see LICENSE.txt for details)
// This file is a part of Cinder-CEF, https://github.com/Gazoo101/Code-Exercise-Framework-Cpp
#pragma once

// Std. Library


// 3rd Party


// 1st Party (This application)
#include "ExerciseBase.h"

class Manager {
public:

	static Manager& Instance() {
		static Manager instance;
		return instance;
	}

	static bool Register( std::unique_ptr<ExerciseBase> exercise )
	{
		mExercises.push_back( std::move( exercise ) );

		return true;
	}

	static std::vector<std::unique_ptr<ExerciseBase>>& GetExercises() { return mExercises; }

protected:

	static inline std::vector<std::unique_ptr<ExerciseBase>> mExercises;

private:

	// This class, being a designated Singleton, we intentionally declare both its constructor and destructor privately.
	Manager() = default;
	~Manager() = default;

};