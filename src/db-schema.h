#ifndef __DB_SCHEMA_H__
#define __DB_SCHEMA_H__

#ifndef NEED_SCHEMA
#error "this file should only be inlucded in db.cc"
#endif

static const char * sch_create_acitivities_table =  "create table activities_table " \
                                                    "(activity_ID integer primary key asc autoincrement, " \
                                                    "start_time integer not null, " \
                                                    "end_time integer);";

static const char * sch_create_acitivity_types_table =  "create table activity_types_table " \
                                                        "(activity_type_ID integer primary key asc autoincrement, "\
                                                        "name varchar(80) not null);";

static const char * sch_create_activities_map_table =   "create table activities_map_table " \
                                                        "(map_ID integer primary key asc autoincrement, " \
                                                        "activity_ID integer not null, " \
                                                        "activity_type_ID integer not null, " \
                                                        "foreign key (activity_ID) references activities_table(activity_ID), " \
                                                        "foreign key (activity_type_ID) references activity_types_table(activity_type_ID));";
#endif /* __DB_SCHEMA_H__ */
