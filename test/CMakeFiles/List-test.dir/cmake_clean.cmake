file(REMOVE_RECURSE
  "../bin-debug/List-test.pdb"
  "../bin-debug/List-test"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/List-test.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
