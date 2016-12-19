When working on OsiriX plugins, *weak link* to these frameworks. Their purpose is to provide the headers for classes available in the OsiriX runtime. It isn't guaranteed that a framework with the correct name is available.

My technique for OsiriX API linking in plugin (and preferences) targets is:

- Include OsiriX-API as a git submodule
- Xcode `Other Linker Flags`: `-undefined dynamic_lookup`
- Xcode `Framework Search Paths`: `$(PROJECT_DIR)/OsiriX-API`

Currently, these frameworks are from OsiriX Lite *8.0.2*.
