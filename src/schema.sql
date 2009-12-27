-- create table start_times_table (time integer primary key);
-- create table end_times_table (time integer primary key);
create table activities_table (activity_ID integer primary key asc autoincrement, start_time integer not null, end_time integer);
create table activity_types_table (activity_type_ID integer primary key asc autoincrement, name varchar(80) not null);
create table activities_map_table (map_ID integer primary key asc autoincrement, activity_ID integer not null, activity_type_ID integer not null, foreign key (activity_ID) references activities_table(activity_ID), foreign key (activity_type_ID) references activity_types_table(activity_type_ID));

