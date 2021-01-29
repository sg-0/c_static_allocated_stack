#[[------------------------------------------

	--------------------------------
	sg-0 CMake Script
	--------------------------------
	
	Project: Generic

---------------------------------------------]]# 
SET(MODULE_NAME QUEUE)

SET( MODULE_SRC
	queue.cpp
)

SET_SOURCE_FILES_PROPERTIES( ${MODULE_SRC}
	COMPILE_FLAGS "${DEFAULT_COMPILE_OPTIONS}"
)

ADD_LIBRARY ( ${MODULE_NAME} STATIC ${MODULE_SRC} )

TARGET_INCLUDE_DIRECTORIES( ${MODULE_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
)
