// Copyright (c) 2023, Lasse Farnung Laursen
// This code is licensed under MIT license (see LICENSE.txt for details)
// This file is a part of Cinder-CEF, https://github.com/Gazoo101/Code-Exercise-Framework-Cpp

// Std. Library


// 3rd Party


// 1st Party (This application)
#include "Framework/Manager.h"

int main()
{
	auto& manager = Manager::Instance();

	for (auto& exercise : manager.GetExercises())
	{
		exercise->Execute();
	}
}