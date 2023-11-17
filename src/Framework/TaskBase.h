// Copyright (c) 2023, Lasse Farnung Laursen
// This code is licensed under MIT license (see LICENSE.txt for details)
// This file is a part of Cinder-CEF, https://github.com/Gazoo101/Code-Exercise-Framework-Cpp
#pragma once

#include "TestHelper.h"

class TaskBase {
public:

	virtual ~TaskBase() = default;
	
	virtual void RunTest() = 0;

protected:

	TestHelper mTestHelper;

};