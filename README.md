You shouldn't actually link to this framework: its purpose it to provide the API for OsiriX plugins.

My technique for OsiriX API linking in plugin (and preferences) targets is:
- Include OsiriX-API as a git submodule
- Xcode target's Other Linker Flags: -undefined dynamic_lookup
- Xcode target's Framework Search Paths: $(PROJECT_DIR)/OsiriX-API
