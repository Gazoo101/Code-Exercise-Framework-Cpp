// Copyright (c) 2023, Lasse Farnung Laursen
// This code is licensed under MIT license (see LICENSE.txt for details)
// This file is a part of Cinder-CEF, https://github.com/Gazoo101/Code-Exercise-Framework-Cpp
#pragma once

#include "Framework/ExerciseDerived.h"

class TaskTemplate : public ExerciseDerived<TaskTemplate, true>
{
public:
	void Execute() override;

private:

};