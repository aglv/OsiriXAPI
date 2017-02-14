You shouldn't actually link to this framework: its purpose it to provide the API
for OsiriX plugins (headers only). If you do, make sure it's a weak link!

My technique for OsiriX API linking in plugin (and preferences) targets is:

- Include OsiriX-API as a git submodule;
- Add the ``OsiriX-API/OsiriX.framework`` to the project, as a *weak* framework;
- Xcode target's ``Framework Search Paths``: ``OsiriX-API``;
- Xcode target's ``Other Linker Flags``: ``-undefined dynamic_lookup``;

Warning: using ``-undefined dynamic_lookup`` causes the linker not to raise warnings for missing symbols. This could be a problem, as you'll only be able to notice that some symbols are actually missing at runtime. For safety, instead of having ``-undefined dynamic_lookup``, you should list symbols by adding ``-Wl,-U,_OBJC_CLASS_$_PluginFilter`` (and others) to your ``Other Linker Flags``.

Currently, this is OsiriXAPI.framework from OsiriX Lite 8.0.2, renamed to
OsiriX.framework, with some extra headers from the OsiriX project (the OsiriX
DCM framework), reorganized and with patched \#includes.
