// Copyright (c) 2023, Lasse Farnung Laursen
// This code is licensed under MIT license (see LICENSE.txt for details)
// This file is a part of Cinder-CEF, https://github.com/Gazoo101/Code-Exercise-Framework-Cpp

// Std. Library
#include <iostream>
#include <memory>

// 3rd Party

// 1st Party (This application)
#include "Framework/TestHelper.h"

#include "Tasks/TaskExample.h"
#include "Tasks/Leetcode/Task2391MinimumAmountOfTimeToCollectGarbage.h"

// TODO: Upgrade each derived class to auto execute their self-run code via a registrar class.

int main()
{
	// Compile set of tasks to execute
	std::vector<std::unique_ptr<TaskBase>> tasks;

	tasks.push_back( std::make_unique<TaskExample>() );
	tasks.push_back( std::make_unique<TaskTask2391>() );


	// Add additional tasks here...
	

	for (auto const& task : tasks)
	{
		task->RunTest();
	}
}