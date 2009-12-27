#ifndef __DB_QUERY_H__
#define __DB_QUERY_H__

#ifndef NEED_SCHEMA
#error "this file should only be inlucded in db.cc"
#endif

static const char * q_insert_activity_type = "insert into activity_types_table(name) values(?1);";
static const char * q_insert_activity = "insert into activities_table(start_time) values(?1);";
static const char * q_update_activity_end_by_id = "update activities_table set end_time = ?1 where activity_ID = ?2;";

#endif
