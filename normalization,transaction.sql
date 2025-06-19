create database schoolDB;
use schoolDB;

create table students_raw(
student_id int Primary key,
name varchar(20),
phone_numbers varchar(100) -- Not atomic (violates 1NF)
);

-- Normalized table(after applying 1NF)
Insert into students_raw values(1,'riya','1234056789'),(2,'aryan','9876543210');

create table students(student_id int ,name varchar(50),phone_number varchar(50) ,primary key(student_id,phone_number));
--------------------------------------------
create database collegeDB;
use  collegeDB;

create table enrollment_row(
student_id int,
course_id int,
student_name varchar(50),
course_name varchar(50),
primary key(student_id,course_id)
);

insert into enrollment_row values(1,101,'amit','math'),(1,102,'amit','physics');
insert into enrollment_row values (2,101,'riya','math'),(3,102,'samar','chemistry');

-- Enrollment table only composite key

create table students(student_id int primary key,student_name varchar(50));
insert into students values(1,"shirani"),(2,"radha");

create table courses(course_id int primary key,course_name varchar(50));
insert into courses values (1,"maths"),(2,"chemistry");

CREATE TABLE enrollments (
    student_id INT,
    course_id INT,
    PRIMARY KEY (student_id, course_id),
    FOREIGN KEY (student_id) REFERENCES students(student_id),
    FOREIGN KEY (course_id) REFERENCES courses(course_id)
);

-- Insert enrollment data
INSERT INTO enrollments VALUES (1, 1), (1, 2), (2, 1);

select * from students;
select * from courses;
select * from enrollments;
------------------------------------------------------------------------------------------

-- Before 3NF
create table enrollment_raw(
emp_id int primary key,
emp_name varchar(50),
dept_id int,
dept_name varchar(50)
);

create table departments(dept_id int primary key,dept_name varchar(50));

create table employees(emp_id int primary key,emp_name varchar(50),dept_id int,foreign key(dept_id) references departments(dept_id));

--------------------------------------------------------------
create table accounts(
id int primary key,
name varchar(50),
balance decimal(10,2)
);

INSERT INTO accounts VALUES (1, 'alice', 1000.00), (2, 'bob', 500.00);

-- Step 1: Start
start transaction;
 -- Step 2: Try dedecting  from alice
  SET SQL_SAFE_UPDATES = 0;
UPDATE accounts
SET balance = balance - 1000
WHERE name = 'alice' AND balance >= 1000;
SET SQL_SAFE_UPDATES = 1; -- Re-enable safe mode
or 
UPDATE accounts
SET balance = balance - 1000
WHERE id = 1 AND balance >= 1000;

 -- Step 3: Check how many rows are affected
SELECT ROW_COUNT();
SELECT FOUND_ROWS();
SELECT COUNT(*) FROM accounts WHERE name = 'alice' AND balance < 1000;

-- Step 4: Verify deduction
SELECT balance FROM accounts WHERE name = 'alice';

COMMIT;
ROLLBACK;
DELIMITER $$

CREATE PROCEDURE process_transaction()
BEGIN
    DECLARE current_balance DECIMAL(10,2);

    -- Get balance
    SELECT balance INTO current_balance FROM accounts WHERE name = 'alice';

    -- Decide whether to commit or rollback
    IF current_balance >= 0 THEN
        COMMIT;
    ELSE
        ROLLBACK;
    END IF;
END$$

DELIMITER ;

-- Call procedure after update
CALL process_transaction();
