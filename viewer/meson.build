viewer_enabled = true

aravis_desktop_dir = join_paths (get_option ('datadir'), 'applications')
aravis_app_data_dir = join_paths (get_option ('datadir'), 'metainfo')
aravis_icon_dir = join_paths (get_option ('datadir'), 'icons', 'hicolor')

viewer_sources = [
	'main.c',
	'arvviewer.c'
]

viewer_headers = [
	'arvviewertypes.h',
	'arvviewer.h'
]

viewer_c_args = [
	'-DARAVIS_LOCALE_DIR="@0@"'.format (join_paths (get_option ('prefix'), 'share', 'locale')),
	'-DARAVIS_GETTEXT="aravis-@0@"'.format (aravis_api_version)
]

viewer_resources = gnome.compile_resources (
	'arvviewerresources', 'arvviewerresources.xml'
	)

executable ('arv-viewer-@0@'.format (aravis_api_version),
	    viewer_sources, viewer_headers, viewer_resources,
	    link_with: aravis_library,
	    c_args: viewer_c_args,
	    include_directories: [library_inc],
	    dependencies: viewer_deps,
	    install: true)

install_subdir (join_paths ('icons', 'gnome'),
		exclude_directories: 'scalable',
		install_dir: aravis_icon_dir,
		strip_directory: true)

subdir ('data')
