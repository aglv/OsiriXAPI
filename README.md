You shouldn't actually link to this framework: its purpose it to provide the API
for OsiriX plugins (headers only). If you do, make sure it's a weak link!

My technique for OsiriX API linking in plugin (and preferences) targets is: -
Include OsiriX-API as a git submodule - Xcode target's Other Linker Flags:
-undefined dynamic\_lookup - Xcode target's Framework Search Paths:
\$(PROJECT\_DIR)/OsiriX-API

Currently, this is OsiriXAPI.framework from OsiriX Lite 8.0.1, renamed to
OsiriX.framework, with some extra headers from the OsiriX project (the OsiriX
DCM framework), reorganized to group certain headers (into DCM, DCMTK and CharLS
directories) and with fixed \#includes.
