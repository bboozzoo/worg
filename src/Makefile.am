bin_PROGRAMS = worg sqlist
worg_SOURCES = main.cc
worg_CXXFLAGS = $(GTKMM_CFLAGS) \
				$(SQLITE3_CFLAGS)
worg_LDFLAGS = $(GTKMM_LIBS) \
			   $(SQLITE3_LIBS)

sqlist_SOURCES = sqlist.cc
sqlist_CXXFLAGS = $(SQLITE3_CFLAGS)
sqlist_LDFLAGS = $(SQLITE3_LIBS)
