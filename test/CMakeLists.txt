
add_executable(testmian main.cpp)
target_link_libraries(testmian xxlib)

add_executable(StaticList-test StaticList-test.cpp)
target_link_libraries(StaticList-test xxlib)

add_executable(DynamicList-test DynamicList-test.cpp)
target_link_libraries(DynamicList-test xxlib)

add_executable(StaticArray-test StaticArray-test.cpp)
target_link_libraries(StaticArray-test xxlib)

add_executable(DynamicArray-test DynamicArray-test.cpp)
target_link_libraries(DynamicArray-test xxlib)

add_executable(LinkList-test LinkList-test.cpp)
target_link_libraries(LinkList-test xxlib)

add_executable(SmartPointer-test SmartPointer-test.cpp)
target_link_libraries(SmartPointer-test xxlib)

add_executable(CircleList-test CircleList-test.cpp)
target_link_libraries(CircleList-test xxlib)

add_executable(DualLinkList-test DualLinkList-test.cpp)
target_link_libraries(DualLinkList-test xxlib)

add_executable(StaticLinkList-test StaticLinkList-test.cpp)
target_link_libraries(StaticLinkList-test xxlib)

