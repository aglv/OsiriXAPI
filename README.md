You shouldn't actually link to this framework.
My technique for OsiriX API linking in plugins (and preferences) targets is:
- Include OsiriX-API as a git submodule
- Xcode target's Other Linker Flags: -undefined dynamic_lookup
- Xcode target's Framework Search Paths: $(PROJECT_DIR)/OsiriX-API
