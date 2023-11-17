// std.dev
#include <vector>

// 3rd Party

// 1st Party
#include "TestHelper.h"

#include "TaskTemplate.h"

namespace {

int solution( std::vector<int>& A )
{
	return 666;
}

}

void TaskTemplate::RunTest()
{
	typedef std::vector<int> VectorInt;

	mTestHelper.execute( solution, VectorInt{ 1, 2, 3, 4, 5 } );
}