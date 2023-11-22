// Copyright (c) 2023, Lasse Farnung Laursen
// This code is licensed under MIT license (see LICENSE.txt for details)
// This file is a part of Cinder-CEF, https://github.com/Gazoo101/Code-Exercise-Framework-Cpp
#pragma once

// Std. Library


// 3rd Party


// 1st Party (This application)
#include "ExerciseBase.h"
#include "Manager.h"

// ExerciseDerived provides registration-functionality and a FunctionRunner instance (via ExerciseBase) for exercises to use.
// 
// It relies on the Curiously Recurring Template Pattern (CRTP) to allow each exercise to automatically instantiate itself,
// and pass itself along to the Manager class for later execution.
//
template <typename DerivedExerciseClass, bool isEnabled = true>
class ExerciseDerived : public ExerciseBase {
public:

    virtual ~ExerciseDerived() = default;

    static bool RegisterExercise()
    {
        if constexpr (isEnabled == false)
        {
            return false;
        }

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