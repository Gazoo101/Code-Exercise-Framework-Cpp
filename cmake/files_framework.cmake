# We intentionally explicitly list the .cpp/.h source files, as using GLOB to discover and assemble *all* source files is semi-frowned upon:
# https://stackoverflow.com/questions/1027247/is-it-better-to-specify-source-files-with-glob-or-each-file-individually-in-cmak

set(FILES_FRAMEWORK
	"${PATH_APP_SRC}/Framework/TaskBase.cpp"
	"${PATH_APP_SRC}/Framework/TaskBase.h"
	"${PATH_APP_SRC}/Framework/TestHelper.cpp"
	"${PATH_APP_SRC}/Framework/TestHelper.h"
	"${PATH_APP_SRC}/main.cpp"
)