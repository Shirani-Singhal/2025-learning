create database inner_join;
use inner_join;
create table facebook(name varchar(25),facebook_friends int);
create table linkedIn(name varchar(25),linkedIn_connections int);
INSERT INTO facebook (name, facebook_friends) VALUES ('Alice', 150), ('Bob', 200);
INSERT INTO linkedIn (name, linkedIn_connections) VALUES ('Alice', 300), ('Bob', 250);

create index ind on facebook(name);
