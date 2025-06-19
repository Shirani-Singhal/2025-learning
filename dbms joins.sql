create database joins;
use joins;
create table trainers(
trainer_id int primary key,
trainer_name varchar(20),
courses varchar(20)
);
create table students(
student_id int primary key,
student_name varchar(20),
trainerID int,
foreign key(trainerID) references trainers(trainer_id)
);
insert into trainers value(3,"Abhinav","ai/ml"),(4,"harshit","ds"),(5,"shirani","cyber");

insert into students values(1,"ram",3),(2 ,"mohan",4),(3,"shyam",5);

#use joins on trainer & student table
select * from trainers inner join students on trainers.trainer_id = students.trainerID;

#1. Show all student names with their trainer names.
select student_name,trainer_name from students inner join trainers on  students.trainerID=trainers.trainer_id;

#2. List students and the courses they are enrolled in.
select student_name,courses from students  inner join trainers on  students.trainerID=trainers.trainer_id ;

#3. Show student name, course name, and trainer name.
select student_name,courses,trainer_name from students inner join trainers on  students.trainerID=trainers.trainer_id;

#4. Find which trainer is assigned to student 'Ram'.
select student_name,trainer_name from students inner join trainers on  students.trainerID=trainers.trainer_id where student_name="ram";

#5. Find which course 'Mohan' is learning.
select student_name,courses from students inner join trainers on  students.trainerID=trainers.trainer_id where student_name="mohan";

#6. Get the total number of students under each trainer.
SELECT trainers.trainer_name, COUNT(students.student_name) AS student_count FROM students
INNER JOIN trainers ON students.trainerID = trainers.trainer_id
GROUP BY trainers.trainer_name;

#7. Show all students learning from 'Ashish'.
select student_name,trainer_name from students inner join trainers on  students.trainerID=trainers.trainer_id where trainer_name="Abhinav";

#8. List courses that have more than 1 student enrolled.
SELECT trainers.trainer_name, COUNT(students.student_name) AS student_count
FROM students
INNER JOIN trainers ON students.trainerID = trainers.trainer_id
GROUP BY trainers.trainer_name
HAVING COUNT(students.student_name) > 1;

#9. List student names and their Trainer IDs.
select student_name,trainer_id from students inner join trainers on  students.trainerID=trainers.trainer_id;

#10. Show all student-trainer pairs where trainer teaches "DS".
select student_name,trainer_name from students inner join trainers on  students.trainerID=trainers.trainer_id where courses="ds";