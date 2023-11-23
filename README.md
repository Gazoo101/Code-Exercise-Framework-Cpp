# Code-Exercise-Framework-Cpp

This framework reduces boiler-plate code when solving C++ coding exercises, such as those issued by LeetCode, Codility and TestDome.

> [!TIP]
> If the coding exercise allows using alternate languages to C++, I recommend considering a higher-level language such as Python. While C++ has become far more flexibly and quicker to write, it is still significantly more verbose and strict compared to other languages. A higher-level language can allow for a greater focus on the exercise to be solved, as opposed to correct syntax. A simple [Python framework to solve coding exercises is available here](https://github.com/Gazoo101/Codility-Python-Framework).

## Features

- One-line execution of exercise function with input and expected outputs.
- Self-registration of exercise code deriving from `ExerciseDerived`.
- Basic primitive to std::string conversion for typical exercise inputs, such as `std::vector<int>` and `std::vector<std::string>`.

## How to Use

The recommended approach to solving a new exercise using this framework is:

- Create a new .cpp and .h file in the [src/Exercises](src/Exercises)'s folder.
- Add these files to the CMake [cmake/files_exercises.cmake](cmake/files_exercises.cmake) file.
- Copy the template class from [src/Exercises/ExerciseTemplate.h](src/Exercises/ExerciseTemplate.h).
- Adjust the class name from `ExerciseTemplate` to <Your Exercise Name>.
- Implement the exercise solution!

### Exercise class

Having copied the ExerciseTemplate content, we just need to replace the `ExerciseTemplate` name as shown below:
```C++
//    ↓-----------------------------------------↓---- Replace the class name(s) here.
class ExerciseTemplate : public ExerciseDerived<ExerciseTemplate, true>
{
public:
	void Execute() override;

private:

};
```

The second template parameter enables/disables the Exercise class from registering itself with the [Exercise Manager](src/Framework/Manager.h). Most exercises are so quick to execute computationally, that you can safely let all of them execute, but if you'd like fine-grained control over which exercises to execute, this template parameter gives you this freedom.

Finally, you implement your solution to test in the exercise .cpp file.

Here's what such a solution could look like (an excerpt from [src/Exercises/ExerciseExample.cpp]), along with some test cases being applied:
```C++
// std.dev
#include <vector>
#include <iostream>

// 3rd Party

// 1st Party
#include "ExerciseExample.h"

namespace {

int Task1Integer( int value )
{
	return 101;
}

std::vector<int> Task2Vector( std::vector<int> const& valueVec )
{
	return std::vector<int> { 1, 2, 3, 4, 5 };
}

int Task3VectorIntFloat( std::vector<int> const& valueVec, int valueInt, float valueFloat )
{
	return 123.32;
}

}

void ExerciseExample::Execute()
{
	using VectorInt = std::vector<int>;

	mTestHelper.Execute( Task1Integer, 99099 );
	mTestHelper.Execute( Task2Vector, VectorInt{ 10, 20, 30, 40, 50 } );
	mTestHelper.ExecuteWithResult( VectorInt{ 1, 2, 3, 4, 5 }, Task2Vector, VectorInt{ 10, 20, 30, 40, 50 } );
	mTestHelper.Execute( Task3VectorIntFloat, VectorInt{ 10, 20, 30, 40, 50 }, 88488, 342.33 );
}
```
The `mTestHelper` property allows us to functions that encapsulate the exercise solution we're building. If we merely want to execute the exercise solution with a set of inputs, we can use `Execute`. If we also with to compare the exercise solution result with an expected output, we can use `ExecuteWithResult`.