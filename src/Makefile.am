bin_PROGRAMS = worg 
#sqlist client
worg_SOURCES = main.cc \
			   db.cc \
			   log.cc \
			   application.cc \
			   activity-model.cc \
			   ui.cc \
			   ui-popup-menu.cc

worg_CXXFLAGS = $(GTKMM_CFLAGS) \
			  $(GLIBMM_CFLAGS) \
			  $(SQLITE3_CFLAGS) \
			  $(GIOMM_CFLAGS)
worg_LDFLAGS = $(GTKMM_LIBS) \
			   $(GLIBMM_LIBS) \
			   $(SQLITE3_LIBS) \
			   $(GIOMM_LIBS)

#sqlist_SOURCES = sqlist.cc
#sqlist_CXXFLAGS = $(SQLITE3_CFLAGS)
#sqlist_LDFLAGS = $(SQLITE3_LIBS)
#
#client_SOURCES = client.cc \
#				 db.cc \
#				 log.cc \
#				 application.cc \
#				 activity-model.cc
#client_CXXFLAGS = $(GTKMM_CFLAGS) \
#			  $(GLIBMM_CFLAGS) \
#			  $(SQLITE3_CFLAGS) \
#			  $(GIOMM_CFLAGS)
#client_LDFLAGS = $(GTKMM_LIBS) \
#			   $(GLIBMM_LIBS) \
#			   $(SQLITE3_LIBS) \
#			   $(GIOMM_LIBS)
