// Copyright (c) 2023, Lasse Farnung Laursen
// This code is licensed under MIT license (see LICENSE.txt for details)
// This file is a part of Cinder-CEF, https://github.com/Gazoo101/Code-Exercise-Framework-Cpp
#pragma once

// Std. Library


// 3rd Party


// 1st Party (This application)
#include "ExerciseBase.h"
#include "Manager.h"

template <typename DerivedExerciseClass, bool isEnabled = true>
class ExerciseDerived : public ExerciseBase {
public:

    //virtual ~ExerciseDerived() = default;

    static bool RegisterExercise()
    {
        auto& manager = Manager::Instance();

        auto exerciseClass = std::make_unique<DerivedExerciseClass>();
        manager.Register( std::move( exerciseClass ) );

        return true;
    }

    static inline bool mRegistered = ExerciseDerived<DerivedExerciseClass, isEnabled>::RegisterExercise();

private:

    // Making the constructor private, be-friending the Derived template class prevents misuse, such as:
    // ExerciseApple : public ExerciseBase<ExerciseBanana>
    friend DerivedExerciseClass;
    ExerciseDerived() { /* (void)mRegistered;*/ }

};