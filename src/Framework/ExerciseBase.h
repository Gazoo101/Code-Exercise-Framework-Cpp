// Copyright (c) 2023, Lasse Farnung Laursen
// This code is licensed under MIT license (see LICENSE.txt for details)
// This file is a part of Cinder-CEF, https://github.com/Gazoo101/Code-Exercise-Framework-Cpp
#pragma once

// Std. Library


// 3rd Party


// 1st Party (This application)
#include "FunctionRunner.h"

// ExerciseBase exists so the Manager class can point to exercises, which derive from ExerciseDerived, without knowing the
// template parameters used with ExerciseDerived.

class ExerciseBase {
public:

	virtual ~ExerciseBase() = default;
	
	virtual void Execute() = 0;

protected:

	FunctionRunner mTestHelper;

};