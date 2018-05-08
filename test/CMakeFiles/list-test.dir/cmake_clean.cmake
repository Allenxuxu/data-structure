file(REMOVE_RECURSE
  "../bin-debug/list-test.pdb"
  "../bin-debug/list-test"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/list-test.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
