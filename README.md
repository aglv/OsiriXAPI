You shouldn't actually link to this framework: its purpose it to provide the API for OsiriX plugins (headers only).

My technique for OsiriX API linking in plugin (and preferences) targets is:
- Include OsiriX-API as a git submodule
- Xcode target's Other Linker Flags: -undefined dynamic_lookup
- Xcode target's Framework Search Paths: $(PROJECT_DIR)/OsiriX-API

Currently, this is OsiriXAPI.framework from OsiriX Lite 7.0.2, renamed to OsiriX.framework and with some extra headers from the OsiriX project (the OsiriX DCM framework).
