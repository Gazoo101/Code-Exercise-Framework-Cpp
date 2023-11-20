# We intentionally explicitly list the .cpp/.h source files, as using GLOB to discover and assemble *all* source files is semi-frowned upon:
# https://stackoverflow.com/questions/1027247/is-it-better-to-specify-source-files-with-glob-or-each-file-individually-in-cmak

set(FILES_TASKS
	"${PATH_APP_SRC}/Tasks/TaskExample.cpp"
	"${PATH_APP_SRC}/Tasks/TaskExample.h"
	
	# Copy this file to create the tasks below from.
	"${PATH_APP_SRC}/Tasks/TaskTemplate.h"
	"${PATH_APP_SRC}/Tasks/TaskTemplate.h"
	
	# --- Add your own Task files below here ---
	#"${PATH_APP_SRC}/Company/Task1.cpp"
	#"${PATH_APP_SRC}/Company/Task1.h"

	"${PATH_APP_SRC}/Tasks/Leetcode/Task2391MinimumAmountOfTimeToCollectGarbage.h"
	"${PATH_APP_SRC}/Tasks/Leetcode/Task2391MinimumAmountOfTimeToCollectGarbage.cpp"
)