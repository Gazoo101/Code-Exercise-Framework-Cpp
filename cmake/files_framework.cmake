# We intentionally explicitly list the .cpp/.h source files, as using GLOB to discover and assemble *all* source files is semi-frowned upon:
# https://stackoverflow.com/questions/1027247/is-it-better-to-specify-source-files-with-glob-or-each-file-individually-in-cmak

set(FILES_FRAMEWORK
	"${PATH_APP_SRC}/Framework/ExerciseBase.cpp"
	"${PATH_APP_SRC}/Framework/ExerciseBase.h"
	"${PATH_APP_SRC}/Framework/ExerciseDerived.cpp"
	"${PATH_APP_SRC}/Framework/ExerciseDerived.h"
	"${PATH_APP_SRC}/Framework/FunctionRunner.cpp"
	"${PATH_APP_SRC}/Framework/FunctionRunner.h"
	"${PATH_APP_SRC}/Framework/Manager.cpp"
	"${PATH_APP_SRC}/Framework/Manager.h"
	"${PATH_APP_SRC}/main.cpp"
)